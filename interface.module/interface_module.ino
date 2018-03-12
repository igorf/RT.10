#include <Arduino.h>
#include "src/CommandSender.h"
#include "src/ModeSelector.h"
#include "src/RunStarter.h"
#include "TimerOne.h"

ModeSelector modeSelector;
RunStarter runStarter;
CommandSender *commandSender = new CommandSender();

const uint8_t SENDER_PIN = 1;
const uint8_t HORNS_PIN = 5;
const uint8_t START_PIN = 3;

int nextCommand = -1;

void setup() {
    modeSelector.init(ModeSelector::MODE_SLOW);
    runStarter.init(HORNS_PIN, START_PIN);
    commandSender->init(SENDER_PIN);

    Timer1.initialize(4000000);
    Timer1.stop();
    Timer1.restart();
    Timer1.attachInterrupt(timerIsr);
}

void loop() {
    modeSelector.select();
    if (runStarter.check()) {
        nextCommand = modeSelector.getMode();
        Serial.print("Start!\n\n");
        Timer1.start();
    }
    delay(10);
}

void timerIsr() {
    Timer1.stop();
    Timer1.restart();
    Serial.print("!!!\n");
    commandSender->send(nextCommand);
    runStarter.arm();
}