#include "Communicator.h"

void Communicator::init(uint8_t port) {
  Serial.begin(9600);

  vw_set_rx_pin(port);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_rx_start();    
}

int Communicator::getCommand() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)) {
        int command = buf[0];
        Serial.print("Got: ");
        Serial.print(command);
        Serial.println("");
        return command;
    }

    return -1;
}