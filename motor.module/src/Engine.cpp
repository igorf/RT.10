#include "Engine.h"
#include <CommunicationCommands.h>

void Engine::init(AccelStepper *stepperPtr, int slowRPM, int fastRPM, uint8_t leftButton, uint8_t rightButton) {
    slowSpeed = slowRPM;
    fastSpeed = fastRPM;
    leftStopButton = new Button(leftButton, false, false, 1);
    rightStopButton = new Button(rightButton, false, false, 1);
    stepper = stepperPtr;
}

void Engine::command(int command) {
    if (command == CommunicationCommands::RUN_SLOW || command == CommunicationCommands::RESET) {
        if (!isRunning) {
            runSlow();
        }
    } else if (command == CommunicationCommands::RUN_FAST) {
        if (!isRunning) {
            runFast();
        }
    } else if (command == CommunicationCommands::STOP) {
        stop();
    }

    if (isRunning) {
        currentStopButton->read();
        if (currentStopButton->isPressed()) {
            stop();
        } else {
            stepper->runSpeed();
        }
    }
}

void Engine::stop() {
    isRunning = false;
    if (stepper->isRunning()) {
        stepper->stop();
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
        lastStopBorder = LEFT_STOPPER;
        return DIRECTION_FORWARD;
    }

    rightStopButton->read();
    if (rightStopButton->isPressed()) {
        lastStopBorder = RIGHT_STOPPER;
        return DIRECTION_BACKWARD;
    }

    if (lastStopBorder == RIGHT_STOPPER) {
        return DIRECTION_BACKWARD;
    }

    return DIRECTION_FORWARD;
}

boolean Engine::running() {
    return isRunning;
}

Button* Engine::getCurrentStopButton(int direction) {
    if (direction == DIRECTION_FORWARD) {
        return rightStopButton;
    }
    return leftStopButton;
}