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
        ServoDriverControl& setServo(uint8_t channel, uint8_t angle);
        ServoDriverControl& setServoPulse(uint8_t channel, uint16_t pulse);
        ServoDriverControl& setSerialPrintEnable(bool enable);
        bool serialPrintEnable = true;
    
    private:
        TwoWire &i2c;
        uint8_t i2c_addr;
        Adafruit_PWMServoDriver servoMotorDriver;
        const uint16_t SERVO_PWM_MIN = 500;
        const uint16_t SERVO_PWM_MAX = 2500;
};

#endif