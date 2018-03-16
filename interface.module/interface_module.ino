#include <Arduino.h>
#include "src/CommandSender.h"
#include "src/ModeSelector.h"
#include "src/RunStarter.h"
#include "src/RunCounter.h"
#include <MsTimer2.h>

ModeSelector modeSelector;
RunStarter runStarter;
CommandSender commandSender;
RunCounter runCounter;

const uint8_t SENDER_PIN    = 1;
const uint8_t HORNS_PIN     = 5;
const uint8_t START_PIN     = 3;
const uint8_t CANCEL_PIN    = 6;
const uint8_t CNT_SCLK_PIN  = 8;
const uint8_t CNT_RCLK_PIN  = 9;
const uint8_t CNT_DIO_PIN   = 10;
const unsigned long RUN_DELAY = 4000;

int nextCommand = -1;

void setup() {
    runCounter.init(CNT_SCLK_PIN, CNT_RCLK_PIN, CNT_DIO_PIN);
    modeSelector.init(ModeSelector::MODE_SLOW);
    runStarter.init(HORNS_PIN, START_PIN, CANCEL_PIN);
    commandSender.init(SENDER_PIN);
    MsTimer2::set(RUN_DELAY, startTarget);
}

void loop() {
    modeSelector.select();
    unsigned long startDelay = runStarter.check();
    if (startDelay > 0) {
        nextCommand = modeSelector.getMode();
        Serial.println("Start timer...");
        MsTimer2::set(startDelay, startTarget);
        MsTimer2::start();
    }
    delay(10);
}

void startTarget() {
    runCounter.inc();
    MsTimer2::stop();
    Serial.print("Start command >> ");
    commandSender.send(nextCommand);
    runStarter.arm();
}