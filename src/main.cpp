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

class BTLowEnergyServerCallbacks : public BLEServerCallbacks {

  void onConnect(BLEServer* server) override {
  }

  void onDisconnect(BLEServer* server) override {
    BLEDevice::startAdvertising();
  }
};

class BTLowEnergyRxCallbacks : public BLECharacteristicCallbacks {

  void onWrite(BLECharacteristic* characteristic) override {
  }
};

void onBTClassicDataReceived() {
    String message = btClassicSerial.readStringUntil('\n');
    if (not message.endsWith("\r")) {
        return;
    }
    Serial.print("Message: ");
    Serial.println(message);
}

void setup(void) {

    Serial.begin(115200);

    btClassicSerial.begin(9600);
    btClassicSerial.onReceive(onBTClassicDataReceived);

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