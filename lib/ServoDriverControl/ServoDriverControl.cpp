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

ServoDriverControl& ServoDriverControl::setServoAngle(uint8_t channel, uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    servoMotorDriver.writeMicroseconds(constrain(channel, 0, 15), map(constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE), SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_ANGLE_PULSE, SERVO_MAX_ANGLE_PULSE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setServoAngle: channel = ");
        Serial.print(channel);
        Serial.print(", angle = ");
        Serial.println(angle);
    }
    return *this;
}

ServoDriverControl& ServoDriverControl::setServoAnglePulse(uint8_t channel, uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    servoMotorDriver.writeMicroseconds(constrain(channel, 0, 15), constrain(pulse, SERVO_MIN_ANGLE_PULSE, SERVO_MAX_ANGLE_PULSE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setServoAnglePulse: channel = ");
        Serial.print(channel);
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

ServoDriverControl& ServoDriverControl::setServoSpeed(uint8_t channel, int8_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    servoMotorDriver.writeMicroseconds(constrain(channel, 0, 15), map(constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED), SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED, SERVO_MAX_LEFT_SPEED_PULSE, SERVO_MAX_RIGHT_SPEED_PULSE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setServoSpeed: channel = ");
        Serial.print(channel);
        Serial.print(", speed = ");
        Serial.println(speed);
    }
    return *this;
}

ServoDriverControl& ServoDriverControl::setServoSpeedPulse(uint8_t channel, int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    servoMotorDriver.writeMicroseconds(constrain(channel, 0, 15), constrain(pulse, SERVO_MIN_ANGLE_PULSE, SERVO_MAX_ANGLE_PULSE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setServoSpeedPulse: channel = ");
        Serial.print(channel);
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

ServoDriverControl& ServoDriverControl::setSerialPrintEnable(bool enable) {
    this->serialPrintEnable = enable;
    return *this;
}