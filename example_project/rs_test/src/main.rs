#![no_std]
#![no_main]

use defmt::{error, info};
use embassy_embedded_hal::shared_bus::asynch::spi::SpiDevice;
use embassy_executor::Spawner;
use embassy_stm32::exti::ExtiInput;
use embassy_stm32::gpio::{Level, Output, Pull, Speed};
use embassy_stm32::mode::Async;
use embassy_stm32::spi::{self, Spi};
use embassy_sync::blocking_mutex::raw::NoopRawMutex;
use embassy_sync::mutex::Mutex;
use embassy_time::{Delay, Timer};
use fh101rf::{registers, Fh101rf};
use static_cell::StaticCell;
use {defmt_rtt as _, panic_probe as _};

type SpiBus = Mutex<NoopRawMutex, Spi<'static, Async>>;

#[embassy_executor::main]
async fn main(_spawner: Spawner) -> ! {
    let p = embassy_stm32::init(Default::default());

    // Pass peripherals as reference: Allows dropping for low-power features
    let spi_config = spi::Config::default();
    let spi = Spi::new(
        p.SPI1,
        p.PA5,
        p.PA7,
        p.PA6,
        p.GPDMA1_CH0,
        p.GPDMA1_CH1,
        spi_config,
    );
    let cs = Output::new(p.PC9, Level::High, Speed::VeryHigh);
    static SPI_BUS: StaticCell<SpiBus> = StaticCell::new();
    let spi_bus = SPI_BUS.init(Mutex::new(spi));
    let spi_dev = SpiDevice::new(spi_bus, cs);

    let rst = Output::new(p.PC6, Level::High, Speed::VeryHigh);
    let mut irq = ExtiInput::new(p.PC7, p.EXTI7, Pull::None);

    info!("Starting up FH101RF Test Application\r\n");
    // Load default configuration
    let mut dev = Fh101rf::new(spi_dev, rst, Delay);

    // Change desired configurations
    {
        dev.conf.nfa868_slow.data = registers::SampleRate::Sr1024;
        dev.conf.nfa868_fast.data = registers::SampleRate::Sr32768;

        dev.conf.n_lco_target_868_lo.data = (3465 & 0xFF) as u8; // (/ (* (+ 868.35 40) 1000000) (* 8 32768)) //
                                                                 // 40MHz above carrier
        dev.conf.n_lco_target_868_hi.data = ((3465 >> 8) & 0xFF) as u8; // (/ (* (+ 868.35 40) 1000000) (* 8
                                                                        // 32768)) // 40MHz above carrier
        dev.conf.band_branch_ctrl.active_bands.band_433 = false;
        dev.conf.band_branch_ctrl.active_bands.band_868 = true;
        dev.conf.band_branch_ctrl.active_bands.band_2g4 = false;
        dev.conf.band_branch_ctrl.active_branches.weak = true;
        dev.conf.band_branch_ctrl.active_branches.medium = true;
        dev.conf.band_branch_ctrl.active_branches.strong = true;

        dev.conf.code_select.a = registers::BinCode::A;
        dev.conf.code_select.b = registers::BinCode::B;

        dev.conf.korrel_thresh_a.data = 0x1A;
        dev.conf.korrel_thresh_b.data = 0x1A;

        dev.conf.fdd_enable.fdd_bands.band_433 = false;
        dev.conf.fdd_enable.fdd_bands.band_868 = true;
        dev.conf.fdd_enable.fdd_bands.band_2g4 = false;

        dev.conf.irq_select.irq_select.correl_match = false;
        dev.conf.irq_select.irq_select.id_match = true;
        dev.conf.irq_select.irq_select.id_match_and_ldr = false;

        dev.conf.idm_enable.match_bands.band_433 = false;
        dev.conf.idm_enable.match_bands.band_868 = true;
        dev.conf.idm_enable.match_bands.band_2g4 = false;

        dev.conf.idm_ctrl.ctrl = registers::Ctrl::IndOnly;

        dev.conf.fifo_length.band_433 = registers::FifoLen::Bit16;
        dev.conf.fifo_length.band_868 = registers::FifoLen::Bit16;
        dev.conf.fifo_length.band_2g4 = registers::FifoLen::Bit16;

        dev.conf.xtal_osc_ctrl.data = true;
        dev.conf.ldo_xtal_ctrl.xtal_osc_byp = false;
        dev.conf.ldo_xtal_ctrl.ldo_ena_nfa = false;

        dev.conf.mux_d_out_sel.out = registers::Out::IrqEvent1;
    }

    Timer::after_millis(500).await;
    let err = dev.init().await;
    if let Err(e) = err {
        panic!("Failed to init FH101RF with {:?}", e);
    }

    // change genpurp_1 register to random number
    dev.conf.genpurp_1.data = 0x5A;
    let err = dev.write_genpurp().await;
    if let Err(e) = err {
        panic!("Failed to write genpurp 1 of FH101RF with {:?}", e);
    }

    let mut counter = 0;
    loop {
        info!("Waiting for interrupt from FH101RF");
        irq.wait_for_rising_edge().await;
        counter += 1;
        info!("Got interrupt {:?}", counter);
        let res = dev.clear_irq().await;
        if let Err(e) = res {
            error!("Failed to clear irq on FH101RF ({:?})", e)
        }
        info!(
            "Read genpurp 1: {:x}",
            dev.read_genpurp().await.unwrap().data
        );
    }
}
