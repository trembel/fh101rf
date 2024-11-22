use crate::registers::ToBytes;
use crate::registers::*;

#[derive(Default, Debug)]
pub struct Fh101rfConfig {
    pub nfa433_slow: Nfa433Slow,
    pub nfa433_fast: Nfa433Fast,
    pub nfa868_slow: Nfa868Slow,
    pub nfa868_fast: Nfa868Fast,
    pub nfa2g4_slow: Nfa2g4Slow,
    pub nfa2g4_fast: Nfa2g4Fast,
    pub calib_status: CalibStatus,
    pub calib_ctrl: CalibCtrl,
    pub n_spg_target: NSpgTarget,
    pub n_lco_target_433_hi: NLcoTarget433Hi,
    pub n_lco_target_433_lo: NLcoTarget433Lo,
    pub n_lco_target_868_hi: NLcoTarget868Hi,
    pub n_lco_target_868_lo: NLcoTarget868Lo,
    pub n_lco_target_2g4_hi: NLcoTarget2g4Hi,
    pub n_lco_target_2g4_lo: NLcoTarget2g4Lo,
    pub lco_freq_433_hi: LcoFreq433Hi,
    pub lco_freq_433_lo: LcoFreq433Lo,
    pub lco_freq_868_hi: LcoFreq868Hi,
    pub lco_freq_868_lo: LcoFreq868Lo,
    pub lco_freq_2g4_hi: LcoFreq2g4Hi,
    pub lco_freq_2g4_lo: LcoFreq2g4Lo,
    pub d_corner_ctrl: DCornerCtrl,
    pub band_branch_ctrl: BandBranchCtrl,
    pub code_select: CodeSelect,
    pub korrel_thresh_a: KorrelThreshA,
    pub korrel_thresh_b: KorrelThreshB,
    //pub korrel_state: KorrelState,
    pub korrel_val: KorrelVal,
    pub fdd_enable: FddEnable,
    pub fdd_active: FddActive,
    pub fo_quit: FoQuit,
    pub fdd_exit_cond: FddExitCond,
    pub irq_select: IrqSelect,
    pub irq_status: IrqStatus,
    pub irq_clr: IrqClr,
    pub irq_set: IrqSet,
    pub id_hi: IdHi,
    pub id_lo: IdLo,
    pub idm_enable: IdmEnable,
    pub idm_ctrl: IdmCtrl,
    pub idm_clr: IdmClr,
    //pub idm_band: IdmBand,
    pub idm_reason: IdmReason,
    pub rtc_select: RtcSelect,
    pub rtc_status: RtcStatus,
    pub rtc_clr: RtcClr,
    pub rtcsh0_thresh_hi: Rtcsh0ThreshHi,
    pub rtcsh0_thresh_lo: Rtcsh0ThreshLo,
    pub rtcsh1_thresh_hi: Rtcsh1ThreshHi,
    pub rtcsh1_thresh_lo: Rtcsh1ThreshLo,
    pub rtclg0_thresh_4: Rtclg0Thresh4,
    pub rtclg0_thresh_3: Rtclg0Thresh3,
    pub rtclg0_thresh_2: Rtclg0Thresh2,
    pub rtclg0_thresh_1: Rtclg0Thresh1,
    pub rtclg0_thresh_0: Rtclg0Thresh0,
    pub rtclg1_thresh_4: Rtclg1Thresh4,
    pub rtclg1_thresh_3: Rtclg1Thresh3,
    pub rtclg1_thresh_2: Rtclg1Thresh2,
    pub rtclg1_thresh_1: Rtclg1Thresh1,
    pub rtclg1_thresh_0: Rtclg1Thresh0,
    pub cyclpresc: Cyclpresc,
    pub cycltop_hi: CycltopHi,
    pub cycltop_lo: CycltopLo,
    pub cntr40_4: Cntr404,
    pub cntr40_3: Cntr403,
    pub cntr40_2: Cntr402,
    pub cntr40_1: Cntr401,
    pub cntr40_0: Cntr400,
    pub cntr40_clr: Cntr40Clr,
    pub fifo_length: FifoLength,
    pub fifo_count_433: FifoCount433,
    pub fifo_count_868: FifoCount868,
    pub fifo_count_2g4: FifoCount2g4,
    pub rx_fifo_5_433: RxFifo5433,
    pub rx_fifo_4_433: RxFifo4433,
    pub rx_fifo_3_433: RxFifo3433,
    pub rx_fifo_2_433: RxFifo2433,
    pub rx_fifo_1_433: RxFifo1433,
    pub rx_fifo_0_433: RxFifo0433,
    pub rx_fifo_5_868: RxFifo5868,
    pub rx_fifo_4_868: RxFifo4868,
    pub rx_fifo_3_868: RxFifo3868,
    pub rx_fifo_2_868: RxFifo2868,
    pub rx_fifo_1_868: RxFifo1868,
    pub rx_fifo_0_868: RxFifo0868,
    pub rx_fifo_5_2g4: RxFifo52g4,
    pub rx_fifo_4_2g4: RxFifo42g4,
    pub rx_fifo_3_2g4: RxFifo32g4,
    pub rx_fifo_2_2g4: RxFifo22g4,
    pub rx_fifo_1_2g4: RxFifo12g4,
    pub rx_fifo_0_2g4: RxFifo02g4,
    pub actual_nfa_433: ActualNfa433,
    pub actual_nfa_868: ActualNfa868,
    pub actual_nfa_2g4: ActualNfa2g4,
    pub actual_bandselect: ActualBandselect,
    pub genpurp_1: Genpurp1,
    pub xtal_osc_ctrl: XtalOscCtrl,
    pub ldo_xtal_ctrl: LdoXtalCtrl,
    pub mux_d_out_sel: MuxDOutSel,
    pub lc_tg_ena: LcTgEna,
    pub xtal_good: XtalGood,
    pub comp_thresh_w: CompThreshW,
    pub korrel_sv_clear: KorrelSvClear,
    pub version: Version,
}

impl ToBytes<104> for Fh101rfConfig {
    fn to_le_bytes(&self) -> [u8; 104] {
        let mut byte_arr: [u8; 104] = [0; 104];

        byte_arr[0] = self.nfa433_slow.to_le_bytes()[0];
        byte_arr[1] = self.nfa433_fast.to_le_bytes()[0];
        byte_arr[2] = self.nfa868_slow.to_le_bytes()[0];
        byte_arr[3] = self.nfa868_fast.to_le_bytes()[0];
        byte_arr[4] = self.nfa2g4_slow.to_le_bytes()[0];
        byte_arr[5] = self.nfa2g4_fast.to_le_bytes()[0];
        byte_arr[6] = self.calib_status.to_le_bytes()[0];
        byte_arr[7] = self.calib_ctrl.to_le_bytes()[0];
        byte_arr[8] = self.n_spg_target.to_le_bytes()[0];
        byte_arr[9] = self.n_lco_target_433_hi.to_le_bytes()[0];
        byte_arr[10] = self.n_lco_target_433_lo.to_le_bytes()[0];
        byte_arr[11] = self.n_lco_target_868_hi.to_le_bytes()[0];
        byte_arr[12] = self.n_lco_target_868_lo.to_le_bytes()[0];
        byte_arr[13] = self.n_lco_target_2g4_hi.to_le_bytes()[0];
        byte_arr[14] = self.n_lco_target_2g4_lo.to_le_bytes()[0];
        byte_arr[15] = self.lco_freq_433_hi.to_le_bytes()[0];
        byte_arr[16] = self.lco_freq_433_lo.to_le_bytes()[0];
        byte_arr[17] = self.lco_freq_868_hi.to_le_bytes()[0];
        byte_arr[18] = self.lco_freq_868_lo.to_le_bytes()[0];
        byte_arr[19] = self.lco_freq_2g4_hi.to_le_bytes()[0];
        byte_arr[20] = self.lco_freq_2g4_lo.to_le_bytes()[0];
        byte_arr[21] = self.d_corner_ctrl.to_le_bytes()[0];
        byte_arr[22] = self.band_branch_ctrl.to_le_bytes()[0];
        byte_arr[23] = self.code_select.to_le_bytes()[0];
        byte_arr[24] = self.korrel_thresh_a.to_le_bytes()[0];
        byte_arr[25] = self.korrel_thresh_b.to_le_bytes()[0];
        //byte_arr[26] = self.korrel_state.to_le_bytes()[0];
        byte_arr[27] = self.korrel_val.to_le_bytes()[0];
        byte_arr[28] = self.fdd_enable.to_le_bytes()[0];
        byte_arr[29] = self.fdd_active.to_le_bytes()[0];
        byte_arr[30] = self.fo_quit.to_le_bytes()[0];
        byte_arr[31] = self.fdd_exit_cond.to_le_bytes()[0];
        byte_arr[32] = self.irq_select.to_le_bytes()[0];
        byte_arr[33] = self.irq_status.to_le_bytes()[0];
        byte_arr[34] = self.irq_clr.to_le_bytes()[0];
        byte_arr[35] = self.irq_set.to_le_bytes()[0];
        byte_arr[36] = self.id_hi.to_le_bytes()[0];
        byte_arr[37] = self.id_lo.to_le_bytes()[0];
        byte_arr[38] = self.idm_enable.to_le_bytes()[0];
        byte_arr[39] = self.idm_ctrl.to_le_bytes()[0];
        byte_arr[40] = self.idm_clr.to_le_bytes()[0];
        //byte_arr[41] = self.idm_band.to_le_bytes()[0];
        byte_arr[42] = self.idm_reason.to_le_bytes()[0];
        byte_arr[43] = self.rtc_select.to_le_bytes()[0];
        byte_arr[44] = self.rtc_status.to_le_bytes()[0];
        byte_arr[45] = self.rtc_clr.to_le_bytes()[0];
        byte_arr[46] = self.rtcsh0_thresh_hi.to_le_bytes()[0];
        byte_arr[47] = self.rtcsh0_thresh_lo.to_le_bytes()[0];
        byte_arr[48] = self.rtcsh1_thresh_hi.to_le_bytes()[0];
        byte_arr[49] = self.rtcsh1_thresh_lo.to_le_bytes()[0];
        byte_arr[50] = self.rtclg0_thresh_4.to_le_bytes()[0];
        byte_arr[51] = self.rtclg0_thresh_3.to_le_bytes()[0];
        byte_arr[52] = self.rtclg0_thresh_2.to_le_bytes()[0];
        byte_arr[53] = self.rtclg0_thresh_1.to_le_bytes()[0];
        byte_arr[54] = self.rtclg0_thresh_0.to_le_bytes()[0];
        byte_arr[55] = self.rtclg1_thresh_4.to_le_bytes()[0];
        byte_arr[56] = self.rtclg1_thresh_3.to_le_bytes()[0];
        byte_arr[57] = self.rtclg1_thresh_2.to_le_bytes()[0];
        byte_arr[58] = self.rtclg1_thresh_1.to_le_bytes()[0];
        byte_arr[59] = self.rtclg1_thresh_0.to_le_bytes()[0];
        byte_arr[60] = self.cyclpresc.to_le_bytes()[0];
        byte_arr[61] = self.cycltop_hi.to_le_bytes()[0];
        byte_arr[62] = self.cycltop_lo.to_le_bytes()[0];
        byte_arr[63] = self.cntr40_4.to_le_bytes()[0];
        byte_arr[64] = self.cntr40_3.to_le_bytes()[0];
        byte_arr[65] = self.cntr40_2.to_le_bytes()[0];
        byte_arr[66] = self.cntr40_1.to_le_bytes()[0];
        byte_arr[67] = self.cntr40_0.to_le_bytes()[0];
        byte_arr[68] = self.cntr40_clr.to_le_bytes()[0];
        byte_arr[69] = self.fifo_length.to_le_bytes()[0];
        byte_arr[70] = self.fifo_count_433.to_le_bytes()[0];
        byte_arr[71] = self.fifo_count_868.to_le_bytes()[0];
        byte_arr[72] = self.fifo_count_2g4.to_le_bytes()[0];
        byte_arr[73] = self.rx_fifo_5_433.to_le_bytes()[0];
        byte_arr[74] = self.rx_fifo_4_433.to_le_bytes()[0];
        byte_arr[75] = self.rx_fifo_3_433.to_le_bytes()[0];
        byte_arr[76] = self.rx_fifo_2_433.to_le_bytes()[0];
        byte_arr[77] = self.rx_fifo_1_433.to_le_bytes()[0];
        byte_arr[78] = self.rx_fifo_0_433.to_le_bytes()[0];
        byte_arr[79] = self.rx_fifo_5_868.to_le_bytes()[0];
        byte_arr[80] = self.rx_fifo_4_868.to_le_bytes()[0];
        byte_arr[81] = self.rx_fifo_3_868.to_le_bytes()[0];
        byte_arr[82] = self.rx_fifo_2_868.to_le_bytes()[0];
        byte_arr[83] = self.rx_fifo_1_868.to_le_bytes()[0];
        byte_arr[84] = self.rx_fifo_0_868.to_le_bytes()[0];
        byte_arr[85] = self.rx_fifo_5_2g4.to_le_bytes()[0];
        byte_arr[86] = self.rx_fifo_4_2g4.to_le_bytes()[0];
        byte_arr[87] = self.rx_fifo_3_2g4.to_le_bytes()[0];
        byte_arr[88] = self.rx_fifo_2_2g4.to_le_bytes()[0];
        byte_arr[89] = self.rx_fifo_1_2g4.to_le_bytes()[0];
        byte_arr[90] = self.rx_fifo_0_2g4.to_le_bytes()[0];
        byte_arr[91] = self.actual_nfa_433.to_le_bytes()[0];
        byte_arr[92] = self.actual_nfa_868.to_le_bytes()[0];
        byte_arr[93] = self.actual_nfa_2g4.to_le_bytes()[0];
        byte_arr[94] = self.actual_bandselect.to_le_bytes()[0];
        byte_arr[95] = self.genpurp_1.to_le_bytes()[0];
        byte_arr[96] = self.xtal_osc_ctrl.to_le_bytes()[0];
        byte_arr[97] = self.ldo_xtal_ctrl.to_le_bytes()[0];
        byte_arr[98] = self.mux_d_out_sel.to_le_bytes()[0];
        byte_arr[99] = self.lc_tg_ena.to_le_bytes()[0];
        byte_arr[100] = self.xtal_good.to_le_bytes()[0];
        byte_arr[101] = self.comp_thresh_w.to_le_bytes()[0];
        byte_arr[101] = self.korrel_sv_clear.to_le_bytes()[0];
        byte_arr[102] = self.version.to_le_bytes()[0];

        byte_arr
    }

    fn to_be_bytes(&self) -> [u8; 104] {
        let mut byte_arr: [u8; 104] = [0; 104];
        byte_arr[103] = self.nfa433_slow.to_be_bytes()[0];
        byte_arr[102] = self.nfa433_fast.to_be_bytes()[0];
        byte_arr[101] = self.nfa868_slow.to_be_bytes()[0];
        byte_arr[100] = self.nfa868_fast.to_be_bytes()[0];
        byte_arr[99] = self.nfa2g4_slow.to_be_bytes()[0];
        byte_arr[98] = self.nfa2g4_fast.to_be_bytes()[0];
        byte_arr[97] = self.calib_status.to_be_bytes()[0];
        byte_arr[96] = self.calib_ctrl.to_be_bytes()[0];
        byte_arr[95] = self.n_spg_target.to_be_bytes()[0];
        byte_arr[94] = self.n_lco_target_433_hi.to_be_bytes()[0];
        byte_arr[93] = self.n_lco_target_433_lo.to_be_bytes()[0];
        byte_arr[92] = self.n_lco_target_868_hi.to_be_bytes()[0];
        byte_arr[91] = self.n_lco_target_868_lo.to_be_bytes()[0];
        byte_arr[90] = self.n_lco_target_2g4_hi.to_be_bytes()[0];
        byte_arr[89] = self.n_lco_target_2g4_lo.to_be_bytes()[0];
        byte_arr[88] = self.lco_freq_433_hi.to_be_bytes()[0];
        byte_arr[87] = self.lco_freq_433_lo.to_be_bytes()[0];
        byte_arr[86] = self.lco_freq_868_hi.to_be_bytes()[0];
        byte_arr[85] = self.lco_freq_868_lo.to_be_bytes()[0];
        byte_arr[84] = self.lco_freq_2g4_hi.to_be_bytes()[0];
        byte_arr[83] = self.lco_freq_2g4_lo.to_be_bytes()[0];
        byte_arr[82] = self.d_corner_ctrl.to_be_bytes()[0];
        byte_arr[81] = self.band_branch_ctrl.to_be_bytes()[0];
        byte_arr[80] = self.code_select.to_be_bytes()[0];
        byte_arr[79] = self.korrel_thresh_a.to_be_bytes()[0];
        byte_arr[78] = self.korrel_thresh_b.to_be_bytes()[0];
        //byte_arr[77] = self.korrel_state.to_be_bytes()[0];
        byte_arr[76] = self.korrel_val.to_be_bytes()[0];
        byte_arr[75] = self.fdd_enable.to_be_bytes()[0];
        byte_arr[74] = self.fdd_active.to_be_bytes()[0];
        byte_arr[73] = self.fo_quit.to_be_bytes()[0];
        byte_arr[72] = self.fdd_exit_cond.to_be_bytes()[0];
        byte_arr[71] = self.irq_select.to_be_bytes()[0];
        byte_arr[70] = self.irq_status.to_be_bytes()[0];
        byte_arr[69] = self.irq_clr.to_be_bytes()[0];
        byte_arr[68] = self.irq_set.to_be_bytes()[0];
        byte_arr[67] = self.id_hi.to_be_bytes()[0];
        byte_arr[66] = self.id_lo.to_be_bytes()[0];
        byte_arr[65] = self.idm_enable.to_be_bytes()[0];
        byte_arr[64] = self.idm_ctrl.to_be_bytes()[0];
        byte_arr[63] = self.idm_clr.to_be_bytes()[0];
        //byte_arr[62] = self.idm_band.to_be_bytes()[0];
        byte_arr[61] = self.idm_reason.to_be_bytes()[0];
        byte_arr[60] = self.rtc_select.to_be_bytes()[0];
        byte_arr[59] = self.rtc_status.to_be_bytes()[0];
        byte_arr[58] = self.rtc_clr.to_be_bytes()[0];
        byte_arr[57] = self.rtcsh0_thresh_hi.to_be_bytes()[0];
        byte_arr[56] = self.rtcsh0_thresh_lo.to_be_bytes()[0];
        byte_arr[55] = self.rtcsh1_thresh_hi.to_be_bytes()[0];
        byte_arr[54] = self.rtcsh1_thresh_lo.to_be_bytes()[0];
        byte_arr[53] = self.rtclg0_thresh_4.to_be_bytes()[0];
        byte_arr[52] = self.rtclg0_thresh_3.to_be_bytes()[0];
        byte_arr[51] = self.rtclg0_thresh_2.to_be_bytes()[0];
        byte_arr[50] = self.rtclg0_thresh_1.to_be_bytes()[0];
        byte_arr[49] = self.rtclg0_thresh_0.to_be_bytes()[0];
        byte_arr[48] = self.rtclg1_thresh_4.to_be_bytes()[0];
        byte_arr[47] = self.rtclg1_thresh_3.to_be_bytes()[0];
        byte_arr[46] = self.rtclg1_thresh_2.to_be_bytes()[0];
        byte_arr[45] = self.rtclg1_thresh_1.to_be_bytes()[0];
        byte_arr[44] = self.rtclg1_thresh_0.to_be_bytes()[0];
        byte_arr[43] = self.cyclpresc.to_be_bytes()[0];
        byte_arr[42] = self.cycltop_hi.to_be_bytes()[0];
        byte_arr[41] = self.cycltop_lo.to_be_bytes()[0];
        byte_arr[40] = self.cntr40_4.to_be_bytes()[0];
        byte_arr[39] = self.cntr40_3.to_be_bytes()[0];
        byte_arr[38] = self.cntr40_2.to_be_bytes()[0];
        byte_arr[37] = self.cntr40_1.to_be_bytes()[0];
        byte_arr[36] = self.cntr40_0.to_be_bytes()[0];
        byte_arr[35] = self.cntr40_clr.to_be_bytes()[0];
        byte_arr[34] = self.fifo_length.to_be_bytes()[0];
        byte_arr[33] = self.fifo_count_433.to_be_bytes()[0];
        byte_arr[32] = self.fifo_count_868.to_be_bytes()[0];
        byte_arr[31] = self.fifo_count_2g4.to_be_bytes()[0];
        byte_arr[30] = self.rx_fifo_5_433.to_be_bytes()[0];
        byte_arr[29] = self.rx_fifo_4_433.to_be_bytes()[0];
        byte_arr[28] = self.rx_fifo_3_433.to_be_bytes()[0];
        byte_arr[27] = self.rx_fifo_2_433.to_be_bytes()[0];
        byte_arr[26] = self.rx_fifo_1_433.to_be_bytes()[0];
        byte_arr[25] = self.rx_fifo_0_433.to_be_bytes()[0];
        byte_arr[24] = self.rx_fifo_5_868.to_be_bytes()[0];
        byte_arr[23] = self.rx_fifo_4_868.to_be_bytes()[0];
        byte_arr[22] = self.rx_fifo_3_868.to_be_bytes()[0];
        byte_arr[21] = self.rx_fifo_2_868.to_be_bytes()[0];
        byte_arr[20] = self.rx_fifo_1_868.to_be_bytes()[0];
        byte_arr[19] = self.rx_fifo_0_868.to_be_bytes()[0];
        byte_arr[18] = self.rx_fifo_5_2g4.to_be_bytes()[0];
        byte_arr[17] = self.rx_fifo_4_2g4.to_be_bytes()[0];
        byte_arr[16] = self.rx_fifo_3_2g4.to_be_bytes()[0];
        byte_arr[15] = self.rx_fifo_2_2g4.to_be_bytes()[0];
        byte_arr[14] = self.rx_fifo_1_2g4.to_be_bytes()[0];
        byte_arr[13] = self.rx_fifo_0_2g4.to_be_bytes()[0];
        byte_arr[12] = self.actual_nfa_433.to_be_bytes()[0];
        byte_arr[11] = self.actual_nfa_868.to_be_bytes()[0];
        byte_arr[10] = self.actual_nfa_2g4.to_be_bytes()[0];
        byte_arr[9] = self.actual_bandselect.to_be_bytes()[0];
        byte_arr[8] = self.genpurp_1.to_be_bytes()[0];
        byte_arr[7] = self.xtal_osc_ctrl.to_be_bytes()[0];
        byte_arr[6] = self.ldo_xtal_ctrl.to_be_bytes()[0];
        byte_arr[5] = self.mux_d_out_sel.to_be_bytes()[0];
        byte_arr[4] = self.lc_tg_ena.to_be_bytes()[0];
        byte_arr[3] = self.xtal_good.to_be_bytes()[0];
        byte_arr[2] = self.comp_thresh_w.to_le_bytes()[0];
        byte_arr[1] = self.korrel_sv_clear.to_be_bytes()[0];
        byte_arr[0] = self.version.to_be_bytes()[0];

        byte_arr
    }
}

impl TryFromBytes<104> for Fh101rfConfig {
    type Error = FromBytesError;
    fn try_from_le_bytes(val: &[u8; 104]) -> Result<Self, Self::Error> {
        Ok(Self {
            nfa433_slow: Nfa433Slow::from_le_bytes(val[0..0].try_into().unwrap()),
            nfa433_fast: Nfa433Fast::from_le_bytes(val[1..1].try_into().unwrap()),
            nfa868_slow: Nfa868Slow::from_le_bytes(val[2..2].try_into().unwrap()),
            nfa868_fast: Nfa868Fast::from_le_bytes(val[3..3].try_into().unwrap()),
            nfa2g4_slow: Nfa2g4Slow::from_le_bytes(val[4..4].try_into().unwrap()),
            nfa2g4_fast: Nfa2g4Fast::from_le_bytes(val[5..5].try_into().unwrap()),
            calib_status: CalibStatus::from_le_bytes(val[6..6].try_into().unwrap()),
            calib_ctrl: CalibCtrl::from_le_bytes(val[7..7].try_into().unwrap()),
            n_spg_target: NSpgTarget::from_le_bytes(val[8..8].try_into().unwrap()),
            n_lco_target_433_hi: NLcoTarget433Hi::from_le_bytes(val[9..9].try_into().unwrap()),
            n_lco_target_433_lo: NLcoTarget433Lo::from_le_bytes(val[10..10].try_into().unwrap()),
            n_lco_target_868_hi: NLcoTarget868Hi::from_le_bytes(val[11..11].try_into().unwrap()),
            n_lco_target_868_lo: NLcoTarget868Lo::from_le_bytes(val[12..12].try_into().unwrap()),
            n_lco_target_2g4_hi: NLcoTarget2g4Hi::from_le_bytes(val[13..13].try_into().unwrap()),
            n_lco_target_2g4_lo: NLcoTarget2g4Lo::from_le_bytes(val[14..14].try_into().unwrap()),
            lco_freq_433_hi: LcoFreq433Hi::from_le_bytes(val[15..15].try_into().unwrap()),
            lco_freq_433_lo: LcoFreq433Lo::from_le_bytes(val[16..16].try_into().unwrap()),
            lco_freq_868_hi: LcoFreq868Hi::from_le_bytes(val[17..17].try_into().unwrap()),
            lco_freq_868_lo: LcoFreq868Lo::from_le_bytes(val[18..18].try_into().unwrap()),
            lco_freq_2g4_hi: LcoFreq2g4Hi::from_le_bytes(val[19..19].try_into().unwrap()),
            lco_freq_2g4_lo: LcoFreq2g4Lo::from_le_bytes(val[20..20].try_into().unwrap()),
            d_corner_ctrl: DCornerCtrl::from_le_bytes(val[21..21].try_into().unwrap()),
            band_branch_ctrl: BandBranchCtrl::from_le_bytes(val[22..22].try_into().unwrap()),
            code_select: CodeSelect::from_le_bytes(val[23..23].try_into().unwrap()),
            korrel_thresh_a: KorrelThreshA::from_le_bytes(val[24..24].try_into().unwrap()),
            korrel_thresh_b: KorrelThreshB::from_le_bytes(val[25..25].try_into().unwrap()),
            //korrel_state: KorrelState::try_from_le_bytes(val[26..26].try_into().unwrap())?,
            korrel_val: KorrelVal::from_le_bytes(val[27..27].try_into().unwrap()),
            fdd_enable: FddEnable::from_le_bytes(val[28..28].try_into().unwrap()),
            fdd_active: FddActive::from_le_bytes(val[29..29].try_into().unwrap()),
            fo_quit: FoQuit::from_le_bytes(val[30..30].try_into().unwrap()),
            fdd_exit_cond: FddExitCond::from_le_bytes(val[31..31].try_into().unwrap()),
            irq_select: IrqSelect::from_le_bytes(val[32..32].try_into().unwrap()),
            irq_status: IrqStatus::from_le_bytes(val[33..33].try_into().unwrap()),
            irq_clr: IrqClr::from_le_bytes(val[34..34].try_into().unwrap()),
            irq_set: IrqSet::from_le_bytes(val[35..35].try_into().unwrap()),
            id_hi: IdHi::from_le_bytes(val[36..36].try_into().unwrap()),
            id_lo: IdLo::from_le_bytes(val[37..37].try_into().unwrap()),
            idm_enable: IdmEnable::from_le_bytes(val[38..38].try_into().unwrap()),
            idm_ctrl: IdmCtrl::from_le_bytes(val[39..39].try_into().unwrap()),
            idm_clr: IdmClr::from_le_bytes(val[40..40].try_into().unwrap()),
            //idm_band: IdmBand::try_from_le_bytes(val[41..41].try_into().unwrap())?,
            idm_reason: IdmReason::from_le_bytes(val[42..42].try_into().unwrap()),
            rtc_select: RtcSelect::from_le_bytes(val[43..43].try_into().unwrap()),
            rtc_status: RtcStatus::from_le_bytes(val[44..44].try_into().unwrap()),
            rtc_clr: RtcClr::from_le_bytes(val[45..45].try_into().unwrap()),
            rtcsh0_thresh_hi: Rtcsh0ThreshHi::from_le_bytes(val[46..46].try_into().unwrap()),
            rtcsh0_thresh_lo: Rtcsh0ThreshLo::from_le_bytes(val[47..47].try_into().unwrap()),
            rtcsh1_thresh_hi: Rtcsh1ThreshHi::from_le_bytes(val[48..48].try_into().unwrap()),
            rtcsh1_thresh_lo: Rtcsh1ThreshLo::from_le_bytes(val[49..49].try_into().unwrap()),
            rtclg0_thresh_4: Rtclg0Thresh4::from_le_bytes(val[50..50].try_into().unwrap()),
            rtclg0_thresh_3: Rtclg0Thresh3::from_le_bytes(val[51..51].try_into().unwrap()),
            rtclg0_thresh_2: Rtclg0Thresh2::from_le_bytes(val[52..52].try_into().unwrap()),
            rtclg0_thresh_1: Rtclg0Thresh1::from_le_bytes(val[53..53].try_into().unwrap()),
            rtclg0_thresh_0: Rtclg0Thresh0::from_le_bytes(val[54..54].try_into().unwrap()),
            rtclg1_thresh_4: Rtclg1Thresh4::from_le_bytes(val[55..55].try_into().unwrap()),
            rtclg1_thresh_3: Rtclg1Thresh3::from_le_bytes(val[56..56].try_into().unwrap()),
            rtclg1_thresh_2: Rtclg1Thresh2::from_le_bytes(val[57..57].try_into().unwrap()),
            rtclg1_thresh_1: Rtclg1Thresh1::from_le_bytes(val[58..58].try_into().unwrap()),
            rtclg1_thresh_0: Rtclg1Thresh0::from_le_bytes(val[59..59].try_into().unwrap()),
            cyclpresc: Cyclpresc::from_le_bytes(val[60..60].try_into().unwrap()),
            cycltop_hi: CycltopHi::from_le_bytes(val[61..61].try_into().unwrap()),
            cycltop_lo: CycltopLo::from_le_bytes(val[62..62].try_into().unwrap()),
            cntr40_4: Cntr404::from_le_bytes(val[63..63].try_into().unwrap()),
            cntr40_3: Cntr403::from_le_bytes(val[64..64].try_into().unwrap()),
            cntr40_2: Cntr402::from_le_bytes(val[65..65].try_into().unwrap()),
            cntr40_1: Cntr401::from_le_bytes(val[66..66].try_into().unwrap()),
            cntr40_0: Cntr400::from_le_bytes(val[67..67].try_into().unwrap()),
            cntr40_clr: Cntr40Clr::from_le_bytes(val[68..68].try_into().unwrap()),
            fifo_length: FifoLength::from_le_bytes(val[69..69].try_into().unwrap()),
            fifo_count_433: FifoCount433::from_le_bytes(val[70..70].try_into().unwrap()),
            fifo_count_868: FifoCount868::from_le_bytes(val[71..71].try_into().unwrap()),
            fifo_count_2g4: FifoCount2g4::from_le_bytes(val[72..72].try_into().unwrap()),
            rx_fifo_5_433: RxFifo5433::from_le_bytes(val[73..73].try_into().unwrap()),
            rx_fifo_4_433: RxFifo4433::from_le_bytes(val[74..74].try_into().unwrap()),
            rx_fifo_3_433: RxFifo3433::from_le_bytes(val[75..75].try_into().unwrap()),
            rx_fifo_2_433: RxFifo2433::from_le_bytes(val[76..76].try_into().unwrap()),
            rx_fifo_1_433: RxFifo1433::from_le_bytes(val[77..77].try_into().unwrap()),
            rx_fifo_0_433: RxFifo0433::from_le_bytes(val[78..78].try_into().unwrap()),
            rx_fifo_5_868: RxFifo5868::from_le_bytes(val[79..79].try_into().unwrap()),
            rx_fifo_4_868: RxFifo4868::from_le_bytes(val[80..80].try_into().unwrap()),
            rx_fifo_3_868: RxFifo3868::from_le_bytes(val[81..81].try_into().unwrap()),
            rx_fifo_2_868: RxFifo2868::from_le_bytes(val[82..82].try_into().unwrap()),
            rx_fifo_1_868: RxFifo1868::from_le_bytes(val[83..83].try_into().unwrap()),
            rx_fifo_0_868: RxFifo0868::from_le_bytes(val[84..84].try_into().unwrap()),
            rx_fifo_5_2g4: RxFifo52g4::from_le_bytes(val[85..85].try_into().unwrap()),
            rx_fifo_4_2g4: RxFifo42g4::from_le_bytes(val[86..86].try_into().unwrap()),
            rx_fifo_3_2g4: RxFifo32g4::from_le_bytes(val[87..87].try_into().unwrap()),
            rx_fifo_2_2g4: RxFifo22g4::from_le_bytes(val[88..88].try_into().unwrap()),
            rx_fifo_1_2g4: RxFifo12g4::from_le_bytes(val[89..89].try_into().unwrap()),
            rx_fifo_0_2g4: RxFifo02g4::from_le_bytes(val[90..90].try_into().unwrap()),
            actual_nfa_433: ActualNfa433::from_le_bytes(val[91..91].try_into().unwrap()),
            actual_nfa_868: ActualNfa868::from_le_bytes(val[92..92].try_into().unwrap()),
            actual_nfa_2g4: ActualNfa2g4::from_le_bytes(val[93..93].try_into().unwrap()),
            actual_bandselect: ActualBandselect::from_le_bytes(val[94..94].try_into().unwrap()),
            genpurp_1: Genpurp1::from_le_bytes(val[95..95].try_into().unwrap()),
            xtal_osc_ctrl: XtalOscCtrl::from_le_bytes(val[96..96].try_into().unwrap()),
            ldo_xtal_ctrl: LdoXtalCtrl::from_le_bytes(val[97..97].try_into().unwrap()),
            mux_d_out_sel: MuxDOutSel::try_from_le_bytes(val[98..98].try_into().unwrap())?,
            lc_tg_ena: LcTgEna::from_le_bytes(val[99..99].try_into().unwrap()),
            xtal_good: XtalGood::from_le_bytes(val[100..100].try_into().unwrap()),
            comp_thresh_w: CompThreshW::from_le_bytes(val[101..101].try_into().unwrap()),
            korrel_sv_clear: KorrelSvClear::from_le_bytes(val[102..102].try_into().unwrap()),
            version: Version::from_le_bytes(val[103..103].try_into().unwrap()),
        })
    }

    fn try_from_be_bytes(val: &[u8; 104]) -> Result<Self, Self::Error> {
        Ok(Self {
            nfa433_slow: Nfa433Slow::from_be_bytes(val[103..103].try_into().unwrap()),
            nfa433_fast: Nfa433Fast::from_be_bytes(val[102..102].try_into().unwrap()),
            nfa868_slow: Nfa868Slow::from_be_bytes(val[101..101].try_into().unwrap()),
            nfa868_fast: Nfa868Fast::from_be_bytes(val[100..100].try_into().unwrap()),
            nfa2g4_slow: Nfa2g4Slow::from_be_bytes(val[99..99].try_into().unwrap()),
            nfa2g4_fast: Nfa2g4Fast::from_be_bytes(val[98..98].try_into().unwrap()),
            calib_status: CalibStatus::from_be_bytes(val[97..97].try_into().unwrap()),
            calib_ctrl: CalibCtrl::from_be_bytes(val[96..96].try_into().unwrap()),
            n_spg_target: NSpgTarget::from_be_bytes(val[95..95].try_into().unwrap()),
            n_lco_target_433_hi: NLcoTarget433Hi::from_be_bytes(val[94..94].try_into().unwrap()),
            n_lco_target_433_lo: NLcoTarget433Lo::from_be_bytes(val[93..93].try_into().unwrap()),
            n_lco_target_868_hi: NLcoTarget868Hi::from_be_bytes(val[92..92].try_into().unwrap()),
            n_lco_target_868_lo: NLcoTarget868Lo::from_be_bytes(val[91..91].try_into().unwrap()),
            n_lco_target_2g4_hi: NLcoTarget2g4Hi::from_be_bytes(val[90..90].try_into().unwrap()),
            n_lco_target_2g4_lo: NLcoTarget2g4Lo::from_be_bytes(val[89..89].try_into().unwrap()),
            lco_freq_433_hi: LcoFreq433Hi::from_be_bytes(val[88..88].try_into().unwrap()),
            lco_freq_433_lo: LcoFreq433Lo::from_be_bytes(val[87..87].try_into().unwrap()),
            lco_freq_868_hi: LcoFreq868Hi::from_be_bytes(val[86..86].try_into().unwrap()),
            lco_freq_868_lo: LcoFreq868Lo::from_be_bytes(val[85..85].try_into().unwrap()),
            lco_freq_2g4_hi: LcoFreq2g4Hi::from_be_bytes(val[84..84].try_into().unwrap()),
            lco_freq_2g4_lo: LcoFreq2g4Lo::from_be_bytes(val[83..83].try_into().unwrap()),
            d_corner_ctrl: DCornerCtrl::from_be_bytes(val[82..82].try_into().unwrap()),
            band_branch_ctrl: BandBranchCtrl::from_be_bytes(val[81..81].try_into().unwrap()),
            code_select: CodeSelect::from_be_bytes(val[80..80].try_into().unwrap()),
            korrel_thresh_a: KorrelThreshA::from_be_bytes(val[79..79].try_into().unwrap()),
            korrel_thresh_b: KorrelThreshB::from_be_bytes(val[78..78].try_into().unwrap()),
            //korrel_state: KorrelState::try_from_be_bytes(val[77..77]try_into().unwrap())?,
            korrel_val: KorrelVal::from_be_bytes(val[76..76].try_into().unwrap()),
            fdd_enable: FddEnable::from_be_bytes(val[75..75].try_into().unwrap()),
            fdd_active: FddActive::from_be_bytes(val[74..74].try_into().unwrap()),
            fo_quit: FoQuit::from_be_bytes(val[73..73].try_into().unwrap()),
            fdd_exit_cond: FddExitCond::from_be_bytes(val[72..72].try_into().unwrap()),
            irq_select: IrqSelect::from_be_bytes(val[71..71].try_into().unwrap()),
            irq_status: IrqStatus::from_be_bytes(val[70..70].try_into().unwrap()),
            irq_clr: IrqClr::from_be_bytes(val[69..69].try_into().unwrap()),
            irq_set: IrqSet::from_be_bytes(val[68..68].try_into().unwrap()),
            id_hi: IdHi::from_be_bytes(val[67..67].try_into().unwrap()),
            id_lo: IdLo::from_be_bytes(val[66..66].try_into().unwrap()),
            idm_enable: IdmEnable::from_be_bytes(val[65..65].try_into().unwrap()),
            idm_ctrl: IdmCtrl::from_be_bytes(val[64..64].try_into().unwrap()),
            idm_clr: IdmClr::from_be_bytes(val[63..63].try_into().unwrap()),
            //idm_band: IdmBand::try_from_be_bytes(val[62..62]try_into().unwrap())?,
            idm_reason: IdmReason::from_be_bytes(val[61..61].try_into().unwrap()),
            rtc_select: RtcSelect::from_be_bytes(val[60..60].try_into().unwrap()),
            rtc_status: RtcStatus::from_be_bytes(val[59..59].try_into().unwrap()),
            rtc_clr: RtcClr::from_be_bytes(val[58..58].try_into().unwrap()),
            rtcsh0_thresh_hi: Rtcsh0ThreshHi::from_be_bytes(val[57..57].try_into().unwrap()),
            rtcsh0_thresh_lo: Rtcsh0ThreshLo::from_be_bytes(val[56..56].try_into().unwrap()),
            rtcsh1_thresh_hi: Rtcsh1ThreshHi::from_be_bytes(val[55..55].try_into().unwrap()),
            rtcsh1_thresh_lo: Rtcsh1ThreshLo::from_be_bytes(val[54..54].try_into().unwrap()),
            rtclg0_thresh_4: Rtclg0Thresh4::from_be_bytes(val[53..53].try_into().unwrap()),
            rtclg0_thresh_3: Rtclg0Thresh3::from_be_bytes(val[52..52].try_into().unwrap()),
            rtclg0_thresh_2: Rtclg0Thresh2::from_be_bytes(val[51..51].try_into().unwrap()),
            rtclg0_thresh_1: Rtclg0Thresh1::from_be_bytes(val[50..50].try_into().unwrap()),
            rtclg0_thresh_0: Rtclg0Thresh0::from_be_bytes(val[49..49].try_into().unwrap()),
            rtclg1_thresh_4: Rtclg1Thresh4::from_be_bytes(val[48..48].try_into().unwrap()),
            rtclg1_thresh_3: Rtclg1Thresh3::from_be_bytes(val[47..47].try_into().unwrap()),
            rtclg1_thresh_2: Rtclg1Thresh2::from_be_bytes(val[46..46].try_into().unwrap()),
            rtclg1_thresh_1: Rtclg1Thresh1::from_be_bytes(val[45..45].try_into().unwrap()),
            rtclg1_thresh_0: Rtclg1Thresh0::from_be_bytes(val[44..44].try_into().unwrap()),
            cyclpresc: Cyclpresc::from_be_bytes(val[43..43].try_into().unwrap()),
            cycltop_hi: CycltopHi::from_be_bytes(val[42..42].try_into().unwrap()),
            cycltop_lo: CycltopLo::from_be_bytes(val[41..41].try_into().unwrap()),
            cntr40_4: Cntr404::from_be_bytes(val[40..40].try_into().unwrap()),
            cntr40_3: Cntr403::from_be_bytes(val[39..39].try_into().unwrap()),
            cntr40_2: Cntr402::from_be_bytes(val[38..38].try_into().unwrap()),
            cntr40_1: Cntr401::from_be_bytes(val[37..37].try_into().unwrap()),
            cntr40_0: Cntr400::from_be_bytes(val[36..36].try_into().unwrap()),
            cntr40_clr: Cntr40Clr::from_be_bytes(val[35..35].try_into().unwrap()),
            fifo_length: FifoLength::from_be_bytes(val[34..34].try_into().unwrap()),
            fifo_count_433: FifoCount433::from_be_bytes(val[33..33].try_into().unwrap()),
            fifo_count_868: FifoCount868::from_be_bytes(val[32..32].try_into().unwrap()),
            fifo_count_2g4: FifoCount2g4::from_be_bytes(val[31..31].try_into().unwrap()),
            rx_fifo_5_433: RxFifo5433::from_be_bytes(val[30..30].try_into().unwrap()),
            rx_fifo_4_433: RxFifo4433::from_be_bytes(val[29..29].try_into().unwrap()),
            rx_fifo_3_433: RxFifo3433::from_be_bytes(val[28..28].try_into().unwrap()),
            rx_fifo_2_433: RxFifo2433::from_be_bytes(val[27..27].try_into().unwrap()),
            rx_fifo_1_433: RxFifo1433::from_be_bytes(val[26..26].try_into().unwrap()),
            rx_fifo_0_433: RxFifo0433::from_be_bytes(val[25..25].try_into().unwrap()),
            rx_fifo_5_868: RxFifo5868::from_be_bytes(val[24..24].try_into().unwrap()),
            rx_fifo_4_868: RxFifo4868::from_be_bytes(val[23..23].try_into().unwrap()),
            rx_fifo_3_868: RxFifo3868::from_be_bytes(val[22..22].try_into().unwrap()),
            rx_fifo_2_868: RxFifo2868::from_be_bytes(val[21..21].try_into().unwrap()),
            rx_fifo_1_868: RxFifo1868::from_be_bytes(val[20..20].try_into().unwrap()),
            rx_fifo_0_868: RxFifo0868::from_be_bytes(val[19..19].try_into().unwrap()),
            rx_fifo_5_2g4: RxFifo52g4::from_be_bytes(val[18..18].try_into().unwrap()),
            rx_fifo_4_2g4: RxFifo42g4::from_be_bytes(val[17..17].try_into().unwrap()),
            rx_fifo_3_2g4: RxFifo32g4::from_be_bytes(val[16..16].try_into().unwrap()),
            rx_fifo_2_2g4: RxFifo22g4::from_be_bytes(val[15..15].try_into().unwrap()),
            rx_fifo_1_2g4: RxFifo12g4::from_be_bytes(val[14..14].try_into().unwrap()),
            rx_fifo_0_2g4: RxFifo02g4::from_be_bytes(val[13..13].try_into().unwrap()),
            actual_nfa_433: ActualNfa433::from_be_bytes(val[12..12].try_into().unwrap()),
            actual_nfa_868: ActualNfa868::from_be_bytes(val[11..11].try_into().unwrap()),
            actual_nfa_2g4: ActualNfa2g4::from_be_bytes(val[10..10].try_into().unwrap()),
            actual_bandselect: ActualBandselect::from_be_bytes(val[9..9].try_into().unwrap()),
            genpurp_1: Genpurp1::from_be_bytes(val[8..8].try_into().unwrap()),
            xtal_osc_ctrl: XtalOscCtrl::from_be_bytes(val[7..7].try_into().unwrap()),
            ldo_xtal_ctrl: LdoXtalCtrl::from_be_bytes(val[6..6].try_into().unwrap()),
            mux_d_out_sel: MuxDOutSel::try_from_be_bytes(val[5..5].try_into().unwrap())?,
            lc_tg_ena: LcTgEna::from_be_bytes(val[4..4].try_into().unwrap()),
            xtal_good: XtalGood::from_be_bytes(val[3..3].try_into().unwrap()),
            comp_thresh_w: CompThreshW::from_be_bytes(val[2..2].try_into().unwrap()),
            korrel_sv_clear: KorrelSvClear::from_be_bytes(val[1..1].try_into().unwrap()),
            version: Version::from_be_bytes(val[0..0].try_into().unwrap()),
        })
    }
}
