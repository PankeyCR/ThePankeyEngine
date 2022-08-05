
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = 1562;
  Serial.println(note.toInt());
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
