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

RobotArmControl& RobotArmControl::setAngle(uint8_t r_num, uint8_t angle) {
    servoDriver.setServoAngle(r_channels[constrain(r_num, 0, 5)], constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    return *this;
}

RobotArmControl& RobotArmControl::setR0Angle(uint8_t angle) {
    setAngle(0, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    return *this;
}

RobotArmControl& RobotArmControl::setR1Angle(uint8_t angle) {
    setAngle(1, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    return *this;
}

RobotArmControl& RobotArmControl::setR2Angle(uint8_t angle) {
    setAngle(2, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    return *this;
}

RobotArmControl& RobotArmControl::setR3Angle(uint8_t angle) {
    setAngle(3, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    return *this;
}

RobotArmControl& RobotArmControl::setR4Angle(uint8_t angle) {
    setAngle(4, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    return *this;
}

RobotArmControl& RobotArmControl::setR5Angle(uint8_t angle) {
    setAngle(5, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
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

RobotArmControl& RobotArmControl::setAnglePulse(uint8_t r_num, uint16_t pulse) {
    servoDriver.setServoAnglePulse(r_channels[constrain(r_num, 0, 5)], constrain(pulse, SERVO_MIN_ANGLE_PULSE, SERVO_MAX_ANGLE_PULSE));
    return *this;
}

RobotArmControl& RobotArmControl::setR0AnglePulse(uint16_t pulse) {
    setAnglePulse(0, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR1AnglePulse(uint16_t pulse) {
    setAnglePulse(1, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR2AnglePulse(uint16_t pulse) {
    setAnglePulse(2, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR3AnglePulse(uint16_t pulse) {
    setAnglePulse(3, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR4AnglePulse(uint16_t pulse) {
    setAnglePulse(4, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR5AnglePulse(uint16_t pulse) {
    setAnglePulse(5, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setAllAnglePulse(uint16_t r0_pulse, uint16_t r1_pulse, uint16_t r2_pulse, uint16_t r3_pulse, uint16_t r4_pulse, uint16_t r5_pulse) {
    setR0AnglePulse(r0_pulse);
    setR1AnglePulse(r1_pulse);
    setR2AnglePulse(r2_pulse);
    setR3AnglePulse(r3_pulse);
    setR4AnglePulse(r4_pulse);
    setR5AnglePulse(r5_pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setSpeed(uint8_t r_num, int8_t speed) {
    servoDriver.setServoSpeed(r_channels[constrain(r_num, 0, 5)], constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    return *this;
}

RobotArmControl& RobotArmControl::setR0Speed(int8_t speed) {
    setSpeed(0, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    return *this;
}

RobotArmControl& RobotArmControl::setR1Speed(int8_t speed) {
    setSpeed(1, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    return *this;
}

RobotArmControl& RobotArmControl::setR2Speed(int8_t speed) {
    setSpeed(2, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    return *this;
}

RobotArmControl& RobotArmControl::setR3Speed(int8_t speed) {
    setSpeed(3, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    return *this;
}

RobotArmControl& RobotArmControl::setR4Speed(int8_t speed) {
    setSpeed(4, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    return *this;
}

RobotArmControl& RobotArmControl::setR5Speed(int8_t speed) {
    setSpeed(5, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    return *this;
}

RobotArmControl& RobotArmControl::setAllSpeed(int8_t r0_speed, int8_t r1_speed, int8_t r2_speed, int8_t r3_speed, int8_t r4_speed, int8_t r5_speed) {
    setR0Speed(r0_speed);
    setR1Speed(r1_speed);
    setR2Speed(r2_speed);
    setR3Speed(r3_speed);
    setR4Speed(r4_speed);
    setR5Speed(r5_speed);
    return *this;
}

RobotArmControl& RobotArmControl::setSpeedPulse(uint8_t r_num, int16_t pulse) {
    servoDriver.setServoSpeedPulse(r_channels[constrain(r_num, 0, 5)], constrain(pulse, SERVO_MAX_LEFT_SPEED_PULSE, SERVO_MAX_RIGHT_SPEED_PULSE));
    return *this;
}

RobotArmControl& RobotArmControl::setR0SpeedPulse(int16_t pulse) {
    setSpeedPulse(0, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR1SpeedPulse(int16_t pulse) {
    setSpeedPulse(1, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR2SpeedPulse(int16_t pulse) {
    setSpeedPulse(2, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR3SpeedPulse(int16_t pulse) {
    setSpeedPulse(3, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR4SpeedPulse(int16_t pulse) {
    setSpeedPulse(4, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR5SpeedPulse(int16_t pulse) {
    setSpeedPulse(5, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setAllSpeedPulse(int16_t r0_pulse, int16_t r1_pulse, int16_t r2_pulse, int16_t r3_pulse, int16_t r4_pulse, int16_t r5_pulse) {
    setR0SpeedPulse(r0_pulse);
    setR1SpeedPulse(r1_pulse);
    setR2SpeedPulse(r2_pulse);
    setR3SpeedPulse(r3_pulse);
    setR4SpeedPulse(r4_pulse);
    setR5SpeedPulse(r5_pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setValue(uint8_t r_num, int16_t value) {
    if (not is360Servos[constrain(r_num, 0, 5)]) {
        setAngle(constrain(r_num, 0, 5), constrain(value, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    }
    else {
        setSpeed(constrain(r_num, 0, 5), constrain(value, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR0Value(int16_t value) {
    setValue(0, value);
    return *this;
}

RobotArmControl& RobotArmControl::setR1Value(int16_t value) {
    setValue(1, value);
    return *this;
}

RobotArmControl& RobotArmControl::setR2Value(int16_t value) {
    setValue(2, value);
    return *this;
}

RobotArmControl& RobotArmControl::setR3Value(int16_t value) {
    setValue(3, value);
    return *this;
}

RobotArmControl& RobotArmControl::setR4Value(int16_t value) {
    setValue(4, value);
    return *this;
}

RobotArmControl& RobotArmControl::setR5Value(int16_t value) {
    setValue(5, value);
    return *this;
}

RobotArmControl& RobotArmControl::setAllValue(int16_t r0_value, int16_t r1_value, int16_t r2_value, int16_t r3_value, int16_t r4_value, int16_t r5_value) {
    setR0Value(r0_value);
    setR1Value(r1_value);
    setR2Value(r2_value);
    setR3Value(r3_value);
    setR4Value(r4_value);
    setR5Value(r5_value);
    return *this;
}

RobotArmControl& RobotArmControl::setValuePulse(uint8_t r_num, int16_t pulse) {
    if (not is360Servos[constrain(r_num, 0, 5)]) {
        setAnglePulse(constrain(r_num, 0, 5), constrain(pulse, SERVO_MIN_ANGLE_PULSE, SERVO_MAX_ANGLE_PULSE));
    }
    else {
        setSpeedPulse(constrain(r_num, 0, 5), constrain(pulse, SERVO_MAX_LEFT_SPEED_PULSE, SERVO_MAX_RIGHT_SPEED_PULSE));
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR0ValuePulse(int16_t pulse) {
    setValuePulse(0, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR1ValuePulse(int16_t pulse) {
    setValuePulse(1, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR2ValuePulse(int16_t pulse) {
    setValuePulse(2, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR3ValuePulse(int16_t pulse) {
    setValuePulse(3, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR4ValuePulse(int16_t pulse) {
    setValuePulse(4, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setR5ValuePulse(int16_t pulse) {
    setValuePulse(5, pulse);
    return *this;
}

RobotArmControl& RobotArmControl::setAllValuePulse(int16_t r0_pulse, int16_t r1_pulse, int16_t r2_pulse, int16_t r3_pulse, int16_t r4_pulse, int16_t r5_pulse) {
    setR0ValuePulse(r0_pulse);
    setR1ValuePulse(r1_pulse);
    setR2ValuePulse(r2_pulse);
    setR3ValuePulse(r3_pulse);
    setR4ValuePulse(r4_pulse);
    setR5ValuePulse(r5_pulse);
    return *this;
}