#include "ZiplineMechanismControl.hpp"

ZiplineMechanismControl::ZiplineMechanismControl(
    ServoDriverControl &servoDriver,
    uint8_t front_channel,
    uint8_t back_channel,
    int16_t front_horizontal_default_angle,
    int16_t back_horizontal_default_angle,
    int16_t front_vertical_default_angle,
    int16_t back_vertical_default_angle
) :
    servoDriver(servoDriver),
    front_channel(front_channel),
    back_channel(back_channel),
    front_horizontal_default_angle(front_horizontal_default_angle),
    back_horizontal_default_angle(back_horizontal_default_angle),
    front_vertical_default_angle(front_vertical_default_angle),
    back_vertical_default_angle(back_vertical_default_angle)
{
    zipline_mechanism_channels[FRONT_INDEX] = front_channel;
    zipline_mechanism_channels[BACK_INDEX] = back_channel;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetHorizontal() {
    setAngle(FRONT_INDEX, front_horizontal_default_angle);
    setAngle(BACK_INDEX, back_horizontal_default_angle);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetVertical() {
    setAngle(FRONT_INDEX, front_vertical_default_angle);
    setAngle(BACK_INDEX, back_vertical_default_angle);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAngle(MechanismIndex mechanism_index, uint8_t angle) {
    servoDriver.setServoAngle(zipline_mechanism_channels[static_cast<uint8_t>(mechanism_index)], constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAngle(uint8_t mechanism_index, uint8_t angle) {
    setAngle(static_cast<MechanismIndex>(mechanism_index), angle);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setFrontAngle(uint8_t angle) {
    setAngle(FRONT_INDEX, angle);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setBackAngle(uint8_t angle) {
    setAngle(BACK_INDEX, angle);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAllAngle(uint8_t front_angle, uint8_t back_angle) {
    setFrontAngle(front_angle);
    setBackAngle(back_angle);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAnglePulse(MechanismIndex mechanism_index, uint16_t pulse) {
    servoDriver.setServoAnglePulse(zipline_mechanism_channels[static_cast<uint8_t>(mechanism_index)], constrain(pulse, SERVO_MIN_ANGLE_PULSE, SERVO_MAX_ANGLE_PULSE));
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAnglePulse(uint8_t mechanism_index, uint16_t pulse) {
    setAnglePulse(static_cast<MechanismIndex>(mechanism_index), pulse);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setFrontAnglePulse(uint16_t pulse) {
    setAnglePulse(FRONT_INDEX, pulse);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setBackAnglePulse(uint16_t pulse) {
    setAnglePulse(BACK_INDEX, pulse);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAllAnglePulse(uint16_t front_pulse, uint16_t back_pulse) {
    setFrontAnglePulse(front_pulse);
    setBackAnglePulse(back_pulse);
    return *this;
}