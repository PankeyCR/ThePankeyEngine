
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "spacetime";

  if(note == "spacetime"){
    Serial.println("is equal to spacetime");
  }
  if(note == "time"){
    Serial.println("is equal to time");
  }

  if(note != "spacetime"){
    Serial.println("is not equal to spacetime");
  }
  if(note != "time"){
    Serial.println("is not equal to time");
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
