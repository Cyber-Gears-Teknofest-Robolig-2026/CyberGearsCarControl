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
        ZiplineMechanismControl& resetHorizontal();
        ZiplineMechanismControl& resetVertical();
        ZiplineMechanismControl& setAngle(MechanismIndex mechanism_index, uint8_t angle);
        ZiplineMechanismControl& setAngle(uint8_t mechanism_index, uint8_t angle);
        ZiplineMechanismControl& setFrontAngle(uint8_t angle);
        ZiplineMechanismControl& setBackAngle(uint8_t angle);
        ZiplineMechanismControl& setAllAngle(uint8_t front_angle, uint8_t back_angle);
        ZiplineMechanismControl& setAnglePulse(MechanismIndex mechanism_index, uint16_t pulse);
        ZiplineMechanismControl& setAnglePulse(uint8_t mechanism_index, uint16_t pulse);
        ZiplineMechanismControl& setFrontAnglePulse(uint16_t pulse);
        ZiplineMechanismControl& setBackAnglePulse(uint16_t pulse);
        ZiplineMechanismControl& setAllAnglePulse(uint16_t front_pulse, uint16_t back_pulse);
        ZiplineMechanismControl& setSerialPrintEnable(bool enable);
        bool getSerialPrintEnable(void) const;

    private:
        ServoDriverControl &servoDriver;
        uint8_t front_channel;
        uint8_t back_channel;
        int16_t front_horizontal_default_angle;
        int16_t back_horizontal_default_angle;
        int16_t front_vertical_default_angle;
        int16_t back_vertical_default_angle;
        uint8_t zipline_mechanism_channels[2];
        bool serialPrintEnable = true;
};

#endif