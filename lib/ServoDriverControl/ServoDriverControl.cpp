#include "ServoDriverControl.hpp"

ServoDriverControl::ServoDriverControl(
    uint8_t i2c_addr,
    TwoWire &i2c
) : 
    i2c_addr(i2c_addr),
    i2c(i2c),
    servoMotorDriver(i2c_addr, i2c)
{
}
