#ifndef __DCMOTORPINS_HPP__
#define __DCMOTORPINS_HPP__

#include <Arduino.h>
#include <cstdint>

namespace DCMotorPins {
    inline constexpr uint8_t RIGHT_MOTOR_PWM_PIN = D0;
    inline constexpr uint8_t RIGHT_MOTOR_FORWARD_PIN = D4;
    inline constexpr uint8_t RIGHT_MOTOR_BACKWARD_PIN = D5;
    inline constexpr uint8_t LEFT_MOTOR_PWM_PIN = D1;
    inline constexpr uint8_t LEFT_MOTOR_FORWARD_PIN = D6;
    inline constexpr uint8_t LEFT_MOTOR_BACKWARD_PIN = D7;
}

#endif