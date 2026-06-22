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
    this->RIGHT_PWM_MAX = (1 << right_motor_pwm_res) - 1;
    this->LEFT_PWM_MAX = (1 << left_motor_pwm_res) - 1;
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
    stopMotors();
}

void DCMotorControl::moveRightMotor(int16_t speed) {
    if (constrain(speed, -RIGHT_PWM_MAX, RIGHT_PWM_MAX) > 0) {
        ledcWrite(right_motor_pwm_ch, constrain(speed, -RIGHT_PWM_MAX, RIGHT_PWM_MAX));
        digitalWrite(right_motor_forward_pin, HIGH);
        digitalWrite(right_motor_backward_pin, LOW);
    } 
    else if (constrain(speed, -RIGHT_PWM_MAX, RIGHT_PWM_MAX) < 0) {
        ledcWrite(right_motor_pwm_ch, speed);
        digitalWrite(right_motor_forward_pin, LOW);
        digitalWrite(right_motor_backward_pin, HIGH);
    } 
    else {
        ledcWrite(right_motor_pwm_ch, 0);
        digitalWrite(right_motor_forward_pin, LOW);
        digitalWrite(right_motor_backward_pin, LOW);
    }
    if (serialPrintEnable) {
        Serial.print("moveRightMotor: speed = ");
        Serial.println(speed);
    }
}

void DCMotorControl::moveLeftMotor(int16_t speed) {
    if (constrain(speed, -LEFT_PWM_MAX, LEFT_PWM_MAX) > 0) {
        ledcWrite(left_motor_pwm_ch, constrain(speed, -LEFT_PWM_MAX, LEFT_PWM_MAX));
        digitalWrite(left_motor_forward_pin, HIGH);
        digitalWrite(left_motor_backward_pin, LOW);
    } 
    else if (constrain(speed, -LEFT_PWM_MAX, LEFT_PWM_MAX) < 0) {
        ledcWrite(left_motor_pwm_ch, speed);
        digitalWrite(left_motor_forward_pin, LOW);
        digitalWrite(left_motor_backward_pin, HIGH);
    } 
    else {
        ledcWrite(left_motor_pwm_ch, 0);
        digitalWrite(left_motor_forward_pin, LOW);
        digitalWrite(left_motor_backward_pin, LOW);
    }
    if (serialPrintEnable) {
        Serial.print("moveLeftMotor: speed = ");
        Serial.println(speed);
    }
}

void DCMotorControl::moveMotors(int16_t left_speed, int16_t right_speed) {
    moveLeftMotor(left_speed);
    moveRightMotor(right_speed);
    if (serialPrintEnable) {
        Serial.print("moveMotors: leftSpeed = ");
        Serial.print(left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(right_speed);
    }
}

void DCMotorControl::stopMotors(void) {
    moveMotors(0, 0);
    if (serialPrintEnable) {
        Serial.println("stopMotors: leftSpeed = 0, rightSpeed = 0");
    }
}

void DCMotorControl::moveForward(int16_t left_speed, int16_t right_speed) {
    moveMotors(left_speed, right_speed);
    if (serialPrintEnable) {
        Serial.print("moveForward: leftSpeed = ");
        Serial.print(left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(right_speed);
    }
}

void DCMotorControl::moveBackward(int16_t left_speed, int16_t right_speed) {
    moveMotors(-left_speed, -right_speed);
    if (serialPrintEnable) {
        Serial.print("moveBackward: leftSpeed = ");
        Serial.print(-left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(-right_speed);
    }
}

void DCMotorControl::turnRight(int16_t left_speed, int16_t right_speed) {
    moveMotors(left_speed, -right_speed);
    if (serialPrintEnable) {
        Serial.print("turnRight: leftSpeed = ");
        Serial.print(left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(-right_speed);
    }
}

void DCMotorControl::turnLeft(int16_t left_speed, int16_t right_speed) {
    moveMotors(-left_speed, right_speed);
    if (serialPrintEnable) {
        Serial.print("turnLeft: leftSpeed = ");
        Serial.print(-left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(right_speed);
    }
}

void DCMotorControl::setSerialPrintEnable(bool enable) {
    this->serialPrintEnable = enable;
}