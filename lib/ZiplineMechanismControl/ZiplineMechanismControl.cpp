#include "ZiplineMechanismControl.hpp"

ZiplineMechanismControl::ZiplineMechanismControl(
    ServoDriverControl &servoDriver,
    uint8_t front_channel,
    uint8_t back_channel
) :
    servoDriver(servoDriver),
    front_channel(front_channel),
    back_channel(back_channel)
{
}