#ifndef __ZIPLINE_MECHANISM_CONTROL_HPP__
#define __ZIPLINE_MECHANISM_CONTROL_HPP__

#include <cstdint>
#include <unordered_map>

#include "ServoDriverControl.hpp"
#include "ZiplineMechanismChannelInfos.hpp"
#include "ZiplineMechanismDefaultAngles.hpp"

using namespace ZiplineMechanismChannelInfos;
using namespace ZiplineMechanismDefaultAngles;

class ZiplineMechanismControl {
    
    public:
        enum MechanismIndex {
            FRONT_INDEX = 0,
            BACK_INDEX = 1
        };
        ZiplineMechanismControl(
            ServoDriverControl &servoDriver,
            uint8_t front_channel = FRONT_CHANNEL,
            uint8_t back_channel = BACK_CHANNEL,
            int16_t front_horizontal_default_angle = FRONT_HORIZONTAL_DEFAULT_ANGLE,
            int16_t back_horizontal_default_angle = BACK_HORIZONTAL_DEFAULT_ANGLE,
            int16_t front_vertical_default_angle = FRONT_VERTICAL_DEFAULT_ANGLE,
            int16_t back_vertical_default_angle = BACK_VERTICAL_DEFAULT_ANGLE
        );
        ZiplineMechanismControl& setAngle(MechanismIndex mechanism_num, uint8_t angle);
        ZiplineMechanismControl& setAngle(uint8_t mechanism_num, uint8_t angle);
        ZiplineMechanismControl& setFrontAngle(uint8_t angle);
        ZiplineMechanismControl& setBackAngle(uint8_t angle);
        ZiplineMechanismControl& setAllAngle(uint8_t front_angle, uint8_t back_angle);
    
    private:
        ServoDriverControl &servoDriver;
        uint8_t front_channel;
        uint8_t back_channel;
        int16_t front_horizontal_default_angle;
        int16_t back_horizontal_default_angle;
        int16_t front_vertical_default_angle;
        int16_t back_vertical_default_angle;
        uint8_t zipline_mechanism_channels[2];
};

#endif