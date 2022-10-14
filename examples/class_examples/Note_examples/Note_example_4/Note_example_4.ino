
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "note";
  Note n_note = note.add(" test example");
  Serial.println(n_note);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
