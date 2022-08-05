
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "hi username";
  Note subNote = note.substring(3, 7);
  
  Serial.print("subNote length: ");Serial.println(subNote.length());
  
  Serial.println(subNote);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
