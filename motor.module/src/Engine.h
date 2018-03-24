#ifndef ENGINE_MODULE_ENGINE_H
#define ENGINE_MODULE_ENGINE_H

#include <Arduino.h>
#include <AFMotor.h>
#include <AccelStepper.h>
#include <Button.h>

class Engine {
public:
    void init(AccelStepper *stepperPtr, int slowRPM, int fastRPM, uint8_t leftButton, uint8_t rightButton);
    void command(int command);
    boolean running();
private:
    int slowSpeed = 0;
    int fastSpeed = 0;
    int lastStopBorder = 0;
    AccelStepper *stepper;
    boolean isRunning = false;
    Button *leftStopButton;
    Button *rightStopButton;
    Button *currentStopButton;

    int getDirection();
    Button *getCurrentStopButton(int direction);
    void runSlow();
    void runFast();
    void startEngine(int speed);
};

#endif