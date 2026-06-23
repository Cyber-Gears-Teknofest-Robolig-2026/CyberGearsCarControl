#ifndef __SERVOPWMINFOS_HPP__
#define __SERVOPWMINFOS_HPP__

#include <cstdint>

namespace ServoPWMInfos {
    inline constexpr uint16_t SERVO_MIN_ANGLE = 0;
    inline constexpr uint16_t SERVO_MAX_ANGLE = 180;
    inline constexpr uint16_t SERVO_MIN_ANGLE_PULSE = 500;
    inline constexpr uint16_t SERVO_MAX_ANGLE_PULSE = 2500;
    inline constexpr int8_t SERVO_MAX_LEFT_SPEED = -((SERVO_MAX_ANGLE-SERVO_MIN_ANGLE)/2);
    inline constexpr int8_t SERVO_MAX_RIGHT_SPEED = (SERVO_MAX_ANGLE-SERVO_MIN_ANGLE)/2;
    inline constexpr int8_t SERVO_STOP_SPEED = 0;
    inline constexpr int16_t SERVO_MAX_LEFT_SPEED_PULSE = -((SERVO_MAX_ANGLE_PULSE-SERVO_MIN_ANGLE_PULSE)/2);
    inline constexpr int16_t SERVO_MAX_RIGHT_SPEED_PULSE = (SERVO_MAX_ANGLE_PULSE-SERVO_MIN_ANGLE_PULSE)/2;
    inline constexpr int16_t SERVO_STOP_SPEED_PULSE = 0;
}

#endif