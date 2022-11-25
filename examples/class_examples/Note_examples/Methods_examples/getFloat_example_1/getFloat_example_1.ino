
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note;
  char* i_char = note.getFloat(123.456f);
  Serial.println(i_char);
  delete i_char;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 