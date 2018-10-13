#include <Arduino.h>
#include <MsTimer2.h>
#include "RunStarter.h"
#include "GlobalConstants.h"

void RunStarter::init() {
    hornsButton = new Button(GlobalConstants::HORNS_PIN, false, true, 200);
    startButton = new Button(GlobalConstants::START_PIN, false, false, 100);
    ready = true;
}

unsigned long RunStarter::check() {
    if (ready) {
        hornsButton->read();
        if (hornsArmed && hornsButton->isPressed()) {
            disarm();
            hornsArmed = false;
            startSource = START_SOURCE_HORNS;
            return HORNS_START_DELAY;
        }

        startButton->read();
        if (startButton->isPressed()) {
            Serial.println("Start button is pressed");
            startSource = START_SOURCE_BUTTON;
            disarm();
            return BUTTON_START_DELAY;
        }
    } else {
        if (!hornsButton->isPressed()) {
            if (startSource == START_SOURCE_HORNS) {
                Serial.println("Start sequence cancelled (rifle is back to horns)");
                MsTimer2::stop();
                arm();
            }
            if (startSource == START_SOURCE_INIT) {
                arm();
            }
        }
    }

    if (!hornsArmed) {
        hornsButton->read();
        if (!hornsButton->isPressed()) {
            hornsArmed = true;
        }
    }

    return 0;
}

void RunStarter::disarm() {
    indicatorOn();
    ready = false;
}

void RunStarter::arm() {
    indicatorOff();
    ready = true;
}

void RunStarter::indicatorOn() {
}

void RunStarter::indicatorOff() {
}
