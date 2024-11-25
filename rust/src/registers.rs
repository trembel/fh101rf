#![allow(clippy::unnecessary_cast)]
#![allow(clippy::module_name_repetitions)]
#![allow(unused_imports)]
//! # `FH101RF` Registers.
//!
//! ## Infos
//!
//! Generated using reginald from `../../fh101rf.yaml`.
//! 
//! Listing file author: Jonah Imfeld, Silvano Cortesi
//!
//! Listing file notice:
//!   Licensed under LGPL-3.0
//!   File Version: 1.0.0
//!
//! ## Register Overview
//! | Address | Name                 | Brief                                                                                                                                                                                          |
//! | ------- | -------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
//! | 0x00    | [`Nfa433Slow`]       | Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 433-MHz band.                                                      |
//! | 0x01    | [`Nfa433Fast`]       | Set the sample-rate for FDD-mode data reception in the 433-MHz band.                                                                                                                           |
//! | 0x02    | [`Nfa868Slow`]       | Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 868-MHz band.                                                      |
//! | 0x03    | [`Nfa868Fast`]       | Set the sample-rate for FDD-mode data reception in the 868-MHz band.                                                                                                                           |
//! | 0x04    | [`Nfa2g4Slow`]       | Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 2.4-GHz band.                                                      |
//! | 0x05    | [`Nfa2g4Fast`]       | Set the sample-rate for FDD-mode data reception in the 2.4-GHz band.                                                                                                                           |
//! | 0x06    | [`CalibStatus`]      | Indicates status of all calibration processes.                                                                                                                                                 |
//! | 0x07    | [`CalibCtrl`]        | Control register for starting calibration processes.                                                                                                                                           |
//! | 0x09    | [`NSpgTarget`]       | Target register for the Signal Processing Gain setting. Set to 0x46 during SPG calibration.                                                                                                    |
//! | 0x0B    | [`NLcoTarget433Hi`]  | Sets the high byte (15:8) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891. (According to register table in DS v1.3b, only 12:8).       |
//! | 0x0C    | [`NLcoTarget433Lo`]  | Sets the low byte (7:0) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891.                                                               |
//! | 0x0D    | [`NLcoTarget868Hi`]  | Sets the high byte (15:8) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738. (According to register table in DS v1.3b, only 12:8).   |
//! | 0x0E    | [`NLcoTarget868Lo`]  | Sets the low byte (7:0) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738.                                                           |
//! | 0x0F    | [`NLcoTarget2g4Hi`]  | Sets the high byte (15:8) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833. (According to register table in DS v1.3b, only 12:8).      |
//! | 0x10    | [`NLcoTarget2g4Lo`]  | Sets the low byte (7:0) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833.                                                              |
//! | 0x14    | [`LcoFreq433Hi`]     | Holds the current frequency of the 433-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).              |
//! | 0x15    | [`LcoFreq433Lo`]     | Holds the current frequency of the 433-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.                                                                      |
//! | 0x16    | [`LcoFreq868Hi`]     | Holds the current frequency of the 868/915-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).          |
//! | 0x17    | [`LcoFreq868Lo`]     | Holds the current frequency of the 868/915-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.                                                                  |
//! | 0x18    | [`LcoFreq2g4Hi`]     | Holds the current frequency of the 2.4-GHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).              |
//! | 0x19    | [`LcoFreq2g4Lo`]     | Holds the current frequency of the 2.4-GHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.                                                                      |
//! | 0x23    | [`DCornerCtrl`]      | Set to 0x02 at power-up.                                                                                                                                                                       |
//! | 0x24    | [`BandBranchCtrl`]   | Selects the active bands and branches (RF-sensitivity).                                                                                                                                        |
//! | 0x28    | [`CodeSelect`]       | Selects the correlation patterns for code A and B.                                                                                                                                             |
//! | 0x29    | [`KorrelThreshA`]    | Sets the threshold for a code A match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).                   |
//! | 0x2A    | [`KorrelThreshB`]    | Sets the threshold for a code B match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).                   |
//! | 0x2B    | [`KorrelState`]      |                                                                                                                                                                                                |
//! | 0x2C    | [`KorrelVal`]        | Indicates the match level for code A and B. A value of 15 indicates no bit errors, a value of 0 indicates 15 bit errors.                                                                       |
//! | 0x2D    | [`FddEnable`]        | Enable the fast data decoder for a given band.                                                                                                                                                 |
//! | 0x2E    | [`FddActive`]        | Reads the FDD mode for each band.                                                                                                                                                              |
//! | 0x2F    | [`FoQuit`]           | Forces the specified band to quit fast mode immediately.                                                                                                                                       |
//! | 0x30    | [`FddExitCond`]      | Holds the FDD exit condition for all the bands.                                                                                                                                                |
//! | 0x31    | [`IrqSelect`]        | Selects the interrupt sources.                                                                                                                                                                 |
//! | 0x32    | [`IrqStatus`]        | Holds the status of the IRQ events.                                                                                                                                                            |
//! | 0x33    | [`IrqClr`]           | Resets the corresponding IRQ event bit.                                                                                                                                                        |
//! | 0x34    | [`IrqSet`]           | Sets the corresponding IRQ event bit (triggers IRQ events for debugging).                                                                                                                      |
//! | 0x35    | [`IdHi`]             | Sets the high byte of the match ID. 4-MSB form the group ID.                                                                                                                                   |
//! | 0x36    | [`IdLo`]             | Sets the low byte of the match ID.                                                                                                                                                             |
//! | 0x37    | [`IdmEnable`]        | Enables the ID match for a given band.                                                                                                                                                         |
//! | 0x38    | [`IdmCtrl`]          | Slect the type of ID's accepted by the receiver.                                                                                                                                               |
//! | 0x39    | [`IdmClr`]           | Clear the FDD_EXIT_COND register.                                                                                                                                                              |
//! | 0x3A    | [`IdmBand`]          | Indicates the frequency band of the ID match event.                                                                                                                                            |
//! | 0x3B    | [`IdmReason`]        | Indicates the type of ID match event.                                                                                                                                                          |
//! | 0x3C    | [`RtcSelect`]        | Allows for selection of the desired timer modes.                                                                                                                                               |
//! | 0x3D    | [`RtcStatus`]        | Indicates occurence of RTC events.                                                                                                                                                             |
//! | 0x3E    | [`RtcClr`]           | Clears the respective event entries in RTC_STATUS.                                                                                                                                             |
//! | 0x3F    | [`Rtcsh0ThreshHi`]   | Upper (Bits 15:8) byte of the RTCSH0 threshold.                                                                                                                                                |
//! | 0x40    | [`Rtcsh0ThreshLo`]   | Lower (Bits 7:0) byte of the RTCSH0 threshold.                                                                                                                                                 |
//! | 0x41    | [`Rtcsh1ThreshHi`]   | Upper (Bits 15:8) byte of the RTCSH1 threshold.                                                                                                                                                |
//! | 0x42    | [`Rtcsh1ThreshLo`]   | Lower (Bits 7:0) byte of the RTCSH1 threshold.                                                                                                                                                 |
//! | 0x43    | [`Rtclg0Thresh4`]    | Bits 39:32 of the RTCLG0 threshold.                                                                                                                                                            |
//! | 0x44    | [`Rtclg0Thresh3`]    | Bits 31:24 of the RTCLG0 threshold.                                                                                                                                                            |
//! | 0x45    | [`Rtclg0Thresh2`]    | Bits 23:16 of the RTCLG0 threshold.                                                                                                                                                            |
//! | 0x46    | [`Rtclg0Thresh1`]    | Bits 15:8 of the RTCLG0 threshold.                                                                                                                                                             |
//! | 0x47    | [`Rtclg0Thresh0`]    | Bits 7:0 of the RTCLG0 threshold.                                                                                                                                                              |
//! | 0x48    | [`Rtclg1Thresh4`]    | Bits 39:32 of the RTCLG1 threshold.                                                                                                                                                            |
//! | 0x49    | [`Rtclg1Thresh3`]    | Bits 31:24 of the RTCLG1 threshold.                                                                                                                                                            |
//! | 0x4A    | [`Rtclg1Thresh2`]    | Bits 23:16 of the RTCLG1 threshold.                                                                                                                                                            |
//! | 0x4B    | [`Rtclg1Thresh1`]    | Bits 15:8 of the RTCLG1 threshold.                                                                                                                                                             |
//! | 0x4C    | [`Rtclg1Thresh0`]    | Bits 7:0 of the RTCLG1 threshold.                                                                                                                                                              |
//! | 0x4D    | [`Cyclpresc`]        | Cycle prescaler for cyclic counter, system clock divided by prescaler (therefore max 8:29.9922 minutes).                                                                                       |
//! | 0x4E    | [`CycltopHi`]        | Bits 15:8 defining the maximal cyclic counter value CYCLTOP before being reset to zero.                                                                                                        |
//! | 0x4F    | [`CycltopLo`]        | Bits 7:0 defining the maximal cyclic counter value CYCLTOP before being reset to zero.                                                                                                         |
//! | 0x50    | [`Cntr404`]          | Bits 39:32 of the system clock counter CNTR40.                                                                                                                                                 |
//! | 0x51    | [`Cntr403`]          | Bits 31:24 of the system clock counter CNTR40.                                                                                                                                                 |
//! | 0x52    | [`Cntr402`]          | Bits 23:16 of the system clock counter CNTR40.                                                                                                                                                 |
//! | 0x53    | [`Cntr401`]          | Bits 15:8 of the system clock counter CNTR40.                                                                                                                                                  |
//! | 0x54    | [`Cntr400`]          | Bits 7:0 of the system clock counter CNTR40.                                                                                                                                                   |
//! | 0x55    | [`Cntr40Clr`]        | Clear the system clock counter CNTR40 by setting this to true. Manually setting the register to false afterwards is mandatory!                                                                 |
//! | 0x56    | [`FifoLength`]       | Selects the FIFO length for each band.                                                                                                                                                         |
//! | 0x57    | [`FifoCount433`]     | Number of bits in the FIFO buffer for the 433MHz band. Can be cleared by writing 0.                                                                                                            |
//! | 0x58    | [`FifoCount868`]     | Number of bits in the FIFO buffer for the 868/915MHz band. Can be cleared by writing 0.                                                                                                        |
//! | 0x59    | [`FifoCount2g4`]     | Number of bits in the FIFO buffer for the 2.4GHz band. Can be cleared by writing 0.                                                                                                            |
//! | 0x5A    | [`RxFifo5433`]       | The FIFO byte 5 for the 433MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x5B    | [`RxFifo4433`]       | The FIFO byte 4 for the 433MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x5C    | [`RxFifo3433`]       | The FIFO byte 3 for the 433MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x5D    | [`RxFifo2433`]       | The FIFO byte 2 for the 433MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x5E    | [`RxFifo1433`]       | The FIFO byte 1 for the 433MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x5F    | [`RxFifo0433`]       | The FIFO byte 0 for the 433MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x60    | [`RxFifo5868`]       | The FIFO byte 5 for the 868MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x61    | [`RxFifo4868`]       | The FIFO byte 4 for the 868MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x62    | [`RxFifo3868`]       | The FIFO byte 3 for the 868MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x63    | [`RxFifo2868`]       | The FIFO byte 2 for the 868MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x64    | [`RxFifo1868`]       | The FIFO byte 1 for the 868MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x65    | [`RxFifo0868`]       | The FIFO byte 0 for the 868MHz band, _5 is filled first.                                                                                                                                       |
//! | 0x66    | [`RxFifo52g4`]       | The FIFO byte 5 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
//! | 0x67    | [`RxFifo42g4`]       | The FIFO byte 4 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
//! | 0x68    | [`RxFifo32g4`]       | The FIFO byte 3 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
//! | 0x69    | [`RxFifo22g4`]       | The FIFO byte 2 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
//! | 0x6A    | [`RxFifo12g4`]       | The FIFO byte 1 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
//! | 0x6B    | [`RxFifo02g4`]       | The FIFO byte 0 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
//! | 0x6C    | [`ActualNfa433`]     | This register contains the actual NFA (sampling rate) value that is currently valid for 433MHz data reception.                                                                                 |
//! | 0x6D    | [`ActualNfa868`]     | This register contains the actual NFA (sampling rate) value that is currently valid for 868MHz data reception.                                                                                 |
//! | 0x6E    | [`ActualNfa2g4`]     | This register contains the actual NFA (sampling rate) value that is currently valid for 2.4GHz data reception.                                                                                 |
//! | 0x6F    | [`ActualBandselect`] | This 3 bit register contains the actual selected frequency bands that are currently used.                                                                                                      |
//! | 0x71    | [`Genpurp1`]         | 8 bits free to use for read/write. (Register table says only write).                                                                                                                           |
//! | 0x73    | [`XtalOscCtrl`]      | Enables the built-in crystal oscillator driving a 2-pin crystal device.                                                                                                                        |
//! | 0x74    | [`LdoXtalCtrl`]      | Controls the LDO and the crystal oscillator.                                                                                                                                                   |
//! | 0x75    | [`MuxDOutSel`]       | Selects the signal routed to the GPO1 and GPO2 pins.                                                                                                                                           |
//! | 0x76    | [`LcTgEna`]          | Set to 0x00 during power-up.                                                                                                                                                                   |
//! | 0x77    | [`XtalGood`]         | Reads as true if the clock source is stable.                                                                                                                                                   |
//! | 0x78    | [`CompThreshW`]      | Set this register to 0xA before executing the comparator calibration.                                                                                                                          |
//! | 0x7C    | [`KorrelSvClear`]    | Set true to clear the KORREL_STATE and KORREL_VAL registers.                                                                                                                                   |
//! | 0x7F    | [`Version`]          | Holds the version number of the IC, currently 0x41.                                                                                                                                            |

// ==== Traits =================================================================

use core::convert::Infallible;
use core::fmt::{Debug, Display};

// Struct to bytes converstion:
pub trait ToBytes<const N: usize>: Sized {
    fn to_le_bytes(&self) -> [u8; N];

    #[inline(always)]
    fn to_be_bytes(&self) -> [u8; N] {
        let mut val = self.to_le_bytes();
        val.reverse();
        val
    }
}

// Bytes to struct conversion (fallible):
pub trait TryFromBytes<const N: usize>: Sized {
    type Error;

    fn try_from_le_bytes(val: &[u8; N]) -> Result<Self, Self::Error>;

    #[inline(always)]
    fn try_from_be_bytes(val: &[u8; N]) -> Result<Self, Self::Error> {
        let mut val = *val;
        val.reverse();
        Self::try_from_le_bytes(&val)
    }
}

// Bytes to struct conversion (infallible):
pub trait FromBytes<const N: usize>: Sized {
    fn from_le_bytes(val: &[u8; N]) -> Self;

    #[inline(always)]
    fn from_be_bytes(val: &[u8; N]) -> Self {
        let mut val = *val;
        val.reverse();
        Self::from_le_bytes(&val)
    }
}

// Implement fallible conversion for infallible conversion:
impl<const N: usize, T> TryFromBytes<N> for T
where
    T: FromBytes<N>,
{
    type Error = Infallible;

    #[inline(always)]
    fn try_from_le_bytes(val: &[u8; N]) -> Result<Self, Self::Error> {
        Ok(Self::from_le_bytes(val))
    }

    #[inline(always)]
    fn try_from_be_bytes(val: &[u8; N]) -> Result<Self, Self::Error> {
        Ok(Self::from_be_bytes(val))
    }
}

// Bytes to struct conversion (infallible, but possibly lossy):
pub trait FromMaskedBytes<const N: usize>: Sized {
    fn from_masked_le_bytes(val: &[u8; N]) -> Self;

    #[inline(always)]
    fn from_masked_be_bytes(val: &[u8; N]) -> Self {
        let mut val = *val;
        val.reverse();
        Self::from_masked_le_bytes(&val)
    }
}

// Implement possibly conversion for infallible conversion:
impl<const N: usize, T> FromMaskedBytes<N> for T
where
    T: FromBytes<N>,
{
    fn from_masked_le_bytes(val: &[u8; N]) -> Self {
        Self::from_le_bytes(val)
    }

    #[inline(always)]
    fn from_masked_be_bytes(val: &[u8; N]) -> Self {
        Self::from_be_bytes(val)
    }
}

// Errors:
#[derive(Debug, PartialEq, Clone)]
pub struct FromBytesError {
    pub pos: usize,
}

impl Display for FromBytesError {
    fn fmt(&self, f: &mut core::fmt::Formatter<'_>) -> core::fmt::Result {
        write!(f, "Failed to unpack field at bit {}", self.pos)
    }
}

// Register properties:
pub enum ResetVal<const N: usize> {
    BigEndian([u8; N]),
    LittleEndian([u8; N]),
}

pub trait Register<const N: usize, A> {
    const ADDRESS: A;
    const RESET_VAL: Option<ResetVal<N>>;

    fn reset_val_le() -> Option<[u8; N]> {
        match Self::RESET_VAL {
            None => None,
            Some(ResetVal::LittleEndian(val_le)) => Some(val_le),
            Some(ResetVal::BigEndian(val)) => {
                let mut val = val;
                val.reverse();
                Some(val)
            }
        }
    }

    fn reset_val_be() -> Option<[u8; N]> {
        match Self::RESET_VAL {
            None => None,
            Some(ResetVal::LittleEndian(val)) => {
                let mut val = val;
                val.reverse();
                Some(val)
            }
            Some(ResetVal::BigEndian(val_be)) => Some(val_be),
        }
    }
}

// ==== `NFA433_SLOW` Register =================================================

/// `NFA433_SLOW` Register
///
/// Address: 0x0
///
/// Reset Value: 0x5
///
/// Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 433-MHz band.
#[derive(Debug, PartialEq)]
pub struct Nfa433Slow {
    /// Bits: `[2:0]`
    pub data: SampleRate,
}

/// Register Properties
impl Register<1, u8> for Nfa433Slow {
    const ADDRESS: u8 = 0x0;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x5]));
}

/// Reset Value
impl Default for Nfa433Slow {
    fn default() -> Self {
        Self {
            data: SampleRate::Sr1024,
        }
    }
}

// ==== `NFA433_FAST` Register =================================================

/// `NFA433_FAST` Register
///
/// Address: 0x1
///
/// Reset Value: 0x0
///
/// Set the sample-rate for FDD-mode data reception in the 433-MHz band.
#[derive(Debug, PartialEq)]
pub struct Nfa433Fast {
    /// Bits: `[2:0]`
    pub data: SampleRate,
}

/// Register Properties
impl Register<1, u8> for Nfa433Fast {
    const ADDRESS: u8 = 0x1;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Nfa433Fast {
    fn default() -> Self {
        Self {
            data: SampleRate::Sr32768,
        }
    }
}

// ==== `NFA868_SLOW` Register =================================================

/// `NFA868_SLOW` Register
///
/// Address: 0x2
///
/// Reset Value: 0x5
///
/// Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 868-MHz band.
#[derive(Debug, PartialEq)]
pub struct Nfa868Slow {
    /// Bits: `[2:0]`
    pub data: SampleRate,
}

/// Register Properties
impl Register<1, u8> for Nfa868Slow {
    const ADDRESS: u8 = 0x2;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x5]));
}

/// Reset Value
impl Default for Nfa868Slow {
    fn default() -> Self {
        Self {
            data: SampleRate::Sr1024,
        }
    }
}

// ==== `NFA868_FAST` Register =================================================

/// `NFA868_FAST` Register
///
/// Address: 0x3
///
/// Reset Value: 0x0
///
/// Set the sample-rate for FDD-mode data reception in the 868-MHz band.
#[derive(Debug, PartialEq)]
pub struct Nfa868Fast {
    /// Bits: `[2:0]`
    pub data: SampleRate,
}

/// Register Properties
impl Register<1, u8> for Nfa868Fast {
    const ADDRESS: u8 = 0x3;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Nfa868Fast {
    fn default() -> Self {
        Self {
            data: SampleRate::Sr32768,
        }
    }
}

// ==== `NFA2G4_SLOW` Register =================================================

/// `NFA2G4_SLOW` Register
///
/// Address: 0x4
///
/// Reset Value: 0x5
///
/// Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 2.4-GHz band.
#[derive(Debug, PartialEq)]
pub struct Nfa2g4Slow {
    /// Bits: `[2:0]`
    pub data: SampleRate,
}

/// Register Properties
impl Register<1, u8> for Nfa2g4Slow {
    const ADDRESS: u8 = 0x4;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x5]));
}

/// Reset Value
impl Default for Nfa2g4Slow {
    fn default() -> Self {
        Self {
            data: SampleRate::Sr1024,
        }
    }
}

// ==== `NFA2G4_FAST` Register =================================================

/// `NFA2G4_FAST` Register
///
/// Address: 0x5
///
/// Reset Value: 0x0
///
/// Set the sample-rate for FDD-mode data reception in the 2.4-GHz band.
#[derive(Debug, PartialEq)]
pub struct Nfa2g4Fast {
    /// Bits: `[2:0]`
    pub data: SampleRate,
}

/// Register Properties
impl Register<1, u8> for Nfa2g4Fast {
    const ADDRESS: u8 = 0x5;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Nfa2g4Fast {
    fn default() -> Self {
        Self {
            data: SampleRate::Sr32768,
        }
    }
}

// ==== `CALIB_STATUS` Register ================================================

/// `CALIB_STATUS` Register
///
/// Address: 0x6
///
/// Reset Value: 0x0
///
/// Indicates status of all calibration processes.
#[derive(Debug, PartialEq)]
pub struct CalibStatus {
    /// Indicates general calibration process in progress.
    ///
    /// Bits: `[0]`
    pub cal_in_prog: bool,
    /// Indicates LCO calibration in progress.
    ///
    /// Bits: `[1]`
    pub lco_cal_in_prog: bool,
    /// Indicates Offset calubration in progress.
    ///
    /// Bits: `[3]`
    pub offset_cal_in_prog: bool,
    /// Indicates SPG calibration in progress.
    ///
    /// Bits: `[2]`
    pub spg_cal_in_prog: bool,
}

/// Register Properties
impl Register<1, u8> for CalibStatus {
    const ADDRESS: u8 = 0x6;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for CalibStatus {
    fn default() -> Self {
        Self {
            cal_in_prog: false,
            lco_cal_in_prog: false,
            offset_cal_in_prog: false,
            spg_cal_in_prog: false,
        }
    }
}

// ==== `CALIB_CTRL` Register ==================================================

/// `CALIB_CTRL` Register
///
/// Address: 0x7
///
/// Reset Value: 0xE
///
/// Control register for starting calibration processes.
#[derive(Debug, PartialEq)]
pub struct CalibCtrl {
    /// Starts the calibration process.
    ///
    /// Bits: `[0]`
    pub cal_start: bool,
    /// Control bit for initiating LCO calibration.
    ///
    /// Bits: `[1]`
    pub lco_cal: bool,
    /// Control bit for initiating offset calibration.
    ///
    /// Bits: `[3]`
    pub offset_cal: bool,
    /// Control bit for initiating SPG calibration.
    ///
    /// Bits: `[2]`
    pub spg_cal: bool,
}

/// Register Properties
impl Register<1, u8> for CalibCtrl {
    const ADDRESS: u8 = 0x7;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0xE]));
}

/// Reset Value
impl Default for CalibCtrl {
    fn default() -> Self {
        Self {
            cal_start: false,
            lco_cal: true,
            offset_cal: true,
            spg_cal: true,
        }
    }
}

// ==== `N_SPG_TARGET` Register ================================================

/// `N_SPG_TARGET` Register
///
/// Address: 0x9
///
/// Reset Value: 0x31
///
/// Target register for the Signal Processing Gain setting. Set to 0x46 during SPG calibration.
#[derive(Debug, PartialEq)]
pub struct NSpgTarget {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for NSpgTarget {
    const ADDRESS: u8 = 0x9;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x31]));
}

/// Reset Value
impl Default for NSpgTarget {
    fn default() -> Self {
        Self {
            data: 0x31,
        }
    }
}

// ==== `N_LCO_TARGET_433_HI` Register =========================================

/// `N_LCO_TARGET_433_HI` Register
///
/// Address: 0xB
///
/// Reset Value: 0xE
///
/// Sets the high byte (15:8) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891. (According to register table in DS v1.3b, only 12:8).
#[derive(Debug, PartialEq)]
pub struct NLcoTarget433Hi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for NLcoTarget433Hi {
    const ADDRESS: u8 = 0xB;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0xE]));
}

/// Reset Value
impl Default for NLcoTarget433Hi {
    fn default() -> Self {
        Self {
            data: 0xE,
        }
    }
}

// ==== `N_LCO_TARGET_433_LO` Register =========================================

/// `N_LCO_TARGET_433_LO` Register
///
/// Address: 0xC
///
/// Reset Value: 0x20
///
/// Sets the low byte (7:0) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891.
#[derive(Debug, PartialEq)]
pub struct NLcoTarget433Lo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for NLcoTarget433Lo {
    const ADDRESS: u8 = 0xC;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x20]));
}

/// Reset Value
impl Default for NLcoTarget433Lo {
    fn default() -> Self {
        Self {
            data: 0x20,
        }
    }
}

// ==== `N_LCO_TARGET_868_HI` Register =========================================

/// `N_LCO_TARGET_868_HI` Register
///
/// Address: 0xD
///
/// Reset Value: 0xD
///
/// Sets the high byte (15:8) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738. (According to register table in DS v1.3b, only 12:8).
#[derive(Debug, PartialEq)]
pub struct NLcoTarget868Hi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for NLcoTarget868Hi {
    const ADDRESS: u8 = 0xD;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0xD]));
}

/// Reset Value
impl Default for NLcoTarget868Hi {
    fn default() -> Self {
        Self {
            data: 0xD,
        }
    }
}

// ==== `N_LCO_TARGET_868_LO` Register =========================================

/// `N_LCO_TARGET_868_LO` Register
///
/// Address: 0xE
///
/// Reset Value: 0x87
///
/// Sets the low byte (7:0) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738.
#[derive(Debug, PartialEq)]
pub struct NLcoTarget868Lo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for NLcoTarget868Lo {
    const ADDRESS: u8 = 0xE;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x87]));
}

/// Reset Value
impl Default for NLcoTarget868Lo {
    fn default() -> Self {
        Self {
            data: 0x87,
        }
    }
}

// ==== `N_LCO_TARGET_2G4_HI` Register =========================================

/// `N_LCO_TARGET_2G4_HI` Register
///
/// Address: 0xF
///
/// Reset Value: 0x12
///
/// Sets the high byte (15:8) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833. (According to register table in DS v1.3b, only 12:8).
#[derive(Debug, PartialEq)]
pub struct NLcoTarget2g4Hi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for NLcoTarget2g4Hi {
    const ADDRESS: u8 = 0xF;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x12]));
}

/// Reset Value
impl Default for NLcoTarget2g4Hi {
    fn default() -> Self {
        Self {
            data: 0x12,
        }
    }
}

// ==== `N_LCO_TARGET_2G4_LO` Register =========================================

/// `N_LCO_TARGET_2G4_LO` Register
///
/// Address: 0x10
///
/// Reset Value: 0xCE
///
/// Sets the low byte (7:0) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833.
#[derive(Debug, PartialEq)]
pub struct NLcoTarget2g4Lo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for NLcoTarget2g4Lo {
    const ADDRESS: u8 = 0x10;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0xCE]));
}

/// Reset Value
impl Default for NLcoTarget2g4Lo {
    fn default() -> Self {
        Self {
            data: 0xCE,
        }
    }
}

// ==== `LCO_FREQ_433_HI` Register =============================================

/// `LCO_FREQ_433_HI` Register
///
/// Address: 0x14
///
/// Reset Value: 0x0
///
/// Holds the current frequency of the 433-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).
#[derive(Debug, PartialEq)]
pub struct LcoFreq433Hi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for LcoFreq433Hi {
    const ADDRESS: u8 = 0x14;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for LcoFreq433Hi {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `LCO_FREQ_433_LO` Register =============================================

/// `LCO_FREQ_433_LO` Register
///
/// Address: 0x15
///
/// Reset Value: 0x0
///
/// Holds the current frequency of the 433-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.
#[derive(Debug, PartialEq)]
pub struct LcoFreq433Lo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for LcoFreq433Lo {
    const ADDRESS: u8 = 0x15;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for LcoFreq433Lo {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `LCO_FREQ_868_HI` Register =============================================

/// `LCO_FREQ_868_HI` Register
///
/// Address: 0x16
///
/// Reset Value: 0x0
///
/// Holds the current frequency of the 868/915-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).
#[derive(Debug, PartialEq)]
pub struct LcoFreq868Hi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for LcoFreq868Hi {
    const ADDRESS: u8 = 0x16;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for LcoFreq868Hi {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `LCO_FREQ_868_LO` Register =============================================

/// `LCO_FREQ_868_LO` Register
///
/// Address: 0x17
///
/// Reset Value: 0x0
///
/// Holds the current frequency of the 868/915-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.
#[derive(Debug, PartialEq)]
pub struct LcoFreq868Lo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for LcoFreq868Lo {
    const ADDRESS: u8 = 0x17;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for LcoFreq868Lo {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `LCO_FREQ_2G4_HI` Register =============================================

/// `LCO_FREQ_2G4_HI` Register
///
/// Address: 0x18
///
/// Reset Value: 0x0
///
/// Holds the current frequency of the 2.4-GHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).
#[derive(Debug, PartialEq)]
pub struct LcoFreq2g4Hi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for LcoFreq2g4Hi {
    const ADDRESS: u8 = 0x18;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for LcoFreq2g4Hi {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `LCO_FREQ_2G4_LO` Register =============================================

/// `LCO_FREQ_2G4_LO` Register
///
/// Address: 0x19
///
/// Reset Value: 0x0
///
/// Holds the current frequency of the 2.4-GHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.
#[derive(Debug, PartialEq)]
pub struct LcoFreq2g4Lo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for LcoFreq2g4Lo {
    const ADDRESS: u8 = 0x19;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for LcoFreq2g4Lo {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `D_CORNER_CTRL` Register ===============================================

/// `D_CORNER_CTRL` Register
///
/// Address: 0x23
///
/// Reset Value: 0x0
///
/// Set to 0x02 at power-up.
#[derive(Debug, PartialEq)]
pub struct DCornerCtrl {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for DCornerCtrl {
    const ADDRESS: u8 = 0x23;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for DCornerCtrl {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `BAND_BRANCH_CTRL` Register ============================================

/// `BAND_BRANCH_CTRL` Register
///
/// Address: 0x24
///
/// Reset Value: 0x77
///
/// Selects the active bands and branches (RF-sensitivity).
#[derive(Debug, PartialEq)]
pub struct BandBranchCtrl {
    /// Selects the active bands.
    ///
    /// Bits: `[6:4]`
    pub active_bands: Bands,
    /// Selects the active detection branches.
    ///
    /// Bits: `[2:0]`
    pub active_branches: Branches,
}

/// Register Properties
impl Register<1, u8> for BandBranchCtrl {
    const ADDRESS: u8 = 0x24;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x77]));
}

/// Reset Value
impl Default for BandBranchCtrl {
    fn default() -> Self {
        Self {
            active_bands: Bands {
                band_2g4: true,
                band_433: true,
                band_868: true,
            },
            active_branches: Branches {
                medium: true,
                strong: true,
                weak: true,
            },
        }
    }
}

// ==== `CODE_SELECT` Register =================================================

/// `CODE_SELECT` Register
///
/// Address: 0x28
///
/// Reset Value: 0x10
///
/// Selects the correlation patterns for code A and B.
#[derive(Debug, PartialEq)]
pub struct CodeSelect {
    /// Selects the correlation pattern for code A.
    ///
    /// Bits: `[3:0]`
    pub a: BinCode,
    /// Selects the correlation pattern for code B.
    ///
    /// Bits: `[7:4]`
    pub b: BinCode,
}

/// Register Properties
impl Register<1, u8> for CodeSelect {
    const ADDRESS: u8 = 0x28;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x10]));
}

/// Reset Value
impl Default for CodeSelect {
    fn default() -> Self {
        Self {
            a: BinCode::A,
            b: BinCode::B,
        }
    }
}

// ==== `KORREL_THRESH_A` Register =============================================

/// `KORREL_THRESH_A` Register
///
/// Address: 0x29
///
/// Reset Value: 0x1A
///
/// Sets the threshold for a code A match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).
#[derive(Debug, PartialEq)]
pub struct KorrelThreshA {
    /// Bits: `[4:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for KorrelThreshA {
    const ADDRESS: u8 = 0x29;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x1A]));
}

/// Reset Value
impl Default for KorrelThreshA {
    fn default() -> Self {
        Self {
            data: 0x1A,
        }
    }
}

// ==== `KORREL_THRESH_B` Register =============================================

/// `KORREL_THRESH_B` Register
///
/// Address: 0x2A
///
/// Reset Value: 0x1A
///
/// Sets the threshold for a code B match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).
#[derive(Debug, PartialEq)]
pub struct KorrelThreshB {
    /// Bits: `[4:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for KorrelThreshB {
    const ADDRESS: u8 = 0x2A;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x1A]));
}

/// Reset Value
impl Default for KorrelThreshB {
    fn default() -> Self {
        Self {
            data: 0x1A,
        }
    }
}

// ==== `KORREL_STATE` Register ================================================

/// `KORREL_STATE` Register
///
/// Address: 0x2B
///
/// Reset Value: 0xC0
#[derive(Debug, PartialEq)]
pub struct KorrelState {
    /// Indicates receiver branch that had contributed for Code A recognition
    ///
    /// Bits: `[2:0]`
    pub korrel_branches_a: Branches,
    /// Indicates receiver branch that had contributed for Code B recognition
    ///
    /// Bits: `[5:3]`
    pub korrel_branches_b: Branches,
    /// Indicates frequency band for latest correlator
    ///
    /// Bits: `[7:6]`
    pub korrel_branches_latest: KorrelBranchesLatest,
}

// Register-specific sub-layouts:
/// Indicates frequency band for latest correlator
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum KorrelBranchesLatest {
    /// Band 2.4GHz matched.
    Band2g4, // 0x2
    /// Band 433MHz matched.
    Band433, // 0x0
    /// Band 868/915MHz matched.
    Band868, // 0x1
}

/// Register Properties
impl Register<1, u8> for KorrelState {
    const ADDRESS: u8 = 0x2B;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0xC0]));
}

// ==== `KORREL_VAL` Register ==================================================

/// `KORREL_VAL` Register
///
/// Address: 0x2C
///
/// Reset Value: 0x0
///
/// Indicates the match level for code A and B. A value of 15 indicates no bit errors, a value of 0 indicates 15 bit errors.
#[derive(Debug, PartialEq)]
pub struct KorrelVal {
    /// Indicates the match level for code A. Refreshed after a positive Code A match. Typically >5
    ///
    /// Bits: `[3:0]`
    pub a: u8,
    /// Indicates the match level for code B. Refreshed after a positive Code B match. Typically >5
    ///
    /// Bits: `[7:4]`
    pub b: u8,
}

/// Register Properties
impl Register<1, u8> for KorrelVal {
    const ADDRESS: u8 = 0x2C;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for KorrelVal {
    fn default() -> Self {
        Self {
            a: 0x0,
            b: 0x0,
        }
    }
}

// ==== `FDD_ENABLE` Register ==================================================

/// `FDD_ENABLE` Register
///
/// Address: 0x2D
///
/// Reset Value: 0x7
///
/// Enable the fast data decoder for a given band.
#[derive(Debug, PartialEq)]
pub struct FddEnable {
    /// Bits: `[2:0]`
    pub fdd_bands: Bands,
}

/// Register Properties
impl Register<1, u8> for FddEnable {
    const ADDRESS: u8 = 0x2D;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x7]));
}

/// Reset Value
impl Default for FddEnable {
    fn default() -> Self {
        Self {
            fdd_bands: Bands {
                band_2g4: true,
                band_433: true,
                band_868: true,
            },
        }
    }
}

// ==== `FDD_ACTIVE` Register ==================================================

/// `FDD_ACTIVE` Register
///
/// Address: 0x2E
///
/// Reset Value: 0x0
///
/// Reads the FDD mode for each band.
#[derive(Debug, PartialEq)]
pub struct FddActive {
    /// Bits: `[0]`
    pub band_2g4: FddMode,
    /// Bits: `[2]`
    pub band_433: FddMode,
    /// Bits: `[1]`
    pub band_868: FddMode,
}

/// Register Properties
impl Register<1, u8> for FddActive {
    const ADDRESS: u8 = 0x2E;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for FddActive {
    fn default() -> Self {
        Self {
            band_2g4: FddMode::Slow,
            band_433: FddMode::Slow,
            band_868: FddMode::Slow,
        }
    }
}

// ==== `FO_QUIT` Register =====================================================

/// `FO_QUIT` Register
///
/// Address: 0x2F
///
/// Reset Value: 0x0
///
/// Forces the specified band to quit fast mode immediately.
#[derive(Debug, PartialEq)]
pub struct FoQuit {
    /// Bits: `[2:0]`
    pub quit_bands: Bands,
}

/// Register Properties
impl Register<1, u8> for FoQuit {
    const ADDRESS: u8 = 0x2F;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for FoQuit {
    fn default() -> Self {
        Self {
            quit_bands: Bands {
                band_2g4: false,
                band_433: false,
                band_868: false,
            },
        }
    }
}

// ==== `FDD_EXIT_COND` Register ===============================================

/// `FDD_EXIT_COND` Register
///
/// Address: 0x30
///
/// Reset Value: 0x0
///
/// Holds the FDD exit condition for all the bands.
#[derive(Debug, PartialEq)]
pub struct FddExitCond {
    /// Bits: `[5:4]`
    pub band_2g4: ExitCond,
    /// Bits: `[1:0]`
    pub band_433: ExitCond,
    /// Bits: `[3:2]`
    pub band_868: ExitCond,
}

/// Register Properties
impl Register<1, u8> for FddExitCond {
    const ADDRESS: u8 = 0x30;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for FddExitCond {
    fn default() -> Self {
        Self {
            band_2g4: ExitCond::NoReason,
            band_433: ExitCond::NoReason,
            band_868: ExitCond::NoReason,
        }
    }
}

// ==== `IRQ_SELECT` Register ==================================================

/// `IRQ_SELECT` Register
///
/// Address: 0x31
///
/// Reset Value: 0x1
///
/// Selects the interrupt sources.
#[derive(Debug, PartialEq)]
pub struct IrqSelect {
    /// Bits: `[7:0]`
    pub irq_select: IrqSource,
}

/// Register Properties
impl Register<1, u8> for IrqSelect {
    const ADDRESS: u8 = 0x31;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x1]));
}

/// Reset Value
impl Default for IrqSelect {
    fn default() -> Self {
        Self {
            irq_select: IrqSource {
                correl_match: false,
                cyclic_timer_alarm: false,
                fifo_full: false,
                fifo_overflow: false,
                id_match: true,
                id_match_and_fifo_full: false,
                id_match_and_ldr: false,
                rtc_timer_alarm: false,
            },
        }
    }
}

// ==== `IRQ_STATUS` Register ==================================================

/// `IRQ_STATUS` Register
///
/// Address: 0x32
///
/// Reset Value: 0x0
///
/// Holds the status of the IRQ events.
#[derive(Debug, PartialEq)]
pub struct IrqStatus {
    /// Bits: `[7:0]`
    pub irq_status: IrqSource,
}

/// Register Properties
impl Register<1, u8> for IrqStatus {
    const ADDRESS: u8 = 0x32;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for IrqStatus {
    fn default() -> Self {
        Self {
            irq_status: IrqSource {
                correl_match: false,
                cyclic_timer_alarm: false,
                fifo_full: false,
                fifo_overflow: false,
                id_match: false,
                id_match_and_fifo_full: false,
                id_match_and_ldr: false,
                rtc_timer_alarm: false,
            },
        }
    }
}

// ==== `IRQ_CLR` Register =====================================================

/// `IRQ_CLR` Register
///
/// Address: 0x33
///
/// Reset Value: 0x0
///
/// Resets the corresponding IRQ event bit.
#[derive(Debug, PartialEq)]
pub struct IrqClr {
    /// Bits: `[7:0]`
    pub irq_clr: IrqSource,
}

/// Register Properties
impl Register<1, u8> for IrqClr {
    const ADDRESS: u8 = 0x33;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for IrqClr {
    fn default() -> Self {
        Self {
            irq_clr: IrqSource {
                correl_match: false,
                cyclic_timer_alarm: false,
                fifo_full: false,
                fifo_overflow: false,
                id_match: false,
                id_match_and_fifo_full: false,
                id_match_and_ldr: false,
                rtc_timer_alarm: false,
            },
        }
    }
}

// ==== `IRQ_SET` Register =====================================================

/// `IRQ_SET` Register
///
/// Address: 0x34
///
/// Reset Value: 0x0
///
/// Sets the corresponding IRQ event bit (triggers IRQ events for debugging).
#[derive(Debug, PartialEq)]
pub struct IrqSet {
    /// Bits: `[7:0]`
    pub irq_set: IrqSource,
}

/// Register Properties
impl Register<1, u8> for IrqSet {
    const ADDRESS: u8 = 0x34;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for IrqSet {
    fn default() -> Self {
        Self {
            irq_set: IrqSource {
                correl_match: false,
                cyclic_timer_alarm: false,
                fifo_full: false,
                fifo_overflow: false,
                id_match: false,
                id_match_and_fifo_full: false,
                id_match_and_ldr: false,
                rtc_timer_alarm: false,
            },
        }
    }
}

// ==== `ID_HI` Register =======================================================

/// `ID_HI` Register
///
/// Address: 0x35
///
/// Reset Value: 0x7D
///
/// Sets the high byte of the match ID. 4-MSB form the group ID.
#[derive(Debug, PartialEq)]
pub struct IdHi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for IdHi {
    const ADDRESS: u8 = 0x35;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x7D]));
}

/// Reset Value
impl Default for IdHi {
    fn default() -> Self {
        Self {
            data: 0x7D,
        }
    }
}

// ==== `ID_LO` Register =======================================================

/// `ID_LO` Register
///
/// Address: 0x36
///
/// Reset Value: 0xA8
///
/// Sets the low byte of the match ID.
#[derive(Debug, PartialEq)]
pub struct IdLo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for IdLo {
    const ADDRESS: u8 = 0x36;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0xA8]));
}

/// Reset Value
impl Default for IdLo {
    fn default() -> Self {
        Self {
            data: 0xA8,
        }
    }
}

// ==== `IDM_ENABLE` Register ==================================================

/// `IDM_ENABLE` Register
///
/// Address: 0x37
///
/// Reset Value: 0x7
///
/// Enables the ID match for a given band.
#[derive(Debug, PartialEq)]
pub struct IdmEnable {
    /// Bits: `[2:0]`
    pub match_bands: Bands,
}

/// Register Properties
impl Register<1, u8> for IdmEnable {
    const ADDRESS: u8 = 0x37;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x7]));
}

/// Reset Value
impl Default for IdmEnable {
    fn default() -> Self {
        Self {
            match_bands: Bands {
                band_2g4: true,
                band_433: true,
                band_868: true,
            },
        }
    }
}

// ==== `IDM_CTRL` Register ====================================================

/// `IDM_CTRL` Register
///
/// Address: 0x38
///
/// Reset Value: 0x0
///
/// Slect the type of ID's accepted by the receiver.
#[derive(Debug, PartialEq)]
pub struct IdmCtrl {
    /// Bits: `[1:0]`
    pub ctrl: Ctrl,
}

// Register-specific sub-layouts:
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Ctrl {
    /// only broadcast ID.
    BroadOnly, // 0x2
    /// individual 16 bit ID or groupwise ID.
    IndGroup, // 0x1
    /// individual 16 bit ID, groupwise ID, or broadcast ID.
    IndGroupBroad, // 0x3
    /// only individual 16 bit ID.
    IndOnly, // 0x0
}

/// Register Properties
impl Register<1, u8> for IdmCtrl {
    const ADDRESS: u8 = 0x38;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for IdmCtrl {
    fn default() -> Self {
        Self {
            ctrl: Ctrl::IndOnly,
        }
    }
}

// ==== `IDM_CLR` Register =====================================================

/// `IDM_CLR` Register
///
/// Address: 0x39
///
/// Reset Value: 0x0
///
/// Clear the FDD_EXIT_COND register.
#[derive(Debug, PartialEq)]
pub struct IdmClr {
    /// Bits: `[0]`
    pub branch: bool,
}

/// Register Properties
impl Register<1, u8> for IdmClr {
    const ADDRESS: u8 = 0x39;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for IdmClr {
    fn default() -> Self {
        Self {
            branch: false,
        }
    }
}

// ==== `IDM_BAND` Register ====================================================

/// `IDM_BAND` Register
///
/// Address: 0x3A
///
/// Reset Value: 0x3
///
/// Indicates the frequency band of the ID match event.
#[derive(Debug, PartialEq)]
pub struct IdmBand {
    /// Bits: `[1:0]`
    pub data: Data,
}

// Register-specific sub-layouts:
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Data {
    Band2g4, // 0x2
    Band433, // 0x0
    Band868, // 0x1
}

/// Register Properties
impl Register<1, u8> for IdmBand {
    const ADDRESS: u8 = 0x3A;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x3]));
}

// ==== `IDM_REASON` Register ==================================================

/// `IDM_REASON` Register
///
/// Address: 0x3B
///
/// Reset Value: 0x0
///
/// Indicates the type of ID match event.
#[derive(Debug, PartialEq)]
pub struct IdmReason {
    /// Bits: `[1:0]`
    pub reason: Reason,
}

// Register-specific sub-layouts:
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Reason {
    /// Broadcast ID
    BroadMatch, // 0x3
    /// Group ID
    GroupMatch, // 0x2
    /// Individual ID
    IndMatch, // 0x1
    /// Unspecified reason
    Unknown, // 0x0
}

/// Register Properties
impl Register<1, u8> for IdmReason {
    const ADDRESS: u8 = 0x3B;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for IdmReason {
    fn default() -> Self {
        Self {
            reason: Reason::Unknown,
        }
    }
}

// ==== `RTC_SELECT` Register ==================================================

/// `RTC_SELECT` Register
///
/// Address: 0x3C
///
/// Reset Value: 0x0
///
/// Allows for selection of the desired timer modes.
#[derive(Debug, PartialEq)]
pub struct RtcSelect {
    /// Selects the cyclic counter (CYCLTOP).
    ///
    /// Bits: `[4]`
    pub cycltop: bool,
    /// Bits: `[3:0]`
    pub rtc_select: Rtc,
}

/// Register Properties
impl Register<1, u8> for RtcSelect {
    const ADDRESS: u8 = 0x3C;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RtcSelect {
    fn default() -> Self {
        Self {
            cycltop: false,
            rtc_select: Rtc {
                rtclg0: false,
                rtclg1: false,
                rtcsh0: false,
                rtcsh1: false,
            },
        }
    }
}

// ==== `RTC_STATUS` Register ==================================================

/// `RTC_STATUS` Register
///
/// Address: 0x3D
///
/// Reset Value: 0x0
///
/// Indicates occurence of RTC events.
#[derive(Debug, PartialEq)]
pub struct RtcStatus {
    /// Bits: `[3:0]`
    pub rtc_select: Rtc,
}

/// Register Properties
impl Register<1, u8> for RtcStatus {
    const ADDRESS: u8 = 0x3D;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RtcStatus {
    fn default() -> Self {
        Self {
            rtc_select: Rtc {
                rtclg0: false,
                rtclg1: false,
                rtcsh0: false,
                rtcsh1: false,
            },
        }
    }
}

// ==== `RTC_CLR` Register =====================================================

/// `RTC_CLR` Register
///
/// Address: 0x3E
///
/// Reset Value: 0x0
///
/// Clears the respective event entries in RTC_STATUS.
#[derive(Debug, PartialEq)]
pub struct RtcClr {
    /// Bits: `[3:0]`
    pub rtc_clr: Rtc,
}

/// Register Properties
impl Register<1, u8> for RtcClr {
    const ADDRESS: u8 = 0x3E;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RtcClr {
    fn default() -> Self {
        Self {
            rtc_clr: Rtc {
                rtclg0: false,
                rtclg1: false,
                rtcsh0: false,
                rtcsh1: false,
            },
        }
    }
}

// ==== `RTCSH0_THRESH_HI` Register ============================================

/// `RTCSH0_THRESH_HI` Register
///
/// Address: 0x3F
///
/// Reset Value: 0x0
///
/// Upper (Bits 15:8) byte of the RTCSH0 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtcsh0ThreshHi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtcsh0ThreshHi {
    const ADDRESS: u8 = 0x3F;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtcsh0ThreshHi {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCSH0_THRESH_LO` Register ============================================

/// `RTCSH0_THRESH_LO` Register
///
/// Address: 0x40
///
/// Reset Value: 0x0
///
/// Lower (Bits 7:0) byte of the RTCSH0 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtcsh0ThreshLo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtcsh0ThreshLo {
    const ADDRESS: u8 = 0x40;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtcsh0ThreshLo {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCSH1_THRESH_HI` Register ============================================

/// `RTCSH1_THRESH_HI` Register
///
/// Address: 0x41
///
/// Reset Value: 0x0
///
/// Upper (Bits 15:8) byte of the RTCSH1 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtcsh1ThreshHi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtcsh1ThreshHi {
    const ADDRESS: u8 = 0x41;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtcsh1ThreshHi {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCSH1_THRESH_LO` Register ============================================

/// `RTCSH1_THRESH_LO` Register
///
/// Address: 0x42
///
/// Reset Value: 0x0
///
/// Lower (Bits 7:0) byte of the RTCSH1 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtcsh1ThreshLo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtcsh1ThreshLo {
    const ADDRESS: u8 = 0x42;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtcsh1ThreshLo {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG0_THRESH_4` Register =============================================

/// `RTCLG0_THRESH_4` Register
///
/// Address: 0x43
///
/// Reset Value: 0x0
///
/// Bits 39:32 of the RTCLG0 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg0Thresh4 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg0Thresh4 {
    const ADDRESS: u8 = 0x43;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg0Thresh4 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG0_THRESH_3` Register =============================================

/// `RTCLG0_THRESH_3` Register
///
/// Address: 0x44
///
/// Reset Value: 0x0
///
/// Bits 31:24 of the RTCLG0 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg0Thresh3 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg0Thresh3 {
    const ADDRESS: u8 = 0x44;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg0Thresh3 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG0_THRESH_2` Register =============================================

/// `RTCLG0_THRESH_2` Register
///
/// Address: 0x45
///
/// Reset Value: 0x0
///
/// Bits 23:16 of the RTCLG0 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg0Thresh2 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg0Thresh2 {
    const ADDRESS: u8 = 0x45;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg0Thresh2 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG0_THRESH_1` Register =============================================

/// `RTCLG0_THRESH_1` Register
///
/// Address: 0x46
///
/// Reset Value: 0x0
///
/// Bits 15:8 of the RTCLG0 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg0Thresh1 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg0Thresh1 {
    const ADDRESS: u8 = 0x46;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg0Thresh1 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG0_THRESH_0` Register =============================================

/// `RTCLG0_THRESH_0` Register
///
/// Address: 0x47
///
/// Reset Value: 0x0
///
/// Bits 7:0 of the RTCLG0 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg0Thresh0 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg0Thresh0 {
    const ADDRESS: u8 = 0x47;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg0Thresh0 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG1_THRESH_4` Register =============================================

/// `RTCLG1_THRESH_4` Register
///
/// Address: 0x48
///
/// Reset Value: 0x0
///
/// Bits 39:32 of the RTCLG1 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg1Thresh4 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg1Thresh4 {
    const ADDRESS: u8 = 0x48;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg1Thresh4 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG1_THRESH_3` Register =============================================

/// `RTCLG1_THRESH_3` Register
///
/// Address: 0x49
///
/// Reset Value: 0x0
///
/// Bits 31:24 of the RTCLG1 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg1Thresh3 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg1Thresh3 {
    const ADDRESS: u8 = 0x49;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg1Thresh3 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG1_THRESH_2` Register =============================================

/// `RTCLG1_THRESH_2` Register
///
/// Address: 0x4A
///
/// Reset Value: 0x0
///
/// Bits 23:16 of the RTCLG1 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg1Thresh2 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg1Thresh2 {
    const ADDRESS: u8 = 0x4A;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg1Thresh2 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG1_THRESH_1` Register =============================================

/// `RTCLG1_THRESH_1` Register
///
/// Address: 0x4B
///
/// Reset Value: 0x0
///
/// Bits 15:8 of the RTCLG1 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg1Thresh1 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg1Thresh1 {
    const ADDRESS: u8 = 0x4B;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg1Thresh1 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RTCLG1_THRESH_0` Register =============================================

/// `RTCLG1_THRESH_0` Register
///
/// Address: 0x4C
///
/// Reset Value: 0x0
///
/// Bits 7:0 of the RTCLG1 threshold.
#[derive(Debug, PartialEq)]
pub struct Rtclg1Thresh0 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Rtclg1Thresh0 {
    const ADDRESS: u8 = 0x4C;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Rtclg1Thresh0 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `CYCLPRESC` Register ===================================================

/// `CYCLPRESC` Register
///
/// Address: 0x4D
///
/// Reset Value: 0x0
///
/// Cycle prescaler for cyclic counter, system clock divided by prescaler (therefore max 8:29.9922 minutes).
#[derive(Debug, PartialEq)]
pub struct Cyclpresc {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Cyclpresc {
    const ADDRESS: u8 = 0x4D;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Cyclpresc {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `CYCLTOP_HI` Register ==================================================

/// `CYCLTOP_HI` Register
///
/// Address: 0x4E
///
/// Reset Value: 0x0
///
/// Bits 15:8 defining the maximal cyclic counter value CYCLTOP before being reset to zero.
#[derive(Debug, PartialEq)]
pub struct CycltopHi {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for CycltopHi {
    const ADDRESS: u8 = 0x4E;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for CycltopHi {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `CYCLTOP_LO` Register ==================================================

/// `CYCLTOP_LO` Register
///
/// Address: 0x4F
///
/// Reset Value: 0x0
///
/// Bits 7:0 defining the maximal cyclic counter value CYCLTOP before being reset to zero.
#[derive(Debug, PartialEq)]
pub struct CycltopLo {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for CycltopLo {
    const ADDRESS: u8 = 0x4F;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for CycltopLo {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `CNTR40_4` Register ====================================================

/// `CNTR40_4` Register
///
/// Address: 0x50
///
/// Reset Value: 0x0
///
/// Bits 39:32 of the system clock counter CNTR40.
#[derive(Debug, PartialEq)]
pub struct Cntr404 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Cntr404 {
    const ADDRESS: u8 = 0x50;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Cntr404 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `CNTR40_3` Register ====================================================

/// `CNTR40_3` Register
///
/// Address: 0x51
///
/// Reset Value: 0x0
///
/// Bits 31:24 of the system clock counter CNTR40.
#[derive(Debug, PartialEq)]
pub struct Cntr403 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Cntr403 {
    const ADDRESS: u8 = 0x51;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Cntr403 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `CNTR40_2` Register ====================================================

/// `CNTR40_2` Register
///
/// Address: 0x52
///
/// Reset Value: 0x0
///
/// Bits 23:16 of the system clock counter CNTR40.
#[derive(Debug, PartialEq)]
pub struct Cntr402 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Cntr402 {
    const ADDRESS: u8 = 0x52;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Cntr402 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `CNTR40_1` Register ====================================================

/// `CNTR40_1` Register
///
/// Address: 0x53
///
/// Reset Value: 0x0
///
/// Bits 15:8 of the system clock counter CNTR40.
#[derive(Debug, PartialEq)]
pub struct Cntr401 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Cntr401 {
    const ADDRESS: u8 = 0x53;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Cntr401 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `CNTR40_0` Register ====================================================

/// `CNTR40_0` Register
///
/// Address: 0x54
///
/// Reset Value: 0x0
///
/// Bits 7:0 of the system clock counter CNTR40.
#[derive(Debug, PartialEq)]
pub struct Cntr400 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Cntr400 {
    const ADDRESS: u8 = 0x54;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Cntr400 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `CNTR40_CLR` Register ==================================================

/// `CNTR40_CLR` Register
///
/// Address: 0x55
///
/// Reset Value: 0x0
///
/// Clear the system clock counter CNTR40 by setting this to true. Manually setting the register to false afterwards is mandatory!
#[derive(Debug, PartialEq)]
pub struct Cntr40Clr {
    /// Bits: `[0]`
    pub clr: bool,
}

/// Register Properties
impl Register<1, u8> for Cntr40Clr {
    const ADDRESS: u8 = 0x55;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Cntr40Clr {
    fn default() -> Self {
        Self {
            clr: false,
        }
    }
}

// ==== `FIFO_LENGTH` Register =================================================

/// `FIFO_LENGTH` Register
///
/// Address: 0x56
///
/// Reset Value: 0x14
///
/// Selects the FIFO length for each band.
#[derive(Debug, PartialEq)]
pub struct FifoLength {
    /// Bits: `[5:4]`
    pub band_2g4: FifoLen,
    /// Bits: `[1:0]`
    pub band_433: FifoLen,
    /// Bits: `[3:2]`
    pub band_868: FifoLen,
}

/// Register Properties
impl Register<1, u8> for FifoLength {
    const ADDRESS: u8 = 0x56;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x14]));
}

/// Reset Value
impl Default for FifoLength {
    fn default() -> Self {
        Self {
            band_2g4: FifoLen::Bit24,
            band_433: FifoLen::Bit16,
            band_868: FifoLen::Bit24,
        }
    }
}

// ==== `FIFO_COUNT_433` Register ==============================================

/// `FIFO_COUNT_433` Register
///
/// Address: 0x57
///
/// Reset Value: 0x0
///
/// Number of bits in the FIFO buffer for the 433MHz band. Can be cleared by writing 0.
#[derive(Debug, PartialEq)]
pub struct FifoCount433 {
    /// Bits: `[5:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for FifoCount433 {
    const ADDRESS: u8 = 0x57;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for FifoCount433 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `FIFO_COUNT_868` Register ==============================================

/// `FIFO_COUNT_868` Register
///
/// Address: 0x58
///
/// Reset Value: 0x0
///
/// Number of bits in the FIFO buffer for the 868/915MHz band. Can be cleared by writing 0.
#[derive(Debug, PartialEq)]
pub struct FifoCount868 {
    /// Bits: `[5:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for FifoCount868 {
    const ADDRESS: u8 = 0x58;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for FifoCount868 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `FIFO_COUNT_2G4` Register ==============================================

/// `FIFO_COUNT_2G4` Register
///
/// Address: 0x59
///
/// Reset Value: 0x0
///
/// Number of bits in the FIFO buffer for the 2.4GHz band. Can be cleared by writing 0.
#[derive(Debug, PartialEq)]
pub struct FifoCount2g4 {
    /// Bits: `[5:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for FifoCount2g4 {
    const ADDRESS: u8 = 0x59;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for FifoCount2g4 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_5_433` Register ===============================================

/// `RX_FIFO_5_433` Register
///
/// Address: 0x5A
///
/// Reset Value: 0x0
///
/// The FIFO byte 5 for the 433MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo5433 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo5433 {
    const ADDRESS: u8 = 0x5A;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo5433 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_4_433` Register ===============================================

/// `RX_FIFO_4_433` Register
///
/// Address: 0x5B
///
/// Reset Value: 0x0
///
/// The FIFO byte 4 for the 433MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo4433 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo4433 {
    const ADDRESS: u8 = 0x5B;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo4433 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_3_433` Register ===============================================

/// `RX_FIFO_3_433` Register
///
/// Address: 0x5C
///
/// Reset Value: 0x0
///
/// The FIFO byte 3 for the 433MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo3433 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo3433 {
    const ADDRESS: u8 = 0x5C;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo3433 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_2_433` Register ===============================================

/// `RX_FIFO_2_433` Register
///
/// Address: 0x5D
///
/// Reset Value: 0x0
///
/// The FIFO byte 2 for the 433MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo2433 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo2433 {
    const ADDRESS: u8 = 0x5D;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo2433 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_1_433` Register ===============================================

/// `RX_FIFO_1_433` Register
///
/// Address: 0x5E
///
/// Reset Value: 0x0
///
/// The FIFO byte 1 for the 433MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo1433 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo1433 {
    const ADDRESS: u8 = 0x5E;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo1433 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_0_433` Register ===============================================

/// `RX_FIFO_0_433` Register
///
/// Address: 0x5F
///
/// Reset Value: 0x0
///
/// The FIFO byte 0 for the 433MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo0433 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo0433 {
    const ADDRESS: u8 = 0x5F;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo0433 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_5_868` Register ===============================================

/// `RX_FIFO_5_868` Register
///
/// Address: 0x60
///
/// Reset Value: 0x0
///
/// The FIFO byte 5 for the 868MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo5868 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo5868 {
    const ADDRESS: u8 = 0x60;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo5868 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_4_868` Register ===============================================

/// `RX_FIFO_4_868` Register
///
/// Address: 0x61
///
/// Reset Value: 0x0
///
/// The FIFO byte 4 for the 868MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo4868 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo4868 {
    const ADDRESS: u8 = 0x61;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo4868 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_3_868` Register ===============================================

/// `RX_FIFO_3_868` Register
///
/// Address: 0x62
///
/// Reset Value: 0x0
///
/// The FIFO byte 3 for the 868MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo3868 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo3868 {
    const ADDRESS: u8 = 0x62;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo3868 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_2_868` Register ===============================================

/// `RX_FIFO_2_868` Register
///
/// Address: 0x63
///
/// Reset Value: 0x0
///
/// The FIFO byte 2 for the 868MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo2868 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo2868 {
    const ADDRESS: u8 = 0x63;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo2868 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_1_868` Register ===============================================

/// `RX_FIFO_1_868` Register
///
/// Address: 0x64
///
/// Reset Value: 0x0
///
/// The FIFO byte 1 for the 868MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo1868 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo1868 {
    const ADDRESS: u8 = 0x64;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo1868 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_0_868` Register ===============================================

/// `RX_FIFO_0_868` Register
///
/// Address: 0x65
///
/// Reset Value: 0x0
///
/// The FIFO byte 0 for the 868MHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo0868 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo0868 {
    const ADDRESS: u8 = 0x65;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo0868 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_5_2G4` Register ===============================================

/// `RX_FIFO_5_2G4` Register
///
/// Address: 0x66
///
/// Reset Value: 0x0
///
/// The FIFO byte 5 for the 2.4GHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo52g4 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo52g4 {
    const ADDRESS: u8 = 0x66;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo52g4 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_4_2G4` Register ===============================================

/// `RX_FIFO_4_2G4` Register
///
/// Address: 0x67
///
/// Reset Value: 0x0
///
/// The FIFO byte 4 for the 2.4GHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo42g4 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo42g4 {
    const ADDRESS: u8 = 0x67;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo42g4 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_3_2G4` Register ===============================================

/// `RX_FIFO_3_2G4` Register
///
/// Address: 0x68
///
/// Reset Value: 0x0
///
/// The FIFO byte 3 for the 2.4GHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo32g4 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo32g4 {
    const ADDRESS: u8 = 0x68;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo32g4 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_2_2G4` Register ===============================================

/// `RX_FIFO_2_2G4` Register
///
/// Address: 0x69
///
/// Reset Value: 0x0
///
/// The FIFO byte 2 for the 2.4GHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo22g4 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo22g4 {
    const ADDRESS: u8 = 0x69;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo22g4 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_1_2G4` Register ===============================================

/// `RX_FIFO_1_2G4` Register
///
/// Address: 0x6A
///
/// Reset Value: 0x0
///
/// The FIFO byte 1 for the 2.4GHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo12g4 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo12g4 {
    const ADDRESS: u8 = 0x6A;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo12g4 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `RX_FIFO_0_2G4` Register ===============================================

/// `RX_FIFO_0_2G4` Register
///
/// Address: 0x6B
///
/// Reset Value: 0x0
///
/// The FIFO byte 0 for the 2.4GHz band, _5 is filled first.
#[derive(Debug, PartialEq)]
pub struct RxFifo02g4 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for RxFifo02g4 {
    const ADDRESS: u8 = 0x6B;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for RxFifo02g4 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `ACTUAL_NFA_433` Register ==============================================

/// `ACTUAL_NFA_433` Register
///
/// Address: 0x6C
///
/// Reset Value: 0x25
///
/// This register contains the actual NFA (sampling rate) value that is currently valid for 433MHz data reception.
#[derive(Debug, PartialEq)]
pub struct ActualNfa433 {
    /// Bits: `[6:4]`
    pub fast: SampleRate,
    /// Bits: `[2:0]`
    pub slow: SampleRate,
}

/// Register Properties
impl Register<1, u8> for ActualNfa433 {
    const ADDRESS: u8 = 0x6C;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x25]));
}

/// Reset Value
impl Default for ActualNfa433 {
    fn default() -> Self {
        Self {
            fast: SampleRate::Sr8192,
            slow: SampleRate::Sr1024,
        }
    }
}

// ==== `ACTUAL_NFA_868` Register ==============================================

/// `ACTUAL_NFA_868` Register
///
/// Address: 0x6D
///
/// Reset Value: 0x15
///
/// This register contains the actual NFA (sampling rate) value that is currently valid for 868MHz data reception.
#[derive(Debug, PartialEq)]
pub struct ActualNfa868 {
    /// Bits: `[6:4]`
    pub fast: SampleRate,
    /// Bits: `[2:0]`
    pub slow: SampleRate,
}

/// Register Properties
impl Register<1, u8> for ActualNfa868 {
    const ADDRESS: u8 = 0x6D;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x15]));
}

/// Reset Value
impl Default for ActualNfa868 {
    fn default() -> Self {
        Self {
            fast: SampleRate::Sr16384,
            slow: SampleRate::Sr1024,
        }
    }
}

// ==== `ACTUAL_NFA_2G4` Register ==============================================

/// `ACTUAL_NFA_2G4` Register
///
/// Address: 0x6E
///
/// Reset Value: 0x25
///
/// This register contains the actual NFA (sampling rate) value that is currently valid for 2.4GHz data reception.
#[derive(Debug, PartialEq)]
pub struct ActualNfa2g4 {
    /// Bits: `[6:4]`
    pub fast: SampleRate,
    /// Bits: `[2:0]`
    pub slow: SampleRate,
}

/// Register Properties
impl Register<1, u8> for ActualNfa2g4 {
    const ADDRESS: u8 = 0x6E;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x25]));
}

/// Reset Value
impl Default for ActualNfa2g4 {
    fn default() -> Self {
        Self {
            fast: SampleRate::Sr8192,
            slow: SampleRate::Sr1024,
        }
    }
}

// ==== `ACTUAL_BANDSELECT` Register ===========================================

/// `ACTUAL_BANDSELECT` Register
///
/// Address: 0x6F
///
/// Reset Value: 0x7
///
/// This 3 bit register contains the actual selected frequency bands that are currently used.
#[derive(Debug, PartialEq)]
pub struct ActualBandselect {
    /// Bits: `[2:0]`
    pub selected_bands: Bands,
}

/// Register Properties
impl Register<1, u8> for ActualBandselect {
    const ADDRESS: u8 = 0x6F;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x7]));
}

/// Reset Value
impl Default for ActualBandselect {
    fn default() -> Self {
        Self {
            selected_bands: Bands {
                band_2g4: true,
                band_433: true,
                band_868: true,
            },
        }
    }
}

// ==== `GENPURP_1` Register ===================================================

/// `GENPURP_1` Register
///
/// Address: 0x71
///
/// Reset Value: 0x0
///
/// 8 bits free to use for read/write. (Register table says only write).
#[derive(Debug, PartialEq)]
pub struct Genpurp1 {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for Genpurp1 {
    const ADDRESS: u8 = 0x71;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for Genpurp1 {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `XTAL_OSC_CTRL` Register ===============================================

/// `XTAL_OSC_CTRL` Register
///
/// Address: 0x73
///
/// Reset Value: 0x1
///
/// Enables the built-in crystal oscillator driving a 2-pin crystal device.
#[derive(Debug, PartialEq)]
pub struct XtalOscCtrl {
    /// Bits: `[0]`
    pub data: bool,
}

/// Register Properties
impl Register<1, u8> for XtalOscCtrl {
    const ADDRESS: u8 = 0x73;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x1]));
}

/// Reset Value
impl Default for XtalOscCtrl {
    fn default() -> Self {
        Self {
            data: true,
        }
    }
}

// ==== `LDO_XTAL_CTRL` Register ===============================================

/// `LDO_XTAL_CTRL` Register
///
/// Address: 0x74
///
/// Reset Value: 0x3
///
/// Controls the LDO and the crystal oscillator.
///
/// Fixed bits:
/// - `[1:0]` = 0b11
#[derive(Debug, PartialEq)]
pub struct LdoXtalCtrl {
    /// sed to deactivate the internal LDO for VDDC voltage generation. If set to true, an external VDDC source must be supplied.
    ///
    /// Bits: `[5]`
    pub ldo_ena_nfa: bool,
    /// Used for selecting an external system clock source that is applied to pin CLK32_XI. In this case, XTAL_OSC_BYP should be true. Set this, if a 2-pin crystal will not be used.
    ///
    /// Bits: `[3]`
    pub xtal_osc_byp: bool,
}

/// Register Properties
impl Register<1, u8> for LdoXtalCtrl {
    const ADDRESS: u8 = 0x74;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x3]));
}

/// Reset Value
impl Default for LdoXtalCtrl {
    fn default() -> Self {
        Self {
            ldo_ena_nfa: false,
            xtal_osc_byp: false,
        }
    }
}

// ==== `MUX_D_OUT_SEL` Register ===============================================

/// `MUX_D_OUT_SEL` Register
///
/// Address: 0x75
///
/// Reset Value: 0xF
///
/// Selects the signal routed to the GPO1 and GPO2 pins.
#[derive(Debug, PartialEq)]
pub struct MuxDOutSel {
    /// Bits: `[3:0]`
    pub out: Out,
}

// Register-specific sub-layouts:
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Out {
    /// System Clock CLK32 on GPO1 and interrupt signal IRQ_EVENT on GPO2.
    Clk32IrqEvent, // 0xE
    /// General ID match on GPO1 and 433MHz Wake-up A signal WUP_A on GPO2.
    IdmWupA433, // 0x6
    /// Interrupt signal IRQ_EVENT on GPO1 and static high on GPO2.
    IrqEvent1, // 0xF
    /// RX data stream at 2.4GHz. CLK on GPO1 and DATA on GPO2.
    Rx2g4, // 0x0
    /// RX data stream at 433MHz. CLK on GPO1 and DATA on GPO2.
    Rx433, // 0x2
    /// RX data stream at 868MHz. CLK on GPO1 and DATA on GPO2.
    Rx868, // 0x1
    /// 2.4GHz Wake-up A signal WUP_A on GPO1 and RX_ACTIVE trigger signal on GPO2.
    WupA2g4RxActive, // 0xA
    /// 433MHz Wake-up A signal WUP_A on GPO1 and RX_ACTIVE trigger signal on GPO2.
    WupA433RxActive, // 0x8
    /// 868MHz Wake-up A signal WUP_A on GPO1 and RX_ACTIVE trigger signal on GPO2.
    WupA868RxActive, // 0x9
    /// Wake-up A/B signals at 2.4GHz. WUP_A on GPO1 and WUP_B on GPO2.
    WupAB2g4, // 0x3
    /// Wake-up A/B signals at 868MHz. WUP_A on GPO1 and WUP_B on GPO2.
    WupAB868, // 0x7
}

/// Register Properties
impl Register<1, u8> for MuxDOutSel {
    const ADDRESS: u8 = 0x75;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0xF]));
}

/// Reset Value
impl Default for MuxDOutSel {
    fn default() -> Self {
        Self {
            out: Out::IrqEvent1,
        }
    }
}

// ==== `LC_TG_ENA` Register ===================================================

/// `LC_TG_ENA` Register
///
/// Address: 0x76
///
/// Reset Value: 0x1
///
/// Set to 0x00 during power-up.
#[derive(Debug, PartialEq)]
pub struct LcTgEna {
    /// Bits: `[0]`
    pub data: bool,
}

/// Register Properties
impl Register<1, u8> for LcTgEna {
    const ADDRESS: u8 = 0x76;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x1]));
}

/// Reset Value
impl Default for LcTgEna {
    fn default() -> Self {
        Self {
            data: true,
        }
    }
}

// ==== `XTAL_GOOD` Register ===================================================

/// `XTAL_GOOD` Register
///
/// Address: 0x77
///
/// Reset Value: 0x0
///
/// Reads as true if the clock source is stable.
#[derive(Debug, PartialEq)]
pub struct XtalGood {
    /// Bits: `[0]`
    pub data: bool,
}

/// Register Properties
impl Register<1, u8> for XtalGood {
    const ADDRESS: u8 = 0x77;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for XtalGood {
    fn default() -> Self {
        Self {
            data: false,
        }
    }
}

// ==== `COMP_THRESH_W` Register ===============================================

/// `COMP_THRESH_W` Register
///
/// Address: 0x78
///
/// Reset Value: 0x0
///
/// Set this register to 0xA before executing the comparator calibration.
#[derive(Debug, PartialEq)]
pub struct CompThreshW {
    /// Bits: `[7:0]`
    pub data: u8,
}

/// Register Properties
impl Register<1, u8> for CompThreshW {
    const ADDRESS: u8 = 0x78;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for CompThreshW {
    fn default() -> Self {
        Self {
            data: 0x0,
        }
    }
}

// ==== `KORREL_SV_CLEAR` Register =============================================

/// `KORREL_SV_CLEAR` Register
///
/// Address: 0x7C
///
/// Reset Value: 0x0
///
/// Set true to clear the KORREL_STATE and KORREL_VAL registers.
#[derive(Debug, PartialEq)]
pub struct KorrelSvClear {
    /// Bits: `[0]`
    pub data: bool,
}

/// Register Properties
impl Register<1, u8> for KorrelSvClear {
    const ADDRESS: u8 = 0x7C;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x0]));
}

/// Reset Value
impl Default for KorrelSvClear {
    fn default() -> Self {
        Self {
            data: false,
        }
    }
}

// ==== `VERSION` Register =====================================================

/// `VERSION` Register
///
/// Address: 0x7F
///
/// Reset Value: 0x41
///
/// Holds the version number of the IC, currently 0x41.
///
/// Fixed bits:
/// - `[7:0]` = 0b1000001
#[derive(Debug, PartialEq)]
pub struct Version {
}

/// Register Properties
impl Register<1, u8> for Version {
    const ADDRESS: u8 = 0x7F;
    const RESET_VAL: Option<ResetVal<1>> = Some(ResetVal::LittleEndian([0x41]));
}

/// Reset Value
impl Default for Version {
    fn default() -> Self {
        Self {
        }
    }
}

// ==== Shared Enums ===========================================================

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum BinCode {
    /// mls A
    A, // 0x0
    /// mls A inv
    AInv, // 0x4
    /// m-sequence A
    ASeq, // 0x6
    /// mls B
    B, // 0x1
    /// mls B inv
    BInv, // 0x5
    /// m-sequence B
    BSeq, // 0x7
    /// mls C
    C, // 0x2
    /// mls D
    D, // 0x3
    /// 16 ones
    One16, // 0xA
    /// 24 ones
    One24, // 0xB
    /// 31 ones
    One31, // 0xC
    /// 8 ones
    One8, // 0x9
    /// 111000 pattern
    Ooozzz, // 0xF
    /// 1100 pattern
    Oozz, // 0xE
    /// 31 zeros
    Zero31, // 0x8
    /// 0101 pattern
    Zozo, // 0xD
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum ExitCond {
    /// FO_QUIT was set - user forced slow mode.
    ForceQuit, // 0x3
    /// ID match failed - 16-bit ID did not match.
    IdFail, // 0x2
    /// RX resetted or FDD is disabled - Initial state.
    NoReason, // 0x0
    /// Timeout - No fast code A or B received.
    Timeout, // 0x1
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum FddMode {
    /// Fast mode.
    Fast, // 0x1
    /// Slow mode.
    Slow, // 0x0
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum FifoLen {
    /// 16-bit FIFO.
    Bit16, // 0x0
    /// 24-bit FIFO.
    Bit24, // 0x1
    /// 32-bit FIFO.
    Bit32, // 0x2
    /// 40-bit FIFO.
    Bit40, // 0x3
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum SampleRate {
    /// 256 Hz. 125ms code-sequence-duration.
    Sr0256, // 0x7
    /// 512 Hz. 62.5ms code-sequence-duration.
    Sr0512, // 0x6
    /// 16384 Hz. 1.957ms code-sequence-duration.
    Sr16384, // 0x1
    /// 1024 Hz. 31.25ms code-sequence-duration.
    Sr1024, // 0x5
    /// 2048 Hz. 15.625ms code-sequence-duration.
    Sr2048, // 0x4
    /// 32768 Hz. 0.977ms code-sequence-duration.
    Sr32768, // 0x0
    /// 4096 Hz. 7.813ms code-sequence-duration.
    Sr4096, // 0x3
    /// 32768 Hz. 0.977ms code-sequence-duration.
    Sr8192, // 0x2
}

// ==== `BANDS` Shared Layout ==================================================

/// `BANDS`
#[derive(Debug, PartialEq)]
pub struct Bands {
    /// True means on for 2.4GHz band.
    ///
    /// Bits: `[2]`
    pub band_2g4: bool,
    /// True means on for 433MHz band.
    ///
    /// Bits: `[0]`
    pub band_433: bool,
    /// True means on for 868/915MHz band.
    ///
    /// Bits: `[1]`
    pub band_868: bool,
}

// ==== `BRANCHES` Shared Layout ===============================================

/// `BRANCHES`
#[derive(Debug, PartialEq)]
pub struct Branches {
    /// True means medium branch on (+8dB of weak).
    ///
    /// Bits: `[1]`
    pub medium: bool,
    /// True means strong branch on (+16dB of weak).
    ///
    /// Bits: `[2]`
    pub strong: bool,
    /// True means weak branch on.
    ///
    /// Bits: `[0]`
    pub weak: bool,
}

// ==== `IRQ_SOURCE` Shared Layout =============================================

/// `IRQ_SOURCE`
#[derive(Debug, PartialEq)]
pub struct IrqSource {
    /// OOK data matches the correlation sequence.
    ///
    /// Bits: `[3]`
    pub correl_match: bool,
    /// Cyclic timer alarm.
    ///
    /// Bits: `[7]`
    pub cyclic_timer_alarm: bool,
    /// FIFO buffer full.
    ///
    /// Bits: `[2]`
    pub fifo_full: bool,
    /// FIFO overflow.
    ///
    /// Bits: `[1]`
    pub fifo_overflow: bool,
    /// The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
    ///
    /// Bits: `[0]`
    pub id_match: bool,
    /// 16-bit ID in FDD mode matches and FIFO buffer full.
    ///
    /// Bits: `[4]`
    pub id_match_and_fifo_full: bool,
    /// 16-bit ID in FDD mode matches and LDR was entered.
    ///
    /// Bits: `[5]`
    pub id_match_and_ldr: bool,
    /// RTC timer alarm.
    ///
    /// Bits: `[6]`
    pub rtc_timer_alarm: bool,
}

// ==== `RTC` Shared Layout ====================================================

/// `RTC`
#[derive(Debug, PartialEq)]
pub struct Rtc {
    /// Selects the long RTC counter
    ///
    /// Bits: `[2]`
    pub rtclg0: bool,
    /// Selects the long RTC counter
    ///
    /// Bits: `[3]`
    pub rtclg1: bool,
    /// Selects the short RTC counter
    ///
    /// Bits: `[0]`
    pub rtcsh0: bool,
    /// Selects the short RTC counter
    ///
    /// Bits: `[1]`
    pub rtcsh1: bool,
}

// ==== `BIN_CODE` Enum Conversion Functions ===================================

impl FromMaskedBytes<1> for BinCode {
    fn from_masked_le_bytes(val: &[u8; 1]) -> Self {
        match [val[0] & 0xF] {
            [0x0] => Self::A,
            [0x4] => Self::AInv,
            [0x6] => Self::ASeq,
            [0x1] => Self::B,
            [0x5] => Self::BInv,
            [0x7] => Self::BSeq,
            [0x2] => Self::C,
            [0x3] => Self::D,
            [0xA] => Self::One16,
            [0xB] => Self::One24,
            [0xC] => Self::One31,
            [0x9] => Self::One8,
            [0xF] => Self::Ooozzz,
            [0xE] => Self::Oozz,
            [0x8] => Self::Zero31,
            [0xD] => Self::Zozo,
            _ => unreachable!(),
        }
    }
}

impl TryFromBytes<1> for BinCode {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        let bytes_outside = [val[0] & 0xF0];
        if bytes_outside == [0; 1] {
            Ok(Self::from_masked_le_bytes(val))
        } else {
            Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for BinCode {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::A => [0x0],
            Self::AInv => [0x4],
            Self::ASeq => [0x6],
            Self::B => [0x1],
            Self::BInv => [0x5],
            Self::BSeq => [0x7],
            Self::C => [0x2],
            Self::D => [0x3],
            Self::One16 => [0xA],
            Self::One24 => [0xB],
            Self::One31 => [0xC],
            Self::One8 => [0x9],
            Self::Ooozzz => [0xF],
            Self::Oozz => [0xE],
            Self::Zero31 => [0x8],
            Self::Zozo => [0xD],
        }
    }
}

// ==== `CTRL` Enum Conversion Functions =======================================

impl FromMaskedBytes<1> for Ctrl {
    fn from_masked_le_bytes(val: &[u8; 1]) -> Self {
        match [val[0] & 0x3] {
            [0x2] => Self::BroadOnly,
            [0x1] => Self::IndGroup,
            [0x3] => Self::IndGroupBroad,
            [0x0] => Self::IndOnly,
            _ => unreachable!(),
        }
    }
}

impl TryFromBytes<1> for Ctrl {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        let bytes_outside = [val[0] & 0xFC];
        if bytes_outside == [0; 1] {
            Ok(Self::from_masked_le_bytes(val))
        } else {
            Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for Ctrl {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::BroadOnly => [0x2],
            Self::IndGroup => [0x1],
            Self::IndGroupBroad => [0x3],
            Self::IndOnly => [0x0],
        }
    }
}

// ==== `DATA` Enum Conversion Functions =======================================

impl TryFromBytes<1> for Data {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        match val {
           [0x2] => Ok(Self::Band2g4),
           [0x0] => Ok(Self::Band433),
           [0x1] => Ok(Self::Band868),
            _ => Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for Data {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::Band2g4 => [0x2],
            Self::Band433 => [0x0],
            Self::Band868 => [0x1],
        }
    }
}

// ==== `EXIT_COND` Enum Conversion Functions ==================================

impl FromMaskedBytes<1> for ExitCond {
    fn from_masked_le_bytes(val: &[u8; 1]) -> Self {
        match [val[0] & 0x3] {
            [0x3] => Self::ForceQuit,
            [0x2] => Self::IdFail,
            [0x0] => Self::NoReason,
            [0x1] => Self::Timeout,
            _ => unreachable!(),
        }
    }
}

impl TryFromBytes<1> for ExitCond {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        let bytes_outside = [val[0] & 0xFC];
        if bytes_outside == [0; 1] {
            Ok(Self::from_masked_le_bytes(val))
        } else {
            Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for ExitCond {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::ForceQuit => [0x3],
            Self::IdFail => [0x2],
            Self::NoReason => [0x0],
            Self::Timeout => [0x1],
        }
    }
}

// ==== `FDD_MODE` Enum Conversion Functions ===================================

impl FromMaskedBytes<1> for FddMode {
    fn from_masked_le_bytes(val: &[u8; 1]) -> Self {
        match [val[0] & 0x1] {
            [0x1] => Self::Fast,
            [0x0] => Self::Slow,
            _ => unreachable!(),
        }
    }
}

impl TryFromBytes<1> for FddMode {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        let bytes_outside = [val[0] & 0xFE];
        if bytes_outside == [0; 1] {
            Ok(Self::from_masked_le_bytes(val))
        } else {
            Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for FddMode {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::Fast => [0x1],
            Self::Slow => [0x0],
        }
    }
}

// ==== `FIFO_LEN` Enum Conversion Functions ===================================

impl FromMaskedBytes<1> for FifoLen {
    fn from_masked_le_bytes(val: &[u8; 1]) -> Self {
        match [val[0] & 0x3] {
            [0x0] => Self::Bit16,
            [0x1] => Self::Bit24,
            [0x2] => Self::Bit32,
            [0x3] => Self::Bit40,
            _ => unreachable!(),
        }
    }
}

impl TryFromBytes<1> for FifoLen {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        let bytes_outside = [val[0] & 0xFC];
        if bytes_outside == [0; 1] {
            Ok(Self::from_masked_le_bytes(val))
        } else {
            Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for FifoLen {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::Bit16 => [0x0],
            Self::Bit24 => [0x1],
            Self::Bit32 => [0x2],
            Self::Bit40 => [0x3],
        }
    }
}

// ==== `KORREL_BRANCHES_LATEST` Enum Conversion Functions =====================

impl TryFromBytes<1> for KorrelBranchesLatest {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        match val {
           [0x2] => Ok(Self::Band2g4),
           [0x0] => Ok(Self::Band433),
           [0x1] => Ok(Self::Band868),
            _ => Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for KorrelBranchesLatest {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::Band2g4 => [0x2],
            Self::Band433 => [0x0],
            Self::Band868 => [0x1],
        }
    }
}

// ==== `OUT` Enum Conversion Functions ========================================

impl TryFromBytes<1> for Out {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        match val {
           [0xE] => Ok(Self::Clk32IrqEvent),
           [0x6] => Ok(Self::IdmWupA433),
           [0xF] => Ok(Self::IrqEvent1),
           [0x0] => Ok(Self::Rx2g4),
           [0x2] => Ok(Self::Rx433),
           [0x1] => Ok(Self::Rx868),
           [0xA] => Ok(Self::WupA2g4RxActive),
           [0x8] => Ok(Self::WupA433RxActive),
           [0x9] => Ok(Self::WupA868RxActive),
           [0x3] => Ok(Self::WupAB2g4),
           [0x7] => Ok(Self::WupAB868),
            _ => Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for Out {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::Clk32IrqEvent => [0xE],
            Self::IdmWupA433 => [0x6],
            Self::IrqEvent1 => [0xF],
            Self::Rx2g4 => [0x0],
            Self::Rx433 => [0x2],
            Self::Rx868 => [0x1],
            Self::WupA2g4RxActive => [0xA],
            Self::WupA433RxActive => [0x8],
            Self::WupA868RxActive => [0x9],
            Self::WupAB2g4 => [0x3],
            Self::WupAB868 => [0x7],
        }
    }
}

// ==== `REASON` Enum Conversion Functions =====================================

impl FromMaskedBytes<1> for Reason {
    fn from_masked_le_bytes(val: &[u8; 1]) -> Self {
        match [val[0] & 0x3] {
            [0x3] => Self::BroadMatch,
            [0x2] => Self::GroupMatch,
            [0x1] => Self::IndMatch,
            [0x0] => Self::Unknown,
            _ => unreachable!(),
        }
    }
}

impl TryFromBytes<1> for Reason {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        let bytes_outside = [val[0] & 0xFC];
        if bytes_outside == [0; 1] {
            Ok(Self::from_masked_le_bytes(val))
        } else {
            Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for Reason {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::BroadMatch => [0x3],
            Self::GroupMatch => [0x2],
            Self::IndMatch => [0x1],
            Self::Unknown => [0x0],
        }
    }
}

// ==== `SAMPLE_RATE` Enum Conversion Functions ================================

impl FromMaskedBytes<1> for SampleRate {
    fn from_masked_le_bytes(val: &[u8; 1]) -> Self {
        match [val[0] & 0x7] {
            [0x7] => Self::Sr0256,
            [0x6] => Self::Sr0512,
            [0x1] => Self::Sr16384,
            [0x5] => Self::Sr1024,
            [0x4] => Self::Sr2048,
            [0x0] => Self::Sr32768,
            [0x3] => Self::Sr4096,
            [0x2] => Self::Sr8192,
            _ => unreachable!(),
        }
    }
}

impl TryFromBytes<1> for SampleRate {
    type Error = FromBytesError;

    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        let bytes_outside = [val[0] & 0xF8];
        if bytes_outside == [0; 1] {
            Ok(Self::from_masked_le_bytes(val))
        } else {
            Err(Self::Error {pos: 0})
        }
    }
}

impl ToBytes<1> for SampleRate {
    fn to_le_bytes(&self) -> [u8; 1] {
        match self {
            Self::Sr0256 => [0x7],
            Self::Sr0512 => [0x6],
            Self::Sr16384 => [0x1],
            Self::Sr1024 => [0x5],
            Self::Sr2048 => [0x4],
            Self::Sr32768 => [0x0],
            Self::Sr4096 => [0x3],
            Self::Sr8192 => [0x2],
        }
    }
}

// ==== `ACTUAL_BANDSELECT` Layout Conversion Functions ========================

impl ToBytes<1> for ActualBandselect {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // SELECTED_BANDS @ ActualBandselect[2:0]:
        let selected_bands: [u8; 1] = self.selected_bands.to_le_bytes();
        val[0] |= selected_bands[0] & 0x7;
        val
    }
}

impl FromBytes<1> for ActualBandselect {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // SELECTED_BANDS @ ActualBandselect[2:0]:
        let mut selected_bands: [u8; 1] = [0; 1];
        selected_bands[0] |= val[0] & 0x7;
        Self {
          // SELECTED_BANDS @ ActualBandselect[2:0]:
          selected_bands: Bands::from_le_bytes(&selected_bands),
        }
    }
}

impl From<ActualBandselect> for u8 {
    fn from(value: ActualBandselect) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for ActualBandselect {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `ACTUAL_NFA_2G4` Layout Conversion Functions ===========================

impl ToBytes<1> for ActualNfa2g4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // FAST @ ActualNfa2g4[6:4]:
        let fast: [u8; 1] = self.fast.to_le_bytes();
        val[0] |= (fast[0] << 4) & 0x70;
        // SLOW @ ActualNfa2g4[2:0]:
        let slow: [u8; 1] = self.slow.to_le_bytes();
        val[0] |= slow[0] & 0x7;
        val
    }
}

impl FromBytes<1> for ActualNfa2g4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // FAST @ ActualNfa2g4[6:4]:
        let mut fast: [u8; 1] = [0; 1];
        fast[0] |= (val[0] & 0x70) >> 4;
        // SLOW @ ActualNfa2g4[2:0]:
        let mut slow: [u8; 1] = [0; 1];
        slow[0] |= val[0] & 0x7;
        Self {
          // FAST @ ActualNfa2g4[6:4]:
          fast: SampleRate::from_masked_le_bytes(&fast),
          // SLOW @ ActualNfa2g4[2:0]:
          slow: SampleRate::from_masked_le_bytes(&slow),
        }
    }
}

impl From<ActualNfa2g4> for u8 {
    fn from(value: ActualNfa2g4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for ActualNfa2g4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `ACTUAL_NFA_433` Layout Conversion Functions ===========================

impl ToBytes<1> for ActualNfa433 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // FAST @ ActualNfa433[6:4]:
        let fast: [u8; 1] = self.fast.to_le_bytes();
        val[0] |= (fast[0] << 4) & 0x70;
        // SLOW @ ActualNfa433[2:0]:
        let slow: [u8; 1] = self.slow.to_le_bytes();
        val[0] |= slow[0] & 0x7;
        val
    }
}

impl FromBytes<1> for ActualNfa433 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // FAST @ ActualNfa433[6:4]:
        let mut fast: [u8; 1] = [0; 1];
        fast[0] |= (val[0] & 0x70) >> 4;
        // SLOW @ ActualNfa433[2:0]:
        let mut slow: [u8; 1] = [0; 1];
        slow[0] |= val[0] & 0x7;
        Self {
          // FAST @ ActualNfa433[6:4]:
          fast: SampleRate::from_masked_le_bytes(&fast),
          // SLOW @ ActualNfa433[2:0]:
          slow: SampleRate::from_masked_le_bytes(&slow),
        }
    }
}

impl From<ActualNfa433> for u8 {
    fn from(value: ActualNfa433) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for ActualNfa433 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `ACTUAL_NFA_868` Layout Conversion Functions ===========================

impl ToBytes<1> for ActualNfa868 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // FAST @ ActualNfa868[6:4]:
        let fast: [u8; 1] = self.fast.to_le_bytes();
        val[0] |= (fast[0] << 4) & 0x70;
        // SLOW @ ActualNfa868[2:0]:
        let slow: [u8; 1] = self.slow.to_le_bytes();
        val[0] |= slow[0] & 0x7;
        val
    }
}

impl FromBytes<1> for ActualNfa868 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // FAST @ ActualNfa868[6:4]:
        let mut fast: [u8; 1] = [0; 1];
        fast[0] |= (val[0] & 0x70) >> 4;
        // SLOW @ ActualNfa868[2:0]:
        let mut slow: [u8; 1] = [0; 1];
        slow[0] |= val[0] & 0x7;
        Self {
          // FAST @ ActualNfa868[6:4]:
          fast: SampleRate::from_masked_le_bytes(&fast),
          // SLOW @ ActualNfa868[2:0]:
          slow: SampleRate::from_masked_le_bytes(&slow),
        }
    }
}

impl From<ActualNfa868> for u8 {
    fn from(value: ActualNfa868) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for ActualNfa868 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `BANDS` Layout Conversion Functions ====================================

impl ToBytes<1> for Bands {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // BAND_2G4 @ Bands[2]:
        val[0] |= ((u8::from(self.band_2g4) << 2) & 0x4) as u8;
        // BAND_433 @ Bands[0]:
        val[0] |= (u8::from(self.band_433) & 0x1) as u8;
        // BAND_868 @ Bands[1]:
        val[0] |= ((u8::from(self.band_868) << 1) & 0x2) as u8;
        val
    }
}

impl FromBytes<1> for Bands {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // BAND_2G4 @ Bands[2]:
          band_2g4: (val[0] & 0x4) >> 2 != 0,
          // BAND_433 @ Bands[0]:
          band_433: val[0] & 0x1 != 0,
          // BAND_868 @ Bands[1]:
          band_868: (val[0] & 0x2) >> 1 != 0,
        }
    }
}

impl From<Bands> for u8 {
    fn from(value: Bands) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Bands {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `BAND_BRANCH_CTRL` Layout Conversion Functions =========================

impl ToBytes<1> for BandBranchCtrl {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // ACTIVE_BANDS @ BandBranchCtrl[6:4]:
        let active_bands: [u8; 1] = self.active_bands.to_le_bytes();
        val[0] |= (active_bands[0] << 4) & 0x70;
        // ACTIVE_BRANCHES @ BandBranchCtrl[2:0]:
        let active_branches: [u8; 1] = self.active_branches.to_le_bytes();
        val[0] |= active_branches[0] & 0x7;
        val
    }
}

impl FromBytes<1> for BandBranchCtrl {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // ACTIVE_BANDS @ BandBranchCtrl[6:4]:
        let mut active_bands: [u8; 1] = [0; 1];
        active_bands[0] |= (val[0] & 0x70) >> 4;
        // ACTIVE_BRANCHES @ BandBranchCtrl[2:0]:
        let mut active_branches: [u8; 1] = [0; 1];
        active_branches[0] |= val[0] & 0x7;
        Self {
          // ACTIVE_BANDS @ BandBranchCtrl[6:4]:
          active_bands: Bands::from_le_bytes(&active_bands),
          // ACTIVE_BRANCHES @ BandBranchCtrl[2:0]:
          active_branches: Branches::from_le_bytes(&active_branches),
        }
    }
}

impl From<BandBranchCtrl> for u8 {
    fn from(value: BandBranchCtrl) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for BandBranchCtrl {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `BRANCHES` Layout Conversion Functions =================================

impl ToBytes<1> for Branches {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // MEDIUM @ Branches[1]:
        val[0] |= ((u8::from(self.medium) << 1) & 0x2) as u8;
        // STRONG @ Branches[2]:
        val[0] |= ((u8::from(self.strong) << 2) & 0x4) as u8;
        // WEAK @ Branches[0]:
        val[0] |= (u8::from(self.weak) & 0x1) as u8;
        val
    }
}

impl FromBytes<1> for Branches {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // MEDIUM @ Branches[1]:
          medium: (val[0] & 0x2) >> 1 != 0,
          // STRONG @ Branches[2]:
          strong: (val[0] & 0x4) >> 2 != 0,
          // WEAK @ Branches[0]:
          weak: val[0] & 0x1 != 0,
        }
    }
}

impl From<Branches> for u8 {
    fn from(value: Branches) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Branches {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CALIB_CTRL` Layout Conversion Functions ===============================

impl ToBytes<1> for CalibCtrl {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // CAL_START @ CalibCtrl[0]:
        val[0] |= (u8::from(self.cal_start) & 0x1) as u8;
        // LCO_CAL @ CalibCtrl[1]:
        val[0] |= ((u8::from(self.lco_cal) << 1) & 0x2) as u8;
        // OFFSET_CAL @ CalibCtrl[3]:
        val[0] |= ((u8::from(self.offset_cal) << 3) & 0x8) as u8;
        // SPG_CAL @ CalibCtrl[2]:
        val[0] |= ((u8::from(self.spg_cal) << 2) & 0x4) as u8;
        val
    }
}

impl FromBytes<1> for CalibCtrl {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // CAL_START @ CalibCtrl[0]:
          cal_start: val[0] & 0x1 != 0,
          // LCO_CAL @ CalibCtrl[1]:
          lco_cal: (val[0] & 0x2) >> 1 != 0,
          // OFFSET_CAL @ CalibCtrl[3]:
          offset_cal: (val[0] & 0x8) >> 3 != 0,
          // SPG_CAL @ CalibCtrl[2]:
          spg_cal: (val[0] & 0x4) >> 2 != 0,
        }
    }
}

impl From<CalibCtrl> for u8 {
    fn from(value: CalibCtrl) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for CalibCtrl {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CALIB_STATUS` Layout Conversion Functions =============================

impl ToBytes<1> for CalibStatus {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // CAL_IN_PROG @ CalibStatus[0]:
        val[0] |= (u8::from(self.cal_in_prog) & 0x1) as u8;
        // LCO_CAL_IN_PROG @ CalibStatus[1]:
        val[0] |= ((u8::from(self.lco_cal_in_prog) << 1) & 0x2) as u8;
        // OFFSET_CAL_IN_PROG @ CalibStatus[3]:
        val[0] |= ((u8::from(self.offset_cal_in_prog) << 3) & 0x8) as u8;
        // SPG_CAL_IN_PROG @ CalibStatus[2]:
        val[0] |= ((u8::from(self.spg_cal_in_prog) << 2) & 0x4) as u8;
        val
    }
}

impl FromBytes<1> for CalibStatus {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // CAL_IN_PROG @ CalibStatus[0]:
          cal_in_prog: val[0] & 0x1 != 0,
          // LCO_CAL_IN_PROG @ CalibStatus[1]:
          lco_cal_in_prog: (val[0] & 0x2) >> 1 != 0,
          // OFFSET_CAL_IN_PROG @ CalibStatus[3]:
          offset_cal_in_prog: (val[0] & 0x8) >> 3 != 0,
          // SPG_CAL_IN_PROG @ CalibStatus[2]:
          spg_cal_in_prog: (val[0] & 0x4) >> 2 != 0,
        }
    }
}

impl From<CalibStatus> for u8 {
    fn from(value: CalibStatus) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for CalibStatus {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CNTR40_0` Layout Conversion Functions =================================

impl ToBytes<1> for Cntr400 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Cntr400[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Cntr400 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Cntr400[7:0]:
          data: val[0],
        }
    }
}

impl From<Cntr400> for u8 {
    fn from(value: Cntr400) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Cntr400 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CNTR40_1` Layout Conversion Functions =================================

impl ToBytes<1> for Cntr401 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Cntr401[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Cntr401 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Cntr401[7:0]:
          data: val[0],
        }
    }
}

impl From<Cntr401> for u8 {
    fn from(value: Cntr401) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Cntr401 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CNTR40_2` Layout Conversion Functions =================================

impl ToBytes<1> for Cntr402 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Cntr402[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Cntr402 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Cntr402[7:0]:
          data: val[0],
        }
    }
}

impl From<Cntr402> for u8 {
    fn from(value: Cntr402) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Cntr402 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CNTR40_3` Layout Conversion Functions =================================

impl ToBytes<1> for Cntr403 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Cntr403[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Cntr403 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Cntr403[7:0]:
          data: val[0],
        }
    }
}

impl From<Cntr403> for u8 {
    fn from(value: Cntr403) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Cntr403 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CNTR40_4` Layout Conversion Functions =================================

impl ToBytes<1> for Cntr404 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Cntr404[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Cntr404 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Cntr404[7:0]:
          data: val[0],
        }
    }
}

impl From<Cntr404> for u8 {
    fn from(value: Cntr404) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Cntr404 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CNTR40_CLR` Layout Conversion Functions ===============================

impl ToBytes<1> for Cntr40Clr {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // CLR @ Cntr40Clr[0]:
        val[0] |= (u8::from(self.clr) & 0x1) as u8;
        val
    }
}

impl FromBytes<1> for Cntr40Clr {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // CLR @ Cntr40Clr[0]:
          clr: val[0] & 0x1 != 0,
        }
    }
}

impl From<Cntr40Clr> for u8 {
    fn from(value: Cntr40Clr) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Cntr40Clr {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CODE_SELECT` Layout Conversion Functions ==============================

impl ToBytes<1> for CodeSelect {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // A @ CodeSelect[3:0]:
        let a: [u8; 1] = self.a.to_le_bytes();
        val[0] |= a[0] & 0xF;
        // B @ CodeSelect[7:4]:
        let b: [u8; 1] = self.b.to_le_bytes();
        val[0] |= (b[0] << 4) & 0xF0;
        val
    }
}

impl FromBytes<1> for CodeSelect {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // A @ CodeSelect[3:0]:
        let mut a: [u8; 1] = [0; 1];
        a[0] |= val[0] & 0xF;
        // B @ CodeSelect[7:4]:
        let mut b: [u8; 1] = [0; 1];
        b[0] |= (val[0] & 0xF0) >> 4;
        Self {
          // A @ CodeSelect[3:0]:
          a: BinCode::from_masked_le_bytes(&a),
          // B @ CodeSelect[7:4]:
          b: BinCode::from_masked_le_bytes(&b),
        }
    }
}

impl From<CodeSelect> for u8 {
    fn from(value: CodeSelect) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for CodeSelect {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `COMP_THRESH_W` Layout Conversion Functions ============================

impl ToBytes<1> for CompThreshW {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ CompThreshW[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for CompThreshW {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ CompThreshW[7:0]:
          data: val[0],
        }
    }
}

impl From<CompThreshW> for u8 {
    fn from(value: CompThreshW) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for CompThreshW {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CYCLPRESC` Layout Conversion Functions ================================

impl ToBytes<1> for Cyclpresc {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Cyclpresc[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Cyclpresc {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Cyclpresc[7:0]:
          data: val[0],
        }
    }
}

impl From<Cyclpresc> for u8 {
    fn from(value: Cyclpresc) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Cyclpresc {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CYCLTOP_HI` Layout Conversion Functions ===============================

impl ToBytes<1> for CycltopHi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ CycltopHi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for CycltopHi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ CycltopHi[7:0]:
          data: val[0],
        }
    }
}

impl From<CycltopHi> for u8 {
    fn from(value: CycltopHi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for CycltopHi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `CYCLTOP_LO` Layout Conversion Functions ===============================

impl ToBytes<1> for CycltopLo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ CycltopLo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for CycltopLo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ CycltopLo[7:0]:
          data: val[0],
        }
    }
}

impl From<CycltopLo> for u8 {
    fn from(value: CycltopLo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for CycltopLo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `D_CORNER_CTRL` Layout Conversion Functions ============================

impl ToBytes<1> for DCornerCtrl {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ DCornerCtrl[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for DCornerCtrl {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ DCornerCtrl[7:0]:
          data: val[0],
        }
    }
}

impl From<DCornerCtrl> for u8 {
    fn from(value: DCornerCtrl) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for DCornerCtrl {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `FDD_ACTIVE` Layout Conversion Functions ===============================

impl ToBytes<1> for FddActive {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // BAND_2G4 @ FddActive[0]:
        let band_2g4: [u8; 1] = self.band_2g4.to_le_bytes();
        val[0] |= band_2g4[0] & 0x1;
        // BAND_433 @ FddActive[2]:
        let band_433: [u8; 1] = self.band_433.to_le_bytes();
        val[0] |= (band_433[0] << 2) & 0x4;
        // BAND_868 @ FddActive[1]:
        let band_868: [u8; 1] = self.band_868.to_le_bytes();
        val[0] |= (band_868[0] << 1) & 0x2;
        val
    }
}

impl FromBytes<1> for FddActive {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // BAND_2G4 @ FddActive[0]:
        let mut band_2g4: [u8; 1] = [0; 1];
        band_2g4[0] |= val[0] & 0x1;
        // BAND_433 @ FddActive[2]:
        let mut band_433: [u8; 1] = [0; 1];
        band_433[0] |= (val[0] & 0x4) >> 2;
        // BAND_868 @ FddActive[1]:
        let mut band_868: [u8; 1] = [0; 1];
        band_868[0] |= (val[0] & 0x2) >> 1;
        Self {
          // BAND_2G4 @ FddActive[0]:
          band_2g4: FddMode::from_masked_le_bytes(&band_2g4),
          // BAND_433 @ FddActive[2]:
          band_433: FddMode::from_masked_le_bytes(&band_433),
          // BAND_868 @ FddActive[1]:
          band_868: FddMode::from_masked_le_bytes(&band_868),
        }
    }
}

impl From<FddActive> for u8 {
    fn from(value: FddActive) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for FddActive {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `FDD_ENABLE` Layout Conversion Functions ===============================

impl ToBytes<1> for FddEnable {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // FDD_BANDS @ FddEnable[2:0]:
        let fdd_bands: [u8; 1] = self.fdd_bands.to_le_bytes();
        val[0] |= fdd_bands[0] & 0x7;
        val
    }
}

impl FromBytes<1> for FddEnable {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // FDD_BANDS @ FddEnable[2:0]:
        let mut fdd_bands: [u8; 1] = [0; 1];
        fdd_bands[0] |= val[0] & 0x7;
        Self {
          // FDD_BANDS @ FddEnable[2:0]:
          fdd_bands: Bands::from_le_bytes(&fdd_bands),
        }
    }
}

impl From<FddEnable> for u8 {
    fn from(value: FddEnable) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for FddEnable {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `FDD_EXIT_COND` Layout Conversion Functions ============================

impl ToBytes<1> for FddExitCond {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // BAND_2G4 @ FddExitCond[5:4]:
        let band_2g4: [u8; 1] = self.band_2g4.to_le_bytes();
        val[0] |= (band_2g4[0] << 4) & 0x30;
        // BAND_433 @ FddExitCond[1:0]:
        let band_433: [u8; 1] = self.band_433.to_le_bytes();
        val[0] |= band_433[0] & 0x3;
        // BAND_868 @ FddExitCond[3:2]:
        let band_868: [u8; 1] = self.band_868.to_le_bytes();
        val[0] |= (band_868[0] << 2) & 0xC;
        val
    }
}

impl FromBytes<1> for FddExitCond {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // BAND_2G4 @ FddExitCond[5:4]:
        let mut band_2g4: [u8; 1] = [0; 1];
        band_2g4[0] |= (val[0] & 0x30) >> 4;
        // BAND_433 @ FddExitCond[1:0]:
        let mut band_433: [u8; 1] = [0; 1];
        band_433[0] |= val[0] & 0x3;
        // BAND_868 @ FddExitCond[3:2]:
        let mut band_868: [u8; 1] = [0; 1];
        band_868[0] |= (val[0] & 0xC) >> 2;
        Self {
          // BAND_2G4 @ FddExitCond[5:4]:
          band_2g4: ExitCond::from_masked_le_bytes(&band_2g4),
          // BAND_433 @ FddExitCond[1:0]:
          band_433: ExitCond::from_masked_le_bytes(&band_433),
          // BAND_868 @ FddExitCond[3:2]:
          band_868: ExitCond::from_masked_le_bytes(&band_868),
        }
    }
}

impl From<FddExitCond> for u8 {
    fn from(value: FddExitCond) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for FddExitCond {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `FIFO_COUNT_2G4` Layout Conversion Functions ===========================

impl ToBytes<1> for FifoCount2g4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ FifoCount2g4[5:0]:
        val[0] |= (self.data & 0x3F) as u8;
        val
    }
}

impl FromBytes<1> for FifoCount2g4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ FifoCount2g4[5:0]:
          data: val[0] & 0x3F,
        }
    }
}

impl From<FifoCount2g4> for u8 {
    fn from(value: FifoCount2g4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for FifoCount2g4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `FIFO_COUNT_433` Layout Conversion Functions ===========================

impl ToBytes<1> for FifoCount433 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ FifoCount433[5:0]:
        val[0] |= (self.data & 0x3F) as u8;
        val
    }
}

impl FromBytes<1> for FifoCount433 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ FifoCount433[5:0]:
          data: val[0] & 0x3F,
        }
    }
}

impl From<FifoCount433> for u8 {
    fn from(value: FifoCount433) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for FifoCount433 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `FIFO_COUNT_868` Layout Conversion Functions ===========================

impl ToBytes<1> for FifoCount868 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ FifoCount868[5:0]:
        val[0] |= (self.data & 0x3F) as u8;
        val
    }
}

impl FromBytes<1> for FifoCount868 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ FifoCount868[5:0]:
          data: val[0] & 0x3F,
        }
    }
}

impl From<FifoCount868> for u8 {
    fn from(value: FifoCount868) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for FifoCount868 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `FIFO_LENGTH` Layout Conversion Functions ==============================

impl ToBytes<1> for FifoLength {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // BAND_2G4 @ FifoLength[5:4]:
        let band_2g4: [u8; 1] = self.band_2g4.to_le_bytes();
        val[0] |= (band_2g4[0] << 4) & 0x30;
        // BAND_433 @ FifoLength[1:0]:
        let band_433: [u8; 1] = self.band_433.to_le_bytes();
        val[0] |= band_433[0] & 0x3;
        // BAND_868 @ FifoLength[3:2]:
        let band_868: [u8; 1] = self.band_868.to_le_bytes();
        val[0] |= (band_868[0] << 2) & 0xC;
        val
    }
}

impl FromBytes<1> for FifoLength {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // BAND_2G4 @ FifoLength[5:4]:
        let mut band_2g4: [u8; 1] = [0; 1];
        band_2g4[0] |= (val[0] & 0x30) >> 4;
        // BAND_433 @ FifoLength[1:0]:
        let mut band_433: [u8; 1] = [0; 1];
        band_433[0] |= val[0] & 0x3;
        // BAND_868 @ FifoLength[3:2]:
        let mut band_868: [u8; 1] = [0; 1];
        band_868[0] |= (val[0] & 0xC) >> 2;
        Self {
          // BAND_2G4 @ FifoLength[5:4]:
          band_2g4: FifoLen::from_masked_le_bytes(&band_2g4),
          // BAND_433 @ FifoLength[1:0]:
          band_433: FifoLen::from_masked_le_bytes(&band_433),
          // BAND_868 @ FifoLength[3:2]:
          band_868: FifoLen::from_masked_le_bytes(&band_868),
        }
    }
}

impl From<FifoLength> for u8 {
    fn from(value: FifoLength) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for FifoLength {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `FO_QUIT` Layout Conversion Functions ==================================

impl ToBytes<1> for FoQuit {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // QUIT_BANDS @ FoQuit[2:0]:
        let quit_bands: [u8; 1] = self.quit_bands.to_le_bytes();
        val[0] |= quit_bands[0] & 0x7;
        val
    }
}

impl FromBytes<1> for FoQuit {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // QUIT_BANDS @ FoQuit[2:0]:
        let mut quit_bands: [u8; 1] = [0; 1];
        quit_bands[0] |= val[0] & 0x7;
        Self {
          // QUIT_BANDS @ FoQuit[2:0]:
          quit_bands: Bands::from_le_bytes(&quit_bands),
        }
    }
}

impl From<FoQuit> for u8 {
    fn from(value: FoQuit) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for FoQuit {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `GENPURP_1` Layout Conversion Functions ================================

impl ToBytes<1> for Genpurp1 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Genpurp1[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Genpurp1 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Genpurp1[7:0]:
          data: val[0],
        }
    }
}

impl From<Genpurp1> for u8 {
    fn from(value: Genpurp1) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Genpurp1 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IDM_BAND` Layout Conversion Functions =================================

impl ToBytes<1> for IdmBand {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ IdmBand[1:0]:
        let data: [u8; 1] = self.data.to_le_bytes();
        val[0] |= data[0] & 0x3;
        val
    }
}

impl TryFromBytes<1> for IdmBand {
    type Error = FromBytesError;
    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        // DATA @ IdmBand[1:0]:
        let mut data: [u8; 1] = [0; 1];
        data[0] |= val[0] & 0x3;
        Ok(Self {
          // DATA @ IdmBand[1:0]:
          data: Data::try_from_le_bytes(&data)?,
        })
    }
}

impl From<IdmBand> for u8 {
    fn from(value: IdmBand) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl TryFrom<u8> for IdmBand {
    type Error = FromBytesError;
    fn try_from(value: u8) -> Result<Self, Self::Error> {
        Self::try_from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IDM_CLR` Layout Conversion Functions ==================================

impl ToBytes<1> for IdmClr {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // BRANCH @ IdmClr[0]:
        val[0] |= (u8::from(self.branch) & 0x1) as u8;
        val
    }
}

impl FromBytes<1> for IdmClr {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // BRANCH @ IdmClr[0]:
          branch: val[0] & 0x1 != 0,
        }
    }
}

impl From<IdmClr> for u8 {
    fn from(value: IdmClr) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IdmClr {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IDM_CTRL` Layout Conversion Functions =================================

impl ToBytes<1> for IdmCtrl {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // CTRL @ IdmCtrl[1:0]:
        let ctrl: [u8; 1] = self.ctrl.to_le_bytes();
        val[0] |= ctrl[0] & 0x3;
        val
    }
}

impl FromBytes<1> for IdmCtrl {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // CTRL @ IdmCtrl[1:0]:
        let mut ctrl: [u8; 1] = [0; 1];
        ctrl[0] |= val[0] & 0x3;
        Self {
          // CTRL @ IdmCtrl[1:0]:
          ctrl: Ctrl::from_masked_le_bytes(&ctrl),
        }
    }
}

impl From<IdmCtrl> for u8 {
    fn from(value: IdmCtrl) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IdmCtrl {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IDM_ENABLE` Layout Conversion Functions ===============================

impl ToBytes<1> for IdmEnable {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // MATCH_BANDS @ IdmEnable[2:0]:
        let match_bands: [u8; 1] = self.match_bands.to_le_bytes();
        val[0] |= match_bands[0] & 0x7;
        val
    }
}

impl FromBytes<1> for IdmEnable {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // MATCH_BANDS @ IdmEnable[2:0]:
        let mut match_bands: [u8; 1] = [0; 1];
        match_bands[0] |= val[0] & 0x7;
        Self {
          // MATCH_BANDS @ IdmEnable[2:0]:
          match_bands: Bands::from_le_bytes(&match_bands),
        }
    }
}

impl From<IdmEnable> for u8 {
    fn from(value: IdmEnable) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IdmEnable {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IDM_REASON` Layout Conversion Functions ===============================

impl ToBytes<1> for IdmReason {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // REASON @ IdmReason[1:0]:
        let reason: [u8; 1] = self.reason.to_le_bytes();
        val[0] |= reason[0] & 0x3;
        val
    }
}

impl FromBytes<1> for IdmReason {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // REASON @ IdmReason[1:0]:
        let mut reason: [u8; 1] = [0; 1];
        reason[0] |= val[0] & 0x3;
        Self {
          // REASON @ IdmReason[1:0]:
          reason: Reason::from_masked_le_bytes(&reason),
        }
    }
}

impl From<IdmReason> for u8 {
    fn from(value: IdmReason) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IdmReason {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `ID_HI` Layout Conversion Functions ====================================

impl ToBytes<1> for IdHi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ IdHi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for IdHi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ IdHi[7:0]:
          data: val[0],
        }
    }
}

impl From<IdHi> for u8 {
    fn from(value: IdHi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IdHi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `ID_LO` Layout Conversion Functions ====================================

impl ToBytes<1> for IdLo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ IdLo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for IdLo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ IdLo[7:0]:
          data: val[0],
        }
    }
}

impl From<IdLo> for u8 {
    fn from(value: IdLo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IdLo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IRQ_CLR` Layout Conversion Functions ==================================

impl ToBytes<1> for IrqClr {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // IRQ_CLR @ IrqClr[7:0]:
        let irq_clr: [u8; 1] = self.irq_clr.to_le_bytes();
        val[0] |= irq_clr[0];
        val
    }
}

impl FromBytes<1> for IrqClr {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // IRQ_CLR @ IrqClr[7:0]:
        let mut irq_clr: [u8; 1] = [0; 1];
        irq_clr[0] |= val[0];
        Self {
          // IRQ_CLR @ IrqClr[7:0]:
          irq_clr: IrqSource::from_le_bytes(&irq_clr),
        }
    }
}

impl From<IrqClr> for u8 {
    fn from(value: IrqClr) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IrqClr {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IRQ_SELECT` Layout Conversion Functions ===============================

impl ToBytes<1> for IrqSelect {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // IRQ_SELECT @ IrqSelect[7:0]:
        let irq_select: [u8; 1] = self.irq_select.to_le_bytes();
        val[0] |= irq_select[0];
        val
    }
}

impl FromBytes<1> for IrqSelect {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // IRQ_SELECT @ IrqSelect[7:0]:
        let mut irq_select: [u8; 1] = [0; 1];
        irq_select[0] |= val[0];
        Self {
          // IRQ_SELECT @ IrqSelect[7:0]:
          irq_select: IrqSource::from_le_bytes(&irq_select),
        }
    }
}

impl From<IrqSelect> for u8 {
    fn from(value: IrqSelect) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IrqSelect {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IRQ_SET` Layout Conversion Functions ==================================

impl ToBytes<1> for IrqSet {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // IRQ_SET @ IrqSet[7:0]:
        let irq_set: [u8; 1] = self.irq_set.to_le_bytes();
        val[0] |= irq_set[0];
        val
    }
}

impl FromBytes<1> for IrqSet {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // IRQ_SET @ IrqSet[7:0]:
        let mut irq_set: [u8; 1] = [0; 1];
        irq_set[0] |= val[0];
        Self {
          // IRQ_SET @ IrqSet[7:0]:
          irq_set: IrqSource::from_le_bytes(&irq_set),
        }
    }
}

impl From<IrqSet> for u8 {
    fn from(value: IrqSet) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IrqSet {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IRQ_SOURCE` Layout Conversion Functions ===============================

impl ToBytes<1> for IrqSource {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // CORREL_MATCH @ IrqSource[3]:
        val[0] |= ((u8::from(self.correl_match) << 3) & 0x8) as u8;
        // CYCLIC_TIMER_ALARM @ IrqSource[7]:
        val[0] |= ((u8::from(self.cyclic_timer_alarm) << 7) & 0x80) as u8;
        // FIFO_FULL @ IrqSource[2]:
        val[0] |= ((u8::from(self.fifo_full) << 2) & 0x4) as u8;
        // FIFO_OVERFLOW @ IrqSource[1]:
        val[0] |= ((u8::from(self.fifo_overflow) << 1) & 0x2) as u8;
        // ID_MATCH @ IrqSource[0]:
        val[0] |= (u8::from(self.id_match) & 0x1) as u8;
        // ID_MATCH_AND_FIFO_FULL @ IrqSource[4]:
        val[0] |= ((u8::from(self.id_match_and_fifo_full) << 4) & 0x10) as u8;
        // ID_MATCH_AND_LDR @ IrqSource[5]:
        val[0] |= ((u8::from(self.id_match_and_ldr) << 5) & 0x20) as u8;
        // RTC_TIMER_ALARM @ IrqSource[6]:
        val[0] |= ((u8::from(self.rtc_timer_alarm) << 6) & 0x40) as u8;
        val
    }
}

impl FromBytes<1> for IrqSource {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // CORREL_MATCH @ IrqSource[3]:
          correl_match: (val[0] & 0x8) >> 3 != 0,
          // CYCLIC_TIMER_ALARM @ IrqSource[7]:
          cyclic_timer_alarm: (val[0] & 0x80) >> 7 != 0,
          // FIFO_FULL @ IrqSource[2]:
          fifo_full: (val[0] & 0x4) >> 2 != 0,
          // FIFO_OVERFLOW @ IrqSource[1]:
          fifo_overflow: (val[0] & 0x2) >> 1 != 0,
          // ID_MATCH @ IrqSource[0]:
          id_match: val[0] & 0x1 != 0,
          // ID_MATCH_AND_FIFO_FULL @ IrqSource[4]:
          id_match_and_fifo_full: (val[0] & 0x10) >> 4 != 0,
          // ID_MATCH_AND_LDR @ IrqSource[5]:
          id_match_and_ldr: (val[0] & 0x20) >> 5 != 0,
          // RTC_TIMER_ALARM @ IrqSource[6]:
          rtc_timer_alarm: (val[0] & 0x40) >> 6 != 0,
        }
    }
}

impl From<IrqSource> for u8 {
    fn from(value: IrqSource) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IrqSource {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `IRQ_STATUS` Layout Conversion Functions ===============================

impl ToBytes<1> for IrqStatus {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // IRQ_STATUS @ IrqStatus[7:0]:
        let irq_status: [u8; 1] = self.irq_status.to_le_bytes();
        val[0] |= irq_status[0];
        val
    }
}

impl FromBytes<1> for IrqStatus {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // IRQ_STATUS @ IrqStatus[7:0]:
        let mut irq_status: [u8; 1] = [0; 1];
        irq_status[0] |= val[0];
        Self {
          // IRQ_STATUS @ IrqStatus[7:0]:
          irq_status: IrqSource::from_le_bytes(&irq_status),
        }
    }
}

impl From<IrqStatus> for u8 {
    fn from(value: IrqStatus) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for IrqStatus {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `KORREL_STATE` Layout Conversion Functions =============================

impl ToBytes<1> for KorrelState {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // KORREL_BRANCHES_A @ KorrelState[2:0]:
        let korrel_branches_a: [u8; 1] = self.korrel_branches_a.to_le_bytes();
        val[0] |= korrel_branches_a[0] & 0x7;
        // KORREL_BRANCHES_B @ KorrelState[5:3]:
        let korrel_branches_b: [u8; 1] = self.korrel_branches_b.to_le_bytes();
        val[0] |= (korrel_branches_b[0] << 3) & 0x38;
        // KORREL_BRANCHES_LATEST @ KorrelState[7:6]:
        let korrel_branches_latest: [u8; 1] = self.korrel_branches_latest.to_le_bytes();
        val[0] |= (korrel_branches_latest[0] << 6) & 0xC0;
        val
    }
}

impl TryFromBytes<1> for KorrelState {
    type Error = FromBytesError;
    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        // KORREL_BRANCHES_A @ KorrelState[2:0]:
        let mut korrel_branches_a: [u8; 1] = [0; 1];
        korrel_branches_a[0] |= val[0] & 0x7;
        // KORREL_BRANCHES_B @ KorrelState[5:3]:
        let mut korrel_branches_b: [u8; 1] = [0; 1];
        korrel_branches_b[0] |= (val[0] & 0x38) >> 3;
        // KORREL_BRANCHES_LATEST @ KorrelState[7:6]:
        let mut korrel_branches_latest: [u8; 1] = [0; 1];
        korrel_branches_latest[0] |= (val[0] & 0xC0) >> 6;
        Ok(Self {
          // KORREL_BRANCHES_A @ KorrelState[2:0]:
          korrel_branches_a: Branches::from_le_bytes(&korrel_branches_a),
          // KORREL_BRANCHES_B @ KorrelState[5:3]:
          korrel_branches_b: Branches::from_le_bytes(&korrel_branches_b),
          // KORREL_BRANCHES_LATEST @ KorrelState[7:6]:
          korrel_branches_latest: KorrelBranchesLatest::try_from_le_bytes(&korrel_branches_latest).map_err(|x| Self::Error {pos: x.pos + 6})?,
        })
    }
}

impl From<KorrelState> for u8 {
    fn from(value: KorrelState) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl TryFrom<u8> for KorrelState {
    type Error = FromBytesError;
    fn try_from(value: u8) -> Result<Self, Self::Error> {
        Self::try_from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `KORREL_SV_CLEAR` Layout Conversion Functions ==========================

impl ToBytes<1> for KorrelSvClear {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ KorrelSvClear[0]:
        val[0] |= (u8::from(self.data) & 0x1) as u8;
        val
    }
}

impl FromBytes<1> for KorrelSvClear {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ KorrelSvClear[0]:
          data: val[0] & 0x1 != 0,
        }
    }
}

impl From<KorrelSvClear> for u8 {
    fn from(value: KorrelSvClear) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for KorrelSvClear {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `KORREL_THRESH_A` Layout Conversion Functions ==========================

impl ToBytes<1> for KorrelThreshA {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ KorrelThreshA[4:0]:
        val[0] |= (self.data & 0x1F) as u8;
        val
    }
}

impl FromBytes<1> for KorrelThreshA {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ KorrelThreshA[4:0]:
          data: val[0] & 0x1F,
        }
    }
}

impl From<KorrelThreshA> for u8 {
    fn from(value: KorrelThreshA) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for KorrelThreshA {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `KORREL_THRESH_B` Layout Conversion Functions ==========================

impl ToBytes<1> for KorrelThreshB {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ KorrelThreshB[4:0]:
        val[0] |= (self.data & 0x1F) as u8;
        val
    }
}

impl FromBytes<1> for KorrelThreshB {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ KorrelThreshB[4:0]:
          data: val[0] & 0x1F,
        }
    }
}

impl From<KorrelThreshB> for u8 {
    fn from(value: KorrelThreshB) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for KorrelThreshB {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `KORREL_VAL` Layout Conversion Functions ===============================

impl ToBytes<1> for KorrelVal {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // A @ KorrelVal[3:0]:
        val[0] |= (self.a & 0xF) as u8;
        // B @ KorrelVal[7:4]:
        val[0] |= ((self.b << 4) & 0xF0) as u8;
        val
    }
}

impl FromBytes<1> for KorrelVal {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // A @ KorrelVal[3:0]:
          a: val[0] & 0xF,
          // B @ KorrelVal[7:4]:
          b: (val[0] & 0xF0) >> 4,
        }
    }
}

impl From<KorrelVal> for u8 {
    fn from(value: KorrelVal) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for KorrelVal {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `LCO_FREQ_2G4_HI` Layout Conversion Functions ==========================

impl ToBytes<1> for LcoFreq2g4Hi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ LcoFreq2g4Hi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for LcoFreq2g4Hi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ LcoFreq2g4Hi[7:0]:
          data: val[0],
        }
    }
}

impl From<LcoFreq2g4Hi> for u8 {
    fn from(value: LcoFreq2g4Hi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for LcoFreq2g4Hi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `LCO_FREQ_2G4_LO` Layout Conversion Functions ==========================

impl ToBytes<1> for LcoFreq2g4Lo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ LcoFreq2g4Lo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for LcoFreq2g4Lo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ LcoFreq2g4Lo[7:0]:
          data: val[0],
        }
    }
}

impl From<LcoFreq2g4Lo> for u8 {
    fn from(value: LcoFreq2g4Lo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for LcoFreq2g4Lo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `LCO_FREQ_433_HI` Layout Conversion Functions ==========================

impl ToBytes<1> for LcoFreq433Hi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ LcoFreq433Hi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for LcoFreq433Hi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ LcoFreq433Hi[7:0]:
          data: val[0],
        }
    }
}

impl From<LcoFreq433Hi> for u8 {
    fn from(value: LcoFreq433Hi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for LcoFreq433Hi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `LCO_FREQ_433_LO` Layout Conversion Functions ==========================

impl ToBytes<1> for LcoFreq433Lo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ LcoFreq433Lo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for LcoFreq433Lo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ LcoFreq433Lo[7:0]:
          data: val[0],
        }
    }
}

impl From<LcoFreq433Lo> for u8 {
    fn from(value: LcoFreq433Lo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for LcoFreq433Lo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `LCO_FREQ_868_HI` Layout Conversion Functions ==========================

impl ToBytes<1> for LcoFreq868Hi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ LcoFreq868Hi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for LcoFreq868Hi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ LcoFreq868Hi[7:0]:
          data: val[0],
        }
    }
}

impl From<LcoFreq868Hi> for u8 {
    fn from(value: LcoFreq868Hi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for LcoFreq868Hi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `LCO_FREQ_868_LO` Layout Conversion Functions ==========================

impl ToBytes<1> for LcoFreq868Lo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ LcoFreq868Lo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for LcoFreq868Lo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ LcoFreq868Lo[7:0]:
          data: val[0],
        }
    }
}

impl From<LcoFreq868Lo> for u8 {
    fn from(value: LcoFreq868Lo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for LcoFreq868Lo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `LC_TG_ENA` Layout Conversion Functions ================================

impl ToBytes<1> for LcTgEna {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ LcTgEna[0]:
        val[0] |= (u8::from(self.data) & 0x1) as u8;
        val
    }
}

impl FromBytes<1> for LcTgEna {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ LcTgEna[0]:
          data: val[0] & 0x1 != 0,
        }
    }
}

impl From<LcTgEna> for u8 {
    fn from(value: LcTgEna) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for LcTgEna {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `LDO_XTAL_CTRL` Layout Conversion Functions ============================

impl ToBytes<1> for LdoXtalCtrl {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // INT @ LdoXtalCtrl[1:0]:
        val[0] |= 0x3; // Fixed value.
        // LDO_ENA_NFA @ LdoXtalCtrl[5]:
        val[0] |= ((u8::from(self.ldo_ena_nfa) << 5) & 0x20) as u8;
        // XTAL_OSC_BYP @ LdoXtalCtrl[3]:
        val[0] |= ((u8::from(self.xtal_osc_byp) << 3) & 0x8) as u8;
        val
    }
}

impl FromBytes<1> for LdoXtalCtrl {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // LDO_ENA_NFA @ LdoXtalCtrl[5]:
          ldo_ena_nfa: (val[0] & 0x20) >> 5 != 0,
          // XTAL_OSC_BYP @ LdoXtalCtrl[3]:
          xtal_osc_byp: (val[0] & 0x8) >> 3 != 0,
        }
    }
}

impl From<LdoXtalCtrl> for u8 {
    fn from(value: LdoXtalCtrl) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for LdoXtalCtrl {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `MUX_D_OUT_SEL` Layout Conversion Functions ============================

impl ToBytes<1> for MuxDOutSel {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // OUT @ MuxDOutSel[3:0]:
        let out: [u8; 1] = self.out.to_le_bytes();
        val[0] |= out[0] & 0xF;
        val
    }
}

impl TryFromBytes<1> for MuxDOutSel {
    type Error = FromBytesError;
    fn try_from_le_bytes(val: &[u8; 1]) -> Result<Self, Self::Error> {
        // OUT @ MuxDOutSel[3:0]:
        let mut out: [u8; 1] = [0; 1];
        out[0] |= val[0] & 0xF;
        Ok(Self {
          // OUT @ MuxDOutSel[3:0]:
          out: Out::try_from_le_bytes(&out)?,
        })
    }
}

impl From<MuxDOutSel> for u8 {
    fn from(value: MuxDOutSel) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl TryFrom<u8> for MuxDOutSel {
    type Error = FromBytesError;
    fn try_from(value: u8) -> Result<Self, Self::Error> {
        Self::try_from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `NFA2G4_FAST` Layout Conversion Functions ==============================

impl ToBytes<1> for Nfa2g4Fast {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Nfa2g4Fast[2:0]:
        let data: [u8; 1] = self.data.to_le_bytes();
        val[0] |= data[0] & 0x7;
        val
    }
}

impl FromBytes<1> for Nfa2g4Fast {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // DATA @ Nfa2g4Fast[2:0]:
        let mut data: [u8; 1] = [0; 1];
        data[0] |= val[0] & 0x7;
        Self {
          // DATA @ Nfa2g4Fast[2:0]:
          data: SampleRate::from_masked_le_bytes(&data),
        }
    }
}

impl From<Nfa2g4Fast> for u8 {
    fn from(value: Nfa2g4Fast) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Nfa2g4Fast {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `NFA2G4_SLOW` Layout Conversion Functions ==============================

impl ToBytes<1> for Nfa2g4Slow {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Nfa2g4Slow[2:0]:
        let data: [u8; 1] = self.data.to_le_bytes();
        val[0] |= data[0] & 0x7;
        val
    }
}

impl FromBytes<1> for Nfa2g4Slow {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // DATA @ Nfa2g4Slow[2:0]:
        let mut data: [u8; 1] = [0; 1];
        data[0] |= val[0] & 0x7;
        Self {
          // DATA @ Nfa2g4Slow[2:0]:
          data: SampleRate::from_masked_le_bytes(&data),
        }
    }
}

impl From<Nfa2g4Slow> for u8 {
    fn from(value: Nfa2g4Slow) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Nfa2g4Slow {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `NFA433_FAST` Layout Conversion Functions ==============================

impl ToBytes<1> for Nfa433Fast {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Nfa433Fast[2:0]:
        let data: [u8; 1] = self.data.to_le_bytes();
        val[0] |= data[0] & 0x7;
        val
    }
}

impl FromBytes<1> for Nfa433Fast {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // DATA @ Nfa433Fast[2:0]:
        let mut data: [u8; 1] = [0; 1];
        data[0] |= val[0] & 0x7;
        Self {
          // DATA @ Nfa433Fast[2:0]:
          data: SampleRate::from_masked_le_bytes(&data),
        }
    }
}

impl From<Nfa433Fast> for u8 {
    fn from(value: Nfa433Fast) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Nfa433Fast {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `NFA433_SLOW` Layout Conversion Functions ==============================

impl ToBytes<1> for Nfa433Slow {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Nfa433Slow[2:0]:
        let data: [u8; 1] = self.data.to_le_bytes();
        val[0] |= data[0] & 0x7;
        val
    }
}

impl FromBytes<1> for Nfa433Slow {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // DATA @ Nfa433Slow[2:0]:
        let mut data: [u8; 1] = [0; 1];
        data[0] |= val[0] & 0x7;
        Self {
          // DATA @ Nfa433Slow[2:0]:
          data: SampleRate::from_masked_le_bytes(&data),
        }
    }
}

impl From<Nfa433Slow> for u8 {
    fn from(value: Nfa433Slow) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Nfa433Slow {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `NFA868_FAST` Layout Conversion Functions ==============================

impl ToBytes<1> for Nfa868Fast {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Nfa868Fast[2:0]:
        let data: [u8; 1] = self.data.to_le_bytes();
        val[0] |= data[0] & 0x7;
        val
    }
}

impl FromBytes<1> for Nfa868Fast {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // DATA @ Nfa868Fast[2:0]:
        let mut data: [u8; 1] = [0; 1];
        data[0] |= val[0] & 0x7;
        Self {
          // DATA @ Nfa868Fast[2:0]:
          data: SampleRate::from_masked_le_bytes(&data),
        }
    }
}

impl From<Nfa868Fast> for u8 {
    fn from(value: Nfa868Fast) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Nfa868Fast {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `NFA868_SLOW` Layout Conversion Functions ==============================

impl ToBytes<1> for Nfa868Slow {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Nfa868Slow[2:0]:
        let data: [u8; 1] = self.data.to_le_bytes();
        val[0] |= data[0] & 0x7;
        val
    }
}

impl FromBytes<1> for Nfa868Slow {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // DATA @ Nfa868Slow[2:0]:
        let mut data: [u8; 1] = [0; 1];
        data[0] |= val[0] & 0x7;
        Self {
          // DATA @ Nfa868Slow[2:0]:
          data: SampleRate::from_masked_le_bytes(&data),
        }
    }
}

impl From<Nfa868Slow> for u8 {
    fn from(value: Nfa868Slow) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Nfa868Slow {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `N_LCO_TARGET_2G4_HI` Layout Conversion Functions ======================

impl ToBytes<1> for NLcoTarget2g4Hi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ NLcoTarget2g4Hi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for NLcoTarget2g4Hi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ NLcoTarget2g4Hi[7:0]:
          data: val[0],
        }
    }
}

impl From<NLcoTarget2g4Hi> for u8 {
    fn from(value: NLcoTarget2g4Hi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for NLcoTarget2g4Hi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `N_LCO_TARGET_2G4_LO` Layout Conversion Functions ======================

impl ToBytes<1> for NLcoTarget2g4Lo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ NLcoTarget2g4Lo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for NLcoTarget2g4Lo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ NLcoTarget2g4Lo[7:0]:
          data: val[0],
        }
    }
}

impl From<NLcoTarget2g4Lo> for u8 {
    fn from(value: NLcoTarget2g4Lo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for NLcoTarget2g4Lo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `N_LCO_TARGET_433_HI` Layout Conversion Functions ======================

impl ToBytes<1> for NLcoTarget433Hi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ NLcoTarget433Hi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for NLcoTarget433Hi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ NLcoTarget433Hi[7:0]:
          data: val[0],
        }
    }
}

impl From<NLcoTarget433Hi> for u8 {
    fn from(value: NLcoTarget433Hi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for NLcoTarget433Hi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `N_LCO_TARGET_433_LO` Layout Conversion Functions ======================

impl ToBytes<1> for NLcoTarget433Lo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ NLcoTarget433Lo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for NLcoTarget433Lo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ NLcoTarget433Lo[7:0]:
          data: val[0],
        }
    }
}

impl From<NLcoTarget433Lo> for u8 {
    fn from(value: NLcoTarget433Lo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for NLcoTarget433Lo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `N_LCO_TARGET_868_HI` Layout Conversion Functions ======================

impl ToBytes<1> for NLcoTarget868Hi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ NLcoTarget868Hi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for NLcoTarget868Hi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ NLcoTarget868Hi[7:0]:
          data: val[0],
        }
    }
}

impl From<NLcoTarget868Hi> for u8 {
    fn from(value: NLcoTarget868Hi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for NLcoTarget868Hi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `N_LCO_TARGET_868_LO` Layout Conversion Functions ======================

impl ToBytes<1> for NLcoTarget868Lo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ NLcoTarget868Lo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for NLcoTarget868Lo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ NLcoTarget868Lo[7:0]:
          data: val[0],
        }
    }
}

impl From<NLcoTarget868Lo> for u8 {
    fn from(value: NLcoTarget868Lo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for NLcoTarget868Lo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `N_SPG_TARGET` Layout Conversion Functions =============================

impl ToBytes<1> for NSpgTarget {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ NSpgTarget[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for NSpgTarget {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ NSpgTarget[7:0]:
          data: val[0],
        }
    }
}

impl From<NSpgTarget> for u8 {
    fn from(value: NSpgTarget) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for NSpgTarget {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTC` Layout Conversion Functions ======================================

impl ToBytes<1> for Rtc {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // RTCLG0 @ Rtc[2]:
        val[0] |= ((u8::from(self.rtclg0) << 2) & 0x4) as u8;
        // RTCLG1 @ Rtc[3]:
        val[0] |= ((u8::from(self.rtclg1) << 3) & 0x8) as u8;
        // RTCSH0 @ Rtc[0]:
        val[0] |= (u8::from(self.rtcsh0) & 0x1) as u8;
        // RTCSH1 @ Rtc[1]:
        val[0] |= ((u8::from(self.rtcsh1) << 1) & 0x2) as u8;
        val
    }
}

impl FromBytes<1> for Rtc {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // RTCLG0 @ Rtc[2]:
          rtclg0: (val[0] & 0x4) >> 2 != 0,
          // RTCLG1 @ Rtc[3]:
          rtclg1: (val[0] & 0x8) >> 3 != 0,
          // RTCSH0 @ Rtc[0]:
          rtcsh0: val[0] & 0x1 != 0,
          // RTCSH1 @ Rtc[1]:
          rtcsh1: (val[0] & 0x2) >> 1 != 0,
        }
    }
}

impl From<Rtc> for u8 {
    fn from(value: Rtc) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtc {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG0_THRESH_0` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg0Thresh0 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg0Thresh0[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg0Thresh0 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg0Thresh0[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg0Thresh0> for u8 {
    fn from(value: Rtclg0Thresh0) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg0Thresh0 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG0_THRESH_1` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg0Thresh1 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg0Thresh1[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg0Thresh1 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg0Thresh1[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg0Thresh1> for u8 {
    fn from(value: Rtclg0Thresh1) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg0Thresh1 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG0_THRESH_2` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg0Thresh2 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg0Thresh2[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg0Thresh2 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg0Thresh2[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg0Thresh2> for u8 {
    fn from(value: Rtclg0Thresh2) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg0Thresh2 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG0_THRESH_3` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg0Thresh3 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg0Thresh3[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg0Thresh3 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg0Thresh3[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg0Thresh3> for u8 {
    fn from(value: Rtclg0Thresh3) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg0Thresh3 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG0_THRESH_4` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg0Thresh4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg0Thresh4[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg0Thresh4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg0Thresh4[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg0Thresh4> for u8 {
    fn from(value: Rtclg0Thresh4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg0Thresh4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG1_THRESH_0` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg1Thresh0 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg1Thresh0[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg1Thresh0 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg1Thresh0[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg1Thresh0> for u8 {
    fn from(value: Rtclg1Thresh0) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg1Thresh0 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG1_THRESH_1` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg1Thresh1 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg1Thresh1[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg1Thresh1 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg1Thresh1[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg1Thresh1> for u8 {
    fn from(value: Rtclg1Thresh1) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg1Thresh1 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG1_THRESH_2` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg1Thresh2 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg1Thresh2[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg1Thresh2 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg1Thresh2[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg1Thresh2> for u8 {
    fn from(value: Rtclg1Thresh2) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg1Thresh2 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG1_THRESH_3` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg1Thresh3 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg1Thresh3[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg1Thresh3 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg1Thresh3[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg1Thresh3> for u8 {
    fn from(value: Rtclg1Thresh3) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg1Thresh3 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCLG1_THRESH_4` Layout Conversion Functions ==========================

impl ToBytes<1> for Rtclg1Thresh4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtclg1Thresh4[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtclg1Thresh4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtclg1Thresh4[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtclg1Thresh4> for u8 {
    fn from(value: Rtclg1Thresh4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtclg1Thresh4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCSH0_THRESH_HI` Layout Conversion Functions =========================

impl ToBytes<1> for Rtcsh0ThreshHi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtcsh0ThreshHi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtcsh0ThreshHi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtcsh0ThreshHi[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtcsh0ThreshHi> for u8 {
    fn from(value: Rtcsh0ThreshHi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtcsh0ThreshHi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCSH0_THRESH_LO` Layout Conversion Functions =========================

impl ToBytes<1> for Rtcsh0ThreshLo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtcsh0ThreshLo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtcsh0ThreshLo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtcsh0ThreshLo[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtcsh0ThreshLo> for u8 {
    fn from(value: Rtcsh0ThreshLo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtcsh0ThreshLo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCSH1_THRESH_HI` Layout Conversion Functions =========================

impl ToBytes<1> for Rtcsh1ThreshHi {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtcsh1ThreshHi[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtcsh1ThreshHi {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtcsh1ThreshHi[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtcsh1ThreshHi> for u8 {
    fn from(value: Rtcsh1ThreshHi) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtcsh1ThreshHi {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTCSH1_THRESH_LO` Layout Conversion Functions =========================

impl ToBytes<1> for Rtcsh1ThreshLo {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ Rtcsh1ThreshLo[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for Rtcsh1ThreshLo {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ Rtcsh1ThreshLo[7:0]:
          data: val[0],
        }
    }
}

impl From<Rtcsh1ThreshLo> for u8 {
    fn from(value: Rtcsh1ThreshLo) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Rtcsh1ThreshLo {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTC_CLR` Layout Conversion Functions ==================================

impl ToBytes<1> for RtcClr {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // RTC_CLR @ RtcClr[3:0]:
        let rtc_clr: [u8; 1] = self.rtc_clr.to_le_bytes();
        val[0] |= rtc_clr[0] & 0xF;
        val
    }
}

impl FromBytes<1> for RtcClr {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // RTC_CLR @ RtcClr[3:0]:
        let mut rtc_clr: [u8; 1] = [0; 1];
        rtc_clr[0] |= val[0] & 0xF;
        Self {
          // RTC_CLR @ RtcClr[3:0]:
          rtc_clr: Rtc::from_le_bytes(&rtc_clr),
        }
    }
}

impl From<RtcClr> for u8 {
    fn from(value: RtcClr) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RtcClr {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTC_SELECT` Layout Conversion Functions ===============================

impl ToBytes<1> for RtcSelect {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // CYCLTOP @ RtcSelect[4]:
        val[0] |= ((u8::from(self.cycltop) << 4) & 0x10) as u8;
        // RTC_SELECT @ RtcSelect[3:0]:
        let rtc_select: [u8; 1] = self.rtc_select.to_le_bytes();
        val[0] |= rtc_select[0] & 0xF;
        val
    }
}

impl FromBytes<1> for RtcSelect {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // RTC_SELECT @ RtcSelect[3:0]:
        let mut rtc_select: [u8; 1] = [0; 1];
        rtc_select[0] |= val[0] & 0xF;
        Self {
          // CYCLTOP @ RtcSelect[4]:
          cycltop: (val[0] & 0x10) >> 4 != 0,
          // RTC_SELECT @ RtcSelect[3:0]:
          rtc_select: Rtc::from_le_bytes(&rtc_select),
        }
    }
}

impl From<RtcSelect> for u8 {
    fn from(value: RtcSelect) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RtcSelect {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RTC_STATUS` Layout Conversion Functions ===============================

impl ToBytes<1> for RtcStatus {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // RTC_SELECT @ RtcStatus[3:0]:
        let rtc_select: [u8; 1] = self.rtc_select.to_le_bytes();
        val[0] |= rtc_select[0] & 0xF;
        val
    }
}

impl FromBytes<1> for RtcStatus {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        // RTC_SELECT @ RtcStatus[3:0]:
        let mut rtc_select: [u8; 1] = [0; 1];
        rtc_select[0] |= val[0] & 0xF;
        Self {
          // RTC_SELECT @ RtcStatus[3:0]:
          rtc_select: Rtc::from_le_bytes(&rtc_select),
        }
    }
}

impl From<RtcStatus> for u8 {
    fn from(value: RtcStatus) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RtcStatus {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_0_2G4` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo02g4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo02g4[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo02g4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo02g4[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo02g4> for u8 {
    fn from(value: RxFifo02g4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo02g4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_0_433` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo0433 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo0433[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo0433 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo0433[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo0433> for u8 {
    fn from(value: RxFifo0433) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo0433 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_0_868` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo0868 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo0868[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo0868 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo0868[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo0868> for u8 {
    fn from(value: RxFifo0868) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo0868 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_1_2G4` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo12g4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo12g4[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo12g4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo12g4[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo12g4> for u8 {
    fn from(value: RxFifo12g4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo12g4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_1_433` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo1433 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo1433[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo1433 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo1433[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo1433> for u8 {
    fn from(value: RxFifo1433) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo1433 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_1_868` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo1868 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo1868[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo1868 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo1868[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo1868> for u8 {
    fn from(value: RxFifo1868) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo1868 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_2_2G4` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo22g4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo22g4[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo22g4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo22g4[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo22g4> for u8 {
    fn from(value: RxFifo22g4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo22g4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_2_433` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo2433 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo2433[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo2433 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo2433[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo2433> for u8 {
    fn from(value: RxFifo2433) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo2433 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_2_868` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo2868 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo2868[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo2868 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo2868[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo2868> for u8 {
    fn from(value: RxFifo2868) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo2868 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_3_2G4` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo32g4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo32g4[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo32g4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo32g4[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo32g4> for u8 {
    fn from(value: RxFifo32g4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo32g4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_3_433` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo3433 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo3433[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo3433 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo3433[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo3433> for u8 {
    fn from(value: RxFifo3433) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo3433 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_3_868` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo3868 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo3868[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo3868 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo3868[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo3868> for u8 {
    fn from(value: RxFifo3868) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo3868 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_4_2G4` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo42g4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo42g4[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo42g4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo42g4[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo42g4> for u8 {
    fn from(value: RxFifo42g4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo42g4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_4_433` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo4433 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo4433[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo4433 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo4433[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo4433> for u8 {
    fn from(value: RxFifo4433) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo4433 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_4_868` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo4868 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo4868[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo4868 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo4868[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo4868> for u8 {
    fn from(value: RxFifo4868) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo4868 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_5_2G4` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo52g4 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo52g4[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo52g4 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo52g4[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo52g4> for u8 {
    fn from(value: RxFifo52g4) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo52g4 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_5_433` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo5433 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo5433[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo5433 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo5433[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo5433> for u8 {
    fn from(value: RxFifo5433) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo5433 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `RX_FIFO_5_868` Layout Conversion Functions ============================

impl ToBytes<1> for RxFifo5868 {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ RxFifo5868[7:0]:
        val[0] |= self.data as u8;
        val
    }
}

impl FromBytes<1> for RxFifo5868 {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ RxFifo5868[7:0]:
          data: val[0],
        }
    }
}

impl From<RxFifo5868> for u8 {
    fn from(value: RxFifo5868) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for RxFifo5868 {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `VERSION` Layout Conversion Functions ==================================

impl ToBytes<1> for Version {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // VERSION_NUMBER @ Version[7:0]:
        val[0] |= 0x41; // Fixed value.
        val
    }
}

impl FromBytes<1> for Version {
    fn from_le_bytes(_val: &[u8; 1]) -> Self {
        Self {
        }
    }
}

impl From<Version> for u8 {
    fn from(value: Version) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for Version {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `XTAL_GOOD` Layout Conversion Functions ================================

impl ToBytes<1> for XtalGood {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ XtalGood[0]:
        val[0] |= (u8::from(self.data) & 0x1) as u8;
        val
    }
}

impl FromBytes<1> for XtalGood {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ XtalGood[0]:
          data: val[0] & 0x1 != 0,
        }
    }
}

impl From<XtalGood> for u8 {
    fn from(value: XtalGood) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for XtalGood {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}

// ==== `XTAL_OSC_CTRL` Layout Conversion Functions ============================

impl ToBytes<1> for XtalOscCtrl {
    #[allow(clippy::cast_possible_truncation)]
    fn to_le_bytes(&self) -> [u8; 1] {
        let mut val: [u8; 1] = [0; 1];
        // DATA @ XtalOscCtrl[0]:
        val[0] |= (u8::from(self.data) & 0x1) as u8;
        val
    }
}

impl FromBytes<1> for XtalOscCtrl {
    fn from_le_bytes(val: &[u8; 1]) -> Self {
        Self {
          // DATA @ XtalOscCtrl[0]:
          data: val[0] & 0x1 != 0,
        }
    }
}

impl From<XtalOscCtrl> for u8 {
    fn from(value: XtalOscCtrl) -> Self {
        Self::from_le_bytes(value.to_le_bytes())
    }
}

impl From<u8> for XtalOscCtrl {
    fn from(value: u8) -> Self {
        Self::from_le_bytes(&value.to_le_bytes())
    }
}
