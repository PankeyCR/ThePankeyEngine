
#include "trilean.h"

using namespace ame;

trilean state;

void setup() {
  Serial.begin(9600);

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
  
}

void loop() {


}
