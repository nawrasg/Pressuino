#include <Pressuino.h>

#define pinButton 5

Pressuino nButton;

void setup(){
  nButton.begin(5, LOW, 100, 1000);
  Serial.begin(9600);
}

void loop(){
  if(nButton.press()) Serial.println("Button pressed");
}
