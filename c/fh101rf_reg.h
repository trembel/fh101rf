// clang-format off
/**
 * @file fh101rf_reg.h
 * @brief FH101RF
 * @note do not edit directly: generated using reginald from ../fh101rf.yaml.
 *
 * Generator: c.funcpack
 *
 * Listing file author: Jonah Imfeld, Silvano Cortesi
 */
#ifndef REGINALD_FH101RF_REG_H
#define REGINALD_FH101RF_REG_H

#include <stdint.h>
#include <stdbool.h>

// =============================================================================
// ==== Shared Enums ===========================================================
// =============================================================================

// ---- BIN_CODE Enum ----------------------------------------------------------

enum fh101rf_bin_code {
  /** @brief mls A */
  FH101RF_BIN_CODE_A = 0x0U,
  /** @brief mls A inv */
  FH101RF_BIN_CODE_A_INV = 0x4U,
  /** @brief m-sequence A */
  FH101RF_BIN_CODE_A_SEQ = 0x6U,
  /** @brief mls B */
  FH101RF_BIN_CODE_B = 0x1U,
  /** @brief mls B inv */
  FH101RF_BIN_CODE_B_INV = 0x5U,
  /** @brief m-sequence B */
  FH101RF_BIN_CODE_B_SEQ = 0x7U,
  /** @brief mls C */
  FH101RF_BIN_CODE_C = 0x2U,
  /** @brief mls D */
  FH101RF_BIN_CODE_D = 0x3U,
  /** @brief 16 ones */
  FH101RF_BIN_CODE_ONE_16 = 0xAU,
  /** @brief 24 ones */
  FH101RF_BIN_CODE_ONE_24 = 0xBU,
  /** @brief 31 ones */
  FH101RF_BIN_CODE_ONE_31 = 0xCU,
  /** @brief 8 ones */
  FH101RF_BIN_CODE_ONE_8 = 0x9U,
  /** @brief 111000 pattern */
  FH101RF_BIN_CODE_OOOZZZ = 0xFU,
  /** @brief 1100 pattern */
  FH101RF_BIN_CODE_OOZZ = 0xEU,
  /** @brief 31 zeros */
  FH101RF_BIN_CODE_ZERO_31 = 0x8U,
  /** @brief 0101 pattern */
  FH101RF_BIN_CODE_ZOZO = 0xDU,
};

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_bin_code.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_BIN_CODE(_VAL_) (                                                         \
  ((_VAL_) <= 0xFU) ? true :                                                                       \
  false )

// ---- EXIT_COND Enum ---------------------------------------------------------

enum fh101rf_exit_cond {
  /** @brief FO_QUIT was set - user forced slow mode. */
  FH101RF_EXIT_COND_FORCE_QUIT = 0x3U,
  /** @brief ID match failed - 16-bit ID did not match. */
  FH101RF_EXIT_COND_ID_FAIL = 0x2U,
  /** @brief RX resetted or FDD is disabled - Initial state. */
  FH101RF_EXIT_COND_NO_REASON = 0x0U,
  /** @brief Timeout - No fast code A or B received. */
  FH101RF_EXIT_COND_TIMEOUT = 0x1U,
};

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_exit_cond.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_EXIT_COND(_VAL_) (                                                        \
  ((_VAL_) <= 0x3U) ? true :                                                                       \
  false )

// ---- FDD_MODE Enum ----------------------------------------------------------

enum fh101rf_fdd_mode {
  /** @brief Fast mode. */
  FH101RF_FDD_MODE_FAST = 0x1U,
  /** @brief Slow mode. */
  FH101RF_FDD_MODE_SLOW = 0x0U,
};

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_fdd_mode.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_FDD_MODE(_VAL_) (                                                         \
  ((_VAL_) <= 0x1U) ? true :                                                                       \
  false )

// ---- FIFO_LEN Enum ----------------------------------------------------------

enum fh101rf_fifo_len {
  /** @brief 16-bit FIFO. */
  FH101RF_FIFO_LEN_BIT16 = 0x0U,
  /** @brief 24-bit FIFO. */
  FH101RF_FIFO_LEN_BIT24 = 0x1U,
  /** @brief 32-bit FIFO. */
  FH101RF_FIFO_LEN_BIT32 = 0x2U,
  /** @brief 40-bit FIFO. */
  FH101RF_FIFO_LEN_BIT40 = 0x3U,
};

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_fifo_len.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_FIFO_LEN(_VAL_) (                                                         \
  ((_VAL_) <= 0x3U) ? true :                                                                       \
  false )

// ---- SAMPLE_RATE Enum -------------------------------------------------------

enum fh101rf_sample_rate {
  /** @brief 256 Hz. 125ms code-sequence-duration. */
  FH101RF_SAMPLE_RATE_SR_0_256 = 0x7U,
  /** @brief 512 Hz. 62.5ms code-sequence-duration. */
  FH101RF_SAMPLE_RATE_SR_0_512 = 0x6U,
  /** @brief 16384 Hz. 1.957ms code-sequence-duration. */
  FH101RF_SAMPLE_RATE_SR_16_384 = 0x1U,
  /** @brief 1024 Hz. 31.25ms code-sequence-duration. */
  FH101RF_SAMPLE_RATE_SR_1_024 = 0x5U,
  /** @brief 2048 Hz. 15.625ms code-sequence-duration. */
  FH101RF_SAMPLE_RATE_SR_2_048 = 0x4U,
  /** @brief 32768 Hz. 0.977ms code-sequence-duration. */
  FH101RF_SAMPLE_RATE_SR_32_768 = 0x0U,
  /** @brief 4096 Hz. 7.813ms code-sequence-duration. */
  FH101RF_SAMPLE_RATE_SR_4_096 = 0x3U,
  /** @brief 32768 Hz. 0.977ms code-sequence-duration. */
  FH101RF_SAMPLE_RATE_SR_8_192 = 0x2U,
};

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_sample_rate.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_SAMPLE_RATE(_VAL_) (                                                      \
  ((_VAL_) <= 0x7U) ? true :                                                                       \
  false )

// =============================================================================
// ==== Shared Layout Structs ==================================================
// =============================================================================

// ---- BANDS Layout -----------------------------------------------------------
// Fields:
//  - [0] BAND_433 (bool): True means on for 433MHz band.
//  - [1] BAND_868 (bool): True means on for 868/915MHz band.
//  - [2] BAND_2G4 (bool): True means on for 2.4GHz band.

// Layout Struct:

/** @note use pack/unpack functions for conversion to/from packed binary value */
struct fh101rf_bands {
  /** @brief True means on for 2.4GHz band. */
  bool band_2g4;
  /** @brief True means on for 433MHz band. */
  bool band_433;
  /** @brief True means on for 868/915MHz band. */
  bool band_868;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_bands struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_bands_pack_le(const struct fh101rf_bands *r, uint8_t val[1]) {
  // BAND_2G4 @ bands[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_2g4 << 2)) & 0x4U);
  // BAND_433 @ bands[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->band_433) & 0x1U);
  // BAND_868 @ bands[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_868 << 1)) & 0x2U);
}

/**
 * @brief Convert @ref struct fh101rf_bands struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_bands_pack_be(const struct fh101rf_bands *r, uint8_t val[1]) {
  // BAND_2G4 @ bands[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_2g4 << 2)) & 0x4U);
  // BAND_433 @ bands[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->band_433) & 0x1U);
  // BAND_868 @ bands[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_868 << 1)) & 0x2U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_bands fh101rf_bands_unpack_le(const uint8_t val[1]) {
  struct fh101rf_bands r = {0};
  // BAND_2G4 @ bands[2]:
  r.band_2g4 = (bool)(((val[0] & 0x4U) >> 2));
  // BAND_433 @ bands[0]:
  r.band_433 = (bool)((val[0] & 0x1U));
  // BAND_868 @ bands[1]:
  r.band_868 = (bool)(((val[0] & 0x2U) >> 1));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_bands fh101rf_bands_unpack_be(const uint8_t val[1]) {
  struct fh101rf_bands r = {0};
  // BAND_2G4 @ bands[2]:
  r.band_2g4 = (bool)(((val[0] & 0x4U) >> 2));
  // BAND_433 @ bands[0]:
  r.band_433 = (bool)((val[0] & 0x1U));
  // BAND_868 @ bands[1]:
  r.band_868 = (bool)(((val[0] & 0x2U) >> 1));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_bands(const struct fh101rf_bands *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_bands_try_unpack_le(const uint8_t val[1], struct fh101rf_bands *r) {
  *r = fh101rf_bands_unpack_le(val);
  return fh101rf_validate_bands(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_bands_try_unpack_be(const uint8_t val[1], struct fh101rf_bands *r) {
  *r = fh101rf_bands_unpack_be(val);
  return fh101rf_validate_bands(r);
}

// ---- BRANCHES Layout --------------------------------------------------------
// Fields:
//  - [0] WEAK (bool): True means weak branch on.
//  - [1] MEDIUM (bool): True means medium branch on (+8dB of weak).
//  - [2] STRONG (bool): True means strong branch on (+16dB of weak).

// Layout Struct:

/** @note use pack/unpack functions for conversion to/from packed binary value */
struct fh101rf_branches {
  /** @brief True means medium branch on (+8dB of weak). */
  bool medium;
  /** @brief True means strong branch on (+16dB of weak). */
  bool strong;
  /** @brief True means weak branch on. */
  bool weak;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_branches struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_branches_pack_le(const struct fh101rf_branches *r, uint8_t val[1]) {
  // MEDIUM @ branches[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->medium << 1)) & 0x2U);
  // STRONG @ branches[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->strong << 2)) & 0x4U);
  // WEAK @ branches[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->weak) & 0x1U);
}

/**
 * @brief Convert @ref struct fh101rf_branches struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_branches_pack_be(const struct fh101rf_branches *r, uint8_t val[1]) {
  // MEDIUM @ branches[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->medium << 1)) & 0x2U);
  // STRONG @ branches[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->strong << 2)) & 0x4U);
  // WEAK @ branches[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->weak) & 0x1U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_branches fh101rf_branches_unpack_le(const uint8_t val[1]) {
  struct fh101rf_branches r = {0};
  // MEDIUM @ branches[1]:
  r.medium = (bool)(((val[0] & 0x2U) >> 1));
  // STRONG @ branches[2]:
  r.strong = (bool)(((val[0] & 0x4U) >> 2));
  // WEAK @ branches[0]:
  r.weak = (bool)((val[0] & 0x1U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_branches fh101rf_branches_unpack_be(const uint8_t val[1]) {
  struct fh101rf_branches r = {0};
  // MEDIUM @ branches[1]:
  r.medium = (bool)(((val[0] & 0x2U) >> 1));
  // STRONG @ branches[2]:
  r.strong = (bool)(((val[0] & 0x4U) >> 2));
  // WEAK @ branches[0]:
  r.weak = (bool)((val[0] & 0x1U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_branches(const struct fh101rf_branches *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_branches_try_unpack_le(const uint8_t val[1], struct fh101rf_branches *r) {
  *r = fh101rf_branches_unpack_le(val);
  return fh101rf_validate_branches(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_branches_try_unpack_be(const uint8_t val[1], struct fh101rf_branches *r) {
  *r = fh101rf_branches_unpack_be(val);
  return fh101rf_validate_branches(r);
}

// ---- IRQ_SOURCE Layout ------------------------------------------------------
// Fields:
//  - [0] ID_MATCH (bool): The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
//  - [1] FIFO_OVERFLOW (bool): FIFO overflow.
//  - [2] FIFO_FULL (bool): FIFO buffer full.
//  - [3] CORREL_MATCH (bool): OOK data matches the correlation sequence.
//  - [4] ID_MATCH_AND_FIFO_FULL (bool): 16-bit ID in FDD mode matches and FIFO buffer full.
//  - [5] ID_MATCH_AND_LDR (bool): 16-bit ID in FDD mode matches and LDR was entered.
//  - [6] RTC_TIMER_ALARM (bool): RTC timer alarm.
//  - [7] CYCLIC_TIMER_ALARM (bool): Cyclic timer alarm.

// Layout Struct:

/** @note use pack/unpack functions for conversion to/from packed binary value */
struct fh101rf_irq_source {
  /** @brief OOK data matches the correlation sequence. */
  bool correl_match;
  /** @brief Cyclic timer alarm. */
  bool cyclic_timer_alarm;
  /** @brief FIFO buffer full. */
  bool fifo_full;
  /** @brief FIFO overflow. */
  bool fifo_overflow;
  /** @brief The 16-bit ID in FDD mode matches (register ID_HI, ID_LO). */
  bool id_match;
  /** @brief 16-bit ID in FDD mode matches and FIFO buffer full. */
  bool id_match_and_fifo_full;
  /** @brief 16-bit ID in FDD mode matches and LDR was entered. */
  bool id_match_and_ldr;
  /** @brief RTC timer alarm. */
  bool rtc_timer_alarm;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_irq_source struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_source_pack_le(const struct fh101rf_irq_source *r, uint8_t val[1]) {
  // CORREL_MATCH @ irq_source[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->correl_match << 3)) & 0x8U);
  // CYCLIC_TIMER_ALARM @ irq_source[7]:
  val[0] &= (uint8_t)~0x80U;
  val[0] |= (uint8_t)(((uint8_t)(r->cyclic_timer_alarm << 7)) & 0x80U);
  // FIFO_FULL @ irq_source[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->fifo_full << 2)) & 0x4U);
  // FIFO_OVERFLOW @ irq_source[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->fifo_overflow << 1)) & 0x2U);
  // ID_MATCH @ irq_source[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->id_match) & 0x1U);
  // ID_MATCH_AND_FIFO_FULL @ irq_source[4]:
  val[0] &= (uint8_t)~0x10U;
  val[0] |= (uint8_t)(((uint8_t)(r->id_match_and_fifo_full << 4)) & 0x10U);
  // ID_MATCH_AND_LDR @ irq_source[5]:
  val[0] &= (uint8_t)~0x20U;
  val[0] |= (uint8_t)(((uint8_t)(r->id_match_and_ldr << 5)) & 0x20U);
  // RTC_TIMER_ALARM @ irq_source[6]:
  val[0] &= (uint8_t)~0x40U;
  val[0] |= (uint8_t)(((uint8_t)(r->rtc_timer_alarm << 6)) & 0x40U);
}

/**
 * @brief Convert @ref struct fh101rf_irq_source struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_source_pack_be(const struct fh101rf_irq_source *r, uint8_t val[1]) {
  // CORREL_MATCH @ irq_source[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->correl_match << 3)) & 0x8U);
  // CYCLIC_TIMER_ALARM @ irq_source[7]:
  val[0] &= (uint8_t)~0x80U;
  val[0] |= (uint8_t)(((uint8_t)(r->cyclic_timer_alarm << 7)) & 0x80U);
  // FIFO_FULL @ irq_source[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->fifo_full << 2)) & 0x4U);
  // FIFO_OVERFLOW @ irq_source[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->fifo_overflow << 1)) & 0x2U);
  // ID_MATCH @ irq_source[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->id_match) & 0x1U);
  // ID_MATCH_AND_FIFO_FULL @ irq_source[4]:
  val[0] &= (uint8_t)~0x10U;
  val[0] |= (uint8_t)(((uint8_t)(r->id_match_and_fifo_full << 4)) & 0x10U);
  // ID_MATCH_AND_LDR @ irq_source[5]:
  val[0] &= (uint8_t)~0x20U;
  val[0] |= (uint8_t)(((uint8_t)(r->id_match_and_ldr << 5)) & 0x20U);
  // RTC_TIMER_ALARM @ irq_source[6]:
  val[0] &= (uint8_t)~0x40U;
  val[0] |= (uint8_t)(((uint8_t)(r->rtc_timer_alarm << 6)) & 0x40U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_source fh101rf_irq_source_unpack_le(const uint8_t val[1]) {
  struct fh101rf_irq_source r = {0};
  // CORREL_MATCH @ irq_source[3]:
  r.correl_match = (bool)(((val[0] & 0x8U) >> 3));
  // CYCLIC_TIMER_ALARM @ irq_source[7]:
  r.cyclic_timer_alarm = (bool)(((val[0] & 0x80U) >> 7));
  // FIFO_FULL @ irq_source[2]:
  r.fifo_full = (bool)(((val[0] & 0x4U) >> 2));
  // FIFO_OVERFLOW @ irq_source[1]:
  r.fifo_overflow = (bool)(((val[0] & 0x2U) >> 1));
  // ID_MATCH @ irq_source[0]:
  r.id_match = (bool)((val[0] & 0x1U));
  // ID_MATCH_AND_FIFO_FULL @ irq_source[4]:
  r.id_match_and_fifo_full = (bool)(((val[0] & 0x10U) >> 4));
  // ID_MATCH_AND_LDR @ irq_source[5]:
  r.id_match_and_ldr = (bool)(((val[0] & 0x20U) >> 5));
  // RTC_TIMER_ALARM @ irq_source[6]:
  r.rtc_timer_alarm = (bool)(((val[0] & 0x40U) >> 6));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_source fh101rf_irq_source_unpack_be(const uint8_t val[1]) {
  struct fh101rf_irq_source r = {0};
  // CORREL_MATCH @ irq_source[3]:
  r.correl_match = (bool)(((val[0] & 0x8U) >> 3));
  // CYCLIC_TIMER_ALARM @ irq_source[7]:
  r.cyclic_timer_alarm = (bool)(((val[0] & 0x80U) >> 7));
  // FIFO_FULL @ irq_source[2]:
  r.fifo_full = (bool)(((val[0] & 0x4U) >> 2));
  // FIFO_OVERFLOW @ irq_source[1]:
  r.fifo_overflow = (bool)(((val[0] & 0x2U) >> 1));
  // ID_MATCH @ irq_source[0]:
  r.id_match = (bool)((val[0] & 0x1U));
  // ID_MATCH_AND_FIFO_FULL @ irq_source[4]:
  r.id_match_and_fifo_full = (bool)(((val[0] & 0x10U) >> 4));
  // ID_MATCH_AND_LDR @ irq_source[5]:
  r.id_match_and_ldr = (bool)(((val[0] & 0x20U) >> 5));
  // RTC_TIMER_ALARM @ irq_source[6]:
  r.rtc_timer_alarm = (bool)(((val[0] & 0x40U) >> 6));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_irq_source(const struct fh101rf_irq_source *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_source_try_unpack_le(const uint8_t val[1], struct fh101rf_irq_source *r) {
  *r = fh101rf_irq_source_unpack_le(val);
  return fh101rf_validate_irq_source(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_source_try_unpack_be(const uint8_t val[1], struct fh101rf_irq_source *r) {
  *r = fh101rf_irq_source_unpack_be(val);
  return fh101rf_validate_irq_source(r);
}

// ---- RTC Layout -------------------------------------------------------------
// Fields:
//  - [0] RTCSH0 (bool): Selects the short RTC counter
//  - [1] RTCSH1 (bool): Selects the short RTC counter
//  - [2] RTCLG0 (bool): Selects the long RTC counter
//  - [3] RTCLG1 (bool): Selects the long RTC counter

// Layout Struct:

/** @note use pack/unpack functions for conversion to/from packed binary value */
struct fh101rf_rtc {
  /** @brief Selects the long RTC counter */
  bool rtclg0;
  /** @brief Selects the long RTC counter */
  bool rtclg1;
  /** @brief Selects the short RTC counter */
  bool rtcsh0;
  /** @brief Selects the short RTC counter */
  bool rtcsh1;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtc struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtc_pack_le(const struct fh101rf_rtc *r, uint8_t val[1]) {
  // RTCLG0 @ rtc[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->rtclg0 << 2)) & 0x4U);
  // RTCLG1 @ rtc[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->rtclg1 << 3)) & 0x8U);
  // RTCSH0 @ rtc[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->rtcsh0) & 0x1U);
  // RTCSH1 @ rtc[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->rtcsh1 << 1)) & 0x2U);
}

/**
 * @brief Convert @ref struct fh101rf_rtc struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtc_pack_be(const struct fh101rf_rtc *r, uint8_t val[1]) {
  // RTCLG0 @ rtc[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->rtclg0 << 2)) & 0x4U);
  // RTCLG1 @ rtc[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->rtclg1 << 3)) & 0x8U);
  // RTCSH0 @ rtc[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->rtcsh0) & 0x1U);
  // RTCSH1 @ rtc[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->rtcsh1 << 1)) & 0x2U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtc fh101rf_rtc_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtc r = {0};
  // RTCLG0 @ rtc[2]:
  r.rtclg0 = (bool)(((val[0] & 0x4U) >> 2));
  // RTCLG1 @ rtc[3]:
  r.rtclg1 = (bool)(((val[0] & 0x8U) >> 3));
  // RTCSH0 @ rtc[0]:
  r.rtcsh0 = (bool)((val[0] & 0x1U));
  // RTCSH1 @ rtc[1]:
  r.rtcsh1 = (bool)(((val[0] & 0x2U) >> 1));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtc fh101rf_rtc_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtc r = {0};
  // RTCLG0 @ rtc[2]:
  r.rtclg0 = (bool)(((val[0] & 0x4U) >> 2));
  // RTCLG1 @ rtc[3]:
  r.rtclg1 = (bool)(((val[0] & 0x8U) >> 3));
  // RTCSH0 @ rtc[0]:
  r.rtcsh0 = (bool)((val[0] & 0x1U));
  // RTCSH1 @ rtc[1]:
  r.rtcsh1 = (bool)(((val[0] & 0x2U) >> 1));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtc(const struct fh101rf_rtc *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtc_try_unpack_le(const uint8_t val[1], struct fh101rf_rtc *r) {
  *r = fh101rf_rtc_unpack_le(val);
  return fh101rf_validate_rtc(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtc_try_unpack_be(const uint8_t val[1], struct fh101rf_rtc *r) {
  *r = fh101rf_rtc_unpack_be(val);
  return fh101rf_validate_rtc(r);
}

// =============================================================================
// ==== ACTUAL_BANDSELECT Register =============================================
// =============================================================================
// This 3 bit register contains the actual selected frequency bands that are currently used.
// Fields:
//  - [2:0] SELECTED_BANDS (layout BANDS)
//    - [0] SELECTED_BANDS.BAND_433 (bool): True means on for 433MHz band.
//    - [1] SELECTED_BANDS.BAND_868 (bool): True means on for 868/915MHz band.
//    - [2] SELECTED_BANDS.BAND_2G4 (bool): True means on for 2.4GHz band.

#define FH101RF_ACTUAL_BANDSELECT_ADDRESS  (0x6FU) //!< ACTUAL_BANDSELECT register address
#define FH101RF_ACTUAL_BANDSELECT_RESET_LE {0x7U}  //!< ACTUAL_BANDSELECT register reset value
#define FH101RF_ACTUAL_BANDSELECT_RESET_BE {0x7U}  //!< ACTUAL_BANDSELECT register reset value

// Register Layout Struct:

/**
 * @brief This 3 bit register contains the actual selected frequency bands that are currently used.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_actual_bandselect {
  struct fh101rf_bands selected_bands;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_actual_bandselect struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_actual_bandselect_pack_le(const struct fh101rf_actual_bandselect *r, uint8_t val[1]) {
  // SELECTED_BANDS @ actual_bandselect[2:0]:
  uint8_t selected_bands[1] = {0};
  fh101rf_bands_pack_le(&r->selected_bands, selected_bands);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)selected_bands[0] & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_actual_bandselect struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_actual_bandselect_pack_be(const struct fh101rf_actual_bandselect *r, uint8_t val[1]) {
  // SELECTED_BANDS @ actual_bandselect[2:0]:
  uint8_t selected_bands[1] = {0};
  fh101rf_bands_pack_be(&r->selected_bands, selected_bands);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)selected_bands[0] & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_actual_bandselect fh101rf_actual_bandselect_unpack_le(const uint8_t val[1]) {
  struct fh101rf_actual_bandselect r = {0};
  // SELECTED_BANDS @ actual_bandselect[2:0]:
  uint8_t selected_bands[1] = {0};
  selected_bands[0] |= (uint8_t)((val[0] & 0x7U));
  r.selected_bands = fh101rf_bands_unpack_le(selected_bands);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_actual_bandselect fh101rf_actual_bandselect_unpack_be(const uint8_t val[1]) {
  struct fh101rf_actual_bandselect r = {0};
  // SELECTED_BANDS @ actual_bandselect[2:0]:
  uint8_t selected_bands[1] = {0};
  selected_bands[0] |= (uint8_t)((val[0] & 0x7U));
  r.selected_bands = fh101rf_bands_unpack_be(selected_bands);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_actual_bandselect(const struct fh101rf_actual_bandselect *r) {
  if (fh101rf_validate_bands(&r->selected_bands)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_actual_bandselect_try_unpack_le(const uint8_t val[1], struct fh101rf_actual_bandselect *r) {
  *r = fh101rf_actual_bandselect_unpack_le(val);
  return fh101rf_validate_actual_bandselect(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_actual_bandselect_try_unpack_be(const uint8_t val[1], struct fh101rf_actual_bandselect *r) {
  *r = fh101rf_actual_bandselect_unpack_be(val);
  return fh101rf_validate_actual_bandselect(r);
}

// =============================================================================
// ==== ACTUAL_NFA_2G4 Register ================================================
// =============================================================================
// This register contains the actual NFA (sampling rate) value that is currently valid for 2.4GHz data reception.
// Fields:
//  - [2:0] SLOW (enum SAMPLE_RATE)
//  - [6:4] FAST (enum SAMPLE_RATE)

#define FH101RF_ACTUAL_NFA_2G4_ADDRESS  (0x6EU) //!< ACTUAL_NFA_2G4 register address
#define FH101RF_ACTUAL_NFA_2G4_RESET_LE {0x25U} //!< ACTUAL_NFA_2G4 register reset value
#define FH101RF_ACTUAL_NFA_2G4_RESET_BE {0x25U} //!< ACTUAL_NFA_2G4 register reset value

// Register Layout Struct:

/**
 * @brief This register contains the actual NFA (sampling rate) value that is currently valid for 2.4GHz data reception.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_actual_nfa_2g4 {
  enum fh101rf_sample_rate fast;
  enum fh101rf_sample_rate slow;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_actual_nfa_2g4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_actual_nfa_2g4_pack_le(const struct fh101rf_actual_nfa_2g4 *r, uint8_t val[1]) {
  // FAST @ actual_nfa_2g4[6:4]:
  val[0] &= (uint8_t)~0x70U;
  val[0] |= (uint8_t)(((uint8_t)(r->fast << 4)) & 0x70U);
  // SLOW @ actual_nfa_2g4[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->slow) & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_actual_nfa_2g4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_actual_nfa_2g4_pack_be(const struct fh101rf_actual_nfa_2g4 *r, uint8_t val[1]) {
  // FAST @ actual_nfa_2g4[6:4]:
  val[0] &= (uint8_t)~0x70U;
  val[0] |= (uint8_t)(((uint8_t)(r->fast << 4)) & 0x70U);
  // SLOW @ actual_nfa_2g4[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->slow) & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_actual_nfa_2g4 fh101rf_actual_nfa_2g4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_actual_nfa_2g4 r = {0};
  // FAST @ actual_nfa_2g4[6:4]:
  r.fast = (enum fh101rf_sample_rate)(((val[0] & 0x70U) >> 4));
  // SLOW @ actual_nfa_2g4[2:0]:
  r.slow = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_actual_nfa_2g4 fh101rf_actual_nfa_2g4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_actual_nfa_2g4 r = {0};
  // FAST @ actual_nfa_2g4[6:4]:
  r.fast = (enum fh101rf_sample_rate)(((val[0] & 0x70U) >> 4));
  // SLOW @ actual_nfa_2g4[2:0]:
  r.slow = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_actual_nfa_2g4(const struct fh101rf_actual_nfa_2g4 *r) {
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->fast))) return 5;
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->slow))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_actual_nfa_2g4_try_unpack_le(const uint8_t val[1], struct fh101rf_actual_nfa_2g4 *r) {
  *r = fh101rf_actual_nfa_2g4_unpack_le(val);
  return fh101rf_validate_actual_nfa_2g4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_actual_nfa_2g4_try_unpack_be(const uint8_t val[1], struct fh101rf_actual_nfa_2g4 *r) {
  *r = fh101rf_actual_nfa_2g4_unpack_be(val);
  return fh101rf_validate_actual_nfa_2g4(r);
}

// =============================================================================
// ==== ACTUAL_NFA_433 Register ================================================
// =============================================================================
// This register contains the actual NFA (sampling rate) value that is currently valid for 433MHz data reception.
// Fields:
//  - [2:0] SLOW (enum SAMPLE_RATE)
//  - [6:4] FAST (enum SAMPLE_RATE)

#define FH101RF_ACTUAL_NFA_433_ADDRESS  (0x6CU) //!< ACTUAL_NFA_433 register address
#define FH101RF_ACTUAL_NFA_433_RESET_LE {0x25U} //!< ACTUAL_NFA_433 register reset value
#define FH101RF_ACTUAL_NFA_433_RESET_BE {0x25U} //!< ACTUAL_NFA_433 register reset value

// Register Layout Struct:

/**
 * @brief This register contains the actual NFA (sampling rate) value that is currently valid for 433MHz data reception.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_actual_nfa_433 {
  enum fh101rf_sample_rate fast;
  enum fh101rf_sample_rate slow;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_actual_nfa_433 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_actual_nfa_433_pack_le(const struct fh101rf_actual_nfa_433 *r, uint8_t val[1]) {
  // FAST @ actual_nfa_433[6:4]:
  val[0] &= (uint8_t)~0x70U;
  val[0] |= (uint8_t)(((uint8_t)(r->fast << 4)) & 0x70U);
  // SLOW @ actual_nfa_433[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->slow) & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_actual_nfa_433 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_actual_nfa_433_pack_be(const struct fh101rf_actual_nfa_433 *r, uint8_t val[1]) {
  // FAST @ actual_nfa_433[6:4]:
  val[0] &= (uint8_t)~0x70U;
  val[0] |= (uint8_t)(((uint8_t)(r->fast << 4)) & 0x70U);
  // SLOW @ actual_nfa_433[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->slow) & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_actual_nfa_433 fh101rf_actual_nfa_433_unpack_le(const uint8_t val[1]) {
  struct fh101rf_actual_nfa_433 r = {0};
  // FAST @ actual_nfa_433[6:4]:
  r.fast = (enum fh101rf_sample_rate)(((val[0] & 0x70U) >> 4));
  // SLOW @ actual_nfa_433[2:0]:
  r.slow = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_actual_nfa_433 fh101rf_actual_nfa_433_unpack_be(const uint8_t val[1]) {
  struct fh101rf_actual_nfa_433 r = {0};
  // FAST @ actual_nfa_433[6:4]:
  r.fast = (enum fh101rf_sample_rate)(((val[0] & 0x70U) >> 4));
  // SLOW @ actual_nfa_433[2:0]:
  r.slow = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_actual_nfa_433(const struct fh101rf_actual_nfa_433 *r) {
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->fast))) return 5;
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->slow))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_actual_nfa_433_try_unpack_le(const uint8_t val[1], struct fh101rf_actual_nfa_433 *r) {
  *r = fh101rf_actual_nfa_433_unpack_le(val);
  return fh101rf_validate_actual_nfa_433(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_actual_nfa_433_try_unpack_be(const uint8_t val[1], struct fh101rf_actual_nfa_433 *r) {
  *r = fh101rf_actual_nfa_433_unpack_be(val);
  return fh101rf_validate_actual_nfa_433(r);
}

// =============================================================================
// ==== ACTUAL_NFA_868 Register ================================================
// =============================================================================
// This register contains the actual NFA (sampling rate) value that is currently valid for 868MHz data reception.
// Fields:
//  - [2:0] SLOW (enum SAMPLE_RATE)
//  - [6:4] FAST (enum SAMPLE_RATE)

#define FH101RF_ACTUAL_NFA_868_ADDRESS  (0x6DU) //!< ACTUAL_NFA_868 register address
#define FH101RF_ACTUAL_NFA_868_RESET_LE {0x15U} //!< ACTUAL_NFA_868 register reset value
#define FH101RF_ACTUAL_NFA_868_RESET_BE {0x15U} //!< ACTUAL_NFA_868 register reset value

// Register Layout Struct:

/**
 * @brief This register contains the actual NFA (sampling rate) value that is currently valid for 868MHz data reception.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_actual_nfa_868 {
  enum fh101rf_sample_rate fast;
  enum fh101rf_sample_rate slow;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_actual_nfa_868 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_actual_nfa_868_pack_le(const struct fh101rf_actual_nfa_868 *r, uint8_t val[1]) {
  // FAST @ actual_nfa_868[6:4]:
  val[0] &= (uint8_t)~0x70U;
  val[0] |= (uint8_t)(((uint8_t)(r->fast << 4)) & 0x70U);
  // SLOW @ actual_nfa_868[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->slow) & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_actual_nfa_868 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_actual_nfa_868_pack_be(const struct fh101rf_actual_nfa_868 *r, uint8_t val[1]) {
  // FAST @ actual_nfa_868[6:4]:
  val[0] &= (uint8_t)~0x70U;
  val[0] |= (uint8_t)(((uint8_t)(r->fast << 4)) & 0x70U);
  // SLOW @ actual_nfa_868[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->slow) & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_actual_nfa_868 fh101rf_actual_nfa_868_unpack_le(const uint8_t val[1]) {
  struct fh101rf_actual_nfa_868 r = {0};
  // FAST @ actual_nfa_868[6:4]:
  r.fast = (enum fh101rf_sample_rate)(((val[0] & 0x70U) >> 4));
  // SLOW @ actual_nfa_868[2:0]:
  r.slow = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_actual_nfa_868 fh101rf_actual_nfa_868_unpack_be(const uint8_t val[1]) {
  struct fh101rf_actual_nfa_868 r = {0};
  // FAST @ actual_nfa_868[6:4]:
  r.fast = (enum fh101rf_sample_rate)(((val[0] & 0x70U) >> 4));
  // SLOW @ actual_nfa_868[2:0]:
  r.slow = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_actual_nfa_868(const struct fh101rf_actual_nfa_868 *r) {
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->fast))) return 5;
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->slow))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_actual_nfa_868_try_unpack_le(const uint8_t val[1], struct fh101rf_actual_nfa_868 *r) {
  *r = fh101rf_actual_nfa_868_unpack_le(val);
  return fh101rf_validate_actual_nfa_868(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_actual_nfa_868_try_unpack_be(const uint8_t val[1], struct fh101rf_actual_nfa_868 *r) {
  *r = fh101rf_actual_nfa_868_unpack_be(val);
  return fh101rf_validate_actual_nfa_868(r);
}

// =============================================================================
// ==== BAND_BRANCH_CTRL Register ==============================================
// =============================================================================
// Selects the active bands and branches (RF-sensitivity).
// Fields:
//  - [2:0] ACTIVE_BRANCHES (layout BRANCHES): Selects the active detection branches.
//    - [0] ACTIVE_BRANCHES.WEAK (bool): True means weak branch on.
//    - [1] ACTIVE_BRANCHES.MEDIUM (bool): True means medium branch on (+8dB of weak).
//    - [2] ACTIVE_BRANCHES.STRONG (bool): True means strong branch on (+16dB of weak).
//  - [6:4] ACTIVE_BANDS (layout BANDS): Selects the active bands.
//    - [4] ACTIVE_BANDS.BAND_433 (bool): True means on for 433MHz band.
//    - [5] ACTIVE_BANDS.BAND_868 (bool): True means on for 868/915MHz band.
//    - [6] ACTIVE_BANDS.BAND_2G4 (bool): True means on for 2.4GHz band.

#define FH101RF_BAND_BRANCH_CTRL_ADDRESS  (0x24U) //!< BAND_BRANCH_CTRL register address
#define FH101RF_BAND_BRANCH_CTRL_RESET_LE {0x77U} //!< BAND_BRANCH_CTRL register reset value
#define FH101RF_BAND_BRANCH_CTRL_RESET_BE {0x77U} //!< BAND_BRANCH_CTRL register reset value

// Register Layout Struct:

/**
 * @brief Selects the active bands and branches (RF-sensitivity).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_band_branch_ctrl {
  /** @brief Selects the active bands. */
  struct fh101rf_bands active_bands;
  /** @brief Selects the active detection branches. */
  struct fh101rf_branches active_branches;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_band_branch_ctrl struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_band_branch_ctrl_pack_le(const struct fh101rf_band_branch_ctrl *r, uint8_t val[1]) {
  // ACTIVE_BANDS @ band_branch_ctrl[6:4]:
  uint8_t active_bands[1] = {0};
  fh101rf_bands_pack_le(&r->active_bands, active_bands);
  val[0] &= (uint8_t)~0x70U;
  val[0] |= (uint8_t)((uint8_t)(active_bands[0] << 4) & 0x70U);
  // ACTIVE_BRANCHES @ band_branch_ctrl[2:0]:
  uint8_t active_branches[1] = {0};
  fh101rf_branches_pack_le(&r->active_branches, active_branches);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)active_branches[0] & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_band_branch_ctrl struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_band_branch_ctrl_pack_be(const struct fh101rf_band_branch_ctrl *r, uint8_t val[1]) {
  // ACTIVE_BANDS @ band_branch_ctrl[6:4]:
  uint8_t active_bands[1] = {0};
  fh101rf_bands_pack_be(&r->active_bands, active_bands);
  val[0] &= (uint8_t)~0x70U;
  val[0] |= (uint8_t)((uint8_t)(active_bands[0] << 4) & 0x70U);
  // ACTIVE_BRANCHES @ band_branch_ctrl[2:0]:
  uint8_t active_branches[1] = {0};
  fh101rf_branches_pack_be(&r->active_branches, active_branches);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)active_branches[0] & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_band_branch_ctrl fh101rf_band_branch_ctrl_unpack_le(const uint8_t val[1]) {
  struct fh101rf_band_branch_ctrl r = {0};
  // ACTIVE_BANDS @ band_branch_ctrl[6:4]:
  uint8_t active_bands[1] = {0};
  active_bands[0] |= (uint8_t)((val[0] & 0x70U) >> 4);
  r.active_bands = fh101rf_bands_unpack_le(active_bands);
  // ACTIVE_BRANCHES @ band_branch_ctrl[2:0]:
  uint8_t active_branches[1] = {0};
  active_branches[0] |= (uint8_t)((val[0] & 0x7U));
  r.active_branches = fh101rf_branches_unpack_le(active_branches);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_band_branch_ctrl fh101rf_band_branch_ctrl_unpack_be(const uint8_t val[1]) {
  struct fh101rf_band_branch_ctrl r = {0};
  // ACTIVE_BANDS @ band_branch_ctrl[6:4]:
  uint8_t active_bands[1] = {0};
  active_bands[0] |= (uint8_t)((val[0] & 0x70U) >> 4);
  r.active_bands = fh101rf_bands_unpack_be(active_bands);
  // ACTIVE_BRANCHES @ band_branch_ctrl[2:0]:
  uint8_t active_branches[1] = {0};
  active_branches[0] |= (uint8_t)((val[0] & 0x7U));
  r.active_branches = fh101rf_branches_unpack_be(active_branches);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_band_branch_ctrl(const struct fh101rf_band_branch_ctrl *r) {
  if (fh101rf_validate_bands(&r->active_bands)) return 5;
  if (fh101rf_validate_branches(&r->active_branches)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_band_branch_ctrl_try_unpack_le(const uint8_t val[1], struct fh101rf_band_branch_ctrl *r) {
  *r = fh101rf_band_branch_ctrl_unpack_le(val);
  return fh101rf_validate_band_branch_ctrl(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_band_branch_ctrl_try_unpack_be(const uint8_t val[1], struct fh101rf_band_branch_ctrl *r) {
  *r = fh101rf_band_branch_ctrl_unpack_be(val);
  return fh101rf_validate_band_branch_ctrl(r);
}

// =============================================================================
// ==== CALIB_CTRL Register ====================================================
// =============================================================================
// Control register for starting calibration processes.
// Fields:
//  - [0] CAL_START (bool): Starts the calibration process.
//  - [1] LCO_CAL (bool): Control bit for initiating LCO calibration.
//  - [2] SPG_CAL (bool): Control bit for initiating SPG calibration.
//  - [3] OFFSET_CAL (bool): Control bit for initiating offset calibration.

#define FH101RF_CALIB_CTRL_ADDRESS  (0x7U) //!< CALIB_CTRL register address
#define FH101RF_CALIB_CTRL_RESET_LE {0xEU} //!< CALIB_CTRL register reset value
#define FH101RF_CALIB_CTRL_RESET_BE {0xEU} //!< CALIB_CTRL register reset value

// Register Layout Struct:

/**
 * @brief Control register for starting calibration processes.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_calib_ctrl {
  /** @brief Starts the calibration process. */
  bool cal_start;
  /** @brief Control bit for initiating LCO calibration. */
  bool lco_cal;
  /** @brief Control bit for initiating offset calibration. */
  bool offset_cal;
  /** @brief Control bit for initiating SPG calibration. */
  bool spg_cal;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_calib_ctrl struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_calib_ctrl_pack_le(const struct fh101rf_calib_ctrl *r, uint8_t val[1]) {
  // CAL_START @ calib_ctrl[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->cal_start) & 0x1U);
  // LCO_CAL @ calib_ctrl[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->lco_cal << 1)) & 0x2U);
  // OFFSET_CAL @ calib_ctrl[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->offset_cal << 3)) & 0x8U);
  // SPG_CAL @ calib_ctrl[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->spg_cal << 2)) & 0x4U);
}

/**
 * @brief Convert @ref struct fh101rf_calib_ctrl struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_calib_ctrl_pack_be(const struct fh101rf_calib_ctrl *r, uint8_t val[1]) {
  // CAL_START @ calib_ctrl[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->cal_start) & 0x1U);
  // LCO_CAL @ calib_ctrl[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->lco_cal << 1)) & 0x2U);
  // OFFSET_CAL @ calib_ctrl[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->offset_cal << 3)) & 0x8U);
  // SPG_CAL @ calib_ctrl[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->spg_cal << 2)) & 0x4U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_calib_ctrl fh101rf_calib_ctrl_unpack_le(const uint8_t val[1]) {
  struct fh101rf_calib_ctrl r = {0};
  // CAL_START @ calib_ctrl[0]:
  r.cal_start = (bool)((val[0] & 0x1U));
  // LCO_CAL @ calib_ctrl[1]:
  r.lco_cal = (bool)(((val[0] & 0x2U) >> 1));
  // OFFSET_CAL @ calib_ctrl[3]:
  r.offset_cal = (bool)(((val[0] & 0x8U) >> 3));
  // SPG_CAL @ calib_ctrl[2]:
  r.spg_cal = (bool)(((val[0] & 0x4U) >> 2));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_calib_ctrl fh101rf_calib_ctrl_unpack_be(const uint8_t val[1]) {
  struct fh101rf_calib_ctrl r = {0};
  // CAL_START @ calib_ctrl[0]:
  r.cal_start = (bool)((val[0] & 0x1U));
  // LCO_CAL @ calib_ctrl[1]:
  r.lco_cal = (bool)(((val[0] & 0x2U) >> 1));
  // OFFSET_CAL @ calib_ctrl[3]:
  r.offset_cal = (bool)(((val[0] & 0x8U) >> 3));
  // SPG_CAL @ calib_ctrl[2]:
  r.spg_cal = (bool)(((val[0] & 0x4U) >> 2));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_calib_ctrl(const struct fh101rf_calib_ctrl *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_calib_ctrl_try_unpack_le(const uint8_t val[1], struct fh101rf_calib_ctrl *r) {
  *r = fh101rf_calib_ctrl_unpack_le(val);
  return fh101rf_validate_calib_ctrl(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_calib_ctrl_try_unpack_be(const uint8_t val[1], struct fh101rf_calib_ctrl *r) {
  *r = fh101rf_calib_ctrl_unpack_be(val);
  return fh101rf_validate_calib_ctrl(r);
}

// =============================================================================
// ==== CALIB_STATUS Register ==================================================
// =============================================================================
// Indicates status of all calibration processes.
// Fields:
//  - [0] CAL_IN_PROG (bool): Indicates general calibration process in progress.
//  - [1] LCO_CAL_IN_PROG (bool): Indicates LCO calibration in progress.
//  - [2] SPG_CAL_IN_PROG (bool): Indicates SPG calibration in progress.
//  - [3] OFFSET_CAL_IN_PROG (bool): Indicates Offset calubration in progress.

#define FH101RF_CALIB_STATUS_ADDRESS  (0x6U) //!< CALIB_STATUS register address
#define FH101RF_CALIB_STATUS_RESET_LE {0x0U} //!< CALIB_STATUS register reset value
#define FH101RF_CALIB_STATUS_RESET_BE {0x0U} //!< CALIB_STATUS register reset value

// Register Layout Struct:

/**
 * @brief Indicates status of all calibration processes.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_calib_status {
  /** @brief Indicates general calibration process in progress. */
  bool cal_in_prog;
  /** @brief Indicates LCO calibration in progress. */
  bool lco_cal_in_prog;
  /** @brief Indicates Offset calubration in progress. */
  bool offset_cal_in_prog;
  /** @brief Indicates SPG calibration in progress. */
  bool spg_cal_in_prog;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_calib_status struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_calib_status_pack_le(const struct fh101rf_calib_status *r, uint8_t val[1]) {
  // CAL_IN_PROG @ calib_status[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->cal_in_prog) & 0x1U);
  // LCO_CAL_IN_PROG @ calib_status[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->lco_cal_in_prog << 1)) & 0x2U);
  // OFFSET_CAL_IN_PROG @ calib_status[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->offset_cal_in_prog << 3)) & 0x8U);
  // SPG_CAL_IN_PROG @ calib_status[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->spg_cal_in_prog << 2)) & 0x4U);
}

/**
 * @brief Convert @ref struct fh101rf_calib_status struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_calib_status_pack_be(const struct fh101rf_calib_status *r, uint8_t val[1]) {
  // CAL_IN_PROG @ calib_status[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->cal_in_prog) & 0x1U);
  // LCO_CAL_IN_PROG @ calib_status[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->lco_cal_in_prog << 1)) & 0x2U);
  // OFFSET_CAL_IN_PROG @ calib_status[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->offset_cal_in_prog << 3)) & 0x8U);
  // SPG_CAL_IN_PROG @ calib_status[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->spg_cal_in_prog << 2)) & 0x4U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_calib_status fh101rf_calib_status_unpack_le(const uint8_t val[1]) {
  struct fh101rf_calib_status r = {0};
  // CAL_IN_PROG @ calib_status[0]:
  r.cal_in_prog = (bool)((val[0] & 0x1U));
  // LCO_CAL_IN_PROG @ calib_status[1]:
  r.lco_cal_in_prog = (bool)(((val[0] & 0x2U) >> 1));
  // OFFSET_CAL_IN_PROG @ calib_status[3]:
  r.offset_cal_in_prog = (bool)(((val[0] & 0x8U) >> 3));
  // SPG_CAL_IN_PROG @ calib_status[2]:
  r.spg_cal_in_prog = (bool)(((val[0] & 0x4U) >> 2));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_calib_status fh101rf_calib_status_unpack_be(const uint8_t val[1]) {
  struct fh101rf_calib_status r = {0};
  // CAL_IN_PROG @ calib_status[0]:
  r.cal_in_prog = (bool)((val[0] & 0x1U));
  // LCO_CAL_IN_PROG @ calib_status[1]:
  r.lco_cal_in_prog = (bool)(((val[0] & 0x2U) >> 1));
  // OFFSET_CAL_IN_PROG @ calib_status[3]:
  r.offset_cal_in_prog = (bool)(((val[0] & 0x8U) >> 3));
  // SPG_CAL_IN_PROG @ calib_status[2]:
  r.spg_cal_in_prog = (bool)(((val[0] & 0x4U) >> 2));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_calib_status(const struct fh101rf_calib_status *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_calib_status_try_unpack_le(const uint8_t val[1], struct fh101rf_calib_status *r) {
  *r = fh101rf_calib_status_unpack_le(val);
  return fh101rf_validate_calib_status(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_calib_status_try_unpack_be(const uint8_t val[1], struct fh101rf_calib_status *r) {
  *r = fh101rf_calib_status_unpack_be(val);
  return fh101rf_validate_calib_status(r);
}

// =============================================================================
// ==== CNTR40_0 Register ======================================================
// =============================================================================
// Bits 7:0 of the system clock counter CNTR40.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_CNTR40_0_ADDRESS  (0x54U) //!< CNTR40_0 register address
#define FH101RF_CNTR40_0_RESET_LE {0x0U}  //!< CNTR40_0 register reset value
#define FH101RF_CNTR40_0_RESET_BE {0x0U}  //!< CNTR40_0 register reset value

// Register Layout Struct:

/**
 * @brief Bits 7:0 of the system clock counter CNTR40.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_cntr40_0 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_cntr40_0 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_0_pack_le(const struct fh101rf_cntr40_0 *r, uint8_t val[1]) {
  // DATA @ cntr40_0[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_cntr40_0 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_0_pack_be(const struct fh101rf_cntr40_0 *r, uint8_t val[1]) {
  // DATA @ cntr40_0[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_0 fh101rf_cntr40_0_unpack_le(const uint8_t val[1]) {
  struct fh101rf_cntr40_0 r = {0};
  // DATA @ cntr40_0[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_0 fh101rf_cntr40_0_unpack_be(const uint8_t val[1]) {
  struct fh101rf_cntr40_0 r = {0};
  // DATA @ cntr40_0[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_cntr40_0(const struct fh101rf_cntr40_0 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_0_try_unpack_le(const uint8_t val[1], struct fh101rf_cntr40_0 *r) {
  *r = fh101rf_cntr40_0_unpack_le(val);
  return fh101rf_validate_cntr40_0(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_0_try_unpack_be(const uint8_t val[1], struct fh101rf_cntr40_0 *r) {
  *r = fh101rf_cntr40_0_unpack_be(val);
  return fh101rf_validate_cntr40_0(r);
}

// =============================================================================
// ==== CNTR40_1 Register ======================================================
// =============================================================================
// Bits 15:8 of the system clock counter CNTR40.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_CNTR40_1_ADDRESS  (0x53U) //!< CNTR40_1 register address
#define FH101RF_CNTR40_1_RESET_LE {0x0U}  //!< CNTR40_1 register reset value
#define FH101RF_CNTR40_1_RESET_BE {0x0U}  //!< CNTR40_1 register reset value

// Register Layout Struct:

/**
 * @brief Bits 15:8 of the system clock counter CNTR40.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_cntr40_1 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_cntr40_1 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_1_pack_le(const struct fh101rf_cntr40_1 *r, uint8_t val[1]) {
  // DATA @ cntr40_1[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_cntr40_1 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_1_pack_be(const struct fh101rf_cntr40_1 *r, uint8_t val[1]) {
  // DATA @ cntr40_1[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_1 fh101rf_cntr40_1_unpack_le(const uint8_t val[1]) {
  struct fh101rf_cntr40_1 r = {0};
  // DATA @ cntr40_1[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_1 fh101rf_cntr40_1_unpack_be(const uint8_t val[1]) {
  struct fh101rf_cntr40_1 r = {0};
  // DATA @ cntr40_1[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_cntr40_1(const struct fh101rf_cntr40_1 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_1_try_unpack_le(const uint8_t val[1], struct fh101rf_cntr40_1 *r) {
  *r = fh101rf_cntr40_1_unpack_le(val);
  return fh101rf_validate_cntr40_1(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_1_try_unpack_be(const uint8_t val[1], struct fh101rf_cntr40_1 *r) {
  *r = fh101rf_cntr40_1_unpack_be(val);
  return fh101rf_validate_cntr40_1(r);
}

// =============================================================================
// ==== CNTR40_2 Register ======================================================
// =============================================================================
// Bits 23:16 of the system clock counter CNTR40.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_CNTR40_2_ADDRESS  (0x52U) //!< CNTR40_2 register address
#define FH101RF_CNTR40_2_RESET_LE {0x0U}  //!< CNTR40_2 register reset value
#define FH101RF_CNTR40_2_RESET_BE {0x0U}  //!< CNTR40_2 register reset value

// Register Layout Struct:

/**
 * @brief Bits 23:16 of the system clock counter CNTR40.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_cntr40_2 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_cntr40_2 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_2_pack_le(const struct fh101rf_cntr40_2 *r, uint8_t val[1]) {
  // DATA @ cntr40_2[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_cntr40_2 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_2_pack_be(const struct fh101rf_cntr40_2 *r, uint8_t val[1]) {
  // DATA @ cntr40_2[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_2 fh101rf_cntr40_2_unpack_le(const uint8_t val[1]) {
  struct fh101rf_cntr40_2 r = {0};
  // DATA @ cntr40_2[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_2 fh101rf_cntr40_2_unpack_be(const uint8_t val[1]) {
  struct fh101rf_cntr40_2 r = {0};
  // DATA @ cntr40_2[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_cntr40_2(const struct fh101rf_cntr40_2 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_2_try_unpack_le(const uint8_t val[1], struct fh101rf_cntr40_2 *r) {
  *r = fh101rf_cntr40_2_unpack_le(val);
  return fh101rf_validate_cntr40_2(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_2_try_unpack_be(const uint8_t val[1], struct fh101rf_cntr40_2 *r) {
  *r = fh101rf_cntr40_2_unpack_be(val);
  return fh101rf_validate_cntr40_2(r);
}

// =============================================================================
// ==== CNTR40_3 Register ======================================================
// =============================================================================
// Bits 31:24 of the system clock counter CNTR40.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_CNTR40_3_ADDRESS  (0x51U) //!< CNTR40_3 register address
#define FH101RF_CNTR40_3_RESET_LE {0x0U}  //!< CNTR40_3 register reset value
#define FH101RF_CNTR40_3_RESET_BE {0x0U}  //!< CNTR40_3 register reset value

// Register Layout Struct:

/**
 * @brief Bits 31:24 of the system clock counter CNTR40.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_cntr40_3 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_cntr40_3 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_3_pack_le(const struct fh101rf_cntr40_3 *r, uint8_t val[1]) {
  // DATA @ cntr40_3[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_cntr40_3 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_3_pack_be(const struct fh101rf_cntr40_3 *r, uint8_t val[1]) {
  // DATA @ cntr40_3[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_3 fh101rf_cntr40_3_unpack_le(const uint8_t val[1]) {
  struct fh101rf_cntr40_3 r = {0};
  // DATA @ cntr40_3[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_3 fh101rf_cntr40_3_unpack_be(const uint8_t val[1]) {
  struct fh101rf_cntr40_3 r = {0};
  // DATA @ cntr40_3[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_cntr40_3(const struct fh101rf_cntr40_3 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_3_try_unpack_le(const uint8_t val[1], struct fh101rf_cntr40_3 *r) {
  *r = fh101rf_cntr40_3_unpack_le(val);
  return fh101rf_validate_cntr40_3(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_3_try_unpack_be(const uint8_t val[1], struct fh101rf_cntr40_3 *r) {
  *r = fh101rf_cntr40_3_unpack_be(val);
  return fh101rf_validate_cntr40_3(r);
}

// =============================================================================
// ==== CNTR40_4 Register ======================================================
// =============================================================================
// Bits 39:32 of the system clock counter CNTR40.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_CNTR40_4_ADDRESS  (0x50U) //!< CNTR40_4 register address
#define FH101RF_CNTR40_4_RESET_LE {0x0U}  //!< CNTR40_4 register reset value
#define FH101RF_CNTR40_4_RESET_BE {0x0U}  //!< CNTR40_4 register reset value

// Register Layout Struct:

/**
 * @brief Bits 39:32 of the system clock counter CNTR40.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_cntr40_4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_cntr40_4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_4_pack_le(const struct fh101rf_cntr40_4 *r, uint8_t val[1]) {
  // DATA @ cntr40_4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_cntr40_4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_4_pack_be(const struct fh101rf_cntr40_4 *r, uint8_t val[1]) {
  // DATA @ cntr40_4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_4 fh101rf_cntr40_4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_cntr40_4 r = {0};
  // DATA @ cntr40_4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_4 fh101rf_cntr40_4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_cntr40_4 r = {0};
  // DATA @ cntr40_4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_cntr40_4(const struct fh101rf_cntr40_4 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_4_try_unpack_le(const uint8_t val[1], struct fh101rf_cntr40_4 *r) {
  *r = fh101rf_cntr40_4_unpack_le(val);
  return fh101rf_validate_cntr40_4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_4_try_unpack_be(const uint8_t val[1], struct fh101rf_cntr40_4 *r) {
  *r = fh101rf_cntr40_4_unpack_be(val);
  return fh101rf_validate_cntr40_4(r);
}

// =============================================================================
// ==== CNTR40_CLR Register ====================================================
// =============================================================================
// Clear the system clock counter CNTR40 by setting this to true. Manually setting the register to false afterwards is mandatory!
// Fields:
//  - [0] CLR (bool)

#define FH101RF_CNTR40_CLR_ADDRESS  (0x55U) //!< CNTR40_CLR register address
#define FH101RF_CNTR40_CLR_RESET_LE {0x0U}  //!< CNTR40_CLR register reset value
#define FH101RF_CNTR40_CLR_RESET_BE {0x0U}  //!< CNTR40_CLR register reset value

// Register Layout Struct:

/**
 * @brief Clear the system clock counter CNTR40 by setting this to true. Manually setting the register to false afterwards is mandatory!
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_cntr40_clr {
  bool clr;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_cntr40_clr struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_clr_pack_le(const struct fh101rf_cntr40_clr *r, uint8_t val[1]) {
  // CLR @ cntr40_clr[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->clr) & 0x1U);
}

/**
 * @brief Convert @ref struct fh101rf_cntr40_clr struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cntr40_clr_pack_be(const struct fh101rf_cntr40_clr *r, uint8_t val[1]) {
  // CLR @ cntr40_clr[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->clr) & 0x1U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_clr fh101rf_cntr40_clr_unpack_le(const uint8_t val[1]) {
  struct fh101rf_cntr40_clr r = {0};
  // CLR @ cntr40_clr[0]:
  r.clr = (bool)((val[0] & 0x1U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cntr40_clr fh101rf_cntr40_clr_unpack_be(const uint8_t val[1]) {
  struct fh101rf_cntr40_clr r = {0};
  // CLR @ cntr40_clr[0]:
  r.clr = (bool)((val[0] & 0x1U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_cntr40_clr(const struct fh101rf_cntr40_clr *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_clr_try_unpack_le(const uint8_t val[1], struct fh101rf_cntr40_clr *r) {
  *r = fh101rf_cntr40_clr_unpack_le(val);
  return fh101rf_validate_cntr40_clr(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cntr40_clr_try_unpack_be(const uint8_t val[1], struct fh101rf_cntr40_clr *r) {
  *r = fh101rf_cntr40_clr_unpack_be(val);
  return fh101rf_validate_cntr40_clr(r);
}

// =============================================================================
// ==== CODE_SELECT Register ===================================================
// =============================================================================
// Selects the correlation patterns for code A and B.
// Fields:
//  - [3:0] A (enum BIN_CODE): Selects the correlation pattern for code A.
//  - [7:4] B (enum BIN_CODE): Selects the correlation pattern for code B.

#define FH101RF_CODE_SELECT_ADDRESS  (0x28U) //!< CODE_SELECT register address
#define FH101RF_CODE_SELECT_RESET_LE {0x10U} //!< CODE_SELECT register reset value
#define FH101RF_CODE_SELECT_RESET_BE {0x10U} //!< CODE_SELECT register reset value

// Register Layout Struct:

/**
 * @brief Selects the correlation patterns for code A and B.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_code_select {
  /** @brief Selects the correlation pattern for code A. */
  enum fh101rf_bin_code a;
  /** @brief Selects the correlation pattern for code B. */
  enum fh101rf_bin_code b;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_code_select struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_code_select_pack_le(const struct fh101rf_code_select *r, uint8_t val[1]) {
  // A @ code_select[3:0]:
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)(((uint8_t)r->a) & 0xFU);
  // B @ code_select[7:4]:
  val[0] &= (uint8_t)~0xF0U;
  val[0] |= (uint8_t)(((uint8_t)(r->b << 4)) & 0xF0U);
}

/**
 * @brief Convert @ref struct fh101rf_code_select struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_code_select_pack_be(const struct fh101rf_code_select *r, uint8_t val[1]) {
  // A @ code_select[3:0]:
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)(((uint8_t)r->a) & 0xFU);
  // B @ code_select[7:4]:
  val[0] &= (uint8_t)~0xF0U;
  val[0] |= (uint8_t)(((uint8_t)(r->b << 4)) & 0xF0U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_code_select fh101rf_code_select_unpack_le(const uint8_t val[1]) {
  struct fh101rf_code_select r = {0};
  // A @ code_select[3:0]:
  r.a = (enum fh101rf_bin_code)((val[0] & 0xFU));
  // B @ code_select[7:4]:
  r.b = (enum fh101rf_bin_code)(((val[0] & 0xF0U) >> 4));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_code_select fh101rf_code_select_unpack_be(const uint8_t val[1]) {
  struct fh101rf_code_select r = {0};
  // A @ code_select[3:0]:
  r.a = (enum fh101rf_bin_code)((val[0] & 0xFU));
  // B @ code_select[7:4]:
  r.b = (enum fh101rf_bin_code)(((val[0] & 0xF0U) >> 4));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_code_select(const struct fh101rf_code_select *r) {
  if (!(FH101RF_IS_VALID_BIN_CODE(r->a))) return 1;
  if (!(FH101RF_IS_VALID_BIN_CODE(r->b))) return 5;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_code_select_try_unpack_le(const uint8_t val[1], struct fh101rf_code_select *r) {
  *r = fh101rf_code_select_unpack_le(val);
  return fh101rf_validate_code_select(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_code_select_try_unpack_be(const uint8_t val[1], struct fh101rf_code_select *r) {
  *r = fh101rf_code_select_unpack_be(val);
  return fh101rf_validate_code_select(r);
}

// =============================================================================
// ==== COMP_THRESH_W Register =================================================
// =============================================================================
// Set this register to 0xA before executing the comparator calibration.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_COMP_THRESH_W_ADDRESS  (0x78U) //!< COMP_THRESH_W register address
#define FH101RF_COMP_THRESH_W_RESET_LE {0x0U}  //!< COMP_THRESH_W register reset value
#define FH101RF_COMP_THRESH_W_RESET_BE {0x0U}  //!< COMP_THRESH_W register reset value

// Register Layout Struct:

/**
 * @brief Set this register to 0xA before executing the comparator calibration.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_comp_thresh_w {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_comp_thresh_w struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_comp_thresh_w_pack_le(const struct fh101rf_comp_thresh_w *r, uint8_t val[1]) {
  // DATA @ comp_thresh_w[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_comp_thresh_w struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_comp_thresh_w_pack_be(const struct fh101rf_comp_thresh_w *r, uint8_t val[1]) {
  // DATA @ comp_thresh_w[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_comp_thresh_w fh101rf_comp_thresh_w_unpack_le(const uint8_t val[1]) {
  struct fh101rf_comp_thresh_w r = {0};
  // DATA @ comp_thresh_w[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_comp_thresh_w fh101rf_comp_thresh_w_unpack_be(const uint8_t val[1]) {
  struct fh101rf_comp_thresh_w r = {0};
  // DATA @ comp_thresh_w[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_comp_thresh_w(const struct fh101rf_comp_thresh_w *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_comp_thresh_w_try_unpack_le(const uint8_t val[1], struct fh101rf_comp_thresh_w *r) {
  *r = fh101rf_comp_thresh_w_unpack_le(val);
  return fh101rf_validate_comp_thresh_w(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_comp_thresh_w_try_unpack_be(const uint8_t val[1], struct fh101rf_comp_thresh_w *r) {
  *r = fh101rf_comp_thresh_w_unpack_be(val);
  return fh101rf_validate_comp_thresh_w(r);
}

// =============================================================================
// ==== CYCLPRESC Register =====================================================
// =============================================================================
// Cycle prescaler for cyclic counter, system clock divided by prescaler (therefore max 8:29.9922 minutes).
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_CYCLPRESC_ADDRESS  (0x4DU) //!< CYCLPRESC register address
#define FH101RF_CYCLPRESC_RESET_LE {0x0U}  //!< CYCLPRESC register reset value
#define FH101RF_CYCLPRESC_RESET_BE {0x0U}  //!< CYCLPRESC register reset value

// Register Layout Struct:

/**
 * @brief Cycle prescaler for cyclic counter, system clock divided by prescaler (therefore max 8:29.9922 minutes).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_cyclpresc {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_cyclpresc struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cyclpresc_pack_le(const struct fh101rf_cyclpresc *r, uint8_t val[1]) {
  // DATA @ cyclpresc[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_cyclpresc struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cyclpresc_pack_be(const struct fh101rf_cyclpresc *r, uint8_t val[1]) {
  // DATA @ cyclpresc[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cyclpresc fh101rf_cyclpresc_unpack_le(const uint8_t val[1]) {
  struct fh101rf_cyclpresc r = {0};
  // DATA @ cyclpresc[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cyclpresc fh101rf_cyclpresc_unpack_be(const uint8_t val[1]) {
  struct fh101rf_cyclpresc r = {0};
  // DATA @ cyclpresc[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_cyclpresc(const struct fh101rf_cyclpresc *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cyclpresc_try_unpack_le(const uint8_t val[1], struct fh101rf_cyclpresc *r) {
  *r = fh101rf_cyclpresc_unpack_le(val);
  return fh101rf_validate_cyclpresc(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cyclpresc_try_unpack_be(const uint8_t val[1], struct fh101rf_cyclpresc *r) {
  *r = fh101rf_cyclpresc_unpack_be(val);
  return fh101rf_validate_cyclpresc(r);
}

// =============================================================================
// ==== CYCLTOP_HI Register ====================================================
// =============================================================================
// Bits 15:8 defining the maximal cyclic counter value CYCLTOP before being reset to zero.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_CYCLTOP_HI_ADDRESS  (0x4EU) //!< CYCLTOP_HI register address
#define FH101RF_CYCLTOP_HI_RESET_LE {0x0U}  //!< CYCLTOP_HI register reset value
#define FH101RF_CYCLTOP_HI_RESET_BE {0x0U}  //!< CYCLTOP_HI register reset value

// Register Layout Struct:

/**
 * @brief Bits 15:8 defining the maximal cyclic counter value CYCLTOP before being reset to zero.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_cycltop_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_cycltop_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cycltop_hi_pack_le(const struct fh101rf_cycltop_hi *r, uint8_t val[1]) {
  // DATA @ cycltop_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_cycltop_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cycltop_hi_pack_be(const struct fh101rf_cycltop_hi *r, uint8_t val[1]) {
  // DATA @ cycltop_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cycltop_hi fh101rf_cycltop_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_cycltop_hi r = {0};
  // DATA @ cycltop_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cycltop_hi fh101rf_cycltop_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_cycltop_hi r = {0};
  // DATA @ cycltop_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_cycltop_hi(const struct fh101rf_cycltop_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cycltop_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_cycltop_hi *r) {
  *r = fh101rf_cycltop_hi_unpack_le(val);
  return fh101rf_validate_cycltop_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cycltop_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_cycltop_hi *r) {
  *r = fh101rf_cycltop_hi_unpack_be(val);
  return fh101rf_validate_cycltop_hi(r);
}

// =============================================================================
// ==== CYCLTOP_LO Register ====================================================
// =============================================================================
// Bits 7:0 defining the maximal cyclic counter value CYCLTOP before being reset to zero.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_CYCLTOP_LO_ADDRESS  (0x4FU) //!< CYCLTOP_LO register address
#define FH101RF_CYCLTOP_LO_RESET_LE {0x0U}  //!< CYCLTOP_LO register reset value
#define FH101RF_CYCLTOP_LO_RESET_BE {0x0U}  //!< CYCLTOP_LO register reset value

// Register Layout Struct:

/**
 * @brief Bits 7:0 defining the maximal cyclic counter value CYCLTOP before being reset to zero.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_cycltop_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_cycltop_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cycltop_lo_pack_le(const struct fh101rf_cycltop_lo *r, uint8_t val[1]) {
  // DATA @ cycltop_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_cycltop_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_cycltop_lo_pack_be(const struct fh101rf_cycltop_lo *r, uint8_t val[1]) {
  // DATA @ cycltop_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cycltop_lo fh101rf_cycltop_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_cycltop_lo r = {0};
  // DATA @ cycltop_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_cycltop_lo fh101rf_cycltop_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_cycltop_lo r = {0};
  // DATA @ cycltop_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_cycltop_lo(const struct fh101rf_cycltop_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cycltop_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_cycltop_lo *r) {
  *r = fh101rf_cycltop_lo_unpack_le(val);
  return fh101rf_validate_cycltop_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_cycltop_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_cycltop_lo *r) {
  *r = fh101rf_cycltop_lo_unpack_be(val);
  return fh101rf_validate_cycltop_lo(r);
}

// =============================================================================
// ==== D_CORNER_CTRL Register =================================================
// =============================================================================
// Set to 0x02 at power-up.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_D_CORNER_CTRL_ADDRESS  (0x23U) //!< D_CORNER_CTRL register address
#define FH101RF_D_CORNER_CTRL_RESET_LE {0x0U}  //!< D_CORNER_CTRL register reset value
#define FH101RF_D_CORNER_CTRL_RESET_BE {0x0U}  //!< D_CORNER_CTRL register reset value

// Register Layout Struct:

/**
 * @brief Set to 0x02 at power-up.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_d_corner_ctrl {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_d_corner_ctrl struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_d_corner_ctrl_pack_le(const struct fh101rf_d_corner_ctrl *r, uint8_t val[1]) {
  // DATA @ d_corner_ctrl[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_d_corner_ctrl struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_d_corner_ctrl_pack_be(const struct fh101rf_d_corner_ctrl *r, uint8_t val[1]) {
  // DATA @ d_corner_ctrl[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_d_corner_ctrl fh101rf_d_corner_ctrl_unpack_le(const uint8_t val[1]) {
  struct fh101rf_d_corner_ctrl r = {0};
  // DATA @ d_corner_ctrl[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_d_corner_ctrl fh101rf_d_corner_ctrl_unpack_be(const uint8_t val[1]) {
  struct fh101rf_d_corner_ctrl r = {0};
  // DATA @ d_corner_ctrl[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_d_corner_ctrl(const struct fh101rf_d_corner_ctrl *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_d_corner_ctrl_try_unpack_le(const uint8_t val[1], struct fh101rf_d_corner_ctrl *r) {
  *r = fh101rf_d_corner_ctrl_unpack_le(val);
  return fh101rf_validate_d_corner_ctrl(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_d_corner_ctrl_try_unpack_be(const uint8_t val[1], struct fh101rf_d_corner_ctrl *r) {
  *r = fh101rf_d_corner_ctrl_unpack_be(val);
  return fh101rf_validate_d_corner_ctrl(r);
}

// =============================================================================
// ==== FDD_ACTIVE Register ====================================================
// =============================================================================
// Reads the FDD mode for each band.
// Fields:
//  - [0] BAND_2G4 (enum FDD_MODE)
//  - [1] BAND_868 (enum FDD_MODE)
//  - [2] BAND_433 (enum FDD_MODE)

#define FH101RF_FDD_ACTIVE_ADDRESS  (0x2EU) //!< FDD_ACTIVE register address
#define FH101RF_FDD_ACTIVE_RESET_LE {0x0U}  //!< FDD_ACTIVE register reset value
#define FH101RF_FDD_ACTIVE_RESET_BE {0x0U}  //!< FDD_ACTIVE register reset value

// Register Layout Struct:

/**
 * @brief Reads the FDD mode for each band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_fdd_active {
  enum fh101rf_fdd_mode band_2g4;
  enum fh101rf_fdd_mode band_433;
  enum fh101rf_fdd_mode band_868;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_fdd_active struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fdd_active_pack_le(const struct fh101rf_fdd_active *r, uint8_t val[1]) {
  // BAND_2G4 @ fdd_active[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->band_2g4) & 0x1U);
  // BAND_433 @ fdd_active[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_433 << 2)) & 0x4U);
  // BAND_868 @ fdd_active[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_868 << 1)) & 0x2U);
}

/**
 * @brief Convert @ref struct fh101rf_fdd_active struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fdd_active_pack_be(const struct fh101rf_fdd_active *r, uint8_t val[1]) {
  // BAND_2G4 @ fdd_active[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->band_2g4) & 0x1U);
  // BAND_433 @ fdd_active[2]:
  val[0] &= (uint8_t)~0x4U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_433 << 2)) & 0x4U);
  // BAND_868 @ fdd_active[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_868 << 1)) & 0x2U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fdd_active fh101rf_fdd_active_unpack_le(const uint8_t val[1]) {
  struct fh101rf_fdd_active r = {0};
  // BAND_2G4 @ fdd_active[0]:
  r.band_2g4 = (enum fh101rf_fdd_mode)((val[0] & 0x1U));
  // BAND_433 @ fdd_active[2]:
  r.band_433 = (enum fh101rf_fdd_mode)(((val[0] & 0x4U) >> 2));
  // BAND_868 @ fdd_active[1]:
  r.band_868 = (enum fh101rf_fdd_mode)(((val[0] & 0x2U) >> 1));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fdd_active fh101rf_fdd_active_unpack_be(const uint8_t val[1]) {
  struct fh101rf_fdd_active r = {0};
  // BAND_2G4 @ fdd_active[0]:
  r.band_2g4 = (enum fh101rf_fdd_mode)((val[0] & 0x1U));
  // BAND_433 @ fdd_active[2]:
  r.band_433 = (enum fh101rf_fdd_mode)(((val[0] & 0x4U) >> 2));
  // BAND_868 @ fdd_active[1]:
  r.band_868 = (enum fh101rf_fdd_mode)(((val[0] & 0x2U) >> 1));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_fdd_active(const struct fh101rf_fdd_active *r) {
  if (!(FH101RF_IS_VALID_FDD_MODE(r->band_2g4))) return 1;
  if (!(FH101RF_IS_VALID_FDD_MODE(r->band_433))) return 3;
  if (!(FH101RF_IS_VALID_FDD_MODE(r->band_868))) return 2;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fdd_active_try_unpack_le(const uint8_t val[1], struct fh101rf_fdd_active *r) {
  *r = fh101rf_fdd_active_unpack_le(val);
  return fh101rf_validate_fdd_active(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fdd_active_try_unpack_be(const uint8_t val[1], struct fh101rf_fdd_active *r) {
  *r = fh101rf_fdd_active_unpack_be(val);
  return fh101rf_validate_fdd_active(r);
}

// =============================================================================
// ==== FDD_ENABLE Register ====================================================
// =============================================================================
// Enable the fast data decoder for a given band.
// Fields:
//  - [2:0] FDD_BANDS (layout BANDS)
//    - [0] FDD_BANDS.BAND_433 (bool): True means on for 433MHz band.
//    - [1] FDD_BANDS.BAND_868 (bool): True means on for 868/915MHz band.
//    - [2] FDD_BANDS.BAND_2G4 (bool): True means on for 2.4GHz band.

#define FH101RF_FDD_ENABLE_ADDRESS  (0x2DU) //!< FDD_ENABLE register address
#define FH101RF_FDD_ENABLE_RESET_LE {0x7U}  //!< FDD_ENABLE register reset value
#define FH101RF_FDD_ENABLE_RESET_BE {0x7U}  //!< FDD_ENABLE register reset value

// Register Layout Struct:

/**
 * @brief Enable the fast data decoder for a given band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_fdd_enable {
  struct fh101rf_bands fdd_bands;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_fdd_enable struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fdd_enable_pack_le(const struct fh101rf_fdd_enable *r, uint8_t val[1]) {
  // FDD_BANDS @ fdd_enable[2:0]:
  uint8_t fdd_bands[1] = {0};
  fh101rf_bands_pack_le(&r->fdd_bands, fdd_bands);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)fdd_bands[0] & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_fdd_enable struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fdd_enable_pack_be(const struct fh101rf_fdd_enable *r, uint8_t val[1]) {
  // FDD_BANDS @ fdd_enable[2:0]:
  uint8_t fdd_bands[1] = {0};
  fh101rf_bands_pack_be(&r->fdd_bands, fdd_bands);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)fdd_bands[0] & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fdd_enable fh101rf_fdd_enable_unpack_le(const uint8_t val[1]) {
  struct fh101rf_fdd_enable r = {0};
  // FDD_BANDS @ fdd_enable[2:0]:
  uint8_t fdd_bands[1] = {0};
  fdd_bands[0] |= (uint8_t)((val[0] & 0x7U));
  r.fdd_bands = fh101rf_bands_unpack_le(fdd_bands);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fdd_enable fh101rf_fdd_enable_unpack_be(const uint8_t val[1]) {
  struct fh101rf_fdd_enable r = {0};
  // FDD_BANDS @ fdd_enable[2:0]:
  uint8_t fdd_bands[1] = {0};
  fdd_bands[0] |= (uint8_t)((val[0] & 0x7U));
  r.fdd_bands = fh101rf_bands_unpack_be(fdd_bands);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_fdd_enable(const struct fh101rf_fdd_enable *r) {
  if (fh101rf_validate_bands(&r->fdd_bands)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fdd_enable_try_unpack_le(const uint8_t val[1], struct fh101rf_fdd_enable *r) {
  *r = fh101rf_fdd_enable_unpack_le(val);
  return fh101rf_validate_fdd_enable(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fdd_enable_try_unpack_be(const uint8_t val[1], struct fh101rf_fdd_enable *r) {
  *r = fh101rf_fdd_enable_unpack_be(val);
  return fh101rf_validate_fdd_enable(r);
}

// =============================================================================
// ==== FDD_EXIT_COND Register =================================================
// =============================================================================
// Holds the FDD exit condition for all the bands.
// Fields:
//  - [1:0] BAND_433 (enum EXIT_COND)
//  - [3:2] BAND_868 (enum EXIT_COND)
//  - [5:4] BAND_2G4 (enum EXIT_COND)

#define FH101RF_FDD_EXIT_COND_ADDRESS  (0x30U) //!< FDD_EXIT_COND register address
#define FH101RF_FDD_EXIT_COND_RESET_LE {0x0U}  //!< FDD_EXIT_COND register reset value
#define FH101RF_FDD_EXIT_COND_RESET_BE {0x0U}  //!< FDD_EXIT_COND register reset value

// Register Layout Struct:

/**
 * @brief Holds the FDD exit condition for all the bands.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_fdd_exit_cond {
  enum fh101rf_exit_cond band_2g4;
  enum fh101rf_exit_cond band_433;
  enum fh101rf_exit_cond band_868;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_fdd_exit_cond struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fdd_exit_cond_pack_le(const struct fh101rf_fdd_exit_cond *r, uint8_t val[1]) {
  // BAND_2G4 @ fdd_exit_cond[5:4]:
  val[0] &= (uint8_t)~0x30U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_2g4 << 4)) & 0x30U);
  // BAND_433 @ fdd_exit_cond[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->band_433) & 0x3U);
  // BAND_868 @ fdd_exit_cond[3:2]:
  val[0] &= (uint8_t)~0xCU;
  val[0] |= (uint8_t)(((uint8_t)(r->band_868 << 2)) & 0xCU);
}

/**
 * @brief Convert @ref struct fh101rf_fdd_exit_cond struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fdd_exit_cond_pack_be(const struct fh101rf_fdd_exit_cond *r, uint8_t val[1]) {
  // BAND_2G4 @ fdd_exit_cond[5:4]:
  val[0] &= (uint8_t)~0x30U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_2g4 << 4)) & 0x30U);
  // BAND_433 @ fdd_exit_cond[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->band_433) & 0x3U);
  // BAND_868 @ fdd_exit_cond[3:2]:
  val[0] &= (uint8_t)~0xCU;
  val[0] |= (uint8_t)(((uint8_t)(r->band_868 << 2)) & 0xCU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fdd_exit_cond fh101rf_fdd_exit_cond_unpack_le(const uint8_t val[1]) {
  struct fh101rf_fdd_exit_cond r = {0};
  // BAND_2G4 @ fdd_exit_cond[5:4]:
  r.band_2g4 = (enum fh101rf_exit_cond)(((val[0] & 0x30U) >> 4));
  // BAND_433 @ fdd_exit_cond[1:0]:
  r.band_433 = (enum fh101rf_exit_cond)((val[0] & 0x3U));
  // BAND_868 @ fdd_exit_cond[3:2]:
  r.band_868 = (enum fh101rf_exit_cond)(((val[0] & 0xCU) >> 2));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fdd_exit_cond fh101rf_fdd_exit_cond_unpack_be(const uint8_t val[1]) {
  struct fh101rf_fdd_exit_cond r = {0};
  // BAND_2G4 @ fdd_exit_cond[5:4]:
  r.band_2g4 = (enum fh101rf_exit_cond)(((val[0] & 0x30U) >> 4));
  // BAND_433 @ fdd_exit_cond[1:0]:
  r.band_433 = (enum fh101rf_exit_cond)((val[0] & 0x3U));
  // BAND_868 @ fdd_exit_cond[3:2]:
  r.band_868 = (enum fh101rf_exit_cond)(((val[0] & 0xCU) >> 2));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_fdd_exit_cond(const struct fh101rf_fdd_exit_cond *r) {
  if (!(FH101RF_IS_VALID_EXIT_COND(r->band_2g4))) return 5;
  if (!(FH101RF_IS_VALID_EXIT_COND(r->band_433))) return 1;
  if (!(FH101RF_IS_VALID_EXIT_COND(r->band_868))) return 3;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fdd_exit_cond_try_unpack_le(const uint8_t val[1], struct fh101rf_fdd_exit_cond *r) {
  *r = fh101rf_fdd_exit_cond_unpack_le(val);
  return fh101rf_validate_fdd_exit_cond(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fdd_exit_cond_try_unpack_be(const uint8_t val[1], struct fh101rf_fdd_exit_cond *r) {
  *r = fh101rf_fdd_exit_cond_unpack_be(val);
  return fh101rf_validate_fdd_exit_cond(r);
}

// =============================================================================
// ==== FIFO_COUNT_2G4 Register ================================================
// =============================================================================
// Number of bits in the FIFO buffer for the 2.4GHz band. Can be cleared by writing 0.
// Fields:
//  - [5:0] DATA (uint)

#define FH101RF_FIFO_COUNT_2G4_ADDRESS  (0x59U) //!< FIFO_COUNT_2G4 register address
#define FH101RF_FIFO_COUNT_2G4_RESET_LE {0x0U}  //!< FIFO_COUNT_2G4 register reset value
#define FH101RF_FIFO_COUNT_2G4_RESET_BE {0x0U}  //!< FIFO_COUNT_2G4 register reset value

// Register Layout Struct:

/**
 * @brief Number of bits in the FIFO buffer for the 2.4GHz band. Can be cleared by writing 0.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_fifo_count_2g4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_fifo_count_2g4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fifo_count_2g4_pack_le(const struct fh101rf_fifo_count_2g4 *r, uint8_t val[1]) {
  // DATA @ fifo_count_2g4[5:0]:
  val[0] &= (uint8_t)~0x3FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x3FU);
}

/**
 * @brief Convert @ref struct fh101rf_fifo_count_2g4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fifo_count_2g4_pack_be(const struct fh101rf_fifo_count_2g4 *r, uint8_t val[1]) {
  // DATA @ fifo_count_2g4[5:0]:
  val[0] &= (uint8_t)~0x3FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x3FU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fifo_count_2g4 fh101rf_fifo_count_2g4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_fifo_count_2g4 r = {0};
  // DATA @ fifo_count_2g4[5:0]:
  r.data = (uint8_t)((val[0] & 0x3FU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fifo_count_2g4 fh101rf_fifo_count_2g4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_fifo_count_2g4 r = {0};
  // DATA @ fifo_count_2g4[5:0]:
  r.data = (uint8_t)((val[0] & 0x3FU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_fifo_count_2g4(const struct fh101rf_fifo_count_2g4 *r) {
  if ((r->data & ~(uint8_t)0x3F) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fifo_count_2g4_try_unpack_le(const uint8_t val[1], struct fh101rf_fifo_count_2g4 *r) {
  *r = fh101rf_fifo_count_2g4_unpack_le(val);
  return fh101rf_validate_fifo_count_2g4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fifo_count_2g4_try_unpack_be(const uint8_t val[1], struct fh101rf_fifo_count_2g4 *r) {
  *r = fh101rf_fifo_count_2g4_unpack_be(val);
  return fh101rf_validate_fifo_count_2g4(r);
}

// =============================================================================
// ==== FIFO_COUNT_433 Register ================================================
// =============================================================================
// Number of bits in the FIFO buffer for the 433MHz band. Can be cleared by writing 0.
// Fields:
//  - [5:0] DATA (uint)

#define FH101RF_FIFO_COUNT_433_ADDRESS  (0x57U) //!< FIFO_COUNT_433 register address
#define FH101RF_FIFO_COUNT_433_RESET_LE {0x0U}  //!< FIFO_COUNT_433 register reset value
#define FH101RF_FIFO_COUNT_433_RESET_BE {0x0U}  //!< FIFO_COUNT_433 register reset value

// Register Layout Struct:

/**
 * @brief Number of bits in the FIFO buffer for the 433MHz band. Can be cleared by writing 0.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_fifo_count_433 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_fifo_count_433 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fifo_count_433_pack_le(const struct fh101rf_fifo_count_433 *r, uint8_t val[1]) {
  // DATA @ fifo_count_433[5:0]:
  val[0] &= (uint8_t)~0x3FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x3FU);
}

/**
 * @brief Convert @ref struct fh101rf_fifo_count_433 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fifo_count_433_pack_be(const struct fh101rf_fifo_count_433 *r, uint8_t val[1]) {
  // DATA @ fifo_count_433[5:0]:
  val[0] &= (uint8_t)~0x3FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x3FU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fifo_count_433 fh101rf_fifo_count_433_unpack_le(const uint8_t val[1]) {
  struct fh101rf_fifo_count_433 r = {0};
  // DATA @ fifo_count_433[5:0]:
  r.data = (uint8_t)((val[0] & 0x3FU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fifo_count_433 fh101rf_fifo_count_433_unpack_be(const uint8_t val[1]) {
  struct fh101rf_fifo_count_433 r = {0};
  // DATA @ fifo_count_433[5:0]:
  r.data = (uint8_t)((val[0] & 0x3FU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_fifo_count_433(const struct fh101rf_fifo_count_433 *r) {
  if ((r->data & ~(uint8_t)0x3F) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fifo_count_433_try_unpack_le(const uint8_t val[1], struct fh101rf_fifo_count_433 *r) {
  *r = fh101rf_fifo_count_433_unpack_le(val);
  return fh101rf_validate_fifo_count_433(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fifo_count_433_try_unpack_be(const uint8_t val[1], struct fh101rf_fifo_count_433 *r) {
  *r = fh101rf_fifo_count_433_unpack_be(val);
  return fh101rf_validate_fifo_count_433(r);
}

// =============================================================================
// ==== FIFO_COUNT_868 Register ================================================
// =============================================================================
// Number of bits in the FIFO buffer for the 868/915MHz band. Can be cleared by writing 0.
// Fields:
//  - [5:0] DATA (uint)

#define FH101RF_FIFO_COUNT_868_ADDRESS  (0x58U) //!< FIFO_COUNT_868 register address
#define FH101RF_FIFO_COUNT_868_RESET_LE {0x0U}  //!< FIFO_COUNT_868 register reset value
#define FH101RF_FIFO_COUNT_868_RESET_BE {0x0U}  //!< FIFO_COUNT_868 register reset value

// Register Layout Struct:

/**
 * @brief Number of bits in the FIFO buffer for the 868/915MHz band. Can be cleared by writing 0.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_fifo_count_868 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_fifo_count_868 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fifo_count_868_pack_le(const struct fh101rf_fifo_count_868 *r, uint8_t val[1]) {
  // DATA @ fifo_count_868[5:0]:
  val[0] &= (uint8_t)~0x3FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x3FU);
}

/**
 * @brief Convert @ref struct fh101rf_fifo_count_868 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fifo_count_868_pack_be(const struct fh101rf_fifo_count_868 *r, uint8_t val[1]) {
  // DATA @ fifo_count_868[5:0]:
  val[0] &= (uint8_t)~0x3FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x3FU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fifo_count_868 fh101rf_fifo_count_868_unpack_le(const uint8_t val[1]) {
  struct fh101rf_fifo_count_868 r = {0};
  // DATA @ fifo_count_868[5:0]:
  r.data = (uint8_t)((val[0] & 0x3FU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fifo_count_868 fh101rf_fifo_count_868_unpack_be(const uint8_t val[1]) {
  struct fh101rf_fifo_count_868 r = {0};
  // DATA @ fifo_count_868[5:0]:
  r.data = (uint8_t)((val[0] & 0x3FU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_fifo_count_868(const struct fh101rf_fifo_count_868 *r) {
  if ((r->data & ~(uint8_t)0x3F) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fifo_count_868_try_unpack_le(const uint8_t val[1], struct fh101rf_fifo_count_868 *r) {
  *r = fh101rf_fifo_count_868_unpack_le(val);
  return fh101rf_validate_fifo_count_868(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fifo_count_868_try_unpack_be(const uint8_t val[1], struct fh101rf_fifo_count_868 *r) {
  *r = fh101rf_fifo_count_868_unpack_be(val);
  return fh101rf_validate_fifo_count_868(r);
}

// =============================================================================
// ==== FIFO_LENGTH Register ===================================================
// =============================================================================
// Selects the FIFO length for each band.
// Fields:
//  - [1:0] BAND_433 (enum FIFO_LEN)
//  - [3:2] BAND_868 (enum FIFO_LEN)
//  - [5:4] BAND_2G4 (enum FIFO_LEN)

#define FH101RF_FIFO_LENGTH_ADDRESS  (0x56U) //!< FIFO_LENGTH register address
#define FH101RF_FIFO_LENGTH_RESET_LE {0x14U} //!< FIFO_LENGTH register reset value
#define FH101RF_FIFO_LENGTH_RESET_BE {0x14U} //!< FIFO_LENGTH register reset value

// Register Layout Struct:

/**
 * @brief Selects the FIFO length for each band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_fifo_length {
  enum fh101rf_fifo_len band_2g4;
  enum fh101rf_fifo_len band_433;
  enum fh101rf_fifo_len band_868;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_fifo_length struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fifo_length_pack_le(const struct fh101rf_fifo_length *r, uint8_t val[1]) {
  // BAND_2G4 @ fifo_length[5:4]:
  val[0] &= (uint8_t)~0x30U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_2g4 << 4)) & 0x30U);
  // BAND_433 @ fifo_length[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->band_433) & 0x3U);
  // BAND_868 @ fifo_length[3:2]:
  val[0] &= (uint8_t)~0xCU;
  val[0] |= (uint8_t)(((uint8_t)(r->band_868 << 2)) & 0xCU);
}

/**
 * @brief Convert @ref struct fh101rf_fifo_length struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fifo_length_pack_be(const struct fh101rf_fifo_length *r, uint8_t val[1]) {
  // BAND_2G4 @ fifo_length[5:4]:
  val[0] &= (uint8_t)~0x30U;
  val[0] |= (uint8_t)(((uint8_t)(r->band_2g4 << 4)) & 0x30U);
  // BAND_433 @ fifo_length[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->band_433) & 0x3U);
  // BAND_868 @ fifo_length[3:2]:
  val[0] &= (uint8_t)~0xCU;
  val[0] |= (uint8_t)(((uint8_t)(r->band_868 << 2)) & 0xCU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fifo_length fh101rf_fifo_length_unpack_le(const uint8_t val[1]) {
  struct fh101rf_fifo_length r = {0};
  // BAND_2G4 @ fifo_length[5:4]:
  r.band_2g4 = (enum fh101rf_fifo_len)(((val[0] & 0x30U) >> 4));
  // BAND_433 @ fifo_length[1:0]:
  r.band_433 = (enum fh101rf_fifo_len)((val[0] & 0x3U));
  // BAND_868 @ fifo_length[3:2]:
  r.band_868 = (enum fh101rf_fifo_len)(((val[0] & 0xCU) >> 2));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fifo_length fh101rf_fifo_length_unpack_be(const uint8_t val[1]) {
  struct fh101rf_fifo_length r = {0};
  // BAND_2G4 @ fifo_length[5:4]:
  r.band_2g4 = (enum fh101rf_fifo_len)(((val[0] & 0x30U) >> 4));
  // BAND_433 @ fifo_length[1:0]:
  r.band_433 = (enum fh101rf_fifo_len)((val[0] & 0x3U));
  // BAND_868 @ fifo_length[3:2]:
  r.band_868 = (enum fh101rf_fifo_len)(((val[0] & 0xCU) >> 2));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_fifo_length(const struct fh101rf_fifo_length *r) {
  if (!(FH101RF_IS_VALID_FIFO_LEN(r->band_2g4))) return 5;
  if (!(FH101RF_IS_VALID_FIFO_LEN(r->band_433))) return 1;
  if (!(FH101RF_IS_VALID_FIFO_LEN(r->band_868))) return 3;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fifo_length_try_unpack_le(const uint8_t val[1], struct fh101rf_fifo_length *r) {
  *r = fh101rf_fifo_length_unpack_le(val);
  return fh101rf_validate_fifo_length(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fifo_length_try_unpack_be(const uint8_t val[1], struct fh101rf_fifo_length *r) {
  *r = fh101rf_fifo_length_unpack_be(val);
  return fh101rf_validate_fifo_length(r);
}

// =============================================================================
// ==== FO_QUIT Register =======================================================
// =============================================================================
// Forces the specified band to quit fast mode immediately.
// Fields:
//  - [2:0] QUIT_BANDS (layout BANDS)
//    - [0] QUIT_BANDS.BAND_433 (bool): True means on for 433MHz band.
//    - [1] QUIT_BANDS.BAND_868 (bool): True means on for 868/915MHz band.
//    - [2] QUIT_BANDS.BAND_2G4 (bool): True means on for 2.4GHz band.

#define FH101RF_FO_QUIT_ADDRESS  (0x2FU) //!< FO_QUIT register address
#define FH101RF_FO_QUIT_RESET_LE {0x0U}  //!< FO_QUIT register reset value
#define FH101RF_FO_QUIT_RESET_BE {0x0U}  //!< FO_QUIT register reset value

// Register Layout Struct:

/**
 * @brief Forces the specified band to quit fast mode immediately.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_fo_quit {
  struct fh101rf_bands quit_bands;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_fo_quit struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fo_quit_pack_le(const struct fh101rf_fo_quit *r, uint8_t val[1]) {
  // QUIT_BANDS @ fo_quit[2:0]:
  uint8_t quit_bands[1] = {0};
  fh101rf_bands_pack_le(&r->quit_bands, quit_bands);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)quit_bands[0] & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_fo_quit struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_fo_quit_pack_be(const struct fh101rf_fo_quit *r, uint8_t val[1]) {
  // QUIT_BANDS @ fo_quit[2:0]:
  uint8_t quit_bands[1] = {0};
  fh101rf_bands_pack_be(&r->quit_bands, quit_bands);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)quit_bands[0] & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fo_quit fh101rf_fo_quit_unpack_le(const uint8_t val[1]) {
  struct fh101rf_fo_quit r = {0};
  // QUIT_BANDS @ fo_quit[2:0]:
  uint8_t quit_bands[1] = {0};
  quit_bands[0] |= (uint8_t)((val[0] & 0x7U));
  r.quit_bands = fh101rf_bands_unpack_le(quit_bands);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_fo_quit fh101rf_fo_quit_unpack_be(const uint8_t val[1]) {
  struct fh101rf_fo_quit r = {0};
  // QUIT_BANDS @ fo_quit[2:0]:
  uint8_t quit_bands[1] = {0};
  quit_bands[0] |= (uint8_t)((val[0] & 0x7U));
  r.quit_bands = fh101rf_bands_unpack_be(quit_bands);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_fo_quit(const struct fh101rf_fo_quit *r) {
  if (fh101rf_validate_bands(&r->quit_bands)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fo_quit_try_unpack_le(const uint8_t val[1], struct fh101rf_fo_quit *r) {
  *r = fh101rf_fo_quit_unpack_le(val);
  return fh101rf_validate_fo_quit(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_fo_quit_try_unpack_be(const uint8_t val[1], struct fh101rf_fo_quit *r) {
  *r = fh101rf_fo_quit_unpack_be(val);
  return fh101rf_validate_fo_quit(r);
}

// =============================================================================
// ==== GENPURP_1 Register =====================================================
// =============================================================================
// 8 bits free to use for read/write. (Register table says only write).
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_GENPURP_1_ADDRESS  (0x71U) //!< GENPURP_1 register address
#define FH101RF_GENPURP_1_RESET_LE {0x0U}  //!< GENPURP_1 register reset value
#define FH101RF_GENPURP_1_RESET_BE {0x0U}  //!< GENPURP_1 register reset value

// Register Layout Struct:

/**
 * @brief 8 bits free to use for read/write. (Register table says only write).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_genpurp_1 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_genpurp_1 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_genpurp_1_pack_le(const struct fh101rf_genpurp_1 *r, uint8_t val[1]) {
  // DATA @ genpurp_1[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_genpurp_1 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_genpurp_1_pack_be(const struct fh101rf_genpurp_1 *r, uint8_t val[1]) {
  // DATA @ genpurp_1[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_genpurp_1 fh101rf_genpurp_1_unpack_le(const uint8_t val[1]) {
  struct fh101rf_genpurp_1 r = {0};
  // DATA @ genpurp_1[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_genpurp_1 fh101rf_genpurp_1_unpack_be(const uint8_t val[1]) {
  struct fh101rf_genpurp_1 r = {0};
  // DATA @ genpurp_1[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_genpurp_1(const struct fh101rf_genpurp_1 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_genpurp_1_try_unpack_le(const uint8_t val[1], struct fh101rf_genpurp_1 *r) {
  *r = fh101rf_genpurp_1_unpack_le(val);
  return fh101rf_validate_genpurp_1(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_genpurp_1_try_unpack_be(const uint8_t val[1], struct fh101rf_genpurp_1 *r) {
  *r = fh101rf_genpurp_1_unpack_be(val);
  return fh101rf_validate_genpurp_1(r);
}

// =============================================================================
// ==== IDM_BAND Register ======================================================
// =============================================================================
// Indicates the frequency band of the ID match event.
// Fields:
//  - [1:0] DATA (enum DATA)

#define FH101RF_IDM_BAND_ADDRESS  (0x3AU) //!< IDM_BAND register address
#define FH101RF_IDM_BAND_RESET_LE {0x3U}  //!< IDM_BAND register reset value
#define FH101RF_IDM_BAND_RESET_BE {0x3U}  //!< IDM_BAND register reset value

// Register-specific enums and sub-layouts:

enum fh101rf_data {
  FH101RF_DATA_BAND_2G4 = 0x2U,
  FH101RF_DATA_BAND_433 = 0x0U,
  FH101RF_DATA_BAND_868 = 0x1U,
};

// Register Layout Struct:

/**
 * @brief Indicates the frequency band of the ID match event.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_idm_band {
  enum fh101rf_data data;
};

// Enum validation functions:

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_data.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_DATA(_VAL_) (                                                             \
  ((_VAL_) <= 0x2U) ? true :                                                                       \
  false )

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_idm_band struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_band_pack_le(const struct fh101rf_idm_band *r, uint8_t val[1]) {
  // DATA @ idm_band[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x3U);
}

/**
 * @brief Convert @ref struct fh101rf_idm_band struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_band_pack_be(const struct fh101rf_idm_band *r, uint8_t val[1]) {
  // DATA @ idm_band[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x3U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_band fh101rf_idm_band_unpack_le(const uint8_t val[1]) {
  struct fh101rf_idm_band r = {0};
  // DATA @ idm_band[1:0]:
  r.data = (enum fh101rf_data)((val[0] & 0x3U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_band fh101rf_idm_band_unpack_be(const uint8_t val[1]) {
  struct fh101rf_idm_band r = {0};
  // DATA @ idm_band[1:0]:
  r.data = (enum fh101rf_data)((val[0] & 0x3U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_idm_band(const struct fh101rf_idm_band *r) {
  if (!(FH101RF_IS_VALID_DATA(r->data))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_band_try_unpack_le(const uint8_t val[1], struct fh101rf_idm_band *r) {
  *r = fh101rf_idm_band_unpack_le(val);
  return fh101rf_validate_idm_band(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_band_try_unpack_be(const uint8_t val[1], struct fh101rf_idm_band *r) {
  *r = fh101rf_idm_band_unpack_be(val);
  return fh101rf_validate_idm_band(r);
}

// =============================================================================
// ==== IDM_CLR Register =======================================================
// =============================================================================
// Clear the FDD_EXIT_COND register.
// Fields:
//  - [0] BRANCH (bool)

#define FH101RF_IDM_CLR_ADDRESS  (0x39U) //!< IDM_CLR register address
#define FH101RF_IDM_CLR_RESET_LE {0x0U}  //!< IDM_CLR register reset value
#define FH101RF_IDM_CLR_RESET_BE {0x0U}  //!< IDM_CLR register reset value

// Register Layout Struct:

/**
 * @brief Clear the FDD_EXIT_COND register.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_idm_clr {
  bool branch;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_idm_clr struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_clr_pack_le(const struct fh101rf_idm_clr *r, uint8_t val[1]) {
  // BRANCH @ idm_clr[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->branch) & 0x1U);
}

/**
 * @brief Convert @ref struct fh101rf_idm_clr struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_clr_pack_be(const struct fh101rf_idm_clr *r, uint8_t val[1]) {
  // BRANCH @ idm_clr[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->branch) & 0x1U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_clr fh101rf_idm_clr_unpack_le(const uint8_t val[1]) {
  struct fh101rf_idm_clr r = {0};
  // BRANCH @ idm_clr[0]:
  r.branch = (bool)((val[0] & 0x1U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_clr fh101rf_idm_clr_unpack_be(const uint8_t val[1]) {
  struct fh101rf_idm_clr r = {0};
  // BRANCH @ idm_clr[0]:
  r.branch = (bool)((val[0] & 0x1U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_idm_clr(const struct fh101rf_idm_clr *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_clr_try_unpack_le(const uint8_t val[1], struct fh101rf_idm_clr *r) {
  *r = fh101rf_idm_clr_unpack_le(val);
  return fh101rf_validate_idm_clr(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_clr_try_unpack_be(const uint8_t val[1], struct fh101rf_idm_clr *r) {
  *r = fh101rf_idm_clr_unpack_be(val);
  return fh101rf_validate_idm_clr(r);
}

// =============================================================================
// ==== IDM_CTRL Register ======================================================
// =============================================================================
// Slect the type of ID's accepted by the receiver.
// Fields:
//  - [1:0] CTRL (enum CTRL)

#define FH101RF_IDM_CTRL_ADDRESS  (0x38U) //!< IDM_CTRL register address
#define FH101RF_IDM_CTRL_RESET_LE {0x0U}  //!< IDM_CTRL register reset value
#define FH101RF_IDM_CTRL_RESET_BE {0x0U}  //!< IDM_CTRL register reset value

// Register-specific enums and sub-layouts:

enum fh101rf_ctrl {
  /** @brief only broadcast ID. */
  FH101RF_CTRL_BROAD_ONLY = 0x2U,
  /** @brief individual 16 bit ID or groupwise ID. */
  FH101RF_CTRL_IND_GROUP = 0x1U,
  /** @brief individual 16 bit ID, groupwise ID, or broadcast ID. */
  FH101RF_CTRL_IND_GROUP_BROAD = 0x3U,
  /** @brief only individual 16 bit ID. */
  FH101RF_CTRL_IND_ONLY = 0x0U,
};

// Register Layout Struct:

/**
 * @brief Slect the type of ID's accepted by the receiver.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_idm_ctrl {
  enum fh101rf_ctrl ctrl;
};

// Enum validation functions:

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_ctrl.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_CTRL(_VAL_) (                                                             \
  ((_VAL_) <= 0x3U) ? true :                                                                       \
  false )

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_idm_ctrl struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_ctrl_pack_le(const struct fh101rf_idm_ctrl *r, uint8_t val[1]) {
  // CTRL @ idm_ctrl[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->ctrl) & 0x3U);
}

/**
 * @brief Convert @ref struct fh101rf_idm_ctrl struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_ctrl_pack_be(const struct fh101rf_idm_ctrl *r, uint8_t val[1]) {
  // CTRL @ idm_ctrl[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->ctrl) & 0x3U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_ctrl fh101rf_idm_ctrl_unpack_le(const uint8_t val[1]) {
  struct fh101rf_idm_ctrl r = {0};
  // CTRL @ idm_ctrl[1:0]:
  r.ctrl = (enum fh101rf_ctrl)((val[0] & 0x3U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_ctrl fh101rf_idm_ctrl_unpack_be(const uint8_t val[1]) {
  struct fh101rf_idm_ctrl r = {0};
  // CTRL @ idm_ctrl[1:0]:
  r.ctrl = (enum fh101rf_ctrl)((val[0] & 0x3U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_idm_ctrl(const struct fh101rf_idm_ctrl *r) {
  if (!(FH101RF_IS_VALID_CTRL(r->ctrl))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_ctrl_try_unpack_le(const uint8_t val[1], struct fh101rf_idm_ctrl *r) {
  *r = fh101rf_idm_ctrl_unpack_le(val);
  return fh101rf_validate_idm_ctrl(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_ctrl_try_unpack_be(const uint8_t val[1], struct fh101rf_idm_ctrl *r) {
  *r = fh101rf_idm_ctrl_unpack_be(val);
  return fh101rf_validate_idm_ctrl(r);
}

// =============================================================================
// ==== IDM_ENABLE Register ====================================================
// =============================================================================
// Enables the ID match for a given band.
// Fields:
//  - [2:0] MATCH_BANDS (layout BANDS)
//    - [0] MATCH_BANDS.BAND_433 (bool): True means on for 433MHz band.
//    - [1] MATCH_BANDS.BAND_868 (bool): True means on for 868/915MHz band.
//    - [2] MATCH_BANDS.BAND_2G4 (bool): True means on for 2.4GHz band.

#define FH101RF_IDM_ENABLE_ADDRESS  (0x37U) //!< IDM_ENABLE register address
#define FH101RF_IDM_ENABLE_RESET_LE {0x7U}  //!< IDM_ENABLE register reset value
#define FH101RF_IDM_ENABLE_RESET_BE {0x7U}  //!< IDM_ENABLE register reset value

// Register Layout Struct:

/**
 * @brief Enables the ID match for a given band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_idm_enable {
  struct fh101rf_bands match_bands;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_idm_enable struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_enable_pack_le(const struct fh101rf_idm_enable *r, uint8_t val[1]) {
  // MATCH_BANDS @ idm_enable[2:0]:
  uint8_t match_bands[1] = {0};
  fh101rf_bands_pack_le(&r->match_bands, match_bands);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)match_bands[0] & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_idm_enable struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_enable_pack_be(const struct fh101rf_idm_enable *r, uint8_t val[1]) {
  // MATCH_BANDS @ idm_enable[2:0]:
  uint8_t match_bands[1] = {0};
  fh101rf_bands_pack_be(&r->match_bands, match_bands);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)match_bands[0] & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_enable fh101rf_idm_enable_unpack_le(const uint8_t val[1]) {
  struct fh101rf_idm_enable r = {0};
  // MATCH_BANDS @ idm_enable[2:0]:
  uint8_t match_bands[1] = {0};
  match_bands[0] |= (uint8_t)((val[0] & 0x7U));
  r.match_bands = fh101rf_bands_unpack_le(match_bands);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_enable fh101rf_idm_enable_unpack_be(const uint8_t val[1]) {
  struct fh101rf_idm_enable r = {0};
  // MATCH_BANDS @ idm_enable[2:0]:
  uint8_t match_bands[1] = {0};
  match_bands[0] |= (uint8_t)((val[0] & 0x7U));
  r.match_bands = fh101rf_bands_unpack_be(match_bands);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_idm_enable(const struct fh101rf_idm_enable *r) {
  if (fh101rf_validate_bands(&r->match_bands)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_enable_try_unpack_le(const uint8_t val[1], struct fh101rf_idm_enable *r) {
  *r = fh101rf_idm_enable_unpack_le(val);
  return fh101rf_validate_idm_enable(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_enable_try_unpack_be(const uint8_t val[1], struct fh101rf_idm_enable *r) {
  *r = fh101rf_idm_enable_unpack_be(val);
  return fh101rf_validate_idm_enable(r);
}

// =============================================================================
// ==== IDM_REASON Register ====================================================
// =============================================================================
// Indicates the type of ID match event.
// Fields:
//  - [1:0] REASON (enum REASON)

#define FH101RF_IDM_REASON_ADDRESS  (0x3BU) //!< IDM_REASON register address
#define FH101RF_IDM_REASON_RESET_LE {0x0U}  //!< IDM_REASON register reset value
#define FH101RF_IDM_REASON_RESET_BE {0x0U}  //!< IDM_REASON register reset value

// Register-specific enums and sub-layouts:

enum fh101rf_reason {
  /** @brief Broadcast ID */
  FH101RF_REASON_BROAD_MATCH = 0x3U,
  /** @brief Group ID */
  FH101RF_REASON_GROUP_MATCH = 0x2U,
  /** @brief Individual ID */
  FH101RF_REASON_IND_MATCH = 0x1U,
  /** @brief Unspecified reason */
  FH101RF_REASON_UNKNOWN = 0x0U,
};

// Register Layout Struct:

/**
 * @brief Indicates the type of ID match event.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_idm_reason {
  enum fh101rf_reason reason;
};

// Enum validation functions:

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_reason.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_REASON(_VAL_) (                                                           \
  ((_VAL_) <= 0x3U) ? true :                                                                       \
  false )

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_idm_reason struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_reason_pack_le(const struct fh101rf_idm_reason *r, uint8_t val[1]) {
  // REASON @ idm_reason[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->reason) & 0x3U);
}

/**
 * @brief Convert @ref struct fh101rf_idm_reason struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_idm_reason_pack_be(const struct fh101rf_idm_reason *r, uint8_t val[1]) {
  // REASON @ idm_reason[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)(((uint8_t)r->reason) & 0x3U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_reason fh101rf_idm_reason_unpack_le(const uint8_t val[1]) {
  struct fh101rf_idm_reason r = {0};
  // REASON @ idm_reason[1:0]:
  r.reason = (enum fh101rf_reason)((val[0] & 0x3U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_idm_reason fh101rf_idm_reason_unpack_be(const uint8_t val[1]) {
  struct fh101rf_idm_reason r = {0};
  // REASON @ idm_reason[1:0]:
  r.reason = (enum fh101rf_reason)((val[0] & 0x3U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_idm_reason(const struct fh101rf_idm_reason *r) {
  if (!(FH101RF_IS_VALID_REASON(r->reason))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_reason_try_unpack_le(const uint8_t val[1], struct fh101rf_idm_reason *r) {
  *r = fh101rf_idm_reason_unpack_le(val);
  return fh101rf_validate_idm_reason(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_idm_reason_try_unpack_be(const uint8_t val[1], struct fh101rf_idm_reason *r) {
  *r = fh101rf_idm_reason_unpack_be(val);
  return fh101rf_validate_idm_reason(r);
}

// =============================================================================
// ==== ID_HI Register =========================================================
// =============================================================================
// Sets the high byte of the match ID. 4-MSB form the group ID.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_ID_HI_ADDRESS  (0x35U) //!< ID_HI register address
#define FH101RF_ID_HI_RESET_LE {0x7DU} //!< ID_HI register reset value
#define FH101RF_ID_HI_RESET_BE {0x7DU} //!< ID_HI register reset value

// Register Layout Struct:

/**
 * @brief Sets the high byte of the match ID. 4-MSB form the group ID.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_id_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_id_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_id_hi_pack_le(const struct fh101rf_id_hi *r, uint8_t val[1]) {
  // DATA @ id_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_id_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_id_hi_pack_be(const struct fh101rf_id_hi *r, uint8_t val[1]) {
  // DATA @ id_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_id_hi fh101rf_id_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_id_hi r = {0};
  // DATA @ id_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_id_hi fh101rf_id_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_id_hi r = {0};
  // DATA @ id_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_id_hi(const struct fh101rf_id_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_id_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_id_hi *r) {
  *r = fh101rf_id_hi_unpack_le(val);
  return fh101rf_validate_id_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_id_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_id_hi *r) {
  *r = fh101rf_id_hi_unpack_be(val);
  return fh101rf_validate_id_hi(r);
}

// =============================================================================
// ==== ID_LO Register =========================================================
// =============================================================================
// Sets the low byte of the match ID.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_ID_LO_ADDRESS  (0x36U) //!< ID_LO register address
#define FH101RF_ID_LO_RESET_LE {0xA8U} //!< ID_LO register reset value
#define FH101RF_ID_LO_RESET_BE {0xA8U} //!< ID_LO register reset value

// Register Layout Struct:

/**
 * @brief Sets the low byte of the match ID.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_id_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_id_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_id_lo_pack_le(const struct fh101rf_id_lo *r, uint8_t val[1]) {
  // DATA @ id_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_id_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_id_lo_pack_be(const struct fh101rf_id_lo *r, uint8_t val[1]) {
  // DATA @ id_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_id_lo fh101rf_id_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_id_lo r = {0};
  // DATA @ id_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_id_lo fh101rf_id_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_id_lo r = {0};
  // DATA @ id_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_id_lo(const struct fh101rf_id_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_id_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_id_lo *r) {
  *r = fh101rf_id_lo_unpack_le(val);
  return fh101rf_validate_id_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_id_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_id_lo *r) {
  *r = fh101rf_id_lo_unpack_be(val);
  return fh101rf_validate_id_lo(r);
}

// =============================================================================
// ==== IRQ_CLR Register =======================================================
// =============================================================================
// Resets the corresponding IRQ event bit.
// Fields:
//  - [7:0] IRQ_CLR (layout IRQ_SOURCE)
//    - [0] IRQ_CLR.ID_MATCH (bool): The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
//    - [1] IRQ_CLR.FIFO_OVERFLOW (bool): FIFO overflow.
//    - [2] IRQ_CLR.FIFO_FULL (bool): FIFO buffer full.
//    - [3] IRQ_CLR.CORREL_MATCH (bool): OOK data matches the correlation sequence.
//    - [4] IRQ_CLR.ID_MATCH_AND_FIFO_FULL (bool): 16-bit ID in FDD mode matches and FIFO buffer full.
//    - [5] IRQ_CLR.ID_MATCH_AND_LDR (bool): 16-bit ID in FDD mode matches and LDR was entered.
//    - [6] IRQ_CLR.RTC_TIMER_ALARM (bool): RTC timer alarm.
//    - [7] IRQ_CLR.CYCLIC_TIMER_ALARM (bool): Cyclic timer alarm.

#define FH101RF_IRQ_CLR_ADDRESS  (0x33U) //!< IRQ_CLR register address
#define FH101RF_IRQ_CLR_RESET_LE {0x0U}  //!< IRQ_CLR register reset value
#define FH101RF_IRQ_CLR_RESET_BE {0x0U}  //!< IRQ_CLR register reset value

// Register Layout Struct:

/**
 * @brief Resets the corresponding IRQ event bit.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_irq_clr {
  struct fh101rf_irq_source irq_clr;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_irq_clr struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_clr_pack_le(const struct fh101rf_irq_clr *r, uint8_t val[1]) {
  // IRQ_CLR @ irq_clr[7:0]:
  uint8_t irq_clr[1] = {0};
  fh101rf_irq_source_pack_le(&r->irq_clr, irq_clr);
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)((uint8_t)irq_clr[0] & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_irq_clr struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_clr_pack_be(const struct fh101rf_irq_clr *r, uint8_t val[1]) {
  // IRQ_CLR @ irq_clr[7:0]:
  uint8_t irq_clr[1] = {0};
  fh101rf_irq_source_pack_be(&r->irq_clr, irq_clr);
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)((uint8_t)irq_clr[0] & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_clr fh101rf_irq_clr_unpack_le(const uint8_t val[1]) {
  struct fh101rf_irq_clr r = {0};
  // IRQ_CLR @ irq_clr[7:0]:
  uint8_t irq_clr[1] = {0};
  irq_clr[0] |= (uint8_t)((val[0] & 0xFFU));
  r.irq_clr = fh101rf_irq_source_unpack_le(irq_clr);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_clr fh101rf_irq_clr_unpack_be(const uint8_t val[1]) {
  struct fh101rf_irq_clr r = {0};
  // IRQ_CLR @ irq_clr[7:0]:
  uint8_t irq_clr[1] = {0};
  irq_clr[0] |= (uint8_t)((val[0] & 0xFFU));
  r.irq_clr = fh101rf_irq_source_unpack_be(irq_clr);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_irq_clr(const struct fh101rf_irq_clr *r) {
  if (fh101rf_validate_irq_source(&r->irq_clr)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_clr_try_unpack_le(const uint8_t val[1], struct fh101rf_irq_clr *r) {
  *r = fh101rf_irq_clr_unpack_le(val);
  return fh101rf_validate_irq_clr(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_clr_try_unpack_be(const uint8_t val[1], struct fh101rf_irq_clr *r) {
  *r = fh101rf_irq_clr_unpack_be(val);
  return fh101rf_validate_irq_clr(r);
}

// =============================================================================
// ==== IRQ_SELECT Register ====================================================
// =============================================================================
// Selects the interrupt sources.
// Fields:
//  - [7:0] IRQ_SELECT (layout IRQ_SOURCE)
//    - [0] IRQ_SELECT.ID_MATCH (bool): The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
//    - [1] IRQ_SELECT.FIFO_OVERFLOW (bool): FIFO overflow.
//    - [2] IRQ_SELECT.FIFO_FULL (bool): FIFO buffer full.
//    - [3] IRQ_SELECT.CORREL_MATCH (bool): OOK data matches the correlation sequence.
//    - [4] IRQ_SELECT.ID_MATCH_AND_FIFO_FULL (bool): 16-bit ID in FDD mode matches and FIFO buffer full.
//    - [5] IRQ_SELECT.ID_MATCH_AND_LDR (bool): 16-bit ID in FDD mode matches and LDR was entered.
//    - [6] IRQ_SELECT.RTC_TIMER_ALARM (bool): RTC timer alarm.
//    - [7] IRQ_SELECT.CYCLIC_TIMER_ALARM (bool): Cyclic timer alarm.

#define FH101RF_IRQ_SELECT_ADDRESS  (0x31U) //!< IRQ_SELECT register address
#define FH101RF_IRQ_SELECT_RESET_LE {0x1U}  //!< IRQ_SELECT register reset value
#define FH101RF_IRQ_SELECT_RESET_BE {0x1U}  //!< IRQ_SELECT register reset value

// Register Layout Struct:

/**
 * @brief Selects the interrupt sources.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_irq_select {
  struct fh101rf_irq_source irq_select;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_irq_select struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_select_pack_le(const struct fh101rf_irq_select *r, uint8_t val[1]) {
  // IRQ_SELECT @ irq_select[7:0]:
  uint8_t irq_select[1] = {0};
  fh101rf_irq_source_pack_le(&r->irq_select, irq_select);
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)((uint8_t)irq_select[0] & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_irq_select struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_select_pack_be(const struct fh101rf_irq_select *r, uint8_t val[1]) {
  // IRQ_SELECT @ irq_select[7:0]:
  uint8_t irq_select[1] = {0};
  fh101rf_irq_source_pack_be(&r->irq_select, irq_select);
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)((uint8_t)irq_select[0] & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_select fh101rf_irq_select_unpack_le(const uint8_t val[1]) {
  struct fh101rf_irq_select r = {0};
  // IRQ_SELECT @ irq_select[7:0]:
  uint8_t irq_select[1] = {0};
  irq_select[0] |= (uint8_t)((val[0] & 0xFFU));
  r.irq_select = fh101rf_irq_source_unpack_le(irq_select);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_select fh101rf_irq_select_unpack_be(const uint8_t val[1]) {
  struct fh101rf_irq_select r = {0};
  // IRQ_SELECT @ irq_select[7:0]:
  uint8_t irq_select[1] = {0};
  irq_select[0] |= (uint8_t)((val[0] & 0xFFU));
  r.irq_select = fh101rf_irq_source_unpack_be(irq_select);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_irq_select(const struct fh101rf_irq_select *r) {
  if (fh101rf_validate_irq_source(&r->irq_select)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_select_try_unpack_le(const uint8_t val[1], struct fh101rf_irq_select *r) {
  *r = fh101rf_irq_select_unpack_le(val);
  return fh101rf_validate_irq_select(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_select_try_unpack_be(const uint8_t val[1], struct fh101rf_irq_select *r) {
  *r = fh101rf_irq_select_unpack_be(val);
  return fh101rf_validate_irq_select(r);
}

// =============================================================================
// ==== IRQ_SET Register =======================================================
// =============================================================================
// Sets the corresponding IRQ event bit (triggers IRQ events for debugging).
// Fields:
//  - [7:0] IRQ_SET (layout IRQ_SOURCE)
//    - [0] IRQ_SET.ID_MATCH (bool): The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
//    - [1] IRQ_SET.FIFO_OVERFLOW (bool): FIFO overflow.
//    - [2] IRQ_SET.FIFO_FULL (bool): FIFO buffer full.
//    - [3] IRQ_SET.CORREL_MATCH (bool): OOK data matches the correlation sequence.
//    - [4] IRQ_SET.ID_MATCH_AND_FIFO_FULL (bool): 16-bit ID in FDD mode matches and FIFO buffer full.
//    - [5] IRQ_SET.ID_MATCH_AND_LDR (bool): 16-bit ID in FDD mode matches and LDR was entered.
//    - [6] IRQ_SET.RTC_TIMER_ALARM (bool): RTC timer alarm.
//    - [7] IRQ_SET.CYCLIC_TIMER_ALARM (bool): Cyclic timer alarm.

#define FH101RF_IRQ_SET_ADDRESS  (0x34U) //!< IRQ_SET register address
#define FH101RF_IRQ_SET_RESET_LE {0x0U}  //!< IRQ_SET register reset value
#define FH101RF_IRQ_SET_RESET_BE {0x0U}  //!< IRQ_SET register reset value

// Register Layout Struct:

/**
 * @brief Sets the corresponding IRQ event bit (triggers IRQ events for debugging).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_irq_set {
  struct fh101rf_irq_source irq_set;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_irq_set struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_set_pack_le(const struct fh101rf_irq_set *r, uint8_t val[1]) {
  // IRQ_SET @ irq_set[7:0]:
  uint8_t irq_set[1] = {0};
  fh101rf_irq_source_pack_le(&r->irq_set, irq_set);
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)((uint8_t)irq_set[0] & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_irq_set struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_set_pack_be(const struct fh101rf_irq_set *r, uint8_t val[1]) {
  // IRQ_SET @ irq_set[7:0]:
  uint8_t irq_set[1] = {0};
  fh101rf_irq_source_pack_be(&r->irq_set, irq_set);
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)((uint8_t)irq_set[0] & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_set fh101rf_irq_set_unpack_le(const uint8_t val[1]) {
  struct fh101rf_irq_set r = {0};
  // IRQ_SET @ irq_set[7:0]:
  uint8_t irq_set[1] = {0};
  irq_set[0] |= (uint8_t)((val[0] & 0xFFU));
  r.irq_set = fh101rf_irq_source_unpack_le(irq_set);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_set fh101rf_irq_set_unpack_be(const uint8_t val[1]) {
  struct fh101rf_irq_set r = {0};
  // IRQ_SET @ irq_set[7:0]:
  uint8_t irq_set[1] = {0};
  irq_set[0] |= (uint8_t)((val[0] & 0xFFU));
  r.irq_set = fh101rf_irq_source_unpack_be(irq_set);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_irq_set(const struct fh101rf_irq_set *r) {
  if (fh101rf_validate_irq_source(&r->irq_set)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_set_try_unpack_le(const uint8_t val[1], struct fh101rf_irq_set *r) {
  *r = fh101rf_irq_set_unpack_le(val);
  return fh101rf_validate_irq_set(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_set_try_unpack_be(const uint8_t val[1], struct fh101rf_irq_set *r) {
  *r = fh101rf_irq_set_unpack_be(val);
  return fh101rf_validate_irq_set(r);
}

// =============================================================================
// ==== IRQ_STATUS Register ====================================================
// =============================================================================
// Holds the status of the IRQ events.
// Fields:
//  - [7:0] IRQ_STATUS (layout IRQ_SOURCE)
//    - [0] IRQ_STATUS.ID_MATCH (bool): The 16-bit ID in FDD mode matches (register ID_HI, ID_LO).
//    - [1] IRQ_STATUS.FIFO_OVERFLOW (bool): FIFO overflow.
//    - [2] IRQ_STATUS.FIFO_FULL (bool): FIFO buffer full.
//    - [3] IRQ_STATUS.CORREL_MATCH (bool): OOK data matches the correlation sequence.
//    - [4] IRQ_STATUS.ID_MATCH_AND_FIFO_FULL (bool): 16-bit ID in FDD mode matches and FIFO buffer full.
//    - [5] IRQ_STATUS.ID_MATCH_AND_LDR (bool): 16-bit ID in FDD mode matches and LDR was entered.
//    - [6] IRQ_STATUS.RTC_TIMER_ALARM (bool): RTC timer alarm.
//    - [7] IRQ_STATUS.CYCLIC_TIMER_ALARM (bool): Cyclic timer alarm.

#define FH101RF_IRQ_STATUS_ADDRESS  (0x32U) //!< IRQ_STATUS register address
#define FH101RF_IRQ_STATUS_RESET_LE {0x0U}  //!< IRQ_STATUS register reset value
#define FH101RF_IRQ_STATUS_RESET_BE {0x0U}  //!< IRQ_STATUS register reset value

// Register Layout Struct:

/**
 * @brief Holds the status of the IRQ events.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_irq_status {
  struct fh101rf_irq_source irq_status;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_irq_status struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_status_pack_le(const struct fh101rf_irq_status *r, uint8_t val[1]) {
  // IRQ_STATUS @ irq_status[7:0]:
  uint8_t irq_status[1] = {0};
  fh101rf_irq_source_pack_le(&r->irq_status, irq_status);
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)((uint8_t)irq_status[0] & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_irq_status struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_irq_status_pack_be(const struct fh101rf_irq_status *r, uint8_t val[1]) {
  // IRQ_STATUS @ irq_status[7:0]:
  uint8_t irq_status[1] = {0};
  fh101rf_irq_source_pack_be(&r->irq_status, irq_status);
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)((uint8_t)irq_status[0] & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_status fh101rf_irq_status_unpack_le(const uint8_t val[1]) {
  struct fh101rf_irq_status r = {0};
  // IRQ_STATUS @ irq_status[7:0]:
  uint8_t irq_status[1] = {0};
  irq_status[0] |= (uint8_t)((val[0] & 0xFFU));
  r.irq_status = fh101rf_irq_source_unpack_le(irq_status);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_irq_status fh101rf_irq_status_unpack_be(const uint8_t val[1]) {
  struct fh101rf_irq_status r = {0};
  // IRQ_STATUS @ irq_status[7:0]:
  uint8_t irq_status[1] = {0};
  irq_status[0] |= (uint8_t)((val[0] & 0xFFU));
  r.irq_status = fh101rf_irq_source_unpack_be(irq_status);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_irq_status(const struct fh101rf_irq_status *r) {
  if (fh101rf_validate_irq_source(&r->irq_status)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_status_try_unpack_le(const uint8_t val[1], struct fh101rf_irq_status *r) {
  *r = fh101rf_irq_status_unpack_le(val);
  return fh101rf_validate_irq_status(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_irq_status_try_unpack_be(const uint8_t val[1], struct fh101rf_irq_status *r) {
  *r = fh101rf_irq_status_unpack_be(val);
  return fh101rf_validate_irq_status(r);
}

// =============================================================================
// ==== KORREL_STATE Register ==================================================
// =============================================================================
// Fields:
//  - [2:0] KORREL_BRANCHES_A (layout BRANCHES): Indicates receiver branch that had contributed for Code A recognition
//    - [0] KORREL_BRANCHES_A.WEAK (bool): True means weak branch on.
//    - [1] KORREL_BRANCHES_A.MEDIUM (bool): True means medium branch on (+8dB of weak).
//    - [2] KORREL_BRANCHES_A.STRONG (bool): True means strong branch on (+16dB of weak).
//  - [5:3] KORREL_BRANCHES_B (layout BRANCHES): Indicates receiver branch that had contributed for Code B recognition
//    - [3] KORREL_BRANCHES_B.WEAK (bool): True means weak branch on.
//    - [4] KORREL_BRANCHES_B.MEDIUM (bool): True means medium branch on (+8dB of weak).
//    - [5] KORREL_BRANCHES_B.STRONG (bool): True means strong branch on (+16dB of weak).
//  - [7:6] KORREL_BRANCHES_LATEST (enum KORREL_BRANCHES_LATEST): Indicates frequency band for latest correlator

#define FH101RF_KORREL_STATE_ADDRESS  (0x2BU) //!< KORREL_STATE register address
#define FH101RF_KORREL_STATE_RESET_LE {0xC0U} //!< KORREL_STATE register reset value
#define FH101RF_KORREL_STATE_RESET_BE {0xC0U} //!< KORREL_STATE register reset value

// Register-specific enums and sub-layouts:

/** @brief Indicates frequency band for latest correlator */
enum fh101rf_korrel_branches_latest {
  /** @brief Band 2.4GHz matched. */
  FH101RF_KORREL_BRANCHES_LATEST_BAND_2G4 = 0x2U,
  /** @brief Band 433MHz matched. */
  FH101RF_KORREL_BRANCHES_LATEST_BAND_433 = 0x0U,
  /** @brief Band 868/915MHz matched. */
  FH101RF_KORREL_BRANCHES_LATEST_BAND_868 = 0x1U,
};

// Register Layout Struct:

/** @note use pack/unpack functions for conversion to/from packed binary value */
struct fh101rf_korrel_state {
  /** @brief Indicates receiver branch that had contributed for Code A recognition */
  struct fh101rf_branches korrel_branches_a;
  /** @brief Indicates receiver branch that had contributed for Code B recognition */
  struct fh101rf_branches korrel_branches_b;
  /** @brief Indicates frequency band for latest correlator */
  enum fh101rf_korrel_branches_latest korrel_branches_latest;
};

// Enum validation functions:

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_korrel_branches_latest.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_KORREL_BRANCHES_LATEST(_VAL_) (                                           \
  ((_VAL_) <= 0x2U) ? true :                                                                       \
  false )

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_korrel_state struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_state_pack_le(const struct fh101rf_korrel_state *r, uint8_t val[1]) {
  // KORREL_BRANCHES_A @ korrel_state[2:0]:
  uint8_t korrel_branches_a[1] = {0};
  fh101rf_branches_pack_le(&r->korrel_branches_a, korrel_branches_a);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)korrel_branches_a[0] & 0x7U);
  // KORREL_BRANCHES_B @ korrel_state[5:3]:
  uint8_t korrel_branches_b[1] = {0};
  fh101rf_branches_pack_le(&r->korrel_branches_b, korrel_branches_b);
  val[0] &= (uint8_t)~0x38U;
  val[0] |= (uint8_t)((uint8_t)(korrel_branches_b[0] << 3) & 0x38U);
  // KORREL_BRANCHES_LATEST @ korrel_state[7:6]:
  val[0] &= (uint8_t)~0xC0U;
  val[0] |= (uint8_t)(((uint8_t)(r->korrel_branches_latest << 6)) & 0xC0U);
}

/**
 * @brief Convert @ref struct fh101rf_korrel_state struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_state_pack_be(const struct fh101rf_korrel_state *r, uint8_t val[1]) {
  // KORREL_BRANCHES_A @ korrel_state[2:0]:
  uint8_t korrel_branches_a[1] = {0};
  fh101rf_branches_pack_be(&r->korrel_branches_a, korrel_branches_a);
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)((uint8_t)korrel_branches_a[0] & 0x7U);
  // KORREL_BRANCHES_B @ korrel_state[5:3]:
  uint8_t korrel_branches_b[1] = {0};
  fh101rf_branches_pack_be(&r->korrel_branches_b, korrel_branches_b);
  val[0] &= (uint8_t)~0x38U;
  val[0] |= (uint8_t)((uint8_t)(korrel_branches_b[0] << 3) & 0x38U);
  // KORREL_BRANCHES_LATEST @ korrel_state[7:6]:
  val[0] &= (uint8_t)~0xC0U;
  val[0] |= (uint8_t)(((uint8_t)(r->korrel_branches_latest << 6)) & 0xC0U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_state fh101rf_korrel_state_unpack_le(const uint8_t val[1]) {
  struct fh101rf_korrel_state r = {0};
  // KORREL_BRANCHES_A @ korrel_state[2:0]:
  uint8_t korrel_branches_a[1] = {0};
  korrel_branches_a[0] |= (uint8_t)((val[0] & 0x7U));
  r.korrel_branches_a = fh101rf_branches_unpack_le(korrel_branches_a);
  // KORREL_BRANCHES_B @ korrel_state[5:3]:
  uint8_t korrel_branches_b[1] = {0};
  korrel_branches_b[0] |= (uint8_t)((val[0] & 0x38U) >> 3);
  r.korrel_branches_b = fh101rf_branches_unpack_le(korrel_branches_b);
  // KORREL_BRANCHES_LATEST @ korrel_state[7:6]:
  r.korrel_branches_latest = (enum fh101rf_korrel_branches_latest)(((val[0] & 0xC0U) >> 6));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_state fh101rf_korrel_state_unpack_be(const uint8_t val[1]) {
  struct fh101rf_korrel_state r = {0};
  // KORREL_BRANCHES_A @ korrel_state[2:0]:
  uint8_t korrel_branches_a[1] = {0};
  korrel_branches_a[0] |= (uint8_t)((val[0] & 0x7U));
  r.korrel_branches_a = fh101rf_branches_unpack_be(korrel_branches_a);
  // KORREL_BRANCHES_B @ korrel_state[5:3]:
  uint8_t korrel_branches_b[1] = {0};
  korrel_branches_b[0] |= (uint8_t)((val[0] & 0x38U) >> 3);
  r.korrel_branches_b = fh101rf_branches_unpack_be(korrel_branches_b);
  // KORREL_BRANCHES_LATEST @ korrel_state[7:6]:
  r.korrel_branches_latest = (enum fh101rf_korrel_branches_latest)(((val[0] & 0xC0U) >> 6));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_korrel_state(const struct fh101rf_korrel_state *r) {
  if (fh101rf_validate_branches(&r->korrel_branches_a)) return 1;
  if (fh101rf_validate_branches(&r->korrel_branches_b)) return 4;
  if (!(FH101RF_IS_VALID_KORREL_BRANCHES_LATEST(r->korrel_branches_latest))) return 7;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_state_try_unpack_le(const uint8_t val[1], struct fh101rf_korrel_state *r) {
  *r = fh101rf_korrel_state_unpack_le(val);
  return fh101rf_validate_korrel_state(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_state_try_unpack_be(const uint8_t val[1], struct fh101rf_korrel_state *r) {
  *r = fh101rf_korrel_state_unpack_be(val);
  return fh101rf_validate_korrel_state(r);
}

// =============================================================================
// ==== KORREL_SV_CLEAR Register ===============================================
// =============================================================================
// Set true to clear the KORREL_STATE and KORREL_VAL registers.
// Fields:
//  - [0] DATA (bool)

#define FH101RF_KORREL_SV_CLEAR_ADDRESS  (0x7CU) //!< KORREL_SV_CLEAR register address
#define FH101RF_KORREL_SV_CLEAR_RESET_LE {0x0U}  //!< KORREL_SV_CLEAR register reset value
#define FH101RF_KORREL_SV_CLEAR_RESET_BE {0x0U}  //!< KORREL_SV_CLEAR register reset value

// Register Layout Struct:

/**
 * @brief Set true to clear the KORREL_STATE and KORREL_VAL registers.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_korrel_sv_clear {
  bool data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_korrel_sv_clear struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_sv_clear_pack_le(const struct fh101rf_korrel_sv_clear *r, uint8_t val[1]) {
  // DATA @ korrel_sv_clear[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1U);
}

/**
 * @brief Convert @ref struct fh101rf_korrel_sv_clear struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_sv_clear_pack_be(const struct fh101rf_korrel_sv_clear *r, uint8_t val[1]) {
  // DATA @ korrel_sv_clear[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_sv_clear fh101rf_korrel_sv_clear_unpack_le(const uint8_t val[1]) {
  struct fh101rf_korrel_sv_clear r = {0};
  // DATA @ korrel_sv_clear[0]:
  r.data = (bool)((val[0] & 0x1U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_sv_clear fh101rf_korrel_sv_clear_unpack_be(const uint8_t val[1]) {
  struct fh101rf_korrel_sv_clear r = {0};
  // DATA @ korrel_sv_clear[0]:
  r.data = (bool)((val[0] & 0x1U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_korrel_sv_clear(const struct fh101rf_korrel_sv_clear *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_sv_clear_try_unpack_le(const uint8_t val[1], struct fh101rf_korrel_sv_clear *r) {
  *r = fh101rf_korrel_sv_clear_unpack_le(val);
  return fh101rf_validate_korrel_sv_clear(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_sv_clear_try_unpack_be(const uint8_t val[1], struct fh101rf_korrel_sv_clear *r) {
  *r = fh101rf_korrel_sv_clear_unpack_be(val);
  return fh101rf_validate_korrel_sv_clear(r);
}

// =============================================================================
// ==== KORREL_THRESH_A Register ===============================================
// =============================================================================
// Sets the threshold for a code A match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).
// Fields:
//  - [4:0] DATA (uint)

#define FH101RF_KORREL_THRESH_A_ADDRESS  (0x29U) //!< KORREL_THRESH_A register address
#define FH101RF_KORREL_THRESH_A_RESET_LE {0x1AU} //!< KORREL_THRESH_A register reset value
#define FH101RF_KORREL_THRESH_A_RESET_BE {0x1AU} //!< KORREL_THRESH_A register reset value

// Register Layout Struct:

/**
 * @brief Sets the threshold for a code A match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_korrel_thresh_a {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_korrel_thresh_a struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_thresh_a_pack_le(const struct fh101rf_korrel_thresh_a *r, uint8_t val[1]) {
  // DATA @ korrel_thresh_a[4:0]:
  val[0] &= (uint8_t)~0x1FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1FU);
}

/**
 * @brief Convert @ref struct fh101rf_korrel_thresh_a struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_thresh_a_pack_be(const struct fh101rf_korrel_thresh_a *r, uint8_t val[1]) {
  // DATA @ korrel_thresh_a[4:0]:
  val[0] &= (uint8_t)~0x1FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1FU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_thresh_a fh101rf_korrel_thresh_a_unpack_le(const uint8_t val[1]) {
  struct fh101rf_korrel_thresh_a r = {0};
  // DATA @ korrel_thresh_a[4:0]:
  r.data = (uint8_t)((val[0] & 0x1FU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_thresh_a fh101rf_korrel_thresh_a_unpack_be(const uint8_t val[1]) {
  struct fh101rf_korrel_thresh_a r = {0};
  // DATA @ korrel_thresh_a[4:0]:
  r.data = (uint8_t)((val[0] & 0x1FU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_korrel_thresh_a(const struct fh101rf_korrel_thresh_a *r) {
  if ((r->data & ~(uint8_t)0x1F) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_thresh_a_try_unpack_le(const uint8_t val[1], struct fh101rf_korrel_thresh_a *r) {
  *r = fh101rf_korrel_thresh_a_unpack_le(val);
  return fh101rf_validate_korrel_thresh_a(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_thresh_a_try_unpack_be(const uint8_t val[1], struct fh101rf_korrel_thresh_a *r) {
  *r = fh101rf_korrel_thresh_a_unpack_be(val);
  return fh101rf_validate_korrel_thresh_a(r);
}

// =============================================================================
// ==== KORREL_THRESH_B Register ===============================================
// =============================================================================
// Sets the threshold for a code B match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).
// Fields:
//  - [4:0] DATA (uint)

#define FH101RF_KORREL_THRESH_B_ADDRESS  (0x2AU) //!< KORREL_THRESH_B register address
#define FH101RF_KORREL_THRESH_B_RESET_LE {0x1AU} //!< KORREL_THRESH_B register reset value
#define FH101RF_KORREL_THRESH_B_RESET_BE {0x1AU} //!< KORREL_THRESH_B register reset value

// Register Layout Struct:

/**
 * @brief Sets the threshold for a code B match. Useful values are between 0x19 and 0x1E. Lower values correspond to more tolerated bit errors (can lead to false wake-up detections).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_korrel_thresh_b {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_korrel_thresh_b struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_thresh_b_pack_le(const struct fh101rf_korrel_thresh_b *r, uint8_t val[1]) {
  // DATA @ korrel_thresh_b[4:0]:
  val[0] &= (uint8_t)~0x1FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1FU);
}

/**
 * @brief Convert @ref struct fh101rf_korrel_thresh_b struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_thresh_b_pack_be(const struct fh101rf_korrel_thresh_b *r, uint8_t val[1]) {
  // DATA @ korrel_thresh_b[4:0]:
  val[0] &= (uint8_t)~0x1FU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1FU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_thresh_b fh101rf_korrel_thresh_b_unpack_le(const uint8_t val[1]) {
  struct fh101rf_korrel_thresh_b r = {0};
  // DATA @ korrel_thresh_b[4:0]:
  r.data = (uint8_t)((val[0] & 0x1FU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_thresh_b fh101rf_korrel_thresh_b_unpack_be(const uint8_t val[1]) {
  struct fh101rf_korrel_thresh_b r = {0};
  // DATA @ korrel_thresh_b[4:0]:
  r.data = (uint8_t)((val[0] & 0x1FU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_korrel_thresh_b(const struct fh101rf_korrel_thresh_b *r) {
  if ((r->data & ~(uint8_t)0x1F) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_thresh_b_try_unpack_le(const uint8_t val[1], struct fh101rf_korrel_thresh_b *r) {
  *r = fh101rf_korrel_thresh_b_unpack_le(val);
  return fh101rf_validate_korrel_thresh_b(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_thresh_b_try_unpack_be(const uint8_t val[1], struct fh101rf_korrel_thresh_b *r) {
  *r = fh101rf_korrel_thresh_b_unpack_be(val);
  return fh101rf_validate_korrel_thresh_b(r);
}

// =============================================================================
// ==== KORREL_VAL Register ====================================================
// =============================================================================
// Indicates the match level for code A and B. A value of 15 indicates no bit errors, a value of 0 indicates 15 bit errors.
// Fields:
//  - [3:0] A (uint): Indicates the match level for code A. Refreshed after a positive Code A match. Typically >5
//  - [7:4] B (uint): Indicates the match level for code B. Refreshed after a positive Code B match. Typically >5

#define FH101RF_KORREL_VAL_ADDRESS  (0x2CU) //!< KORREL_VAL register address
#define FH101RF_KORREL_VAL_RESET_LE {0x0U}  //!< KORREL_VAL register reset value
#define FH101RF_KORREL_VAL_RESET_BE {0x0U}  //!< KORREL_VAL register reset value

// Register Layout Struct:

/**
 * @brief Indicates the match level for code A and B. A value of 15 indicates no bit errors, a value of 0 indicates 15 bit errors.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_korrel_val {
  /** @brief Indicates the match level for code A. Refreshed after a positive Code A match. Typically >5 */
  uint8_t a;
  /** @brief Indicates the match level for code B. Refreshed after a positive Code B match. Typically >5 */
  uint8_t b;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_korrel_val struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_val_pack_le(const struct fh101rf_korrel_val *r, uint8_t val[1]) {
  // A @ korrel_val[3:0]:
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)(((uint8_t)r->a) & 0xFU);
  // B @ korrel_val[7:4]:
  val[0] &= (uint8_t)~0xF0U;
  val[0] |= (uint8_t)(((uint8_t)(r->b << 4)) & 0xF0U);
}

/**
 * @brief Convert @ref struct fh101rf_korrel_val struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_korrel_val_pack_be(const struct fh101rf_korrel_val *r, uint8_t val[1]) {
  // A @ korrel_val[3:0]:
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)(((uint8_t)r->a) & 0xFU);
  // B @ korrel_val[7:4]:
  val[0] &= (uint8_t)~0xF0U;
  val[0] |= (uint8_t)(((uint8_t)(r->b << 4)) & 0xF0U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_val fh101rf_korrel_val_unpack_le(const uint8_t val[1]) {
  struct fh101rf_korrel_val r = {0};
  // A @ korrel_val[3:0]:
  r.a = (uint8_t)((val[0] & 0xFU));
  // B @ korrel_val[7:4]:
  r.b = (uint8_t)(((val[0] & 0xF0U) >> 4));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_korrel_val fh101rf_korrel_val_unpack_be(const uint8_t val[1]) {
  struct fh101rf_korrel_val r = {0};
  // A @ korrel_val[3:0]:
  r.a = (uint8_t)((val[0] & 0xFU));
  // B @ korrel_val[7:4]:
  r.b = (uint8_t)(((val[0] & 0xF0U) >> 4));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_korrel_val(const struct fh101rf_korrel_val *r) {
  if ((r->a & ~(uint8_t)0xF) != 0) return 1;
  if ((r->b & ~(uint8_t)0xF) != 0) return 5;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_val_try_unpack_le(const uint8_t val[1], struct fh101rf_korrel_val *r) {
  *r = fh101rf_korrel_val_unpack_le(val);
  return fh101rf_validate_korrel_val(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_korrel_val_try_unpack_be(const uint8_t val[1], struct fh101rf_korrel_val *r) {
  *r = fh101rf_korrel_val_unpack_be(val);
  return fh101rf_validate_korrel_val(r);
}

// =============================================================================
// ==== LCO_FREQ_2G4_HI Register ===============================================
// =============================================================================
// Holds the current frequency of the 2.4-GHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_LCO_FREQ_2G4_HI_ADDRESS  (0x18U) //!< LCO_FREQ_2G4_HI register address
#define FH101RF_LCO_FREQ_2G4_HI_RESET_LE {0x0U}  //!< LCO_FREQ_2G4_HI register reset value
#define FH101RF_LCO_FREQ_2G4_HI_RESET_BE {0x0U}  //!< LCO_FREQ_2G4_HI register reset value

// Register Layout Struct:

/**
 * @brief Holds the current frequency of the 2.4-GHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_lco_freq_2g4_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_lco_freq_2g4_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_2g4_hi_pack_le(const struct fh101rf_lco_freq_2g4_hi *r, uint8_t val[1]) {
  // DATA @ lco_freq_2g4_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_lco_freq_2g4_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_2g4_hi_pack_be(const struct fh101rf_lco_freq_2g4_hi *r, uint8_t val[1]) {
  // DATA @ lco_freq_2g4_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_2g4_hi fh101rf_lco_freq_2g4_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_lco_freq_2g4_hi r = {0};
  // DATA @ lco_freq_2g4_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_2g4_hi fh101rf_lco_freq_2g4_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_lco_freq_2g4_hi r = {0};
  // DATA @ lco_freq_2g4_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_lco_freq_2g4_hi(const struct fh101rf_lco_freq_2g4_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_2g4_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_lco_freq_2g4_hi *r) {
  *r = fh101rf_lco_freq_2g4_hi_unpack_le(val);
  return fh101rf_validate_lco_freq_2g4_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_2g4_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_lco_freq_2g4_hi *r) {
  *r = fh101rf_lco_freq_2g4_hi_unpack_be(val);
  return fh101rf_validate_lco_freq_2g4_hi(r);
}

// =============================================================================
// ==== LCO_FREQ_2G4_LO Register ===============================================
// =============================================================================
// Holds the current frequency of the 2.4-GHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_LCO_FREQ_2G4_LO_ADDRESS  (0x19U) //!< LCO_FREQ_2G4_LO register address
#define FH101RF_LCO_FREQ_2G4_LO_RESET_LE {0x0U}  //!< LCO_FREQ_2G4_LO register reset value
#define FH101RF_LCO_FREQ_2G4_LO_RESET_BE {0x0U}  //!< LCO_FREQ_2G4_LO register reset value

// Register Layout Struct:

/**
 * @brief Holds the current frequency of the 2.4-GHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_lco_freq_2g4_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_lco_freq_2g4_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_2g4_lo_pack_le(const struct fh101rf_lco_freq_2g4_lo *r, uint8_t val[1]) {
  // DATA @ lco_freq_2g4_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_lco_freq_2g4_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_2g4_lo_pack_be(const struct fh101rf_lco_freq_2g4_lo *r, uint8_t val[1]) {
  // DATA @ lco_freq_2g4_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_2g4_lo fh101rf_lco_freq_2g4_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_lco_freq_2g4_lo r = {0};
  // DATA @ lco_freq_2g4_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_2g4_lo fh101rf_lco_freq_2g4_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_lco_freq_2g4_lo r = {0};
  // DATA @ lco_freq_2g4_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_lco_freq_2g4_lo(const struct fh101rf_lco_freq_2g4_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_2g4_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_lco_freq_2g4_lo *r) {
  *r = fh101rf_lco_freq_2g4_lo_unpack_le(val);
  return fh101rf_validate_lco_freq_2g4_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_2g4_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_lco_freq_2g4_lo *r) {
  *r = fh101rf_lco_freq_2g4_lo_unpack_be(val);
  return fh101rf_validate_lco_freq_2g4_lo(r);
}

// =============================================================================
// ==== LCO_FREQ_433_HI Register ===============================================
// =============================================================================
// Holds the current frequency of the 433-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_LCO_FREQ_433_HI_ADDRESS  (0x14U) //!< LCO_FREQ_433_HI register address
#define FH101RF_LCO_FREQ_433_HI_RESET_LE {0x0U}  //!< LCO_FREQ_433_HI register reset value
#define FH101RF_LCO_FREQ_433_HI_RESET_BE {0x0U}  //!< LCO_FREQ_433_HI register reset value

// Register Layout Struct:

/**
 * @brief Holds the current frequency of the 433-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_lco_freq_433_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_lco_freq_433_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_433_hi_pack_le(const struct fh101rf_lco_freq_433_hi *r, uint8_t val[1]) {
  // DATA @ lco_freq_433_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_lco_freq_433_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_433_hi_pack_be(const struct fh101rf_lco_freq_433_hi *r, uint8_t val[1]) {
  // DATA @ lco_freq_433_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_433_hi fh101rf_lco_freq_433_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_lco_freq_433_hi r = {0};
  // DATA @ lco_freq_433_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_433_hi fh101rf_lco_freq_433_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_lco_freq_433_hi r = {0};
  // DATA @ lco_freq_433_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_lco_freq_433_hi(const struct fh101rf_lco_freq_433_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_433_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_lco_freq_433_hi *r) {
  *r = fh101rf_lco_freq_433_hi_unpack_le(val);
  return fh101rf_validate_lco_freq_433_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_433_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_lco_freq_433_hi *r) {
  *r = fh101rf_lco_freq_433_hi_unpack_be(val);
  return fh101rf_validate_lco_freq_433_hi(r);
}

// =============================================================================
// ==== LCO_FREQ_433_LO Register ===============================================
// =============================================================================
// Holds the current frequency of the 433-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_LCO_FREQ_433_LO_ADDRESS  (0x15U) //!< LCO_FREQ_433_LO register address
#define FH101RF_LCO_FREQ_433_LO_RESET_LE {0x0U}  //!< LCO_FREQ_433_LO register reset value
#define FH101RF_LCO_FREQ_433_LO_RESET_BE {0x0U}  //!< LCO_FREQ_433_LO register reset value

// Register Layout Struct:

/**
 * @brief Holds the current frequency of the 433-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_lco_freq_433_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_lco_freq_433_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_433_lo_pack_le(const struct fh101rf_lco_freq_433_lo *r, uint8_t val[1]) {
  // DATA @ lco_freq_433_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_lco_freq_433_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_433_lo_pack_be(const struct fh101rf_lco_freq_433_lo *r, uint8_t val[1]) {
  // DATA @ lco_freq_433_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_433_lo fh101rf_lco_freq_433_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_lco_freq_433_lo r = {0};
  // DATA @ lco_freq_433_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_433_lo fh101rf_lco_freq_433_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_lco_freq_433_lo r = {0};
  // DATA @ lco_freq_433_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_lco_freq_433_lo(const struct fh101rf_lco_freq_433_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_433_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_lco_freq_433_lo *r) {
  *r = fh101rf_lco_freq_433_lo_unpack_le(val);
  return fh101rf_validate_lco_freq_433_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_433_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_lco_freq_433_lo *r) {
  *r = fh101rf_lco_freq_433_lo_unpack_be(val);
  return fh101rf_validate_lco_freq_433_lo(r);
}

// =============================================================================
// ==== LCO_FREQ_868_HI Register ===============================================
// =============================================================================
// Holds the current frequency of the 868/915-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_LCO_FREQ_868_HI_ADDRESS  (0x16U) //!< LCO_FREQ_868_HI register address
#define FH101RF_LCO_FREQ_868_HI_RESET_LE {0x0U}  //!< LCO_FREQ_868_HI register reset value
#define FH101RF_LCO_FREQ_868_HI_RESET_BE {0x0U}  //!< LCO_FREQ_868_HI register reset value

// Register Layout Struct:

/**
 * @brief Holds the current frequency of the 868/915-MHz band, high byte (15:8). Read the registers in the given order from 0x14 to 0x19. (According to register table in DS v1.3b, only 12:8).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_lco_freq_868_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_lco_freq_868_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_868_hi_pack_le(const struct fh101rf_lco_freq_868_hi *r, uint8_t val[1]) {
  // DATA @ lco_freq_868_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_lco_freq_868_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_868_hi_pack_be(const struct fh101rf_lco_freq_868_hi *r, uint8_t val[1]) {
  // DATA @ lco_freq_868_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_868_hi fh101rf_lco_freq_868_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_lco_freq_868_hi r = {0};
  // DATA @ lco_freq_868_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_868_hi fh101rf_lco_freq_868_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_lco_freq_868_hi r = {0};
  // DATA @ lco_freq_868_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_lco_freq_868_hi(const struct fh101rf_lco_freq_868_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_868_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_lco_freq_868_hi *r) {
  *r = fh101rf_lco_freq_868_hi_unpack_le(val);
  return fh101rf_validate_lco_freq_868_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_868_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_lco_freq_868_hi *r) {
  *r = fh101rf_lco_freq_868_hi_unpack_be(val);
  return fh101rf_validate_lco_freq_868_hi(r);
}

// =============================================================================
// ==== LCO_FREQ_868_LO Register ===============================================
// =============================================================================
// Holds the current frequency of the 868/915-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_LCO_FREQ_868_LO_ADDRESS  (0x17U) //!< LCO_FREQ_868_LO register address
#define FH101RF_LCO_FREQ_868_LO_RESET_LE {0x0U}  //!< LCO_FREQ_868_LO register reset value
#define FH101RF_LCO_FREQ_868_LO_RESET_BE {0x0U}  //!< LCO_FREQ_868_LO register reset value

// Register Layout Struct:

/**
 * @brief Holds the current frequency of the 868/915-MHz band, low byte (7:0). Read the registers in the given order from 0x14 to 0x19.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_lco_freq_868_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_lco_freq_868_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_868_lo_pack_le(const struct fh101rf_lco_freq_868_lo *r, uint8_t val[1]) {
  // DATA @ lco_freq_868_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_lco_freq_868_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lco_freq_868_lo_pack_be(const struct fh101rf_lco_freq_868_lo *r, uint8_t val[1]) {
  // DATA @ lco_freq_868_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_868_lo fh101rf_lco_freq_868_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_lco_freq_868_lo r = {0};
  // DATA @ lco_freq_868_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lco_freq_868_lo fh101rf_lco_freq_868_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_lco_freq_868_lo r = {0};
  // DATA @ lco_freq_868_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_lco_freq_868_lo(const struct fh101rf_lco_freq_868_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_868_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_lco_freq_868_lo *r) {
  *r = fh101rf_lco_freq_868_lo_unpack_le(val);
  return fh101rf_validate_lco_freq_868_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lco_freq_868_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_lco_freq_868_lo *r) {
  *r = fh101rf_lco_freq_868_lo_unpack_be(val);
  return fh101rf_validate_lco_freq_868_lo(r);
}

// =============================================================================
// ==== LC_TG_ENA Register =====================================================
// =============================================================================
// Set to 0x00 during power-up.
// Fields:
//  - [0] DATA (bool)

#define FH101RF_LC_TG_ENA_ADDRESS  (0x76U) //!< LC_TG_ENA register address
#define FH101RF_LC_TG_ENA_RESET_LE {0x1U}  //!< LC_TG_ENA register reset value
#define FH101RF_LC_TG_ENA_RESET_BE {0x1U}  //!< LC_TG_ENA register reset value

// Register Layout Struct:

/**
 * @brief Set to 0x00 during power-up.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_lc_tg_ena {
  bool data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_lc_tg_ena struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lc_tg_ena_pack_le(const struct fh101rf_lc_tg_ena *r, uint8_t val[1]) {
  // DATA @ lc_tg_ena[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1U);
}

/**
 * @brief Convert @ref struct fh101rf_lc_tg_ena struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_lc_tg_ena_pack_be(const struct fh101rf_lc_tg_ena *r, uint8_t val[1]) {
  // DATA @ lc_tg_ena[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lc_tg_ena fh101rf_lc_tg_ena_unpack_le(const uint8_t val[1]) {
  struct fh101rf_lc_tg_ena r = {0};
  // DATA @ lc_tg_ena[0]:
  r.data = (bool)((val[0] & 0x1U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_lc_tg_ena fh101rf_lc_tg_ena_unpack_be(const uint8_t val[1]) {
  struct fh101rf_lc_tg_ena r = {0};
  // DATA @ lc_tg_ena[0]:
  r.data = (bool)((val[0] & 0x1U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_lc_tg_ena(const struct fh101rf_lc_tg_ena *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lc_tg_ena_try_unpack_le(const uint8_t val[1], struct fh101rf_lc_tg_ena *r) {
  *r = fh101rf_lc_tg_ena_unpack_le(val);
  return fh101rf_validate_lc_tg_ena(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_lc_tg_ena_try_unpack_be(const uint8_t val[1], struct fh101rf_lc_tg_ena *r) {
  *r = fh101rf_lc_tg_ena_unpack_be(val);
  return fh101rf_validate_lc_tg_ena(r);
}

// =============================================================================
// ==== LDO_XTAL_CTRL Register =================================================
// =============================================================================
// Controls the LDO and the crystal oscillator.
// Fields:
//  - [1:0] INT (fixed: 0x3): RESERVED. Do not change. Write 0x3
//  - [3] XTAL_OSC_BYP (bool): Used for selecting an external system clock source that is applied to pin CLK32_XI. In this case, XTAL_OSC_BYP should be true. Set this, if a 2-pin crystal will not be used.
//  - [5] LDO_ENA_NFA (bool): sed to deactivate the internal LDO for VDDC voltage generation. If set to true, an external VDDC source must be supplied.

#define FH101RF_LDO_XTAL_CTRL_ADDRESS  (0x74U) //!< LDO_XTAL_CTRL register address
#define FH101RF_LDO_XTAL_CTRL_RESET_LE {0x3U}  //!< LDO_XTAL_CTRL register reset value
#define FH101RF_LDO_XTAL_CTRL_RESET_BE {0x3U}  //!< LDO_XTAL_CTRL register reset value

// Register Layout Struct:

/**
 * @brief Controls the LDO and the crystal oscillator.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_ldo_xtal_ctrl {
  /** @brief sed to deactivate the internal LDO for VDDC voltage generation. If set to true, an external VDDC source must be supplied. */
  bool ldo_ena_nfa;
  /** @brief Used for selecting an external system clock source that is applied to pin CLK32_XI. In this case, XTAL_OSC_BYP should be true. Set this, if a 2-pin crystal will not be used. */
  bool xtal_osc_byp;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_ldo_xtal_ctrl struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_ldo_xtal_ctrl_pack_le(const struct fh101rf_ldo_xtal_ctrl *r, uint8_t val[1]) {
  // INT @ ldo_xtal_ctrl[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)0x3; // Fixed value.
  // LDO_ENA_NFA @ ldo_xtal_ctrl[5]:
  val[0] &= (uint8_t)~0x20U;
  val[0] |= (uint8_t)(((uint8_t)(r->ldo_ena_nfa << 5)) & 0x20U);
  // XTAL_OSC_BYP @ ldo_xtal_ctrl[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->xtal_osc_byp << 3)) & 0x8U);
}

/**
 * @brief Convert @ref struct fh101rf_ldo_xtal_ctrl struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_ldo_xtal_ctrl_pack_be(const struct fh101rf_ldo_xtal_ctrl *r, uint8_t val[1]) {
  // INT @ ldo_xtal_ctrl[1:0]:
  val[0] &= (uint8_t)~0x3U;
  val[0] |= (uint8_t)0x3; // Fixed value.
  // LDO_ENA_NFA @ ldo_xtal_ctrl[5]:
  val[0] &= (uint8_t)~0x20U;
  val[0] |= (uint8_t)(((uint8_t)(r->ldo_ena_nfa << 5)) & 0x20U);
  // XTAL_OSC_BYP @ ldo_xtal_ctrl[3]:
  val[0] &= (uint8_t)~0x8U;
  val[0] |= (uint8_t)(((uint8_t)(r->xtal_osc_byp << 3)) & 0x8U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_ldo_xtal_ctrl fh101rf_ldo_xtal_ctrl_unpack_le(const uint8_t val[1]) {
  struct fh101rf_ldo_xtal_ctrl r = {0};
  // LDO_ENA_NFA @ ldo_xtal_ctrl[5]:
  r.ldo_ena_nfa = (bool)(((val[0] & 0x20U) >> 5));
  // XTAL_OSC_BYP @ ldo_xtal_ctrl[3]:
  r.xtal_osc_byp = (bool)(((val[0] & 0x8U) >> 3));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_ldo_xtal_ctrl fh101rf_ldo_xtal_ctrl_unpack_be(const uint8_t val[1]) {
  struct fh101rf_ldo_xtal_ctrl r = {0};
  // LDO_ENA_NFA @ ldo_xtal_ctrl[5]:
  r.ldo_ena_nfa = (bool)(((val[0] & 0x20U) >> 5));
  // XTAL_OSC_BYP @ ldo_xtal_ctrl[3]:
  r.xtal_osc_byp = (bool)(((val[0] & 0x8U) >> 3));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_ldo_xtal_ctrl(const struct fh101rf_ldo_xtal_ctrl *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_ldo_xtal_ctrl_try_unpack_le(const uint8_t val[1], struct fh101rf_ldo_xtal_ctrl *r) {
  *r = fh101rf_ldo_xtal_ctrl_unpack_le(val);
  return fh101rf_validate_ldo_xtal_ctrl(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_ldo_xtal_ctrl_try_unpack_be(const uint8_t val[1], struct fh101rf_ldo_xtal_ctrl *r) {
  *r = fh101rf_ldo_xtal_ctrl_unpack_be(val);
  return fh101rf_validate_ldo_xtal_ctrl(r);
}

// =============================================================================
// ==== MUX_D_OUT_SEL Register =================================================
// =============================================================================
// Selects the signal routed to the GPO1 and GPO2 pins.
// Fields:
//  - [3:0] OUT (enum OUT)

#define FH101RF_MUX_D_OUT_SEL_ADDRESS  (0x75U) //!< MUX_D_OUT_SEL register address
#define FH101RF_MUX_D_OUT_SEL_RESET_LE {0xFU}  //!< MUX_D_OUT_SEL register reset value
#define FH101RF_MUX_D_OUT_SEL_RESET_BE {0xFU}  //!< MUX_D_OUT_SEL register reset value

// Register-specific enums and sub-layouts:

enum fh101rf_out {
  /** @brief System Clock CLK32 on GPO1 and interrupt signal IRQ_EVENT on GPO2. */
  FH101RF_OUT_CLK32_IRQ_EVENT = 0xEU,
  /** @brief General ID match on GPO1 and 433MHz Wake-up A signal WUP_A on GPO2. */
  FH101RF_OUT_IDM_WUP_A_433 = 0x6U,
  /** @brief Interrupt signal IRQ_EVENT on GPO1 and static high on GPO2. */
  FH101RF_OUT_IRQ_EVENT_1 = 0xFU,
  /** @brief RX data stream at 2.4GHz. CLK on GPO1 and DATA on GPO2. */
  FH101RF_OUT_RX_2G4 = 0x0U,
  /** @brief RX data stream at 433MHz. CLK on GPO1 and DATA on GPO2. */
  FH101RF_OUT_RX_433 = 0x2U,
  /** @brief RX data stream at 868MHz. CLK on GPO1 and DATA on GPO2. */
  FH101RF_OUT_RX_868 = 0x1U,
  /** @brief 2.4GHz Wake-up A signal WUP_A on GPO1 and RX_ACTIVE trigger signal on GPO2. */
  FH101RF_OUT_WUP_A_2G4_RX_ACTIVE = 0xAU,
  /** @brief 433MHz Wake-up A signal WUP_A on GPO1 and RX_ACTIVE trigger signal on GPO2. */
  FH101RF_OUT_WUP_A_433_RX_ACTIVE = 0x8U,
  /** @brief 868MHz Wake-up A signal WUP_A on GPO1 and RX_ACTIVE trigger signal on GPO2. */
  FH101RF_OUT_WUP_A_868_RX_ACTIVE = 0x9U,
  /** @brief Wake-up A/B signals at 2.4GHz. WUP_A on GPO1 and WUP_B on GPO2. */
  FH101RF_OUT_WUP_A_B_2G4 = 0x3U,
  /** @brief Wake-up A/B signals at 868MHz. WUP_A on GPO1 and WUP_B on GPO2. */
  FH101RF_OUT_WUP_A_B_868 = 0x7U,
};

// Register Layout Struct:

/**
 * @brief Selects the signal routed to the GPO1 and GPO2 pins.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_mux_d_out_sel {
  enum fh101rf_out out;
};

// Enum validation functions:

/**
 * @brief Check if a numeric value is a valid @ref enum fh101rf_out.
 * @returns bool (true/false)
 */
#define FH101RF_IS_VALID_OUT(_VAL_) (                                                              \
  ((_VAL_) <= 0x3U) ? true :                                                                       \
  (0x6U <= (_VAL_) && (_VAL_) <= 0xAU) ? true :                                                    \
  (0xEU <= (_VAL_) && (_VAL_) <= 0xFU) ? true :                                                    \
  false )

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_mux_d_out_sel struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_mux_d_out_sel_pack_le(const struct fh101rf_mux_d_out_sel *r, uint8_t val[1]) {
  // OUT @ mux_d_out_sel[3:0]:
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)(((uint8_t)r->out) & 0xFU);
}

/**
 * @brief Convert @ref struct fh101rf_mux_d_out_sel struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_mux_d_out_sel_pack_be(const struct fh101rf_mux_d_out_sel *r, uint8_t val[1]) {
  // OUT @ mux_d_out_sel[3:0]:
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)(((uint8_t)r->out) & 0xFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_mux_d_out_sel fh101rf_mux_d_out_sel_unpack_le(const uint8_t val[1]) {
  struct fh101rf_mux_d_out_sel r = {0};
  // OUT @ mux_d_out_sel[3:0]:
  r.out = (enum fh101rf_out)((val[0] & 0xFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_mux_d_out_sel fh101rf_mux_d_out_sel_unpack_be(const uint8_t val[1]) {
  struct fh101rf_mux_d_out_sel r = {0};
  // OUT @ mux_d_out_sel[3:0]:
  r.out = (enum fh101rf_out)((val[0] & 0xFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_mux_d_out_sel(const struct fh101rf_mux_d_out_sel *r) {
  if (!(FH101RF_IS_VALID_OUT(r->out))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_mux_d_out_sel_try_unpack_le(const uint8_t val[1], struct fh101rf_mux_d_out_sel *r) {
  *r = fh101rf_mux_d_out_sel_unpack_le(val);
  return fh101rf_validate_mux_d_out_sel(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_mux_d_out_sel_try_unpack_be(const uint8_t val[1], struct fh101rf_mux_d_out_sel *r) {
  *r = fh101rf_mux_d_out_sel_unpack_be(val);
  return fh101rf_validate_mux_d_out_sel(r);
}

// =============================================================================
// ==== NFA2G4_FAST Register ===================================================
// =============================================================================
// Set the sample-rate for FDD-mode data reception in the 2.4-GHz band.
// Fields:
//  - [2:0] DATA (enum SAMPLE_RATE)

#define FH101RF_NFA2G4_FAST_ADDRESS  (0x5U) //!< NFA2G4_FAST register address
#define FH101RF_NFA2G4_FAST_RESET_LE {0x0U} //!< NFA2G4_FAST register reset value
#define FH101RF_NFA2G4_FAST_RESET_BE {0x0U} //!< NFA2G4_FAST register reset value

// Register Layout Struct:

/**
 * @brief Set the sample-rate for FDD-mode data reception in the 2.4-GHz band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_nfa2g4_fast {
  enum fh101rf_sample_rate data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_nfa2g4_fast struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa2g4_fast_pack_le(const struct fh101rf_nfa2g4_fast *r, uint8_t val[1]) {
  // DATA @ nfa2g4_fast[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_nfa2g4_fast struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa2g4_fast_pack_be(const struct fh101rf_nfa2g4_fast *r, uint8_t val[1]) {
  // DATA @ nfa2g4_fast[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa2g4_fast fh101rf_nfa2g4_fast_unpack_le(const uint8_t val[1]) {
  struct fh101rf_nfa2g4_fast r = {0};
  // DATA @ nfa2g4_fast[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa2g4_fast fh101rf_nfa2g4_fast_unpack_be(const uint8_t val[1]) {
  struct fh101rf_nfa2g4_fast r = {0};
  // DATA @ nfa2g4_fast[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_nfa2g4_fast(const struct fh101rf_nfa2g4_fast *r) {
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->data))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa2g4_fast_try_unpack_le(const uint8_t val[1], struct fh101rf_nfa2g4_fast *r) {
  *r = fh101rf_nfa2g4_fast_unpack_le(val);
  return fh101rf_validate_nfa2g4_fast(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa2g4_fast_try_unpack_be(const uint8_t val[1], struct fh101rf_nfa2g4_fast *r) {
  *r = fh101rf_nfa2g4_fast_unpack_be(val);
  return fh101rf_validate_nfa2g4_fast(r);
}

// =============================================================================
// ==== NFA2G4_SLOW Register ===================================================
// =============================================================================
// Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 2.4-GHz band.
// Fields:
//  - [2:0] DATA (enum SAMPLE_RATE)

#define FH101RF_NFA2G4_SLOW_ADDRESS  (0x4U) //!< NFA2G4_SLOW register address
#define FH101RF_NFA2G4_SLOW_RESET_LE {0x5U} //!< NFA2G4_SLOW register reset value
#define FH101RF_NFA2G4_SLOW_RESET_BE {0x5U} //!< NFA2G4_SLOW register reset value

// Register Layout Struct:

/**
 * @brief Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 2.4-GHz band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_nfa2g4_slow {
  enum fh101rf_sample_rate data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_nfa2g4_slow struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa2g4_slow_pack_le(const struct fh101rf_nfa2g4_slow *r, uint8_t val[1]) {
  // DATA @ nfa2g4_slow[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_nfa2g4_slow struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa2g4_slow_pack_be(const struct fh101rf_nfa2g4_slow *r, uint8_t val[1]) {
  // DATA @ nfa2g4_slow[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa2g4_slow fh101rf_nfa2g4_slow_unpack_le(const uint8_t val[1]) {
  struct fh101rf_nfa2g4_slow r = {0};
  // DATA @ nfa2g4_slow[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa2g4_slow fh101rf_nfa2g4_slow_unpack_be(const uint8_t val[1]) {
  struct fh101rf_nfa2g4_slow r = {0};
  // DATA @ nfa2g4_slow[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_nfa2g4_slow(const struct fh101rf_nfa2g4_slow *r) {
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->data))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa2g4_slow_try_unpack_le(const uint8_t val[1], struct fh101rf_nfa2g4_slow *r) {
  *r = fh101rf_nfa2g4_slow_unpack_le(val);
  return fh101rf_validate_nfa2g4_slow(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa2g4_slow_try_unpack_be(const uint8_t val[1], struct fh101rf_nfa2g4_slow *r) {
  *r = fh101rf_nfa2g4_slow_unpack_be(val);
  return fh101rf_validate_nfa2g4_slow(r);
}

// =============================================================================
// ==== NFA433_FAST Register ===================================================
// =============================================================================
// Set the sample-rate for FDD-mode data reception in the 433-MHz band.
// Fields:
//  - [2:0] DATA (enum SAMPLE_RATE)

#define FH101RF_NFA433_FAST_ADDRESS  (0x1U) //!< NFA433_FAST register address
#define FH101RF_NFA433_FAST_RESET_LE {0x0U} //!< NFA433_FAST register reset value
#define FH101RF_NFA433_FAST_RESET_BE {0x0U} //!< NFA433_FAST register reset value

// Register Layout Struct:

/**
 * @brief Set the sample-rate for FDD-mode data reception in the 433-MHz band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_nfa433_fast {
  enum fh101rf_sample_rate data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_nfa433_fast struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa433_fast_pack_le(const struct fh101rf_nfa433_fast *r, uint8_t val[1]) {
  // DATA @ nfa433_fast[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_nfa433_fast struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa433_fast_pack_be(const struct fh101rf_nfa433_fast *r, uint8_t val[1]) {
  // DATA @ nfa433_fast[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa433_fast fh101rf_nfa433_fast_unpack_le(const uint8_t val[1]) {
  struct fh101rf_nfa433_fast r = {0};
  // DATA @ nfa433_fast[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa433_fast fh101rf_nfa433_fast_unpack_be(const uint8_t val[1]) {
  struct fh101rf_nfa433_fast r = {0};
  // DATA @ nfa433_fast[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_nfa433_fast(const struct fh101rf_nfa433_fast *r) {
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->data))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa433_fast_try_unpack_le(const uint8_t val[1], struct fh101rf_nfa433_fast *r) {
  *r = fh101rf_nfa433_fast_unpack_le(val);
  return fh101rf_validate_nfa433_fast(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa433_fast_try_unpack_be(const uint8_t val[1], struct fh101rf_nfa433_fast *r) {
  *r = fh101rf_nfa433_fast_unpack_be(val);
  return fh101rf_validate_nfa433_fast(r);
}

// =============================================================================
// ==== NFA433_SLOW Register ===================================================
// =============================================================================
// Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 433-MHz band.
// Fields:
//  - [2:0] DATA (enum SAMPLE_RATE)

#define FH101RF_NFA433_SLOW_ADDRESS  (0x0U) //!< NFA433_SLOW register address
#define FH101RF_NFA433_SLOW_RESET_LE {0x5U} //!< NFA433_SLOW register reset value
#define FH101RF_NFA433_SLOW_RESET_BE {0x5U} //!< NFA433_SLOW register reset value

// Register Layout Struct:

/**
 * @brief Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 433-MHz band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_nfa433_slow {
  enum fh101rf_sample_rate data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_nfa433_slow struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa433_slow_pack_le(const struct fh101rf_nfa433_slow *r, uint8_t val[1]) {
  // DATA @ nfa433_slow[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_nfa433_slow struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa433_slow_pack_be(const struct fh101rf_nfa433_slow *r, uint8_t val[1]) {
  // DATA @ nfa433_slow[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa433_slow fh101rf_nfa433_slow_unpack_le(const uint8_t val[1]) {
  struct fh101rf_nfa433_slow r = {0};
  // DATA @ nfa433_slow[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa433_slow fh101rf_nfa433_slow_unpack_be(const uint8_t val[1]) {
  struct fh101rf_nfa433_slow r = {0};
  // DATA @ nfa433_slow[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_nfa433_slow(const struct fh101rf_nfa433_slow *r) {
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->data))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa433_slow_try_unpack_le(const uint8_t val[1], struct fh101rf_nfa433_slow *r) {
  *r = fh101rf_nfa433_slow_unpack_le(val);
  return fh101rf_validate_nfa433_slow(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa433_slow_try_unpack_be(const uint8_t val[1], struct fh101rf_nfa433_slow *r) {
  *r = fh101rf_nfa433_slow_unpack_be(val);
  return fh101rf_validate_nfa433_slow(r);
}

// =============================================================================
// ==== NFA868_FAST Register ===================================================
// =============================================================================
// Set the sample-rate for FDD-mode data reception in the 868-MHz band.
// Fields:
//  - [2:0] DATA (enum SAMPLE_RATE)

#define FH101RF_NFA868_FAST_ADDRESS  (0x3U) //!< NFA868_FAST register address
#define FH101RF_NFA868_FAST_RESET_LE {0x0U} //!< NFA868_FAST register reset value
#define FH101RF_NFA868_FAST_RESET_BE {0x0U} //!< NFA868_FAST register reset value

// Register Layout Struct:

/**
 * @brief Set the sample-rate for FDD-mode data reception in the 868-MHz band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_nfa868_fast {
  enum fh101rf_sample_rate data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_nfa868_fast struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa868_fast_pack_le(const struct fh101rf_nfa868_fast *r, uint8_t val[1]) {
  // DATA @ nfa868_fast[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_nfa868_fast struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa868_fast_pack_be(const struct fh101rf_nfa868_fast *r, uint8_t val[1]) {
  // DATA @ nfa868_fast[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa868_fast fh101rf_nfa868_fast_unpack_le(const uint8_t val[1]) {
  struct fh101rf_nfa868_fast r = {0};
  // DATA @ nfa868_fast[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa868_fast fh101rf_nfa868_fast_unpack_be(const uint8_t val[1]) {
  struct fh101rf_nfa868_fast r = {0};
  // DATA @ nfa868_fast[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_nfa868_fast(const struct fh101rf_nfa868_fast *r) {
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->data))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa868_fast_try_unpack_le(const uint8_t val[1], struct fh101rf_nfa868_fast *r) {
  *r = fh101rf_nfa868_fast_unpack_le(val);
  return fh101rf_validate_nfa868_fast(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa868_fast_try_unpack_be(const uint8_t val[1], struct fh101rf_nfa868_fast *r) {
  *r = fh101rf_nfa868_fast_unpack_be(val);
  return fh101rf_validate_nfa868_fast(r);
}

// =============================================================================
// ==== NFA868_SLOW Register ===================================================
// =============================================================================
// Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 868-MHz band.
// Fields:
//  - [2:0] DATA (enum SAMPLE_RATE)

#define FH101RF_NFA868_SLOW_ADDRESS  (0x2U) //!< NFA868_SLOW register address
#define FH101RF_NFA868_SLOW_RESET_LE {0x5U} //!< NFA868_SLOW register reset value
#define FH101RF_NFA868_SLOW_RESET_BE {0x5U} //!< NFA868_SLOW register reset value

// Register Layout Struct:

/**
 * @brief Set the sample-rate for preamble-listening (LDR-mode with FDD/IDM enabled) or single-sequence wake-up (FDD disabled) in the 868-MHz band.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_nfa868_slow {
  enum fh101rf_sample_rate data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_nfa868_slow struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa868_slow_pack_le(const struct fh101rf_nfa868_slow *r, uint8_t val[1]) {
  // DATA @ nfa868_slow[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/**
 * @brief Convert @ref struct fh101rf_nfa868_slow struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_nfa868_slow_pack_be(const struct fh101rf_nfa868_slow *r, uint8_t val[1]) {
  // DATA @ nfa868_slow[2:0]:
  val[0] &= (uint8_t)~0x7U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x7U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa868_slow fh101rf_nfa868_slow_unpack_le(const uint8_t val[1]) {
  struct fh101rf_nfa868_slow r = {0};
  // DATA @ nfa868_slow[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_nfa868_slow fh101rf_nfa868_slow_unpack_be(const uint8_t val[1]) {
  struct fh101rf_nfa868_slow r = {0};
  // DATA @ nfa868_slow[2:0]:
  r.data = (enum fh101rf_sample_rate)((val[0] & 0x7U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_nfa868_slow(const struct fh101rf_nfa868_slow *r) {
  if (!(FH101RF_IS_VALID_SAMPLE_RATE(r->data))) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa868_slow_try_unpack_le(const uint8_t val[1], struct fh101rf_nfa868_slow *r) {
  *r = fh101rf_nfa868_slow_unpack_le(val);
  return fh101rf_validate_nfa868_slow(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_nfa868_slow_try_unpack_be(const uint8_t val[1], struct fh101rf_nfa868_slow *r) {
  *r = fh101rf_nfa868_slow_unpack_be(val);
  return fh101rf_validate_nfa868_slow(r);
}

// =============================================================================
// ==== N_LCO_TARGET_2G4_HI Register ===========================================
// =============================================================================
// Sets the high byte (15:8) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833. (According to register table in DS v1.3b, only 12:8).
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_N_LCO_TARGET_2G4_HI_ADDRESS  (0xFU)  //!< N_LCO_TARGET_2G4_HI register address
#define FH101RF_N_LCO_TARGET_2G4_HI_RESET_LE {0x12U} //!< N_LCO_TARGET_2G4_HI register reset value
#define FH101RF_N_LCO_TARGET_2G4_HI_RESET_BE {0x12U} //!< N_LCO_TARGET_2G4_HI register reset value

// Register Layout Struct:

/**
 * @brief Sets the high byte (15:8) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833. (According to register table in DS v1.3b, only 12:8).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_n_lco_target_2g4_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_2g4_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_2g4_hi_pack_le(const struct fh101rf_n_lco_target_2g4_hi *r, uint8_t val[1]) {
  // DATA @ n_lco_target_2g4_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_2g4_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_2g4_hi_pack_be(const struct fh101rf_n_lco_target_2g4_hi *r, uint8_t val[1]) {
  // DATA @ n_lco_target_2g4_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_2g4_hi fh101rf_n_lco_target_2g4_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_2g4_hi r = {0};
  // DATA @ n_lco_target_2g4_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_2g4_hi fh101rf_n_lco_target_2g4_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_2g4_hi r = {0};
  // DATA @ n_lco_target_2g4_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_n_lco_target_2g4_hi(const struct fh101rf_n_lco_target_2g4_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_2g4_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_n_lco_target_2g4_hi *r) {
  *r = fh101rf_n_lco_target_2g4_hi_unpack_le(val);
  return fh101rf_validate_n_lco_target_2g4_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_2g4_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_n_lco_target_2g4_hi *r) {
  *r = fh101rf_n_lco_target_2g4_hi_unpack_be(val);
  return fh101rf_validate_n_lco_target_2g4_hi(r);
}

// =============================================================================
// ==== N_LCO_TARGET_2G4_LO Register ===========================================
// =============================================================================
// Sets the low byte (7:0) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_N_LCO_TARGET_2G4_LO_ADDRESS  (0x10U) //!< N_LCO_TARGET_2G4_LO register address
#define FH101RF_N_LCO_TARGET_2G4_LO_RESET_LE {0xCEU} //!< N_LCO_TARGET_2G4_LO register reset value
#define FH101RF_N_LCO_TARGET_2G4_LO_RESET_BE {0xCEU} //!< N_LCO_TARGET_2G4_LO register reset value

// Register Layout Struct:

/**
 * @brief Sets the low byte (7:0) target freqency for the 2.4-GHz band. N_LCO_TARGET_<band> × 16 × 32,768 Hz; Values between 4482 and 4833.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_n_lco_target_2g4_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_2g4_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_2g4_lo_pack_le(const struct fh101rf_n_lco_target_2g4_lo *r, uint8_t val[1]) {
  // DATA @ n_lco_target_2g4_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_2g4_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_2g4_lo_pack_be(const struct fh101rf_n_lco_target_2g4_lo *r, uint8_t val[1]) {
  // DATA @ n_lco_target_2g4_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_2g4_lo fh101rf_n_lco_target_2g4_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_2g4_lo r = {0};
  // DATA @ n_lco_target_2g4_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_2g4_lo fh101rf_n_lco_target_2g4_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_2g4_lo r = {0};
  // DATA @ n_lco_target_2g4_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_n_lco_target_2g4_lo(const struct fh101rf_n_lco_target_2g4_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_2g4_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_n_lco_target_2g4_lo *r) {
  *r = fh101rf_n_lco_target_2g4_lo_unpack_le(val);
  return fh101rf_validate_n_lco_target_2g4_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_2g4_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_n_lco_target_2g4_lo *r) {
  *r = fh101rf_n_lco_target_2g4_lo_unpack_be(val);
  return fh101rf_validate_n_lco_target_2g4_lo(r);
}

// =============================================================================
// ==== N_LCO_TARGET_433_HI Register ===========================================
// =============================================================================
// Sets the high byte (15:8) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891. (According to register table in DS v1.3b, only 12:8).
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_N_LCO_TARGET_433_HI_ADDRESS  (0xBU) //!< N_LCO_TARGET_433_HI register address
#define FH101RF_N_LCO_TARGET_433_HI_RESET_LE {0xEU} //!< N_LCO_TARGET_433_HI register reset value
#define FH101RF_N_LCO_TARGET_433_HI_RESET_BE {0xEU} //!< N_LCO_TARGET_433_HI register reset value

// Register Layout Struct:

/**
 * @brief Sets the high byte (15:8) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891. (According to register table in DS v1.3b, only 12:8).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_n_lco_target_433_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_433_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_433_hi_pack_le(const struct fh101rf_n_lco_target_433_hi *r, uint8_t val[1]) {
  // DATA @ n_lco_target_433_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_433_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_433_hi_pack_be(const struct fh101rf_n_lco_target_433_hi *r, uint8_t val[1]) {
  // DATA @ n_lco_target_433_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_433_hi fh101rf_n_lco_target_433_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_433_hi r = {0};
  // DATA @ n_lco_target_433_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_433_hi fh101rf_n_lco_target_433_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_433_hi r = {0};
  // DATA @ n_lco_target_433_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_n_lco_target_433_hi(const struct fh101rf_n_lco_target_433_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_433_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_n_lco_target_433_hi *r) {
  *r = fh101rf_n_lco_target_433_hi_unpack_le(val);
  return fh101rf_validate_n_lco_target_433_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_433_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_n_lco_target_433_hi *r) {
  *r = fh101rf_n_lco_target_433_hi_unpack_be(val);
  return fh101rf_validate_n_lco_target_433_hi(r);
}

// =============================================================================
// ==== N_LCO_TARGET_433_LO Register ===========================================
// =============================================================================
// Sets the low byte (7:0) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_N_LCO_TARGET_433_LO_ADDRESS  (0xCU)  //!< N_LCO_TARGET_433_LO register address
#define FH101RF_N_LCO_TARGET_433_LO_RESET_LE {0x20U} //!< N_LCO_TARGET_433_LO register reset value
#define FH101RF_N_LCO_TARGET_433_LO_RESET_BE {0x20U} //!< N_LCO_TARGET_433_LO register reset value

// Register Layout Struct:

/**
 * @brief Sets the low byte (7:0) target freqency for the 433-MHz band. N_LCO_TARGET_<band> × 4 × 32,768 Hz; Values between 3304 and 3891.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_n_lco_target_433_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_433_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_433_lo_pack_le(const struct fh101rf_n_lco_target_433_lo *r, uint8_t val[1]) {
  // DATA @ n_lco_target_433_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_433_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_433_lo_pack_be(const struct fh101rf_n_lco_target_433_lo *r, uint8_t val[1]) {
  // DATA @ n_lco_target_433_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_433_lo fh101rf_n_lco_target_433_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_433_lo r = {0};
  // DATA @ n_lco_target_433_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_433_lo fh101rf_n_lco_target_433_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_433_lo r = {0};
  // DATA @ n_lco_target_433_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_n_lco_target_433_lo(const struct fh101rf_n_lco_target_433_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_433_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_n_lco_target_433_lo *r) {
  *r = fh101rf_n_lco_target_433_lo_unpack_le(val);
  return fh101rf_validate_n_lco_target_433_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_433_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_n_lco_target_433_lo *r) {
  *r = fh101rf_n_lco_target_433_lo_unpack_be(val);
  return fh101rf_validate_n_lco_target_433_lo(r);
}

// =============================================================================
// ==== N_LCO_TARGET_868_HI Register ===========================================
// =============================================================================
// Sets the high byte (15:8) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738. (According to register table in DS v1.3b, only 12:8).
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_N_LCO_TARGET_868_HI_ADDRESS  (0xDU) //!< N_LCO_TARGET_868_HI register address
#define FH101RF_N_LCO_TARGET_868_HI_RESET_LE {0xDU} //!< N_LCO_TARGET_868_HI register reset value
#define FH101RF_N_LCO_TARGET_868_HI_RESET_BE {0xDU} //!< N_LCO_TARGET_868_HI register reset value

// Register Layout Struct:

/**
 * @brief Sets the high byte (15:8) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738. (According to register table in DS v1.3b, only 12:8).
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_n_lco_target_868_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_868_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_868_hi_pack_le(const struct fh101rf_n_lco_target_868_hi *r, uint8_t val[1]) {
  // DATA @ n_lco_target_868_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_868_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_868_hi_pack_be(const struct fh101rf_n_lco_target_868_hi *r, uint8_t val[1]) {
  // DATA @ n_lco_target_868_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_868_hi fh101rf_n_lco_target_868_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_868_hi r = {0};
  // DATA @ n_lco_target_868_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_868_hi fh101rf_n_lco_target_868_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_868_hi r = {0};
  // DATA @ n_lco_target_868_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_n_lco_target_868_hi(const struct fh101rf_n_lco_target_868_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_868_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_n_lco_target_868_hi *r) {
  *r = fh101rf_n_lco_target_868_hi_unpack_le(val);
  return fh101rf_validate_n_lco_target_868_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_868_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_n_lco_target_868_hi *r) {
  *r = fh101rf_n_lco_target_868_hi_unpack_be(val);
  return fh101rf_validate_n_lco_target_868_hi(r);
}

// =============================================================================
// ==== N_LCO_TARGET_868_LO Register ===========================================
// =============================================================================
// Sets the low byte (7:0) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_N_LCO_TARGET_868_LO_ADDRESS  (0xEU)  //!< N_LCO_TARGET_868_LO register address
#define FH101RF_N_LCO_TARGET_868_LO_RESET_LE {0x87U} //!< N_LCO_TARGET_868_LO register reset value
#define FH101RF_N_LCO_TARGET_868_LO_RESET_BE {0x87U} //!< N_LCO_TARGET_868_LO register reset value

// Register Layout Struct:

/**
 * @brief Sets the low byte (7:0) target freqency for the 868/915-MHz band. N_LCO_TARGET_<band> × 8 × 32,768 Hz; Values between 3281 and 3738.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_n_lco_target_868_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_868_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_868_lo_pack_le(const struct fh101rf_n_lco_target_868_lo *r, uint8_t val[1]) {
  // DATA @ n_lco_target_868_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_n_lco_target_868_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_lco_target_868_lo_pack_be(const struct fh101rf_n_lco_target_868_lo *r, uint8_t val[1]) {
  // DATA @ n_lco_target_868_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_868_lo fh101rf_n_lco_target_868_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_868_lo r = {0};
  // DATA @ n_lco_target_868_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_lco_target_868_lo fh101rf_n_lco_target_868_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_n_lco_target_868_lo r = {0};
  // DATA @ n_lco_target_868_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_n_lco_target_868_lo(const struct fh101rf_n_lco_target_868_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_868_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_n_lco_target_868_lo *r) {
  *r = fh101rf_n_lco_target_868_lo_unpack_le(val);
  return fh101rf_validate_n_lco_target_868_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_lco_target_868_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_n_lco_target_868_lo *r) {
  *r = fh101rf_n_lco_target_868_lo_unpack_be(val);
  return fh101rf_validate_n_lco_target_868_lo(r);
}

// =============================================================================
// ==== N_SPG_TARGET Register ==================================================
// =============================================================================
// Target register for the Signal Processing Gain setting. Set to 0x46 during SPG calibration.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_N_SPG_TARGET_ADDRESS  (0x9U)  //!< N_SPG_TARGET register address
#define FH101RF_N_SPG_TARGET_RESET_LE {0x31U} //!< N_SPG_TARGET register reset value
#define FH101RF_N_SPG_TARGET_RESET_BE {0x31U} //!< N_SPG_TARGET register reset value

// Register Layout Struct:

/**
 * @brief Target register for the Signal Processing Gain setting. Set to 0x46 during SPG calibration.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_n_spg_target {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_n_spg_target struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_spg_target_pack_le(const struct fh101rf_n_spg_target *r, uint8_t val[1]) {
  // DATA @ n_spg_target[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_n_spg_target struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_n_spg_target_pack_be(const struct fh101rf_n_spg_target *r, uint8_t val[1]) {
  // DATA @ n_spg_target[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_spg_target fh101rf_n_spg_target_unpack_le(const uint8_t val[1]) {
  struct fh101rf_n_spg_target r = {0};
  // DATA @ n_spg_target[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_n_spg_target fh101rf_n_spg_target_unpack_be(const uint8_t val[1]) {
  struct fh101rf_n_spg_target r = {0};
  // DATA @ n_spg_target[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_n_spg_target(const struct fh101rf_n_spg_target *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_spg_target_try_unpack_le(const uint8_t val[1], struct fh101rf_n_spg_target *r) {
  *r = fh101rf_n_spg_target_unpack_le(val);
  return fh101rf_validate_n_spg_target(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_n_spg_target_try_unpack_be(const uint8_t val[1], struct fh101rf_n_spg_target *r) {
  *r = fh101rf_n_spg_target_unpack_be(val);
  return fh101rf_validate_n_spg_target(r);
}

// =============================================================================
// ==== RTCLG0_THRESH_0 Register ===============================================
// =============================================================================
// Bits 7:0 of the RTCLG0 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG0_THRESH_0_ADDRESS  (0x47U) //!< RTCLG0_THRESH_0 register address
#define FH101RF_RTCLG0_THRESH_0_RESET_LE {0x0U}  //!< RTCLG0_THRESH_0 register reset value
#define FH101RF_RTCLG0_THRESH_0_RESET_BE {0x0U}  //!< RTCLG0_THRESH_0 register reset value

// Register Layout Struct:

/**
 * @brief Bits 7:0 of the RTCLG0 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg0_thresh_0 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_0 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_0_pack_le(const struct fh101rf_rtclg0_thresh_0 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_0[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_0 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_0_pack_be(const struct fh101rf_rtclg0_thresh_0 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_0[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_0 fh101rf_rtclg0_thresh_0_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_0 r = {0};
  // DATA @ rtclg0_thresh_0[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_0 fh101rf_rtclg0_thresh_0_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_0 r = {0};
  // DATA @ rtclg0_thresh_0[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg0_thresh_0(const struct fh101rf_rtclg0_thresh_0 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_0_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg0_thresh_0 *r) {
  *r = fh101rf_rtclg0_thresh_0_unpack_le(val);
  return fh101rf_validate_rtclg0_thresh_0(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_0_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg0_thresh_0 *r) {
  *r = fh101rf_rtclg0_thresh_0_unpack_be(val);
  return fh101rf_validate_rtclg0_thresh_0(r);
}

// =============================================================================
// ==== RTCLG0_THRESH_1 Register ===============================================
// =============================================================================
// Bits 15:8 of the RTCLG0 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG0_THRESH_1_ADDRESS  (0x46U) //!< RTCLG0_THRESH_1 register address
#define FH101RF_RTCLG0_THRESH_1_RESET_LE {0x0U}  //!< RTCLG0_THRESH_1 register reset value
#define FH101RF_RTCLG0_THRESH_1_RESET_BE {0x0U}  //!< RTCLG0_THRESH_1 register reset value

// Register Layout Struct:

/**
 * @brief Bits 15:8 of the RTCLG0 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg0_thresh_1 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_1 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_1_pack_le(const struct fh101rf_rtclg0_thresh_1 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_1[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_1 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_1_pack_be(const struct fh101rf_rtclg0_thresh_1 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_1[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_1 fh101rf_rtclg0_thresh_1_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_1 r = {0};
  // DATA @ rtclg0_thresh_1[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_1 fh101rf_rtclg0_thresh_1_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_1 r = {0};
  // DATA @ rtclg0_thresh_1[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg0_thresh_1(const struct fh101rf_rtclg0_thresh_1 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_1_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg0_thresh_1 *r) {
  *r = fh101rf_rtclg0_thresh_1_unpack_le(val);
  return fh101rf_validate_rtclg0_thresh_1(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_1_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg0_thresh_1 *r) {
  *r = fh101rf_rtclg0_thresh_1_unpack_be(val);
  return fh101rf_validate_rtclg0_thresh_1(r);
}

// =============================================================================
// ==== RTCLG0_THRESH_2 Register ===============================================
// =============================================================================
// Bits 23:16 of the RTCLG0 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG0_THRESH_2_ADDRESS  (0x45U) //!< RTCLG0_THRESH_2 register address
#define FH101RF_RTCLG0_THRESH_2_RESET_LE {0x0U}  //!< RTCLG0_THRESH_2 register reset value
#define FH101RF_RTCLG0_THRESH_2_RESET_BE {0x0U}  //!< RTCLG0_THRESH_2 register reset value

// Register Layout Struct:

/**
 * @brief Bits 23:16 of the RTCLG0 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg0_thresh_2 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_2 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_2_pack_le(const struct fh101rf_rtclg0_thresh_2 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_2[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_2 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_2_pack_be(const struct fh101rf_rtclg0_thresh_2 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_2[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_2 fh101rf_rtclg0_thresh_2_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_2 r = {0};
  // DATA @ rtclg0_thresh_2[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_2 fh101rf_rtclg0_thresh_2_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_2 r = {0};
  // DATA @ rtclg0_thresh_2[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg0_thresh_2(const struct fh101rf_rtclg0_thresh_2 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_2_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg0_thresh_2 *r) {
  *r = fh101rf_rtclg0_thresh_2_unpack_le(val);
  return fh101rf_validate_rtclg0_thresh_2(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_2_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg0_thresh_2 *r) {
  *r = fh101rf_rtclg0_thresh_2_unpack_be(val);
  return fh101rf_validate_rtclg0_thresh_2(r);
}

// =============================================================================
// ==== RTCLG0_THRESH_3 Register ===============================================
// =============================================================================
// Bits 31:24 of the RTCLG0 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG0_THRESH_3_ADDRESS  (0x44U) //!< RTCLG0_THRESH_3 register address
#define FH101RF_RTCLG0_THRESH_3_RESET_LE {0x0U}  //!< RTCLG0_THRESH_3 register reset value
#define FH101RF_RTCLG0_THRESH_3_RESET_BE {0x0U}  //!< RTCLG0_THRESH_3 register reset value

// Register Layout Struct:

/**
 * @brief Bits 31:24 of the RTCLG0 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg0_thresh_3 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_3 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_3_pack_le(const struct fh101rf_rtclg0_thresh_3 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_3[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_3 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_3_pack_be(const struct fh101rf_rtclg0_thresh_3 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_3[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_3 fh101rf_rtclg0_thresh_3_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_3 r = {0};
  // DATA @ rtclg0_thresh_3[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_3 fh101rf_rtclg0_thresh_3_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_3 r = {0};
  // DATA @ rtclg0_thresh_3[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg0_thresh_3(const struct fh101rf_rtclg0_thresh_3 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_3_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg0_thresh_3 *r) {
  *r = fh101rf_rtclg0_thresh_3_unpack_le(val);
  return fh101rf_validate_rtclg0_thresh_3(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_3_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg0_thresh_3 *r) {
  *r = fh101rf_rtclg0_thresh_3_unpack_be(val);
  return fh101rf_validate_rtclg0_thresh_3(r);
}

// =============================================================================
// ==== RTCLG0_THRESH_4 Register ===============================================
// =============================================================================
// Bits 39:32 of the RTCLG0 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG0_THRESH_4_ADDRESS  (0x43U) //!< RTCLG0_THRESH_4 register address
#define FH101RF_RTCLG0_THRESH_4_RESET_LE {0x0U}  //!< RTCLG0_THRESH_4 register reset value
#define FH101RF_RTCLG0_THRESH_4_RESET_BE {0x0U}  //!< RTCLG0_THRESH_4 register reset value

// Register Layout Struct:

/**
 * @brief Bits 39:32 of the RTCLG0 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg0_thresh_4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_4_pack_le(const struct fh101rf_rtclg0_thresh_4 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg0_thresh_4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg0_thresh_4_pack_be(const struct fh101rf_rtclg0_thresh_4 *r, uint8_t val[1]) {
  // DATA @ rtclg0_thresh_4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_4 fh101rf_rtclg0_thresh_4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_4 r = {0};
  // DATA @ rtclg0_thresh_4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg0_thresh_4 fh101rf_rtclg0_thresh_4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg0_thresh_4 r = {0};
  // DATA @ rtclg0_thresh_4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg0_thresh_4(const struct fh101rf_rtclg0_thresh_4 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_4_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg0_thresh_4 *r) {
  *r = fh101rf_rtclg0_thresh_4_unpack_le(val);
  return fh101rf_validate_rtclg0_thresh_4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg0_thresh_4_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg0_thresh_4 *r) {
  *r = fh101rf_rtclg0_thresh_4_unpack_be(val);
  return fh101rf_validate_rtclg0_thresh_4(r);
}

// =============================================================================
// ==== RTCLG1_THRESH_0 Register ===============================================
// =============================================================================
// Bits 7:0 of the RTCLG1 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG1_THRESH_0_ADDRESS  (0x4CU) //!< RTCLG1_THRESH_0 register address
#define FH101RF_RTCLG1_THRESH_0_RESET_LE {0x0U}  //!< RTCLG1_THRESH_0 register reset value
#define FH101RF_RTCLG1_THRESH_0_RESET_BE {0x0U}  //!< RTCLG1_THRESH_0 register reset value

// Register Layout Struct:

/**
 * @brief Bits 7:0 of the RTCLG1 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg1_thresh_0 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_0 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_0_pack_le(const struct fh101rf_rtclg1_thresh_0 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_0[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_0 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_0_pack_be(const struct fh101rf_rtclg1_thresh_0 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_0[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_0 fh101rf_rtclg1_thresh_0_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_0 r = {0};
  // DATA @ rtclg1_thresh_0[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_0 fh101rf_rtclg1_thresh_0_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_0 r = {0};
  // DATA @ rtclg1_thresh_0[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg1_thresh_0(const struct fh101rf_rtclg1_thresh_0 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_0_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg1_thresh_0 *r) {
  *r = fh101rf_rtclg1_thresh_0_unpack_le(val);
  return fh101rf_validate_rtclg1_thresh_0(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_0_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg1_thresh_0 *r) {
  *r = fh101rf_rtclg1_thresh_0_unpack_be(val);
  return fh101rf_validate_rtclg1_thresh_0(r);
}

// =============================================================================
// ==== RTCLG1_THRESH_1 Register ===============================================
// =============================================================================
// Bits 15:8 of the RTCLG1 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG1_THRESH_1_ADDRESS  (0x4BU) //!< RTCLG1_THRESH_1 register address
#define FH101RF_RTCLG1_THRESH_1_RESET_LE {0x0U}  //!< RTCLG1_THRESH_1 register reset value
#define FH101RF_RTCLG1_THRESH_1_RESET_BE {0x0U}  //!< RTCLG1_THRESH_1 register reset value

// Register Layout Struct:

/**
 * @brief Bits 15:8 of the RTCLG1 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg1_thresh_1 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_1 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_1_pack_le(const struct fh101rf_rtclg1_thresh_1 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_1[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_1 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_1_pack_be(const struct fh101rf_rtclg1_thresh_1 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_1[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_1 fh101rf_rtclg1_thresh_1_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_1 r = {0};
  // DATA @ rtclg1_thresh_1[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_1 fh101rf_rtclg1_thresh_1_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_1 r = {0};
  // DATA @ rtclg1_thresh_1[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg1_thresh_1(const struct fh101rf_rtclg1_thresh_1 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_1_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg1_thresh_1 *r) {
  *r = fh101rf_rtclg1_thresh_1_unpack_le(val);
  return fh101rf_validate_rtclg1_thresh_1(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_1_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg1_thresh_1 *r) {
  *r = fh101rf_rtclg1_thresh_1_unpack_be(val);
  return fh101rf_validate_rtclg1_thresh_1(r);
}

// =============================================================================
// ==== RTCLG1_THRESH_2 Register ===============================================
// =============================================================================
// Bits 23:16 of the RTCLG1 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG1_THRESH_2_ADDRESS  (0x4AU) //!< RTCLG1_THRESH_2 register address
#define FH101RF_RTCLG1_THRESH_2_RESET_LE {0x0U}  //!< RTCLG1_THRESH_2 register reset value
#define FH101RF_RTCLG1_THRESH_2_RESET_BE {0x0U}  //!< RTCLG1_THRESH_2 register reset value

// Register Layout Struct:

/**
 * @brief Bits 23:16 of the RTCLG1 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg1_thresh_2 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_2 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_2_pack_le(const struct fh101rf_rtclg1_thresh_2 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_2[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_2 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_2_pack_be(const struct fh101rf_rtclg1_thresh_2 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_2[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_2 fh101rf_rtclg1_thresh_2_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_2 r = {0};
  // DATA @ rtclg1_thresh_2[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_2 fh101rf_rtclg1_thresh_2_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_2 r = {0};
  // DATA @ rtclg1_thresh_2[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg1_thresh_2(const struct fh101rf_rtclg1_thresh_2 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_2_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg1_thresh_2 *r) {
  *r = fh101rf_rtclg1_thresh_2_unpack_le(val);
  return fh101rf_validate_rtclg1_thresh_2(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_2_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg1_thresh_2 *r) {
  *r = fh101rf_rtclg1_thresh_2_unpack_be(val);
  return fh101rf_validate_rtclg1_thresh_2(r);
}

// =============================================================================
// ==== RTCLG1_THRESH_3 Register ===============================================
// =============================================================================
// Bits 31:24 of the RTCLG1 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG1_THRESH_3_ADDRESS  (0x49U) //!< RTCLG1_THRESH_3 register address
#define FH101RF_RTCLG1_THRESH_3_RESET_LE {0x0U}  //!< RTCLG1_THRESH_3 register reset value
#define FH101RF_RTCLG1_THRESH_3_RESET_BE {0x0U}  //!< RTCLG1_THRESH_3 register reset value

// Register Layout Struct:

/**
 * @brief Bits 31:24 of the RTCLG1 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg1_thresh_3 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_3 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_3_pack_le(const struct fh101rf_rtclg1_thresh_3 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_3[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_3 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_3_pack_be(const struct fh101rf_rtclg1_thresh_3 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_3[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_3 fh101rf_rtclg1_thresh_3_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_3 r = {0};
  // DATA @ rtclg1_thresh_3[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_3 fh101rf_rtclg1_thresh_3_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_3 r = {0};
  // DATA @ rtclg1_thresh_3[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg1_thresh_3(const struct fh101rf_rtclg1_thresh_3 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_3_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg1_thresh_3 *r) {
  *r = fh101rf_rtclg1_thresh_3_unpack_le(val);
  return fh101rf_validate_rtclg1_thresh_3(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_3_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg1_thresh_3 *r) {
  *r = fh101rf_rtclg1_thresh_3_unpack_be(val);
  return fh101rf_validate_rtclg1_thresh_3(r);
}

// =============================================================================
// ==== RTCLG1_THRESH_4 Register ===============================================
// =============================================================================
// Bits 39:32 of the RTCLG1 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCLG1_THRESH_4_ADDRESS  (0x48U) //!< RTCLG1_THRESH_4 register address
#define FH101RF_RTCLG1_THRESH_4_RESET_LE {0x0U}  //!< RTCLG1_THRESH_4 register reset value
#define FH101RF_RTCLG1_THRESH_4_RESET_BE {0x0U}  //!< RTCLG1_THRESH_4 register reset value

// Register Layout Struct:

/**
 * @brief Bits 39:32 of the RTCLG1 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtclg1_thresh_4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_4_pack_le(const struct fh101rf_rtclg1_thresh_4 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtclg1_thresh_4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtclg1_thresh_4_pack_be(const struct fh101rf_rtclg1_thresh_4 *r, uint8_t val[1]) {
  // DATA @ rtclg1_thresh_4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_4 fh101rf_rtclg1_thresh_4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_4 r = {0};
  // DATA @ rtclg1_thresh_4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtclg1_thresh_4 fh101rf_rtclg1_thresh_4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtclg1_thresh_4 r = {0};
  // DATA @ rtclg1_thresh_4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtclg1_thresh_4(const struct fh101rf_rtclg1_thresh_4 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_4_try_unpack_le(const uint8_t val[1], struct fh101rf_rtclg1_thresh_4 *r) {
  *r = fh101rf_rtclg1_thresh_4_unpack_le(val);
  return fh101rf_validate_rtclg1_thresh_4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtclg1_thresh_4_try_unpack_be(const uint8_t val[1], struct fh101rf_rtclg1_thresh_4 *r) {
  *r = fh101rf_rtclg1_thresh_4_unpack_be(val);
  return fh101rf_validate_rtclg1_thresh_4(r);
}

// =============================================================================
// ==== RTCSH0_THRESH_HI Register ==============================================
// =============================================================================
// Upper (Bits 15:8) byte of the RTCSH0 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCSH0_THRESH_HI_ADDRESS  (0x3FU) //!< RTCSH0_THRESH_HI register address
#define FH101RF_RTCSH0_THRESH_HI_RESET_LE {0x0U}  //!< RTCSH0_THRESH_HI register reset value
#define FH101RF_RTCSH0_THRESH_HI_RESET_BE {0x0U}  //!< RTCSH0_THRESH_HI register reset value

// Register Layout Struct:

/**
 * @brief Upper (Bits 15:8) byte of the RTCSH0 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtcsh0_thresh_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtcsh0_thresh_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtcsh0_thresh_hi_pack_le(const struct fh101rf_rtcsh0_thresh_hi *r, uint8_t val[1]) {
  // DATA @ rtcsh0_thresh_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtcsh0_thresh_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtcsh0_thresh_hi_pack_be(const struct fh101rf_rtcsh0_thresh_hi *r, uint8_t val[1]) {
  // DATA @ rtcsh0_thresh_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtcsh0_thresh_hi fh101rf_rtcsh0_thresh_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtcsh0_thresh_hi r = {0};
  // DATA @ rtcsh0_thresh_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtcsh0_thresh_hi fh101rf_rtcsh0_thresh_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtcsh0_thresh_hi r = {0};
  // DATA @ rtcsh0_thresh_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtcsh0_thresh_hi(const struct fh101rf_rtcsh0_thresh_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtcsh0_thresh_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_rtcsh0_thresh_hi *r) {
  *r = fh101rf_rtcsh0_thresh_hi_unpack_le(val);
  return fh101rf_validate_rtcsh0_thresh_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtcsh0_thresh_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_rtcsh0_thresh_hi *r) {
  *r = fh101rf_rtcsh0_thresh_hi_unpack_be(val);
  return fh101rf_validate_rtcsh0_thresh_hi(r);
}

// =============================================================================
// ==== RTCSH0_THRESH_LO Register ==============================================
// =============================================================================
// Lower (Bits 7:0) byte of the RTCSH0 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCSH0_THRESH_LO_ADDRESS  (0x40U) //!< RTCSH0_THRESH_LO register address
#define FH101RF_RTCSH0_THRESH_LO_RESET_LE {0x0U}  //!< RTCSH0_THRESH_LO register reset value
#define FH101RF_RTCSH0_THRESH_LO_RESET_BE {0x0U}  //!< RTCSH0_THRESH_LO register reset value

// Register Layout Struct:

/**
 * @brief Lower (Bits 7:0) byte of the RTCSH0 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtcsh0_thresh_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtcsh0_thresh_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtcsh0_thresh_lo_pack_le(const struct fh101rf_rtcsh0_thresh_lo *r, uint8_t val[1]) {
  // DATA @ rtcsh0_thresh_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtcsh0_thresh_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtcsh0_thresh_lo_pack_be(const struct fh101rf_rtcsh0_thresh_lo *r, uint8_t val[1]) {
  // DATA @ rtcsh0_thresh_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtcsh0_thresh_lo fh101rf_rtcsh0_thresh_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtcsh0_thresh_lo r = {0};
  // DATA @ rtcsh0_thresh_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtcsh0_thresh_lo fh101rf_rtcsh0_thresh_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtcsh0_thresh_lo r = {0};
  // DATA @ rtcsh0_thresh_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtcsh0_thresh_lo(const struct fh101rf_rtcsh0_thresh_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtcsh0_thresh_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_rtcsh0_thresh_lo *r) {
  *r = fh101rf_rtcsh0_thresh_lo_unpack_le(val);
  return fh101rf_validate_rtcsh0_thresh_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtcsh0_thresh_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_rtcsh0_thresh_lo *r) {
  *r = fh101rf_rtcsh0_thresh_lo_unpack_be(val);
  return fh101rf_validate_rtcsh0_thresh_lo(r);
}

// =============================================================================
// ==== RTCSH1_THRESH_HI Register ==============================================
// =============================================================================
// Upper (Bits 15:8) byte of the RTCSH1 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCSH1_THRESH_HI_ADDRESS  (0x41U) //!< RTCSH1_THRESH_HI register address
#define FH101RF_RTCSH1_THRESH_HI_RESET_LE {0x0U}  //!< RTCSH1_THRESH_HI register reset value
#define FH101RF_RTCSH1_THRESH_HI_RESET_BE {0x0U}  //!< RTCSH1_THRESH_HI register reset value

// Register Layout Struct:

/**
 * @brief Upper (Bits 15:8) byte of the RTCSH1 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtcsh1_thresh_hi {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtcsh1_thresh_hi struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtcsh1_thresh_hi_pack_le(const struct fh101rf_rtcsh1_thresh_hi *r, uint8_t val[1]) {
  // DATA @ rtcsh1_thresh_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtcsh1_thresh_hi struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtcsh1_thresh_hi_pack_be(const struct fh101rf_rtcsh1_thresh_hi *r, uint8_t val[1]) {
  // DATA @ rtcsh1_thresh_hi[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtcsh1_thresh_hi fh101rf_rtcsh1_thresh_hi_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtcsh1_thresh_hi r = {0};
  // DATA @ rtcsh1_thresh_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtcsh1_thresh_hi fh101rf_rtcsh1_thresh_hi_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtcsh1_thresh_hi r = {0};
  // DATA @ rtcsh1_thresh_hi[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtcsh1_thresh_hi(const struct fh101rf_rtcsh1_thresh_hi *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtcsh1_thresh_hi_try_unpack_le(const uint8_t val[1], struct fh101rf_rtcsh1_thresh_hi *r) {
  *r = fh101rf_rtcsh1_thresh_hi_unpack_le(val);
  return fh101rf_validate_rtcsh1_thresh_hi(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtcsh1_thresh_hi_try_unpack_be(const uint8_t val[1], struct fh101rf_rtcsh1_thresh_hi *r) {
  *r = fh101rf_rtcsh1_thresh_hi_unpack_be(val);
  return fh101rf_validate_rtcsh1_thresh_hi(r);
}

// =============================================================================
// ==== RTCSH1_THRESH_LO Register ==============================================
// =============================================================================
// Lower (Bits 7:0) byte of the RTCSH1 threshold.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RTCSH1_THRESH_LO_ADDRESS  (0x42U) //!< RTCSH1_THRESH_LO register address
#define FH101RF_RTCSH1_THRESH_LO_RESET_LE {0x0U}  //!< RTCSH1_THRESH_LO register reset value
#define FH101RF_RTCSH1_THRESH_LO_RESET_BE {0x0U}  //!< RTCSH1_THRESH_LO register reset value

// Register Layout Struct:

/**
 * @brief Lower (Bits 7:0) byte of the RTCSH1 threshold.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtcsh1_thresh_lo {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtcsh1_thresh_lo struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtcsh1_thresh_lo_pack_le(const struct fh101rf_rtcsh1_thresh_lo *r, uint8_t val[1]) {
  // DATA @ rtcsh1_thresh_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtcsh1_thresh_lo struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtcsh1_thresh_lo_pack_be(const struct fh101rf_rtcsh1_thresh_lo *r, uint8_t val[1]) {
  // DATA @ rtcsh1_thresh_lo[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtcsh1_thresh_lo fh101rf_rtcsh1_thresh_lo_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtcsh1_thresh_lo r = {0};
  // DATA @ rtcsh1_thresh_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtcsh1_thresh_lo fh101rf_rtcsh1_thresh_lo_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtcsh1_thresh_lo r = {0};
  // DATA @ rtcsh1_thresh_lo[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtcsh1_thresh_lo(const struct fh101rf_rtcsh1_thresh_lo *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtcsh1_thresh_lo_try_unpack_le(const uint8_t val[1], struct fh101rf_rtcsh1_thresh_lo *r) {
  *r = fh101rf_rtcsh1_thresh_lo_unpack_le(val);
  return fh101rf_validate_rtcsh1_thresh_lo(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtcsh1_thresh_lo_try_unpack_be(const uint8_t val[1], struct fh101rf_rtcsh1_thresh_lo *r) {
  *r = fh101rf_rtcsh1_thresh_lo_unpack_be(val);
  return fh101rf_validate_rtcsh1_thresh_lo(r);
}

// =============================================================================
// ==== RTC_CLR Register =======================================================
// =============================================================================
// Clears the respective event entries in RTC_STATUS.
// Fields:
//  - [3:0] RTC_CLR (layout RTC)
//    - [0] RTC_CLR.RTCSH0 (bool): Selects the short RTC counter
//    - [1] RTC_CLR.RTCSH1 (bool): Selects the short RTC counter
//    - [2] RTC_CLR.RTCLG0 (bool): Selects the long RTC counter
//    - [3] RTC_CLR.RTCLG1 (bool): Selects the long RTC counter

#define FH101RF_RTC_CLR_ADDRESS  (0x3EU) //!< RTC_CLR register address
#define FH101RF_RTC_CLR_RESET_LE {0x0U}  //!< RTC_CLR register reset value
#define FH101RF_RTC_CLR_RESET_BE {0x0U}  //!< RTC_CLR register reset value

// Register Layout Struct:

/**
 * @brief Clears the respective event entries in RTC_STATUS.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtc_clr {
  struct fh101rf_rtc rtc_clr;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtc_clr struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtc_clr_pack_le(const struct fh101rf_rtc_clr *r, uint8_t val[1]) {
  // RTC_CLR @ rtc_clr[3:0]:
  uint8_t rtc_clr[1] = {0};
  fh101rf_rtc_pack_le(&r->rtc_clr, rtc_clr);
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)((uint8_t)rtc_clr[0] & 0xFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtc_clr struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtc_clr_pack_be(const struct fh101rf_rtc_clr *r, uint8_t val[1]) {
  // RTC_CLR @ rtc_clr[3:0]:
  uint8_t rtc_clr[1] = {0};
  fh101rf_rtc_pack_be(&r->rtc_clr, rtc_clr);
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)((uint8_t)rtc_clr[0] & 0xFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtc_clr fh101rf_rtc_clr_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtc_clr r = {0};
  // RTC_CLR @ rtc_clr[3:0]:
  uint8_t rtc_clr[1] = {0};
  rtc_clr[0] |= (uint8_t)((val[0] & 0xFU));
  r.rtc_clr = fh101rf_rtc_unpack_le(rtc_clr);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtc_clr fh101rf_rtc_clr_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtc_clr r = {0};
  // RTC_CLR @ rtc_clr[3:0]:
  uint8_t rtc_clr[1] = {0};
  rtc_clr[0] |= (uint8_t)((val[0] & 0xFU));
  r.rtc_clr = fh101rf_rtc_unpack_be(rtc_clr);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtc_clr(const struct fh101rf_rtc_clr *r) {
  if (fh101rf_validate_rtc(&r->rtc_clr)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtc_clr_try_unpack_le(const uint8_t val[1], struct fh101rf_rtc_clr *r) {
  *r = fh101rf_rtc_clr_unpack_le(val);
  return fh101rf_validate_rtc_clr(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtc_clr_try_unpack_be(const uint8_t val[1], struct fh101rf_rtc_clr *r) {
  *r = fh101rf_rtc_clr_unpack_be(val);
  return fh101rf_validate_rtc_clr(r);
}

// =============================================================================
// ==== RTC_SELECT Register ====================================================
// =============================================================================
// Allows for selection of the desired timer modes.
// Fields:
//  - [3:0] RTC_SELECT (layout RTC)
//    - [0] RTC_SELECT.RTCSH0 (bool): Selects the short RTC counter
//    - [1] RTC_SELECT.RTCSH1 (bool): Selects the short RTC counter
//    - [2] RTC_SELECT.RTCLG0 (bool): Selects the long RTC counter
//    - [3] RTC_SELECT.RTCLG1 (bool): Selects the long RTC counter
//  - [4] CYCLTOP (bool): Selects the cyclic counter (CYCLTOP).

#define FH101RF_RTC_SELECT_ADDRESS  (0x3CU) //!< RTC_SELECT register address
#define FH101RF_RTC_SELECT_RESET_LE {0x0U}  //!< RTC_SELECT register reset value
#define FH101RF_RTC_SELECT_RESET_BE {0x0U}  //!< RTC_SELECT register reset value

// Register Layout Struct:

/**
 * @brief Allows for selection of the desired timer modes.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtc_select {
  /** @brief Selects the cyclic counter (CYCLTOP). */
  bool cycltop;
  struct fh101rf_rtc rtc_select;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtc_select struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtc_select_pack_le(const struct fh101rf_rtc_select *r, uint8_t val[1]) {
  // CYCLTOP @ rtc_select[4]:
  val[0] &= (uint8_t)~0x10U;
  val[0] |= (uint8_t)(((uint8_t)(r->cycltop << 4)) & 0x10U);
  // RTC_SELECT @ rtc_select[3:0]:
  uint8_t rtc_select[1] = {0};
  fh101rf_rtc_pack_le(&r->rtc_select, rtc_select);
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)((uint8_t)rtc_select[0] & 0xFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtc_select struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtc_select_pack_be(const struct fh101rf_rtc_select *r, uint8_t val[1]) {
  // CYCLTOP @ rtc_select[4]:
  val[0] &= (uint8_t)~0x10U;
  val[0] |= (uint8_t)(((uint8_t)(r->cycltop << 4)) & 0x10U);
  // RTC_SELECT @ rtc_select[3:0]:
  uint8_t rtc_select[1] = {0};
  fh101rf_rtc_pack_be(&r->rtc_select, rtc_select);
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)((uint8_t)rtc_select[0] & 0xFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtc_select fh101rf_rtc_select_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtc_select r = {0};
  // CYCLTOP @ rtc_select[4]:
  r.cycltop = (bool)(((val[0] & 0x10U) >> 4));
  // RTC_SELECT @ rtc_select[3:0]:
  uint8_t rtc_select[1] = {0};
  rtc_select[0] |= (uint8_t)((val[0] & 0xFU));
  r.rtc_select = fh101rf_rtc_unpack_le(rtc_select);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtc_select fh101rf_rtc_select_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtc_select r = {0};
  // CYCLTOP @ rtc_select[4]:
  r.cycltop = (bool)(((val[0] & 0x10U) >> 4));
  // RTC_SELECT @ rtc_select[3:0]:
  uint8_t rtc_select[1] = {0};
  rtc_select[0] |= (uint8_t)((val[0] & 0xFU));
  r.rtc_select = fh101rf_rtc_unpack_be(rtc_select);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtc_select(const struct fh101rf_rtc_select *r) {
  if (fh101rf_validate_rtc(&r->rtc_select)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtc_select_try_unpack_le(const uint8_t val[1], struct fh101rf_rtc_select *r) {
  *r = fh101rf_rtc_select_unpack_le(val);
  return fh101rf_validate_rtc_select(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtc_select_try_unpack_be(const uint8_t val[1], struct fh101rf_rtc_select *r) {
  *r = fh101rf_rtc_select_unpack_be(val);
  return fh101rf_validate_rtc_select(r);
}

// =============================================================================
// ==== RTC_STATUS Register ====================================================
// =============================================================================
// Indicates occurence of RTC events.
// Fields:
//  - [3:0] RTC_SELECT (layout RTC)
//    - [0] RTC_SELECT.RTCSH0 (bool): Selects the short RTC counter
//    - [1] RTC_SELECT.RTCSH1 (bool): Selects the short RTC counter
//    - [2] RTC_SELECT.RTCLG0 (bool): Selects the long RTC counter
//    - [3] RTC_SELECT.RTCLG1 (bool): Selects the long RTC counter

#define FH101RF_RTC_STATUS_ADDRESS  (0x3DU) //!< RTC_STATUS register address
#define FH101RF_RTC_STATUS_RESET_LE {0x0U}  //!< RTC_STATUS register reset value
#define FH101RF_RTC_STATUS_RESET_BE {0x0U}  //!< RTC_STATUS register reset value

// Register Layout Struct:

/**
 * @brief Indicates occurence of RTC events.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rtc_status {
  struct fh101rf_rtc rtc_select;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rtc_status struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtc_status_pack_le(const struct fh101rf_rtc_status *r, uint8_t val[1]) {
  // RTC_SELECT @ rtc_status[3:0]:
  uint8_t rtc_select[1] = {0};
  fh101rf_rtc_pack_le(&r->rtc_select, rtc_select);
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)((uint8_t)rtc_select[0] & 0xFU);
}

/**
 * @brief Convert @ref struct fh101rf_rtc_status struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rtc_status_pack_be(const struct fh101rf_rtc_status *r, uint8_t val[1]) {
  // RTC_SELECT @ rtc_status[3:0]:
  uint8_t rtc_select[1] = {0};
  fh101rf_rtc_pack_be(&r->rtc_select, rtc_select);
  val[0] &= (uint8_t)~0xFU;
  val[0] |= (uint8_t)((uint8_t)rtc_select[0] & 0xFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtc_status fh101rf_rtc_status_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rtc_status r = {0};
  // RTC_SELECT @ rtc_status[3:0]:
  uint8_t rtc_select[1] = {0};
  rtc_select[0] |= (uint8_t)((val[0] & 0xFU));
  r.rtc_select = fh101rf_rtc_unpack_le(rtc_select);
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rtc_status fh101rf_rtc_status_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rtc_status r = {0};
  // RTC_SELECT @ rtc_status[3:0]:
  uint8_t rtc_select[1] = {0};
  rtc_select[0] |= (uint8_t)((val[0] & 0xFU));
  r.rtc_select = fh101rf_rtc_unpack_be(rtc_select);
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rtc_status(const struct fh101rf_rtc_status *r) {
  if (fh101rf_validate_rtc(&r->rtc_select)) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtc_status_try_unpack_le(const uint8_t val[1], struct fh101rf_rtc_status *r) {
  *r = fh101rf_rtc_status_unpack_le(val);
  return fh101rf_validate_rtc_status(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rtc_status_try_unpack_be(const uint8_t val[1], struct fh101rf_rtc_status *r) {
  *r = fh101rf_rtc_status_unpack_be(val);
  return fh101rf_validate_rtc_status(r);
}

// =============================================================================
// ==== RX_FIFO_0_2G4 Register =================================================
// =============================================================================
// The FIFO byte 0 for the 2.4GHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_0_2G4_ADDRESS  (0x6BU) //!< RX_FIFO_0_2G4 register address
#define FH101RF_RX_FIFO_0_2G4_RESET_LE {0x0U}  //!< RX_FIFO_0_2G4 register reset value
#define FH101RF_RX_FIFO_0_2G4_RESET_BE {0x0U}  //!< RX_FIFO_0_2G4 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 0 for the 2.4GHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_0_2g4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_0_2g4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_0_2g4_pack_le(const struct fh101rf_rx_fifo_0_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_0_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_0_2g4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_0_2g4_pack_be(const struct fh101rf_rx_fifo_0_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_0_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_0_2g4 fh101rf_rx_fifo_0_2g4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_0_2g4 r = {0};
  // DATA @ rx_fifo_0_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_0_2g4 fh101rf_rx_fifo_0_2g4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_0_2g4 r = {0};
  // DATA @ rx_fifo_0_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_0_2g4(const struct fh101rf_rx_fifo_0_2g4 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_0_2g4_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_0_2g4 *r) {
  *r = fh101rf_rx_fifo_0_2g4_unpack_le(val);
  return fh101rf_validate_rx_fifo_0_2g4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_0_2g4_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_0_2g4 *r) {
  *r = fh101rf_rx_fifo_0_2g4_unpack_be(val);
  return fh101rf_validate_rx_fifo_0_2g4(r);
}

// =============================================================================
// ==== RX_FIFO_0_433 Register =================================================
// =============================================================================
// The FIFO byte 0 for the 433MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_0_433_ADDRESS  (0x5FU) //!< RX_FIFO_0_433 register address
#define FH101RF_RX_FIFO_0_433_RESET_LE {0x0U}  //!< RX_FIFO_0_433 register reset value
#define FH101RF_RX_FIFO_0_433_RESET_BE {0x0U}  //!< RX_FIFO_0_433 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 0 for the 433MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_0_433 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_0_433 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_0_433_pack_le(const struct fh101rf_rx_fifo_0_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_0_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_0_433 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_0_433_pack_be(const struct fh101rf_rx_fifo_0_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_0_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_0_433 fh101rf_rx_fifo_0_433_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_0_433 r = {0};
  // DATA @ rx_fifo_0_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_0_433 fh101rf_rx_fifo_0_433_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_0_433 r = {0};
  // DATA @ rx_fifo_0_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_0_433(const struct fh101rf_rx_fifo_0_433 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_0_433_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_0_433 *r) {
  *r = fh101rf_rx_fifo_0_433_unpack_le(val);
  return fh101rf_validate_rx_fifo_0_433(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_0_433_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_0_433 *r) {
  *r = fh101rf_rx_fifo_0_433_unpack_be(val);
  return fh101rf_validate_rx_fifo_0_433(r);
}

// =============================================================================
// ==== RX_FIFO_0_868 Register =================================================
// =============================================================================
// The FIFO byte 0 for the 868MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_0_868_ADDRESS  (0x65U) //!< RX_FIFO_0_868 register address
#define FH101RF_RX_FIFO_0_868_RESET_LE {0x0U}  //!< RX_FIFO_0_868 register reset value
#define FH101RF_RX_FIFO_0_868_RESET_BE {0x0U}  //!< RX_FIFO_0_868 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 0 for the 868MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_0_868 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_0_868 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_0_868_pack_le(const struct fh101rf_rx_fifo_0_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_0_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_0_868 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_0_868_pack_be(const struct fh101rf_rx_fifo_0_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_0_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_0_868 fh101rf_rx_fifo_0_868_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_0_868 r = {0};
  // DATA @ rx_fifo_0_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_0_868 fh101rf_rx_fifo_0_868_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_0_868 r = {0};
  // DATA @ rx_fifo_0_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_0_868(const struct fh101rf_rx_fifo_0_868 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_0_868_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_0_868 *r) {
  *r = fh101rf_rx_fifo_0_868_unpack_le(val);
  return fh101rf_validate_rx_fifo_0_868(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_0_868_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_0_868 *r) {
  *r = fh101rf_rx_fifo_0_868_unpack_be(val);
  return fh101rf_validate_rx_fifo_0_868(r);
}

// =============================================================================
// ==== RX_FIFO_1_2G4 Register =================================================
// =============================================================================
// The FIFO byte 1 for the 2.4GHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_1_2G4_ADDRESS  (0x6AU) //!< RX_FIFO_1_2G4 register address
#define FH101RF_RX_FIFO_1_2G4_RESET_LE {0x0U}  //!< RX_FIFO_1_2G4 register reset value
#define FH101RF_RX_FIFO_1_2G4_RESET_BE {0x0U}  //!< RX_FIFO_1_2G4 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 1 for the 2.4GHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_1_2g4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_1_2g4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_1_2g4_pack_le(const struct fh101rf_rx_fifo_1_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_1_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_1_2g4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_1_2g4_pack_be(const struct fh101rf_rx_fifo_1_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_1_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_1_2g4 fh101rf_rx_fifo_1_2g4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_1_2g4 r = {0};
  // DATA @ rx_fifo_1_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_1_2g4 fh101rf_rx_fifo_1_2g4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_1_2g4 r = {0};
  // DATA @ rx_fifo_1_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_1_2g4(const struct fh101rf_rx_fifo_1_2g4 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_1_2g4_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_1_2g4 *r) {
  *r = fh101rf_rx_fifo_1_2g4_unpack_le(val);
  return fh101rf_validate_rx_fifo_1_2g4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_1_2g4_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_1_2g4 *r) {
  *r = fh101rf_rx_fifo_1_2g4_unpack_be(val);
  return fh101rf_validate_rx_fifo_1_2g4(r);
}

// =============================================================================
// ==== RX_FIFO_1_433 Register =================================================
// =============================================================================
// The FIFO byte 1 for the 433MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_1_433_ADDRESS  (0x5EU) //!< RX_FIFO_1_433 register address
#define FH101RF_RX_FIFO_1_433_RESET_LE {0x0U}  //!< RX_FIFO_1_433 register reset value
#define FH101RF_RX_FIFO_1_433_RESET_BE {0x0U}  //!< RX_FIFO_1_433 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 1 for the 433MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_1_433 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_1_433 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_1_433_pack_le(const struct fh101rf_rx_fifo_1_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_1_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_1_433 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_1_433_pack_be(const struct fh101rf_rx_fifo_1_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_1_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_1_433 fh101rf_rx_fifo_1_433_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_1_433 r = {0};
  // DATA @ rx_fifo_1_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_1_433 fh101rf_rx_fifo_1_433_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_1_433 r = {0};
  // DATA @ rx_fifo_1_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_1_433(const struct fh101rf_rx_fifo_1_433 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_1_433_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_1_433 *r) {
  *r = fh101rf_rx_fifo_1_433_unpack_le(val);
  return fh101rf_validate_rx_fifo_1_433(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_1_433_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_1_433 *r) {
  *r = fh101rf_rx_fifo_1_433_unpack_be(val);
  return fh101rf_validate_rx_fifo_1_433(r);
}

// =============================================================================
// ==== RX_FIFO_1_868 Register =================================================
// =============================================================================
// The FIFO byte 1 for the 868MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_1_868_ADDRESS  (0x64U) //!< RX_FIFO_1_868 register address
#define FH101RF_RX_FIFO_1_868_RESET_LE {0x0U}  //!< RX_FIFO_1_868 register reset value
#define FH101RF_RX_FIFO_1_868_RESET_BE {0x0U}  //!< RX_FIFO_1_868 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 1 for the 868MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_1_868 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_1_868 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_1_868_pack_le(const struct fh101rf_rx_fifo_1_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_1_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_1_868 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_1_868_pack_be(const struct fh101rf_rx_fifo_1_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_1_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_1_868 fh101rf_rx_fifo_1_868_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_1_868 r = {0};
  // DATA @ rx_fifo_1_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_1_868 fh101rf_rx_fifo_1_868_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_1_868 r = {0};
  // DATA @ rx_fifo_1_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_1_868(const struct fh101rf_rx_fifo_1_868 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_1_868_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_1_868 *r) {
  *r = fh101rf_rx_fifo_1_868_unpack_le(val);
  return fh101rf_validate_rx_fifo_1_868(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_1_868_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_1_868 *r) {
  *r = fh101rf_rx_fifo_1_868_unpack_be(val);
  return fh101rf_validate_rx_fifo_1_868(r);
}

// =============================================================================
// ==== RX_FIFO_2_2G4 Register =================================================
// =============================================================================
// The FIFO byte 2 for the 2.4GHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_2_2G4_ADDRESS  (0x69U) //!< RX_FIFO_2_2G4 register address
#define FH101RF_RX_FIFO_2_2G4_RESET_LE {0x0U}  //!< RX_FIFO_2_2G4 register reset value
#define FH101RF_RX_FIFO_2_2G4_RESET_BE {0x0U}  //!< RX_FIFO_2_2G4 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 2 for the 2.4GHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_2_2g4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_2_2g4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_2_2g4_pack_le(const struct fh101rf_rx_fifo_2_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_2_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_2_2g4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_2_2g4_pack_be(const struct fh101rf_rx_fifo_2_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_2_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_2_2g4 fh101rf_rx_fifo_2_2g4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_2_2g4 r = {0};
  // DATA @ rx_fifo_2_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_2_2g4 fh101rf_rx_fifo_2_2g4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_2_2g4 r = {0};
  // DATA @ rx_fifo_2_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_2_2g4(const struct fh101rf_rx_fifo_2_2g4 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_2_2g4_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_2_2g4 *r) {
  *r = fh101rf_rx_fifo_2_2g4_unpack_le(val);
  return fh101rf_validate_rx_fifo_2_2g4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_2_2g4_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_2_2g4 *r) {
  *r = fh101rf_rx_fifo_2_2g4_unpack_be(val);
  return fh101rf_validate_rx_fifo_2_2g4(r);
}

// =============================================================================
// ==== RX_FIFO_2_433 Register =================================================
// =============================================================================
// The FIFO byte 2 for the 433MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_2_433_ADDRESS  (0x5DU) //!< RX_FIFO_2_433 register address
#define FH101RF_RX_FIFO_2_433_RESET_LE {0x0U}  //!< RX_FIFO_2_433 register reset value
#define FH101RF_RX_FIFO_2_433_RESET_BE {0x0U}  //!< RX_FIFO_2_433 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 2 for the 433MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_2_433 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_2_433 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_2_433_pack_le(const struct fh101rf_rx_fifo_2_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_2_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_2_433 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_2_433_pack_be(const struct fh101rf_rx_fifo_2_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_2_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_2_433 fh101rf_rx_fifo_2_433_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_2_433 r = {0};
  // DATA @ rx_fifo_2_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_2_433 fh101rf_rx_fifo_2_433_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_2_433 r = {0};
  // DATA @ rx_fifo_2_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_2_433(const struct fh101rf_rx_fifo_2_433 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_2_433_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_2_433 *r) {
  *r = fh101rf_rx_fifo_2_433_unpack_le(val);
  return fh101rf_validate_rx_fifo_2_433(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_2_433_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_2_433 *r) {
  *r = fh101rf_rx_fifo_2_433_unpack_be(val);
  return fh101rf_validate_rx_fifo_2_433(r);
}

// =============================================================================
// ==== RX_FIFO_2_868 Register =================================================
// =============================================================================
// The FIFO byte 2 for the 868MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_2_868_ADDRESS  (0x63U) //!< RX_FIFO_2_868 register address
#define FH101RF_RX_FIFO_2_868_RESET_LE {0x0U}  //!< RX_FIFO_2_868 register reset value
#define FH101RF_RX_FIFO_2_868_RESET_BE {0x0U}  //!< RX_FIFO_2_868 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 2 for the 868MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_2_868 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_2_868 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_2_868_pack_le(const struct fh101rf_rx_fifo_2_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_2_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_2_868 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_2_868_pack_be(const struct fh101rf_rx_fifo_2_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_2_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_2_868 fh101rf_rx_fifo_2_868_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_2_868 r = {0};
  // DATA @ rx_fifo_2_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_2_868 fh101rf_rx_fifo_2_868_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_2_868 r = {0};
  // DATA @ rx_fifo_2_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_2_868(const struct fh101rf_rx_fifo_2_868 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_2_868_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_2_868 *r) {
  *r = fh101rf_rx_fifo_2_868_unpack_le(val);
  return fh101rf_validate_rx_fifo_2_868(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_2_868_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_2_868 *r) {
  *r = fh101rf_rx_fifo_2_868_unpack_be(val);
  return fh101rf_validate_rx_fifo_2_868(r);
}

// =============================================================================
// ==== RX_FIFO_3_2G4 Register =================================================
// =============================================================================
// The FIFO byte 3 for the 2.4GHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_3_2G4_ADDRESS  (0x68U) //!< RX_FIFO_3_2G4 register address
#define FH101RF_RX_FIFO_3_2G4_RESET_LE {0x0U}  //!< RX_FIFO_3_2G4 register reset value
#define FH101RF_RX_FIFO_3_2G4_RESET_BE {0x0U}  //!< RX_FIFO_3_2G4 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 3 for the 2.4GHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_3_2g4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_3_2g4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_3_2g4_pack_le(const struct fh101rf_rx_fifo_3_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_3_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_3_2g4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_3_2g4_pack_be(const struct fh101rf_rx_fifo_3_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_3_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_3_2g4 fh101rf_rx_fifo_3_2g4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_3_2g4 r = {0};
  // DATA @ rx_fifo_3_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_3_2g4 fh101rf_rx_fifo_3_2g4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_3_2g4 r = {0};
  // DATA @ rx_fifo_3_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_3_2g4(const struct fh101rf_rx_fifo_3_2g4 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_3_2g4_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_3_2g4 *r) {
  *r = fh101rf_rx_fifo_3_2g4_unpack_le(val);
  return fh101rf_validate_rx_fifo_3_2g4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_3_2g4_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_3_2g4 *r) {
  *r = fh101rf_rx_fifo_3_2g4_unpack_be(val);
  return fh101rf_validate_rx_fifo_3_2g4(r);
}

// =============================================================================
// ==== RX_FIFO_3_433 Register =================================================
// =============================================================================
// The FIFO byte 3 for the 433MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_3_433_ADDRESS  (0x5CU) //!< RX_FIFO_3_433 register address
#define FH101RF_RX_FIFO_3_433_RESET_LE {0x0U}  //!< RX_FIFO_3_433 register reset value
#define FH101RF_RX_FIFO_3_433_RESET_BE {0x0U}  //!< RX_FIFO_3_433 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 3 for the 433MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_3_433 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_3_433 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_3_433_pack_le(const struct fh101rf_rx_fifo_3_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_3_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_3_433 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_3_433_pack_be(const struct fh101rf_rx_fifo_3_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_3_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_3_433 fh101rf_rx_fifo_3_433_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_3_433 r = {0};
  // DATA @ rx_fifo_3_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_3_433 fh101rf_rx_fifo_3_433_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_3_433 r = {0};
  // DATA @ rx_fifo_3_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_3_433(const struct fh101rf_rx_fifo_3_433 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_3_433_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_3_433 *r) {
  *r = fh101rf_rx_fifo_3_433_unpack_le(val);
  return fh101rf_validate_rx_fifo_3_433(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_3_433_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_3_433 *r) {
  *r = fh101rf_rx_fifo_3_433_unpack_be(val);
  return fh101rf_validate_rx_fifo_3_433(r);
}

// =============================================================================
// ==== RX_FIFO_3_868 Register =================================================
// =============================================================================
// The FIFO byte 3 for the 868MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_3_868_ADDRESS  (0x62U) //!< RX_FIFO_3_868 register address
#define FH101RF_RX_FIFO_3_868_RESET_LE {0x0U}  //!< RX_FIFO_3_868 register reset value
#define FH101RF_RX_FIFO_3_868_RESET_BE {0x0U}  //!< RX_FIFO_3_868 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 3 for the 868MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_3_868 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_3_868 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_3_868_pack_le(const struct fh101rf_rx_fifo_3_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_3_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_3_868 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_3_868_pack_be(const struct fh101rf_rx_fifo_3_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_3_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_3_868 fh101rf_rx_fifo_3_868_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_3_868 r = {0};
  // DATA @ rx_fifo_3_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_3_868 fh101rf_rx_fifo_3_868_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_3_868 r = {0};
  // DATA @ rx_fifo_3_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_3_868(const struct fh101rf_rx_fifo_3_868 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_3_868_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_3_868 *r) {
  *r = fh101rf_rx_fifo_3_868_unpack_le(val);
  return fh101rf_validate_rx_fifo_3_868(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_3_868_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_3_868 *r) {
  *r = fh101rf_rx_fifo_3_868_unpack_be(val);
  return fh101rf_validate_rx_fifo_3_868(r);
}

// =============================================================================
// ==== RX_FIFO_4_2G4 Register =================================================
// =============================================================================
// The FIFO byte 4 for the 2.4GHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_4_2G4_ADDRESS  (0x67U) //!< RX_FIFO_4_2G4 register address
#define FH101RF_RX_FIFO_4_2G4_RESET_LE {0x0U}  //!< RX_FIFO_4_2G4 register reset value
#define FH101RF_RX_FIFO_4_2G4_RESET_BE {0x0U}  //!< RX_FIFO_4_2G4 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 4 for the 2.4GHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_4_2g4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_4_2g4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_4_2g4_pack_le(const struct fh101rf_rx_fifo_4_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_4_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_4_2g4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_4_2g4_pack_be(const struct fh101rf_rx_fifo_4_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_4_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_4_2g4 fh101rf_rx_fifo_4_2g4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_4_2g4 r = {0};
  // DATA @ rx_fifo_4_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_4_2g4 fh101rf_rx_fifo_4_2g4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_4_2g4 r = {0};
  // DATA @ rx_fifo_4_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_4_2g4(const struct fh101rf_rx_fifo_4_2g4 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_4_2g4_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_4_2g4 *r) {
  *r = fh101rf_rx_fifo_4_2g4_unpack_le(val);
  return fh101rf_validate_rx_fifo_4_2g4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_4_2g4_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_4_2g4 *r) {
  *r = fh101rf_rx_fifo_4_2g4_unpack_be(val);
  return fh101rf_validate_rx_fifo_4_2g4(r);
}

// =============================================================================
// ==== RX_FIFO_4_433 Register =================================================
// =============================================================================
// The FIFO byte 4 for the 433MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_4_433_ADDRESS  (0x5BU) //!< RX_FIFO_4_433 register address
#define FH101RF_RX_FIFO_4_433_RESET_LE {0x0U}  //!< RX_FIFO_4_433 register reset value
#define FH101RF_RX_FIFO_4_433_RESET_BE {0x0U}  //!< RX_FIFO_4_433 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 4 for the 433MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_4_433 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_4_433 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_4_433_pack_le(const struct fh101rf_rx_fifo_4_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_4_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_4_433 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_4_433_pack_be(const struct fh101rf_rx_fifo_4_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_4_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_4_433 fh101rf_rx_fifo_4_433_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_4_433 r = {0};
  // DATA @ rx_fifo_4_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_4_433 fh101rf_rx_fifo_4_433_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_4_433 r = {0};
  // DATA @ rx_fifo_4_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_4_433(const struct fh101rf_rx_fifo_4_433 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_4_433_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_4_433 *r) {
  *r = fh101rf_rx_fifo_4_433_unpack_le(val);
  return fh101rf_validate_rx_fifo_4_433(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_4_433_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_4_433 *r) {
  *r = fh101rf_rx_fifo_4_433_unpack_be(val);
  return fh101rf_validate_rx_fifo_4_433(r);
}

// =============================================================================
// ==== RX_FIFO_4_868 Register =================================================
// =============================================================================
// The FIFO byte 4 for the 868MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_4_868_ADDRESS  (0x61U) //!< RX_FIFO_4_868 register address
#define FH101RF_RX_FIFO_4_868_RESET_LE {0x0U}  //!< RX_FIFO_4_868 register reset value
#define FH101RF_RX_FIFO_4_868_RESET_BE {0x0U}  //!< RX_FIFO_4_868 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 4 for the 868MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_4_868 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_4_868 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_4_868_pack_le(const struct fh101rf_rx_fifo_4_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_4_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_4_868 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_4_868_pack_be(const struct fh101rf_rx_fifo_4_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_4_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_4_868 fh101rf_rx_fifo_4_868_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_4_868 r = {0};
  // DATA @ rx_fifo_4_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_4_868 fh101rf_rx_fifo_4_868_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_4_868 r = {0};
  // DATA @ rx_fifo_4_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_4_868(const struct fh101rf_rx_fifo_4_868 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_4_868_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_4_868 *r) {
  *r = fh101rf_rx_fifo_4_868_unpack_le(val);
  return fh101rf_validate_rx_fifo_4_868(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_4_868_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_4_868 *r) {
  *r = fh101rf_rx_fifo_4_868_unpack_be(val);
  return fh101rf_validate_rx_fifo_4_868(r);
}

// =============================================================================
// ==== RX_FIFO_5_2G4 Register =================================================
// =============================================================================
// The FIFO byte 5 for the 2.4GHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_5_2G4_ADDRESS  (0x66U) //!< RX_FIFO_5_2G4 register address
#define FH101RF_RX_FIFO_5_2G4_RESET_LE {0x0U}  //!< RX_FIFO_5_2G4 register reset value
#define FH101RF_RX_FIFO_5_2G4_RESET_BE {0x0U}  //!< RX_FIFO_5_2G4 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 5 for the 2.4GHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_5_2g4 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_5_2g4 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_5_2g4_pack_le(const struct fh101rf_rx_fifo_5_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_5_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_5_2g4 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_5_2g4_pack_be(const struct fh101rf_rx_fifo_5_2g4 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_5_2g4[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_5_2g4 fh101rf_rx_fifo_5_2g4_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_5_2g4 r = {0};
  // DATA @ rx_fifo_5_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_5_2g4 fh101rf_rx_fifo_5_2g4_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_5_2g4 r = {0};
  // DATA @ rx_fifo_5_2g4[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_5_2g4(const struct fh101rf_rx_fifo_5_2g4 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_5_2g4_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_5_2g4 *r) {
  *r = fh101rf_rx_fifo_5_2g4_unpack_le(val);
  return fh101rf_validate_rx_fifo_5_2g4(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_5_2g4_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_5_2g4 *r) {
  *r = fh101rf_rx_fifo_5_2g4_unpack_be(val);
  return fh101rf_validate_rx_fifo_5_2g4(r);
}

// =============================================================================
// ==== RX_FIFO_5_433 Register =================================================
// =============================================================================
// The FIFO byte 5 for the 433MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_5_433_ADDRESS  (0x5AU) //!< RX_FIFO_5_433 register address
#define FH101RF_RX_FIFO_5_433_RESET_LE {0x0U}  //!< RX_FIFO_5_433 register reset value
#define FH101RF_RX_FIFO_5_433_RESET_BE {0x0U}  //!< RX_FIFO_5_433 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 5 for the 433MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_5_433 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_5_433 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_5_433_pack_le(const struct fh101rf_rx_fifo_5_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_5_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_5_433 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_5_433_pack_be(const struct fh101rf_rx_fifo_5_433 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_5_433[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_5_433 fh101rf_rx_fifo_5_433_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_5_433 r = {0};
  // DATA @ rx_fifo_5_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_5_433 fh101rf_rx_fifo_5_433_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_5_433 r = {0};
  // DATA @ rx_fifo_5_433[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_5_433(const struct fh101rf_rx_fifo_5_433 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_5_433_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_5_433 *r) {
  *r = fh101rf_rx_fifo_5_433_unpack_le(val);
  return fh101rf_validate_rx_fifo_5_433(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_5_433_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_5_433 *r) {
  *r = fh101rf_rx_fifo_5_433_unpack_be(val);
  return fh101rf_validate_rx_fifo_5_433(r);
}

// =============================================================================
// ==== RX_FIFO_5_868 Register =================================================
// =============================================================================
// The FIFO byte 5 for the 868MHz band, _5 is filled first.
// Fields:
//  - [7:0] DATA (uint)

#define FH101RF_RX_FIFO_5_868_ADDRESS  (0x60U) //!< RX_FIFO_5_868 register address
#define FH101RF_RX_FIFO_5_868_RESET_LE {0x0U}  //!< RX_FIFO_5_868 register reset value
#define FH101RF_RX_FIFO_5_868_RESET_BE {0x0U}  //!< RX_FIFO_5_868 register reset value

// Register Layout Struct:

/**
 * @brief The FIFO byte 5 for the 868MHz band, _5 is filled first.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_rx_fifo_5_868 {
  uint8_t data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_5_868 struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_5_868_pack_le(const struct fh101rf_rx_fifo_5_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_5_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/**
 * @brief Convert @ref struct fh101rf_rx_fifo_5_868 struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_rx_fifo_5_868_pack_be(const struct fh101rf_rx_fifo_5_868 *r, uint8_t val[1]) {
  // DATA @ rx_fifo_5_868[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0xFFU);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_5_868 fh101rf_rx_fifo_5_868_unpack_le(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_5_868 r = {0};
  // DATA @ rx_fifo_5_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_rx_fifo_5_868 fh101rf_rx_fifo_5_868_unpack_be(const uint8_t val[1]) {
  struct fh101rf_rx_fifo_5_868 r = {0};
  // DATA @ rx_fifo_5_868[7:0]:
  r.data = (uint8_t)((val[0] & 0xFFU));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_rx_fifo_5_868(const struct fh101rf_rx_fifo_5_868 *r) {
  if ((r->data & ~(uint8_t)0xFF) != 0) return 1;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_5_868_try_unpack_le(const uint8_t val[1], struct fh101rf_rx_fifo_5_868 *r) {
  *r = fh101rf_rx_fifo_5_868_unpack_le(val);
  return fh101rf_validate_rx_fifo_5_868(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_rx_fifo_5_868_try_unpack_be(const uint8_t val[1], struct fh101rf_rx_fifo_5_868 *r) {
  *r = fh101rf_rx_fifo_5_868_unpack_be(val);
  return fh101rf_validate_rx_fifo_5_868(r);
}

// =============================================================================
// ==== VERSION Register =======================================================
// =============================================================================
// Holds the version number of the IC, currently 0x41.
// Fields:
//  - [7:0] VERSION_NUMBER (fixed: 0x41)

#define FH101RF_VERSION_ADDRESS  (0x7FU) //!< VERSION register address
#define FH101RF_VERSION_RESET_LE {0x41U} //!< VERSION register reset value
#define FH101RF_VERSION_RESET_BE {0x41U} //!< VERSION register reset value

// Register Layout Struct:

/**
 * @brief Holds the version number of the IC, currently 0x41.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_version {
  int dummy; // Register contains no variable fields.
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_version struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_version_pack_le(const struct fh101rf_version *r, uint8_t val[1]) {
  // VERSION_NUMBER @ version[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)0x41; // Fixed value.
  (void)r;
}

/**
 * @brief Convert @ref struct fh101rf_version struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_version_pack_be(const struct fh101rf_version *r, uint8_t val[1]) {
  // VERSION_NUMBER @ version[7:0]:
  val[0] &= (uint8_t)~0xFFU;
  val[0] |= (uint8_t)0x41; // Fixed value.
  (void)r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_version fh101rf_version_unpack_le(const uint8_t val[1]) {
  struct fh101rf_version r = {0};
  (void)val;
  (void)r;
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_version fh101rf_version_unpack_be(const uint8_t val[1]) {
  struct fh101rf_version r = {0};
  (void)val;
  (void)r;
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_version(const struct fh101rf_version *r) {
  (void)r;
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_version_try_unpack_le(const uint8_t val[1], struct fh101rf_version *r) {
  *r = fh101rf_version_unpack_le(val);
  return fh101rf_validate_version(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_version_try_unpack_be(const uint8_t val[1], struct fh101rf_version *r) {
  *r = fh101rf_version_unpack_be(val);
  return fh101rf_validate_version(r);
}

// =============================================================================
// ==== XTAL_GOOD Register =====================================================
// =============================================================================
// Reads as true if the clock source is stable.
// Fields:
//  - [0] DATA (bool)

#define FH101RF_XTAL_GOOD_ADDRESS  (0x77U) //!< XTAL_GOOD register address
#define FH101RF_XTAL_GOOD_RESET_LE {0x0U}  //!< XTAL_GOOD register reset value
#define FH101RF_XTAL_GOOD_RESET_BE {0x0U}  //!< XTAL_GOOD register reset value

// Register Layout Struct:

/**
 * @brief Reads as true if the clock source is stable.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_xtal_good {
  bool data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_xtal_good struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_xtal_good_pack_le(const struct fh101rf_xtal_good *r, uint8_t val[1]) {
  // DATA @ xtal_good[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1U);
}

/**
 * @brief Convert @ref struct fh101rf_xtal_good struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_xtal_good_pack_be(const struct fh101rf_xtal_good *r, uint8_t val[1]) {
  // DATA @ xtal_good[0]:
  val[0] &= (uint8_t)~0x1U;
  val[0] |= (uint8_t)(((uint8_t)r->data) & 0x1U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_xtal_good fh101rf_xtal_good_unpack_le(const uint8_t val[1]) {
  struct fh101rf_xtal_good r = {0};
  // DATA @ xtal_good[0]:
  r.data = (bool)((val[0] & 0x1U));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_xtal_good fh101rf_xtal_good_unpack_be(const uint8_t val[1]) {
  struct fh101rf_xtal_good r = {0};
  // DATA @ xtal_good[0]:
  r.data = (bool)((val[0] & 0x1U));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_xtal_good(const struct fh101rf_xtal_good *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_xtal_good_try_unpack_le(const uint8_t val[1], struct fh101rf_xtal_good *r) {
  *r = fh101rf_xtal_good_unpack_le(val);
  return fh101rf_validate_xtal_good(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_xtal_good_try_unpack_be(const uint8_t val[1], struct fh101rf_xtal_good *r) {
  *r = fh101rf_xtal_good_unpack_be(val);
  return fh101rf_validate_xtal_good(r);
}

// =============================================================================
// ==== XTAL_OSC_CTRL Register =================================================
// =============================================================================
// Enables the built-in crystal oscillator driving a 2-pin crystal device.
// Fields:
//  - [1] DATA (bool)

#define FH101RF_XTAL_OSC_CTRL_ADDRESS  (0x73U) //!< XTAL_OSC_CTRL register address
#define FH101RF_XTAL_OSC_CTRL_RESET_LE {0x1U}  //!< XTAL_OSC_CTRL register reset value
#define FH101RF_XTAL_OSC_CTRL_RESET_BE {0x1U}  //!< XTAL_OSC_CTRL register reset value

// Register Layout Struct:

/**
 * @brief Enables the built-in crystal oscillator driving a 2-pin crystal device.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
struct fh101rf_xtal_osc_ctrl {
  bool data;
};

// Layout struct conversion functions:

/**
 * @brief Convert @ref struct fh101rf_xtal_osc_ctrl struct to packed little-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_xtal_osc_ctrl_pack_le(const struct fh101rf_xtal_osc_ctrl *r, uint8_t val[1]) {
  // DATA @ xtal_osc_ctrl[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->data << 1)) & 0x2U);
}

/**
 * @brief Convert @ref struct fh101rf_xtal_osc_ctrl struct to packed big-endian value.
 * @note use pack/unpack functions for conversion to/from packed binary value
 */
static inline void fh101rf_xtal_osc_ctrl_pack_be(const struct fh101rf_xtal_osc_ctrl *r, uint8_t val[1]) {
  // DATA @ xtal_osc_ctrl[1]:
  val[0] &= (uint8_t)~0x2U;
  val[0] |= (uint8_t)(((uint8_t)(r->data << 1)) & 0x2U);
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_xtal_osc_ctrl fh101rf_xtal_osc_ctrl_unpack_le(const uint8_t val[1]) {
  struct fh101rf_xtal_osc_ctrl r = {0};
  // DATA @ xtal_osc_ctrl[1]:
  r.data = (bool)(((val[0] & 0x2U) >> 1));
  return r;
}

/** @brief Convert packed {endian} binary value to struct. */
static inline struct fh101rf_xtal_osc_ctrl fh101rf_xtal_osc_ctrl_unpack_be(const uint8_t val[1]) {
  struct fh101rf_xtal_osc_ctrl r = {0};
  // DATA @ xtal_osc_ctrl[1]:
  r.data = (bool)(((val[0] & 0x2U) >> 1));
  return r;
}

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
static inline int fh101rf_validate_xtal_osc_ctrl(const struct fh101rf_xtal_osc_ctrl *r) {
  return 0;
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_xtal_osc_ctrl_try_unpack_le(const uint8_t val[1], struct fh101rf_xtal_osc_ctrl *r) {
  *r = fh101rf_xtal_osc_ctrl_unpack_le(val);
  return fh101rf_validate_xtal_osc_ctrl(r);
}

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
static inline int fh101rf_xtal_osc_ctrl_try_unpack_be(const uint8_t val[1], struct fh101rf_xtal_osc_ctrl *r) {
  *r = fh101rf_xtal_osc_ctrl_unpack_be(val);
  return fh101rf_validate_xtal_osc_ctrl(r);
}

// =============================================================================
// ==== Generic Macros =========================================================
// =============================================================================

/**
 * @brief Convert struct to packed little-endian binary value.
 * All non-field/always write bits are left untouched.
 */
#define FH101RF_PACK_LE(_struct_ptr_, _val_) _Generic((_struct_ptr_),                              \
    struct fh101rf_actual_bandselect* : fh101rf_actual_bandselect_pack_le,                         \
    struct fh101rf_actual_nfa_2g4* : fh101rf_actual_nfa_2g4_pack_le,                               \
    struct fh101rf_actual_nfa_433* : fh101rf_actual_nfa_433_pack_le,                               \
    struct fh101rf_actual_nfa_868* : fh101rf_actual_nfa_868_pack_le,                               \
    struct fh101rf_bands* : fh101rf_bands_pack_le,                                                 \
    struct fh101rf_band_branch_ctrl* : fh101rf_band_branch_ctrl_pack_le,                           \
    struct fh101rf_branches* : fh101rf_branches_pack_le,                                           \
    struct fh101rf_calib_ctrl* : fh101rf_calib_ctrl_pack_le,                                       \
    struct fh101rf_calib_status* : fh101rf_calib_status_pack_le,                                   \
    struct fh101rf_cntr40_0* : fh101rf_cntr40_0_pack_le,                                           \
    struct fh101rf_cntr40_1* : fh101rf_cntr40_1_pack_le,                                           \
    struct fh101rf_cntr40_2* : fh101rf_cntr40_2_pack_le,                                           \
    struct fh101rf_cntr40_3* : fh101rf_cntr40_3_pack_le,                                           \
    struct fh101rf_cntr40_4* : fh101rf_cntr40_4_pack_le,                                           \
    struct fh101rf_cntr40_clr* : fh101rf_cntr40_clr_pack_le,                                       \
    struct fh101rf_code_select* : fh101rf_code_select_pack_le,                                     \
    struct fh101rf_comp_thresh_w* : fh101rf_comp_thresh_w_pack_le,                                 \
    struct fh101rf_cyclpresc* : fh101rf_cyclpresc_pack_le,                                         \
    struct fh101rf_cycltop_hi* : fh101rf_cycltop_hi_pack_le,                                       \
    struct fh101rf_cycltop_lo* : fh101rf_cycltop_lo_pack_le,                                       \
    struct fh101rf_d_corner_ctrl* : fh101rf_d_corner_ctrl_pack_le,                                 \
    struct fh101rf_fdd_active* : fh101rf_fdd_active_pack_le,                                       \
    struct fh101rf_fdd_enable* : fh101rf_fdd_enable_pack_le,                                       \
    struct fh101rf_fdd_exit_cond* : fh101rf_fdd_exit_cond_pack_le,                                 \
    struct fh101rf_fifo_count_2g4* : fh101rf_fifo_count_2g4_pack_le,                               \
    struct fh101rf_fifo_count_433* : fh101rf_fifo_count_433_pack_le,                               \
    struct fh101rf_fifo_count_868* : fh101rf_fifo_count_868_pack_le,                               \
    struct fh101rf_fifo_length* : fh101rf_fifo_length_pack_le,                                     \
    struct fh101rf_fo_quit* : fh101rf_fo_quit_pack_le,                                             \
    struct fh101rf_genpurp_1* : fh101rf_genpurp_1_pack_le,                                         \
    struct fh101rf_idm_band* : fh101rf_idm_band_pack_le,                                           \
    struct fh101rf_idm_clr* : fh101rf_idm_clr_pack_le,                                             \
    struct fh101rf_idm_ctrl* : fh101rf_idm_ctrl_pack_le,                                           \
    struct fh101rf_idm_enable* : fh101rf_idm_enable_pack_le,                                       \
    struct fh101rf_idm_reason* : fh101rf_idm_reason_pack_le,                                       \
    struct fh101rf_id_hi* : fh101rf_id_hi_pack_le,                                                 \
    struct fh101rf_id_lo* : fh101rf_id_lo_pack_le,                                                 \
    struct fh101rf_irq_clr* : fh101rf_irq_clr_pack_le,                                             \
    struct fh101rf_irq_select* : fh101rf_irq_select_pack_le,                                       \
    struct fh101rf_irq_set* : fh101rf_irq_set_pack_le,                                             \
    struct fh101rf_irq_source* : fh101rf_irq_source_pack_le,                                       \
    struct fh101rf_irq_status* : fh101rf_irq_status_pack_le,                                       \
    struct fh101rf_korrel_state* : fh101rf_korrel_state_pack_le,                                   \
    struct fh101rf_korrel_sv_clear* : fh101rf_korrel_sv_clear_pack_le,                             \
    struct fh101rf_korrel_thresh_a* : fh101rf_korrel_thresh_a_pack_le,                             \
    struct fh101rf_korrel_thresh_b* : fh101rf_korrel_thresh_b_pack_le,                             \
    struct fh101rf_korrel_val* : fh101rf_korrel_val_pack_le,                                       \
    struct fh101rf_lco_freq_2g4_hi* : fh101rf_lco_freq_2g4_hi_pack_le,                             \
    struct fh101rf_lco_freq_2g4_lo* : fh101rf_lco_freq_2g4_lo_pack_le,                             \
    struct fh101rf_lco_freq_433_hi* : fh101rf_lco_freq_433_hi_pack_le,                             \
    struct fh101rf_lco_freq_433_lo* : fh101rf_lco_freq_433_lo_pack_le,                             \
    struct fh101rf_lco_freq_868_hi* : fh101rf_lco_freq_868_hi_pack_le,                             \
    struct fh101rf_lco_freq_868_lo* : fh101rf_lco_freq_868_lo_pack_le,                             \
    struct fh101rf_lc_tg_ena* : fh101rf_lc_tg_ena_pack_le,                                         \
    struct fh101rf_ldo_xtal_ctrl* : fh101rf_ldo_xtal_ctrl_pack_le,                                 \
    struct fh101rf_mux_d_out_sel* : fh101rf_mux_d_out_sel_pack_le,                                 \
    struct fh101rf_nfa2g4_fast* : fh101rf_nfa2g4_fast_pack_le,                                     \
    struct fh101rf_nfa2g4_slow* : fh101rf_nfa2g4_slow_pack_le,                                     \
    struct fh101rf_nfa433_fast* : fh101rf_nfa433_fast_pack_le,                                     \
    struct fh101rf_nfa433_slow* : fh101rf_nfa433_slow_pack_le,                                     \
    struct fh101rf_nfa868_fast* : fh101rf_nfa868_fast_pack_le,                                     \
    struct fh101rf_nfa868_slow* : fh101rf_nfa868_slow_pack_le,                                     \
    struct fh101rf_n_lco_target_2g4_hi* : fh101rf_n_lco_target_2g4_hi_pack_le,                     \
    struct fh101rf_n_lco_target_2g4_lo* : fh101rf_n_lco_target_2g4_lo_pack_le,                     \
    struct fh101rf_n_lco_target_433_hi* : fh101rf_n_lco_target_433_hi_pack_le,                     \
    struct fh101rf_n_lco_target_433_lo* : fh101rf_n_lco_target_433_lo_pack_le,                     \
    struct fh101rf_n_lco_target_868_hi* : fh101rf_n_lco_target_868_hi_pack_le,                     \
    struct fh101rf_n_lco_target_868_lo* : fh101rf_n_lco_target_868_lo_pack_le,                     \
    struct fh101rf_n_spg_target* : fh101rf_n_spg_target_pack_le,                                   \
    struct fh101rf_rtc* : fh101rf_rtc_pack_le,                                                     \
    struct fh101rf_rtclg0_thresh_0* : fh101rf_rtclg0_thresh_0_pack_le,                             \
    struct fh101rf_rtclg0_thresh_1* : fh101rf_rtclg0_thresh_1_pack_le,                             \
    struct fh101rf_rtclg0_thresh_2* : fh101rf_rtclg0_thresh_2_pack_le,                             \
    struct fh101rf_rtclg0_thresh_3* : fh101rf_rtclg0_thresh_3_pack_le,                             \
    struct fh101rf_rtclg0_thresh_4* : fh101rf_rtclg0_thresh_4_pack_le,                             \
    struct fh101rf_rtclg1_thresh_0* : fh101rf_rtclg1_thresh_0_pack_le,                             \
    struct fh101rf_rtclg1_thresh_1* : fh101rf_rtclg1_thresh_1_pack_le,                             \
    struct fh101rf_rtclg1_thresh_2* : fh101rf_rtclg1_thresh_2_pack_le,                             \
    struct fh101rf_rtclg1_thresh_3* : fh101rf_rtclg1_thresh_3_pack_le,                             \
    struct fh101rf_rtclg1_thresh_4* : fh101rf_rtclg1_thresh_4_pack_le,                             \
    struct fh101rf_rtcsh0_thresh_hi* : fh101rf_rtcsh0_thresh_hi_pack_le,                           \
    struct fh101rf_rtcsh0_thresh_lo* : fh101rf_rtcsh0_thresh_lo_pack_le,                           \
    struct fh101rf_rtcsh1_thresh_hi* : fh101rf_rtcsh1_thresh_hi_pack_le,                           \
    struct fh101rf_rtcsh1_thresh_lo* : fh101rf_rtcsh1_thresh_lo_pack_le,                           \
    struct fh101rf_rtc_clr* : fh101rf_rtc_clr_pack_le,                                             \
    struct fh101rf_rtc_select* : fh101rf_rtc_select_pack_le,                                       \
    struct fh101rf_rtc_status* : fh101rf_rtc_status_pack_le,                                       \
    struct fh101rf_rx_fifo_0_2g4* : fh101rf_rx_fifo_0_2g4_pack_le,                                 \
    struct fh101rf_rx_fifo_0_433* : fh101rf_rx_fifo_0_433_pack_le,                                 \
    struct fh101rf_rx_fifo_0_868* : fh101rf_rx_fifo_0_868_pack_le,                                 \
    struct fh101rf_rx_fifo_1_2g4* : fh101rf_rx_fifo_1_2g4_pack_le,                                 \
    struct fh101rf_rx_fifo_1_433* : fh101rf_rx_fifo_1_433_pack_le,                                 \
    struct fh101rf_rx_fifo_1_868* : fh101rf_rx_fifo_1_868_pack_le,                                 \
    struct fh101rf_rx_fifo_2_2g4* : fh101rf_rx_fifo_2_2g4_pack_le,                                 \
    struct fh101rf_rx_fifo_2_433* : fh101rf_rx_fifo_2_433_pack_le,                                 \
    struct fh101rf_rx_fifo_2_868* : fh101rf_rx_fifo_2_868_pack_le,                                 \
    struct fh101rf_rx_fifo_3_2g4* : fh101rf_rx_fifo_3_2g4_pack_le,                                 \
    struct fh101rf_rx_fifo_3_433* : fh101rf_rx_fifo_3_433_pack_le,                                 \
    struct fh101rf_rx_fifo_3_868* : fh101rf_rx_fifo_3_868_pack_le,                                 \
    struct fh101rf_rx_fifo_4_2g4* : fh101rf_rx_fifo_4_2g4_pack_le,                                 \
    struct fh101rf_rx_fifo_4_433* : fh101rf_rx_fifo_4_433_pack_le,                                 \
    struct fh101rf_rx_fifo_4_868* : fh101rf_rx_fifo_4_868_pack_le,                                 \
    struct fh101rf_rx_fifo_5_2g4* : fh101rf_rx_fifo_5_2g4_pack_le,                                 \
    struct fh101rf_rx_fifo_5_433* : fh101rf_rx_fifo_5_433_pack_le,                                 \
    struct fh101rf_rx_fifo_5_868* : fh101rf_rx_fifo_5_868_pack_le,                                 \
    struct fh101rf_version* : fh101rf_version_pack_le,                                             \
    struct fh101rf_xtal_good* : fh101rf_xtal_good_pack_le,                                         \
    struct fh101rf_xtal_osc_ctrl* : fh101rf_xtal_osc_ctrl_pack_le                                  \
  )(_struct_ptr_, _val_)

/**
 * @brief Convert struct to packed big-endian binary value.
 * All non-field/always write bits are left untouched.
 */
#define FH101RF_PACK_BE(_struct_ptr_, _val_) _Generic((_struct_ptr_),                              \
    struct fh101rf_actual_bandselect* : fh101rf_actual_bandselect_pack_be,                         \
    struct fh101rf_actual_nfa_2g4* : fh101rf_actual_nfa_2g4_pack_be,                               \
    struct fh101rf_actual_nfa_433* : fh101rf_actual_nfa_433_pack_be,                               \
    struct fh101rf_actual_nfa_868* : fh101rf_actual_nfa_868_pack_be,                               \
    struct fh101rf_bands* : fh101rf_bands_pack_be,                                                 \
    struct fh101rf_band_branch_ctrl* : fh101rf_band_branch_ctrl_pack_be,                           \
    struct fh101rf_branches* : fh101rf_branches_pack_be,                                           \
    struct fh101rf_calib_ctrl* : fh101rf_calib_ctrl_pack_be,                                       \
    struct fh101rf_calib_status* : fh101rf_calib_status_pack_be,                                   \
    struct fh101rf_cntr40_0* : fh101rf_cntr40_0_pack_be,                                           \
    struct fh101rf_cntr40_1* : fh101rf_cntr40_1_pack_be,                                           \
    struct fh101rf_cntr40_2* : fh101rf_cntr40_2_pack_be,                                           \
    struct fh101rf_cntr40_3* : fh101rf_cntr40_3_pack_be,                                           \
    struct fh101rf_cntr40_4* : fh101rf_cntr40_4_pack_be,                                           \
    struct fh101rf_cntr40_clr* : fh101rf_cntr40_clr_pack_be,                                       \
    struct fh101rf_code_select* : fh101rf_code_select_pack_be,                                     \
    struct fh101rf_comp_thresh_w* : fh101rf_comp_thresh_w_pack_be,                                 \
    struct fh101rf_cyclpresc* : fh101rf_cyclpresc_pack_be,                                         \
    struct fh101rf_cycltop_hi* : fh101rf_cycltop_hi_pack_be,                                       \
    struct fh101rf_cycltop_lo* : fh101rf_cycltop_lo_pack_be,                                       \
    struct fh101rf_d_corner_ctrl* : fh101rf_d_corner_ctrl_pack_be,                                 \
    struct fh101rf_fdd_active* : fh101rf_fdd_active_pack_be,                                       \
    struct fh101rf_fdd_enable* : fh101rf_fdd_enable_pack_be,                                       \
    struct fh101rf_fdd_exit_cond* : fh101rf_fdd_exit_cond_pack_be,                                 \
    struct fh101rf_fifo_count_2g4* : fh101rf_fifo_count_2g4_pack_be,                               \
    struct fh101rf_fifo_count_433* : fh101rf_fifo_count_433_pack_be,                               \
    struct fh101rf_fifo_count_868* : fh101rf_fifo_count_868_pack_be,                               \
    struct fh101rf_fifo_length* : fh101rf_fifo_length_pack_be,                                     \
    struct fh101rf_fo_quit* : fh101rf_fo_quit_pack_be,                                             \
    struct fh101rf_genpurp_1* : fh101rf_genpurp_1_pack_be,                                         \
    struct fh101rf_idm_band* : fh101rf_idm_band_pack_be,                                           \
    struct fh101rf_idm_clr* : fh101rf_idm_clr_pack_be,                                             \
    struct fh101rf_idm_ctrl* : fh101rf_idm_ctrl_pack_be,                                           \
    struct fh101rf_idm_enable* : fh101rf_idm_enable_pack_be,                                       \
    struct fh101rf_idm_reason* : fh101rf_idm_reason_pack_be,                                       \
    struct fh101rf_id_hi* : fh101rf_id_hi_pack_be,                                                 \
    struct fh101rf_id_lo* : fh101rf_id_lo_pack_be,                                                 \
    struct fh101rf_irq_clr* : fh101rf_irq_clr_pack_be,                                             \
    struct fh101rf_irq_select* : fh101rf_irq_select_pack_be,                                       \
    struct fh101rf_irq_set* : fh101rf_irq_set_pack_be,                                             \
    struct fh101rf_irq_source* : fh101rf_irq_source_pack_be,                                       \
    struct fh101rf_irq_status* : fh101rf_irq_status_pack_be,                                       \
    struct fh101rf_korrel_state* : fh101rf_korrel_state_pack_be,                                   \
    struct fh101rf_korrel_sv_clear* : fh101rf_korrel_sv_clear_pack_be,                             \
    struct fh101rf_korrel_thresh_a* : fh101rf_korrel_thresh_a_pack_be,                             \
    struct fh101rf_korrel_thresh_b* : fh101rf_korrel_thresh_b_pack_be,                             \
    struct fh101rf_korrel_val* : fh101rf_korrel_val_pack_be,                                       \
    struct fh101rf_lco_freq_2g4_hi* : fh101rf_lco_freq_2g4_hi_pack_be,                             \
    struct fh101rf_lco_freq_2g4_lo* : fh101rf_lco_freq_2g4_lo_pack_be,                             \
    struct fh101rf_lco_freq_433_hi* : fh101rf_lco_freq_433_hi_pack_be,                             \
    struct fh101rf_lco_freq_433_lo* : fh101rf_lco_freq_433_lo_pack_be,                             \
    struct fh101rf_lco_freq_868_hi* : fh101rf_lco_freq_868_hi_pack_be,                             \
    struct fh101rf_lco_freq_868_lo* : fh101rf_lco_freq_868_lo_pack_be,                             \
    struct fh101rf_lc_tg_ena* : fh101rf_lc_tg_ena_pack_be,                                         \
    struct fh101rf_ldo_xtal_ctrl* : fh101rf_ldo_xtal_ctrl_pack_be,                                 \
    struct fh101rf_mux_d_out_sel* : fh101rf_mux_d_out_sel_pack_be,                                 \
    struct fh101rf_nfa2g4_fast* : fh101rf_nfa2g4_fast_pack_be,                                     \
    struct fh101rf_nfa2g4_slow* : fh101rf_nfa2g4_slow_pack_be,                                     \
    struct fh101rf_nfa433_fast* : fh101rf_nfa433_fast_pack_be,                                     \
    struct fh101rf_nfa433_slow* : fh101rf_nfa433_slow_pack_be,                                     \
    struct fh101rf_nfa868_fast* : fh101rf_nfa868_fast_pack_be,                                     \
    struct fh101rf_nfa868_slow* : fh101rf_nfa868_slow_pack_be,                                     \
    struct fh101rf_n_lco_target_2g4_hi* : fh101rf_n_lco_target_2g4_hi_pack_be,                     \
    struct fh101rf_n_lco_target_2g4_lo* : fh101rf_n_lco_target_2g4_lo_pack_be,                     \
    struct fh101rf_n_lco_target_433_hi* : fh101rf_n_lco_target_433_hi_pack_be,                     \
    struct fh101rf_n_lco_target_433_lo* : fh101rf_n_lco_target_433_lo_pack_be,                     \
    struct fh101rf_n_lco_target_868_hi* : fh101rf_n_lco_target_868_hi_pack_be,                     \
    struct fh101rf_n_lco_target_868_lo* : fh101rf_n_lco_target_868_lo_pack_be,                     \
    struct fh101rf_n_spg_target* : fh101rf_n_spg_target_pack_be,                                   \
    struct fh101rf_rtc* : fh101rf_rtc_pack_be,                                                     \
    struct fh101rf_rtclg0_thresh_0* : fh101rf_rtclg0_thresh_0_pack_be,                             \
    struct fh101rf_rtclg0_thresh_1* : fh101rf_rtclg0_thresh_1_pack_be,                             \
    struct fh101rf_rtclg0_thresh_2* : fh101rf_rtclg0_thresh_2_pack_be,                             \
    struct fh101rf_rtclg0_thresh_3* : fh101rf_rtclg0_thresh_3_pack_be,                             \
    struct fh101rf_rtclg0_thresh_4* : fh101rf_rtclg0_thresh_4_pack_be,                             \
    struct fh101rf_rtclg1_thresh_0* : fh101rf_rtclg1_thresh_0_pack_be,                             \
    struct fh101rf_rtclg1_thresh_1* : fh101rf_rtclg1_thresh_1_pack_be,                             \
    struct fh101rf_rtclg1_thresh_2* : fh101rf_rtclg1_thresh_2_pack_be,                             \
    struct fh101rf_rtclg1_thresh_3* : fh101rf_rtclg1_thresh_3_pack_be,                             \
    struct fh101rf_rtclg1_thresh_4* : fh101rf_rtclg1_thresh_4_pack_be,                             \
    struct fh101rf_rtcsh0_thresh_hi* : fh101rf_rtcsh0_thresh_hi_pack_be,                           \
    struct fh101rf_rtcsh0_thresh_lo* : fh101rf_rtcsh0_thresh_lo_pack_be,                           \
    struct fh101rf_rtcsh1_thresh_hi* : fh101rf_rtcsh1_thresh_hi_pack_be,                           \
    struct fh101rf_rtcsh1_thresh_lo* : fh101rf_rtcsh1_thresh_lo_pack_be,                           \
    struct fh101rf_rtc_clr* : fh101rf_rtc_clr_pack_be,                                             \
    struct fh101rf_rtc_select* : fh101rf_rtc_select_pack_be,                                       \
    struct fh101rf_rtc_status* : fh101rf_rtc_status_pack_be,                                       \
    struct fh101rf_rx_fifo_0_2g4* : fh101rf_rx_fifo_0_2g4_pack_be,                                 \
    struct fh101rf_rx_fifo_0_433* : fh101rf_rx_fifo_0_433_pack_be,                                 \
    struct fh101rf_rx_fifo_0_868* : fh101rf_rx_fifo_0_868_pack_be,                                 \
    struct fh101rf_rx_fifo_1_2g4* : fh101rf_rx_fifo_1_2g4_pack_be,                                 \
    struct fh101rf_rx_fifo_1_433* : fh101rf_rx_fifo_1_433_pack_be,                                 \
    struct fh101rf_rx_fifo_1_868* : fh101rf_rx_fifo_1_868_pack_be,                                 \
    struct fh101rf_rx_fifo_2_2g4* : fh101rf_rx_fifo_2_2g4_pack_be,                                 \
    struct fh101rf_rx_fifo_2_433* : fh101rf_rx_fifo_2_433_pack_be,                                 \
    struct fh101rf_rx_fifo_2_868* : fh101rf_rx_fifo_2_868_pack_be,                                 \
    struct fh101rf_rx_fifo_3_2g4* : fh101rf_rx_fifo_3_2g4_pack_be,                                 \
    struct fh101rf_rx_fifo_3_433* : fh101rf_rx_fifo_3_433_pack_be,                                 \
    struct fh101rf_rx_fifo_3_868* : fh101rf_rx_fifo_3_868_pack_be,                                 \
    struct fh101rf_rx_fifo_4_2g4* : fh101rf_rx_fifo_4_2g4_pack_be,                                 \
    struct fh101rf_rx_fifo_4_433* : fh101rf_rx_fifo_4_433_pack_be,                                 \
    struct fh101rf_rx_fifo_4_868* : fh101rf_rx_fifo_4_868_pack_be,                                 \
    struct fh101rf_rx_fifo_5_2g4* : fh101rf_rx_fifo_5_2g4_pack_be,                                 \
    struct fh101rf_rx_fifo_5_433* : fh101rf_rx_fifo_5_433_pack_be,                                 \
    struct fh101rf_rx_fifo_5_868* : fh101rf_rx_fifo_5_868_pack_be,                                 \
    struct fh101rf_version* : fh101rf_version_pack_be,                                             \
    struct fh101rf_xtal_good* : fh101rf_xtal_good_pack_be,                                         \
    struct fh101rf_xtal_osc_ctrl* : fh101rf_xtal_osc_ctrl_pack_be                                  \
  )(_struct_ptr_, _val_)

/**
 * @brief Validate struct
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 * Confirms that all enums are valid, and all values fit into respective fields
 */
#define FH101RF_VALIDATE(_struct_ptr_) _Generic((_struct_ptr_),                                    \
    struct fh101rf_actual_bandselect* : fh101rf_actual_bandselect_validate,                        \
    struct fh101rf_actual_nfa_2g4* : fh101rf_actual_nfa_2g4_validate,                              \
    struct fh101rf_actual_nfa_433* : fh101rf_actual_nfa_433_validate,                              \
    struct fh101rf_actual_nfa_868* : fh101rf_actual_nfa_868_validate,                              \
    struct fh101rf_bands* : fh101rf_bands_validate,                                                \
    struct fh101rf_band_branch_ctrl* : fh101rf_band_branch_ctrl_validate,                          \
    struct fh101rf_branches* : fh101rf_branches_validate,                                          \
    struct fh101rf_calib_ctrl* : fh101rf_calib_ctrl_validate,                                      \
    struct fh101rf_calib_status* : fh101rf_calib_status_validate,                                  \
    struct fh101rf_cntr40_0* : fh101rf_cntr40_0_validate,                                          \
    struct fh101rf_cntr40_1* : fh101rf_cntr40_1_validate,                                          \
    struct fh101rf_cntr40_2* : fh101rf_cntr40_2_validate,                                          \
    struct fh101rf_cntr40_3* : fh101rf_cntr40_3_validate,                                          \
    struct fh101rf_cntr40_4* : fh101rf_cntr40_4_validate,                                          \
    struct fh101rf_cntr40_clr* : fh101rf_cntr40_clr_validate,                                      \
    struct fh101rf_code_select* : fh101rf_code_select_validate,                                    \
    struct fh101rf_comp_thresh_w* : fh101rf_comp_thresh_w_validate,                                \
    struct fh101rf_cyclpresc* : fh101rf_cyclpresc_validate,                                        \
    struct fh101rf_cycltop_hi* : fh101rf_cycltop_hi_validate,                                      \
    struct fh101rf_cycltop_lo* : fh101rf_cycltop_lo_validate,                                      \
    struct fh101rf_d_corner_ctrl* : fh101rf_d_corner_ctrl_validate,                                \
    struct fh101rf_fdd_active* : fh101rf_fdd_active_validate,                                      \
    struct fh101rf_fdd_enable* : fh101rf_fdd_enable_validate,                                      \
    struct fh101rf_fdd_exit_cond* : fh101rf_fdd_exit_cond_validate,                                \
    struct fh101rf_fifo_count_2g4* : fh101rf_fifo_count_2g4_validate,                              \
    struct fh101rf_fifo_count_433* : fh101rf_fifo_count_433_validate,                              \
    struct fh101rf_fifo_count_868* : fh101rf_fifo_count_868_validate,                              \
    struct fh101rf_fifo_length* : fh101rf_fifo_length_validate,                                    \
    struct fh101rf_fo_quit* : fh101rf_fo_quit_validate,                                            \
    struct fh101rf_genpurp_1* : fh101rf_genpurp_1_validate,                                        \
    struct fh101rf_idm_band* : fh101rf_idm_band_validate,                                          \
    struct fh101rf_idm_clr* : fh101rf_idm_clr_validate,                                            \
    struct fh101rf_idm_ctrl* : fh101rf_idm_ctrl_validate,                                          \
    struct fh101rf_idm_enable* : fh101rf_idm_enable_validate,                                      \
    struct fh101rf_idm_reason* : fh101rf_idm_reason_validate,                                      \
    struct fh101rf_id_hi* : fh101rf_id_hi_validate,                                                \
    struct fh101rf_id_lo* : fh101rf_id_lo_validate,                                                \
    struct fh101rf_irq_clr* : fh101rf_irq_clr_validate,                                            \
    struct fh101rf_irq_select* : fh101rf_irq_select_validate,                                      \
    struct fh101rf_irq_set* : fh101rf_irq_set_validate,                                            \
    struct fh101rf_irq_source* : fh101rf_irq_source_validate,                                      \
    struct fh101rf_irq_status* : fh101rf_irq_status_validate,                                      \
    struct fh101rf_korrel_state* : fh101rf_korrel_state_validate,                                  \
    struct fh101rf_korrel_sv_clear* : fh101rf_korrel_sv_clear_validate,                            \
    struct fh101rf_korrel_thresh_a* : fh101rf_korrel_thresh_a_validate,                            \
    struct fh101rf_korrel_thresh_b* : fh101rf_korrel_thresh_b_validate,                            \
    struct fh101rf_korrel_val* : fh101rf_korrel_val_validate,                                      \
    struct fh101rf_lco_freq_2g4_hi* : fh101rf_lco_freq_2g4_hi_validate,                            \
    struct fh101rf_lco_freq_2g4_lo* : fh101rf_lco_freq_2g4_lo_validate,                            \
    struct fh101rf_lco_freq_433_hi* : fh101rf_lco_freq_433_hi_validate,                            \
    struct fh101rf_lco_freq_433_lo* : fh101rf_lco_freq_433_lo_validate,                            \
    struct fh101rf_lco_freq_868_hi* : fh101rf_lco_freq_868_hi_validate,                            \
    struct fh101rf_lco_freq_868_lo* : fh101rf_lco_freq_868_lo_validate,                            \
    struct fh101rf_lc_tg_ena* : fh101rf_lc_tg_ena_validate,                                        \
    struct fh101rf_ldo_xtal_ctrl* : fh101rf_ldo_xtal_ctrl_validate,                                \
    struct fh101rf_mux_d_out_sel* : fh101rf_mux_d_out_sel_validate,                                \
    struct fh101rf_nfa2g4_fast* : fh101rf_nfa2g4_fast_validate,                                    \
    struct fh101rf_nfa2g4_slow* : fh101rf_nfa2g4_slow_validate,                                    \
    struct fh101rf_nfa433_fast* : fh101rf_nfa433_fast_validate,                                    \
    struct fh101rf_nfa433_slow* : fh101rf_nfa433_slow_validate,                                    \
    struct fh101rf_nfa868_fast* : fh101rf_nfa868_fast_validate,                                    \
    struct fh101rf_nfa868_slow* : fh101rf_nfa868_slow_validate,                                    \
    struct fh101rf_n_lco_target_2g4_hi* : fh101rf_n_lco_target_2g4_hi_validate,                    \
    struct fh101rf_n_lco_target_2g4_lo* : fh101rf_n_lco_target_2g4_lo_validate,                    \
    struct fh101rf_n_lco_target_433_hi* : fh101rf_n_lco_target_433_hi_validate,                    \
    struct fh101rf_n_lco_target_433_lo* : fh101rf_n_lco_target_433_lo_validate,                    \
    struct fh101rf_n_lco_target_868_hi* : fh101rf_n_lco_target_868_hi_validate,                    \
    struct fh101rf_n_lco_target_868_lo* : fh101rf_n_lco_target_868_lo_validate,                    \
    struct fh101rf_n_spg_target* : fh101rf_n_spg_target_validate,                                  \
    struct fh101rf_rtc* : fh101rf_rtc_validate,                                                    \
    struct fh101rf_rtclg0_thresh_0* : fh101rf_rtclg0_thresh_0_validate,                            \
    struct fh101rf_rtclg0_thresh_1* : fh101rf_rtclg0_thresh_1_validate,                            \
    struct fh101rf_rtclg0_thresh_2* : fh101rf_rtclg0_thresh_2_validate,                            \
    struct fh101rf_rtclg0_thresh_3* : fh101rf_rtclg0_thresh_3_validate,                            \
    struct fh101rf_rtclg0_thresh_4* : fh101rf_rtclg0_thresh_4_validate,                            \
    struct fh101rf_rtclg1_thresh_0* : fh101rf_rtclg1_thresh_0_validate,                            \
    struct fh101rf_rtclg1_thresh_1* : fh101rf_rtclg1_thresh_1_validate,                            \
    struct fh101rf_rtclg1_thresh_2* : fh101rf_rtclg1_thresh_2_validate,                            \
    struct fh101rf_rtclg1_thresh_3* : fh101rf_rtclg1_thresh_3_validate,                            \
    struct fh101rf_rtclg1_thresh_4* : fh101rf_rtclg1_thresh_4_validate,                            \
    struct fh101rf_rtcsh0_thresh_hi* : fh101rf_rtcsh0_thresh_hi_validate,                          \
    struct fh101rf_rtcsh0_thresh_lo* : fh101rf_rtcsh0_thresh_lo_validate,                          \
    struct fh101rf_rtcsh1_thresh_hi* : fh101rf_rtcsh1_thresh_hi_validate,                          \
    struct fh101rf_rtcsh1_thresh_lo* : fh101rf_rtcsh1_thresh_lo_validate,                          \
    struct fh101rf_rtc_clr* : fh101rf_rtc_clr_validate,                                            \
    struct fh101rf_rtc_select* : fh101rf_rtc_select_validate,                                      \
    struct fh101rf_rtc_status* : fh101rf_rtc_status_validate,                                      \
    struct fh101rf_rx_fifo_0_2g4* : fh101rf_rx_fifo_0_2g4_validate,                                \
    struct fh101rf_rx_fifo_0_433* : fh101rf_rx_fifo_0_433_validate,                                \
    struct fh101rf_rx_fifo_0_868* : fh101rf_rx_fifo_0_868_validate,                                \
    struct fh101rf_rx_fifo_1_2g4* : fh101rf_rx_fifo_1_2g4_validate,                                \
    struct fh101rf_rx_fifo_1_433* : fh101rf_rx_fifo_1_433_validate,                                \
    struct fh101rf_rx_fifo_1_868* : fh101rf_rx_fifo_1_868_validate,                                \
    struct fh101rf_rx_fifo_2_2g4* : fh101rf_rx_fifo_2_2g4_validate,                                \
    struct fh101rf_rx_fifo_2_433* : fh101rf_rx_fifo_2_433_validate,                                \
    struct fh101rf_rx_fifo_2_868* : fh101rf_rx_fifo_2_868_validate,                                \
    struct fh101rf_rx_fifo_3_2g4* : fh101rf_rx_fifo_3_2g4_validate,                                \
    struct fh101rf_rx_fifo_3_433* : fh101rf_rx_fifo_3_433_validate,                                \
    struct fh101rf_rx_fifo_3_868* : fh101rf_rx_fifo_3_868_validate,                                \
    struct fh101rf_rx_fifo_4_2g4* : fh101rf_rx_fifo_4_2g4_validate,                                \
    struct fh101rf_rx_fifo_4_433* : fh101rf_rx_fifo_4_433_validate,                                \
    struct fh101rf_rx_fifo_4_868* : fh101rf_rx_fifo_4_868_validate,                                \
    struct fh101rf_rx_fifo_5_2g4* : fh101rf_rx_fifo_5_2g4_validate,                                \
    struct fh101rf_rx_fifo_5_433* : fh101rf_rx_fifo_5_433_validate,                                \
    struct fh101rf_rx_fifo_5_868* : fh101rf_rx_fifo_5_868_validate,                                \
    struct fh101rf_version* : fh101rf_version_validate,                                            \
    struct fh101rf_xtal_good* : fh101rf_xtal_good_validate,                                        \
    struct fh101rf_xtal_osc_ctrl* : fh101rf_xtal_osc_ctrl_validate                                 \
  )(_struct_ptr_)

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
#define FH101RF_TRY_UNPACK_LE(_val_, _struct_ptr_) _Generic((_struct_ptr_),                        \
    struct fh101rf_actual_bandselect* : fh101rf_actual_bandselect_try_unpack_le,                   \
    struct fh101rf_actual_nfa_2g4* : fh101rf_actual_nfa_2g4_try_unpack_le,                         \
    struct fh101rf_actual_nfa_433* : fh101rf_actual_nfa_433_try_unpack_le,                         \
    struct fh101rf_actual_nfa_868* : fh101rf_actual_nfa_868_try_unpack_le,                         \
    struct fh101rf_bands* : fh101rf_bands_try_unpack_le,                                           \
    struct fh101rf_band_branch_ctrl* : fh101rf_band_branch_ctrl_try_unpack_le,                     \
    struct fh101rf_branches* : fh101rf_branches_try_unpack_le,                                     \
    struct fh101rf_calib_ctrl* : fh101rf_calib_ctrl_try_unpack_le,                                 \
    struct fh101rf_calib_status* : fh101rf_calib_status_try_unpack_le,                             \
    struct fh101rf_cntr40_0* : fh101rf_cntr40_0_try_unpack_le,                                     \
    struct fh101rf_cntr40_1* : fh101rf_cntr40_1_try_unpack_le,                                     \
    struct fh101rf_cntr40_2* : fh101rf_cntr40_2_try_unpack_le,                                     \
    struct fh101rf_cntr40_3* : fh101rf_cntr40_3_try_unpack_le,                                     \
    struct fh101rf_cntr40_4* : fh101rf_cntr40_4_try_unpack_le,                                     \
    struct fh101rf_cntr40_clr* : fh101rf_cntr40_clr_try_unpack_le,                                 \
    struct fh101rf_code_select* : fh101rf_code_select_try_unpack_le,                               \
    struct fh101rf_comp_thresh_w* : fh101rf_comp_thresh_w_try_unpack_le,                           \
    struct fh101rf_cyclpresc* : fh101rf_cyclpresc_try_unpack_le,                                   \
    struct fh101rf_cycltop_hi* : fh101rf_cycltop_hi_try_unpack_le,                                 \
    struct fh101rf_cycltop_lo* : fh101rf_cycltop_lo_try_unpack_le,                                 \
    struct fh101rf_d_corner_ctrl* : fh101rf_d_corner_ctrl_try_unpack_le,                           \
    struct fh101rf_fdd_active* : fh101rf_fdd_active_try_unpack_le,                                 \
    struct fh101rf_fdd_enable* : fh101rf_fdd_enable_try_unpack_le,                                 \
    struct fh101rf_fdd_exit_cond* : fh101rf_fdd_exit_cond_try_unpack_le,                           \
    struct fh101rf_fifo_count_2g4* : fh101rf_fifo_count_2g4_try_unpack_le,                         \
    struct fh101rf_fifo_count_433* : fh101rf_fifo_count_433_try_unpack_le,                         \
    struct fh101rf_fifo_count_868* : fh101rf_fifo_count_868_try_unpack_le,                         \
    struct fh101rf_fifo_length* : fh101rf_fifo_length_try_unpack_le,                               \
    struct fh101rf_fo_quit* : fh101rf_fo_quit_try_unpack_le,                                       \
    struct fh101rf_genpurp_1* : fh101rf_genpurp_1_try_unpack_le,                                   \
    struct fh101rf_idm_band* : fh101rf_idm_band_try_unpack_le,                                     \
    struct fh101rf_idm_clr* : fh101rf_idm_clr_try_unpack_le,                                       \
    struct fh101rf_idm_ctrl* : fh101rf_idm_ctrl_try_unpack_le,                                     \
    struct fh101rf_idm_enable* : fh101rf_idm_enable_try_unpack_le,                                 \
    struct fh101rf_idm_reason* : fh101rf_idm_reason_try_unpack_le,                                 \
    struct fh101rf_id_hi* : fh101rf_id_hi_try_unpack_le,                                           \
    struct fh101rf_id_lo* : fh101rf_id_lo_try_unpack_le,                                           \
    struct fh101rf_irq_clr* : fh101rf_irq_clr_try_unpack_le,                                       \
    struct fh101rf_irq_select* : fh101rf_irq_select_try_unpack_le,                                 \
    struct fh101rf_irq_set* : fh101rf_irq_set_try_unpack_le,                                       \
    struct fh101rf_irq_source* : fh101rf_irq_source_try_unpack_le,                                 \
    struct fh101rf_irq_status* : fh101rf_irq_status_try_unpack_le,                                 \
    struct fh101rf_korrel_state* : fh101rf_korrel_state_try_unpack_le,                             \
    struct fh101rf_korrel_sv_clear* : fh101rf_korrel_sv_clear_try_unpack_le,                       \
    struct fh101rf_korrel_thresh_a* : fh101rf_korrel_thresh_a_try_unpack_le,                       \
    struct fh101rf_korrel_thresh_b* : fh101rf_korrel_thresh_b_try_unpack_le,                       \
    struct fh101rf_korrel_val* : fh101rf_korrel_val_try_unpack_le,                                 \
    struct fh101rf_lco_freq_2g4_hi* : fh101rf_lco_freq_2g4_hi_try_unpack_le,                       \
    struct fh101rf_lco_freq_2g4_lo* : fh101rf_lco_freq_2g4_lo_try_unpack_le,                       \
    struct fh101rf_lco_freq_433_hi* : fh101rf_lco_freq_433_hi_try_unpack_le,                       \
    struct fh101rf_lco_freq_433_lo* : fh101rf_lco_freq_433_lo_try_unpack_le,                       \
    struct fh101rf_lco_freq_868_hi* : fh101rf_lco_freq_868_hi_try_unpack_le,                       \
    struct fh101rf_lco_freq_868_lo* : fh101rf_lco_freq_868_lo_try_unpack_le,                       \
    struct fh101rf_lc_tg_ena* : fh101rf_lc_tg_ena_try_unpack_le,                                   \
    struct fh101rf_ldo_xtal_ctrl* : fh101rf_ldo_xtal_ctrl_try_unpack_le,                           \
    struct fh101rf_mux_d_out_sel* : fh101rf_mux_d_out_sel_try_unpack_le,                           \
    struct fh101rf_nfa2g4_fast* : fh101rf_nfa2g4_fast_try_unpack_le,                               \
    struct fh101rf_nfa2g4_slow* : fh101rf_nfa2g4_slow_try_unpack_le,                               \
    struct fh101rf_nfa433_fast* : fh101rf_nfa433_fast_try_unpack_le,                               \
    struct fh101rf_nfa433_slow* : fh101rf_nfa433_slow_try_unpack_le,                               \
    struct fh101rf_nfa868_fast* : fh101rf_nfa868_fast_try_unpack_le,                               \
    struct fh101rf_nfa868_slow* : fh101rf_nfa868_slow_try_unpack_le,                               \
    struct fh101rf_n_lco_target_2g4_hi* : fh101rf_n_lco_target_2g4_hi_try_unpack_le,               \
    struct fh101rf_n_lco_target_2g4_lo* : fh101rf_n_lco_target_2g4_lo_try_unpack_le,               \
    struct fh101rf_n_lco_target_433_hi* : fh101rf_n_lco_target_433_hi_try_unpack_le,               \
    struct fh101rf_n_lco_target_433_lo* : fh101rf_n_lco_target_433_lo_try_unpack_le,               \
    struct fh101rf_n_lco_target_868_hi* : fh101rf_n_lco_target_868_hi_try_unpack_le,               \
    struct fh101rf_n_lco_target_868_lo* : fh101rf_n_lco_target_868_lo_try_unpack_le,               \
    struct fh101rf_n_spg_target* : fh101rf_n_spg_target_try_unpack_le,                             \
    struct fh101rf_rtc* : fh101rf_rtc_try_unpack_le,                                               \
    struct fh101rf_rtclg0_thresh_0* : fh101rf_rtclg0_thresh_0_try_unpack_le,                       \
    struct fh101rf_rtclg0_thresh_1* : fh101rf_rtclg0_thresh_1_try_unpack_le,                       \
    struct fh101rf_rtclg0_thresh_2* : fh101rf_rtclg0_thresh_2_try_unpack_le,                       \
    struct fh101rf_rtclg0_thresh_3* : fh101rf_rtclg0_thresh_3_try_unpack_le,                       \
    struct fh101rf_rtclg0_thresh_4* : fh101rf_rtclg0_thresh_4_try_unpack_le,                       \
    struct fh101rf_rtclg1_thresh_0* : fh101rf_rtclg1_thresh_0_try_unpack_le,                       \
    struct fh101rf_rtclg1_thresh_1* : fh101rf_rtclg1_thresh_1_try_unpack_le,                       \
    struct fh101rf_rtclg1_thresh_2* : fh101rf_rtclg1_thresh_2_try_unpack_le,                       \
    struct fh101rf_rtclg1_thresh_3* : fh101rf_rtclg1_thresh_3_try_unpack_le,                       \
    struct fh101rf_rtclg1_thresh_4* : fh101rf_rtclg1_thresh_4_try_unpack_le,                       \
    struct fh101rf_rtcsh0_thresh_hi* : fh101rf_rtcsh0_thresh_hi_try_unpack_le,                     \
    struct fh101rf_rtcsh0_thresh_lo* : fh101rf_rtcsh0_thresh_lo_try_unpack_le,                     \
    struct fh101rf_rtcsh1_thresh_hi* : fh101rf_rtcsh1_thresh_hi_try_unpack_le,                     \
    struct fh101rf_rtcsh1_thresh_lo* : fh101rf_rtcsh1_thresh_lo_try_unpack_le,                     \
    struct fh101rf_rtc_clr* : fh101rf_rtc_clr_try_unpack_le,                                       \
    struct fh101rf_rtc_select* : fh101rf_rtc_select_try_unpack_le,                                 \
    struct fh101rf_rtc_status* : fh101rf_rtc_status_try_unpack_le,                                 \
    struct fh101rf_rx_fifo_0_2g4* : fh101rf_rx_fifo_0_2g4_try_unpack_le,                           \
    struct fh101rf_rx_fifo_0_433* : fh101rf_rx_fifo_0_433_try_unpack_le,                           \
    struct fh101rf_rx_fifo_0_868* : fh101rf_rx_fifo_0_868_try_unpack_le,                           \
    struct fh101rf_rx_fifo_1_2g4* : fh101rf_rx_fifo_1_2g4_try_unpack_le,                           \
    struct fh101rf_rx_fifo_1_433* : fh101rf_rx_fifo_1_433_try_unpack_le,                           \
    struct fh101rf_rx_fifo_1_868* : fh101rf_rx_fifo_1_868_try_unpack_le,                           \
    struct fh101rf_rx_fifo_2_2g4* : fh101rf_rx_fifo_2_2g4_try_unpack_le,                           \
    struct fh101rf_rx_fifo_2_433* : fh101rf_rx_fifo_2_433_try_unpack_le,                           \
    struct fh101rf_rx_fifo_2_868* : fh101rf_rx_fifo_2_868_try_unpack_le,                           \
    struct fh101rf_rx_fifo_3_2g4* : fh101rf_rx_fifo_3_2g4_try_unpack_le,                           \
    struct fh101rf_rx_fifo_3_433* : fh101rf_rx_fifo_3_433_try_unpack_le,                           \
    struct fh101rf_rx_fifo_3_868* : fh101rf_rx_fifo_3_868_try_unpack_le,                           \
    struct fh101rf_rx_fifo_4_2g4* : fh101rf_rx_fifo_4_2g4_try_unpack_le,                           \
    struct fh101rf_rx_fifo_4_433* : fh101rf_rx_fifo_4_433_try_unpack_le,                           \
    struct fh101rf_rx_fifo_4_868* : fh101rf_rx_fifo_4_868_try_unpack_le,                           \
    struct fh101rf_rx_fifo_5_2g4* : fh101rf_rx_fifo_5_2g4_try_unpack_le,                           \
    struct fh101rf_rx_fifo_5_433* : fh101rf_rx_fifo_5_433_try_unpack_le,                           \
    struct fh101rf_rx_fifo_5_868* : fh101rf_rx_fifo_5_868_try_unpack_le,                           \
    struct fh101rf_version* : fh101rf_version_try_unpack_le,                                       \
    struct fh101rf_xtal_good* : fh101rf_xtal_good_try_unpack_le,                                   \
    struct fh101rf_xtal_osc_ctrl* : fh101rf_xtal_osc_ctrl_try_unpack_le                            \
  )(_val_, _struct_ptr_)

/**
 * @brief Attempt to convert packed {endian} binary value to struct.
 * @returns 0 if valid.
 * @returns the position of the first invalid field if invalid.
 */
#define FH101RF_TRY_UNPACK_BE(_val_, _struct_ptr_) _Generic((_struct_ptr_),                        \
    struct fh101rf_actual_bandselect* : fh101rf_actual_bandselect_try_unpack_be,                   \
    struct fh101rf_actual_nfa_2g4* : fh101rf_actual_nfa_2g4_try_unpack_be,                         \
    struct fh101rf_actual_nfa_433* : fh101rf_actual_nfa_433_try_unpack_be,                         \
    struct fh101rf_actual_nfa_868* : fh101rf_actual_nfa_868_try_unpack_be,                         \
    struct fh101rf_bands* : fh101rf_bands_try_unpack_be,                                           \
    struct fh101rf_band_branch_ctrl* : fh101rf_band_branch_ctrl_try_unpack_be,                     \
    struct fh101rf_branches* : fh101rf_branches_try_unpack_be,                                     \
    struct fh101rf_calib_ctrl* : fh101rf_calib_ctrl_try_unpack_be,                                 \
    struct fh101rf_calib_status* : fh101rf_calib_status_try_unpack_be,                             \
    struct fh101rf_cntr40_0* : fh101rf_cntr40_0_try_unpack_be,                                     \
    struct fh101rf_cntr40_1* : fh101rf_cntr40_1_try_unpack_be,                                     \
    struct fh101rf_cntr40_2* : fh101rf_cntr40_2_try_unpack_be,                                     \
    struct fh101rf_cntr40_3* : fh101rf_cntr40_3_try_unpack_be,                                     \
    struct fh101rf_cntr40_4* : fh101rf_cntr40_4_try_unpack_be,                                     \
    struct fh101rf_cntr40_clr* : fh101rf_cntr40_clr_try_unpack_be,                                 \
    struct fh101rf_code_select* : fh101rf_code_select_try_unpack_be,                               \
    struct fh101rf_comp_thresh_w* : fh101rf_comp_thresh_w_try_unpack_be,                           \
    struct fh101rf_cyclpresc* : fh101rf_cyclpresc_try_unpack_be,                                   \
    struct fh101rf_cycltop_hi* : fh101rf_cycltop_hi_try_unpack_be,                                 \
    struct fh101rf_cycltop_lo* : fh101rf_cycltop_lo_try_unpack_be,                                 \
    struct fh101rf_d_corner_ctrl* : fh101rf_d_corner_ctrl_try_unpack_be,                           \
    struct fh101rf_fdd_active* : fh101rf_fdd_active_try_unpack_be,                                 \
    struct fh101rf_fdd_enable* : fh101rf_fdd_enable_try_unpack_be,                                 \
    struct fh101rf_fdd_exit_cond* : fh101rf_fdd_exit_cond_try_unpack_be,                           \
    struct fh101rf_fifo_count_2g4* : fh101rf_fifo_count_2g4_try_unpack_be,                         \
    struct fh101rf_fifo_count_433* : fh101rf_fifo_count_433_try_unpack_be,                         \
    struct fh101rf_fifo_count_868* : fh101rf_fifo_count_868_try_unpack_be,                         \
    struct fh101rf_fifo_length* : fh101rf_fifo_length_try_unpack_be,                               \
    struct fh101rf_fo_quit* : fh101rf_fo_quit_try_unpack_be,                                       \
    struct fh101rf_genpurp_1* : fh101rf_genpurp_1_try_unpack_be,                                   \
    struct fh101rf_idm_band* : fh101rf_idm_band_try_unpack_be,                                     \
    struct fh101rf_idm_clr* : fh101rf_idm_clr_try_unpack_be,                                       \
    struct fh101rf_idm_ctrl* : fh101rf_idm_ctrl_try_unpack_be,                                     \
    struct fh101rf_idm_enable* : fh101rf_idm_enable_try_unpack_be,                                 \
    struct fh101rf_idm_reason* : fh101rf_idm_reason_try_unpack_be,                                 \
    struct fh101rf_id_hi* : fh101rf_id_hi_try_unpack_be,                                           \
    struct fh101rf_id_lo* : fh101rf_id_lo_try_unpack_be,                                           \
    struct fh101rf_irq_clr* : fh101rf_irq_clr_try_unpack_be,                                       \
    struct fh101rf_irq_select* : fh101rf_irq_select_try_unpack_be,                                 \
    struct fh101rf_irq_set* : fh101rf_irq_set_try_unpack_be,                                       \
    struct fh101rf_irq_source* : fh101rf_irq_source_try_unpack_be,                                 \
    struct fh101rf_irq_status* : fh101rf_irq_status_try_unpack_be,                                 \
    struct fh101rf_korrel_state* : fh101rf_korrel_state_try_unpack_be,                             \
    struct fh101rf_korrel_sv_clear* : fh101rf_korrel_sv_clear_try_unpack_be,                       \
    struct fh101rf_korrel_thresh_a* : fh101rf_korrel_thresh_a_try_unpack_be,                       \
    struct fh101rf_korrel_thresh_b* : fh101rf_korrel_thresh_b_try_unpack_be,                       \
    struct fh101rf_korrel_val* : fh101rf_korrel_val_try_unpack_be,                                 \
    struct fh101rf_lco_freq_2g4_hi* : fh101rf_lco_freq_2g4_hi_try_unpack_be,                       \
    struct fh101rf_lco_freq_2g4_lo* : fh101rf_lco_freq_2g4_lo_try_unpack_be,                       \
    struct fh101rf_lco_freq_433_hi* : fh101rf_lco_freq_433_hi_try_unpack_be,                       \
    struct fh101rf_lco_freq_433_lo* : fh101rf_lco_freq_433_lo_try_unpack_be,                       \
    struct fh101rf_lco_freq_868_hi* : fh101rf_lco_freq_868_hi_try_unpack_be,                       \
    struct fh101rf_lco_freq_868_lo* : fh101rf_lco_freq_868_lo_try_unpack_be,                       \
    struct fh101rf_lc_tg_ena* : fh101rf_lc_tg_ena_try_unpack_be,                                   \
    struct fh101rf_ldo_xtal_ctrl* : fh101rf_ldo_xtal_ctrl_try_unpack_be,                           \
    struct fh101rf_mux_d_out_sel* : fh101rf_mux_d_out_sel_try_unpack_be,                           \
    struct fh101rf_nfa2g4_fast* : fh101rf_nfa2g4_fast_try_unpack_be,                               \
    struct fh101rf_nfa2g4_slow* : fh101rf_nfa2g4_slow_try_unpack_be,                               \
    struct fh101rf_nfa433_fast* : fh101rf_nfa433_fast_try_unpack_be,                               \
    struct fh101rf_nfa433_slow* : fh101rf_nfa433_slow_try_unpack_be,                               \
    struct fh101rf_nfa868_fast* : fh101rf_nfa868_fast_try_unpack_be,                               \
    struct fh101rf_nfa868_slow* : fh101rf_nfa868_slow_try_unpack_be,                               \
    struct fh101rf_n_lco_target_2g4_hi* : fh101rf_n_lco_target_2g4_hi_try_unpack_be,               \
    struct fh101rf_n_lco_target_2g4_lo* : fh101rf_n_lco_target_2g4_lo_try_unpack_be,               \
    struct fh101rf_n_lco_target_433_hi* : fh101rf_n_lco_target_433_hi_try_unpack_be,               \
    struct fh101rf_n_lco_target_433_lo* : fh101rf_n_lco_target_433_lo_try_unpack_be,               \
    struct fh101rf_n_lco_target_868_hi* : fh101rf_n_lco_target_868_hi_try_unpack_be,               \
    struct fh101rf_n_lco_target_868_lo* : fh101rf_n_lco_target_868_lo_try_unpack_be,               \
    struct fh101rf_n_spg_target* : fh101rf_n_spg_target_try_unpack_be,                             \
    struct fh101rf_rtc* : fh101rf_rtc_try_unpack_be,                                               \
    struct fh101rf_rtclg0_thresh_0* : fh101rf_rtclg0_thresh_0_try_unpack_be,                       \
    struct fh101rf_rtclg0_thresh_1* : fh101rf_rtclg0_thresh_1_try_unpack_be,                       \
    struct fh101rf_rtclg0_thresh_2* : fh101rf_rtclg0_thresh_2_try_unpack_be,                       \
    struct fh101rf_rtclg0_thresh_3* : fh101rf_rtclg0_thresh_3_try_unpack_be,                       \
    struct fh101rf_rtclg0_thresh_4* : fh101rf_rtclg0_thresh_4_try_unpack_be,                       \
    struct fh101rf_rtclg1_thresh_0* : fh101rf_rtclg1_thresh_0_try_unpack_be,                       \
    struct fh101rf_rtclg1_thresh_1* : fh101rf_rtclg1_thresh_1_try_unpack_be,                       \
    struct fh101rf_rtclg1_thresh_2* : fh101rf_rtclg1_thresh_2_try_unpack_be,                       \
    struct fh101rf_rtclg1_thresh_3* : fh101rf_rtclg1_thresh_3_try_unpack_be,                       \
    struct fh101rf_rtclg1_thresh_4* : fh101rf_rtclg1_thresh_4_try_unpack_be,                       \
    struct fh101rf_rtcsh0_thresh_hi* : fh101rf_rtcsh0_thresh_hi_try_unpack_be,                     \
    struct fh101rf_rtcsh0_thresh_lo* : fh101rf_rtcsh0_thresh_lo_try_unpack_be,                     \
    struct fh101rf_rtcsh1_thresh_hi* : fh101rf_rtcsh1_thresh_hi_try_unpack_be,                     \
    struct fh101rf_rtcsh1_thresh_lo* : fh101rf_rtcsh1_thresh_lo_try_unpack_be,                     \
    struct fh101rf_rtc_clr* : fh101rf_rtc_clr_try_unpack_be,                                       \
    struct fh101rf_rtc_select* : fh101rf_rtc_select_try_unpack_be,                                 \
    struct fh101rf_rtc_status* : fh101rf_rtc_status_try_unpack_be,                                 \
    struct fh101rf_rx_fifo_0_2g4* : fh101rf_rx_fifo_0_2g4_try_unpack_be,                           \
    struct fh101rf_rx_fifo_0_433* : fh101rf_rx_fifo_0_433_try_unpack_be,                           \
    struct fh101rf_rx_fifo_0_868* : fh101rf_rx_fifo_0_868_try_unpack_be,                           \
    struct fh101rf_rx_fifo_1_2g4* : fh101rf_rx_fifo_1_2g4_try_unpack_be,                           \
    struct fh101rf_rx_fifo_1_433* : fh101rf_rx_fifo_1_433_try_unpack_be,                           \
    struct fh101rf_rx_fifo_1_868* : fh101rf_rx_fifo_1_868_try_unpack_be,                           \
    struct fh101rf_rx_fifo_2_2g4* : fh101rf_rx_fifo_2_2g4_try_unpack_be,                           \
    struct fh101rf_rx_fifo_2_433* : fh101rf_rx_fifo_2_433_try_unpack_be,                           \
    struct fh101rf_rx_fifo_2_868* : fh101rf_rx_fifo_2_868_try_unpack_be,                           \
    struct fh101rf_rx_fifo_3_2g4* : fh101rf_rx_fifo_3_2g4_try_unpack_be,                           \
    struct fh101rf_rx_fifo_3_433* : fh101rf_rx_fifo_3_433_try_unpack_be,                           \
    struct fh101rf_rx_fifo_3_868* : fh101rf_rx_fifo_3_868_try_unpack_be,                           \
    struct fh101rf_rx_fifo_4_2g4* : fh101rf_rx_fifo_4_2g4_try_unpack_be,                           \
    struct fh101rf_rx_fifo_4_433* : fh101rf_rx_fifo_4_433_try_unpack_be,                           \
    struct fh101rf_rx_fifo_4_868* : fh101rf_rx_fifo_4_868_try_unpack_be,                           \
    struct fh101rf_rx_fifo_5_2g4* : fh101rf_rx_fifo_5_2g4_try_unpack_be,                           \
    struct fh101rf_rx_fifo_5_433* : fh101rf_rx_fifo_5_433_try_unpack_be,                           \
    struct fh101rf_rx_fifo_5_868* : fh101rf_rx_fifo_5_868_try_unpack_be,                           \
    struct fh101rf_version* : fh101rf_version_try_unpack_be,                                       \
    struct fh101rf_xtal_good* : fh101rf_xtal_good_try_unpack_be,                                   \
    struct fh101rf_xtal_osc_ctrl* : fh101rf_xtal_osc_ctrl_try_unpack_be                            \
  )(_val_, _struct_ptr_)

#endif /* REGINALD_FH101RF_REG_H */
// clang-format on
