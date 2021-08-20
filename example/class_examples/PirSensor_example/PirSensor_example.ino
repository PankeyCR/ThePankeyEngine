
#include "PirSensor.h"

using namespace ame;

PirSensor pir;

void setup() {
  Serial.begin(9600);
  pir.addPin(4);
}

void loop() {
  pir.update();
  if(pir.isPressed()){
    Serial.println("isPressed");
  }
  if(pir.isReleased()){
    Serial.println("isReleased");
  }
  if(pir.isClick()){
    Serial.println("isClick");
  }
}
