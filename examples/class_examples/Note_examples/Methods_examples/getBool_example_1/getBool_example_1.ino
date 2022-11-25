
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note;
  char* i_char_1 = note.getBool(true);
  Serial.println(i_char_1);
  char* i_char_2 = note.getBool(false);
  Serial.println(i_char_2);
  delete i_char_1;
  delete i_char_2;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 