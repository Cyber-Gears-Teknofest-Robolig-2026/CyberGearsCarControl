#ifndef __SERVODRIVERCONTROL_HPP__
#define __SERVODRIVERCONTROL_HPP__

#include <Wire.h>
#include <cstdint>

#include "ServoDriverI2CInfos.hpp"

using namespace ServoDriverI2CInfos;

class ServoDriverControl {
    
    public:
        ServoDriverControl(
            TwoWire &i2c = I2C,
            uint8_t i2c_addr = I2C_ADDR
        );
    
    private:
        TwoWire &i2c;
        uint8_t i2c_addr;
};

#endif