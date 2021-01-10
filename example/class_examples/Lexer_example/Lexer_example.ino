
#include "Lexer.h"
#include "MemoryFree.h"

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
  lexer->   addToken("if")->
            addToken("while")->
            addToken("iterate")->
            addToken("for")->
            addToken("class")->
            addToken("interface")->
            addToken("extend")->
            addToken("implement")->
            addToken("void")->
            addToken("fun")->
            
            addPrimitiveClass("String")->
            addPrimitiveClass("int")->
            addPrimitiveClass("long")->
            addPrimitiveClass("double")->
            addPrimitiveClass("float")->
            
            addBreakPoint(' ')->
            addBreakPoint('\r')->
            addBreakPoint('\0')->
            addBreakPoint('\n')->
            
    //  \n can be a breaking point or a delimiter, that depends on the parser
    // and the lenguaje design
    
         //   addDelimiterToken("enter","\n")->
            addDelimiterToken("comments","/*")->
            addDelimiterToken("linecomments","//")->
            addDelimiterToken("classDelimiter","->")->
            addDelimiterToken("Lparenthesis","(")->
            addDelimiterToken("Rparenthesis",")")->
            addDelimiterToken("LCurlyB","{")->
            addDelimiterToken("RCurlyB","}")->
            addDelimiterToken("endCodeLine",";")->
            addDelimiterToken("Dpoint",":")->
            addDelimiterToken("coma",",")->
            
            addDelimiterToken("equal","=")->
            addDelimiterToken("isEqual", "==")->
            addDelimiterToken("notEqual", "!=")->
            addDelimiterToken("smallerEqual", "<=")->
            addDelimiterToken("greatterEqual", ">=")->
            addDelimiterToken("smaller", "<")->
            addDelimiterToken("greatter", ">")->
            
            addDelimiterToken("sum","+")->
            addDelimiterToken("sub","-")->
            addDelimiterToken("mul","*")->
            addDelimiterToken("div","/")->
            addDelimiterToken("exclamation","!")->
            addDelimiterToken("question","?");


  Serial.println("starting lexer capture");
  for(int x = 0; x < scriptText.length(); x++){
    lexer->capture(scriptText.charAt(x));
  }
  
  Serial.println("printing tokens");
  lexer->printTokens(&Serial);

  delete lexer;
  Serial.println("////////////end");
  Serial.println(freeMemory());
}