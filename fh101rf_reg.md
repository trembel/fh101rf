# FH101RF

## Register Map

Generated from listing file: ./fh101rf.yaml.

Listing file author: Jonah Imfeld, Silvano Cortesi.

Listing file notice:
```
  Licensed under LGPL-3.0
  File Version: 1.0.1
```

| **Address** | **Register**        | **Reset Value** | **Brief**                                                                                                                                                                                      |
| ----------- | ------------------- | --------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 0x00        | NFA433_SLOW         | 0x05            | Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 433-MHz band.                                                      |
| 0x01        | NFA433_FAST         | 0x00            | Set the sample-rate for FDD-mode data reception in the 433-MHz band.                                                                                                                           |
| 0x02        | NFA868_SLOW         | 0x05            | Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 868-MHz band.                                                      |
| 0x03        | NFA868_FAST         | 0x00            | Set the sample-rate for FDD-mode data reception in the 868-MHz band.                                                                                                                           |
| 0x04        | NFA2G4_SLOW         | 0x05            | Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 2.4-GHz band.                                                      |
| 0x05        | NFA2G4_FAST         | 0x00            | Set the sample-rate for FDD-mode data reception in the 2.4-GHz band.                                                                                                                           |
| 0x06        | CALIB_STATUS        | 0x00            | Indicates status of all calibration processes.                                                                                                                                                 |
| 0x07        | CALIB_CTRL          | 0x0E            | Control register for starting calibration processes.                                                                                                                                           |
| 0x09        | N_SPG_TARGET        | 0x31            | Target register for the Signal Processing Gain setting. Set to 0x46 during SPG calibration.                                                                                                    |
| 0x0B        | N_LCO_TARGET_433_HI | 0x0E            | Sets the high byte (15:8) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891. (According to register table in DS v1.3b, only 12:8).       |
| 0x0C        | N_LCO_TARGET_433_LO | 0x20            | Sets the low byte (7:0) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891.                                                               |
| 0x0D        | N_LCO_TARGET_868_HI | 0x0D            | Sets the high byte (15:8) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738. (According to register table in DS v1.3b, only 12:8).   |
| 0x0E        | N_LCO_TARGET_868_LO | 0x87            | Sets the low byte (7:0) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738.                                                           |
| 0x0F        | N_LCO_TARGET_2G4_HI | 0x12            | Sets the high byte (15:8) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833. (According to register table in DS v1.3b, only 12:8).      |
| 0x10        | N_LCO_TARGET_2G4_LO | 0xCE            | Sets the low byte (7:0) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833.                                                              |
| 0x14        | LCO_FREQ_433_HI     | 0x00            | Holds the current frequency of the 433-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).              |
| 0x15        | LCO_FREQ_433_LO     | 0x00            | Holds the current frequency of the 433-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.                                                                      |
| 0x16        | LCO_FREQ_868_HI     | 0x00            | Holds the current frequency of the 868/915-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).          |
| 0x17        | LCO_FREQ_868_LO     | 0x00            | Holds the current frequency of the 868/915-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.                                                                  |
| 0x18        | LCO_FREQ_2G4_HI     | 0x00            | Holds the current frequency of the 2.4-GHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).              |
| 0x19        | LCO_FREQ_2G4_LO     | 0x00            | Holds the current frequency of the 2.4-GHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.                                                                      |
| 0x23        | D_CORNER_CTRL       | 0x00            | Set to 0x02 at power-up.                                                                                                                                                                       |
| 0x24        | BAND_BRANCH_CTRL    | 0x77            | Selects the active bands and branches (RF-sensitivity).                                                                                                                                        |
| 0x28        | CODE_SELECT         | 0x10            | Selects the correlation patterns for code A and B.                                                                                                                                             |
| 0x29        | KORREL_THRESH_A     | 0x1A            | Sets the threshold for a code A match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).                   |
| 0x2A        | KORREL_THRESH_B     | 0x1A            | Sets the threshold for a code B match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).                   |
| 0x2B        | KORREL_STATE        | 0xC0            | -                                                                                                                                                                                              |
| 0x2C        | KORREL_VAL          | 0x00            | Indicates the match level for code A and B. A value of 15 indicates no bit errors, a value of 0 indicates 15 bit errors.                                                                       |
| 0x2D        | FDD_ENABLE          | 0x07            | Enable the fast data decoder for a given band.                                                                                                                                                 |
| 0x2E        | FDD_ACTIVE          | 0x00            | Reads the FDD mode for each band.                                                                                                                                                              |
| 0x2F        | FO_QUIT             | 0x00            | Forces the specified band to quit fast mode immediately.                                                                                                                                       |
| 0x30        | FDD_EXIT_COND       | 0x00            | Holds the FDD exit condition for all the bands.                                                                                                                                                |
| 0x31        | IRQ_SELECT          | 0x01            | Selects the interrupt sources.                                                                                                                                                                 |
| 0x32        | IRQ_STATUS          | 0x00            | Holds the status of the IRQ events.                                                                                                                                                            |
| 0x33        | IRQ_CLR             | 0x00            | Resets the corresponding IRQ event bit.                                                                                                                                                        |
| 0x34        | IRQ_SET             | 0x00            | Sets the corresponding IRQ event bit (triggers IRQ events for debugging).                                                                                                                      |
| 0x35        | ID_HI               | 0x7D            | Sets the high byte of the match ID. 4-MSB form the group ID.                                                                                                                                   |
| 0x36        | ID_LO               | 0xA8            | Sets the low byte of the match ID.                                                                                                                                                             |
| 0x37        | IDM_ENABLE          | 0x07            | Enables the ID match for a given band.                                                                                                                                                         |
| 0x38        | IDM_CTRL            | 0x00            | Slect the type of ID's accepted by the receiver.                                                                                                                                               |
| 0x39        | IDM_CLR             | 0x00            | Clear the FDD_EXIT_COND register.                                                                                                                                                              |
| 0x3A        | IDM_BAND            | 0x03            | Indicates the frequency band of the ID match event.                                                                                                                                            |
| 0x3B        | IDM_REASON          | 0x00            | Indicates the type of ID match event.                                                                                                                                                          |
| 0x3C        | RTC_SELECT          | 0x00            | Allows for selection of the desired timer modes.                                                                                                                                               |
| 0x3D        | RTC_STATUS          | 0x00            | Indicates occurence of RTC events.                                                                                                                                                             |
| 0x3E        | RTC_CLR             | 0x00            | Clears the respective event entries in RTC_STATUS.                                                                                                                                             |
| 0x3F        | RTCSH0_THRESH_HI    | 0x00            | Upper (Bits 15:8) byte of the RTCSH0 threshold.                                                                                                                                                |
| 0x40        | RTCSH0_THRESH_LO    | 0x00            | Lower (Bits 7:0) byte of the RTCSH0 threshold.                                                                                                                                                 |
| 0x41        | RTCSH1_THRESH_HI    | 0x00            | Upper (Bits 15:8) byte of the RTCSH1 threshold.                                                                                                                                                |
| 0x42        | RTCSH1_THRESH_LO    | 0x00            | Lower (Bits 7:0) byte of the RTCSH1 threshold.                                                                                                                                                 |
| 0x43        | RTCLG0_THRESH_4     | 0x00            | Bits 39:32 of the RTCLG0 threshold.                                                                                                                                                            |
| 0x44        | RTCLG0_THRESH_3     | 0x00            | Bits 31:24 of the RTCLG0 threshold.                                                                                                                                                            |
| 0x45        | RTCLG0_THRESH_2     | 0x00            | Bits 23:16 of the RTCLG0 threshold.                                                                                                                                                            |
| 0x46        | RTCLG0_THRESH_1     | 0x00            | Bits 15:8 of the RTCLG0 threshold.                                                                                                                                                             |
| 0x47        | RTCLG0_THRESH_0     | 0x00            | Bits 7:0 of the RTCLG0 threshold.                                                                                                                                                              |
| 0x48        | RTCLG1_THRESH_4     | 0x00            | Bits 39:32 of the RTCLG1 threshold.                                                                                                                                                            |
| 0x49        | RTCLG1_THRESH_3     | 0x00            | Bits 31:24 of the RTCLG1 threshold.                                                                                                                                                            |
| 0x4A        | RTCLG1_THRESH_2     | 0x00            | Bits 23:16 of the RTCLG1 threshold.                                                                                                                                                            |
| 0x4B        | RTCLG1_THRESH_1     | 0x00            | Bits 15:8 of the RTCLG1 threshold.                                                                                                                                                             |
| 0x4C        | RTCLG1_THRESH_0     | 0x00            | Bits 7:0 of the RTCLG1 threshold.                                                                                                                                                              |
| 0x4D        | CYCLPRESC           | 0x00            | Cycle prescaler for cyclic counter, system clock divided by prescaler (therefore max 8:29.9922 minutes).                                                                                       |
| 0x4E        | CYCLTOP_HI          | 0x00            | Bits 15:8 defining the maximal cyclic counter value CYCLTOP before being reset to zero.                                                                                                        |
| 0x4F        | CYCLTOP_LO          | 0x00            | Bits 7:0 defining the maximal cyclic counter value CYCLTOP before being reset to zero.                                                                                                         |
| 0x50        | CNTR40_4            | 0x00            | Bits 39:32 of the system clock counter CNTR40.                                                                                                                                                 |
| 0x51        | CNTR40_3            | 0x00            | Bits 31:24 of the system clock counter CNTR40.                                                                                                                                                 |
| 0x52        | CNTR40_2            | 0x00            | Bits 23:16 of the system clock counter CNTR40.                                                                                                                                                 |
| 0x53        | CNTR40_1            | 0x00            | Bits 15:8 of the system clock counter CNTR40.                                                                                                                                                  |
| 0x54        | CNTR40_0            | 0x00            | Bits 7:0 of the system clock counter CNTR40.                                                                                                                                                   |
| 0x55        | CNTR40_CLR          | 0x00            | Clear the system clock counter CNTR40 by setting this to true. Manually setting the register to false afterwards is mandatory!                                                                 |
| 0x56        | FIFO_LENGTH         | 0x14            | Selects the FIFO length for each band.                                                                                                                                                         |
| 0x57        | FIFO_COUNT_433      | 0x00            | Number of bits in the FIFO buffer for the 433MHz band. Can be cleared by writing 0.                                                                                                            |
| 0x58        | FIFO_COUNT_868      | 0x00            | Number of bits in the FIFO buffer for the 868/915MHz band. Can be cleared by writing 0.                                                                                                        |
| 0x59        | FIFO_COUNT_2G4      | 0x00            | Number of bits in the FIFO buffer for the 2.4GHz band. Can be cleared by writing 0.                                                                                                            |
| 0x5A        | RX_FIFO_5_433       | 0x00            | The FIFO byte 5 for the 433MHz band, _5 is filled first.                                                                                                                                       |
| 0x5B        | RX_FIFO_4_433       | 0x00            | The FIFO byte 4 for the 433MHz band, _5 is filled first.                                                                                                                                       |
| 0x5C        | RX_FIFO_3_433       | 0x00            | The FIFO byte 3 for the 433MHz band, _5 is filled first.                                                                                                                                       |
| 0x5D        | RX_FIFO_2_433       | 0x00            | The FIFO byte 2 for the 433MHz band, _5 is filled first.                                                                                                                                       |
| 0x5E        | RX_FIFO_1_433       | 0x00            | The FIFO byte 1 for the 433MHz band, _5 is filled first.                                                                                                                                       |
| 0x5F        | RX_FIFO_0_433       | 0x00            | The FIFO byte 0 for the 433MHz band, _5 is filled first.                                                                                                                                       |
| 0x60        | RX_FIFO_5_868       | 0x00            | The FIFO byte 5 for the 868MHz band, _5 is filled first.                                                                                                                                       |
| 0x61        | RX_FIFO_4_868       | 0x00            | The FIFO byte 4 for the 868MHz band, _5 is filled first.                                                                                                                                       |
| 0x62        | RX_FIFO_3_868       | 0x00            | The FIFO byte 3 for the 868MHz band, _5 is filled first.                                                                                                                                       |
| 0x63        | RX_FIFO_2_868       | 0x00            | The FIFO byte 2 for the 868MHz band, _5 is filled first.                                                                                                                                       |
| 0x64        | RX_FIFO_1_868       | 0x00            | The FIFO byte 1 for the 868MHz band, _5 is filled first.                                                                                                                                       |
| 0x65        | RX_FIFO_0_868       | 0x00            | The FIFO byte 0 for the 868MHz band, _5 is filled first.                                                                                                                                       |
| 0x66        | RX_FIFO_5_2G4       | 0x00            | The FIFO byte 5 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
| 0x67        | RX_FIFO_4_2G4       | 0x00            | The FIFO byte 4 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
| 0x68        | RX_FIFO_3_2G4       | 0x00            | The FIFO byte 3 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
| 0x69        | RX_FIFO_2_2G4       | 0x00            | The FIFO byte 2 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
| 0x6A        | RX_FIFO_1_2G4       | 0x00            | The FIFO byte 1 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
| 0x6B        | RX_FIFO_0_2G4       | 0x00            | The FIFO byte 0 for the 2.4GHz band, _5 is filled first.                                                                                                                                       |
| 0x6C        | ACTUAL_NFA_433      | 0x25            | This register contains the actual NFA (sampling rate) value that is currently valid for 433MHz data reception.                                                                                 |
| 0x6D        | ACTUAL_NFA_868      | 0x15            | This register contains the actual NFA (sampling rate) value that is currently valid for 868MHz data reception.                                                                                 |
| 0x6E        | ACTUAL_NFA_2G4      | 0x25            | This register contains the actual NFA (sampling rate) value that is currently valid for 2.4GHz data reception.                                                                                 |
| 0x6F        | ACTUAL_BANDSELECT   | 0x07            | This 3 bit register contains the actual selected frequency bands that are currently used.                                                                                                      |
| 0x71        | GENPURP_1           | 0x00            | 8 bits free to use for read/write. (Register table says only write).                                                                                                                           |
| 0x73        | XTAL_OSC_CTRL       | 0x01            | Enables the built-in crystal oscillator driving a 2-pin crystal device.                                                                                                                        |
| 0x74        | LDO_XTAL_CTRL       | 0x03            | Controls the LDO and the crystal oscillator.                                                                                                                                                   |
| 0x75        | MUX_D_OUT_SEL       | 0x0F            | Selects the signal routed to the GPO1 and GPO2 pins.                                                                                                                                           |
| 0x76        | LC_TG_ENA           | 0x01            | Set to 0x00 during power-up.                                                                                                                                                                   |
| 0x77        | XTAL_GOOD           | 0x00            | Reads as true if the clock source is stable.                                                                                                                                                   |
| 0x78        | COMP_THRESH_W       | 0x00            | Set this register to 0xA before executing the comparator calibration.                                                                                                                          |
| 0x7C        | KORREL_SV_CLEAR     | 0x00            | Set true to clear the KORREL_STATE and KORREL_VAL registers.                                                                                                                                   |
| 0x7F        | VERSION             | 0x41            | Holds the version number of the IC, currently 0x41.                                                                                                                                            |

## Register Details

### NFA433_SLOW

#### Info:

  - Address: 0x00
  - Reset: 0x05

#### Register:

| **Bits:**   | 7:3 | 2:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | W    |

  - Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 433-MHz band.

#### Fields:

  - DATA [2:0]
   - [W]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.

### NFA433_FAST

#### Info:

  - Address: 0x01
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:3 | 2:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | W    |

  - Set the sample-rate for FDD-mode data reception in the 433-MHz band.

#### Fields:

  - DATA [2:0]
   - [W]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.

### NFA868_SLOW

#### Info:

  - Address: 0x02
  - Reset: 0x05

#### Register:

| **Bits:**   | 7:3 | 2:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | W    |

  - Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 868-MHz band.

#### Fields:

  - DATA [2:0]
   - [W]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.

### NFA868_FAST

#### Info:

  - Address: 0x03
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:3 | 2:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | W    |

  - Set the sample-rate for FDD-mode data reception in the 868-MHz band.

#### Fields:

  - DATA [2:0]
   - [W]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.

### NFA2G4_SLOW

#### Info:

  - Address: 0x04
  - Reset: 0x05

#### Register:

| **Bits:**   | 7:3 | 2:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | W    |

  - Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 2.4-GHz band.

#### Fields:

  - DATA [2:0]
   - [W]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.

### NFA2G4_FAST

#### Info:

  - Address: 0x05
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:3 | 2:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | W    |

  - Set the sample-rate for FDD-mode data reception in the 2.4-GHz band.

#### Fields:

  - DATA [2:0]
   - [W]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.

### CALIB_STATUS

#### Info:

  - Address: 0x06
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:4 | 3                  | 2               | 1               | 0           |
| ----------- | --- | ------------------ | --------------- | --------------- | ----------- |
| **Field:**  | /   | OFFSET_CAL_IN_PROG | SPG_CAL_IN_PROG | LCO_CAL_IN_PROG | CAL_IN_PROG |
| **Access:** | /   | R                  | R               | R               | R           |

  - Indicates status of all calibration processes.

#### Fields:

  - CAL_IN_PROG [0]
    - Indicates general calibration process in progress.
   - [R]
   - Type: bool
  - LCO_CAL_IN_PROG [1]
    - Indicates LCO calibration in progress.
   - [R]
   - Type: bool
  - SPG_CAL_IN_PROG [2]
    - Indicates SPG calibration in progress.
   - [R]
   - Type: bool
  - OFFSET_CAL_IN_PROG [3]
    - Indicates Offset calubration in progress.
   - [R]
   - Type: bool

### CALIB_CTRL

#### Info:

  - Address: 0x07
  - Reset: 0x0E

#### Register:

| **Bits:**   | 7:4 | 3          | 2       | 1       | 0         |
| ----------- | --- | ---------- | ------- | ------- | --------- |
| **Field:**  | /   | OFFSET_CAL | SPG_CAL | LCO_CAL | CAL_START |
| **Access:** | /   | R/W        | R/W     | R/W     | R/W       |

  - Control register for starting calibration processes.

#### Fields:

  - CAL_START [0]
    - Starts the calibration process.
   - [R/W]
   - Type: bool
  - LCO_CAL [1]
    - Control bit for initiating LCO calibration.
   - [R/W]
   - Type: bool
  - SPG_CAL [2]
    - Control bit for initiating SPG calibration.
   - [R/W]
   - Type: bool
  - OFFSET_CAL [3]
    - Control bit for initiating offset calibration.
   - [R/W]
   - Type: bool

### N_SPG_TARGET

#### Info:

  - Address: 0x09
  - Reset: 0x31

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Target register for the Signal Processing Gain setting. Set to 0x46 during SPG calibration.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### N_LCO_TARGET_433_HI

#### Info:

  - Address: 0x0B
  - Reset: 0x0E

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Sets the high byte (15:8) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891. (According to register table in DS v1.3b, only 12:8).

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### N_LCO_TARGET_433_LO

#### Info:

  - Address: 0x0C
  - Reset: 0x20

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Sets the low byte (7:0) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### N_LCO_TARGET_868_HI

#### Info:

  - Address: 0x0D
  - Reset: 0x0D

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Sets the high byte (15:8) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738. (According to register table in DS v1.3b, only 12:8).

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### N_LCO_TARGET_868_LO

#### Info:

  - Address: 0x0E
  - Reset: 0x87

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Sets the low byte (7:0) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### N_LCO_TARGET_2G4_HI

#### Info:

  - Address: 0x0F
  - Reset: 0x12

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Sets the high byte (15:8) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833. (According to register table in DS v1.3b, only 12:8).

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### N_LCO_TARGET_2G4_LO

#### Info:

  - Address: 0x10
  - Reset: 0xCE

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Sets the low byte (7:0) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### LCO_FREQ_433_HI

#### Info:

  - Address: 0x14
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Holds the current frequency of the 433-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### LCO_FREQ_433_LO

#### Info:

  - Address: 0x15
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Holds the current frequency of the 433-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### LCO_FREQ_868_HI

#### Info:

  - Address: 0x16
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Holds the current frequency of the 868/915-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### LCO_FREQ_868_LO

#### Info:

  - Address: 0x17
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Holds the current frequency of the 868/915-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### LCO_FREQ_2G4_HI

#### Info:

  - Address: 0x18
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Holds the current frequency of the 2.4-GHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### LCO_FREQ_2G4_LO

#### Info:

  - Address: 0x19
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Holds the current frequency of the 2.4-GHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### D_CORNER_CTRL

#### Info:

  - Address: 0x23
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Set to 0x02 at power-up.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### BAND_BRANCH_CTRL

#### Info:

  - Address: 0x24
  - Reset: 0x77

#### Register:

| **Bits:**   | 7 | 6:4          | 3 | 2:0             |
| ----------- | - | ------------ | - | --------------- |
| **Field:**  | / | ACTIVE_BANDS | / | ACTIVE_BRANCHES |
| **Access:** | / | W            | / | W               |

  - Selects the active bands and branches (RF-sensitivity).

#### Structured Fields:

 - [2:0]: ACTIVE_BRANCHES

| **Bits:**   | 2      | 1      | 0    |
| ----------- | ------ | ------ | ---- |
| **Field:**  | STRONG | MEDIUM | WEAK |
| **Access:** | /      | /      | /    |

 - [6:4]: ACTIVE_BANDS

| **Bits:**   | 2        | 1        | 0        |
| ----------- | -------- | -------- | -------- |
| **Field:**  | BAND_2G4 | BAND_868 | BAND_433 |
| **Access:** | /        | /        | /        |

#### Fields:

  - ACTIVE_BRANCHES [2:0]
    - Selects the active detection branches.
   - [W]
   - Type: struct BRANCHES
    - ACTIVE_BRANCHES.WEAK [0]
      - True means weak branch on.
     - Type: bool
    - ACTIVE_BRANCHES.MEDIUM [1]
      - True means medium branch on (+8dB of weak).
     - Type: bool
    - ACTIVE_BRANCHES.STRONG [2]
      - True means strong branch on (+16dB of weak).
     - Type: bool
  - ACTIVE_BANDS [6:4]
    - Selects the active bands.
   - [W]
   - Type: struct BANDS
    - ACTIVE_BANDS.BAND_433 [4]
      - True means on for 433MHz band.
     - Type: bool
    - ACTIVE_BANDS.BAND_868 [5]
      - True means on for 868/915MHz band.
     - Type: bool
    - ACTIVE_BANDS.BAND_2G4 [6]
      - True means on for 2.4GHz band.
     - Type: bool

### CODE_SELECT

#### Info:

  - Address: 0x28
  - Reset: 0x10

#### Register:

| **Bits:**   | 7:4 | 3:0 |
| ----------- | --- | --- |
| **Field:**  | B   | A   |
| **Access:** | W   | W   |

  - Selects the correlation patterns for code A and B.

#### Fields:

  - A [3:0]
    - Selects the correlation pattern for code A.
   - [W]
   - Type: enum BIN_CODE
     - 0x00: A
        - mls A
     - 0x04: A_inv
        - mls A inv
     - 0x06: A_seq
        - m-sequence A
     - 0x01: B
        - mls B
     - 0x05: B_inv
        - mls B inv
     - 0x07: B_seq
        - m-sequence B
     - 0x02: C
        - mls C
     - 0x03: D
        - mls D
     - 0x0A: ONE_16
        - 16 ones
     - 0x0B: ONE_24
        - 24 ones
     - 0x0C: ONE_31
        - 31 ones
     - 0x09: ONE_8
        - 8 ones
     - 0x0F: OOOZZZ
        - 111000 pattern
     - 0x0E: OOZZ
        - 1100 pattern
     - 0x08: ZERO_31
        - 31 zeros
     - 0x0D: ZOZO
        - 0101 pattern
  - B [7:4]
    - Selects the correlation pattern for code B.
   - [W]
   - Type: enum BIN_CODE
     - 0x00: A
        - mls A
     - 0x04: A_inv
        - mls A inv
     - 0x06: A_seq
        - m-sequence A
     - 0x01: B
        - mls B
     - 0x05: B_inv
        - mls B inv
     - 0x07: B_seq
        - m-sequence B
     - 0x02: C
        - mls C
     - 0x03: D
        - mls D
     - 0x0A: ONE_16
        - 16 ones
     - 0x0B: ONE_24
        - 24 ones
     - 0x0C: ONE_31
        - 31 ones
     - 0x09: ONE_8
        - 8 ones
     - 0x0F: OOOZZZ
        - 111000 pattern
     - 0x0E: OOZZ
        - 1100 pattern
     - 0x08: ZERO_31
        - 31 zeros
     - 0x0D: ZOZO
        - 0101 pattern

### KORREL_THRESH_A

#### Info:

  - Address: 0x29
  - Reset: 0x1A

#### Register:

| **Bits:**   | 7:5 | 4:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | R/W  |

  - Sets the threshold for a code A match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).

#### Fields:

  - DATA [4:0]
   - [R/W]
   - Type: uint

### KORREL_THRESH_B

#### Info:

  - Address: 0x2A
  - Reset: 0x1A

#### Register:

| **Bits:**   | 7:5 | 4:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | R/W  |

  - Sets the threshold for a code B match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).

#### Fields:

  - DATA [4:0]
   - [R/W]
   - Type: uint

### KORREL_STATE

#### Info:

  - Address: 0x2B
  - Reset: 0xC0

#### Register:

| **Bits:**   | 7:6                    | 5:3               | 2:0               |
| ----------- | ---------------------- | ----------------- | ----------------- |
| **Field:**  | KORREL_BRANCHES_LATEST | KORREL_BRANCHES_B | KORREL_BRANCHES_A |
| **Access:** | R                      | R                 | R                 |


#### Structured Fields:

 - [2:0]: KORREL_BRANCHES_A

| **Bits:**   | 2      | 1      | 0    |
| ----------- | ------ | ------ | ---- |
| **Field:**  | STRONG | MEDIUM | WEAK |
| **Access:** | /      | /      | /    |

 - [5:3]: KORREL_BRANCHES_B

| **Bits:**   | 2      | 1      | 0    |
| ----------- | ------ | ------ | ---- |
| **Field:**  | STRONG | MEDIUM | WEAK |
| **Access:** | /      | /      | /    |

#### Fields:

  - KORREL_BRANCHES_A [2:0]
    - Indicates receiver branch that had contributed for Code A recognition
   - [R]
   - Type: struct BRANCHES
    - KORREL_BRANCHES_A.WEAK [0]
      - True means weak branch on.
     - Type: bool
    - KORREL_BRANCHES_A.MEDIUM [1]
      - True means medium branch on (+8dB of weak).
     - Type: bool
    - KORREL_BRANCHES_A.STRONG [2]
      - True means strong branch on (+16dB of weak).
     - Type: bool
  - KORREL_BRANCHES_B [5:3]
    - Indicates receiver branch that had contributed for Code B recognition
   - [R]
   - Type: struct BRANCHES
    - KORREL_BRANCHES_B.WEAK [3]
      - True means weak branch on.
     - Type: bool
    - KORREL_BRANCHES_B.MEDIUM [4]
      - True means medium branch on (+8dB of weak).
     - Type: bool
    - KORREL_BRANCHES_B.STRONG [5]
      - True means strong branch on (+16dB of weak).
     - Type: bool
  - KORREL_BRANCHES_LATEST [7:6]
    - Indicates frequency band for latest correlator
   - [R]
   - Type: enum KORREL_BRANCHES_LATEST
     - 0x02: BAND_2G4
        - Band 2.4GHz matched.
     - 0x00: BAND_433
        - Band 433MHz matched.
     - 0x01: BAND_868
        - Band 868/915MHz matched.

### KORREL_VAL

#### Info:

  - Address: 0x2C
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:4 | 3:0 |
| ----------- | --- | --- |
| **Field:**  | B   | A   |
| **Access:** | R   | R   |

  - Indicates the match level for code A and B. A value of 15 indicates no bit errors, a value of 0 indicates 15 bit errors.

#### Fields:

  - A [3:0]
    - Indicates the match level for code A. Refreshed after a positive Code A match. Typically >5
   - [R]
   - Type: uint
  - B [7:4]
    - Indicates the match level for code B. Refreshed after a positive Code B match. Typically >5
   - [R]
   - Type: uint

### FDD_ENABLE

#### Info:

  - Address: 0x2D
  - Reset: 0x07

#### Register:

| **Bits:**   | 7:3 | 2:0       |
| ----------- | --- | --------- |
| **Field:**  | /   | FDD_BANDS |
| **Access:** | /   | W         |

  - Enable the fast data decoder for a given band.

#### Structured Fields:

 - [2:0]: FDD_BANDS

| **Bits:**   | 2        | 1        | 0        |
| ----------- | -------- | -------- | -------- |
| **Field:**  | BAND_2G4 | BAND_868 | BAND_433 |
| **Access:** | /        | /        | /        |

#### Fields:

  - FDD_BANDS [2:0]
   - [W]
   - Type: struct BANDS
    - FDD_BANDS.BAND_433 [0]
      - True means on for 433MHz band.
     - Type: bool
    - FDD_BANDS.BAND_868 [1]
      - True means on for 868/915MHz band.
     - Type: bool
    - FDD_BANDS.BAND_2G4 [2]
      - True means on for 2.4GHz band.
     - Type: bool

### FDD_ACTIVE

#### Info:

  - Address: 0x2E
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:3 | 2        | 1        | 0        |
| ----------- | --- | -------- | -------- | -------- |
| **Field:**  | /   | BAND_433 | BAND_868 | BAND_2G4 |
| **Access:** | /   | R        | R        | R        |

  - Reads the FDD mode for each band.

#### Fields:

  - BAND_2G4 [0]
   - [R]
   - Type: enum FDD_MODE
     - 0x01: FAST
        - Fast mode.
     - 0x00: SLOW
        - Slow mode.
  - BAND_868 [1]
   - [R]
   - Type: enum FDD_MODE
     - 0x01: FAST
        - Fast mode.
     - 0x00: SLOW
        - Slow mode.
  - BAND_433 [2]
   - [R]
   - Type: enum FDD_MODE
     - 0x01: FAST
        - Fast mode.
     - 0x00: SLOW
        - Slow mode.

### FO_QUIT

#### Info:

  - Address: 0x2F
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:3 | 2:0        |
| ----------- | --- | ---------- |
| **Field:**  | /   | QUIT_BANDS |
| **Access:** | /   | W          |

  - Forces the specified band to quit fast mode immediately.

#### Structured Fields:

 - [2:0]: QUIT_BANDS

| **Bits:**   | 2        | 1        | 0        |
| ----------- | -------- | -------- | -------- |
| **Field:**  | BAND_2G4 | BAND_868 | BAND_433 |
| **Access:** | /        | /        | /        |

#### Fields:

  - QUIT_BANDS [2:0]
   - [W]
   - Type: struct BANDS
    - QUIT_BANDS.BAND_433 [0]
      - True means on for 433MHz band.
     - Type: bool
    - QUIT_BANDS.BAND_868 [1]
      - True means on for 868/915MHz band.
     - Type: bool
    - QUIT_BANDS.BAND_2G4 [2]
      - True means on for 2.4GHz band.
     - Type: bool

### FDD_EXIT_COND

#### Info:

  - Address: 0x30
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:6 | 5:4      | 3:2      | 1:0      |
| ----------- | --- | -------- | -------- | -------- |
| **Field:**  | /   | BAND_2G4 | BAND_868 | BAND_433 |
| **Access:** | /   | R        | R        | R        |

  - Holds the FDD exit condition for all the bands.

#### Fields:

  - BAND_433 [1:0]
   - [R]
   - Type: enum EXIT_COND
     - 0x03: FORCE_QUIT
        - FO_QUIT was set - user forced slow mode.
     - 0x02: ID_FAIL
        - ID match failed - 16-bit ID did not match.
     - 0x00: NO_REASON
        - RX resetted or FDD is disabled - Initial state.
     - 0x01: TIMEOUT
        - Timeout - No fast code A or B received.
  - BAND_868 [3:2]
   - [R]
   - Type: enum EXIT_COND
     - 0x03: FORCE_QUIT
        - FO_QUIT was set - user forced slow mode.
     - 0x02: ID_FAIL
        - ID match failed - 16-bit ID did not match.
     - 0x00: NO_REASON
        - RX resetted or FDD is disabled - Initial state.
     - 0x01: TIMEOUT
        - Timeout - No fast code A or B received.
  - BAND_2G4 [5:4]
   - [R]
   - Type: enum EXIT_COND
     - 0x03: FORCE_QUIT
        - FO_QUIT was set - user forced slow mode.
     - 0x02: ID_FAIL
        - ID match failed - 16-bit ID did not match.
     - 0x00: NO_REASON
        - RX resetted or FDD is disabled - Initial state.
     - 0x01: TIMEOUT
        - Timeout - No fast code A or B received.

### IRQ_SELECT

#### Info:

  - Address: 0x31
  - Reset: 0x01

#### Register:

| **Bits:**   | 7:0        |
| ----------- | ---------- |
| **Field:**  | IRQ_SELECT |
| **Access:** | W          |

  - Selects the interrupt sources.

#### Structured Fields:

 - [7:0]: IRQ_SELECT

| **Bits:**   | 7                  | 6               | 5                | 4                      | 3            | 2         | 1             | 0        |
| ----------- | ------------------ | --------------- | ---------------- | ---------------------- | ------------ | --------- | ------------- | -------- |
| **Field:**  | CYCLIC_TIMER_ALARM | RTC_TIMER_ALARM | ID_MATCH_AND_LDR | ID_MATCH_AND_FIFO_FULL | CORREL_MATCH | FIFO_FULL | FIFO_OVERFLOW | ID_MATCH |
| **Access:** | /                  | /               | /                | /                      | /            | /         | /             | /        |

#### Fields:

  - IRQ_SELECT [7:0]
   - [W]
   - Type: struct IRQ_SOURCE
    - IRQ_SELECT.ID_MATCH [0]
      - The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
     - Type: bool
    - IRQ_SELECT.FIFO_OVERFLOW [1]
      - FIFO overflow.
     - Type: bool
    - IRQ_SELECT.FIFO_FULL [2]
      - FIFO buffer full.
     - Type: bool
    - IRQ_SELECT.CORREL_MATCH [3]
      - OOK data matches the correlation sequence.
     - Type: bool
    - IRQ_SELECT.ID_MATCH_AND_FIFO_FULL [4]
      - 16-bit ID in FDD mode matches and FIFO buffer full.
     - Type: bool
    - IRQ_SELECT.ID_MATCH_AND_LDR [5]
      - 16-bit ID in FDD mode matches and LDR was entered.
     - Type: bool
    - IRQ_SELECT.RTC_TIMER_ALARM [6]
      - RTC timer alarm.
     - Type: bool
    - IRQ_SELECT.CYCLIC_TIMER_ALARM [7]
      - Cyclic timer alarm.
     - Type: bool

### IRQ_STATUS

#### Info:

  - Address: 0x32
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0        |
| ----------- | ---------- |
| **Field:**  | IRQ_STATUS |
| **Access:** | R          |

  - Holds the status of the IRQ events.

#### Structured Fields:

 - [7:0]: IRQ_STATUS

| **Bits:**   | 7                  | 6               | 5                | 4                      | 3            | 2         | 1             | 0        |
| ----------- | ------------------ | --------------- | ---------------- | ---------------------- | ------------ | --------- | ------------- | -------- |
| **Field:**  | CYCLIC_TIMER_ALARM | RTC_TIMER_ALARM | ID_MATCH_AND_LDR | ID_MATCH_AND_FIFO_FULL | CORREL_MATCH | FIFO_FULL | FIFO_OVERFLOW | ID_MATCH |
| **Access:** | /                  | /               | /                | /                      | /            | /         | /             | /        |

#### Fields:

  - IRQ_STATUS [7:0]
   - [R]
   - Type: struct IRQ_SOURCE
    - IRQ_STATUS.ID_MATCH [0]
      - The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
     - Type: bool
    - IRQ_STATUS.FIFO_OVERFLOW [1]
      - FIFO overflow.
     - Type: bool
    - IRQ_STATUS.FIFO_FULL [2]
      - FIFO buffer full.
     - Type: bool
    - IRQ_STATUS.CORREL_MATCH [3]
      - OOK data matches the correlation sequence.
     - Type: bool
    - IRQ_STATUS.ID_MATCH_AND_FIFO_FULL [4]
      - 16-bit ID in FDD mode matches and FIFO buffer full.
     - Type: bool
    - IRQ_STATUS.ID_MATCH_AND_LDR [5]
      - 16-bit ID in FDD mode matches and LDR was entered.
     - Type: bool
    - IRQ_STATUS.RTC_TIMER_ALARM [6]
      - RTC timer alarm.
     - Type: bool
    - IRQ_STATUS.CYCLIC_TIMER_ALARM [7]
      - Cyclic timer alarm.
     - Type: bool

### IRQ_CLR

#### Info:

  - Address: 0x33
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0     |
| ----------- | ------- |
| **Field:**  | IRQ_CLR |
| **Access:** | W       |

  - Resets the corresponding IRQ event bit.

#### Structured Fields:

 - [7:0]: IRQ_CLR

| **Bits:**   | 7                  | 6               | 5                | 4                      | 3            | 2         | 1             | 0        |
| ----------- | ------------------ | --------------- | ---------------- | ---------------------- | ------------ | --------- | ------------- | -------- |
| **Field:**  | CYCLIC_TIMER_ALARM | RTC_TIMER_ALARM | ID_MATCH_AND_LDR | ID_MATCH_AND_FIFO_FULL | CORREL_MATCH | FIFO_FULL | FIFO_OVERFLOW | ID_MATCH |
| **Access:** | /                  | /               | /                | /                      | /            | /         | /             | /        |

#### Fields:

  - IRQ_CLR [7:0]
   - [W]
   - Type: struct IRQ_SOURCE
    - IRQ_CLR.ID_MATCH [0]
      - The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
     - Type: bool
    - IRQ_CLR.FIFO_OVERFLOW [1]
      - FIFO overflow.
     - Type: bool
    - IRQ_CLR.FIFO_FULL [2]
      - FIFO buffer full.
     - Type: bool
    - IRQ_CLR.CORREL_MATCH [3]
      - OOK data matches the correlation sequence.
     - Type: bool
    - IRQ_CLR.ID_MATCH_AND_FIFO_FULL [4]
      - 16-bit ID in FDD mode matches and FIFO buffer full.
     - Type: bool
    - IRQ_CLR.ID_MATCH_AND_LDR [5]
      - 16-bit ID in FDD mode matches and LDR was entered.
     - Type: bool
    - IRQ_CLR.RTC_TIMER_ALARM [6]
      - RTC timer alarm.
     - Type: bool
    - IRQ_CLR.CYCLIC_TIMER_ALARM [7]
      - Cyclic timer alarm.
     - Type: bool

### IRQ_SET

#### Info:

  - Address: 0x34
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0     |
| ----------- | ------- |
| **Field:**  | IRQ_SET |
| **Access:** | W       |

  - Sets the corresponding IRQ event bit (triggers IRQ events for debugging).

#### Structured Fields:

 - [7:0]: IRQ_SET

| **Bits:**   | 7                  | 6               | 5                | 4                      | 3            | 2         | 1             | 0        |
| ----------- | ------------------ | --------------- | ---------------- | ---------------------- | ------------ | --------- | ------------- | -------- |
| **Field:**  | CYCLIC_TIMER_ALARM | RTC_TIMER_ALARM | ID_MATCH_AND_LDR | ID_MATCH_AND_FIFO_FULL | CORREL_MATCH | FIFO_FULL | FIFO_OVERFLOW | ID_MATCH |
| **Access:** | /                  | /               | /                | /                      | /            | /         | /             | /        |

#### Fields:

  - IRQ_SET [7:0]
   - [W]
   - Type: struct IRQ_SOURCE
    - IRQ_SET.ID_MATCH [0]
      - The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
     - Type: bool
    - IRQ_SET.FIFO_OVERFLOW [1]
      - FIFO overflow.
     - Type: bool
    - IRQ_SET.FIFO_FULL [2]
      - FIFO buffer full.
     - Type: bool
    - IRQ_SET.CORREL_MATCH [3]
      - OOK data matches the correlation sequence.
     - Type: bool
    - IRQ_SET.ID_MATCH_AND_FIFO_FULL [4]
      - 16-bit ID in FDD mode matches and FIFO buffer full.
     - Type: bool
    - IRQ_SET.ID_MATCH_AND_LDR [5]
      - 16-bit ID in FDD mode matches and LDR was entered.
     - Type: bool
    - IRQ_SET.RTC_TIMER_ALARM [6]
      - RTC timer alarm.
     - Type: bool
    - IRQ_SET.CYCLIC_TIMER_ALARM [7]
      - Cyclic timer alarm.
     - Type: bool

### ID_HI

#### Info:

  - Address: 0x35
  - Reset: 0x7D

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Sets the high byte of the match ID. 4-MSB form the group ID.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### ID_LO

#### Info:

  - Address: 0x36
  - Reset: 0xA8

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Sets the low byte of the match ID.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### IDM_ENABLE

#### Info:

  - Address: 0x37
  - Reset: 0x07

#### Register:

| **Bits:**   | 7:3 | 2:0         |
| ----------- | --- | ----------- |
| **Field:**  | /   | MATCH_BANDS |
| **Access:** | /   | W           |

  - Enables the ID match for a given band.

#### Structured Fields:

 - [2:0]: MATCH_BANDS

| **Bits:**   | 2        | 1        | 0        |
| ----------- | -------- | -------- | -------- |
| **Field:**  | BAND_2G4 | BAND_868 | BAND_433 |
| **Access:** | /        | /        | /        |

#### Fields:

  - MATCH_BANDS [2:0]
   - [W]
   - Type: struct BANDS
    - MATCH_BANDS.BAND_433 [0]
      - True means on for 433MHz band.
     - Type: bool
    - MATCH_BANDS.BAND_868 [1]
      - True means on for 868/915MHz band.
     - Type: bool
    - MATCH_BANDS.BAND_2G4 [2]
      - True means on for 2.4GHz band.
     - Type: bool

### IDM_CTRL

#### Info:

  - Address: 0x38
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:2 | 1:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | CTRL |
| **Access:** | /   | W    |

  - Slect the type of ID's accepted by the receiver.

#### Fields:

  - CTRL [1:0]
   - [W]
   - Type: enum CTRL
     - 0x02: BROAD_ONLY
        - only broadcast ID.
     - 0x01: IND_GROUP
        - individual 16 bit ID or groupwise ID.
     - 0x03: IND_GROUP_BROAD
        - individual 16 bit ID, groupwise ID, or broadcast ID.
     - 0x00: IND_ONLY
        - only individual 16 bit ID.

### IDM_CLR

#### Info:

  - Address: 0x39
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:1 | 0      |
| ----------- | --- | ------ |
| **Field:**  | /   | BRANCH |
| **Access:** | /   | W      |

  - Clear the FDD_EXIT_COND register.

#### Fields:

  - BRANCH [0]
   - [W]
   - Type: bool

### IDM_BAND

#### Info:

  - Address: 0x3A
  - Reset: 0x03

#### Register:

| **Bits:**   | 7:2 | 1:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | R    |

  - Indicates the frequency band of the ID match event.

#### Fields:

  - DATA [1:0]
   - [R]
   - Type: enum DATA
     - 0x02: BAND_2G4
     - 0x00: BAND_433
     - 0x01: BAND_868

### IDM_REASON

#### Info:

  - Address: 0x3B
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:2 | 1:0    |
| ----------- | --- | ------ |
| **Field:**  | /   | REASON |
| **Access:** | /   | R      |

  - Indicates the type of ID match event.

#### Fields:

  - REASON [1:0]
   - [R]
   - Type: enum REASON
     - 0x03: BROAD_MATCH
        - Broadcast ID
     - 0x02: GROUP_MATCH
        - Group ID
     - 0x01: IND_MATCH
        - Individual ID
     - 0x00: UNKNOWN
        - Unspecified reason

### RTC_SELECT

#### Info:

  - Address: 0x3C
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:5 | 4       | 3:0        |
| ----------- | --- | ------- | ---------- |
| **Field:**  | /   | CYCLTOP | RTC_SELECT |
| **Access:** | /   | W       | W          |

  - Allows for selection of the desired timer modes.

#### Structured Fields:

 - [3:0]: RTC_SELECT

| **Bits:**   | 3      | 2      | 1      | 0      |
| ----------- | ------ | ------ | ------ | ------ |
| **Field:**  | RTCLG1 | RTCLG0 | RTCSH1 | RTCSH0 |
| **Access:** | /      | /      | /      | /      |

#### Fields:

  - RTC_SELECT [3:0]
   - [W]
   - Type: struct RTC
    - RTC_SELECT.RTCSH0 [0]
      - Selects the short RTC counter
     - Type: bool
    - RTC_SELECT.RTCSH1 [1]
      - Selects the short RTC counter
     - Type: bool
    - RTC_SELECT.RTCLG0 [2]
      - Selects the long RTC counter
     - Type: bool
    - RTC_SELECT.RTCLG1 [3]
      - Selects the long RTC counter
     - Type: bool
  - CYCLTOP [4]
    - Selects the cyclic counter (CYCLTOP).
   - [W]
   - Type: bool

### RTC_STATUS

#### Info:

  - Address: 0x3D
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:4 | 3:0        |
| ----------- | --- | ---------- |
| **Field:**  | /   | RTC_SELECT |
| **Access:** | /   | R          |

  - Indicates occurence of RTC events.

#### Structured Fields:

 - [3:0]: RTC_SELECT

| **Bits:**   | 3      | 2      | 1      | 0      |
| ----------- | ------ | ------ | ------ | ------ |
| **Field:**  | RTCLG1 | RTCLG0 | RTCSH1 | RTCSH0 |
| **Access:** | /      | /      | /      | /      |

#### Fields:

  - RTC_SELECT [3:0]
   - [R]
   - Type: struct RTC
    - RTC_SELECT.RTCSH0 [0]
      - Selects the short RTC counter
     - Type: bool
    - RTC_SELECT.RTCSH1 [1]
      - Selects the short RTC counter
     - Type: bool
    - RTC_SELECT.RTCLG0 [2]
      - Selects the long RTC counter
     - Type: bool
    - RTC_SELECT.RTCLG1 [3]
      - Selects the long RTC counter
     - Type: bool

### RTC_CLR

#### Info:

  - Address: 0x3E
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:4 | 3:0     |
| ----------- | --- | ------- |
| **Field:**  | /   | RTC_CLR |
| **Access:** | /   | W       |

  - Clears the respective event entries in RTC_STATUS.

#### Structured Fields:

 - [3:0]: RTC_CLR

| **Bits:**   | 3      | 2      | 1      | 0      |
| ----------- | ------ | ------ | ------ | ------ |
| **Field:**  | RTCLG1 | RTCLG0 | RTCSH1 | RTCSH0 |
| **Access:** | /      | /      | /      | /      |

#### Fields:

  - RTC_CLR [3:0]
   - [W]
   - Type: struct RTC
    - RTC_CLR.RTCSH0 [0]
      - Selects the short RTC counter
     - Type: bool
    - RTC_CLR.RTCSH1 [1]
      - Selects the short RTC counter
     - Type: bool
    - RTC_CLR.RTCLG0 [2]
      - Selects the long RTC counter
     - Type: bool
    - RTC_CLR.RTCLG1 [3]
      - Selects the long RTC counter
     - Type: bool

### RTCSH0_THRESH_HI

#### Info:

  - Address: 0x3F
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Upper (Bits 15:8) byte of the RTCSH0 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCSH0_THRESH_LO

#### Info:

  - Address: 0x40
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Lower (Bits 7:0) byte of the RTCSH0 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCSH1_THRESH_HI

#### Info:

  - Address: 0x41
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Upper (Bits 15:8) byte of the RTCSH1 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCSH1_THRESH_LO

#### Info:

  - Address: 0x42
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Lower (Bits 7:0) byte of the RTCSH1 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG0_THRESH_4

#### Info:

  - Address: 0x43
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 39:32 of the RTCLG0 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG0_THRESH_3

#### Info:

  - Address: 0x44
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 31:24 of the RTCLG0 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG0_THRESH_2

#### Info:

  - Address: 0x45
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 23:16 of the RTCLG0 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG0_THRESH_1

#### Info:

  - Address: 0x46
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 15:8 of the RTCLG0 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG0_THRESH_0

#### Info:

  - Address: 0x47
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 7:0 of the RTCLG0 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG1_THRESH_4

#### Info:

  - Address: 0x48
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 39:32 of the RTCLG1 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG1_THRESH_3

#### Info:

  - Address: 0x49
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 31:24 of the RTCLG1 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG1_THRESH_2

#### Info:

  - Address: 0x4A
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 23:16 of the RTCLG1 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG1_THRESH_1

#### Info:

  - Address: 0x4B
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 15:8 of the RTCLG1 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### RTCLG1_THRESH_0

#### Info:

  - Address: 0x4C
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 7:0 of the RTCLG1 threshold.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### CYCLPRESC

#### Info:

  - Address: 0x4D
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Cycle prescaler for cyclic counter, system clock divided by prescaler (therefore max 8:29.9922 minutes).

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### CYCLTOP_HI

#### Info:

  - Address: 0x4E
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 15:8 defining the maximal cyclic counter value CYCLTOP before being reset to zero.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### CYCLTOP_LO

#### Info:

  - Address: 0x4F
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Bits 7:0 defining the maximal cyclic counter value CYCLTOP before being reset to zero.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### CNTR40_4

#### Info:

  - Address: 0x50
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Bits 39:32 of the system clock counter CNTR40.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### CNTR40_3

#### Info:

  - Address: 0x51
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Bits 31:24 of the system clock counter CNTR40.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### CNTR40_2

#### Info:

  - Address: 0x52
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Bits 23:16 of the system clock counter CNTR40.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### CNTR40_1

#### Info:

  - Address: 0x53
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Bits 15:8 of the system clock counter CNTR40.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### CNTR40_0

#### Info:

  - Address: 0x54
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - Bits 7:0 of the system clock counter CNTR40.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### CNTR40_CLR

#### Info:

  - Address: 0x55
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:1 | 0   |
| ----------- | --- | --- |
| **Field:**  | /   | CLR |
| **Access:** | /   | W   |

  - Clear the system clock counter CNTR40 by setting this to true. Manually setting the register to false afterwards is mandatory!

#### Fields:

  - CLR [0]
   - [W]
   - Type: bool

### FIFO_LENGTH

#### Info:

  - Address: 0x56
  - Reset: 0x14

#### Register:

| **Bits:**   | 7:6 | 5:4      | 3:2      | 1:0      |
| ----------- | --- | -------- | -------- | -------- |
| **Field:**  | /   | BAND_2G4 | BAND_868 | BAND_433 |
| **Access:** | /   | W        | W        | W        |

  - Selects the FIFO length for each band.

#### Fields:

  - BAND_433 [1:0]
   - [W]
   - Type: enum FIFO_LEN
     - 0x00: BIT16
        - 16-bit FIFO.
     - 0x01: BIT24
        - 24-bit FIFO.
     - 0x02: BIT32
        - 32-bit FIFO.
     - 0x03: BIT40
        - 40-bit FIFO.
  - BAND_868 [3:2]
   - [W]
   - Type: enum FIFO_LEN
     - 0x00: BIT16
        - 16-bit FIFO.
     - 0x01: BIT24
        - 24-bit FIFO.
     - 0x02: BIT32
        - 32-bit FIFO.
     - 0x03: BIT40
        - 40-bit FIFO.
  - BAND_2G4 [5:4]
   - [W]
   - Type: enum FIFO_LEN
     - 0x00: BIT16
        - 16-bit FIFO.
     - 0x01: BIT24
        - 24-bit FIFO.
     - 0x02: BIT32
        - 32-bit FIFO.
     - 0x03: BIT40
        - 40-bit FIFO.

### FIFO_COUNT_433

#### Info:

  - Address: 0x57
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:6 | 5:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | R/W  |

  - Number of bits in the FIFO buffer for the 433MHz band. Can be cleared by writing 0.

#### Fields:

  - DATA [5:0]
   - [R/W]
   - Type: uint

### FIFO_COUNT_868

#### Info:

  - Address: 0x58
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:6 | 5:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | R/W  |

  - Number of bits in the FIFO buffer for the 868/915MHz band. Can be cleared by writing 0.

#### Fields:

  - DATA [5:0]
   - [R/W]
   - Type: uint

### FIFO_COUNT_2G4

#### Info:

  - Address: 0x59
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:6 | 5:0  |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | R/W  |

  - Number of bits in the FIFO buffer for the 2.4GHz band. Can be cleared by writing 0.

#### Fields:

  - DATA [5:0]
   - [R/W]
   - Type: uint

### RX_FIFO_5_433

#### Info:

  - Address: 0x5A
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 5 for the 433MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_4_433

#### Info:

  - Address: 0x5B
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 4 for the 433MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_3_433

#### Info:

  - Address: 0x5C
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 3 for the 433MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_2_433

#### Info:

  - Address: 0x5D
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 2 for the 433MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_1_433

#### Info:

  - Address: 0x5E
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 1 for the 433MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_0_433

#### Info:

  - Address: 0x5F
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 0 for the 433MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_5_868

#### Info:

  - Address: 0x60
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 5 for the 868MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_4_868

#### Info:

  - Address: 0x61
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 4 for the 868MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_3_868

#### Info:

  - Address: 0x62
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 3 for the 868MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_2_868

#### Info:

  - Address: 0x63
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 2 for the 868MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_1_868

#### Info:

  - Address: 0x64
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 1 for the 868MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_0_868

#### Info:

  - Address: 0x65
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 0 for the 868MHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_5_2G4

#### Info:

  - Address: 0x66
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 5 for the 2.4GHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_4_2G4

#### Info:

  - Address: 0x67
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 4 for the 2.4GHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_3_2G4

#### Info:

  - Address: 0x68
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 3 for the 2.4GHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_2_2G4

#### Info:

  - Address: 0x69
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 2 for the 2.4GHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_1_2G4

#### Info:

  - Address: 0x6A
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 1 for the 2.4GHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### RX_FIFO_0_2G4

#### Info:

  - Address: 0x6B
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R    |

  - The FIFO byte 0 for the 2.4GHz band, _5 is filled first.

#### Fields:

  - DATA [7:0]
   - [R]
   - Type: uint

### ACTUAL_NFA_433

#### Info:

  - Address: 0x6C
  - Reset: 0x25

#### Register:

| **Bits:**   | 7 | 6:4  | 3 | 2:0  |
| ----------- | - | ---- | - | ---- |
| **Field:**  | / | FAST | / | SLOW |
| **Access:** | / | R    | / | R    |

  - This register contains the actual NFA (sampling rate) value that is currently valid for 433MHz data reception.

#### Fields:

  - SLOW [2:0]
   - [R]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.
  - FAST [6:4]
   - [R]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.

### ACTUAL_NFA_868

#### Info:

  - Address: 0x6D
  - Reset: 0x15

#### Register:

| **Bits:**   | 7 | 6:4  | 3 | 2:0  |
| ----------- | - | ---- | - | ---- |
| **Field:**  | / | FAST | / | SLOW |
| **Access:** | / | R    | / | R    |

  - This register contains the actual NFA (sampling rate) value that is currently valid for 868MHz data reception.

#### Fields:

  - SLOW [2:0]
   - [R]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.
  - FAST [6:4]
   - [R]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.

### ACTUAL_NFA_2G4

#### Info:

  - Address: 0x6E
  - Reset: 0x25

#### Register:

| **Bits:**   | 7 | 6:4  | 3 | 2:0  |
| ----------- | - | ---- | - | ---- |
| **Field:**  | / | FAST | / | SLOW |
| **Access:** | / | R    | / | R    |

  - This register contains the actual NFA (sampling rate) value that is currently valid for 2.4GHz data reception.

#### Fields:

  - SLOW [2:0]
   - [R]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.
  - FAST [6:4]
   - [R]
   - Type: enum SAMPLE_RATE
     - 0x07: SR_0_256
        - 256 Hz. 125ms code-sequence-duration.
     - 0x06: SR_0_512
        - 512 Hz. 62.5ms code-sequence-duration.
     - 0x01: SR_16_384
        - 16384 Hz. 1.957ms code-sequence-duration.
     - 0x05: SR_1_024
        - 1024 Hz. 31.25ms code-sequence-duration.
     - 0x04: SR_2_048
        - 2048 Hz. 15.625ms code-sequence-duration.
     - 0x00: SR_32_768
        - 32768 Hz. 0.977ms code-sequence-duration.
     - 0x03: SR_4_096
        - 4096 Hz. 7.813ms code-sequence-duration.
     - 0x02: SR_8_192
        - 32768 Hz. 0.977ms code-sequence-duration.

### ACTUAL_BANDSELECT

#### Info:

  - Address: 0x6F
  - Reset: 0x07

#### Register:

| **Bits:**   | 7:3 | 2:0            |
| ----------- | --- | -------------- |
| **Field:**  | /   | SELECTED_BANDS |
| **Access:** | /   | R              |

  - This 3 bit register contains the actual selected frequency bands that are currently used.

#### Structured Fields:

 - [2:0]: SELECTED_BANDS

| **Bits:**   | 2        | 1        | 0        |
| ----------- | -------- | -------- | -------- |
| **Field:**  | BAND_2G4 | BAND_868 | BAND_433 |
| **Access:** | /        | /        | /        |

#### Fields:

  - SELECTED_BANDS [2:0]
   - [R]
   - Type: struct BANDS
    - SELECTED_BANDS.BAND_433 [0]
      - True means on for 433MHz band.
     - Type: bool
    - SELECTED_BANDS.BAND_868 [1]
      - True means on for 868/915MHz band.
     - Type: bool
    - SELECTED_BANDS.BAND_2G4 [2]
      - True means on for 2.4GHz band.
     - Type: bool

### GENPURP_1

#### Info:

  - Address: 0x71
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | R/W  |

  - 8 bits free to use for read/write. (Register table says only write).

#### Fields:

  - DATA [7:0]
   - [R/W]
   - Type: uint

### XTAL_OSC_CTRL

#### Info:

  - Address: 0x73
  - Reset: 0x01

#### Register:

| **Bits:**   | 7:1 | 0    |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | W    |

  - Enables the built-in crystal oscillator driving a 2-pin crystal device.

#### Fields:

  - DATA [0]
   - [W]
   - Type: bool

### LDO_XTAL_CTRL

#### Info:

  - Address: 0x74
  - Reset: 0x03

#### Register:

| **Bits:**   | 7:6 | 5           | 4 | 3            | 2 | 1:0 |
| ----------- | --- | ----------- | - | ------------ | - | --- |
| **Field:**  | /   | LDO_ENA_NFA | / | XTAL_OSC_BYP | / | INT |
| **Access:** | /   | W           | / | W            | / | W   |

  - Controls the LDO and the crystal oscillator.

#### Fields:

  - INT [1:0]
    - RESERVED. Do not change. Write 0x3
   - [W]
   - Type: fixed 0x03
  - XTAL_OSC_BYP [3]
    - Used for selecting an external system clock source that is applied to pin CLK32_XI. In this case, XTAL_OSC_BYP should be true. Set this, if a 2-pin crystal will not be used.
   - [W]
   - Type: bool
  - LDO_ENA_NFA [5]
    - sed to deactivate the internal LDO for VDDC voltage generation. If set to true, an external VDDC source must be supplied.
   - [W]
   - Type: bool

### MUX_D_OUT_SEL

#### Info:

  - Address: 0x75
  - Reset: 0x0F

#### Register:

| **Bits:**   | 7:4 | 3:0 |
| ----------- | --- | --- |
| **Field:**  | /   | OUT |
| **Access:** | /   | W   |

  - Selects the signal routed to the GPO1 and GPO2 pins.

#### Fields:

  - OUT [3:0]
   - [W]
   - Type: enum OUT
     - 0x0E: CLK32_IRQ_EVENT
        - System Clock CLK32 on GPO1 and interrupt signal IRQ_EVENT on GPO2.
     - 0x06: IDM_WUP_A_433
        - General ID match on GPO1 and 433MHz Wake-up A signal WUP_A on GPO2.
     - 0x0F: IRQ_EVENT_1
        - Interrupt signal IRQ_EVENT on GPO1 and static high on GPO2.
     - 0x00: RX_2G4
        - RX data stream at 2.4GHz. CLK on GPO1 and DATA on GPO2.
     - 0x02: RX_433
        - RX data stream at 433MHz. CLK on GPO1 and DATA on GPO2.
     - 0x01: RX_868
        - RX data stream at 868MHz. CLK on GPO1 and DATA on GPO2.
     - 0x0A: WUP_A_2G4_RX_ACTIVE
        - 2.4GHz Wake-up A signal WUP_A on GPO1 and RX_ACTIVE trigger signal on GPO2.
     - 0x08: WUP_A_433_RX_ACTIVE
        - 433MHz Wake-up A signal WUP_A on GPO1 and RX_ACTIVE trigger signal on GPO2.
     - 0x09: WUP_A_868_RX_ACTIVE
        - 868MHz Wake-up A signal WUP_A on GPO1 and RX_ACTIVE trigger signal on GPO2.
     - 0x03: WUP_A_B_2G4
        - Wake-up A/B signals at 2.4GHz. WUP_A on GPO1 and WUP_B on GPO2.
     - 0x07: WUP_A_B_868
        - Wake-up A/B signals at 868MHz. WUP_A on GPO1 and WUP_B on GPO2.

### LC_TG_ENA

#### Info:

  - Address: 0x76
  - Reset: 0x01

#### Register:

| **Bits:**   | 7:1 | 0    |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | W    |

  - Set to 0x00 during power-up.

#### Fields:

  - DATA [0]
   - [W]
   - Type: bool

### XTAL_GOOD

#### Info:

  - Address: 0x77
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:1 | 0    |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | R    |

  - Reads as true if the clock source is stable.

#### Fields:

  - DATA [0]
   - [R]
   - Type: bool

### COMP_THRESH_W

#### Info:

  - Address: 0x78
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:0  |
| ----------- | ---- |
| **Field:**  | DATA |
| **Access:** | W    |

  - Set this register to 0xA before executing the comparator calibration.

#### Fields:

  - DATA [7:0]
   - [W]
   - Type: uint

### KORREL_SV_CLEAR

#### Info:

  - Address: 0x7C
  - Reset: 0x00

#### Register:

| **Bits:**   | 7:1 | 0    |
| ----------- | --- | ---- |
| **Field:**  | /   | DATA |
| **Access:** | /   | W    |

  - Set true to clear the KORREL_STATE and KORREL_VAL registers.

#### Fields:

  - DATA [0]
   - [W]
   - Type: bool

### VERSION

#### Info:

  - Address: 0x7F
  - Reset: 0x41

#### Register:

| **Bits:**   | 7:0            |
| ----------- | -------------- |
| **Field:**  | VERSION_NUMBER |
| **Access:** | R              |

  - Holds the version number of the IC, currently 0x41.

#### Fields:

  - VERSION_NUMBER [7:0]
   - [R]
   - Type: fixed 0x41
