#include "ServoDriverControl.hpp"

ServoDriverControl::ServoDriverControl(
    TwoWire &i2c,
    uint8_t i2c_addr
) {
    this->i2c = i2c;
    this->i2c_addr = i2c_addr;
}
