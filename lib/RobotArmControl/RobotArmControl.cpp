#include "RobotArmControl.hpp"


RobotArmControl::RobotArmControl(
    ServoDriverControl &servoDriver,
    uint8_t r0_channel,
    uint8_t r1_channel,
    uint8_t r2_channel,
    uint8_t r3_channel,
    uint8_t r4_channel,
    uint8_t r5_channel,
    bool r0_is360servo,
    bool r1_is360servo,
    bool r2_is360servo,
    bool r3_is360servo,
    bool r4_is360servo,
    bool r5_is360servo
) : 
    servoDriver(servoDriver),
    r0_channel(r0_channel),
    r1_channel(r1_channel),
    r2_channel(r2_channel),
    r3_channel(r3_channel),
    r4_channel(r4_channel),
    r5_channel(r5_channel),
    r0_is360servo(r0_is360servo),
    r1_is360servo(r1_is360servo),
    r2_is360servo(r2_is360servo),
    r3_is360servo(r3_is360servo),
    r4_is360servo(r4_is360servo),
    r5_is360servo(r5_is360servo)
{
    r_channels[0] = r0_channel;
    r_channels[1] = r1_channel;
    r_channels[2] = r2_channel;
    r_channels[3] = r3_channel;
    r_channels[4] = r4_channel;
    r_channels[5] = r5_channel;
    is360Servos[0] = r0_is360servo;
    is360Servos[1] = r1_is360servo;
    is360Servos[2] = r2_is360servo;
    is360Servos[3] = r3_is360servo;
    is360Servos[4] = r4_is360servo;
    is360Servos[5] = r5_is360servo;
}

RobotArmControl& RobotArmControl::setValue(uint8_t r_num, uint16_t value) {
    if (not is360Servos[constrain(r_num, 0, 5)]) {
        servoDriver.setServoAngle(r_channels[constrain(r_num, 0, 5)], constrain(value, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    }
    else {
        servoDriver.setServoSpeed(r_channels[constrain(r_num, 0, 5)], constrain(value, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    }
    return *this;
}

/*RobotArmControl& RobotArmControl::setPulse(uint8_t r_num, uint16_t pulse) {
    servoDriver.setServoAnglePulse(r_channels[constrain(r_num, 0, 5)], constrain(pulse, 500, 2500));
    return *this;
}

RobotArmControl& RobotArmControl::setR0Pulse(uint16_t pulse) {
    servoDriver.setServoAnglePulse(r0_channel, constrain(pulse, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR1Pulse(uint16_t pulse) {
    servoDriver.setServoAnglePulse(r1_channel, constrain(pulse, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR2Pulse(uint16_t pulse) {
    servoDriver.setServoAnglePulse(r2_channel, constrain(pulse, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR3Pulse(uint16_t pulse) {
    servoDriver.setServoAnglePulse(r3_channel, constrain(pulse, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR4Pulse(uint16_t pulse) {
    servoDriver.setServoAnglePulse(r4_channel, constrain(pulse, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR5Pulse(uint16_t pulse) {
    servoDriver.setServoAnglePulse(r5_channel, constrain(pulse, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setAllPulse(uint16_t r0_pulse, uint16_t r1_pulse, uint16_t r2_pulse, uint16_t r3_pulse, uint16_t r4_pulse, uint16_t r5_pulse) {
    setR0Pulse(constrain(r0_pulse, 0, 180));
    setR1Pulse(constrain(r1_pulse, 0, 180));
    setR2Pulse(constrain(r2_pulse, 0, 180));
    setR3Pulse(constrain(r3_pulse, 0, 180));
    setR4Pulse(constrain(r4_pulse, 0, 180));
    setR5Pulse(constrain(r5_pulse, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setValue(uint8_t r_num, uint16_t value) {
    return *this;
}*/

/////////////////////////////////////////////////////////////////////

/*RobotArmControl& RobotArmControl::setR0Angle(uint8_t angle) {
    servoDriver.setServoAngle(r0_channel, constrain(angle, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR1Angle(uint8_t angle) {
    servoDriver.setServoAngle(r1_channel, constrain(angle, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR2Angle(uint8_t angle) {
    servoDriver.setServoAngle(r2_channel, constrain(angle, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR3Angle(uint8_t angle) {
    servoDriver.setServoAngle(r3_channel, constrain(angle, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR4Angle(uint8_t angle) {
    servoDriver.setServoAngle(r4_channel, constrain(angle, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setR5Angle(uint8_t angle) {
    servoDriver.setServoAngle(r5_channel, constrain(angle, 0, 180));
    return *this;
}

RobotArmControl& RobotArmControl::setAllAngle(uint8_t r0_angle, uint8_t r1_angle, uint8_t r2_angle, uint8_t r3_angle, uint8_t r4_angle, uint8_t r5_angle) {
    setR0Angle(constrain(r0_angle, 0, 180));
    setR1Angle(constrain(r1_angle, 0, 180));
    setR2Angle(constrain(r2_angle, 0, 180));
    setR3Angle(constrain(r3_angle, 0, 180));
    setR4Angle(constrain(r4_angle, 0, 180));
    setR5Angle(constrain(r5_angle, 0, 180));
    return *this;
}*/