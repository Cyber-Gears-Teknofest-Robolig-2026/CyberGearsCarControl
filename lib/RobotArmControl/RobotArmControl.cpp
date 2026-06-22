#include "RobotArmControl.hpp"


RobotArmControl::RobotArmControl(
    ServoDriverControl &servoDriver,
    uint8_t r0_channel,
    uint8_t r1_channel,
    uint8_t r2_channel,
    uint8_t r3_channel,
    uint8_t r4_channel,
    uint8_t r5_channel
) : servoDriver(servoDriver),
    r0_channel(r0_channel),
    r1_channel(r1_channel),
    r2_channel(r2_channel),
    r3_channel(r3_channel),
    r4_channel(r4_channel),
    r5_channel(r5_channel)
{
}

RobotArmControl& RobotArmControl::setR0Angle(uint8_t angle) {
    servoDriver.setServo(r0_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR1Angle(uint8_t angle) {
    servoDriver.setServo(r1_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR2Angle(uint8_t angle) {
    servoDriver.setServo(r2_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR3Angle(uint8_t angle) {
    servoDriver.setServo(r3_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR4Angle(uint8_t angle) {
    servoDriver.setServo(r4_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR5Angle(uint8_t angle) {
    servoDriver.setServo(r5_channel, angle);
    return *this;
}