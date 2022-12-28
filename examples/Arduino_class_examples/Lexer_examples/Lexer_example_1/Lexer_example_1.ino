
#include "Lexer.hpp"
#include "Note.hpp"
#include "System.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Lexer lexer;

  Token bool_value = lexer.getToken("1");
  System::console.println(bool_value);

  Token int_value = lexer.getToken("15");
  System::console.println(int_value);

  Token long_value = lexer.getToken("123456789l");
  System::console.println(long_value);

  Token float_value = lexer.getToken("123.4567f");
  System::console.println(float_value);

  Token number_value = lexer.getToken("123.4567");
  System::console.println(number_value);

  Token note_value = lexer.getToken("\"Hellow\"");
  System::console.println(note_value);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}





//