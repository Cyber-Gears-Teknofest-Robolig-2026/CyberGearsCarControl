#include <Arduino.h>

#include "DCMotorPins.hpp"
#include "DCMotorPWMInfos.hpp"

#include "DCMotorControl.hpp"

DCMotorControl dcmotors;

void setup(void) {
    Serial.begin(115200);
    dcmotors.begin();
}

void loop(void) {
    dcmotors.moveForward(dcmotors.LEFT_PWM_MAX, dcmotors.RIGHT_PWM_MAX);
    delay(1000);
    dcmotors.moveBackward(dcmotors.LEFT_PWM_MAX, dcmotors.RIGHT_PWM_MAX);
    delay(1000);
    dcmotors.turnRight(dcmotors.LEFT_PWM_MAX, dcmotors.RIGHT_PWM_MAX);
    delay(1000);
    dcmotors.turnLeft(dcmotors.LEFT_PWM_MAX, dcmotors.RIGHT_PWM_MAX);
    delay(1000);
    dcmotors.stopMotors();
    delay(1000);
}