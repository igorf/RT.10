#include <Arduino.h>
#include <CommandSender.h>
#include "src/ModeSelector.h"

ModeSelector modeSelector;
CommandSender *commandSender = new CommandSender();

const uint8_t SENDER_PIN = 11;

void setup() {
    modeSelector.init(ModeSelector::MODE_SLOW);
    commandSender->init(SENDER_PIN);
}

void loop() {
    modeSelector.select();
    int mode = modeSelector.getMode();
    delay(1);
}