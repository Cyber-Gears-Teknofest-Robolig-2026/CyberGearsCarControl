#ifndef __ZIPLINE_MECHANISM_CONTROL_HPP__
#define __ZIPLINE_MECHANISM_CONTROL_HPP__

#include <cstdint>

#include "ServoDriverControl.hpp"
#include "ZiplineMechanismChannelInfos.hpp"

using namespace ZiplineMechanismChannelInfos;

class ZiplineMechanismControl {
    
    public:
        ZiplineMechanismControl(
            ServoDriverControl &servoDriver,
            uint8_t front_channel = FRONT_CHANNEL,
            uint8_t back_channel = BACK_CHANNEL
        );
    
    private:
        ServoDriverControl &servoDriver;
        uint8_t front_channel;
        uint8_t back_channel;
};

#endif