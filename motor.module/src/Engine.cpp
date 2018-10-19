#include "Engine.h"
#include "GlobalConstants.h"
#include <CommunicationCommands.h>

void Engine::init(CardReader* cardReader) {
    stepper = new AccelStepper(1, GlobalConstants::PULL_PIN, GlobalConstants::DIR_PIN);
    this->cardReader = cardReader;

    slowSpeed = cardReader->readFloatFromFile("rpm.slow.ini", 1.0);
    fastSpeed = cardReader->readFloatFromFile("rpm.fast.ini", 2.0);
    reverse = cardReader->readIntFromFile("reverse.ini", 1);
    leftStopButton = new FinishButton(GlobalConstants::LEFT_STOPPER_PIN);
    rightStopButton = new FinishButton(GlobalConstants::RIGHT_STOPPER_PIN);
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
        if (currentStopButton->wasPressed()) {
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

void Engine::startEngine(float speed) {
    int direction = getDirection();
    currentStopButton = getCurrentStopButton(direction);
    currentStopButton->reset();
    stepper->setMaxSpeed(speed * direction * reverse);
    stepper->setSpeed(speed * direction * reverse);
    isRunning = true;
}

void Engine::runSlow() {
    startEngine(slowSpeed);
}

void Engine::runFast() {
    startEngine(fastSpeed);
}

int Engine::getDirection() {
    if (leftStopButton->isPressed()) {
        lastStopBorder = LEFT_STOPPER;
        return DIRECTION_FORWARD;
    }

    if (rightStopButton->isPressed()) {
        lastStopBorder = RIGHT_STOPPER;
        return DIRECTION_BACKWARD;
    }

    if (lastStopBorder == RIGHT_STOPPER) {
        return DIRECTION_BACKWARD;
    }

    return DIRECTION_FORWARD;
}

FinishButton* Engine::getCurrentStopButton(int direction) {
    if (direction == DIRECTION_FORWARD) {
        return rightStopButton;
    }
    return leftStopButton;
}