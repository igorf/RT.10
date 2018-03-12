#include <Arduino.h>
#include "src/CommandSender.h"
#include "src/ModeSelector.h"
#include "src/RunStarter.h"
#include <MsTimer2.h>

ModeSelector modeSelector;
RunStarter runStarter;
CommandSender commandSender;

const uint8_t SENDER_PIN = 1;
const uint8_t HORNS_PIN = 5;
const uint8_t START_PIN = 3;
const unsigned long RUN_DELAY = 4000;

int nextCommand = -1;

void setup() {
    modeSelector.init(ModeSelector::MODE_SLOW);
    runStarter.init(HORNS_PIN, START_PIN);
    commandSender.init(SENDER_PIN);
    MsTimer2::set(RUN_DELAY, startTarget);
}

void loop() {
    modeSelector.select();
    if (runStarter.check()) {
        nextCommand = modeSelector.getMode();
        Serial.println("Start timer...");
        MsTimer2::start();
    }
    delay(10);
}

void startTarget() {
    MsTimer2::stop();
    Serial.print("Start command >> ");
    commandSender.send(nextCommand);
    runStarter.arm();
}