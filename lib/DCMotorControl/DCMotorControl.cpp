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
) :
    right_motor_pwm_pin(right_motor_pwm_pin),
    right_motor_forward_pin(right_motor_forward_pin),
    right_motor_backward_pin(right_motor_backward_pin),
    left_motor_pwm_pin(left_motor_pwm_pin),
    left_motor_forward_pin(left_motor_forward_pin),
    left_motor_backward_pin(left_motor_backward_pin),
    right_motor_pwm_ch(right_motor_pwm_ch),
    right_motor_pwm_freq(right_motor_pwm_freq),
    right_motor_pwm_res(right_motor_pwm_res),
    left_motor_pwm_ch(left_motor_pwm_ch),
    left_motor_pwm_freq(left_motor_pwm_freq),
    left_motor_pwm_res(left_motor_pwm_res),
    RIGHT_PWM_MAX((1 << right_motor_pwm_res) - 1),
    LEFT_PWM_MAX((1 << left_motor_pwm_res) - 1)
{
}

DCMotorControl& DCMotorControl::begin(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
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
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("DCMotorControl begin");
    }
    return *this;
}

DCMotorControl& DCMotorControl::moveRightMotor(int16_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    if (constrain(speed, -RIGHT_PWM_MAX, RIGHT_PWM_MAX) > 0) {
        ledcWrite(right_motor_pwm_ch, constrain(speed, -RIGHT_PWM_MAX, RIGHT_PWM_MAX));
        digitalWrite(right_motor_forward_pin, HIGH);
        digitalWrite(right_motor_backward_pin, LOW);
    } 
    else if (constrain(speed, -RIGHT_PWM_MAX, RIGHT_PWM_MAX) < 0) {
        ledcWrite(right_motor_pwm_ch, -speed);
        digitalWrite(right_motor_forward_pin, LOW);
        digitalWrite(right_motor_backward_pin, HIGH);
    } 
    else {
        ledcWrite(right_motor_pwm_ch, 0);
        digitalWrite(right_motor_forward_pin, LOW);
        digitalWrite(right_motor_backward_pin, LOW);
    }
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("moveRightMotor: speed = ");
        Serial.println(speed);
    }
    return *this;
}

DCMotorControl& DCMotorControl::moveLeftMotor(int16_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    if (constrain(speed, -LEFT_PWM_MAX, LEFT_PWM_MAX) > 0) {
        ledcWrite(left_motor_pwm_ch, constrain(speed, -LEFT_PWM_MAX, LEFT_PWM_MAX));
        digitalWrite(left_motor_forward_pin, HIGH);
        digitalWrite(left_motor_backward_pin, LOW);
    } 
    else if (constrain(speed, -LEFT_PWM_MAX, LEFT_PWM_MAX) < 0) {
        ledcWrite(left_motor_pwm_ch, -speed);
        digitalWrite(left_motor_forward_pin, LOW);
        digitalWrite(left_motor_backward_pin, HIGH);
    } 
    else {
        ledcWrite(left_motor_pwm_ch, 0);
        digitalWrite(left_motor_forward_pin, LOW);
        digitalWrite(left_motor_backward_pin, LOW);
    }
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("moveLeftMotor: speed = ");
        Serial.println(speed);
    }
    return *this;
}

DCMotorControl& DCMotorControl::moveMotors(int16_t left_speed, int16_t right_speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    moveLeftMotor(left_speed);
    moveRightMotor(right_speed);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("moveMotors: leftSpeed = ");
        Serial.print(left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(right_speed);
    }
    return *this;
}

DCMotorControl& DCMotorControl::stopMotors(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    moveMotors(0, 0);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("stopMotors: leftSpeed = 0, rightSpeed = 0");
    }
    return *this;
}

DCMotorControl& DCMotorControl::moveForward(int16_t left_speed, int16_t right_speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    moveMotors(left_speed, right_speed);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("moveForward: leftSpeed = ");
        Serial.print(left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(right_speed);
    }
    return *this;
}

DCMotorControl& DCMotorControl::moveBackward(int16_t left_speed, int16_t right_speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    moveMotors(-left_speed, -right_speed);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("moveBackward: leftSpeed = ");
        Serial.print(-left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(-right_speed);
    }
    return *this;
}

DCMotorControl& DCMotorControl::turnRight(int16_t left_speed, int16_t right_speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    moveMotors(left_speed, -right_speed);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("turnRight: leftSpeed = ");
        Serial.print(left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(-right_speed);
    }
    return *this;
}

DCMotorControl& DCMotorControl::turnLeft(int16_t left_speed, int16_t right_speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    moveMotors(-left_speed, right_speed);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("turnLeft: leftSpeed = ");
        Serial.print(-left_speed);
        Serial.print(", rightSpeed = ");
        Serial.println(right_speed);
    }
    return *this;
}

DCMotorControl& DCMotorControl::setSerialPrintEnable(bool enable) {
    this->serialPrintEnable = enable;
    return *this;
}

uint16_t DCMotorControl::getRightPwmMin(void) const {
    return RIGHT_PWM_MIN;
}

uint16_t DCMotorControl::getLeftPwmMin(void) const {
    return LEFT_PWM_MIN;
}

uint16_t DCMotorControl::getRightPwmMax(void) const {
    return RIGHT_PWM_MAX;
}

uint16_t DCMotorControl::getLeftPwmMax(void) const {
    return LEFT_PWM_MAX;
}

bool DCMotorControl::getSerialPrintEnable(void) const {
    return serialPrintEnable;
}