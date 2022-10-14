
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = 'h';
  Serial.println(note);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
