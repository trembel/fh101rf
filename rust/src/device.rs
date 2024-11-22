use crate::hal_type;
use crate::maybe_async_attr;
use crate::registers::*;
use crate::Error;
use crate::Fh101rfConfig;
use embedded_hal::digital::OutputPin;

pub struct Fh101rf<SPI, OUT, DELAY> {
    pub spi: SPI,
    pub rst: OUT,
    pub sleep: DELAY,
    pub conf: Fh101rfConfig,
}

impl<SPI, OUT, DELAY> Fh101rf<SPI, OUT, DELAY>
where
    SPI: hal_type::spi::SpiDevice<u8>,
    OUT: OutputPin,
    DELAY: hal_type::delay::DelayNs,
{
    /// Creates a new instance of `Fh101rf`
    ///
    /// Requires the SPI device and it's device address
    pub fn new(spi: SPI, rst: OUT, sleep: DELAY) -> Self {
        Self {
            spi,
            rst,
            sleep,
            conf: Fh101rfConfig::default(),
        }
    }

    /// Allow direct access to the SPI bus
    pub fn bus(&mut self) -> &mut SPI {
        &mut self.spi
    }

    /// Function to write a register to the device
    #[maybe_async_attr]
    pub async fn write_reg(&mut self, mut adr: u8, val: u8) -> Result<(), Error<SPI>> {
        adr &= 0x7F;

        let buf: [u8; 2] = [adr, val];
        self.spi.write(&buf).await.map_err(Error::Communication)
    }
    /// Function to read a register from the device
    #[maybe_async_attr]
    pub async fn read_reg(&mut self, mut adr: u8, res: &mut u8) -> Result<(), Error<SPI>> {
        adr |= 0x80;

        let write: [u8; 2] = [adr, 0];
        let mut read: [u8; 2] = [0; 2];

        let result = self.spi.transfer(&mut read, &write).await.map_err(Error::Communication);
        *res = read[1];
        result
    }

    /// Initialize function
    #[maybe_async_attr]
    pub async fn init(&mut self) -> Result<LcoCalibData, Error<SPI>> {
        // Reset Wake-Up Radio
        self.rst.set_low().map_err(|_| Error::<SPI>::Gpio)?;
        self.sleep.delay_ms(1).await;
        self.rst.set_high().map_err(|_| Error::<SPI>::Gpio)?;
        self.sleep.delay_ms(500).await; // 0.5s according to DS until XTAL is ready

        // Check if connection is valid by reading out VERSION
        self.check_connection().await?;

        // Check whether XTAL_GOOD == 1
        {
            let mut xtal_good: u8 = 0;
            self.read_reg(XtalGood::ADDRESS, &mut xtal_good).await?;
            if !XtalGood::from_le_bytes(&[xtal_good]).data {
                return Err(Error::Config("XTAL_GOOD not ready"));
            }
        }

        // Set D_CORNER_CTRL to 0x02
        {
            self.conf.d_corner_ctrl.data = 0x02;
            self.write_reg(DCornerCtrl::ADDRESS, self.conf.d_corner_ctrl.to_le_bytes()[0])
                .await?;
        }

        // Set LC_TG_ENA to 0x00
        {
            self.conf.lc_tg_ena.data = false;
            self.write_reg(LcTgEna::ADDRESS, self.conf.lc_tg_ena.to_le_bytes()[0])
                .await?;
        }

        // Set COMP_THRESH_W to 0x0A
        {
            self.conf.comp_thresh_w.data = 0x0A;
            self.write_reg(CompThreshW::ADDRESS, self.conf.comp_thresh_w.to_le_bytes()[0])
                .await?;
        }

        let lco_calib_data = self.calibrate().await?;
        self.write_cfg_regs().await?;

        Ok(lco_calib_data)
    }

    /// Function to calibrate the FH101RF
    #[maybe_async_attr]
    pub async fn calibrate(&mut self) -> Result<LcoCalibData, Error<SPI>> {
        // Calibrate LCO frequency
        let lco_calib_data = self.lco_calibrate().await?;

        // Calibrate Sample Pulse
        self.sample_pulse_calibrate().await?;

        // Calibrate Comparator
        self.comp_calibrate().await?;

        Ok(lco_calib_data)
    }

    /// Function to clear the irq register of the FH101RF
    #[maybe_async_attr]
    pub async fn clear_irq(&mut self) -> Result<(), Error<SPI>> {
        let clr = IrqClr {
            irq_clr: IrqSource {
                correl_match: true,
                id_match: true,
                id_match_and_fifo_full: true,
                fifo_overflow: true,
                fifo_full: true,
                cyclic_timer_alarm: true,
                id_match_and_ldr: true,
                rtc_timer_alarm: true,
            },
        };

        self.write_reg(IrqClr::ADDRESS, clr.to_le_bytes()[0]).await
    }

    /// Function to read the GENPURP1 register of the FH101RF. Returns reference to self
    #[maybe_async_attr]
    pub async fn read_genpurp(&mut self) -> Result<&Genpurp1, Error<SPI>> {
        let mut genpurp1: u8 = 0;

        self.read_reg(Genpurp1::ADDRESS, &mut genpurp1).await?;
        self.conf.genpurp_1 = Genpurp1::from_le_bytes(&[genpurp1]);
        Ok(&self.conf.genpurp_1)
    }

    /// Function to write the GENPURP1 register of the FH101RF from self reference.
    #[maybe_async_attr]
    pub async fn write_genpurp(&mut self) -> Result<(), Error<SPI>> {
        self.write_reg(Genpurp1::ADDRESS, self.conf.genpurp_1.to_le_bytes()[0])
            .await
    }

    /// Function polling the version registers, to check whether the communication with the FH101RF works
    #[maybe_async_attr]
    async fn check_connection(&mut self) -> Result<(), Error<SPI>> {
        let mut version: u8 = 0;

        self.read_reg(Version::ADDRESS, &mut version).await?;

        if Version::reset_val_le().unwrap() != [version] {
            return Err(Error::Config("Version"));
        }
        Ok(())
    }

    /// Function to calibrate the LCO of the FH101RF
    #[maybe_async_attr]
    async fn lco_calibrate(&mut self) -> Result<LcoCalibData, Error<SPI>> {
        // Set BAND_BRANCH_CTRL as desired
        self.write_reg(BandBranchCtrl::ADDRESS, self.conf.band_branch_ctrl.to_le_bytes()[0])
            .await?;

        // Set N_LCO_TARGET accordingly
        self.write_reg(NLcoTarget433Hi::ADDRESS, self.conf.n_lco_target_433_hi.to_le_bytes()[0])
            .await?;
        self.write_reg(NLcoTarget433Lo::ADDRESS, self.conf.n_lco_target_433_lo.to_le_bytes()[0])
            .await?;
        self.write_reg(NLcoTarget868Hi::ADDRESS, self.conf.n_lco_target_868_hi.to_le_bytes()[0])
            .await?;
        self.write_reg(NLcoTarget868Lo::ADDRESS, self.conf.n_lco_target_868_lo.to_le_bytes()[0])
            .await?;
        self.write_reg(NLcoTarget2g4Hi::ADDRESS, self.conf.n_lco_target_2g4_hi.to_le_bytes()[0])
            .await?;
        self.write_reg(NLcoTarget2g4Lo::ADDRESS, self.conf.n_lco_target_2g4_lo.to_le_bytes()[0])
            .await?;

        // Set LCO_CAL and CAL_START in CALIB_CTRL
        {
            self.conf.calib_ctrl.cal_start = true;
            self.conf.calib_ctrl.lco_cal = true;
            self.conf.calib_ctrl.offset_cal = false;
            self.conf.calib_ctrl.spg_cal = false;
            let res = self
                .write_reg(CalibCtrl::ADDRESS, self.conf.calib_ctrl.to_le_bytes()[0])
                .await;
            self.conf.calib_ctrl.cal_start = false;
            self.conf.calib_ctrl.lco_cal = false;
            res?;
        }

        // Check CALIB_CTRL for CAL_START going low
        {
            let mut temp = CalibCtrl {
                cal_start: true,
                ..Default::default()
            };

            while temp.cal_start {
                let mut calib_ctrl: u8 = 0;
                self.read_reg(CalibCtrl::ADDRESS, &mut calib_ctrl).await?;
                temp = CalibCtrl::from_le_bytes(&[calib_ctrl]);
            }
        }

        // Wait for CAL_IN_PROG to become false
        {
            let mut status = CalibStatus {
                cal_in_prog: true,
                lco_cal_in_prog: true,
                offset_cal_in_prog: true,
                spg_cal_in_prog: true,
            };

            while status.cal_in_prog && status.lco_cal_in_prog {
                let mut calib_status: u8 = 0;
                self.read_reg(CalibStatus::ADDRESS, &mut calib_status).await?;
                status = CalibStatus::from_le_bytes(&[calib_status]);
            }
        }

        // Read LCO_TARGET after calibration
        let mut calib_data = LcoCalibData {
            band_433: None,
            band_868: None,
            band_2g4: None,
        };

        if self.conf.band_branch_ctrl.active_bands.band_433 {
            let mut data: [u8; 2] = [0; 2];
            self.read_reg(LcoFreq433Hi::ADDRESS, &mut data[1]).await?;
            self.read_reg(LcoFreq433Lo::ADDRESS, &mut data[0]).await?;
            calib_data.band_433 = Some(((data[1] as u16) << 8) | (data[0] as u16));
        }
        if self.conf.band_branch_ctrl.active_bands.band_868 {
            let mut data: [u8; 2] = [0; 2];
            self.read_reg(LcoFreq868Hi::ADDRESS, &mut data[1]).await?;
            self.read_reg(LcoFreq868Lo::ADDRESS, &mut data[0]).await?;
            calib_data.band_868 = Some(((data[1] as u16) << 8) | (data[0] as u16));
        }
        if self.conf.band_branch_ctrl.active_bands.band_2g4 {
            let mut data: [u8; 2] = [0; 2];
            self.read_reg(LcoFreq2g4Hi::ADDRESS, &mut data[1]).await?;
            self.read_reg(LcoFreq2g4Lo::ADDRESS, &mut data[0]).await?;
            calib_data.band_2g4 = Some(((data[1] as u16) << 8) | (data[0] as u16));
        }

        Ok(calib_data)
    }

    /// Function to calibrate the Sample Pulse of the FH101RF
    #[maybe_async_attr]
    async fn sample_pulse_calibrate(&mut self) -> Result<(), Error<SPI>> {
        // Set N_SPG_TARGET to non-default-value 0x46
        {
            self.conf.n_spg_target.data = 0x46;
            self.write_reg(NSpgTarget::ADDRESS, self.conf.n_spg_target.to_le_bytes()[0])
                .await?;
        }

        // Set SPG_CAL and CAL_START in CALIB_CTRL
        {
            self.conf.calib_ctrl.cal_start = true;
            self.conf.calib_ctrl.lco_cal = false;
            self.conf.calib_ctrl.offset_cal = false;
            self.conf.calib_ctrl.spg_cal = true;
            let res = self
                .write_reg(CalibCtrl::ADDRESS, self.conf.calib_ctrl.to_le_bytes()[0])
                .await;
            self.conf.calib_ctrl.cal_start = false;
            self.conf.calib_ctrl.spg_cal = false;
            res?;
        }

        // Check CALIB_CTRL for CAL_START going low
        {
            let mut temp = CalibCtrl {
                cal_start: true,
                ..Default::default()
            };

            while temp.cal_start {
                let mut calib_ctrl: u8 = 0;
                self.read_reg(CalibCtrl::ADDRESS, &mut calib_ctrl).await?;
                temp = CalibCtrl::from_le_bytes(&[calib_ctrl]);
            }
        }

        // Wait for CAL_IN_PROG to become false
        {
            let mut status = CalibStatus {
                cal_in_prog: true,
                lco_cal_in_prog: true,
                offset_cal_in_prog: true,
                spg_cal_in_prog: true,
            };

            while status.cal_in_prog && status.spg_cal_in_prog {
                let mut calib_status: u8 = 0;
                self.read_reg(CalibStatus::ADDRESS, &mut calib_status).await?;
                status = CalibStatus::from_le_bytes(&[calib_status]);
            }
        }

        Ok(())
    }

    /// Function to calibrate the Comparator of the FH101RF
    #[maybe_async_attr]
    async fn comp_calibrate(&mut self) -> Result<(), Error<SPI>> {
        // Save current value of register BAND_BRANCH_CTRL
        // not needed as already in our register struct

        // Set Bits 6 to 4 in BAND_BRANCH_CTRL to 1
        {
            let temp = BandBranchCtrl {
                active_bands: Bands {
                    band_2g4: true,
                    band_433: true,
                    band_868: true,
                },
                active_branches: Branches {
                    medium: self.conf.band_branch_ctrl.active_branches.medium,
                    strong: self.conf.band_branch_ctrl.active_branches.strong,
                    weak: self.conf.band_branch_ctrl.active_branches.weak,
                },
            };
            self.write_reg(BandBranchCtrl::ADDRESS, temp.to_le_bytes()[0]).await?;
        }

        // Set COMP_THRESH_W to 0x0A
        {
            self.conf.comp_thresh_w.data = 0x0A;
            let res = self
                .write_reg(CompThreshW::ADDRESS, self.conf.comp_thresh_w.to_le_bytes()[0])
                .await;
            self.conf.comp_thresh_w.data = 0x00;
            res?;
        }

        // Set OFFSET_CAL and CAL_START in CALIB_CTRL
        {
            self.conf.calib_ctrl.cal_start = true;
            self.conf.calib_ctrl.lco_cal = false;
            self.conf.calib_ctrl.offset_cal = true;
            self.conf.calib_ctrl.spg_cal = false;
            let res = self
                .write_reg(CalibCtrl::ADDRESS, self.conf.calib_ctrl.to_le_bytes()[0])
                .await;
            self.conf.calib_ctrl.cal_start = false;
            self.conf.calib_ctrl.offset_cal = false;
            res?;
        }

        // Check CALIB_CTRL for CAL_START going low
        {
            let mut temp = CalibCtrl {
                cal_start: true,
                ..Default::default()
            };

            while temp.cal_start {
                let mut calib_ctrl: u8 = 0;
                self.read_reg(CalibCtrl::ADDRESS, &mut calib_ctrl).await?;
                temp = CalibCtrl::from_le_bytes(&[calib_ctrl]);
            }
        }

        // Wait for CAL_IN_PROG to become false
        {
            let mut status = CalibStatus {
                cal_in_prog: true,
                lco_cal_in_prog: true,
                offset_cal_in_prog: true,
                spg_cal_in_prog: true,
            };

            while status.cal_in_prog && status.offset_cal_in_prog {
                let mut calib_status: u8 = 0;
                self.read_reg(CalibStatus::ADDRESS, &mut calib_status).await?;
                status = CalibStatus::from_le_bytes(&[calib_status]);
            }
        }

        // Reset BAND_BRANCH_CTRL to saved value
        self.write_reg(BandBranchCtrl::ADDRESS, self.conf.band_branch_ctrl.to_le_bytes()[0])
            .await?;

        Ok(())
    }

    /// Function writing all config registers to the FH101RF
    #[maybe_async_attr]
    async fn write_cfg_regs(&mut self) -> Result<(), Error<SPI>> {
        // Write NFA433_SLOW
        self.write_reg(Nfa433Slow::ADDRESS, self.conf.nfa433_slow.to_le_bytes()[0])
            .await?;

        // Write NFA433_FAST
        self.write_reg(Nfa433Fast::ADDRESS, self.conf.nfa433_fast.to_le_bytes()[0])
            .await?;

        // Write NFA868_SLOW
        self.write_reg(Nfa868Slow::ADDRESS, self.conf.nfa868_slow.to_le_bytes()[0])
            .await?;

        // Write NFA868_FAST
        self.write_reg(Nfa868Fast::ADDRESS, self.conf.nfa868_fast.to_le_bytes()[0])
            .await?;

        // Write NFA2G4_SLOW
        self.write_reg(Nfa2g4Slow::ADDRESS, self.conf.nfa2g4_slow.to_le_bytes()[0])
            .await?;

        // Write NFA2G4_FAST
        self.write_reg(Nfa2g4Fast::ADDRESS, self.conf.nfa2g4_fast.to_le_bytes()[0])
            .await?;

        // Write N_LCO_TARGET_433_HI
        self.write_reg(NLcoTarget433Hi::ADDRESS, self.conf.n_lco_target_433_hi.to_le_bytes()[0])
            .await?;

        // Write N_LCO_TARGET_433_LO
        self.write_reg(NLcoTarget433Lo::ADDRESS, self.conf.n_lco_target_433_lo.to_le_bytes()[0])
            .await?;

        // Write N_LCO_TARGET_868_HI
        self.write_reg(NLcoTarget868Hi::ADDRESS, self.conf.n_lco_target_868_hi.to_le_bytes()[0])
            .await?;

        // Write N_LCO_TARGET_868_LO
        self.write_reg(NLcoTarget868Lo::ADDRESS, self.conf.n_lco_target_868_lo.to_le_bytes()[0])
            .await?;

        // Write N_LCO_TARGET_2G4_HI
        self.write_reg(NLcoTarget2g4Hi::ADDRESS, self.conf.n_lco_target_2g4_hi.to_le_bytes()[0])
            .await?;

        // Write N_LCO_TARGET_2G4_LO
        self.write_reg(NLcoTarget2g4Lo::ADDRESS, self.conf.n_lco_target_2g4_lo.to_le_bytes()[0])
            .await?;

        // Write BAND_BRANCH_CTRL
        self.write_reg(BandBranchCtrl::ADDRESS, self.conf.band_branch_ctrl.to_le_bytes()[0])
            .await?;

        // Write CODE_SELECT
        self.write_reg(CodeSelect::ADDRESS, self.conf.code_select.to_le_bytes()[0])
            .await?;

        // Write KORREL_THRESH_A
        self.write_reg(KorrelThreshA::ADDRESS, self.conf.korrel_thresh_a.to_le_bytes()[0])
            .await?;

        // Write KORREL_THRESH_B
        self.write_reg(KorrelThreshB::ADDRESS, self.conf.korrel_thresh_b.to_le_bytes()[0])
            .await?;

        // Write FDD_ENABLE
        self.write_reg(FddEnable::ADDRESS, self.conf.fdd_enable.to_le_bytes()[0])
            .await?;

        // Write ID_HI
        self.write_reg(IdHi::ADDRESS, self.conf.id_hi.to_le_bytes()[0]).await?;

        // Write ID_LO
        self.write_reg(IdLo::ADDRESS, self.conf.id_lo.to_le_bytes()[0]).await?;

        // Write IDM_ENABLE
        self.write_reg(IdmEnable::ADDRESS, self.conf.idm_enable.to_le_bytes()[0])
            .await?;

        // Write IDM_CTRL
        self.write_reg(IdmCtrl::ADDRESS, self.conf.idm_ctrl.to_le_bytes()[0])
            .await?;

        // Write IDM_CLR (clearing all matches)
        let temp = IdmClr { branch: true };
        self.write_reg(IdmClr::ADDRESS, temp.to_le_bytes()[0]).await?;

        // Write RTC_SELECT
        self.write_reg(RtcSelect::ADDRESS, self.conf.rtc_select.to_le_bytes()[0])
            .await?;

        // Write RTC_CLR (clearing all event entries)
        let temp = RtcClr {
            rtc_clr: Rtc {
                rtclg0: true,
                rtclg1: true,
                rtcsh0: true,
                rtcsh1: true,
            },
        };
        self.write_reg(RtcClr::ADDRESS, temp.to_le_bytes()[0]).await?;

        // Write RTCSH0_THRESH_HI
        self.write_reg(Rtcsh0ThreshHi::ADDRESS, self.conf.rtcsh0_thresh_hi.to_le_bytes()[0])
            .await?;

        // Write RTCSH0_THRESH_LO
        self.write_reg(Rtcsh0ThreshLo::ADDRESS, self.conf.rtcsh0_thresh_lo.to_le_bytes()[0])
            .await?;

        // Write RTCSH1_THRESH_HI
        self.write_reg(Rtcsh1ThreshHi::ADDRESS, self.conf.rtcsh1_thresh_hi.to_le_bytes()[0])
            .await?;

        // Write RTCSH1_THRESH_LO
        self.write_reg(Rtcsh1ThreshLo::ADDRESS, self.conf.rtcsh1_thresh_lo.to_le_bytes()[0])
            .await?;

        // Write RTCLG0_THRESH_4
        self.write_reg(Rtclg0Thresh4::ADDRESS, self.conf.rtclg0_thresh_4.to_le_bytes()[0])
            .await?;

        // Write RTCLG0_THRESH_3
        self.write_reg(Rtclg0Thresh3::ADDRESS, self.conf.rtclg0_thresh_3.to_le_bytes()[0])
            .await?;

        // Write RTCLG0_THRESH_2
        self.write_reg(Rtclg0Thresh2::ADDRESS, self.conf.rtclg0_thresh_2.to_le_bytes()[0])
            .await?;

        // Write RTCLG0_THRESH_1
        self.write_reg(Rtclg0Thresh1::ADDRESS, self.conf.rtclg0_thresh_1.to_le_bytes()[0])
            .await?;

        // Write RTCLG0_THRESH_0
        self.write_reg(Rtclg0Thresh0::ADDRESS, self.conf.rtclg0_thresh_0.to_le_bytes()[0])
            .await?;

        // Write RTCLG1_THRESH_4
        self.write_reg(Rtclg1Thresh4::ADDRESS, self.conf.rtclg1_thresh_4.to_le_bytes()[0])
            .await?;

        // Write RTCLG1_THRESH_3
        self.write_reg(Rtclg1Thresh3::ADDRESS, self.conf.rtclg1_thresh_3.to_le_bytes()[0])
            .await?;

        // Write RTCLG1_THRESH_2
        self.write_reg(Rtclg1Thresh2::ADDRESS, self.conf.rtclg1_thresh_2.to_le_bytes()[0])
            .await?;

        // Write RTCLG1_THRESH_1
        self.write_reg(Rtclg1Thresh1::ADDRESS, self.conf.rtclg1_thresh_1.to_le_bytes()[0])
            .await?;

        // Write RTCLG1_THRESH_0
        self.write_reg(Rtclg1Thresh0::ADDRESS, self.conf.rtclg1_thresh_0.to_le_bytes()[0])
            .await?;

        // Write CYCLPRESC
        self.write_reg(Cyclpresc::ADDRESS, self.conf.cyclpresc.to_le_bytes()[0])
            .await?;

        // Write CYCLTOP_HI
        self.write_reg(CycltopHi::ADDRESS, self.conf.cycltop_hi.to_le_bytes()[0])
            .await?;

        // Write CYCLTOP_LO
        self.write_reg(CycltopLo::ADDRESS, self.conf.cycltop_lo.to_le_bytes()[0])
            .await?;

        // Write CNTR40_CLR (clearing counter CNTR40)
        let temp = Cntr40Clr { clr: true };
        self.write_reg(Cntr40Clr::ADDRESS, temp.to_le_bytes()[0]).await?;

        // Write FIFO_LENGTH
        self.write_reg(FifoLength::ADDRESS, self.conf.fifo_length.to_le_bytes()[0])
            .await?;

        // Write FIFO_COUNT_433 (clearing to 0)
        let temp = FifoCount433 { data: 0 };
        self.write_reg(FifoCount433::ADDRESS, temp.to_le_bytes()[0]).await?;

        // Write FIFO_COUNT_868 (clearing to 0)
        let temp = FifoCount868 { data: 0 };
        self.write_reg(FifoCount868::ADDRESS, temp.to_le_bytes()[0]).await?;

        // Write FIFO_COUNT_2G4 (clearing to 0)
        let temp = FifoCount2g4 { data: 0 };
        self.write_reg(FifoCount2g4::ADDRESS, temp.to_le_bytes()[0]).await?;

        // Write GENPURP_1
        self.write_reg(Genpurp1::ADDRESS, self.conf.genpurp_1.to_le_bytes()[0])
            .await?;

        // Write XTAL_OSC_CTRL
        self.write_reg(XtalOscCtrl::ADDRESS, self.conf.xtal_osc_ctrl.to_le_bytes()[0])
            .await?;

        // Write LDO_XTAL_CTRL
        self.write_reg(LdoXtalCtrl::ADDRESS, self.conf.ldo_xtal_ctrl.to_le_bytes()[0])
            .await?;

        // Write MUX_D_OUT_SEL
        self.write_reg(MuxDOutSel::ADDRESS, self.conf.mux_d_out_sel.to_le_bytes()[0])
            .await?;

        // Write KORREL_SV_CLEAR (clear KORREL_STATE)
        let temp = KorrelSvClear { data: true };
        self.write_reg(KorrelSvClear::ADDRESS, temp.to_le_bytes()[0]).await?;

        // Write IRQ_SELECT
        self.write_reg(IrqSelect::ADDRESS, self.conf.irq_select.to_le_bytes()[0])
            .await?;

        Ok(())
    }
}

pub struct LcoCalibData {
    pub band_433: Option<u16>,
    pub band_868: Option<u16>,
    pub band_2g4: Option<u16>,
}
