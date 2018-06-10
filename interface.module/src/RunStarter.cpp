#include <Arduino.h>
#include <MsTimer2.h>
#include "RunStarter.h"
#include "GlobalConstants.h"

void RunStarter::init(uint8_t hornsPin, uint8_t startPin, uint8_t cancelPin, uint8_t startIndicator) {
    hornsButton     = new Button(hornsPin, false, true, 200);
    startButton     = new Button(startPin, false, false, 100);
    cancelButton    = new Button(cancelPin, false, false, 100);
    indicatorPin = startIndicator;
    if (indicatorPin > 0) {
        pinMode(indicatorPin, OUTPUT);
        digitalWrite(indicatorPin, GlobalConstants::LIGHT_MODE_OFF);
    }
    ready = false;
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
            startSource = START_SOURCE_BUTTON;
            disarm();
            return BUTTON_START_DELAY;
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
    if (indicatorPin > 0) {
        digitalWrite(indicatorPin, GlobalConstants::LIGHT_MODE_ON);
    }
}

void RunStarter::indicatorOff() {
    if (indicatorPin > 0) {
        digitalWrite(indicatorPin, GlobalConstants::LIGHT_MODE_OFF);
    }
}
