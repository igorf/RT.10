#include <Arduino.h>
#include <MsTimer2.h>
#include "RunStarter.h"

void RunStarter::init(uint8_t horns, uint8_t start) {

    hornsButton = new  Button(horns, false, true, 100);
    startButton = new Button(start, false, false, 100);
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

    return false;
}

void RunStarter::disarm() {
    ready = false;
}

void RunStarter::arm() {
    ready = true;
}