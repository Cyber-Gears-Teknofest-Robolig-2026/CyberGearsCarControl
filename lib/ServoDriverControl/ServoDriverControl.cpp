#include "ServoDriverControl.hpp"

ServoDriverControl::ServoDriverControl(
    TwoWire &i2c,
    uint8_t i2c_addr
) : 
    i2c(i2c),
    i2c_addr(i2c_addr)
{
}
