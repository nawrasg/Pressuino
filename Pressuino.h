#ifndef PRESSUINO_H
#define PRESSUINO_H

#include "Arduino.h"

class Pressuino{
public :
    void begin(int pin, boolean state, int min, int max); //state = button state when pressed
    boolean press();
    unsigned long lastTimestamp();
private:
    int pinButton, nDelayMin, nDelayMax;
    boolean nState;
    unsigned long nLastPress, nLastTimestamp;
};

#endif // PRESSUINO_H
