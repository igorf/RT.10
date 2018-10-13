#include <HardwareSerial.h>
#include <VirtualWire.h>
#include "CommandSender.h"
#include "GlobalConstants.h"

void CommandSender::init() {
    port = GlobalConstants::SENDER_PIN;
    Serial.begin(9600);

    vw_set_tx_pin(port);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
}

void CommandSender::send(int command) {
    int data[1] = {command};
    vw_send((uint8_t *)data, sizeof(data));
    //vw_wait_tx();
    Serial.println(command);
}