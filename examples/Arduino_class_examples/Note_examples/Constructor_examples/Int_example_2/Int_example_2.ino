
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = 150;
  Serial.println(note);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 