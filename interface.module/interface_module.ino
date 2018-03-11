#include <Arduino.h>
#include "src/CommandSender.h"
#include "src/ModeSelector.h"
#include "src/RunStarter.h"

ModeSelector modeSelector;
RunStarter runStarter;
CommandSender *commandSender = new CommandSender();

const uint8_t SENDER_PIN = 1;
const uint8_t HORNS_PIN = 5;
const uint8_t START_PIN = 3;

void setup() {
    modeSelector.init(ModeSelector::MODE_SLOW);
    runStarter.init(HORNS_PIN, START_PIN);
    commandSender->init(SENDER_PIN);
}

void loop() {
    modeSelector.select();
    if (runStarter.check()) {
        int mode = modeSelector.getMode();
        Serial.print("Start!\n\n");
    }
    delay(10);
}