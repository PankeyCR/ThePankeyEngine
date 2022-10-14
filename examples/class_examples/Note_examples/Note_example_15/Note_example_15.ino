
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "check out at charAt method";
  
  for(int x = 0; x < note.length(); x++){
    Serial.print(note.charAt(x));
  }
  Serial.println();
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
