#ifndef __SERVO_DRIVER_I2C_INFOS_HPP__
#define __SERVO_DRIVER_I2C_INFOS_HPP__

#include <Wire.h>
#include <cstdint>

namespace ServoDriverI2CInfos {
    inline constexpr uint8_t I2C_ADDR   = 0x40;
    inline constexpr TwoWire& I2C       = Wire;
}

#endif