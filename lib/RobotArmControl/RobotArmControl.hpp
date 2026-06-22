#ifndef __ROBOTARMCONTROL_HPP__
#define __ROBOTARMCONTROL_HPP__

#include <cstdint>

#include "ServoDriverControl.hpp"
#include "RobotArmChannelInfos.hpp"

using namespace RobotArmChannelInfos;

class RobotArmControl {
    
    public:
        RobotArmControl(
            ServoDriverControl &servoDriver,
            uint8_t r0_channel = R0_CHANNEL,
            uint8_t r1_channel = R1_CHANNEL,
            uint8_t r2_channel = R2_CHANNEL,
            uint8_t r3_channel = R3_CHANNEL,
            uint8_t r4_channel = R4_CHANNEL,
            uint8_t r5_channel = R5_CHANNEL
        );
        RobotArmControl& setR0Angle(uint8_t angle);
        RobotArmControl& setR1Angle(uint8_t angle);
        RobotArmControl& setR2Angle(uint8_t angle);
        RobotArmControl& setR3Angle(uint8_t angle);
        RobotArmControl& setR4Angle(uint8_t angle);
        RobotArmControl& setR5Angle(uint8_t angle);
        RobotArmControl& setAllAngle(
            uint8_t r0_angle,
            uint8_t r1_angle,
            uint8_t r2_angle,
            uint8_t r3_angle,
            uint8_t r4_angle,
            uint8_t r5_angle
        );
    
    private:
        ServoDriverControl &servoDriver;
        uint8_t r0_channel;
        uint8_t r1_channel;
        uint8_t r2_channel;
        uint8_t r3_channel;
        uint8_t r4_channel;
        uint8_t r5_channel;
};

#endif