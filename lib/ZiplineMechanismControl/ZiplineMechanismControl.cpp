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
    horizontal_default_angles[FRONT_INDEX] = front_horizontal_default_angle;
    horizontal_default_angles[BACK_INDEX] = back_horizontal_default_angle;
    vertical_default_angles[FRONT_INDEX] = front_vertical_default_angle;
    vertical_default_angles[BACK_INDEX] = back_vertical_default_angle;
}

ZiplineMechanismControl& ZiplineMechanismControl::release(MechanismIndex mechanism_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    bool serialPrintEnable_servoDriver_temp = servoDriver.getSerialPrintEnable();
    serialPrintEnable = false;
    servoDriver.setSerialPrintEnable(false);
    servoDriver.releaseServo(zipline_mechanism_channels[static_cast<uint8_t>(mechanism_index)]);
    serialPrintEnable = serialPrintEnable_temp;
    servoDriver.setSerialPrintEnable(serialPrintEnable_servoDriver_temp);
    if (serialPrintEnable) {
        Serial.print("release: mechanism_index = ");
        Serial.print(static_cast<uint8_t>(mechanism_index));
        Serial.println();
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::release(uint8_t mechanism_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(static_cast<MechanismIndex>(mechanism_index));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("release: mechanism_index = ");
        Serial.print(mechanism_index);
        Serial.println();
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::releaseFront(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(FRONT_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("releaseFront: front = ");
        Serial.println();
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::releaseBack(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(BACK_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("releaseBack: back = ");
        Serial.println();
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::releaseAll(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(FRONT_INDEX);
    release(BACK_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("releaseAll: front = ");
        Serial.print(front_horizontal_default_angle);
        Serial.print(", back = ");
        Serial.println(back_horizontal_default_angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetHorizontal(MechanismIndex mechanism_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(mechanism_index, horizontal_default_angles[static_cast<uint8_t>(mechanism_index)]);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetHorizontal: mechanism_index = ");
        Serial.print(static_cast<uint8_t>(mechanism_index));
        Serial.print(", angle = ");
        Serial.println(horizontal_default_angles[static_cast<uint8_t>(mechanism_index)]);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetHorizontal(uint8_t mechanism_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetHorizontal(static_cast<MechanismIndex>(mechanism_index));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetHorizontal: mechanism_index = ");
        Serial.print(mechanism_index);
        Serial.print(", angle = ");
        Serial.println(horizontal_default_angles[mechanism_index]);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetHorizontalFront(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetHorizontal(FRONT_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetHorizontalFront: front = ");
        Serial.println(front_horizontal_default_angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetHorizontalBack(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetHorizontal(BACK_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetHorizontalBack: back = ");
        Serial.println(back_horizontal_default_angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetHorizontalAll(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetHorizontalFront();
    resetHorizontalBack();
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetHorizontal: front = ");
        Serial.print(front_horizontal_default_angle);
        Serial.print(", back = ");
        Serial.println(back_horizontal_default_angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetVertical(MechanismIndex mechanism_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetVertical(static_cast<uint8_t>(mechanism_index));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetVertical: mechanism_index = ");
        Serial.print(static_cast<uint8_t>(mechanism_index));
        Serial.print(", angle = ");
        Serial.println(vertical_default_angles[static_cast<uint8_t>(mechanism_index)]);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetVertical(uint8_t mechanism_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetVertical(static_cast<MechanismIndex>(mechanism_index));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetVertical: mechanism_index = ");
        Serial.print(mechanism_index);
        Serial.print(", angle = ");
        Serial.println(vertical_default_angles[mechanism_index]);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetVerticalFront(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetVertical(FRONT_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetVerticalFront: front = ");
        Serial.println(front_vertical_default_angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetVerticalBack(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetVertical(BACK_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetVerticalBack: back = ");
        Serial.println(back_vertical_default_angle);
    }
    return *this;
}

ZiplineMechanismControl& ZiplineMechanismControl::resetVerticalAll(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetVerticalFront();
    resetVerticalBack();
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
