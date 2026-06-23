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
}