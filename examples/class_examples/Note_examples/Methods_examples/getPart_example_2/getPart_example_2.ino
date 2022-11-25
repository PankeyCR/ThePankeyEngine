
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "hi username";
  Note part = note.getPart(3, 7);
  
  Serial.print("part size: ");Serial.println(part.length());
  
  Serial.println(part);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 