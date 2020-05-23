
#ifndef SerialScriptState_cpp
#define SerialScriptState_cpp

#include "SerialScriptState.h"

	
	SerialScriptState::SerialScriptState(Stream* serialPort){
		this->id = new String("SerialScriptState");
		this->port = serialPort;
	}
	
	SerialScriptState::SerialScriptState(Stream* serialPort,Stream* extraPort){
		this->id = new String("SerialScriptState");
		this->port = serialPort;
		this->extraSerial = extraPort;
	}
	
	SerialScriptState::~SerialScriptState(){
		if(this->lexer != nullptr){
			delete this->lexer;
			this->lexer = nullptr;
		}
		if(this->serial != nullptr){
			delete this->serial;
			this->serial = nullptr;
		}
		this->port = nullptr;
	}
	
	void SerialScriptState::setSerialStart(char s){
		this->start = s;
	}
	
	void SerialScriptState::setSerialEnd(char e){
		this->end = e;
	}
	
	String SerialScriptState::getClassName(){
		return "SerialScriptState";
	}
	
	String SerialScriptState::toString(){
		return "SerialScriptState";
	}
	
	void SerialScriptState::initialize(Application *app){
		this->lexer = new Lexer();
		this->serial = new SerialConnection();
		this->serial->setPort(this->port);
		
		this->lexer->	addToken("if")->
						addToken("while")->
						addToken("iterate")->
						addToken("for")->
						addToken("class")->
						addToken("interface")->
						addToken("extend")->
						addToken("implement")->
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
						
						// addCompareToken("isEqual", "==")->
						// addCompareToken("notEqual", "!=")->
						// addCompareToken("smallerEqual", "<=")->
						// addCompareToken("greatterEqual", ">=")->
						// addCompareToken("smaller", "<")->
						// addCompareToken("greatter", ">")->
						
						// addDelimiterToken("classDelimiter",'.')->
						// addDelimiterToken("Lparenthesis",'(')->
						// addDelimiterToken("Rparenthesis",')')->
						// addDelimiterToken("LCurlyB",'{')->
						// addDelimiterToken("RCurlyB",'}')->
						// addDelimiterToken("endCodeLine",';')->
						// addDelimiterToken("Dpoint",':')->
						// addDelimiterToken("coma",',')->
						
						// addDelimiterToken("equal",'=')->
						// addDelimiterToken("sum",'+')->
						// addDelimiterToken("sub",'-')->
						// addDelimiterToken("mul",'*')->
						// addDelimiterToken("div",'/')->
						// addDelimiterToken("exclamation",'!')->
						// addDelimiterToken("question",'?');
						
						addDelimiterToken("classDelimiter",".")->
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
						
						addDelimiterToken("equal","=")->
						addDelimiterToken("sum","+")->
						addDelimiterToken("sub","-")->
						addDelimiterToken("mul","*")->
						addDelimiterToken("div","/")->
						addDelimiterToken("exclamation","!")->
						addDelimiterToken("question","?");
		
		
	}
	
	void SerialScriptState::update(){
		//String mns = this->serial->getString();
		String mns = this->serial->safeReceive(this->start,this->end);
		
		if(mns == ""){
			return;
		}
		if(extraSerial!=nullptr){
			extraSerial->println(mns);
		}else{
			if(port!=nullptr){
				port->println(mns);
			}
		}
		
        int mnsLenght = mns.length() + 1; 
        char mnsArray[mnsLenght];
        mns.toCharArray(mnsArray, mnsLenght);
		
        for(int i=0; i < mnsLenght; i++){
			this->lexer->capture(mnsArray[i]);
        }
		
		if(this->lexer->syntaxError()){
			if(extraSerial!=nullptr){
				extraSerial->println("syntaxError");
			}else{
				if(port!=nullptr){
					port->println("syntaxError");
				}
			}
			return;
		}
		if(extraSerial!=nullptr){
			extraSerial->println(this->lexer->getCapturedToken()->getPos());
			iterate(this->lexer->getCapturedToken()){
				extraSerial->print(this->lexer->getCapturedToken()->getKey());
				extraSerial->print(" ");
				extraSerial->println(this->lexer->getCapturedToken()->getValue());
			}
		}else{
			if(port!=nullptr){
				port->println(this->lexer->getCapturedToken()->getPos());
				iterate(this->lexer->getCapturedToken()){
					port->print(this->lexer->getCapturedToken()->getKey());
					port->print(" ");
					port->println(this->lexer->getCapturedToken()->getValue());
				}
			}
		}
		this->lexer->getCapturedToken()->resetDelete();
	}
	
#endif 