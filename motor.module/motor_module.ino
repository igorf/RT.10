#include <Arduino.h>
#include <VirtualWire.h>
#include <AccelStepper.h>
#include <SD.h>

#include "Communicator.h"
#include "Engine.h"
//#include "Calibrator.h"
#include "CardReader.h"

CardReader* reader;
Communicator* communicator = new Communicator();
Engine* engine = new Engine();

void setup() {
    Serial.begin(9600);

    reader->init();
    communicator->init();
    engine->init(reader);
}

void loop() {
    int command = communicator->getCommand();
    engine->command(command);
    //calibrator->commandFromCommunicator(command);
}