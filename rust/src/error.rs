use crate::hal_type;
use core::fmt::{self, Display, Formatter};

/// Errors that can occur when using the FH101RF
pub enum Error<SPI>
where
    SPI: hal_type::spi::ErrorType,
{
    /// SPI error occured during a communication transaction
    Communication(SPI::Error),
    /// Wrong configuration error
    Config(&'static str),
    /// No data available
    NoData,
    /// GPIO error
    Gpio,
    /// Value does not exist
    Value(&'static str),
    /// Generic FH101RF error
    Generic,
}

impl<SPI> Display for Error<SPI>
where
    SPI: hal_type::spi::ErrorType,
    SPI::Error: core::fmt::Debug,
{
    fn fmt(&self, f: &mut Formatter<'_>) -> core::fmt::Result {
        write!(f, "{:?}", self)
    }
}

// We can't derive this implementation, as the compiler will complain that the
// associated error type doesn't implement `Debug`.
impl<SPI> fmt::Debug for Error<SPI>
where
    SPI: hal_type::spi::ErrorType,
    SPI::Error: fmt::Debug,
{
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Error::Communication(error) => write!(f, "Communication error ({:?})", error),
            Error::Config(s) => write!(f, "Configuration error ({:?})", s),
            Error::NoData => write!(f, "No Data available error"),
            Error::Gpio => write!(f, "Gpio error"),
            Error::Value(s) => write!(f, "Value error ({:?})", s),
            Error::Generic => write!(f, "Generic error"),
        }
    }
}

#[cfg(feature = "defmt")]
impl<SPI> defmt::Format for Error<SPI>
where
    SPI: hal_type::spi::SpiDevice<u8>,
{
    fn format(&self, f: defmt::Formatter) {
        match self {
            Error::Communication(_) => defmt::write!(f, "Communication error"),
            Error::Config(s) => defmt::write!(f, "Configuration error ({:?})", s),
            Error::NoData => defmt::write!(f, "No Data available error"),
            Error::Gpio => defmt::write!(f, "Gpio error"),
            Error::Value(s) => defmt::write!(f, "Value error ({:?})", s),
            Error::Generic => defmt::write!(f, "Generic error"),
        }
    }
}
