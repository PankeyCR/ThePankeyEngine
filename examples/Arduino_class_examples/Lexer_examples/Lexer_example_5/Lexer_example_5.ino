
#include "Lexer.hpp"
#include "System.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note script = "++ ==";
  
  Lexer lexer;
  lexer.addBreakPoint(' ');

  lexer.addDelimiterToken(Token("sum","++"));
  lexer.addDelimiterToken(Token("equal","=="));

  lexer.capture(script);

  System::console.println(lexer);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}





//