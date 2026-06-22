#include "RobotArmControl.hpp"


RobotArmControl::RobotArmControl(
    ServoDriverControl &servoDriver,
    uint8_t r0_channel,
    uint8_t r1_channel,
    uint8_t r2_channel,
    uint8_t r3_channel,
    uint8_t r4_channel,
    uint8_t r5_channel
) : 
    servoDriver(servoDriver),
    r0_channel(r0_channel),
    r1_channel(r1_channel),
    r2_channel(r2_channel),
    r3_channel(r3_channel),
    r4_channel(r4_channel),
    r5_channel(r5_channel)
{
}

RobotArmControl& RobotArmControl::setR0Angle(uint8_t angle) {
    servoDriver.setServoAngle(r0_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR1Angle(uint8_t angle) {
    servoDriver.setServoAngle(r1_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR2Angle(uint8_t angle) {
    servoDriver.setServoAngle(r2_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR3Angle(uint8_t angle) {
    servoDriver.setServoAngle(r3_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR4Angle(uint8_t angle) {
    servoDriver.setServoAngle(r4_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setR5Angle(uint8_t angle) {
    servoDriver.setServoAngle(r5_channel, angle);
    return *this;
}

RobotArmControl& RobotArmControl::setAllAngle(uint8_t r0_angle, uint8_t r1_angle, uint8_t r2_angle, uint8_t r3_angle, uint8_t r4_angle, uint8_t r5_angle) {
    setR0Angle(r0_angle);
    setR1Angle(r1_angle);
    setR2Angle(r2_angle);
    setR3Angle(r3_angle);
    setR4Angle(r4_angle);
    setR5Angle(r5_angle);
    return *this;
}