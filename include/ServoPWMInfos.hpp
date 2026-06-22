#ifndef __SERVOPWMINFOS_HPP__
#define __SERVOPWMINFOS_HPP__

#include <cstdint>

namespace ServoPWMInfos {
    inline constexpr uint16_t R0_MIN_PULSE = 500;
    inline constexpr uint16_t R0_MAX_PULSE = 2500;
    inline constexpr uint16_t R1_MIN_PULSE = 500;
    inline constexpr uint16_t R1_MAX_PULSE = 2500;
    inline constexpr uint16_t R2_MIN_PULSE = 500;
    inline constexpr uint16_t R2_MAX_PULSE = 2500;
    inline constexpr uint16_t R3_MIN_PULSE = 500;
    inline constexpr uint16_t R3_MAX_PULSE = 2500;
    inline constexpr uint16_t R4_MIN_PULSE = 500;
    inline constexpr uint16_t R4_MAX_PULSE = 2500;
    inline constexpr uint16_t R5_MIN_PULSE = 500;
    inline constexpr uint16_t R5_MAX_PULSE = 2500;
    inline constexpr uint16_t MIN_ANGLE = 0;
    inline constexpr uint16_t MAX_ANGLE = 180;
    inline constexpr uint16_t MAX_LEFT_SPEED = -90;
    inline constexpr uint16_t MAX_RIGHT_SPEED = 90;
    inline constexpr uint16_t STOP_SPEED = 90;
}

#endif