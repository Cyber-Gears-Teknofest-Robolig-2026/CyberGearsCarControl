#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

//#include "DCMotorPins.hpp"
//#include "DCMotorPWMInfos.hpp"
#include "DCMotorControl.hpp"

//#include "ServoDriverI2CInfos.hpp"
//#include "ServoPWMInfos.hpp"
#include "ServoDriverControl.hpp"

//#include "RobotArmChannelInfos.hpp"
//#include "RobotArmServoTypeInfos.hpp"
//#include "RobotArmDefaultValues.hpp"
#include "RobotArmControl.hpp"

//#include "ZiplineMechanismChannelInfos.hpp"
//#include "ZiplineMechanismDefaultAngles.hpp"
#include "ZiplineMechanismControl.hpp"

#include "BTClassicInfos.hpp"
#include "BLEInfos.hpp"
#include "CarControlBTValues.hpp"

DCMotorControl dcmotors;
ServoDriverControl servoMotors;
RobotArmControl robotArm(servoMotors);
ZiplineMechanismControl ziplineMechanism(servoMotors);

BLECharacteristic* bleTxCharacteristic;
BLECharacteristic* bleRxCharacteristic;

// --BT Classic--

void onBTClassicDataReceived(String message) {
    Serial.print("BT Classic Message: ");
    Serial.println(message);
    String command = message.substring(0, message.indexOf(':'));
    String value = message.substring(message.indexOf(':') + 1);
    Serial.println(command);
    Serial.println(value);
    if (command == BT_MOTOR_RIGHT) {
        dcmotors.moveRightMotor(value.toInt());
    }
    else if (command == BT_MOTOR_LEFT) {
        dcmotors.moveLeftMotor(value.toInt());
    }
    else if (command == BT_MOTORS_ALL) {
        int firstComma  = value.indexOf(',');
        String rightSpeedStr = value.substring(0, firstComma);
        String leftSpeedStr = value.substring(firstComma + 1);
        int16_t rightSpeed = rightSpeedStr.toInt();
        int16_t leftSpeed = leftSpeedStr.toInt();
        dcmotors.moveMotors(leftSpeed, rightSpeed);
    }
    else if (command == BT_ROBOT_ARM_R0) {
        robotArm.setR0Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R1) {
        robotArm.setR1Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R2) {
        robotArm.setR2Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R3) {
        robotArm.setR3Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R4) {
        robotArm.setR4Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R5) {
        robotArm.setR5Value(value.toInt());
    }
    else if (command == BT_ROBOTS_ARM_ALL) {
        int firstComma  = value.indexOf(',');
        int secondComma = value.indexOf(',', firstComma + 1);
        int thirdComma  = value.indexOf(',', secondComma + 1);
        int fourthComma = value.indexOf(',', thirdComma + 1);
        int fifthComma  = value.indexOf(',', fourthComma + 1);
        String r0ValueStr = value.substring(0, firstComma);
        String r1ValueStr = value.substring(firstComma + 1, secondComma);
        String r2ValueStr = value.substring(secondComma + 1, thirdComma);
        String r3ValueStr = value.substring(thirdComma + 1, fourthComma);
        String r4ValueStr = value.substring(fourthComma + 1, fifthComma);
        String r5ValueStr = value.substring(fifthComma + 1);
        int16_t r0Value = r0ValueStr.toInt();
        int16_t r1Value = r1ValueStr.toInt();
        int16_t r2Value = r2ValueStr.toInt();
        int16_t r3Value = r3ValueStr.toInt();
        int16_t r4Value = r4ValueStr.toInt();
        int16_t r5Value = r5ValueStr.toInt();
        robotArm.setAllValue(r0Value, r1Value, r2Value, r3Value, r4Value, r5Value);
    }
    else if (command == BT_ZIPLINE_FRONT) {
        ziplineMechanism.setFrontAngle(value.toInt());
    }
    else if (command == BT_ZIPLINE_BACK) {
        ziplineMechanism.setBackAngle(value.toInt());
    }
    else if (command == BT_ZIPLINE_ALL) {
        int firstComma  = value.indexOf(',');
        String frontValueStr = value.substring(0, firstComma);
        String backValueStr = value.substring(firstComma + 1);
        int16_t frontValue = frontValueStr.toInt();
        int16_t backValue = backValueStr.toInt();
        ziplineMechanism.setAllAngle(frontValue, backValue);
    }
}

String btClassicMessage;
bool btClassicDataReady = false;

void BTClassicRxCallback() {
    String message = btClassicSerial.readStringUntil('\n');
    if (not message.endsWith("\r")) return;
    btClassicMessage = message;
    btClassicDataReady = true;
}

// --BLE--

class BTLowEnergyServerCallbacks : public BLEServerCallbacks {

  void onConnect(BLEServer* server) override {
  }

  void onDisconnect(BLEServer* server) override {
    BLEDevice::startAdvertising();
  }
};

void onBLEDataReceived(String message) {
    Serial.print("BLE Message: ");
    Serial.println(message);
    String command = message.substring(0, message.indexOf(':'));
    String value = message.substring(message.indexOf(':') + 1);
    Serial.println(command);
    Serial.println(value);
    if (command == BT_MOTOR_RIGHT) {
        dcmotors.moveRightMotor(value.toInt());
    }
    else if (command == BT_MOTOR_LEFT) {
        dcmotors.moveLeftMotor(value.toInt());
    }
    else if (command == BT_MOTORS_ALL) {
        int firstComma  = value.indexOf(',');
        String rightSpeedStr = value.substring(0, firstComma);
        String leftSpeedStr = value.substring(firstComma + 1);
        int16_t rightSpeed = rightSpeedStr.toInt();
        int16_t leftSpeed = leftSpeedStr.toInt();
        dcmotors.moveMotors(leftSpeed, rightSpeed);
    }
    else if (command == BT_ROBOT_ARM_R0) {
        robotArm.setR0Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R1) {
        robotArm.setR1Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R2) {
        robotArm.setR2Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R3) {
        robotArm.setR3Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R4) {
        robotArm.setR4Value(value.toInt());
    }
    else if (command == BT_ROBOT_ARM_R5) {
        robotArm.setR5Value(value.toInt());
    }
    else if (command == BT_ROBOTS_ARM_ALL) {
        int firstComma  = value.indexOf(',');
        int secondComma = value.indexOf(',', firstComma + 1);
        int thirdComma  = value.indexOf(',', secondComma + 1);
        int fourthComma = value.indexOf(',', thirdComma + 1);
        int fifthComma  = value.indexOf(',', fourthComma + 1);
        String r0ValueStr = value.substring(0, firstComma);
        String r1ValueStr = value.substring(firstComma + 1, secondComma);
        String r2ValueStr = value.substring(secondComma + 1, thirdComma);
        String r3ValueStr = value.substring(thirdComma + 1, fourthComma);
        String r4ValueStr = value.substring(fourthComma + 1, fifthComma);
        String r5ValueStr = value.substring(fifthComma + 1);
        int16_t r0Value = r0ValueStr.toInt();
        int16_t r1Value = r1ValueStr.toInt();
        int16_t r2Value = r2ValueStr.toInt();
        int16_t r3Value = r3ValueStr.toInt();
        int16_t r4Value = r4ValueStr.toInt();
        int16_t r5Value = r5ValueStr.toInt();
        robotArm.setAllValue(r0Value, r1Value, r2Value, r3Value, r4Value, r5Value);
    }
    else if (command == BT_ZIPLINE_FRONT) {
        ziplineMechanism.setFrontAngle(value.toInt());
    }
    else if (command == BT_ZIPLINE_BACK) {
        ziplineMechanism.setBackAngle(value.toInt());
    }
    else if (command == BT_ZIPLINE_ALL) {
        int firstComma  = value.indexOf(',');
        String frontValueStr = value.substring(0, firstComma);
        String backValueStr = value.substring(firstComma + 1);
        int16_t frontValue = frontValueStr.toInt();
        int16_t backValue = backValueStr.toInt();
        ziplineMechanism.setAllAngle(frontValue, backValue);
    }
}

String bleMessage;
bool bleDataReady = false;

class BTLowEnergyRxCallbacks : public BLECharacteristicCallbacks {

  void onWrite(BLECharacteristic* characteristic) override {
    String message = characteristic->getValue().c_str();
    if (not message.endsWith("\r\n")) return;
    message.trim();
    bleMessage = message;
    bleDataReady = true;
  }
};

void setup(void) {

    Serial.begin(115200);

    btClassicSerial.begin(BT_CLASSIC_SERIAL_BAUD_RATE);
    btClassicSerial.onReceive(BTClassicRxCallback);

    BLEDevice::init(BLE_DEVICE_NAME);
    BLEServer* bleServer = BLEDevice::createServer();
    bleServer->setCallbacks(new BTLowEnergyServerCallbacks());
    BLEService* bleService = bleServer->createService(BLE_SERVICE_UUID);
    bleTxCharacteristic = bleService->createCharacteristic(
        BLE_TX_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_NOTIFY
    );
    bleTxCharacteristic->addDescriptor(new BLE2902());
    bleRxCharacteristic = bleService->createCharacteristic(
        BLE_RX_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_WRITE |
        BLECharacteristic::PROPERTY_WRITE_NR
    );
    bleRxCharacteristic->setCallbacks(new BTLowEnergyRxCallbacks());
    bleService->start();
    BLEAdvertising* bleAdvertising = BLEDevice::getAdvertising();
    bleAdvertising->addServiceUUID(BLE_SERVICE_UUID);
    bleAdvertising->setScanResponse(true);
    bleAdvertising->start();

    dcmotors.begin().setSerialPrintEnable(true);
    servoMotors.begin().setSerialPrintEnable(true);
    robotArm.reset().setSerialPrintEnable(true);
    ziplineMechanism.resetHorizontal().setSerialPrintEnable(true);
}

void loop(void) {

    /*if (btClassicSerial.available()) {
        onBTClassicDataReceived();
    }*/

    if (btClassicDataReady) {
        onBTClassicDataReceived(btClassicMessage);
        btClassicDataReady = false;
    }

    if (bleDataReady) {
        onBLEDataReceived(bleMessage);
        bleDataReady = false;
    }

    /*ziplineMechanism.setAngle(ziplineMechanism.FRONT_INDEX, 0);
    delay(1000);
    ziplineMechanism.setAngle(ziplineMechanism.FRONT_INDEX, 90);
    delay(1000);
    ziplineMechanism.setAngle(ziplineMechanism.FRONT_INDEX, 180);
    delay(1000);
    ziplineMechanism.setAngle(ziplineMechanism.BACK_INDEX, 0);
    delay(1000);
    ziplineMechanism.setAngle(ziplineMechanism.BACK_INDEX, 90);
    delay(1000);
    ziplineMechanism.setAngle(ziplineMechanism.BACK_INDEX, 180);
    delay(1000);*/

    /*robotArm.setValue(robotArm.R0_INDEX, -90);
    delay(1000);
    robotArm.setValue(robotArm.R0_INDEX, 0);
    delay(1000);
    robotArm.setValue(robotArm.R0_INDEX, 90);
    delay(1000);
    robotArm.setValue(robotArm.R1_INDEX, 0);
    delay(1000);
    robotArm.setValue(robotArm.R1_INDEX, 90);
    delay(1000);
    robotArm.setValue(robotArm.R1_INDEX, 180);
    delay(1000);*/

    /*servoMotors.setServoAngle(0, 0);
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
    delay(1000);*/

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