#include "Engine.h"

void Engine::init(AccelStepper *stepperPtr, int slowRPM, int fastRPM, uint8_t leftButton, uint8_t rightButton) {
    slowSpeed = slowRPM;
    fastSpeed = fastRPM;
    leftStopButton = new Button(leftButton, false, false, 1);
    rightStopButton = new Button(rightButton, false, false, 1);
    stepper = stepperPtr;
}

void Engine::command(int command) {
    if (command == 0 || command == 3) {
        if (!isRunning) {
            runSlow();
        }
    } else if (command == 1) {
        if (!isRunning) {
            runFast();
        }
    } else if (command == 2) {
        isRunning = false;
        if (stepper->isRunning()) {
            stepper->stop();
        }
    }

    if (isRunning) {
        currentStopButton->read();
        if (currentStopButton->isPressed()) {
            isRunning = false;
            if (stepper->isRunning()) {
                stepper->stop();
            }
        }
    }
}

void Engine::startEngine(int speed) {
    int direction = getDirection();
    currentStopButton = getCurrentStopButton(direction);
    stepper->setMaxSpeed(speed * direction);
    stepper->setSpeed(speed * direction);
    isRunning = true;
}

void Engine::runSlow() {
    startEngine(slowSpeed);
}

void Engine::runFast() {
    startEngine(fastSpeed);
}

int Engine::getDirection() {
    leftStopButton->read();
    if (leftStopButton->isPressed()) {
        lastStopBorder = 1;
        return 1;
    }

    rightStopButton->read();
    if (rightStopButton->isPressed()) {
        lastStopBorder = 2;
        return -1;
    }

    if (lastStopBorder == 2) {
        return -1;
    }

    return 1;
}

boolean Engine::running() {
    return isRunning;
}

Button* Engine::getCurrentStopButton(int direction) {
    if (direction == 1) {
        return rightStopButton;
    }
    return leftStopButton;
}