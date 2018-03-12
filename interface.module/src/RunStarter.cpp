#include <Arduino.h>
#include <MsTimer2.h>
#include "RunStarter.h"

void RunStarter::init(uint8_t hornsPin, uint8_t startPin, uint8_t cancelPin) {

    hornsButton     = new Button(hornsPin, false, true, 200);
    startButton     = new Button(startPin, false, false, 100);
    cancelButton    = new Button(cancelPin, false, false, 100);
    ready = false;
}

bool RunStarter::check() {
    if (ready) {
        hornsButton->read();
        if (hornsArmed && hornsButton->isPressed()) {
            disarm();
            hornsArmed = false;
            startSource = START_SOURCE_HORNS;
            return true;
        }

        startButton->read();
        if (startButton->isPressed()) {
            startSource = START_SOURCE_BUTTON;
            disarm();
            return true;
        }
    } else {
        cancelButton->read();
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

        if (cancelButton->isPressed()) {
            Serial.println("Start sequence cancelled (cancel pressed)");
            MsTimer2::stop();
            arm();
        }
    }

    if (!hornsArmed) {
        hornsButton->read();
        if (!hornsButton->isPressed()) {
            hornsArmed = true;
        }
    }

    return false;
}

void RunStarter::disarm() {
    ready = false;
}

void RunStarter::arm() {
    ready = true;
}