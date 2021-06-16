
#ifndef Lexer_cpp
#define Lexer_cpp

#include "Lexer.h"

	
	Lexer::Lexer(){
		this->tokens = new PrimitiveList<Token>();
		this->capturedTokens = new PrimitiveList<Token>();
		this->breakPoint = new PrimitiveList<char>();
	}
	
	Lexer::~Lexer(){
		delete this->tokens;
		delete this->capturedTokens;
		delete this->breakPoint;
	}
	
	bool Lexer::isString(String mns){
        char mnsArray[mns.length()+1];
        mns.toCharArray(mnsArray, mns.length()+1);
		
		if(mnsArray[0]!='"' && mnsArray[0]!='\''){
			return false;
		}
		if(mnsArray[mns.length()-1]!='"' && mnsArray[mns.length()-1]!='\''){
			return false;
		}
        for(int i=0; i < mns.length(); i++){
			if(i!=0 && i!=mns.length()-1){
				if(mnsArray[i]=='"' && mnsArray[i]=='\''){
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
	
	bool Lexer::isToken(String mns){
		for(int x = 0; x < tokens->getPosition(); x++){
			Token* t = tokens->getByPosition(x);
			if(t->name == mns || t->type == mns){
				return true;
			}
		}
		return false;
	}
	
	bool Lexer::isVariable(String mns){
		if(environment == nullptr){
			return false;
		}
		return environment->containVariable(mns);
	}
	
	Token Lexer::getToken(String tkn){
		if(this->isDouble(tkn)){
			return Token(tkn,"Double","");
		}
		if(this->isFloat(tkn)){
			return Token(tkn,"Float","");
		}
		if(this->isString(tkn)){
			return Token(tkn,"String","");
		}
		if(this->isInt(tkn)){
			return Token(tkn,"Int","");
		}
		if(this->isLong(tkn)){
			return Token(tkn,"Long","");
		}
		for(int x = 0; x < this->tokens->getPosition(); x++){
			Token* t = this->tokens->getByPosition(x);
			if(t->name == tkn || t->type == tkn){
				return Token(t->name,t->type,t->info,t->text_Position,t->line_Position,t->list_Position);
			}
		}
		if(environment == nullptr){
			return Token("","","ERROR");
		}
		return environment->getToken(tkn);
	}
	
	// LinkedList<Token> Lexer::getTokens(String s){
		// LinkedList<Token> list;
		
		// return list;
	// }
	
	bool Lexer::containBreakPoint(char brk){
		return this->breakPoint->containByLValue(brk);
	}
	
	void Lexer::addCapturedTokens(Token tkn){
		this->capturedTokens->addLValue(tkn);
	}
	
	List<Token>* Lexer::getCapturedTokens(){
		return this->capturedTokens;
	}
	
	Lexer* Lexer::addTokenStructure(Token tkn){
		this->tokens->addLValue(tkn);
		return this;
	}
	
	Lexer* Lexer::addBreakPoint(char brk){
		this->breakPoint->addLValue(brk);
		return this;
	}
	
	void Lexer::setEnvironment(Environment* e){
		this->environment = e;
	}
	
	Environment* Lexer::getEnvironment(){
		return this->environment;
	}
	
	void Lexer::printTokens(Stream* port){
		port->println("Printing Tokens:");
		for(int x = 0; x < this->capturedTokens->getPosition(); x++){
			Token* t = capturedTokens->getByPosition(x);
			port->println(*t);
		}
	}
	
	bool Lexer::syntax(){
		for(int x = 0; x < this->capturedTokens->getPosition(); x++){
			Token* t = capturedTokens->getByPosition(x);
			if(t->info == "error"){
				return false;
			}
		}
		return true;
	}
	
	void Lexer::printError(Stream* port){
		port->println("Printing Errors:");
		// for(int x = 0; x < this->capturedTokens->getPosition(); x++){
			// Token* t = capturedTokens->getByPosition(x);
			// port->println(*t);
		// }
	}
	
	void Lexer::capture(char chr){}
	
#endif 
