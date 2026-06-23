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

ZiplineMechanismControl& ZiplineMechanismControl::setAngle(MechanismIndex mechanism_num, uint8_t angle) {
    servoDriver.setServoAngle(zipline_mechanism_channels[static_cast<uint8_t>(mechanism_num)], constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAngle(uint8_t mechanism_num, uint8_t angle) {
    setAngle(static_cast<MechanismIndex>(mechanism_num), angle);
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