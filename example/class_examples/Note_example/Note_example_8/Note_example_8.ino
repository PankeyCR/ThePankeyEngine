
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = -150;
  
  Serial.print("size: ");Serial.println(note.length());

  for(char value : note){
    Serial.print(value);
  }
  
  Serial.println();
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
