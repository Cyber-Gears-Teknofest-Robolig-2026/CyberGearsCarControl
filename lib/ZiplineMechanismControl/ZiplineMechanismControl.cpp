#include "ZiplineMechanismControl.hpp"

ZiplineMechanismControl::ZiplineMechanismControl(
    ServoDriverControl &servoDriver,
    uint8_t front_channel,
    uint8_t back_channel,
    int16_t front_horizontal_default_angle,
    int16_t back_horizontal_default_angle,
    int16_t front_vertical_default_angle,
    int16_t back_vertical_default_angle
) :
    servoDriver(servoDriver),
    front_channel(front_channel),
    back_channel(back_channel),
    front_horizontal_default_angle(front_horizontal_default_angle),
    back_horizontal_default_angle(back_horizontal_default_angle),
    front_vertical_default_angle(front_vertical_default_angle),
    back_vertical_default_angle(back_vertical_default_angle)
{
    zipline_mechanism_channels[FRONT_INDEX] = front_channel;
    zipline_mechanism_channels[BACK_INDEX] = back_channel;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetHorizontal() {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(FRONT_INDEX, front_horizontal_default_angle);
    setAngle(BACK_INDEX, back_horizontal_default_angle);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetHorizontal: front = ");
        Serial.print(front_horizontal_default_angle);
        Serial.print(", back = ");
        Serial.println(back_horizontal_default_angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetVertical() {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(FRONT_INDEX, front_vertical_default_angle);
    setAngle(BACK_INDEX, back_vertical_default_angle);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetVertical: front = ");
        Serial.print(front_vertical_default_angle);
        Serial.print(", back = ");
        Serial.println(back_vertical_default_angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAngle(MechanismIndex mechanism_index, uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    bool serialPrintEnable_servoDriver_temp = servoDriver.getSerialPrintEnable();
    serialPrintEnable = false;
    servoDriver.setSerialPrintEnable(false);
    servoDriver.setServoAngle(zipline_mechanism_channels[static_cast<uint8_t>(mechanism_index)], constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    serialPrintEnable = serialPrintEnable_temp;
    servoDriver.setSerialPrintEnable(serialPrintEnable_servoDriver_temp);
    if (serialPrintEnable) {
        Serial.print("setAngle: mechanism_index = ");
        Serial.print(static_cast<uint8_t>(mechanism_index));
        Serial.print(", angle = ");
        Serial.println(angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAngle(uint8_t mechanism_index, uint8_t angle) {
    setAngle(static_cast<MechanismIndex>(mechanism_index), angle);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setFrontAngle(uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(FRONT_INDEX, angle);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setFrontAngle: angle = ");
        Serial.println(angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setBackAngle(uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(BACK_INDEX, angle);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setBackAngle: angle = ");
        Serial.println(angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAllAngle(uint8_t front_angle, uint8_t back_angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setFrontAngle(front_angle);
    setBackAngle(back_angle);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAllAngle: front = ");
        Serial.print(front_angle);
        Serial.print(", back = ");
        Serial.println(back_angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAnglePulse(MechanismIndex mechanism_index, uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    bool serialPrintEnable_servoDriver_temp = servoDriver.getSerialPrintEnable();
    serialPrintEnable = false;
    servoDriver.setSerialPrintEnable(false);
    servoDriver.setServoAnglePulse(zipline_mechanism_channels[static_cast<uint8_t>(mechanism_index)], constrain(pulse, SERVO_MIN_ANGLE_PULSE, SERVO_MAX_ANGLE_PULSE));
    serialPrintEnable = serialPrintEnable_temp;
    servoDriver.setSerialPrintEnable(serialPrintEnable_servoDriver_temp);
    if (serialPrintEnable) {
        Serial.print("setAnglePulse: mechanism_index = ");
        Serial.print(static_cast<uint8_t>(mechanism_index));
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAnglePulse(uint8_t mechanism_index, uint16_t pulse) {
    setAnglePulse(static_cast<MechanismIndex>(mechanism_index), pulse);
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setFrontAnglePulse(uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAnglePulse(FRONT_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setFrontAnglePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setBackAnglePulse(uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAnglePulse(BACK_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setBackAnglePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setAllAnglePulse(uint16_t front_pulse, uint16_t back_pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setFrontAnglePulse(front_pulse);
    setBackAnglePulse(back_pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAllAnglePulse: front = ");
        Serial.print(front_pulse);
        Serial.print(", back = ");
        Serial.println(back_pulse);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::setSerialPrintEnable(bool enable) {
    this->serialPrintEnable = enable;
    return *this;
}

bool ZiplineMechanismControl::getSerialPrintEnable(void) const {
    return serialPrintEnable;
}
