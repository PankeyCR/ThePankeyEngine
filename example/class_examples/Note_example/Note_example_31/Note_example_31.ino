
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

  char* n_char = new char[5];
  for(int x = 0; x < 4; x++){
    n_char[x] = x + 48 + 4;
  }
  n_char[4] = '\0';
  
  Serial.println(n_char);
  Serial.println(Note::length(n_char));
  
  char* i_char = new char[9];
  Note::copy(i_char, m_char);
  Note::concat(i_char, n_char);
  
  Serial.println(i_char);
  Serial.println(Note::length(i_char));

  delete m_char;
  delete n_char;
  delete i_char;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
