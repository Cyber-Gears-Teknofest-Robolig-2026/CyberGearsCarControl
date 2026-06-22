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

ServoDriverControl& ServoDriverControl::begin() {
    servoMotorDriver.begin();
    servoMotorDriver.setOscillatorFrequency(27000000);
    servoMotorDriver.setPWMFreq(50);
    return *this;
}

ServoDriverControl& ServoDriverControl::setServoPulse(uint8_t channel, uint16_t pulse) {
    servoMotorDriver.writeMicroseconds(constrain(channel, 0, 15), constrain(pulse, SERVO_PWM_MIN, SERVO_PWM_MAX));
    return *this;
}

ServoDriverControl& ServoDriverControl::setServo(uint8_t channel, uint8_t angle) {
    servoMotorDriver.writeMicroseconds(constrain(channel, 0, 15), map(constrain(angle, 0, 180), 0, 180, SERVO_PWM_MIN, SERVO_PWM_MAX));
    return *this;
}