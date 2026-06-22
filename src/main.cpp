#include <Arduino.h>

#include "DCMotorPins.hpp"
#include "DCMotorPWMInfos.hpp"
#include "DCMotorControl.hpp"

#include "ServoDriverI2CInfos.hpp"
#include "ServoDriverControl.hpp"

#include "RobotArmChannelInfos.hpp"
#include "RobotArmControl.hpp"

DCMotorControl dcmotors;
ServoDriverControl servoMotors;

RobotArmControl robotArm(servoMotors);

void setup(void) {
    Serial.begin(115200);
    dcmotors.begin().setSerialPrintEnable(true);
    servoMotors.begin().setSerialPrintEnable(true);
}

void loop(void) {

    servoMotors.setServo(0, 0);
    delay(1000);
    servoMotors.setServo(0, 90);
    delay(1000);
    servoMotors.setServo(0, 180);
    delay(1000);

    /*dcmotors.moveForward(dcmotors.LEFT_PWM_MAX, dcmotors.RIGHT_PWM_MAX);
    delay(1000);
    dcmotors.moveBackward(dcmotors.LEFT_PWM_MAX, dcmotors.RIGHT_PWM_MAX);
    delay(1000);
    dcmotors.turnRight(dcmotors.LEFT_PWM_MAX, dcmotors.RIGHT_PWM_MAX);
    delay(1000);
    dcmotors.turnLeft(dcmotors.LEFT_PWM_MAX, dcmotors.RIGHT_PWM_MAX);
    delay(1000);
    dcmotors.stopMotors();
    delay(1000);*/
}