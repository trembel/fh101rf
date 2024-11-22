//! Driver crate for the FH101RF Wake-Up Radio
//!
//! The driver is built on top of [`embedded-hal`], which means it is portable
//! and can be used on any platform that implements the `embedded-hal` API (also async)
//!
//! [`embedded-hal`]: https://crates.io/crates/embedded-hal
#![no_std]

#[cfg(feature = "async")]
use maybe_async::must_be_async as maybe_async_attr;
#[cfg(not(feature = "async"))]
use maybe_async::must_be_sync as maybe_async_attr;

#[cfg(not(feature = "async"))]
use embedded_hal as hal_type;
#[cfg(feature = "async")]
use embedded_hal_async as hal_type;

pub mod registers;

mod config;
pub use config::Fh101rfConfig;

mod error;
pub use error::Error;

mod device;
pub use device::{Fh101rf, LcoCalibData};
