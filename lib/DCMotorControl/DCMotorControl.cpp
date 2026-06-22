#include "DCMotorControl.hpp"

DCMotorControl::DCMotorControl(
    uint8_t right_motor_pwm_pin ,
    uint8_t right_motor_forward_pin,
    uint8_t right_motor_backward_pin,
    uint8_t left_motor_pwm_pin,
    uint8_t left_motor_forward_pin,
    uint8_t left_motor_backward_pin,
    uint8_t right_motor_pwm_ch,
    uint16_t right_motor_pwm_freq,
    uint8_t right_motor_pwm_res,
    uint8_t left_motor_pwm_ch,
    uint16_t left_motor_pwm_freq,
    uint8_t left_motor_pwm_res
) {
    this->right_motor_pwm_pin = right_motor_pwm_pin;
    this->right_motor_forward_pin = right_motor_forward_pin;
    this->right_motor_backward_pin = right_motor_backward_pin;
    this->left_motor_pwm_pin = left_motor_pwm_pin;
    this->left_motor_forward_pin = left_motor_forward_pin;
    this->left_motor_backward_pin = left_motor_backward_pin;
    this->right_motor_pwm_ch = right_motor_pwm_ch;
    this->right_motor_pwm_freq = right_motor_pwm_freq;
    this->right_motor_pwm_res = right_motor_pwm_res;
    this->left_motor_pwm_ch = left_motor_pwm_ch;
    this->left_motor_pwm_freq = left_motor_pwm_freq;
    this->left_motor_pwm_res = left_motor_pwm_res;
}

void DCMotorControl::begin(void) {
    pinMode(right_motor_pwm_pin, OUTPUT);
    pinMode(right_motor_forward_pin, OUTPUT);
    pinMode(right_motor_backward_pin, OUTPUT);
    pinMode(left_motor_pwm_pin, OUTPUT);
    pinMode(left_motor_forward_pin, OUTPUT);
    pinMode(left_motor_backward_pin, OUTPUT);
    ledcSetup(right_motor_pwm_ch, right_motor_pwm_freq, right_motor_pwm_res);
    ledcSetup(left_motor_pwm_ch, left_motor_pwm_freq, left_motor_pwm_res);
    ledcAttachPin(right_motor_pwm_pin, right_motor_pwm_ch);
    ledcAttachPin(left_motor_pwm_pin, left_motor_pwm_ch);
}