#include <HardwareSerial.h>
#include <VirtualWire.h>
#include "CommandSender.h"

void CommandSender::init(uint8_t senderPort) {
    port = senderPort;
    Serial.begin(9600);

    vw_set_tx_pin(port);
    vw_setup(4000);
}

void CommandSender::send(int command) {
    int data[1] = {command};
    vw_send((uint8_t *)data, sizeof(data));
    //vw_wait_tx();
    Serial.println(command);
}