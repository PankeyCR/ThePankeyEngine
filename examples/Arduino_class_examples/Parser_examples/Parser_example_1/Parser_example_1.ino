
#include "Lexer.hpp"
#include "System.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note script = "int x=(12+12)*12";
  
  Lexer lexer;
  lexer.addBreakPoint(' ');
  lexer.addTypeToken(Token("int","int"));
  lexer.addDelimiterToken(Token("equal","="));
  lexer.addDelimiterToken(Token("open_Parethesis","("));
  lexer.addDelimiterToken(Token("close_Parethesis",")"));
  lexer.addDelimiterToken(Token("sum","+"));
  lexer.addDelimiterToken(Token("mult","*"));

  lexer.capture(script);

  System::console.println(lexer);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}





//