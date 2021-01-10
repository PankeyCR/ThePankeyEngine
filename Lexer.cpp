
#ifndef Lexer_cpp
#define Lexer_cpp

#include "Lexer.h"

	
	Lexer::Lexer(){
		this->captureToken = new PrimitiveMap<String,String>();
		this->delimiterToken = new PrimitiveMap<String,String>();
		
		this->tokens = new LinkedList<String>();
		this->primitiveClasses = new LinkedList<String>();
		this->breakPoint = new LinkedList<char>();
		this->delimiterCatcher = new PrimitiveMap<String,int>();
	}
	
	Lexer::~Lexer(){
		delete this->captureToken;
		delete this->delimiterToken;
		delete this->tokens;
		delete this->primitiveClasses;
		delete this->breakPoint;
		delete this->delimiterCatcher;
	}
	
	void Lexer::capture(char chr){
		this->captureChar = chr;
		//Serial.println("start capture "+String(chr));
		
		if(this->delimiterCatcher->getPosition() >= 1){
			bool deleteCatcher = false;
			LinkedList<String> deleteCatcherList(false);
			for(Iterator i : *this->delimiterCatcher){
				int* delPosition = this->delimiterCatcher->getPointer(i);
				String* delToken = this->delimiterCatcher->getKeyPointer(i);
				
				(*delPosition)++;
				if(*delPosition == delToken->length() && this->delimiterCatcher->getPosition() == 1){
					deleteCatcher = true;
					break;
				}
				if(*delPosition == delToken->length() && this->delimiterCatcher->getPosition() > 1){
					deleteCatcherList.addPointer(delToken);
					continue;
				}
				
				if(*delPosition <= delToken->length()){
					if(chr != delToken->charAt(*delPosition)){
						 deleteCatcherList.addPointer(delToken);
					}
				}
			}
			for(Iterator di : deleteCatcherList){
				this->delimiterCatcher->removeDeleteByPointer(deleteCatcherList.getPointer(di));
			}
			if(deleteCatcher){
				this->delimiterCatcher->resetDelete();
				if(this->reading != ""){
					String tkn = this->getToken(this->reading);
					if(tkn != ""){
						this->captureToken->addLValues(tkn,this->reading);
						this->reading = "";
					}
				}
			}
		}
		
		if(this->delimiterCatcher->isEmpty()){
			for(Iterator dt : *this->delimiterToken){
				String delToken = this->delimiterToken->getLValue(dt);
				if(delToken.charAt(0) == chr){
					this->delimiterCatcher->addPointers(new String(delToken),new int(0));
					if(this->reading != ""){
						String tkn = this->getToken(this->reading);
						if(tkn != ""){
							this->captureToken->addLValues(tkn,this->reading);
							this->reading = "";
						}else{
							this->captureToken->addLValues("Variable",this->reading);
							this->reading = "";
						}
					}
				}
			}
		}
		
		if(this->breakPoint->containByLValue(chr)){
			if(this->reading != ""){
				String tkn = this->getToken(this->reading);
				if(tkn != ""){
					this->captureToken->addLValues(tkn,this->reading);
					this->reading = "";
					return;
				}else{
					this->captureToken->addLValues("Variable",this->reading);
					this->reading = "";
					return;
				}
			}else{
				return;
			}
		}
		this->reading.concat(chr);
		return;
	}
	
	bool Lexer::isString(String mns){
        char mnsArray[mns.length()+1];
        mns.toCharArray(mnsArray, mns.length()+1);
		
		if(mnsArray[0]!='"'){
			return false;
		}
		if(mnsArray[mns.length()-1]!='"'){
			return false;
		}
        for(int i=0; i < mns.length(); i++){
			if(i!=0 && i!=mns.length()-1){
				if(mnsArray[i]=='"'){
					return false;
				}
			}
		}
		return true;
	}
	
	bool Lexer::isFloat(String mns){ 
        char mnsArray[mns.length() + 1];
        mns.toCharArray(mnsArray, mns.length() + 1);
		
		if(mnsArray[mns.length()-1]!='f'){
			return false;
		}
		bool dpoint = true;
        for(int i=0; i < mns.length(); i++){
			if(i!=mns.length()-1){
				if(mnsArray[i] != '0' && mnsArray[i] != '1' && mnsArray[i] != '2' && mnsArray[i] != '3' && mnsArray[i] != '4' &&
				   mnsArray[i] != '5' && mnsArray[i] != '6' && mnsArray[i] != '7' && mnsArray[i] != '8' && mnsArray[i] != '9'){
					if(mnsArray[i] == '.'){
						if(dpoint){
							dpoint =false;
						}else{
							return false;
						}
					}else{
						return false;
					}
				}
			}
		}
		return true;
	}
	
	bool Lexer::isInt(String mns){
        char mnsArray[mns.length() + 1];
        mns.toCharArray(mnsArray, mns.length() + 1);
		
        for(int i=0; i < mns.length(); i++){
			if(mnsArray[i] != '0' && mnsArray[i] != '1' && mnsArray[i] != '2' && mnsArray[i] != '3' && mnsArray[i] != '4' &&
			   mnsArray[i] != '5' && mnsArray[i] != '6' && mnsArray[i] != '7' && mnsArray[i] != '8' && mnsArray[i] != '9'){
				return false;
			}
		}
		return true;
	}
	
	bool Lexer::isLong(String mns){
        char mnsArray[mns.length() + 1];
        mns.toCharArray(mnsArray, mns.length() + 1);
		
		if(mnsArray[mns.length()-1]!='l'){
			return false;
		}
		
        for(int i=0; i < mns.length(); i++){
			if(i!=mns.length()-1){
				if(mnsArray[i] != '0' && mnsArray[i] != '1' && mnsArray[i] != '2' && mnsArray[i] != '3' && mnsArray[i] != '4' &&
				   mnsArray[i] != '5' && mnsArray[i] != '6' && mnsArray[i] != '7' && mnsArray[i] != '8' && mnsArray[i] != '9'){
					return false;
				}
			}
		}
		return true;
	}
	
	bool Lexer::isDouble(String mns){ 
        char mnsArray[mns.length() + 1];
        mns.toCharArray(mnsArray, mns.length() + 1);
		
		if(mnsArray[mns.length()-1]!='d'){
			return false;
		}
		
		bool dpoint = true;
        for(int i=0; i < mns.length(); i++){
			if(i!=mns.length()-1){
				if(mnsArray[i] != '0' && mnsArray[i] != '1' && mnsArray[i] != '2' && mnsArray[i] != '3' && mnsArray[i] != '4' &&
				   mnsArray[i] != '5' && mnsArray[i] != '6' && mnsArray[i] != '7' && mnsArray[i] != '8' && mnsArray[i] != '9'){
					if(mnsArray[i] == '.'){
						if(dpoint){
							dpoint =false;
						}else{
							return false;
						}
					}else{
						return false;
					}
				}
			}
		}
		return true;
	}
	
	String Lexer::getToken(String tkn){
		if(this->isDouble(tkn)){
			return "Double";
		}
		if(this->isFloat(tkn)){
			return "Float";
		}
		if(this->isString(tkn)){
			return "String";
		}
		if(this->isInt(tkn)){
			return "Int";
		}
		if(this->isLong(tkn)){
			return "Long";
		}
		if(this->tokens->containByLValue(tkn)){
			return tkn;
		}
		if(this->primitiveClasses->containByLValue(tkn)){
			return "ClassName";
		}
		if(this->delimiterToken->containValueByLValue(tkn)){
			return *this->delimiterToken->getKeyByLValue(tkn);
		}
		
		return "";
	}
	
	String Lexer::getActualToken(){
		return this->reading;
	}
	
	String Lexer::getCapturedToken(int x){
		String* token = this->captureToken->getByPosition(x);
		if(token == nullptr){
			return "";
		}
		return *token;
	}
	
	Map<String,String>* Lexer::getCapturedToken(){
		return this->captureToken;
	}
	
	Lexer* Lexer::addToken(String tkn){
		this->tokens->addLValue(tkn);
		return this;
	}
	
	Lexer* Lexer::addPrimitiveClass(String cls){
		this->primitiveClasses->addLValue(cls);
		return this;
	}
	
	Lexer* Lexer::addBreakPoint(char brk){
		this->breakPoint->addLValue(brk);
		return this;
	}
	
	Lexer* Lexer::addDelimiterToken(String name,String dlm){
		this->delimiterToken->addLValues(name,dlm);
		return this;
	}
	
	void Lexer::printTokens(Stream* port){
		for(Iterator i : *this->getCapturedToken()){
			port->print(this->getCapturedToken()->getKey(i));
			port->print(" ");
			port->println(this->getCapturedToken()->getLValue(i));
		}
	}
	
#endif 