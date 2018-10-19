#include <CommunicationCommands.h>
#include "Calibrator.h"

void Calibrator::init(uint8_t leftPin, uint8_t rightPin) {
    buttons[0] = new FinishButton(leftPin);
    buttons[1] = new FinishButton(rightPin);
}

void Calibrator::display() {
    Serial.print("Time elapsed: ");
    Serial.println(result);
}

void Calibrator::arm() {
    armed = true;
}

void Calibrator::disarm() {
    armed = false;
}

void Calibrator::start(FinishButton *startButton) {
    startMeasureButton = startButton;
    timeBorder = millis();
    measuring = true;
    Serial.println("Measuring::start");
}

void Calibrator::stop() {
    armed = false;
    measuring = false;
    long now = millis();
    result = now - timeBorder;
    Serial.println("Measuring::stop");
    display();
}

void Calibrator::reset() {
    armed = false;
    measuring = false;
    result = 0;
    timeBorder = 0;
}

void Calibrator::commandFromCommunicator(int command) {
    if (command == CommunicationCommands::RUN_FAST || command == CommunicationCommands::RUN_SLOW) {
        arm();
    } else if (command == CommunicationCommands::STOP) {
        disarm();
    } else if (command == CommunicationCommands::RESET) {
        reset();
    }
    check();
}

void Calibrator::check() {
    if (!armed) {
        return;
    }

    for (auto &button : buttons) {
        if (button->isPressed()) {
            if (!measuring) {
                start(button);
            } else if (button != startMeasureButton) {
                stop();
            }
        }
    }
}