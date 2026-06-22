#ifndef __SERVODRIVERCONTROL_HPP__
#define __SERVODRIVERCONTROL_HPP__

#include <Wire.h>
#include <cstdint>
#include <Adafruit_PWMServoDriver.h>

#include "ServoDriverI2CInfos.hpp"

using namespace ServoDriverI2CInfos;

class ServoDriverControl {
    
    public:
        ServoDriverControl(
            uint8_t i2c_addr = I2C_ADDR,
            TwoWire &i2c = I2C
        );
        ServoDriverControl& begin();
    
    private:
        TwoWire &i2c;
        uint8_t i2c_addr;
        Adafruit_PWMServoDriver servoMotorDriver;
};

#endif