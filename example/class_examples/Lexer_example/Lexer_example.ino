
#include "Lexer.h"
#include "MemoryFree.h"

using namespace ame;

String scriptText = String("//simple script class\n")+
  "class ScriptClass{\n"+
  " int value=0;\n"+
  " void scriptMethod(int t){\n"+  
  "   value=(t*40)/(2.15d+1.6f);\n"+  
  " }\n"+  
  "}\n";
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
//  Serial.println(scriptText);
  Lexer* lexer = new Lexer();
  lexer->   addTypeToken(Token("if"))->
            addTypeToken(Token("while"))->
            addTypeToken(Token("iterate"))->
            addTypeToken(Token("for"))->
            addTypeToken(Token("class"))->
            addTypeToken(Token("interface"))->
            addTypeToken(Token("extend"))->
            addTypeToken(Token("implement"))->
            addTypeToken(Token("void"))->
            addTypeToken(Token("fun"))->
            
            addTypeToken(Token("String"))->
            addTypeToken(Token("int"))->
            addTypeToken(Token("long"))->
            addTypeToken(Token("double"))->
            addTypeToken(Token("float"))->
            
            addBreakPoint(' ')->
            addBreakPoint('\r')->
            addBreakPoint('\0')->
            addBreakPoint('\n')->
            
    //  \n can be a breaking point or a delimiter, that depends on the parser
    // and the lenguaje design
    
         //   addDelimiterToken("enter","\n"))->
            addDelimiterToken(Token("comments","/*"))->
            addDelimiterToken(Token("linecomments","//"))->
            addDelimiterToken(Token("classDelimiter","->"))->
            addDelimiterToken(Token("Lparenthesis","("))->
            addDelimiterToken(Token("Rparenthesis",")"))->
            addDelimiterToken(Token("LCurlyB","{"))->
            addDelimiterToken(Token("RCurlyB","}"))->
            addDelimiterToken(Token("endCodeLine",";"))->
            addDelimiterToken(Token("Dpoint",":"))->
            addDelimiterToken(Token("coma",","))->
            
            addDelimiterToken(Token("equal","="))->
            addDelimiterToken(Token("isEqual", "=="))->
            addDelimiterToken(Token("notEqual", "!="))->
            addDelimiterToken(Token("smallerEqual", "<="))->
            addDelimiterToken(Token("greatterEqual", ">="))->
            addDelimiterToken(Token("smaller", "<"))->
            addDelimiterToken(Token("greatter", ">"))->
            
            addDelimiterToken(Token("sum","+"))->
            addDelimiterToken(Token("sub","-"))->
            addDelimiterToken(Token("mul","*"))->
            addDelimiterToken(Token("div","/"))->
            addDelimiterToken(Token("exclamation","!"))->
            addDelimiterToken(Token("question","?"));


  Serial.println("starting lexer capture");
  LexerCaptureString(lexer,scriptText);
  
  Serial.println("printing tokens");
  lexer->printTokens(&Serial);

  delete lexer;
  Serial.println("////////////end");
  Serial.println(freeMemory());
}
