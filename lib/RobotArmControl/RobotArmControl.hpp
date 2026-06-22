#ifndef __ROBOTARMCONTROL_HPP__
#define __ROBOTARMCONTROL_HPP__

#include <cstdint>

#include "ServoDriverControl.hpp"
#include "RobotArmServoTypeInfos.hpp"
#include "RobotArmChannelInfos.hpp"

using namespace RobotArmChannelInfos;
using namespace RobotArmServoTypeInfos;

class RobotArmControl {
    
    public:
        RobotArmControl(
            ServoDriverControl &servoDriver,
            uint8_t r0_channel = R0_CHANNEL,
            uint8_t r1_channel = R1_CHANNEL,
            uint8_t r2_channel = R2_CHANNEL,
            uint8_t r3_channel = R3_CHANNEL,
            uint8_t r4_channel = R4_CHANNEL,
            uint8_t r5_channel = R5_CHANNEL,
            bool r0_is360servo = R0_IS_360_SERVO,
            bool r1_is360servo = R1_IS_360_SERVO,
            bool r2_is360servo = R2_IS_360_SERVO,
            bool r3_is360servo = R3_IS_360_SERVO,
            bool r4_is360servo = R4_IS_360_SERVO,
            bool r5_is360servo = R5_IS_360_SERVO
        );
        RobotArmControl& setPulse(uint8_t r_num, uint16_t pulse);
        RobotArmControl& setR0Pulse(uint16_t pulse);
        RobotArmControl& setR1Pulse(uint16_t pulse);
        RobotArmControl& setR2Pulse(uint16_t pulse);
        RobotArmControl& setR3Pulse(uint16_t pulse);
        RobotArmControl& setR4Pulse(uint16_t pulse);
        RobotArmControl& setR5Pulse(uint16_t pulse);
        RobotArmControl& setAllPulse(
            uint16_t r0_pulse,
            uint16_t r1_pulse,
            uint16_t r2_pulse,
            uint16_t r3_pulse,
            uint16_t r4_pulse,
            uint16_t r5_pulse
        );
        RobotArmControl& setValue(uint8_t r_num, uint16_t value);
        /*RobotArmControl& setR0Angle(uint8_t angle);
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
        );*/
    
    private:
        ServoDriverControl &servoDriver;
        uint8_t r0_channel;
        uint8_t r1_channel;
        uint8_t r2_channel;
        uint8_t r3_channel;
        uint8_t r4_channel;
        uint8_t r5_channel;
        uint8_t r_channels[6];
        bool r0_is360servo;
        bool r1_is360servo;
        bool r2_is360servo;
        bool r3_is360servo;
        bool r4_is360servo;
        bool r5_is360servo;
};

#endif