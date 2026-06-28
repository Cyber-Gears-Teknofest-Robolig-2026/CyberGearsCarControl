#include "RobotArmControl.hpp"


RobotArmControl::RobotArmControl(
    ServoDriverControl &servoDriver,
    uint8_t r0_channel,
    uint8_t r1_channel,
    uint8_t r2_channel,
    uint8_t r3_channel,
    uint8_t r4_channel,
    uint8_t r5_channel,
    bool r0_is360servo,
    bool r1_is360servo,
    bool r2_is360servo,
    bool r3_is360servo,
    bool r4_is360servo,
    bool r5_is360servo,
    int16_t r0_default_value,
    int16_t r1_default_value,
    int16_t r2_default_value,
    int16_t r3_default_value,
    int16_t r4_default_value,
    int16_t r5_default_value
) :
    servoDriver(servoDriver),
    r0_channel(r0_channel),
    r1_channel(r1_channel),
    r2_channel(r2_channel),
    r3_channel(r3_channel),
    r4_channel(r4_channel),
    r5_channel(r5_channel),
    r0_is360servo(r0_is360servo),
    r1_is360servo(r1_is360servo),
    r2_is360servo(r2_is360servo),
    r3_is360servo(r3_is360servo),
    r4_is360servo(r4_is360servo),
    r5_is360servo(r5_is360servo),
    r0_default_value(r0_default_value),
    r1_default_value(r1_default_value),
    r2_default_value(r2_default_value),
    r3_default_value(r3_default_value),
    r4_default_value(r4_default_value),
    r5_default_value(r5_default_value)
{
    r_channels[R0_INDEX] = r0_channel;
    r_channels[R1_INDEX] = r1_channel;
    r_channels[R2_INDEX] = r2_channel;
    r_channels[R3_INDEX] = r3_channel;
    r_channels[R4_INDEX] = r4_channel;
    r_channels[R5_INDEX] = r5_channel;
    is360Servos[R0_INDEX] = r0_is360servo;
    is360Servos[R1_INDEX] = r1_is360servo;
    is360Servos[R2_INDEX] = r2_is360servo;
    is360Servos[R3_INDEX] = r3_is360servo;
    is360Servos[R4_INDEX] = r4_is360servo;
    is360Servos[R5_INDEX] = r5_is360servo;
    r_default_values[R0_INDEX] = r0_default_value;
    r_default_values[R1_INDEX] = r1_default_value;
    r_default_values[R2_INDEX] = r2_default_value;
    r_default_values[R3_INDEX] = r3_default_value;
    r_default_values[R4_INDEX] = r4_default_value;
    r_default_values[R5_INDEX] = r5_default_value;
}

RobotArmControl& RobotArmControl::release(RobotArmIndex r_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    servoDriver.releaseServo(r_channels[static_cast<uint8_t>(r_index)]);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("release: r_index = ");
        Serial.println(static_cast<uint8_t>(r_index));
    }
    return *this;
}

RobotArmControl& RobotArmControl::release(uint8_t r_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(static_cast<RobotArmIndex>(r_index));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("release: r_index = ");
        Serial.println(r_index);
    }
    return *this;
}

RobotArmControl& RobotArmControl::releaseR0(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(R0_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("releaseR0");
    }
    return *this;
}

RobotArmControl& RobotArmControl::releaseR1(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(R1_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("releaseR1");
    }
    return *this;
}

RobotArmControl& RobotArmControl::releaseR2(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(R2_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("releaseR2");
    }
    return *this;
}

RobotArmControl& RobotArmControl::releaseR3(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(R3_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("releaseR3");
    }
    return *this;
}

RobotArmControl& RobotArmControl::releaseR4(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(R4_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("releaseR4");
    }
    return *this;
}

RobotArmControl& RobotArmControl::releaseR5(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    release(R5_INDEX);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("releaseR5");
    }
    return *this;
}

RobotArmControl& RobotArmControl::releaseAll(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    releaseR0();
    releaseR1();
    releaseR2();
    releaseR3();
    releaseR4();
    releaseR5();
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.println("releaseAll");
    }
    return *this;
}

RobotArmControl& RobotArmControl::reset(RobotArmIndex r_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(r_index, r_default_values[r_index]);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("reset: r_index = ");
        Serial.print(static_cast<uint8_t>(r_index));
        Serial.print(", r_value = ");
        Serial.println(r_default_values[r_index]);
    }
    return *this;
}

RobotArmControl& RobotArmControl::reset(uint8_t r_index) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    reset(static_cast<RobotArmIndex>(r_index));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("reset: r_index = ");
        Serial.println(r_index);
    }
    return *this;
}

RobotArmControl& RobotArmControl::resetR0(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R0_INDEX, r0_default_value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetR0: r0_value = ");
        Serial.println(r0_default_value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::resetR1(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R1_INDEX, r1_default_value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetR1: r1_value = ");
        Serial.println(r1_default_value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::resetR2(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R2_INDEX, r2_default_value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetR2: r2_value = ");
        Serial.println(r2_default_value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::resetR3(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R3_INDEX, r3_default_value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetR3: r3_value = ");
        Serial.println(r3_default_value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::resetR4(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R4_INDEX, r4_default_value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetR4: r4_value = ");
        Serial.println(r4_default_value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::resetR5(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R5_INDEX, r5_default_value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("resetR5: r5_value = ");
        Serial.println(r5_default_value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::resetAll(void) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    resetR0();
    resetR1();
    resetR2();
    resetR3();
    resetR4();
    resetR5();
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("reset: r0 = ");
        Serial.print(r0_default_value);
        Serial.print(", r1 = ");
        Serial.print(r1_default_value);
        Serial.print(", r2 = ");
        Serial.print(r2_default_value);
        Serial.print(", r3 = ");
        Serial.print(r3_default_value);
        Serial.print(", r4 = ");
        Serial.print(r4_default_value);
        Serial.print(", r5 = ");
        Serial.println(r5_default_value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAngle(RobotArmIndex r_index, uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    bool serialPrintEnable_servoDriver_temp = servoDriver.getSerialPrintEnable();
    serialPrintEnable = false;
    servoDriver.setSerialPrintEnable(false);
    servoDriver.setServoAngle(r_channels[static_cast<uint8_t>(r_index)], constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    serialPrintEnable = serialPrintEnable_temp;
    servoDriver.setSerialPrintEnable(serialPrintEnable_servoDriver_temp);
    if (serialPrintEnable) {
        Serial.print("setAngle: r_index = ");
        Serial.print(static_cast<uint8_t>(r_index));
        Serial.print(", angle = ");
        Serial.println(angle);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAngle(uint8_t r_index, uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(static_cast<RobotArmIndex>(r_index), angle);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAngle: r_index = ");
        Serial.print(r_index);
        Serial.print(", angle = ");
        Serial.println(angle);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR0Angle(uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(R0_INDEX, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR0Angle: angle = ");
        Serial.println(angle);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR1Angle(uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(R1_INDEX, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR1Angle: angle = ");
        Serial.println(angle);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR2Angle(uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(R2_INDEX, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR2Angle: angle = ");
        Serial.println(angle);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR3Angle(uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(R3_INDEX, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR3Angle: angle = ");
        Serial.println(angle);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR4Angle(uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(R4_INDEX, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR4Angle: angle = ");
        Serial.println(angle);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR5Angle(uint8_t angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAngle(R5_INDEX, constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR5Angle: angle = ");
        Serial.println(angle);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAllAngle(uint8_t r0_angle, uint8_t r1_angle, uint8_t r2_angle, uint8_t r3_angle, uint8_t r4_angle, uint8_t r5_angle) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setR0Angle(r0_angle);
    setR1Angle(r1_angle);
    setR2Angle(r2_angle);
    setR3Angle(r3_angle);
    setR4Angle(r4_angle);
    setR5Angle(r5_angle);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAllAngle: r0 = ");
        Serial.print(r0_angle);
        Serial.print(", r1 = ");
        Serial.print(r1_angle);
        Serial.print(", r2 = ");
        Serial.print(r2_angle);
        Serial.print(", r3 = ");
        Serial.print(r3_angle);
        Serial.print(", r4 = ");
        Serial.print(r4_angle);
        Serial.print(", r5 = ");
        Serial.println(r5_angle);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAnglePulse(RobotArmIndex r_index, uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    bool serialPrintEnable_servoDriver_temp = servoDriver.getSerialPrintEnable();
    serialPrintEnable = false;
    servoDriver.setSerialPrintEnable(false);
    servoDriver.setServoAnglePulse(r_channels[static_cast<uint8_t>(r_index)], constrain(pulse, SERVO_MIN_ANGLE_PULSE, SERVO_MAX_ANGLE_PULSE));
    serialPrintEnable = serialPrintEnable_temp;
    servoDriver.setSerialPrintEnable(serialPrintEnable_servoDriver_temp);
    if (serialPrintEnable) {
        Serial.print("setAnglePulse: r_index = ");
        Serial.print(static_cast<uint8_t>(r_index));
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAnglePulse(uint8_t r_index, uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAnglePulse(static_cast<RobotArmIndex>(r_index), pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAnglePulse: r_index = ");
        Serial.print(r_index);
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR0AnglePulse(uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAnglePulse(R0_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR0AnglePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR1AnglePulse(uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAnglePulse(R1_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR1AnglePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR2AnglePulse(uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAnglePulse(R2_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR2AnglePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR3AnglePulse(uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAnglePulse(R3_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR3AnglePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR4AnglePulse(uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAnglePulse(R4_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR4AnglePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR5AnglePulse(uint16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setAnglePulse(R5_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR5AnglePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAllAnglePulse(uint16_t r0_pulse, uint16_t r1_pulse, uint16_t r2_pulse, uint16_t r3_pulse, uint16_t r4_pulse, uint16_t r5_pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setR0AnglePulse(r0_pulse);
    setR1AnglePulse(r1_pulse);
    setR2AnglePulse(r2_pulse);
    setR3AnglePulse(r3_pulse);
    setR4AnglePulse(r4_pulse);
    setR5AnglePulse(r5_pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAllAnglePulse: r0 = ");
        Serial.print(r0_pulse);
        Serial.print(", r1 = ");
        Serial.print(r1_pulse);
        Serial.print(", r2 = ");
        Serial.print(r2_pulse);
        Serial.print(", r3 = ");
        Serial.print(r3_pulse);
        Serial.print(", r4 = ");
        Serial.print(r4_pulse);
        Serial.print(", r5 = ");
        Serial.println(r5_pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setSpeed(RobotArmIndex r_index, int8_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    bool serialPrintEnable_servoDriver_temp = servoDriver.getSerialPrintEnable();
    serialPrintEnable = false;
    servoDriver.setSerialPrintEnable(false);
    servoDriver.setServoSpeed(r_channels[static_cast<uint8_t>(r_index)], constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    serialPrintEnable = serialPrintEnable_temp;
    servoDriver.setSerialPrintEnable(serialPrintEnable_servoDriver_temp);
    if (serialPrintEnable) {
        Serial.print("setSpeed: r_index = ");
        Serial.print(static_cast<uint8_t>(r_index));
        Serial.print(", speed = ");
        Serial.println(speed);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setSpeed(uint8_t r_index, int8_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeed(static_cast<RobotArmIndex>(r_index), speed);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setSpeed: r_index = ");
        Serial.print(r_index);
        Serial.print(", speed = ");
        Serial.println(speed);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR0Speed(int8_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeed(R0_INDEX, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR0Speed: speed = ");
        Serial.println(speed);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR1Speed(int8_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeed(R1_INDEX, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR1Speed: speed = ");
        Serial.println(speed);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR2Speed(int8_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeed(R2_INDEX, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR2Speed: speed = ");
        Serial.println(speed);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR3Speed(int8_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeed(R3_INDEX, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR3Speed: speed = ");
        Serial.println(speed);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR4Speed(int8_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeed(R4_INDEX, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR4Speed: speed = ");
        Serial.println(speed);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR5Speed(int8_t speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeed(R5_INDEX, constrain(speed, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR5Speed: speed = ");
        Serial.println(speed);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAllSpeed(int8_t r0_speed, int8_t r1_speed, int8_t r2_speed, int8_t r3_speed, int8_t r4_speed, int8_t r5_speed) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setR0Speed(r0_speed);
    setR1Speed(r1_speed);
    setR2Speed(r2_speed);
    setR3Speed(r3_speed);
    setR4Speed(r4_speed);
    setR5Speed(r5_speed);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAllSpeed: r0 = ");
        Serial.print(r0_speed);
        Serial.print(", r1 = ");
        Serial.print(r1_speed);
        Serial.print(", r2 = ");
        Serial.print(r2_speed);
        Serial.print(", r3 = ");
        Serial.print(r3_speed);
        Serial.print(", r4 = ");
        Serial.print(r4_speed);
        Serial.print(", r5 = ");
        Serial.println(r5_speed);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setSpeedPulse(RobotArmIndex r_index, int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    bool serialPrintEnable_servoDriver_temp = servoDriver.getSerialPrintEnable();
    serialPrintEnable = false;
    servoDriver.setSerialPrintEnable(false);
    servoDriver.setServoSpeedPulse(r_channels[static_cast<uint8_t>(r_index)], constrain(pulse, SERVO_MAX_LEFT_SPEED_PULSE, SERVO_MAX_RIGHT_SPEED_PULSE));
    serialPrintEnable = serialPrintEnable_temp;
    servoDriver.setSerialPrintEnable(serialPrintEnable_servoDriver_temp);
    if (serialPrintEnable) {
        Serial.print("setSpeedPulse: r_index = ");
        Serial.print(static_cast<uint8_t>(r_index));
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setSpeedPulse(uint8_t r_index, int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeedPulse(static_cast<RobotArmIndex>(r_index), pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setSpeedPulse: r_index = ");
        Serial.print(r_index);
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR0SpeedPulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeedPulse(R0_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR0SpeedPulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR1SpeedPulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeedPulse(R1_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR1SpeedPulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR2SpeedPulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeedPulse(R2_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR2SpeedPulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR3SpeedPulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeedPulse(R3_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR3SpeedPulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR4SpeedPulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeedPulse(R4_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR4SpeedPulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR5SpeedPulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setSpeedPulse(R5_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR5SpeedPulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAllSpeedPulse(int16_t r0_pulse, int16_t r1_pulse, int16_t r2_pulse, int16_t r3_pulse, int16_t r4_pulse, int16_t r5_pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setR0SpeedPulse(r0_pulse);
    setR1SpeedPulse(r1_pulse);
    setR2SpeedPulse(r2_pulse);
    setR3SpeedPulse(r3_pulse);
    setR4SpeedPulse(r4_pulse);
    setR5SpeedPulse(r5_pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAllSpeedPulse: r0 = ");
        Serial.print(r0_pulse);
        Serial.print(", r1 = ");
        Serial.print(r1_pulse);
        Serial.print(", r2 = ");
        Serial.print(r2_pulse);
        Serial.print(", r3 = ");
        Serial.print(r3_pulse);
        Serial.print(", r4 = ");
        Serial.print(r4_pulse);
        Serial.print(", r5 = ");
        Serial.println(r5_pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setValue(RobotArmIndex r_index, int16_t value) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    if (not is360Servos[static_cast<uint8_t>(r_index)]) {
        setAngle(r_index, constrain(value, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    }
    else {
        setSpeed(r_index, constrain(value, SERVO_MAX_LEFT_SPEED, SERVO_MAX_RIGHT_SPEED));
    }
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setValue: r_index = ");
        Serial.print(static_cast<uint8_t>(r_index));
        Serial.print(", value = ");
        Serial.println(value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setValue(uint8_t r_index, int16_t value) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(static_cast<RobotArmIndex>(r_index), value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setValue: r_index = ");
        Serial.print(r_index);
        Serial.print(", value = ");
        Serial.println(value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR0Value(int16_t value) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R0_INDEX, value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR0Value: value = ");
        Serial.println(value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR1Value(int16_t value) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R1_INDEX, value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR1Value: value = ");
        Serial.println(value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR2Value(int16_t value) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R2_INDEX, value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR2Value: value = ");
        Serial.println(value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR3Value(int16_t value) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R3_INDEX, value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR3Value: value = ");
        Serial.println(value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR4Value(int16_t value) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R4_INDEX, value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR4Value: value = ");
        Serial.println(value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR5Value(int16_t value) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValue(R5_INDEX, value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR5Value: value = ");
        Serial.println(value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAllValue(int16_t r0_value, int16_t r1_value, int16_t r2_value, int16_t r3_value, int16_t r4_value, int16_t r5_value) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setR0Value(r0_value);
    setR1Value(r1_value);
    setR2Value(r2_value);
    setR3Value(r3_value);
    setR4Value(r4_value);
    setR5Value(r5_value);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAllValue: r0 = ");
        Serial.print(r0_value);
        Serial.print(", r1 = ");
        Serial.print(r1_value);
        Serial.print(", r2 = ");
        Serial.print(r2_value);
        Serial.print(", r3 = ");
        Serial.print(r3_value);
        Serial.print(", r4 = ");
        Serial.print(r4_value);
        Serial.print(", r5 = ");
        Serial.println(r5_value);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setValuePulse(RobotArmIndex r_index, int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    if (not is360Servos[static_cast<uint8_t>(r_index)]) {
        setAnglePulse(r_index, constrain(pulse, SERVO_MIN_ANGLE_PULSE, SERVO_MAX_ANGLE_PULSE));
    }
    else {
        setSpeedPulse(r_index, constrain(pulse, SERVO_MAX_LEFT_SPEED_PULSE, SERVO_MAX_RIGHT_SPEED_PULSE));
    }
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setValuePulse: r_index = ");
        Serial.print(static_cast<uint8_t>(r_index));
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setValuePulse(uint8_t r_index, int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValuePulse(static_cast<RobotArmIndex>(r_index), pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setValuePulse: r_index = ");
        Serial.print(r_index);
        Serial.print(", pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR0ValuePulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValuePulse(R0_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR0ValuePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR1ValuePulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValuePulse(R1_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR1ValuePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR2ValuePulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValuePulse(R2_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR2ValuePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR3ValuePulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValuePulse(R3_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR3ValuePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR4ValuePulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValuePulse(R4_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR4ValuePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setR5ValuePulse(int16_t pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setValuePulse(R5_INDEX, pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setR5ValuePulse: pulse = ");
        Serial.println(pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setAllValuePulse(int16_t r0_pulse, int16_t r1_pulse, int16_t r2_pulse, int16_t r3_pulse, int16_t r4_pulse, int16_t r5_pulse) {
    bool serialPrintEnable_temp = serialPrintEnable;
    serialPrintEnable = false;
    setR0ValuePulse(r0_pulse);
    setR1ValuePulse(r1_pulse);
    setR2ValuePulse(r2_pulse);
    setR3ValuePulse(r3_pulse);
    setR4ValuePulse(r4_pulse);
    setR5ValuePulse(r5_pulse);
    serialPrintEnable = serialPrintEnable_temp;
    if (serialPrintEnable) {
        Serial.print("setAllValuePulse: r0 = ");
        Serial.print(r0_pulse);
        Serial.print(", r1 = ");
        Serial.print(r1_pulse);
        Serial.print(", r2 = ");
        Serial.print(r2_pulse);
        Serial.print(", r3 = ");
        Serial.print(r3_pulse);
        Serial.print(", r4 = ");
        Serial.print(r4_pulse);
        Serial.print(", r5 = ");
        Serial.println(r5_pulse);
    }
    return *this;
}

RobotArmControl& RobotArmControl::setSerialPrintEnable(bool enable) {
    this->serialPrintEnable = enable;
    return *this;
}

bool RobotArmControl::getSerialPrintEnable(void) const {
    return serialPrintEnable;
}
