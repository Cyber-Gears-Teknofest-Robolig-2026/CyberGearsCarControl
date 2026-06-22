#ifndef __DCMOTORPWMINFOS_HPP__
#define __DCMOTORPWMINFOS_HPP__

#include <cstdint>

namespace DCMotorPWMInfos {
    inline constexpr uint8_t RIGHT_MOTOR_PWM_CH = 0;
    inline constexpr uint16_t RIGHT_MOTOR_PWM_FREQ = 5000;
    inline constexpr uint8_t RIGHT_MOTOR_PWM_RES = 8;
    inline constexpr uint8_t LEFT_MOTOR_PWM_CH = 1;
    inline constexpr uint16_t LEFT_MOTOR_PWM_FREQ = 5000;
    inline constexpr uint8_t LEFT_MOTOR_PWM_RES = 8;
}

#endif