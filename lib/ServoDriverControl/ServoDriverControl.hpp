#ifndef __SERVO_DRIVER_CONTROL_HPP__
#define __SERVO_DRIVER_CONTROL_HPP__

#include <Wire.h>
#include <cstdint>
#include <Adafruit_PWMServoDriver.h>

#include "ServoDriverI2CInfos.hpp"
#include "ServoPWMInfos.hpp"

using namespace ServoDriverI2CInfos;
using namespace ServoPWMInfos;

class ServoDriverControl {
    
    public:
        ServoDriverControl(
            uint8_t i2c_addr = I2C_ADDR,
            TwoWire &i2c = I2C
        );
        ServoDriverControl& begin();
        ServoDriverControl& releaseServo(uint8_t channel);
        ServoDriverControl& setServoAngle(uint8_t channel, uint8_t angle);
        ServoDriverControl& setServoAnglePulse(uint8_t channel, uint16_t pulse);
        ServoDriverControl& setServoSpeed(uint8_t channel, int8_t speed);
        ServoDriverControl& setServoSpeedPulse(uint8_t channel, int16_t pulse);
        ServoDriverControl& setSerialPrintEnable(bool enable);
        bool getSerialPrintEnable(void) const;
    
    private:
        TwoWire &i2c;
        uint8_t i2c_addr;
        Adafruit_PWMServoDriver servoMotorDriver;
        bool serialPrintEnable = true;
};

#endif