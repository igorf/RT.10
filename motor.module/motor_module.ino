#include <AFMotor.h>
#include <Arduino.h>
#include <VirtualWire.h>
#include <AccelStepper.h>
#include "Communicator.h"
#include "Engine.h"

const uint8_t COMMUNICATION_PIN = A0;
const uint8_t LEFT_STOPPER_PIN  = A1;
const uint8_t RIGHT_STOPPER_PIN = A2;

const int MOTOR_STEPS_PER_ROTATION = 12;
const int MOTOR_SLOT = 2;
const int FAST_RPM = 64;
const int SLOW_RPM = 32;

AF_Stepper motor(MOTOR_STEPS_PER_ROTATION, MOTOR_SLOT);

void forwardstep() {
    motor.onestep(FORWARD, DOUBLE);
}

void backwardstep() {
    motor.onestep(BACKWARD, DOUBLE);
}

AccelStepper* stepper = new AccelStepper(forwardstep, backwardstep);
Communicator* communicator = new Communicator();
Engine* engine = new Engine();

void setup() {
    communicator->init(COMMUNICATION_PIN);
    engine->init(stepper, SLOW_RPM, FAST_RPM, LEFT_STOPPER_PIN, RIGHT_STOPPER_PIN);
}

void loop() {
    int command = communicator->getCommand();

    engine->command(command);
    if (engine->running()) {
        stepper->runSpeed();
    }
}