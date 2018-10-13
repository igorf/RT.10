#include <Arduino.h>
#include "src/CommandSender.h"
#include "src/ModeSelector.h"
#include "src/RunStarter.h"
#include "src/RunCounter.h"
#include "src/RunControl.h"
#include "src/ScreenResetter.h"
#include "src/GlobalConstants.h"
#include <MsTimer2.h>

ModeSelector    *modeSelector   = new ModeSelector();
RunStarter      *runStarter     = new RunStarter();
CommandSender   *commandSender  = new CommandSender();
RunCounter      *runCounter     = new RunCounter();
RunControl      *runControl     = new RunControl();
ScreenResetter  *screenResetter = new ScreenResetter();

int nextCommand = -1;

void setup() {
    Serial.println("Starting program...");
    runCounter->init();
    modeSelector->init(ModeSelector::MODE_SLOW);
    runStarter->init();
    runControl->init();
    commandSender->init();
    screenResetter->init(runCounter);
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

    screenResetter->check();

    int runCommand = runControl->check();
    if (runCommand > 0) {
        commandSender->send(runCommand);
    }
}

void startTarget() {
    runCounter->inc();
    MsTimer2::stop();
    Serial.print("Start command >> ");
    commandSender->send(nextCommand);
    runStarter->arm();
}