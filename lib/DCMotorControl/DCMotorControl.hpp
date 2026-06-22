#ifndef __DCMOTORCONTROL_HPP__
#define __DCMOTORCONTROL_HPP__

#include <cstdint>
#include "DCMotorPins.hpp"

using namespace DCMotorPins;

class DCMotorControl {
    
    public:
        DCMotorControl(
            uint8_t right_motor_pwm_pin = RIGHT_MOTOR_PWM_PIN,
            uint8_t right_motor_forward_pin = RIGHT_MOTOR_FORWARD_PIN,
            uint8_t right_motor_backward_pin = RIGHT_MOTOR_BACKWARD_PIN,
            uint8_t left_motor_pwm_pin = LEFT_MOTOR_PWM_PIN,
            uint8_t left_motor_forward_pin = LEFT_MOTOR_FORWARD_PIN,
            uint8_t left_motor_backward_pin = LEFT_MOTOR_BACKWARD_PIN
        );
        void begin(void);
    
    private:
        uint8_t right_motor_pwm_pin;
        uint8_t right_motor_forward_pin;
        uint8_t right_motor_backward_pin;
        uint8_t left_motor_pwm_pin;
        uint8_t left_motor_forward_pin;
        uint8_t left_motor_backward_pin;
};

#endif