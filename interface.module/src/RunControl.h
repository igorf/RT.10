#ifndef INTERFACE_MODULE_RUNCONTROL_H
#define INTERFACE_MODULE_RUNCONTROL_H

#include <stdint.h>
#include <Button.h>
#include "CommunicationCommands.h"

class RunControl {
public:
    void init(uint8_t stop, uint8_t reset);
    int check();

protected:
    Button *stopButton;
    Button *resetButton;

private:
    const int STOP_COMMAND = CommunicationCommands::STOP;
    const int RESET_COMMAND = CommunicationCommands::RESET;
    boolean stopReady = false;
    boolean resetReady = false;
};


#endif //INTERFACE_MODULE_RUNCONTROL_H
