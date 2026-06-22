#include "DCMotorControl.hpp"

DCMotorControl::DCMotorControl(
    uint8_t right_motor_pwm_pin ,
    uint8_t right_motor_forward_pin,
    uint8_t right_motor_backward_pin,
    uint8_t left_motor_pwm_pin,
    uint8_t left_motor_forward_pin,
    uint8_t left_motor_backward_pin
) {
    this->right_motor_pwm_pin = right_motor_pwm_pin;
    this->right_motor_forward_pin = right_motor_forward_pin;
    this->right_motor_backward_pin = right_motor_backward_pin;
    this->left_motor_pwm_pin = left_motor_pwm_pin;
    this->left_motor_forward_pin = left_motor_forward_pin;
    this->left_motor_backward_pin = left_motor_backward_pin;
}