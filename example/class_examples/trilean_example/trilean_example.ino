
#include "trilean.hpp"

using namespace ame;

trilean state;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////////////start");
  
  state=true;
  Serial.println(state==true);
  Serial.println(state!=true);
  Serial.println(state==false);
  Serial.println(state!=false);
  Serial.println(state==unknown);
  Serial.println(state!=unknown);
  state=false;
  Serial.println();
  Serial.println(state==true);
  Serial.println(state!=true);
  Serial.println(state==false);
  Serial.println(state!=false);
  Serial.println(state==unknown);
  Serial.println(state!=unknown);
  state=unknown;
  Serial.println();
  Serial.println(state==true);
  Serial.println(state!=true);
  Serial.println(state==false);
  Serial.println(state!=false);
  Serial.println(state==unknown);
  Serial.println(state!=unknown);
  Serial.println(unknown);
  
  Serial.println("////////////////////end");
}
