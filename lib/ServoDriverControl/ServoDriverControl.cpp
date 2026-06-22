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
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    servoMotorDriver.begin();
    servoMotorDriver.setOscillatorFrequency(27000000);
    servoMotorDriver.setPWMFreq(50);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("ServoDriverControl begin");
    }
    return *this;
}

ServoDriverControl& ServoDriverControl::setServoPulse(uint8_t channel, uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    servoMotorDriver.writeMicroseconds(constrain(channel, 0, 15), constrain(pulse, SERVO_PWM_MIN, SERVO_PWM_MAX));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setServoPulse: channel = ");
        Serial.print(channel);
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

ServoDriverControl& ServoDriverControl::setServo(uint8_t channel, uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    servoMotorDriver.writeMicroseconds(constrain(channel, 0, 15), map(constrain(angle, 0, 180), 0, 180, SERVO_PWM_MIN, SERVO_PWM_MAX));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setServo: channel = ");
        Serial.print(channel);
        Serial.print(", angle = ");
        Serial.println(angle);
    }
    return *this;
}

ServoDriverControl& ServoDriverControl::setSerialPrintEnable(bool enable) {
    this->serialPrintEnable = enable;
    return *this;
}