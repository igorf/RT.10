#ifndef ENGINE_MODULE_COMMUNICATOR_H
#define ENGINE_MODULE_COMMUNICATOR_H

#include <Arduino.h>
#include <VirtualWire.h>

class Communicator {
    public:
        void init(uint8_t rx_pin);
        int getCommand();
};

#endif