
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "hi user";
  Note subNote = note.subNote(3);
  
  Serial.print("subNote size: ");Serial.println(subNote.length());

  for(char value : subNote){
    Serial.print(value);
  }
  
  Serial.println();
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
