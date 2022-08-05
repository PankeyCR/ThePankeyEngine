
#include "Lexer.hpp"
#include "MemoryRam.h"

using namespace ame;

Note scriptText = Note("//simple script class\n")+
  "class ScriptClass{\n"+
  " int value=0;\n"+
  " void scriptMethod(int t){\n"+  
  "   value=(t*40)/(2.15d+1.6f);\n"+  
  " }\n"+  
  "};\n";
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(getRamSize());
//  Serial.println(scriptText);
  Lexer lexer;
  lexer.addTypeToken(Token("if"));
  lexer.addTypeToken(Token("while"));
  lexer.addTypeToken(Token("iterate"));
  lexer.addTypeToken(Token("for"));
  lexer.addTypeToken(Token("class"));
  lexer.addTypeToken(Token("interface"));
  lexer.addTypeToken(Token("extend"));
  lexer.addTypeToken(Token("implement"));
  lexer.addTypeToken(Token("void"));
  lexer.addTypeToken(Token("fun"));
  
  lexer.addTypeToken(Token("String"));
  lexer.addTypeToken(Token("int"));
  lexer.addTypeToken(Token("long"));
  lexer.addTypeToken(Token("double"));
  lexer.addTypeToken(Token("float"));
  
  lexer.addBreakPoint(' ');
  lexer.addBreakPoint('\r');
  lexer.addBreakPoint('\0');
  lexer.addBreakPoint('\n');
  
    //  \n can be a breaking point or a delimiter, that depends on the parser
    // and the lenguaje design
    
         //   addDelimiterToken("enter","\n"));
  lexer.addDelimiterToken(Token("comments","/*"));
  lexer.addDelimiterToken(Token("linecomments","//"));
  lexer.addDelimiterToken(Token("classDelimiter",";"));
  lexer.addDelimiterToken(Token("Lparenthesis","("));
  lexer.addDelimiterToken(Token("Rparenthesis",")"));
  lexer.addDelimiterToken(Token("LCurlyB","{"));
  lexer.addDelimiterToken(Token("RCurlyB","}"));
  lexer.addDelimiterToken(Token("endCodeLine",";"));
  lexer.addDelimiterToken(Token("Dpoint",":"));
  lexer.addDelimiterToken(Token("coma",","));
  
  lexer.addDelimiterToken(Token("equal","="));
  lexer.addDelimiterToken(Token("isEqual", "=="));
  lexer.addDelimiterToken(Token("notEqual", "!="));
  lexer.addDelimiterToken(Token("smallerEqual", "<="));
  lexer.addDelimiterToken(Token("greatterEqual", ">="));
  lexer.addDelimiterToken(Token("smaller", "<"));
  lexer.addDelimiterToken(Token("greatter", ">"));
  
  lexer.addDelimiterToken(Token("sum","+"));
  lexer.addDelimiterToken(Token("sub","-"));
  lexer.addDelimiterToken(Token("mul","*"));
  lexer.addDelimiterToken(Token("div","/"));
  lexer.addDelimiterToken(Token("exclamation","!"));
  lexer.addDelimiterToken(Token("question","?"));


  Serial.println("starting lexer capture");
  LexerCaptureNoteV(lexer,scriptText);
  
  Serial.println("printing tokens");
  lexer.printTokens(&Serial);

  Serial.println("////////////end");
  Serial.println(getRamSize());
}
