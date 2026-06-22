#ifndef __SERVODRIVERI2CINPOS_HPP__
#define __SERVODRIVERI2CINPOS_HPP__

#include <Wire.h>
#include <cstdint>

namespace ServoDriverI2CInfos {
    inline constexpr uint8_t I2C_ADDR   = 0x40;
    inline constexpr TwoWire& I2C       = Wire;
}

#endif