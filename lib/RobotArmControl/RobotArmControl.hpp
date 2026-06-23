#ifndef __ROBOT_ARM_CONTROL_HPP__
#define __ROBOT_ARM_CONTROL_HPP__

#include <cstdint>

#include "ServoDriverControl.hpp"
#include "RobotArmServoTypeInfos.hpp"
#include "RobotArmChannelInfos.hpp"
#include "RobotArmDefaultValues.hpp"

using namespace RobotArmChannelInfos;
using namespace RobotArmServoTypeInfos;
using namespace RobotArmDefaultValues;

class RobotArmControl {

    public:
        enum class RobotArmIndex : uint8_t {
            R0_INDEX = 0,
            R1_INDEX = 1,
            R2_INDEX = 2,
            R3_INDEX = 3,
            R4_INDEX = 4,
            R5_INDEX = 5
        };
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
            bool r5_is360servo = R5_IS_360_SERVO,
            int16_t r0_default_value = R0_DEFAULT_VALUE,
            int16_t r1_default_value = R1_DEFAULT_VALUE,
            int16_t r2_default_value = R2_DEFAULT_VALUE,
            int16_t r3_default_value = R3_DEFAULT_VALUE,
            int16_t r4_default_value = R4_DEFAULT_VALUE,
            int16_t r5_default_value = R5_DEFAULT_VALUE
        );
        RobotArmControl& reset();
        RobotArmControl& setAngle(RobotArmIndex r_index, uint8_t angle);
        RobotArmControl& setAngle(uint8_t r_index, uint8_t angle);
        RobotArmControl& setR0Angle(uint8_t angle);
        RobotArmControl& setR1Angle(uint8_t angle);
        RobotArmControl& setR2Angle(uint8_t angle);
        RobotArmControl& setR3Angle(uint8_t angle);
        RobotArmControl& setR4Angle(uint8_t angle);
        RobotArmControl& setR5Angle(uint8_t angle);
        RobotArmControl& setAllAngle(uint8_t r0_angle, uint8_t r1_angle, uint8_t r2_angle, uint8_t r3_angle, uint8_t r4_angle, uint8_t r5_angle);
        RobotArmControl& setAnglePulse(RobotArmIndex r_index, uint16_t pulse);
        RobotArmControl& setAnglePulse(uint8_t r_index, uint16_t pulse);
        RobotArmControl& setR0AnglePulse(uint16_t pulse);
        RobotArmControl& setR1AnglePulse(uint16_t pulse);
        RobotArmControl& setR2AnglePulse(uint16_t pulse);
        RobotArmControl& setR3AnglePulse(uint16_t pulse);
        RobotArmControl& setR4AnglePulse(uint16_t pulse);
        RobotArmControl& setR5AnglePulse(uint16_t pulse);
        RobotArmControl& setAllAnglePulse(uint16_t r0_pulse, uint16_t r1_pulse, uint16_t r2_pulse, uint16_t r3_pulse, uint16_t r4_pulse, uint16_t r5_pulse);
        RobotArmControl& setSpeed(RobotArmIndex r_index, int8_t speed);
        RobotArmControl& setSpeed(uint8_t r_num, int8_t speed);
        RobotArmControl& setR0Speed(int8_t speed);
        RobotArmControl& setR1Speed(int8_t speed);
        RobotArmControl& setR2Speed(int8_t speed);
        RobotArmControl& setR3Speed(int8_t speed);
        RobotArmControl& setR4Speed(int8_t speed);
        RobotArmControl& setR5Speed(int8_t speed);
        RobotArmControl& setAllSpeed(int8_t r0_speed, int8_t r1_speed, int8_t r2_speed, int8_t r3_speed, int8_t r4_speed, int8_t r5_speed);
        RobotArmControl& setSpeedPulse(RobotArmIndex r_index, int16_t pulse);
        RobotArmControl& setSpeedPulse(uint8_t r_num, int16_t pulse);
        RobotArmControl& setR0SpeedPulse(int16_t pulse);
        RobotArmControl& setR1SpeedPulse(int16_t pulse);
        RobotArmControl& setR2SpeedPulse(int16_t pulse);
        RobotArmControl& setR3SpeedPulse(int16_t pulse);
        RobotArmControl& setR4SpeedPulse(int16_t pulse);
        RobotArmControl& setR5SpeedPulse(int16_t pulse);
        RobotArmControl& setAllSpeedPulse(int16_t r0_pulse, int16_t r1_pulse, int16_t r2_pulse, int16_t r3_pulse, int16_t r4_pulse, int16_t r5_pulse);
        RobotArmControl& setValue(uint8_t r_num, int16_t value);
        RobotArmControl& setR0Value(int16_t value);
        RobotArmControl& setR1Value(int16_t value);
        RobotArmControl& setR2Value(int16_t value);
        RobotArmControl& setR3Value(int16_t value);
        RobotArmControl& setR4Value(int16_t value);
        RobotArmControl& setR5Value(int16_t value);
        RobotArmControl& setAllValue(int16_t r0_value, int16_t r1_value, int16_t r2_value, int16_t r3_value, int16_t r4_value, int16_t r5_value);
        RobotArmControl& setValuePulse(uint8_t r_num, int16_t pulse);
        RobotArmControl& setR0ValuePulse(int16_t pulse);
        RobotArmControl& setR1ValuePulse(int16_t pulse);
        RobotArmControl& setR2ValuePulse(int16_t pulse);
        RobotArmControl& setR3ValuePulse(int16_t pulse);
        RobotArmControl& setR4ValuePulse(int16_t pulse);
        RobotArmControl& setR5ValuePulse(int16_t pulse);
        RobotArmControl& setAllValuePulse(int16_t r0_pulse, int16_t r1_pulse, int16_t r2_pulse, int16_t r3_pulse, int16_t r4_pulse, int16_t r5_pulse);
        RobotArmControl& setSerialPrintEnable(bool enable);
        bool getSerialPrintEnable(void) const;

    private:
        ServoDriverControl &servoDriver;
        uint8_t r0_channel;
        uint8_t r1_channel;
        uint8_t r2_channel;
        uint8_t r3_channel;
        uint8_t r4_channel;
        uint8_t r5_channel;
        bool r0_is360servo;
        bool r1_is360servo;
        bool r2_is360servo;
        bool r3_is360servo;
        bool r4_is360servo;
        bool r5_is360servo;
        int16_t r0_default_value;
        int16_t r1_default_value;
        int16_t r2_default_value;
        int16_t r3_default_value;
        int16_t r4_default_value;
        int16_t r5_default_value;
        uint8_t r_channels[6];
        bool is360Servos[6];
        bool serialPrintEnable = true;
};

#endif