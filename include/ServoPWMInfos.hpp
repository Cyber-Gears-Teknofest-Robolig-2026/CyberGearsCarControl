#ifndef __SERVOPWMINFOS_HPP__
#define __SERVOPWMINFOS_HPP__

#include <cstdint>

namespace ServoPWMInfos {
    inline constexpr uint16_t MIN_ANGLE = 0;
    inline constexpr uint16_t MAX_ANGLE = 180;
    inline constexpr uint16_t MIN_ANGLE_PULSE = 500;
    inline constexpr uint16_t MAX_ANGLE_PULSE = 2500;
    inline constexpr int8_t MAX_LEFT_SPEED = -((MAX_ANGLE-MIN_ANGLE)/2);
    inline constexpr int8_t MAX_RIGHT_SPEED = (MAX_ANGLE-MIN_ANGLE)/2;
    inline constexpr int8_t STOP_SPEED = 0;
    inline constexpr int16_t MAX_LEFT_SPEED_PULSE = -((MAX_ANGLE_PULSE-MIN_ANGLE_PULSE)/2);
    inline constexpr int16_t MAX_RIGHT_SPEED_PULSE = (MAX_ANGLE_PULSE-MIN_ANGLE_PULSE)/2;
    inline constexpr int16_t STOP_SPEED_PULSE = 0;
}

#endif