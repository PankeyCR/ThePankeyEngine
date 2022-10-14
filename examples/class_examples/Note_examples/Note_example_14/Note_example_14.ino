
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = Note("hi user,") + Note(" trying to") + Note(" add notes");
  
  Serial.println(note);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
