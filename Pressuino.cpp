#include "Arduino.h"
#include "Pressuino.h"

void Pressuino::begin(int pin, boolean state, int min, int max){
    pinButton = pin;
    nState = state;
    nDelayMin = min;
    nDelayMax = max;
    nLastPress = 0;
    nLastTimestamp = 0;
    pinMode(pinButton, INPUT);
}

boolean Pressuino::press(){
    if(digitalRead(pinButton) == nState){
        unsigned long nMoment = millis();
        if(((nMoment - nLastPress) < nDelayMax) && ((nMoment - nLastPress) > nDelayMin)){
                nLastTimestamp = nMoment;
            return true;
        }else{
            nLastPress = millis();
            return false;
        }
    }else{
        return false;
    }
}

unsigned long Pressuino::lastTimestamp(){
    return nLastTimestamp;
}
