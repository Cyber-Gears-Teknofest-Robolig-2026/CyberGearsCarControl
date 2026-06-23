#ifndef __ZIPLINE_MECHANISM_CONTROL_HPP__
#define __ZIPLINE_MECHANISM_CONTROL_HPP__

#include <cstdint>

#include "ServoDriverControl.hpp"
#include "ZiplineMechanismChannelInfos.hpp"
#include "ZiplineMechanismDefaultAngles.hpp"

using namespace ZiplineMechanismChannelInfos;
using namespace ZiplineMechanismDefaultAngles;

class ZiplineMechanismControl {
    
    public:
        ZiplineMechanismControl(
            ServoDriverControl &servoDriver,
            uint8_t front_channel = FRONT_CHANNEL,
            uint8_t back_channel = BACK_CHANNEL,
            int16_t front_horizontal_default_angle = FRONT_HORIZONTAL_DEFAULT_ANGLE,
            int16_t back_horizontal_default_angle = BACK_HORIZONTAL_DEFAULT_ANGLE,
            int16_t front_vertical_default_angle = FRONT_VERTICAL_DEFAULT_ANGLE,
            int16_t back_vertical_default_angle = BACK_VERTICAL_DEFAULT_ANGLE
        );
    
    private:
        ServoDriverControl &servoDriver;
        uint8_t front_channel;
        uint8_t back_channel;
        int16_t front_horizontal_default_angle;
        int16_t back_horizontal_default_angle;
        int16_t front_vertical_default_angle;
        int16_t back_vertical_default_angle;
};

#endif