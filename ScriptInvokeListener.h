

#ifndef ScriptInvokeListener_h
#define ScriptInvokeListener_h

#include "Arduino.h"
#include "Command.h"
#include "Message.h"
#include "Note.h"
#include "Map.h"
#include "Method.h"
#include "Lexer.h"
#include "Parser.h"
#include "PrimitiveMap.h"
#include "Environment.h"
#include "ScriptState.h"

namespace ame{

class ScriptInvokeListener : public Command<Message>{
    public:
		ScriptInvokeListener(Application* app){
			lexer = initLexer();
			environment = new Environment();
			parser = initParser(environment);
			scriptState = (ScriptState*)app->getStateManager()->get("ScriptState");
		}
		ScriptInvokeListener(ScriptState* s){
			lexer = initLexer();
			environment = new Environment();
			parser = initParser(environment);
			scriptState = s;
		}
		
		ScriptInvokeListener(Lexer* l, Parser* p, ScriptState* s){
			lexer = l;
			environment = new Environment();
			parser = initParser(p, environment);
			scriptState = s;
		}
		
		ScriptInvokeListener(Lexer* l, Parser* p, Environment* e, ScriptState* s){
			lexer = l;
			environment = e;
			parser = initParser(p, environment);
			scriptState = s;
		}
		
		ScriptInvokeListener(Lexer* l, Parser* p, Application* app){
			lexer = l;
			environment = new Environment();
			parser = initParser(p, environment);
			scriptState = (ScriptState*)app->getStateManager()->get("ScriptState");
		}
		
		ScriptInvokeListener(Lexer* l, Parser* p, Environment* e, Application* app){
			lexer = l;
			environment = e;
			parser = initParser(p, environment);
			scriptState = (ScriptState*)app->getStateManager()->get("ScriptState");
		}
		~ScriptInvokeListener(){
			delete lexer;
			delete parser;
			delete environment;
		}

		void messageLoopType(String t){
			loopType = t;
		}

		void messageRunType(String t){
			runType = t;
		}

		void messageSaveType(String t){
			saveType = t;
		}

		void execute(Message* mns){
			if(mns->type() == runType){
				String note = mns->text();
				for(char c : note){
					lexer->capture(c);
				}
				parser->addLexerTokens(lexer);
				Script* script = parser->compile();
				if(script == nullptr){
					Serial.println("run no script");
					return;
				}
				script->run();
			}
			if(mns->type() == saveType){
				String note = mns->text();
				for(char c : note){
					lexer->capture(c);
				}
				parser->addLexerTokens(lexer);
				Script* script = parser->compile();
				if(script == nullptr){
					Serial.println("save no script");
					return;
				}
				scriptState->addScript(script);
			}
			if(mns->type() == loopType){
				String note = mns->text();
				for(char c : note){
					lexer->capture(c);
				}
				parser->addLexerTokens(lexer);
				Script* script = parser->compile();
				if(script == nullptr){
					lexer->printTokens(&Serial);
					Serial.println("loop no script");
					return;
				}
				scriptState->addLoopScript(script);
			}
		}

protected:

Lexer* initLexer(){
	Lexer* l = new Lexer();
	l-> 	addToken("if")->
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
			addPrimitiveClass("Object")->
			
			addBreakPoint(' ')->
			addBreakPoint('\r')->
			addBreakPoint('\0')->
			// addBreakPoint('\n')->
			
	//  \n can be a breaking point or a delimiter, that depends on the parser
	// and the lenguaje design
	
			addDelimiterToken("enter","\n")->
			addDelimiterToken("commentstart","/*")->
			addDelimiterToken("commentend","*/")->
			addDelimiterToken("linecomment","//")->
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
	return l;
}
Parser* initParser(Parser* p, Environment* e){
	p->setLineCommentToken("linecomment");
	p->setCommentTokens("commentstart","commentend");
	p->setLineCommentToken("linecomment");
	p->addBlock(e, "PrimiviteClass", "Variable", "endCodeLine");
	p->addBlock(e, "Variable");
	return p;
}
Parser* initParser(Environment* e){
	Parser* p = new Parser();
	return initParser(p, e);
}


String runType = "run";
String saveType = "loop";
String loopType = "loop";
Lexer* lexer = nullptr;
Parser* parser = nullptr;
Environment* environment = nullptr;
ScriptState* scriptState = nullptr;
	
};

}

#endif 
