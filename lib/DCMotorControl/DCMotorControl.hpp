#ifndef __DCMOTORCONTROL_HPP__
#define __DCMOTORCONTROL_HPP__

#include <Arduino.h>
#include <cstdint>

#include "DCMotorPins.hpp"
#include "DCMotorPWMInfos.hpp"

using namespace DCMotorPins;
using namespace DCMotorPWMInfos;

class DCMotorControl {
    
    public:
        DCMotorControl(
            uint8_t right_motor_pwm_pin = RIGHT_MOTOR_PWM_PIN,
            uint8_t right_motor_forward_pin = RIGHT_MOTOR_FORWARD_PIN,
            uint8_t right_motor_backward_pin = RIGHT_MOTOR_BACKWARD_PIN,
            uint8_t left_motor_pwm_pin = LEFT_MOTOR_PWM_PIN,
            uint8_t left_motor_forward_pin = LEFT_MOTOR_FORWARD_PIN,
            uint8_t left_motor_backward_pin = LEFT_MOTOR_BACKWARD_PIN,
            uint8_t right_motor_pwm_ch = RIGHT_MOTOR_PWM_CH,
            uint16_t right_motor_pwm_freq = RIGHT_MOTOR_PWM_FREQ,
            uint8_t right_motor_pwm_res = RIGHT_MOTOR_PWM_RES,
            uint8_t left_motor_pwm_ch = LEFT_MOTOR_PWM_CH,
            uint16_t left_motor_pwm_freq = LEFT_MOTOR_PWM_FREQ,
            uint8_t left_motor_pwm_res = LEFT_MOTOR_PWM_RES
        );
        void begin(void);
        void moveRightMotor(int16_t speed);
        void moveLeftMotor(int16_t speed);
        void moveMotors(int16_t left_speed, int16_t right_speed);
    
    private:
        uint8_t right_motor_pwm_pin;
        uint8_t right_motor_forward_pin;
        uint8_t right_motor_backward_pin;
        uint8_t left_motor_pwm_pin;
        uint8_t left_motor_forward_pin;
        uint8_t left_motor_backward_pin;
        uint8_t right_motor_pwm_ch;
        uint16_t right_motor_pwm_freq;
        uint8_t right_motor_pwm_res;
        uint8_t left_motor_pwm_ch;
        uint16_t left_motor_pwm_freq;
        uint8_t left_motor_pwm_res;
        uint16_t right_pwm_max;
        uint16_t left_pwm_max;
};

#endif