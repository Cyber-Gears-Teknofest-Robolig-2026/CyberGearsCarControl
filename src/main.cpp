#include <Arduino.h>

//#include "DCMotorPins.hpp"
//#include "DCMotorPWMInfos.hpp"

#include "DCMotorControl.hpp"

DCMotorControl dcmotors;

void setup(void) {
    dcmotors.begin();
}

void loop(void) {
}