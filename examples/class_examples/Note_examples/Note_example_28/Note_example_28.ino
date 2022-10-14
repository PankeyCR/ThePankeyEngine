
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = 1234.5678f;
  Serial.println(note.toFloat());
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
