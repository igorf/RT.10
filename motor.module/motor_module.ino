#include <AFMotor.h>
#include <Arduino.h>
#include <VirtualWire.h>
#include <AccelStepper.h>

#include "Communicator.h"
#include "Engine.h"
#include "Calibrator.h"

const uint8_t COMMUNICATION_PIN = A0;
const uint8_t LEFT_STOPPER_PIN  = A1;
const uint8_t RIGHT_STOPPER_PIN = A2;
const uint8_t LEFT_MEASURE_PIN  = A3;
const uint8_t RIGHT_MEASURE_PIN = A4;

const int MOTOR_STEPS_PER_ROTATION = 12;
const int MOTOR_SLOT = 2;
const int FAST_RPM = 64;
const int SLOW_RPM = 32;

AF_Stepper motor(MOTOR_STEPS_PER_ROTATION, MOTOR_SLOT);

void forwardStep() {
    motor.onestep(FORWARD, DOUBLE);
}

void backwardStep() {
    motor.onestep(BACKWARD, DOUBLE);
}

AccelStepper* stepper = new AccelStepper(forwardStep, backwardStep);
Communicator* communicator = new Communicator();
Engine* engine = new Engine();
Calibrator* calibrator = new Calibrator();

void setup() {
    Serial.begin(9600);

    communicator->init(COMMUNICATION_PIN);
    engine->init(stepper, SLOW_RPM, FAST_RPM, LEFT_STOPPER_PIN, RIGHT_STOPPER_PIN);
    calibrator->init(LEFT_MEASURE_PIN, RIGHT_MEASURE_PIN);
}

void loop() {
    int command = communicator->getCommand();
    engine->command(command);
    calibrator->commandFromCommunicator(command);
}