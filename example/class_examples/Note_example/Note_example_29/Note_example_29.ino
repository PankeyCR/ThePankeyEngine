
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  char* m_char = new char[5];
  for(int x = 0; x < 4; x++){
    m_char[x] = x + 48;
  }
  m_char[4] = '\0';
  Serial.println(m_char);
  Serial.println(Note::length(m_char));

  delete m_char;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
