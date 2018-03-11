#include <Arduino.h>
#include "RunStarter.h"

void RunStarter::init(uint8_t horns, uint8_t start) {
    hornsPin = horns;
    startPin = start;
    armed = false;

    pinMode(hornsPin, INPUT);
    pinMode(startPin, INPUT);
    lastTime = millis();
}

bool RunStarter::check() {
    if (armed) {
        if (digitalRead(hornsPin) == LOW || digitalRead(startPin) == HIGH) {
            if (millis() - lastTime > STATE_DELAY) {
                disarm();
                lastTime = millis();
                return true;
            }
        }
    } else {
        if (digitalRead(hornsPin) == HIGH) {
            arm();
        }
    }

    return false;
}

void RunStarter::disarm() {
    armed = false;
}

void RunStarter::arm() {
    armed = true;
}