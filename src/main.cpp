#include <Arduino.h>

#include "DCMotorPins.hpp"
#include "DCMotorPWMInfos.hpp"
#include "DCMotorControl.hpp"

#include "ServoDriverI2CInfos.hpp"
#include "ServoPWMInfos.hpp"
#include "ServoDriverControl.hpp"

#include "RobotArmChannelInfos.hpp"
#include "RobotArmServoTypeInfos.hpp"
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

    servoMotors.setServoAngle(0, 0);
    delay(1000);
    servoMotors.setServoAngle(0, 90);
    delay(1000);
    servoMotors.setServoAngle(0, 180);
    delay(1000);
    servoMotors.setServoSpeed(0, -90);
    delay(1000);
    servoMotors.setServoSpeed(0, 0);
    delay(1000);
    servoMotors.setServoSpeed(0, 90);
    delay(1000);

    /*dcmotors.moveForward(dcmotors.getLeftPwmMax(), dcmotors.getRightPwmMax());
    delay(1000);
    dcmotors.moveBackward(dcmotors.getLeftPwmMax(), dcmotors.getRightPwmMax());
    delay(1000);
    dcmotors.turnRight(dcmotors.getLeftPwmMax(), dcmotors.getRightPwmMax());
    delay(1000);
    dcmotors.turnLeft(dcmotors.getLeftPwmMax(), dcmotors.getRightPwmMax());
    delay(1000);
    dcmotors.stopMotors();
    delay(1000);*/
}