#ifndef INTERFACE_MODULE_COMMANDSENDER_H
#define INTERFACE_MODULE_COMMANDSENDER_H


#include <stdint.h>

class CommandSender {

public:
    void init(uint8_t senderPort);
    void send(int command);

private:
    uint8_t port;
};


#endif //INTERFACE_MODULE_COMMANDSENDER_H
