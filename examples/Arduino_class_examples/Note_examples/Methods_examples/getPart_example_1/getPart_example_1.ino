
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "hi user";
  Note part = note.getPart(3);
  
  Serial.print("part size: ");Serial.println(part.length());

  for(char value : part){
    Serial.print(value);
  }
  
  Serial.println();
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 