#include <Arduino.h>
#include "src/CommandSender.h"
#include "src/ModeSelector.h"
#include "src/RunStarter.h"
#include "src/RunCounter.h"
#include "src/RunControl.h"
#include "src/GlobalConstants.h"
#include <MsTimer2.h>

ModeSelector    *modeSelector   = new ModeSelector();
RunStarter      *runStarter     = new RunStarter();
CommandSender   *commandSender  = new CommandSender();
RunCounter      *runCounter     = new RunCounter();
RunControl      *runControl     = new RunControl();

int nextCommand = -1;

void setup() {
    runCounter->init(GlobalConstants::CNT_SCLK_PIN, GlobalConstants::CNT_RCLK_PIN, GlobalConstants::CNT_DIO_PIN, GlobalConstants::COUNT_RESET_PIN);
    modeSelector->init(ModeSelector::MODE_SLOW);
    runStarter->init(GlobalConstants::HORNS_PIN, GlobalConstants::START_PIN, GlobalConstants::CANCEL_PIN, GlobalConstants::START_LIGHT_PIN);
    runControl->init(GlobalConstants::STOP_PIN, GlobalConstants::RESET_PIN);
    commandSender->init(GlobalConstants::SENDER_PIN);
    MsTimer2::set(GlobalConstants::RUN_DELAY, startTarget);
}

void loop() {
    modeSelector->select();
    unsigned long startDelay = runStarter->check();
    if (startDelay > 0) {
        nextCommand = modeSelector->getMode();
        Serial.println("Start timer...");
        MsTimer2::set(startDelay, startTarget);
        MsTimer2::start();
    }

    int runCommand = runControl->check();
    if (runCommand > 0) {
        commandSender->send(runCommand);
    }
    runCounter->iterate();
}

void startTarget() {
    runCounter->inc();
    MsTimer2::stop();
    Serial.print("Start command >> ");
    commandSender->send(nextCommand);
    runStarter->arm();
}