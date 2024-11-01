/**
 * @file fh101rf.c
 * @brief FH101RF Driver
 *
 * Listing file author: Silvano Cortesi
 *
 * Listing file notice:
 *   Licensed under TBD
 */

#include "fh101rf.h"
#include "fh101rf_reg.h"
#include <stdint.h>
#include <string.h>

// ======== Macro Quick Access
// =================================================================

#define DRVR_LOG(msg)                                                          \
  if (h != 0 && h->log != 0) {                                                 \
    h->log(msg, false, false, 0);                                              \
  }

#define DRVR_LOG_VAR(msg, val)                                                 \
  if (h != 0 && h->log != 0) {                                                 \
    h->log(msg, false, true, val);                                             \
  }

#define DRVR_ERR(msg)                                                          \
  if (h != 0 && h->log != 0) {                                                 \
    h->log(msg, true, false, 0);                                               \
  }

#define DRVR_ERR_VAR(msg, val)                                                 \
  if (h != 0 && h->log != 0) {                                                 \
    h->log(msg, true, true, val);                                              \
  }

// ======== Private Prototypes (not shared)
// =================================================================
static fh101rf_err_t check_connection(const struct fh101rf_h *h);
static fh101rf_err_t validate_handle(const struct fh101rf_h *h);

fh101rf_err_t write_all_regs(const struct fh101rf_h *h);

fh101rf_err_t comp_calibrate(struct fh101rf_h *h);
fh101rf_err_t lco_calibrate(struct fh101rf_h *h);
fh101rf_err_t sample_pulse_calibrate(struct fh101rf_h *h);

// ======== Public Functions
// =================================================================
fh101rf_err_t
fh101rf_init_struct_with_reset_val(struct fh101rf_reg_config *conf) {
  // Check that pointer is none zero
  fh101rf_err_t err = E_FH101RF_SUCCESS;
  if (conf == 0) {
    return E_FH101RF_NULLPTR_ERR;
  }
  // Fill default configuration into struct
  fh101rf_reset_val_le(conf);

  return err;
}

fh101rf_err_t fh101rf_init(struct fh101rf_h *h) {
  fh101rf_err_t err = E_FH101RF_SUCCESS;

  // Check if handles are valid
  err |= validate_handle(h);
  if (err)
    return err;

  // Check if connections are valid
  err |= check_connection(h);
  if (err)
    return err;

  // Check whether XTAL_GOOD == 1
  {
    uint8_t result = 0;
    err |= fh101rf_read_reg(h, FH101RF_XTAL_GOOD_ADDRESS, &result);
    if (err) {
      DRVR_ERR("Failed to readout XTAL_GOOD");
      return err;
    }
  }

  // Set D_CORNER_CTRL to 0x02
  {
    h->conf.d_corner_ctrl.data = 0x02;
    uint8_t data = 0;
    fh101rf_d_corner_ctrl_pack_le(&h->conf.d_corner_ctrl, &data);
    err |= fh101rf_write_reg(h, FH101RF_D_CORNER_CTRL_ADDRESS, data);
    if (err) {
      DRVR_ERR("Failed to set D_CORNER_CTRL to 0x02");
      return err;
    }
  }

  // Set LC_TG_ENA to 0x00
  {
    h->conf.lc_tg_ena.data = 0x00;
    uint8_t data = 0;
    fh101rf_lc_tg_ena_pack_le(&h->conf.lc_tg_ena, &data);
    err |= fh101rf_write_reg(h, FH101RF_LC_TG_ENA_ADDRESS, data);
    if (err) {
      DRVR_ERR("Failed to set LC_TG_ENA to 0x00");
      return err;
    }
  }

  // Perform calibration
  err |= fh101rf_calibrate(h);
  if (err) {
    DRVR_ERR("Failed to calibrate FH101RF");
    return err;
  }

  // Set default configuration to device
  err |= write_all_regs(h);
  if (err) {
    DRVR_ERR("Failed to write all registers");
  }

  return err;
}

fh101rf_err_t fh101rf_write_reg(const struct fh101rf_h *h, uint8_t reg_adr,
                                uint8_t val) {
  reg_adr &= 0x7F;

  fh101rf_err_t err = E_FH101RF_SUCCESS;
  err |= h->spi_write(&reg_adr, 1);
  err |= h->spi_write(&val, 1);

  return err;
}

fh101rf_err_t fh101rf_read_reg(const struct fh101rf_h *h, uint8_t reg_adr,
                               uint8_t *res) {
  reg_adr |= 0x80;

  fh101rf_err_t err = E_FH101RF_SUCCESS;
  err |= h->spi_write(&reg_adr, 1);
  err |= h->spi_read(res, 1);

  return err;
}

fh101rf_err_t fh101rf_calibrate(struct fh101rf_h *h) {
  fh101rf_err_t err = E_FH101RF_SUCCESS;
  // Calibrate LCO frequency
  err |= lco_calibrate(h);
  if (err) {
    DRVR_ERR("LCO Calibration failed");
    return err;
  }

  // Calibrate LCO frequency
  err |= sample_pulse_calibrate(h);
  if (err) {
    DRVR_ERR("Sample Pulse Calibration failed");
    return err;
  }

  // Calibrate LCO frequency
  err |= comp_calibrate(h);
  if (err) {
    DRVR_ERR("Comparator Calibration failed");
    return err;
  }

  return err;
}

// ======== Private Functions
// =================================================================

fh101rf_err_t write_all_regs(const struct fh101rf_h *h) {
  fh101rf_err_t err = E_FH101RF_SUCCESS;

  // Write NFA433_SLOW
  {
    uint8_t val = 0;
    fh101rf_nfa433_slow_pack_le(&h->conf.nfa433_slow, &val);
    err |= fh101rf_write_reg(h, FH101RF_NFA433_SLOW_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set NFA433_SLOW");
      return err;
    }
  }

  // Write NFA433_FAST
  {
    uint8_t val = 0;
    fh101rf_nfa433_fast_pack_le(&h->conf.nfa433_fast, &val);
    err |= fh101rf_write_reg(h, FH101RF_NFA433_FAST_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set NFA433_FAST");
      return err;
    }
  }

  // Write NFA868_SLOW
  {
    uint8_t val = 0;
    fh101rf_nfa868_slow_pack_le(&h->conf.nfa868_slow, &val);
    err |= fh101rf_write_reg(h, FH101RF_NFA868_SLOW_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set NFA868_SLOW");
      return err;
    }
  }

  // Write NFA868_FAST
  {
    uint8_t val = 0;
    fh101rf_nfa868_fast_pack_le(&h->conf.nfa868_fast, &val);
    err |= fh101rf_write_reg(h, FH101RF_NFA868_FAST_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set NFA868_FAST");
      return err;
    }
  }

  // Write NFA2G4_SLOW
  {
    uint8_t val = 0;
    fh101rf_nfa2g4_slow_pack_le(&h->conf.nfa2g4_slow, &val);
    err |= fh101rf_write_reg(h, FH101RF_NFA2G4_SLOW_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set NFA2G4_SLOW");
      return err;
    }
  }

  // Write NFA2G4_FAST
  {
    uint8_t val = 0;
    fh101rf_nfa2g4_fast_pack_le(&h->conf.nfa2g4_fast, &val);
    err |= fh101rf_write_reg(h, FH101RF_NFA2G4_FAST_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set NFA2G4_FAST");
      return err;
    }
  }

  // Write N_LCO_TARGET_433_HI
  {
    uint8_t val = 0;
    fh101rf_n_lco_target_433_hi_pack_le(&h->conf.n_lco_target_433_hi, &val);
    err |= fh101rf_write_reg(h, FH101RF_N_LCO_TARGET_433_HI_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set N_LCO_TARGET_433_HI");
      return err;
    }
  }

  // Write N_LCO_TARGET_433_LO
  {
    uint8_t val = 0;
    fh101rf_n_lco_target_433_lo_pack_le(&h->conf.n_lco_target_433_lo, &val);
    err |= fh101rf_write_reg(h, FH101RF_N_LCO_TARGET_433_LO_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set N_LCO_TARGET_433_LO");
      return err;
    }
  }

  // Write N_LCO_TARGET_868_HI
  {
    uint8_t val = 0;
    fh101rf_n_lco_target_868_hi_pack_le(&h->conf.n_lco_target_868_hi, &val);
    err |= fh101rf_write_reg(h, FH101RF_N_LCO_TARGET_868_HI_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set N_LCO_TARGET_868_HI");
      return err;
    }
  }

  // Write N_LCO_TARGET_868_LO
  {
    uint8_t val = 0;
    fh101rf_n_lco_target_868_lo_pack_le(&h->conf.n_lco_target_868_lo, &val);
    err |= fh101rf_write_reg(h, FH101RF_N_LCO_TARGET_868_LO_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set N_LCO_TARGET_868_LO");
      return err;
    }
  }

  // Write N_LCO_TARGET_2G4_HI
  {
    uint8_t val = 0;
    fh101rf_n_lco_target_2g4_hi_pack_le(&h->conf.n_lco_target_2g4_hi, &val);
    err |= fh101rf_write_reg(h, FH101RF_N_LCO_TARGET_2G4_HI_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set N_LCO_TARGET_2G4_HI");
      return err;
    }
  }

  // Write N_LCO_TARGET_2G4_LO
  {
    uint8_t val = 0;
    fh101rf_n_lco_target_2g4_lo_pack_le(&h->conf.n_lco_target_2g4_lo, &val);
    err |= fh101rf_write_reg(h, FH101RF_N_LCO_TARGET_2G4_LO_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set N_LCO_TARGET_2G4_LO");
      return err;
    }
  }

  // Write BAND_BRANCH_CTRL
  {
    uint8_t val = 0;
    fh101rf_band_branch_ctrl_pack_le(&h->conf.band_branch_ctrl, &val);
    err |= fh101rf_write_reg(h, FH101RF_BAND_BRANCH_CTRL_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set BAND_BRANCH_CTRL");
      return err;
    }
  }

  // Write CODE_SELECT
  {
    uint8_t val = 0;
    fh101rf_code_select_pack_le(&h->conf.code_select, &val);
    err |= fh101rf_write_reg(h, FH101RF_CODE_SELECT_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set CODE_SELECT");
      return err;
    }
  }

  // Write KORREL_THRESH_A
  {
    uint8_t val = 0;
    fh101rf_korrel_thresh_a_pack_le(&h->conf.korrel_thresh_a, &val);
    err |= fh101rf_write_reg(h, FH101RF_KORREL_THRESH_A_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set KORREL_THRESH_A");
      return err;
    }
  }

  // Write KORREL_THRESH_B
  {
    uint8_t val = 0;
    fh101rf_korrel_thresh_b_pack_le(&h->conf.korrel_thresh_b, &val);
    err |= fh101rf_write_reg(h, FH101RF_KORREL_THRESH_B_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set KORREL_THRESH_B");
      return err;
    }
  }

  // Write FDD_ENABLE
  {
    uint8_t val = 0;
    fh101rf_fdd_enable_pack_le(&h->conf.fdd_enable, &val);
    err |= fh101rf_write_reg(h, FH101RF_FDD_ENABLE_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set FDD_ENABLE");
      return err;
    }
  }

  // Write IRQ_SELECT
  {
    uint8_t val = 0;
    fh101rf_irq_select_pack_le(&h->conf.irq_select, &val);
    err |= fh101rf_write_reg(h, FH101RF_IRQ_SELECT_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set IRQ_SELECT");
      return err;
    }
  }

  // Write IRQ_CLR (clearing all registers)
  {
    uint8_t val = 0;
    struct fh101rf_irq_clr temp = {.irq_clr = {.correl_match = true,
                                               .cyclic_timer_alarm = true,
                                               .fifo_full = true,
                                               .fifo_overflow = true,
                                               .id_match = true,
                                               .id_match_and_fifo_full = true,
                                               .id_match_and_ldr = true,
                                               .rtc_timer_alarm = true}};
    fh101rf_irq_clr_pack_le(&temp, &val);
    err |= fh101rf_write_reg(h, FH101RF_IRQ_CLR_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set IRQ_CLR");
      return err;
    }
  }

  // Write ID_HI
  {
    uint8_t val = 0;
    fh101rf_id_hi_pack_le(&h->conf.id_hi, &val);
    err |= fh101rf_write_reg(h, FH101RF_ID_HI_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set ID_HI");
      return err;
    }
  }

  // Write ID_LO
  {
    uint8_t val = 0;
    fh101rf_id_lo_pack_le(&h->conf.id_lo, &val);
    err |= fh101rf_write_reg(h, FH101RF_ID_LO_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set ID_LO");
      return err;
    }
  }

  // Write IDM_ENABLE
  {
    uint8_t val = 0;
    fh101rf_idm_enable_pack_le(&h->conf.idm_enable, &val);
    err |= fh101rf_write_reg(h, FH101RF_IDM_ENABLE_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set IDM_ENABLE");
      return err;
    }
  }

  // Write IDM_CTRL
  {
    uint8_t val = 0;
    fh101rf_idm_ctrl_pack_le(&h->conf.idm_ctrl, &val);
    err |= fh101rf_write_reg(h, FH101RF_IDM_CTRL_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set IDM_CTRL");
      return err;
    }
  }

  // Write IDM_CLR (clearing all matches)
  {
    uint8_t val = 0;
    struct fh101rf_idm_clr temp = {.branch = true};
    fh101rf_idm_clr_pack_le(&temp, &val);
    err |= fh101rf_write_reg(h, FH101RF_IDM_CLR_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set IDM_CLR");
      return err;
    }
  }

  // Write RTC_SELECT
  {
    uint8_t val = 0;
    fh101rf_rtc_select_pack_le(&h->conf.rtc_select, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTC_SELECT_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTC_SELECT");
      return err;
    }
  }

  // Write RTC_CLR (clearing all event entries)
  {
    uint8_t val = 0;
    struct fh101rf_rtc_clr temp = {.rtc_clr = {
                                       .rtclg0 = true,
                                       .rtclg1 = true,
                                       .rtcsh0 = true,
                                       .rtcsh1 = true,
                                   }};
    fh101rf_rtc_clr_pack_le(&temp, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTC_CLR_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTC_CLR");
      return err;
    }
  }

  // Write RTCSH0_THRESH_HI
  {
    uint8_t val = 0;
    fh101rf_rtcsh0_thresh_hi_pack_le(&h->conf.rtcsh0_thresh_hi, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCSH0_THRESH_HI_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCSH0_THRESH_HI");
      return err;
    }
  }

  // Write RTCSH0_THRESH_LO
  {
    uint8_t val = 0;
    fh101rf_rtcsh0_thresh_lo_pack_le(&h->conf.rtcsh0_thresh_lo, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCSH0_THRESH_LO_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCSH0_THRESH_LO");
      return err;
    }
  }

  // Write RTCSH1_THRESH_HI
  {
    uint8_t val = 0;
    fh101rf_rtcsh1_thresh_hi_pack_le(&h->conf.rtcsh1_thresh_hi, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCSH1_THRESH_HI_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCSH1_THRESH_HI");
      return err;
    }
  }

  // Write RTCSH1_THRESH_LO
  {
    uint8_t val = 0;
    fh101rf_rtcsh1_thresh_lo_pack_le(&h->conf.rtcsh1_thresh_lo, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCSH1_THRESH_LO_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCSH1_THRESH_LO");
      return err;
    }
  }

  // Write RTCLG0_THRESH_4
  {
    uint8_t val = 0;
    fh101rf_rtclg0_thresh_4_pack_le(&h->conf.rtclg0_thresh_4, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG0_THRESH_4_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG0_THRESH_4");
      return err;
    }
  }

  // Write RTCLG0_THRESH_3
  {
    uint8_t val = 0;
    fh101rf_rtclg0_thresh_3_pack_le(&h->conf.rtclg0_thresh_3, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG0_THRESH_3_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG0_THRESH_3");
      return err;
    }
  }

  // Write RTCLG0_THRESH_2
  {
    uint8_t val = 0;
    fh101rf_rtclg0_thresh_2_pack_le(&h->conf.rtclg0_thresh_2, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG0_THRESH_2_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG0_THRESH_2");
      return err;
    }
  }

  // Write RTCLG0_THRESH_1
  {
    uint8_t val = 0;
    fh101rf_rtclg0_thresh_1_pack_le(&h->conf.rtclg0_thresh_1, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG0_THRESH_1_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG0_THRESH_1");
      return err;
    }
  }

  // Write RTCLG0_THRESH_0
  {
    uint8_t val = 0;
    fh101rf_rtclg0_thresh_0_pack_le(&h->conf.rtclg0_thresh_0, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG0_THRESH_0_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG0_THRESH_0");
      return err;
    }
  }

  // Write RTCLG1_THRESH_4
  {
    uint8_t val = 0;
    fh101rf_rtclg1_thresh_4_pack_le(&h->conf.rtclg1_thresh_4, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG1_THRESH_4_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG1_THRESH_4");
      return err;
    }
  }

  // Write RTCLG1_THRESH_3
  {
    uint8_t val = 0;
    fh101rf_rtclg1_thresh_3_pack_le(&h->conf.rtclg1_thresh_3, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG1_THRESH_3_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG1_THRESH_3");
      return err;
    }
  }

  // Write RTCLG1_THRESH_2
  {
    uint8_t val = 0;
    fh101rf_rtclg1_thresh_2_pack_le(&h->conf.rtclg1_thresh_2, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG1_THRESH_2_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG1_THRESH_2");
      return err;
    }
  }

  // Write RTCLG1_THRESH_1
  {
    uint8_t val = 0;
    fh101rf_rtclg1_thresh_1_pack_le(&h->conf.rtclg1_thresh_1, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG1_THRESH_1_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG1_THRESH_1");
      return err;
    }
  }

  // Write RTCLG1_THRESH_0
  {
    uint8_t val = 0;
    fh101rf_rtclg1_thresh_0_pack_le(&h->conf.rtclg1_thresh_0, &val);
    err |= fh101rf_write_reg(h, FH101RF_RTCLG1_THRESH_0_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set RTCLG1_THRESH_0");
      return err;
    }
  }

  // Write CYCLPRESC
  {
    uint8_t val = 0;
    fh101rf_cyclpresc_pack_le(&h->conf.cyclpresc, &val);
    err |= fh101rf_write_reg(h, FH101RF_CYCLPRESC_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set CYCLPRESC");
      return err;
    }
  }

  // Write CYCLTOP_HI
  {
    uint8_t val = 0;
    fh101rf_cycltop_hi_pack_le(&h->conf.cycltop_hi, &val);
    err |= fh101rf_write_reg(h, FH101RF_CYCLTOP_HI_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set CYCLTOP_HI");
      return err;
    }
  }

  // Write CYCLTOP_LO
  {
    uint8_t val = 0;
    fh101rf_cycltop_lo_pack_le(&h->conf.cycltop_lo, &val);
    err |= fh101rf_write_reg(h, FH101RF_CYCLTOP_LO_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set CYCLTOP_LO");
      return err;
    }
  }

  // Write CNTR40_CLR (clearing counter CNTR40)
  {
    uint8_t val = 0;
    struct fh101rf_cntr40_clr temp = {
        .clr = true,
    };
    fh101rf_cntr40_clr_pack_le(&temp, &val);
    err |= fh101rf_write_reg(h, FH101RF_CNTR40_CLR_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set CNTR40_CLR");
      return err;
    }
  }

  // Write FIFO_LENGTH
  {
    uint8_t val = 0;
    fh101rf_fifo_length_pack_le(&h->conf.fifo_length, &val);
    err |= fh101rf_write_reg(h, FH101RF_FIFO_LENGTH_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set FIFO_LENGTH");
      return err;
    }
  }

  // Write FIFO_COUNT_433 (clearing to 0)
  {
    uint8_t val = 0;
    struct fh101rf_fifo_count_433 temp = {
        .data = 0,
    };
    fh101rf_fifo_count_433_pack_le(&temp, &val);
    err |= fh101rf_write_reg(h, FH101RF_FIFO_COUNT_433_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set FIFO_COUNT_433");
      return err;
    }
  }

  // Write FIFO_COUNT_868 (clearing to 0)
  {
    uint8_t val = 0;
    struct fh101rf_fifo_count_868 temp = {
        .data = 0,
    };
    fh101rf_fifo_count_868_pack_le(&temp, &val);
    err |= fh101rf_write_reg(h, FH101RF_FIFO_COUNT_868_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set FIFO_COUNT_868");
      return err;
    }
  }

  // Write FIFO_COUNT_2G4 (clearing to 0)
  {
    uint8_t val = 0;
    struct fh101rf_fifo_count_2g4 temp = {
        .data = 0,
    };
    fh101rf_fifo_count_2g4_pack_le(&temp, &val);
    err |= fh101rf_write_reg(h, FH101RF_FIFO_COUNT_2G4_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set FIFO_COUNT_2G4");
      return err;
    }
  }

  // Write GENPURP_1
  {
    uint8_t val = 0;
    fh101rf_genpurp_1_pack_le(&h->conf.genpurp_1, &val);
    err |= fh101rf_write_reg(h, FH101RF_GENPURP_1_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set GENPURP_1");
      return err;
    }
  }

  // Write XTAL_OSC_CTRL
  {
    uint8_t val = 0;
    fh101rf_xtal_osc_ctrl_pack_le(&h->conf.xtal_osc_ctrl, &val);
    err |= fh101rf_write_reg(h, FH101RF_XTAL_OSC_CTRL_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set XTAL_OSC_CTRL");
      return err;
    }
  }

  // Write LDO_XTAL_CTRL
  {
    uint8_t val = 0;
    fh101rf_ldo_xtal_ctrl_pack_le(&h->conf.ldo_xtal_ctrl, &val);
    err |= fh101rf_write_reg(h, FH101RF_LDO_XTAL_CTRL_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set LDO_XTAL_CTRL");
      return err;
    }
  }

  // Write MUX_D_OUT_SEL
  {
    uint8_t val = 0;
    fh101rf_mux_d_out_sel_pack_le(&h->conf.mux_d_out_sel, &val);
    err |= fh101rf_write_reg(h, FH101RF_MUX_D_OUT_SEL_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set MUX_D_OUT_SEL");
      return err;
    }
  }

  // Write KORREL_SV_CLEAR (clear KORREL_STATE)
  {
    uint8_t val = 0;
    struct fh101rf_korrel_sv_clear temp = {
        .data = true,
    };
    fh101rf_korrel_sv_clear_pack_le(&temp, &val);
    err |= fh101rf_write_reg(h, FH101RF_KORREL_SV_CLEAR_ADDRESS, val);
    if (err) {
      DRVR_ERR("Failed to set KORREL_SV_CLEAR");
      return err;
    }
  }

  return err;
}

fh101rf_err_t check_connection(const struct fh101rf_h *h) {

  fh101rf_err_t err = E_FH101RF_SUCCESS;

  // Check version value:
  uint8_t result = 0;
  fh101rf_read_reg(h, FH101RF_VERSION_ADDRESS, &result);

  uint8_t default_version[1] = FH101RF_VERSION_RESET_LE;
  if (result != default_version[0]) {
    DRVR_ERR_VAR("Got wrong version id", result);
    return E_FH101RF_COM_ERR;
  }

  return err;
}

fh101rf_err_t validate_handle(const struct fh101rf_h *h) {
  fh101rf_err_t err = E_FH101RF_SUCCESS;

  if (h == 0) {
    return E_FH101RF_NULLPTR_ERR;
  }

  if (h->spi_read == 0) {
    DRVR_ERR("ERROR: spi_read is nullptr!");
    err |= E_FH101RF_NULLPTR_ERR;
  }

  if (h->spi_write == 0) {
    DRVR_ERR("ERROR: spi_write is nullptr!");
    err |= E_FH101RF_NULLPTR_ERR;
  }

  if (h->sleep_ms == 0) {
    DRVR_ERR("ERROR: sleep_ms is nullptr!");
    err |= E_FH101RF_NULLPTR_ERR;
  }

  return err;
}

fh101rf_err_t comp_calibrate(struct fh101rf_h *h) {
  fh101rf_err_t err = E_FH101RF_SUCCESS;

  // Save current value of register BAND_BRANCH_CTRL
  // not needed as already in our register struct

  // Set Bits 6 to 4 in BAND_BRANCH_CTRL to 1
  {
    struct fh101rf_band_branch_ctrl temp;
    memcpy(&temp, &h->conf.band_branch_ctrl,
           sizeof(struct fh101rf_band_branch_ctrl));
    temp.active_bands.band_433 = true;
    temp.active_bands.band_868 = true;
    temp.active_bands.band_2g4 = true;

    uint8_t data = 0;
    fh101rf_band_branch_ctrl_pack_le(&h->conf.band_branch_ctrl, &data);
    err |= fh101rf_write_reg(h, FH101RF_BAND_BRANCH_CTRL_ADDRESS, data);
    if (err) {
      DRVR_ERR("Failed to set BAND_BRANCH_CTRL");
      return err;
    }
  }

  // Set COMP_THRESH_W to 0x0A
  {
    h->conf.comp_thresh_w.data = 0x0A;
    uint8_t data = 0;
    fh101rf_comp_thresh_w_pack_le(&h->conf.comp_thresh_w, &data);
    err |= fh101rf_write_reg(h, FH101RF_COMP_THRESH_W_ADDRESS, data);
    h->conf.comp_thresh_w.data = 0x00;
    if (err) {
      DRVR_ERR("Failed to set COMP_THRESH_W to 0x0A");
      return err;
    }
  }

  // Set OFFSET_CAL and CAL_START in CALIB_CTRL
  {
    h->conf.calib_ctrl.cal_start = true;
    h->conf.calib_ctrl.offset_cal = true;
    uint8_t data = 0;
    fh101rf_calib_ctrl_pack_le(&h->conf.calib_ctrl, &data);
    err |= fh101rf_write_reg(h, FH101RF_CALIB_CTRL_ADDRESS, data);
    h->conf.calib_ctrl.cal_start = false;
    h->conf.calib_ctrl.offset_cal = false;
    if (err) {
      DRVR_ERR("Failed to set CALIB_CTRL");
      return err;
    }
  }

  // Check CALIB_CTRL for CAL_START
  {
    struct fh101rf_calib_ctrl temp = {0};
    while (temp.cal_start == false) {
      uint8_t result = 0;
      err |= fh101rf_read_reg(h, FH101RF_CALIB_CTRL_ADDRESS, &result);
      if (err) {
        DRVR_ERR("Failed to readout CALIB_CTRL");
        return err;
      }

      temp = fh101rf_calib_ctrl_unpack_le(&result);
      h->sleep_ms(1);
    }
  }

  // Wait for CAL_IN_PROG to become false
  {
    struct fh101rf_calib_status status = {
        .cal_in_prog = true,
        .lco_cal_in_prog = true,
        .offset_cal_in_prog = true,
        .spg_cal_in_prog = true,
    };

    while (status.cal_in_prog == true) {
      uint8_t result = 0;
      err |= fh101rf_read_reg(h, FH101RF_CALIB_STATUS_ADDRESS, &result);
      if (err) {
        DRVR_ERR("Failed to readout CALIB_STATUS");
        return err;
      }

      status = fh101rf_calib_status_unpack_le(&result);
      h->sleep_ms(1);
    }
  }

  // Reset BAND_BRANCH_CTRL to saved value
  {
    uint8_t data = 0;
    fh101rf_band_branch_ctrl_pack_le(&h->conf.band_branch_ctrl, &data);
    err |= fh101rf_write_reg(h, FH101RF_BAND_BRANCH_CTRL_ADDRESS, data);
    if (err) {
      DRVR_ERR("Failed to set BAND_BRANCH_CTRL");
      return err;
    }
  }

  return err;
}

fh101rf_err_t lco_calibrate(struct fh101rf_h *h) {
  fh101rf_err_t err = E_FH101RF_SUCCESS;

  // Set BAND_BRANCH_CTRL as desired
  {
    uint8_t data = 0;
    fh101rf_band_branch_ctrl_pack_le(&h->conf.band_branch_ctrl, &data);
    err |= fh101rf_write_reg(h, FH101RF_BAND_BRANCH_CTRL_ADDRESS, data);
    if (err) {
      DRVR_ERR("Failed to set BAND_BRANCH_CTRL");
      return err;
    }
  }

  // Set N_LCO_TARGET accordingly

  // Set LCO_CAL and CAL_START in CALIB_CTRL
  {
    h->conf.calib_ctrl.cal_start = true;
    h->conf.calib_ctrl.lco_cal = true;
    uint8_t data = 0;
    fh101rf_calib_ctrl_pack_le(&h->conf.calib_ctrl, &data);
    err |= fh101rf_write_reg(h, FH101RF_CALIB_CTRL_ADDRESS, data);
    h->conf.calib_ctrl.cal_start = false;
    h->conf.calib_ctrl.lco_cal = false;
    if (err) {
      DRVR_ERR("Failed to set CALIB_CTRL");
      return err;
    }
  }

  // Check CALIB_CTRL for CAL_START
  {
    struct fh101rf_calib_ctrl temp = {0};
    while (temp.cal_start == false) {
      uint8_t result = 0;
      err |= fh101rf_read_reg(h, FH101RF_CALIB_CTRL_ADDRESS, &result);
      if (err) {
        DRVR_ERR("Failed to readout CALIB_CTRL");
        return err;
      }

      temp = fh101rf_calib_ctrl_unpack_le(&result);
      h->sleep_ms(1);
    }
  }

  // Wait for CAL_IN_PROG to become false
  {
    struct fh101rf_calib_status status = {
        .cal_in_prog = true,
        .lco_cal_in_prog = true,
        .offset_cal_in_prog = true,
        .spg_cal_in_prog = true,
    };

    while (status.cal_in_prog == true) {
      uint8_t result = 0;
      err |= fh101rf_read_reg(h, FH101RF_CALIB_STATUS_ADDRESS, &result);
      if (err) {
        DRVR_ERR("Failed to readout CALIB_STATUS");
        return err;
      }

      status = fh101rf_calib_status_unpack_le(&result);
      h->sleep_ms(1);
    }
  }

  // TODO: Readout LCO_FREQ, calculate effective frequency, compare to float
  // values in struct

  return err;
}

fh101rf_err_t sample_pulse_calibrate(struct fh101rf_h *h) {
  fh101rf_err_t err = E_FH101RF_SUCCESS;

  // Set N_SPG_TARGET to non-default-value 0x46
  {
    h->conf.n_spg_target.data = 0x46;

    uint8_t data = 0;
    fh101rf_n_spg_target_pack_le(&h->conf.n_spg_target, &data);
    err |= fh101rf_write_reg(h, FH101RF_N_SPG_TARGET_ADDRESS, data);
    if (err) {
      DRVR_ERR("Failed to set N_SPG_TARGET");
      return err;
    }
  }

  // Set SPG_CAL_CAL and CAL_START in CALIB_CTRL
  {
    h->conf.calib_ctrl.cal_start = true;
    h->conf.calib_ctrl.spg_cal = true;
    uint8_t data = 0;
    fh101rf_calib_ctrl_pack_le(&h->conf.calib_ctrl, &data);
    err |= fh101rf_write_reg(h, FH101RF_CALIB_CTRL_ADDRESS, data);
    h->conf.calib_ctrl.cal_start = false;
    h->conf.calib_ctrl.spg_cal = false;
    if (err) {
      DRVR_ERR("Failed to set CALIB_CTRL");
      return err;
    }
  }

  // Check CALIB_CTRL for CAL_START
  {
    struct fh101rf_calib_ctrl temp = {0};
    while (temp.cal_start == false) {
      uint8_t result = 0;
      err |= fh101rf_read_reg(h, FH101RF_CALIB_CTRL_ADDRESS, &result);
      if (err) {
        DRVR_ERR("Failed to readout CALIB_CTRL");
        return err;
      }

      temp = fh101rf_calib_ctrl_unpack_le(&result);
      h->sleep_ms(1);
    }
  }

  // Wait for CAL_IN_PROG to become false
  {
    struct fh101rf_calib_status status = {
        .cal_in_prog = true,
        .lco_cal_in_prog = true,
        .offset_cal_in_prog = true,
        .spg_cal_in_prog = true,
    };

    while (status.cal_in_prog == true) {
      uint8_t result = 0;
      err |= fh101rf_read_reg(h, FH101RF_CALIB_STATUS_ADDRESS, &result);
      if (err) {
        DRVR_ERR("Failed to readout CALIB_STATUS");
        return err;
      }

      status = fh101rf_calib_status_unpack_le(&result);
      h->sleep_ms(1);
    }
  }

  return err;
}
