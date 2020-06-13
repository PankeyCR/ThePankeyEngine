
#include "Lexer.h"
#include "MemoryFree.h"

String scriptText = String("//simple script class\n")+
  "class ScriptClass{\n"+
  " int value=0;\n"+
  " void scriptMethod(int t){\n"+  
  "   value=(t*40)/(2.15d+1.6f);\n"+  
  " }\n"+  
  "}\n";

int deletememory;
int startmemory;
int instancememory;
 
void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  Serial.println(scriptText);
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
            addBreakPoint('\n')->
            addBreakPoint('\r')->
            addBreakPoint('\0')->
            
            addDelimiterToken("comments","/*")->
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

  instancememory = freeMemory();

  for(int x = 0; x < scriptText.length(); x++){
    lexer->capture(scriptText.charAt(x));
  }
  
  //lexer->printTokens(&Serial);

  delete lexer;
  
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {

}
