/**
 * @file fh101rf.h
 * @brief FH101RF Driver
 *
 * Listing file author: Silvano Cortesi
 *
 * Listing file notice:
 *   Licensed under TBD
 */

#ifndef FH101RF_H
#define FH101RF_H

#include "fh101rf_reg.h"

// Struct containing all registers
struct fh101rf {
  struct fh101rf_nfa433_slow nfa433_slow;
  struct fh101rf_nfa433_fast nfa433_fast;
  struct fh101rf_nfa868_slow nfa868_slow;
  struct fh101rf_nfa868_fast nfa868_fast;
  struct fh101rf_nfa2g4_slow nfa2g4_slow;
  struct fh101rf_nfa2g4_fast nfa2g4_fast;
  struct fh101rf_calib_status calib_status;
  struct fh101rf_calib_ctrl calib_ctrl;
  struct fh101rf_n_spg_target n_spg_target;
  struct fh101rf_n_lco_target_433_hi n_lco_target_433_hi;
  struct fh101rf_n_lco_target_433_lo n_lco_target_433_lo;
  struct fh101rf_n_lco_target_868_hi n_lco_target_868_hi;
  struct fh101rf_n_lco_target_868_lo n_lco_target_868_lo;
  struct fh101rf_n_lco_target_2g4_hi n_lco_target_2g4_hi;
  struct fh101rf_n_lco_target_2g4_lo n_lco_target_2g4_lo;
  struct fh101rf_lco_freq_433_hi lco_freq_433_hi;
  struct fh101rf_lco_freq_433_lo lco_freq_433_lo;
  struct fh101rf_lco_freq_868_hi lco_freq_868_hi;
  struct fh101rf_lco_freq_868_lo lco_freq_868_lo;
  struct fh101rf_lco_freq_2g4_hi lco_freq_2g4_hi;
  struct fh101rf_lco_freq_2g4_lo lco_freq_2g4_lo;
  struct fh101rf_d_corner_ctrl d_corner_ctrl;
  struct fh101rf_band_branch_ctrl band_branch_ctrl;
  struct fh101rf_code_select code_select;
  struct fh101rf_korrel_thresh_a korrel_thresh_a;
  struct fh101rf_korrel_thresh_b korrel_thresh_b;
  struct fh101rf_korrel_state korrel_state;
  struct fh101rf_korrel_val korrel_val;
  struct fh101rf_fdd_enable fdd_enable;
  struct fh101rf_fdd_active fdd_active;
  struct fh101rf_fo_quit fo_quit;
  struct fh101rf_fdd_exit_cond fdd_exit_cond;
  struct fh101rf_irq_select irq_select;
  struct fh101rf_irq_status irq_status;
  struct fh101rf_irq_clr irq_clr;
  struct fh101rf_irq_set irq_set;
  struct fh101rf_id_hi id_hi;
  struct fh101rf_id_lo id_lo;
  struct fh101rf_idm_enable idm_enable;
  struct fh101rf_idm_ctrl idm_ctrl;
  struct fh101rf_idm_clr idm_clr;
  struct fh101rf_idm_band idm_band;
  struct fh101rf_idm_reason idm_reason;
  struct fh101rf_rtc_select rtc_select;
  struct fh101rf_rtc_status rtc_status;
  struct fh101rf_rtc_clr rtc_clr;
  struct fh101rf_rtcsh0_thresh_hi rtcsh0_thresh_hi;
  struct fh101rf_rtcsh0_thresh_lo rtcsh0_thresh_lo;
  struct fh101rf_rtcsh1_thresh_hi rtcsh1_thresh_hi;
  struct fh101rf_rtcsh1_thresh_lo rtcsh1_thresh_lo;
  struct fh101rf_rtclg0_thresh_4 rtclg0_thresh_4;
  struct fh101rf_rtclg0_thresh_3 rtclg0_thresh_3;
  struct fh101rf_rtclg0_thresh_2 rtclg0_thresh_2;
  struct fh101rf_rtclg0_thresh_1 rtclg0_thresh_1;
  struct fh101rf_rtclg0_thresh_0 rtclg0_thresh_0;
  struct fh101rf_rtclg1_thresh_4 rtclg1_thresh_4;
  struct fh101rf_rtclg1_thresh_3 rtclg1_thresh_3;
  struct fh101rf_rtclg1_thresh_2 rtclg1_thresh_2;
  struct fh101rf_rtclg1_thresh_1 rtclg1_thresh_1;
  struct fh101rf_rtclg1_thresh_0 rtclg1_thresh_0;
  struct fh101rf_cyclpresc cyclpresc;
  struct fh101rf_cycltop_hi cycltop_hi;
  struct fh101rf_cycltop_lo cycltop_lo;
  struct fh101rf_cntr40_4 cntr40_4;
  struct fh101rf_cntr40_3 cntr40_3;
  struct fh101rf_cntr40_2 cntr40_2;
  struct fh101rf_cntr40_1 cntr40_1;
  struct fh101rf_cntr40_0 cntr40_0;
  struct fh101rf_cntr40_clr cntr40_clr;
  struct fh101rf_fifo_length fifo_length;
  struct fh101rf_fifo_count_433 fifo_count_433;
  struct fh101rf_fifo_count_868 fifo_count_868;
  struct fh101rf_fifo_count_2g4 fifo_count_2g4;
  struct fh101rf_rx_fifo_5_433 rx_fifo_5_433;
  struct fh101rf_rx_fifo_4_433 rx_fifo_4_433;
  struct fh101rf_rx_fifo_3_433 rx_fifo_3_433;
  struct fh101rf_rx_fifo_2_433 rx_fifo_2_433;
  struct fh101rf_rx_fifo_1_433 rx_fifo_1_433;
  struct fh101rf_rx_fifo_0_433 rx_fifo_0_433;
  struct fh101rf_rx_fifo_5_868 rx_fifo_5_868;
  struct fh101rf_rx_fifo_4_868 rx_fifo_4_868;
  struct fh101rf_rx_fifo_3_868 rx_fifo_3_868;
  struct fh101rf_rx_fifo_2_868 rx_fifo_2_868;
  struct fh101rf_rx_fifo_1_868 rx_fifo_1_868;
  struct fh101rf_rx_fifo_0_868 rx_fifo_0_868;
  struct fh101rf_rx_fifo_5_2g4 rx_fifo_5_2g4;
  struct fh101rf_rx_fifo_4_2g4 rx_fifo_4_2g4;
  struct fh101rf_rx_fifo_3_2g4 rx_fifo_3_2g4;
  struct fh101rf_rx_fifo_2_2g4 rx_fifo_2_2g4;
  struct fh101rf_rx_fifo_1_2g4 rx_fifo_1_2g4;
  struct fh101rf_rx_fifo_0_2g4 rx_fifo_0_2g4;
  struct fh101rf_actual_nfa_433 actual_nfa_433;
  struct fh101rf_actual_nfa_868 actual_nfa_868;
  struct fh101rf_actual_nfa_2g4 actual_nfa_2g4;
  struct fh101rf_actual_bandselect actual_bandselect;
  struct fh101rf_genpurp_1 genpurp_1;
  struct fh101rf_xtal_osc_ctrl xtal_osc_ctrl;
  struct fh101rf_ldo_xtal_ctrl ldo_xtal_ctrl;
  struct fh101rf_mux_d_out_sel mux_d_out_sel;
  struct fh101rf_lc_tg_ena lc_tg_ena;
  struct fh101rf_xtal_good xtal_good;
  struct fh101rf_korrel_sv_clear korrel_sv_clear;
  struct fh101rf_version version;
};

static inline struct fh101rf fh101rf_default_le(void) {
  struct fh101rf dev;
  dev.nfa433_slow =
      fh101rf_nfa433_slow_unpack_le((uint8_t[1])FH101RF_NFA433_SLOW_RESET_LE);
  dev.nfa433_fast =
      fh101rf_nfa433_fast_unpack_le((uint8_t[1])FH101RF_NFA433_FAST_RESET_LE);
  dev.nfa868_slow =
      fh101rf_nfa868_slow_unpack_le((uint8_t[1])FH101RF_NFA868_SLOW_RESET_LE);
  dev.nfa868_fast =
      fh101rf_nfa868_fast_unpack_le((uint8_t[1])FH101RF_NFA868_FAST_RESET_LE);
  dev.nfa2g4_slow =
      fh101rf_nfa2g4_slow_unpack_le((uint8_t[1])FH101RF_NFA2G4_SLOW_RESET_LE);
  dev.nfa2g4_fast =
      fh101rf_nfa2g4_fast_unpack_le((uint8_t[1])FH101RF_NFA2G4_FAST_RESET_LE);
  dev.calib_status =
      fh101rf_calib_status_unpack_le((uint8_t[1])FH101RF_CALIB_STATUS_RESET_LE);
  dev.calib_ctrl =
      fh101rf_calib_ctrl_unpack_le((uint8_t[1])FH101RF_CALIB_CTRL_RESET_LE);
  dev.n_spg_target =
      fh101rf_n_spg_target_unpack_le((uint8_t[1])FH101RF_N_SPG_TARGET_RESET_LE);
  dev.n_lco_target_433_hi = fh101rf_n_lco_target_433_hi_unpack_le(
      (uint8_t[1])FH101RF_N_LCO_TARGET_433_HI_RESET_LE);
  dev.n_lco_target_433_lo = fh101rf_n_lco_target_433_lo_unpack_le(
      (uint8_t[1])FH101RF_N_LCO_TARGET_433_LO_RESET_LE);
  dev.n_lco_target_868_hi = fh101rf_n_lco_target_868_hi_unpack_le(
      (uint8_t[1])FH101RF_N_LCO_TARGET_868_HI_RESET_LE);
  dev.n_lco_target_868_lo = fh101rf_n_lco_target_868_lo_unpack_le(
      (uint8_t[1])FH101RF_N_LCO_TARGET_868_LO_RESET_LE);
  dev.n_lco_target_2g4_hi = fh101rf_n_lco_target_2g4_hi_unpack_le(
      (uint8_t[1])FH101RF_N_LCO_TARGET_2G4_HI_RESET_LE);
  dev.n_lco_target_2g4_lo = fh101rf_n_lco_target_2g4_lo_unpack_le(
      (uint8_t[1])FH101RF_N_LCO_TARGET_2G4_LO_RESET_LE);
  dev.lco_freq_433_hi = fh101rf_lco_freq_433_hi_unpack_le(
      (uint8_t[1])FH101RF_LCO_FREQ_433_HI_RESET_LE);
  dev.lco_freq_433_lo = fh101rf_lco_freq_433_lo_unpack_le(
      (uint8_t[1])FH101RF_LCO_FREQ_433_LO_RESET_LE);
  dev.lco_freq_868_hi = fh101rf_lco_freq_868_hi_unpack_le(
      (uint8_t[1])FH101RF_LCO_FREQ_868_HI_RESET_LE);
  dev.lco_freq_868_lo = fh101rf_lco_freq_868_lo_unpack_le(
      (uint8_t[1])FH101RF_LCO_FREQ_868_LO_RESET_LE);
  dev.lco_freq_2g4_hi = fh101rf_lco_freq_2g4_hi_unpack_le(
      (uint8_t[1])FH101RF_LCO_FREQ_2G4_HI_RESET_LE);
  dev.lco_freq_2g4_lo = fh101rf_lco_freq_2g4_lo_unpack_le(
      (uint8_t[1])FH101RF_LCO_FREQ_2G4_LO_RESET_LE);
  dev.d_corner_ctrl = fh101rf_d_corner_ctrl_unpack_le(
      (uint8_t[1])FH101RF_D_CORNER_CTRL_RESET_LE);
  dev.band_branch_ctrl = fh101rf_band_branch_ctrl_unpack_le(
      (uint8_t[1])FH101RF_BAND_BRANCH_CTRL_RESET_LE);
  dev.code_select =
      fh101rf_code_select_unpack_le((uint8_t[1])FH101RF_CODE_SELECT_RESET_LE);
  dev.korrel_thresh_a = fh101rf_korrel_thresh_a_unpack_le(
      (uint8_t[1])FH101RF_KORREL_THRESH_A_RESET_LE);
  dev.korrel_thresh_b = fh101rf_korrel_thresh_b_unpack_le(
      (uint8_t[1])FH101RF_KORREL_THRESH_B_RESET_LE);
  dev.korrel_state =
      fh101rf_korrel_state_unpack_le((uint8_t[1])FH101RF_KORREL_STATE_RESET_LE);
  dev.korrel_val =
      fh101rf_korrel_val_unpack_le((uint8_t[1])FH101RF_KORREL_VAL_RESET_LE);
  dev.fdd_enable =
      fh101rf_fdd_enable_unpack_le((uint8_t[1])FH101RF_FDD_ENABLE_RESET_LE);
  dev.fdd_active =
      fh101rf_fdd_active_unpack_le((uint8_t[1])FH101RF_FDD_ACTIVE_RESET_LE);
  dev.fo_quit = fh101rf_fo_quit_unpack_le((uint8_t[1])FH101RF_FO_QUIT_RESET_LE);
  dev.fdd_exit_cond = fh101rf_fdd_exit_cond_unpack_le(
      (uint8_t[1])FH101RF_FDD_EXIT_COND_RESET_LE);
  dev.irq_select =
      fh101rf_irq_select_unpack_le((uint8_t[1])FH101RF_IRQ_SELECT_RESET_LE);
  dev.irq_status =
      fh101rf_irq_status_unpack_le((uint8_t[1])FH101RF_IRQ_STATUS_RESET_LE);
  dev.irq_clr = fh101rf_irq_clr_unpack_le((uint8_t[1])FH101RF_IRQ_CLR_RESET_LE);
  dev.irq_set = fh101rf_irq_set_unpack_le((uint8_t[1])FH101RF_IRQ_SET_RESET_LE);
  dev.id_hi = fh101rf_id_hi_unpack_le((uint8_t[1])FH101RF_ID_HI_RESET_LE);
  dev.id_lo = fh101rf_id_lo_unpack_le((uint8_t[1])FH101RF_ID_LO_RESET_LE);
  dev.idm_enable =
      fh101rf_idm_enable_unpack_le((uint8_t[1])FH101RF_IDM_ENABLE_RESET_LE);
  dev.idm_ctrl =
      fh101rf_idm_ctrl_unpack_le((uint8_t[1])FH101RF_IDM_CTRL_RESET_LE);
  dev.idm_clr = fh101rf_idm_clr_unpack_le((uint8_t[1])FH101RF_IDM_CLR_RESET_LE);
  dev.idm_band =
      fh101rf_idm_band_unpack_le((uint8_t[1])FH101RF_IDM_BAND_RESET_LE);
  dev.idm_reason =
      fh101rf_idm_reason_unpack_le((uint8_t[1])FH101RF_IDM_REASON_RESET_LE);
  dev.rtc_select =
      fh101rf_rtc_select_unpack_le((uint8_t[1])FH101RF_RTC_SELECT_RESET_LE);
  dev.rtc_status =
      fh101rf_rtc_status_unpack_le((uint8_t[1])FH101RF_RTC_STATUS_RESET_LE);
  dev.rtc_clr = fh101rf_rtc_clr_unpack_le((uint8_t[1])FH101RF_RTC_CLR_RESET_LE);
  dev.rtcsh0_thresh_hi = fh101rf_rtcsh0_thresh_hi_unpack_le(
      (uint8_t[1])FH101RF_RTCSH0_THRESH_HI_RESET_LE);
  dev.rtcsh0_thresh_lo = fh101rf_rtcsh0_thresh_lo_unpack_le(
      (uint8_t[1])FH101RF_RTCSH0_THRESH_LO_RESET_LE);
  dev.rtcsh1_thresh_hi = fh101rf_rtcsh1_thresh_hi_unpack_le(
      (uint8_t[1])FH101RF_RTCSH1_THRESH_HI_RESET_LE);
  dev.rtcsh1_thresh_lo = fh101rf_rtcsh1_thresh_lo_unpack_le(
      (uint8_t[1])FH101RF_RTCSH1_THRESH_LO_RESET_LE);
  dev.rtclg0_thresh_4 = fh101rf_rtclg0_thresh_4_unpack_le(
      (uint8_t[1])FH101RF_RTCLG0_THRESH_4_RESET_LE);
  dev.rtclg0_thresh_3 = fh101rf_rtclg0_thresh_3_unpack_le(
      (uint8_t[1])FH101RF_RTCLG0_THRESH_3_RESET_LE);
  dev.rtclg0_thresh_2 = fh101rf_rtclg0_thresh_2_unpack_le(
      (uint8_t[1])FH101RF_RTCLG0_THRESH_2_RESET_LE);
  dev.rtclg0_thresh_1 = fh101rf_rtclg0_thresh_1_unpack_le(
      (uint8_t[1])FH101RF_RTCLG0_THRESH_1_RESET_LE);
  dev.rtclg0_thresh_0 = fh101rf_rtclg0_thresh_0_unpack_le(
      (uint8_t[1])FH101RF_RTCLG0_THRESH_0_RESET_LE);
  dev.rtclg1_thresh_4 = fh101rf_rtclg1_thresh_4_unpack_le(
      (uint8_t[1])FH101RF_RTCLG1_THRESH_4_RESET_LE);
  dev.rtclg1_thresh_3 = fh101rf_rtclg1_thresh_3_unpack_le(
      (uint8_t[1])FH101RF_RTCLG1_THRESH_3_RESET_LE);
  dev.rtclg1_thresh_2 = fh101rf_rtclg1_thresh_2_unpack_le(
      (uint8_t[1])FH101RF_RTCLG1_THRESH_2_RESET_LE);
  dev.rtclg1_thresh_1 = fh101rf_rtclg1_thresh_1_unpack_le(
      (uint8_t[1])FH101RF_RTCLG1_THRESH_1_RESET_LE);
  dev.rtclg1_thresh_0 = fh101rf_rtclg1_thresh_0_unpack_le(
      (uint8_t[1])FH101RF_RTCLG1_THRESH_0_RESET_LE);
  dev.cyclpresc =
      fh101rf_cyclpresc_unpack_le((uint8_t[1])FH101RF_CYCLPRESC_RESET_LE);
  dev.cycltop_hi =
      fh101rf_cycltop_hi_unpack_le((uint8_t[1])FH101RF_CYCLTOP_HI_RESET_LE);
  dev.cycltop_lo =
      fh101rf_cycltop_lo_unpack_le((uint8_t[1])FH101RF_CYCLTOP_LO_RESET_LE);
  dev.cntr40_4 =
      fh101rf_cntr40_4_unpack_le((uint8_t[1])FH101RF_CNTR40_4_RESET_LE);
  dev.cntr40_3 =
      fh101rf_cntr40_3_unpack_le((uint8_t[1])FH101RF_CNTR40_3_RESET_LE);
  dev.cntr40_2 =
      fh101rf_cntr40_2_unpack_le((uint8_t[1])FH101RF_CNTR40_2_RESET_LE);
  dev.cntr40_1 =
      fh101rf_cntr40_1_unpack_le((uint8_t[1])FH101RF_CNTR40_1_RESET_LE);
  dev.cntr40_0 =
      fh101rf_cntr40_0_unpack_le((uint8_t[1])FH101RF_CNTR40_0_RESET_LE);
  dev.cntr40_clr =
      fh101rf_cntr40_clr_unpack_le((uint8_t[1])FH101RF_CNTR40_CLR_RESET_LE);
  dev.fifo_length =
      fh101rf_fifo_length_unpack_le((uint8_t[1])FH101RF_FIFO_LENGTH_RESET_LE);
  dev.fifo_count_433 = fh101rf_fifo_count_433_unpack_le(
      (uint8_t[1])FH101RF_FIFO_COUNT_433_RESET_LE);
  dev.fifo_count_868 = fh101rf_fifo_count_868_unpack_le(
      (uint8_t[1])FH101RF_FIFO_COUNT_868_RESET_LE);
  dev.fifo_count_2g4 = fh101rf_fifo_count_2g4_unpack_le(
      (uint8_t[1])FH101RF_FIFO_COUNT_2G4_RESET_LE);
  dev.rx_fifo_5_433 = fh101rf_rx_fifo_5_433_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_5_433_RESET_LE);
  dev.rx_fifo_4_433 = fh101rf_rx_fifo_4_433_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_4_433_RESET_LE);
  dev.rx_fifo_3_433 = fh101rf_rx_fifo_3_433_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_3_433_RESET_LE);
  dev.rx_fifo_2_433 = fh101rf_rx_fifo_2_433_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_2_433_RESET_LE);
  dev.rx_fifo_1_433 = fh101rf_rx_fifo_1_433_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_1_433_RESET_LE);
  dev.rx_fifo_0_433 = fh101rf_rx_fifo_0_433_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_0_433_RESET_LE);
  dev.rx_fifo_5_868 = fh101rf_rx_fifo_5_868_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_5_868_RESET_LE);
  dev.rx_fifo_4_868 = fh101rf_rx_fifo_4_868_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_4_868_RESET_LE);
  dev.rx_fifo_3_868 = fh101rf_rx_fifo_3_868_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_3_868_RESET_LE);
  dev.rx_fifo_2_868 = fh101rf_rx_fifo_2_868_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_2_868_RESET_LE);
  dev.rx_fifo_1_868 = fh101rf_rx_fifo_1_868_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_1_868_RESET_LE);
  dev.rx_fifo_0_868 = fh101rf_rx_fifo_0_868_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_0_868_RESET_LE);
  dev.rx_fifo_5_2g4 = fh101rf_rx_fifo_5_2g4_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_5_2G4_RESET_LE);
  dev.rx_fifo_4_2g4 = fh101rf_rx_fifo_4_2g4_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_4_2G4_RESET_LE);
  dev.rx_fifo_3_2g4 = fh101rf_rx_fifo_3_2g4_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_3_2G4_RESET_LE);
  dev.rx_fifo_2_2g4 = fh101rf_rx_fifo_2_2g4_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_2_2G4_RESET_LE);
  dev.rx_fifo_1_2g4 = fh101rf_rx_fifo_1_2g4_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_1_2G4_RESET_LE);
  dev.rx_fifo_0_2g4 = fh101rf_rx_fifo_0_2g4_unpack_le(
      (uint8_t[1])FH101RF_RX_FIFO_0_2G4_RESET_LE);
  dev.actual_nfa_433 = fh101rf_actual_nfa_433_unpack_le(
      (uint8_t[1])FH101RF_ACTUAL_NFA_433_RESET_LE);
  dev.actual_nfa_868 = fh101rf_actual_nfa_868_unpack_le(
      (uint8_t[1])FH101RF_ACTUAL_NFA_868_RESET_LE);
  dev.actual_nfa_2g4 = fh101rf_actual_nfa_2g4_unpack_le(
      (uint8_t[1])FH101RF_ACTUAL_NFA_2G4_RESET_LE);
  dev.actual_bandselect = fh101rf_actual_bandselect_unpack_le(
      (uint8_t[1])FH101RF_ACTUAL_BANDSELECT_RESET_LE);
  dev.genpurp_1 =
      fh101rf_genpurp_1_unpack_le((uint8_t[1])FH101RF_GENPURP_1_RESET_LE);
  dev.xtal_osc_ctrl = fh101rf_xtal_osc_ctrl_unpack_le(
      (uint8_t[1])FH101RF_XTAL_OSC_CTRL_RESET_LE);
  dev.ldo_xtal_ctrl = fh101rf_ldo_xtal_ctrl_unpack_le(
      (uint8_t[1])FH101RF_LDO_XTAL_CTRL_RESET_LE);
  dev.mux_d_out_sel = fh101rf_mux_d_out_sel_unpack_le(
      (uint8_t[1])FH101RF_MUX_D_OUT_SEL_RESET_LE);
  dev.lc_tg_ena =
      fh101rf_lc_tg_ena_unpack_le((uint8_t[1])FH101RF_LC_TG_ENA_RESET_LE);
  dev.xtal_good =
      fh101rf_xtal_good_unpack_le((uint8_t[1])FH101RF_XTAL_GOOD_RESET_LE);
  dev.korrel_sv_clear = fh101rf_korrel_sv_clear_unpack_le(
      (uint8_t[1])FH101RF_KORREL_SV_CLEAR_RESET_LE);
  dev.version = fh101rf_version_unpack_le((uint8_t[1])FH101RF_VERSION_RESET_LE);

  return dev;
}

static inline void fh101rf_pack_le(const struct fh101rf *dev,
                                   uint8_t byte_arr[103]) {
  fh101rf_nfa433_slow_pack_le(&dev->nfa433_slow, &byte_arr[0]);
  fh101rf_nfa433_fast_pack_le(&dev->nfa433_fast, &byte_arr[1]);
  fh101rf_nfa868_slow_pack_le(&dev->nfa868_slow, &byte_arr[2]);
  fh101rf_nfa868_fast_pack_le(&dev->nfa868_fast, &byte_arr[3]);
  fh101rf_nfa2g4_slow_pack_le(&dev->nfa2g4_slow, &byte_arr[4]);
  fh101rf_nfa2g4_fast_pack_le(&dev->nfa2g4_fast, &byte_arr[5]);
  fh101rf_calib_status_pack_le(&dev->calib_status, &byte_arr[6]);
  fh101rf_calib_ctrl_pack_le(&dev->calib_ctrl, &byte_arr[7]);
  fh101rf_n_spg_target_pack_le(&dev->n_spg_target, &byte_arr[8]);
  fh101rf_n_lco_target_433_hi_pack_le(&dev->n_lco_target_433_hi, &byte_arr[9]);
  fh101rf_n_lco_target_433_lo_pack_le(&dev->n_lco_target_433_lo, &byte_arr[10]);
  fh101rf_n_lco_target_868_hi_pack_le(&dev->n_lco_target_868_hi, &byte_arr[11]);
  fh101rf_n_lco_target_868_lo_pack_le(&dev->n_lco_target_868_lo, &byte_arr[12]);
  fh101rf_n_lco_target_2g4_hi_pack_le(&dev->n_lco_target_2g4_hi, &byte_arr[13]);
  fh101rf_n_lco_target_2g4_lo_pack_le(&dev->n_lco_target_2g4_lo, &byte_arr[14]);
  fh101rf_lco_freq_433_hi_pack_le(&dev->lco_freq_433_hi, &byte_arr[15]);
  fh101rf_lco_freq_433_lo_pack_le(&dev->lco_freq_433_lo, &byte_arr[16]);
  fh101rf_lco_freq_868_hi_pack_le(&dev->lco_freq_868_hi, &byte_arr[17]);
  fh101rf_lco_freq_868_lo_pack_le(&dev->lco_freq_868_lo, &byte_arr[18]);
  fh101rf_lco_freq_2g4_hi_pack_le(&dev->lco_freq_2g4_hi, &byte_arr[19]);
  fh101rf_lco_freq_2g4_lo_pack_le(&dev->lco_freq_2g4_lo, &byte_arr[20]);
  fh101rf_d_corner_ctrl_pack_le(&dev->d_corner_ctrl, &byte_arr[21]);
  fh101rf_band_branch_ctrl_pack_le(&dev->band_branch_ctrl, &byte_arr[22]);
  fh101rf_code_select_pack_le(&dev->code_select, &byte_arr[23]);
  fh101rf_korrel_thresh_a_pack_le(&dev->korrel_thresh_a, &byte_arr[24]);
  fh101rf_korrel_thresh_b_pack_le(&dev->korrel_thresh_b, &byte_arr[25]);
  fh101rf_korrel_state_pack_le(&dev->korrel_state, &byte_arr[26]);
  fh101rf_korrel_val_pack_le(&dev->korrel_val, &byte_arr[27]);
  fh101rf_fdd_enable_pack_le(&dev->fdd_enable, &byte_arr[28]);
  fh101rf_fdd_active_pack_le(&dev->fdd_active, &byte_arr[29]);
  fh101rf_fo_quit_pack_le(&dev->fo_quit, &byte_arr[30]);
  fh101rf_fdd_exit_cond_pack_le(&dev->fdd_exit_cond, &byte_arr[31]);
  fh101rf_irq_select_pack_le(&dev->irq_select, &byte_arr[32]);
  fh101rf_irq_status_pack_le(&dev->irq_status, &byte_arr[33]);
  fh101rf_irq_clr_pack_le(&dev->irq_clr, &byte_arr[34]);
  fh101rf_irq_set_pack_le(&dev->irq_set, &byte_arr[35]);
  fh101rf_id_hi_pack_le(&dev->id_hi, &byte_arr[36]);
  fh101rf_id_lo_pack_le(&dev->id_lo, &byte_arr[37]);
  fh101rf_idm_enable_pack_le(&dev->idm_enable, &byte_arr[38]);
  fh101rf_idm_ctrl_pack_le(&dev->idm_ctrl, &byte_arr[39]);
  fh101rf_idm_clr_pack_le(&dev->idm_clr, &byte_arr[40]);
  fh101rf_idm_band_pack_le(&dev->idm_band, &byte_arr[41]);
  fh101rf_idm_reason_pack_le(&dev->idm_reason, &byte_arr[42]);
  fh101rf_rtc_select_pack_le(&dev->rtc_select, &byte_arr[43]);
  fh101rf_rtc_status_pack_le(&dev->rtc_status, &byte_arr[44]);
  fh101rf_rtc_clr_pack_le(&dev->rtc_clr, &byte_arr[45]);
  fh101rf_rtcsh0_thresh_hi_pack_le(&dev->rtcsh0_thresh_hi, &byte_arr[46]);
  fh101rf_rtcsh0_thresh_lo_pack_le(&dev->rtcsh0_thresh_lo, &byte_arr[47]);
  fh101rf_rtcsh1_thresh_hi_pack_le(&dev->rtcsh1_thresh_hi, &byte_arr[48]);
  fh101rf_rtcsh1_thresh_lo_pack_le(&dev->rtcsh1_thresh_lo, &byte_arr[49]);
  fh101rf_rtclg0_thresh_4_pack_le(&dev->rtclg0_thresh_4, &byte_arr[50]);
  fh101rf_rtclg0_thresh_3_pack_le(&dev->rtclg0_thresh_3, &byte_arr[51]);
  fh101rf_rtclg0_thresh_2_pack_le(&dev->rtclg0_thresh_2, &byte_arr[52]);
  fh101rf_rtclg0_thresh_1_pack_le(&dev->rtclg0_thresh_1, &byte_arr[53]);
  fh101rf_rtclg0_thresh_0_pack_le(&dev->rtclg0_thresh_0, &byte_arr[54]);
  fh101rf_rtclg1_thresh_4_pack_le(&dev->rtclg1_thresh_4, &byte_arr[55]);
  fh101rf_rtclg1_thresh_3_pack_le(&dev->rtclg1_thresh_3, &byte_arr[56]);
  fh101rf_rtclg1_thresh_2_pack_le(&dev->rtclg1_thresh_2, &byte_arr[57]);
  fh101rf_rtclg1_thresh_1_pack_le(&dev->rtclg1_thresh_1, &byte_arr[58]);
  fh101rf_rtclg1_thresh_0_pack_le(&dev->rtclg1_thresh_0, &byte_arr[59]);
  fh101rf_cyclpresc_pack_le(&dev->cyclpresc, &byte_arr[60]);
  fh101rf_cycltop_hi_pack_le(&dev->cycltop_hi, &byte_arr[61]);
  fh101rf_cycltop_lo_pack_le(&dev->cycltop_lo, &byte_arr[62]);
  fh101rf_cntr40_4_pack_le(&dev->cntr40_4, &byte_arr[63]);
  fh101rf_cntr40_3_pack_le(&dev->cntr40_3, &byte_arr[64]);
  fh101rf_cntr40_2_pack_le(&dev->cntr40_2, &byte_arr[65]);
  fh101rf_cntr40_1_pack_le(&dev->cntr40_1, &byte_arr[66]);
  fh101rf_cntr40_0_pack_le(&dev->cntr40_0, &byte_arr[67]);
  fh101rf_cntr40_clr_pack_le(&dev->cntr40_clr, &byte_arr[68]);
  fh101rf_fifo_length_pack_le(&dev->fifo_length, &byte_arr[69]);
  fh101rf_fifo_count_433_pack_le(&dev->fifo_count_433, &byte_arr[70]);
  fh101rf_fifo_count_868_pack_le(&dev->fifo_count_868, &byte_arr[71]);
  fh101rf_fifo_count_2g4_pack_le(&dev->fifo_count_2g4, &byte_arr[72]);
  fh101rf_rx_fifo_5_433_pack_le(&dev->rx_fifo_5_433, &byte_arr[73]);
  fh101rf_rx_fifo_4_433_pack_le(&dev->rx_fifo_4_433, &byte_arr[74]);
  fh101rf_rx_fifo_3_433_pack_le(&dev->rx_fifo_3_433, &byte_arr[75]);
  fh101rf_rx_fifo_2_433_pack_le(&dev->rx_fifo_2_433, &byte_arr[76]);
  fh101rf_rx_fifo_1_433_pack_le(&dev->rx_fifo_1_433, &byte_arr[77]);
  fh101rf_rx_fifo_0_433_pack_le(&dev->rx_fifo_0_433, &byte_arr[78]);
  fh101rf_rx_fifo_5_868_pack_le(&dev->rx_fifo_5_868, &byte_arr[79]);
  fh101rf_rx_fifo_4_868_pack_le(&dev->rx_fifo_4_868, &byte_arr[80]);
  fh101rf_rx_fifo_3_868_pack_le(&dev->rx_fifo_3_868, &byte_arr[81]);
  fh101rf_rx_fifo_2_868_pack_le(&dev->rx_fifo_2_868, &byte_arr[82]);
  fh101rf_rx_fifo_1_868_pack_le(&dev->rx_fifo_1_868, &byte_arr[83]);
  fh101rf_rx_fifo_0_868_pack_le(&dev->rx_fifo_0_868, &byte_arr[84]);
  fh101rf_rx_fifo_5_2g4_pack_le(&dev->rx_fifo_5_2g4, &byte_arr[85]);
  fh101rf_rx_fifo_4_2g4_pack_le(&dev->rx_fifo_4_2g4, &byte_arr[86]);
  fh101rf_rx_fifo_3_2g4_pack_le(&dev->rx_fifo_3_2g4, &byte_arr[87]);
  fh101rf_rx_fifo_2_2g4_pack_le(&dev->rx_fifo_2_2g4, &byte_arr[88]);
  fh101rf_rx_fifo_1_2g4_pack_le(&dev->rx_fifo_1_2g4, &byte_arr[89]);
  fh101rf_rx_fifo_0_2g4_pack_le(&dev->rx_fifo_0_2g4, &byte_arr[90]);
  fh101rf_actual_nfa_433_pack_le(&dev->actual_nfa_433, &byte_arr[91]);
  fh101rf_actual_nfa_868_pack_le(&dev->actual_nfa_868, &byte_arr[92]);
  fh101rf_actual_nfa_2g4_pack_le(&dev->actual_nfa_2g4, &byte_arr[93]);
  fh101rf_actual_bandselect_pack_le(&dev->actual_bandselect, &byte_arr[94]);
  fh101rf_genpurp_1_pack_le(&dev->genpurp_1, &byte_arr[95]);
  fh101rf_xtal_osc_ctrl_pack_le(&dev->xtal_osc_ctrl, &byte_arr[96]);
  fh101rf_ldo_xtal_ctrl_pack_le(&dev->ldo_xtal_ctrl, &byte_arr[97]);
  fh101rf_mux_d_out_sel_pack_le(&dev->mux_d_out_sel, &byte_arr[98]);
  fh101rf_lc_tg_ena_pack_le(&dev->lc_tg_ena, &byte_arr[99]);
  fh101rf_xtal_good_pack_le(&dev->xtal_good, &byte_arr[100]);
  fh101rf_korrel_sv_clear_pack_le(&dev->korrel_sv_clear, &byte_arr[101]);
  fh101rf_version_pack_le(&dev->version, &byte_arr[102]);
}

static inline void fh101rf_pack_be(const struct fh101rf *dev,
                                   uint8_t byte_arr[103]) {
  fh101rf_nfa433_slow_pack_be(&dev->nfa433_slow, &byte_arr[102]);
  fh101rf_nfa433_fast_pack_be(&dev->nfa433_fast, &byte_arr[101]);
  fh101rf_nfa868_slow_pack_be(&dev->nfa868_slow, &byte_arr[100]);
  fh101rf_nfa868_fast_pack_be(&dev->nfa868_fast, &byte_arr[99]);
  fh101rf_nfa2g4_slow_pack_be(&dev->nfa2g4_slow, &byte_arr[98]);
  fh101rf_nfa2g4_fast_pack_be(&dev->nfa2g4_fast, &byte_arr[97]);
  fh101rf_calib_status_pack_be(&dev->calib_status, &byte_arr[96]);
  fh101rf_calib_ctrl_pack_be(&dev->calib_ctrl, &byte_arr[95]);
  fh101rf_n_spg_target_pack_be(&dev->n_spg_target, &byte_arr[94]);
  fh101rf_n_lco_target_433_hi_pack_be(&dev->n_lco_target_433_hi, &byte_arr[93]);
  fh101rf_n_lco_target_433_lo_pack_be(&dev->n_lco_target_433_lo, &byte_arr[92]);
  fh101rf_n_lco_target_868_hi_pack_be(&dev->n_lco_target_868_hi, &byte_arr[91]);
  fh101rf_n_lco_target_868_lo_pack_be(&dev->n_lco_target_868_lo, &byte_arr[90]);
  fh101rf_n_lco_target_2g4_hi_pack_be(&dev->n_lco_target_2g4_hi, &byte_arr[89]);
  fh101rf_n_lco_target_2g4_lo_pack_be(&dev->n_lco_target_2g4_lo, &byte_arr[88]);
  fh101rf_lco_freq_433_hi_pack_be(&dev->lco_freq_433_hi, &byte_arr[87]);
  fh101rf_lco_freq_433_lo_pack_be(&dev->lco_freq_433_lo, &byte_arr[86]);
  fh101rf_lco_freq_868_hi_pack_be(&dev->lco_freq_868_hi, &byte_arr[85]);
  fh101rf_lco_freq_868_lo_pack_be(&dev->lco_freq_868_lo, &byte_arr[84]);
  fh101rf_lco_freq_2g4_hi_pack_be(&dev->lco_freq_2g4_hi, &byte_arr[83]);
  fh101rf_lco_freq_2g4_lo_pack_be(&dev->lco_freq_2g4_lo, &byte_arr[82]);
  fh101rf_d_corner_ctrl_pack_be(&dev->d_corner_ctrl, &byte_arr[81]);
  fh101rf_band_branch_ctrl_pack_be(&dev->band_branch_ctrl, &byte_arr[80]);
  fh101rf_code_select_pack_be(&dev->code_select, &byte_arr[79]);
  fh101rf_korrel_thresh_a_pack_be(&dev->korrel_thresh_a, &byte_arr[78]);
  fh101rf_korrel_thresh_b_pack_be(&dev->korrel_thresh_b, &byte_arr[77]);
  fh101rf_korrel_state_pack_be(&dev->korrel_state, &byte_arr[76]);
  fh101rf_korrel_val_pack_be(&dev->korrel_val, &byte_arr[75]);
  fh101rf_fdd_enable_pack_be(&dev->fdd_enable, &byte_arr[74]);
  fh101rf_fdd_active_pack_be(&dev->fdd_active, &byte_arr[73]);
  fh101rf_fo_quit_pack_be(&dev->fo_quit, &byte_arr[72]);
  fh101rf_fdd_exit_cond_pack_be(&dev->fdd_exit_cond, &byte_arr[71]);
  fh101rf_irq_select_pack_be(&dev->irq_select, &byte_arr[70]);
  fh101rf_irq_status_pack_be(&dev->irq_status, &byte_arr[69]);
  fh101rf_irq_clr_pack_be(&dev->irq_clr, &byte_arr[68]);
  fh101rf_irq_set_pack_be(&dev->irq_set, &byte_arr[67]);
  fh101rf_id_hi_pack_be(&dev->id_hi, &byte_arr[66]);
  fh101rf_id_lo_pack_be(&dev->id_lo, &byte_arr[65]);
  fh101rf_idm_enable_pack_be(&dev->idm_enable, &byte_arr[64]);
  fh101rf_idm_ctrl_pack_be(&dev->idm_ctrl, &byte_arr[63]);
  fh101rf_idm_clr_pack_be(&dev->idm_clr, &byte_arr[62]);
  fh101rf_idm_band_pack_be(&dev->idm_band, &byte_arr[61]);
  fh101rf_idm_reason_pack_be(&dev->idm_reason, &byte_arr[60]);
  fh101rf_rtc_select_pack_be(&dev->rtc_select, &byte_arr[59]);
  fh101rf_rtc_status_pack_be(&dev->rtc_status, &byte_arr[58]);
  fh101rf_rtc_clr_pack_be(&dev->rtc_clr, &byte_arr[57]);
  fh101rf_rtcsh0_thresh_hi_pack_be(&dev->rtcsh0_thresh_hi, &byte_arr[56]);
  fh101rf_rtcsh0_thresh_lo_pack_be(&dev->rtcsh0_thresh_lo, &byte_arr[55]);
  fh101rf_rtcsh1_thresh_hi_pack_be(&dev->rtcsh1_thresh_hi, &byte_arr[54]);
  fh101rf_rtcsh1_thresh_lo_pack_be(&dev->rtcsh1_thresh_lo, &byte_arr[53]);
  fh101rf_rtclg0_thresh_4_pack_be(&dev->rtclg0_thresh_4, &byte_arr[52]);
  fh101rf_rtclg0_thresh_3_pack_be(&dev->rtclg0_thresh_3, &byte_arr[51]);
  fh101rf_rtclg0_thresh_2_pack_be(&dev->rtclg0_thresh_2, &byte_arr[50]);
  fh101rf_rtclg0_thresh_1_pack_be(&dev->rtclg0_thresh_1, &byte_arr[49]);
  fh101rf_rtclg0_thresh_0_pack_be(&dev->rtclg0_thresh_0, &byte_arr[48]);
  fh101rf_rtclg1_thresh_4_pack_be(&dev->rtclg1_thresh_4, &byte_arr[47]);
  fh101rf_rtclg1_thresh_3_pack_be(&dev->rtclg1_thresh_3, &byte_arr[46]);
  fh101rf_rtclg1_thresh_2_pack_be(&dev->rtclg1_thresh_2, &byte_arr[45]);
  fh101rf_rtclg1_thresh_1_pack_be(&dev->rtclg1_thresh_1, &byte_arr[44]);
  fh101rf_rtclg1_thresh_0_pack_be(&dev->rtclg1_thresh_0, &byte_arr[43]);
  fh101rf_cyclpresc_pack_be(&dev->cyclpresc, &byte_arr[42]);
  fh101rf_cycltop_hi_pack_be(&dev->cycltop_hi, &byte_arr[41]);
  fh101rf_cycltop_lo_pack_be(&dev->cycltop_lo, &byte_arr[40]);
  fh101rf_cntr40_4_pack_be(&dev->cntr40_4, &byte_arr[39]);
  fh101rf_cntr40_3_pack_be(&dev->cntr40_3, &byte_arr[38]);
  fh101rf_cntr40_2_pack_be(&dev->cntr40_2, &byte_arr[37]);
  fh101rf_cntr40_1_pack_be(&dev->cntr40_1, &byte_arr[36]);
  fh101rf_cntr40_0_pack_be(&dev->cntr40_0, &byte_arr[35]);
  fh101rf_cntr40_clr_pack_be(&dev->cntr40_clr, &byte_arr[34]);
  fh101rf_fifo_length_pack_be(&dev->fifo_length, &byte_arr[33]);
  fh101rf_fifo_count_433_pack_be(&dev->fifo_count_433, &byte_arr[32]);
  fh101rf_fifo_count_868_pack_be(&dev->fifo_count_868, &byte_arr[31]);
  fh101rf_fifo_count_2g4_pack_be(&dev->fifo_count_2g4, &byte_arr[30]);
  fh101rf_rx_fifo_5_433_pack_be(&dev->rx_fifo_5_433, &byte_arr[29]);
  fh101rf_rx_fifo_4_433_pack_be(&dev->rx_fifo_4_433, &byte_arr[28]);
  fh101rf_rx_fifo_3_433_pack_be(&dev->rx_fifo_3_433, &byte_arr[27]);
  fh101rf_rx_fifo_2_433_pack_be(&dev->rx_fifo_2_433, &byte_arr[26]);
  fh101rf_rx_fifo_1_433_pack_be(&dev->rx_fifo_1_433, &byte_arr[25]);
  fh101rf_rx_fifo_0_433_pack_be(&dev->rx_fifo_0_433, &byte_arr[24]);
  fh101rf_rx_fifo_5_868_pack_be(&dev->rx_fifo_5_868, &byte_arr[23]);
  fh101rf_rx_fifo_4_868_pack_be(&dev->rx_fifo_4_868, &byte_arr[22]);
  fh101rf_rx_fifo_3_868_pack_be(&dev->rx_fifo_3_868, &byte_arr[21]);
  fh101rf_rx_fifo_2_868_pack_be(&dev->rx_fifo_2_868, &byte_arr[20]);
  fh101rf_rx_fifo_1_868_pack_be(&dev->rx_fifo_1_868, &byte_arr[19]);
  fh101rf_rx_fifo_0_868_pack_be(&dev->rx_fifo_0_868, &byte_arr[18]);
  fh101rf_rx_fifo_5_2g4_pack_be(&dev->rx_fifo_5_2g4, &byte_arr[17]);
  fh101rf_rx_fifo_4_2g4_pack_be(&dev->rx_fifo_4_2g4, &byte_arr[16]);
  fh101rf_rx_fifo_3_2g4_pack_be(&dev->rx_fifo_3_2g4, &byte_arr[15]);
  fh101rf_rx_fifo_2_2g4_pack_be(&dev->rx_fifo_2_2g4, &byte_arr[14]);
  fh101rf_rx_fifo_1_2g4_pack_be(&dev->rx_fifo_1_2g4, &byte_arr[13]);
  fh101rf_rx_fifo_0_2g4_pack_be(&dev->rx_fifo_0_2g4, &byte_arr[12]);
  fh101rf_actual_nfa_433_pack_be(&dev->actual_nfa_433, &byte_arr[11]);
  fh101rf_actual_nfa_868_pack_be(&dev->actual_nfa_868, &byte_arr[10]);
  fh101rf_actual_nfa_2g4_pack_be(&dev->actual_nfa_2g4, &byte_arr[9]);
  fh101rf_actual_bandselect_pack_be(&dev->actual_bandselect, &byte_arr[8]);
  fh101rf_genpurp_1_pack_be(&dev->genpurp_1, &byte_arr[7]);
  fh101rf_xtal_osc_ctrl_pack_be(&dev->xtal_osc_ctrl, &byte_arr[6]);
  fh101rf_ldo_xtal_ctrl_pack_be(&dev->ldo_xtal_ctrl, &byte_arr[5]);
  fh101rf_mux_d_out_sel_pack_be(&dev->mux_d_out_sel, &byte_arr[4]);
  fh101rf_lc_tg_ena_pack_be(&dev->lc_tg_ena, &byte_arr[3]);
  fh101rf_xtal_good_pack_be(&dev->xtal_good, &byte_arr[2]);
  fh101rf_korrel_sv_clear_pack_be(&dev->korrel_sv_clear, &byte_arr[1]);
  fh101rf_version_pack_be(&dev->version, &byte_arr[0]);
}

#endif // FH101RF_H
