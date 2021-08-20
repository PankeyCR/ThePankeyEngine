
#ifndef Lexer_cpp
#define Lexer_cpp

#include "Lexer.h"

	
	ame::Lexer::Lexer(){
		this->typeTokens = new ame::PrimitiveList<ame::Token>();
		this->delimiterTokens = new ame::PrimitiveList<ame::Token>();
		this->capturedTokens = new ame::PrimitiveList<ame::Token>();
		this->breakPoint = new ame::PrimitiveList<char>();
	}
	
	ame::Lexer::~Lexer(){
		delete this->typeTokens;
		delete this->delimiterTokens;
		delete this->capturedTokens;
		delete this->breakPoint;
	}
	
	String ame::Lexer::extractString(String mns){
        char mnsArray[mns.length()+1];
        mns.toCharArray(mnsArray, mns.length()+1);
		
		if(mnsArray[0] != '"' && mnsArray[mns.length()-1] != '"'){
			return mns;
		}
		String extract = "";
        for(int i=1; i < mns.length() - 1; i++){
			extract.concat(mnsArray[i]);
		}
		return extract;
	}
	
	bool ame::Lexer::isString(String mns){
        char mnsArray[mns.length()+1];
        mns.toCharArray(mnsArray, mns.length()+1);
		
		if(mnsArray[0]!='"' && mnsArray[mns.length()-1]!='"'){
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
	
	bool ame::Lexer::isFloat(String mns){ 
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
	
	bool ame::Lexer::isInt(String mns){
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
	
	bool ame::Lexer::isLong(String mns){
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
	
	bool ame::Lexer::isDouble(String mns){ 
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
	
	bool ame::Lexer::isTypeToken(String mns){
		for(int x = 0; x < typeTokens->getPosition(); x++){
			Token* t = typeTokens->getByPosition(x);
			if(t->name == mns){
				return true;
			}
		}
		return false;
	}
	
	bool ame::Lexer::isVariable(String mns){
		if(environment == nullptr){
			return false;
		}
		return environment->containVariable(mns);
	}
	
	ame::Token ame::Lexer::getToken(String tkn){
		if(this->isDouble(tkn)){
			return Token("Double",tkn,"");
		}
		if(this->isFloat(tkn)){
			return Token("Float",tkn,"");
		}
		if(this->isString(tkn)){
			return Token("String",tkn,"");
		}
		if(this->isInt(tkn)){
			return Token("Int",tkn,"");
		}
		if(this->isLong(tkn)){
			return Token("Long",tkn,"");
		}
		for(int x = 0; x < this->typeTokens->getPosition(); x++){
			ame::Token* t = this->typeTokens->getByPosition(x);
			if(t->name == tkn){
				return Token(tkn,tkn);
			}
		}
		for(int x = 0; x < this->delimiterTokens->getPosition(); x++){
			ame::Token* t = this->delimiterTokens->getByPosition(x);
			if(t->value == tkn){
				return Token(*t);
			}
		}
		if(environment != nullptr){
			return environment->getToken(tkn);
		}
		return Token("Variable",tkn);
	}
	
	// LinkedList<Token> ame::Lexer::getTokens(String s){
		// LinkedList<Token> list;
		
		// return list;
	// }
	
	void ame::Lexer::addCapturedTokens(Token tkn){
		this->capturedTokens->addLValue(tkn);
	}
	
	int ame::Lexer::getCapturedTokensPosiotion(){
		return this->capturedTokens->getPosition();
	}
	
	ame::List<ame::Token>* ame::Lexer::getCapturedTokens(){
		return this->capturedTokens;
	}
	
	ame::Lexer* ame::Lexer::addBreakPoint(char brk){
		this->breakPoint->addLValue(brk);
		return this;
	}
	
	bool ame::Lexer::containBreakPoint(char brk){
		return this->breakPoint->containByLValue(brk);
	}
	
	ame::Lexer* ame::Lexer::addTypeToken(Token tkn){
		this->typeTokens->addLValue(tkn);
		return this;
	}
	
	bool ame::Lexer::containTypeToken(String t){
		for(int x = 0; x < this->typeTokens->getPosition(); x++){
			Token* token = this->typeTokens->getByPosition(x);
			if(t == token->name){
				return true;
			}
		}
		return false;
	}
	
	ame::Lexer* ame::Lexer::addDelimiterToken(Token tkn){
		this->delimiterTokens->addLValue(tkn);
		return this;
	}
	
	bool ame::Lexer::containDelimiterToken(String t){
		for(int x = 0; x < this->delimiterTokens->getPosition(); x++){
			Token* token = this->delimiterTokens->getByPosition(x);
			if(t == token->value){
				return true;
			}
		}
		return false;
	}
	
	bool ame::Lexer::containDelimiterTokenChar(int x, char c){
		for(int xc = 0; xc < this->delimiterTokens->getPosition(); xc++){
			Token* token = this->delimiterTokens->getByPosition(xc);
			String t = token->value;
			char mnsArray[t.length() + 1];
			t.toCharArray(mnsArray, t.length() + 1);
			
			if( (t.length()-1) < x ){
				continue;
			}
			if(mnsArray[x] == c){
				return true;
			}
		}
		return false;
	}
	
	int ame::Lexer::getDelimiterTokenSize(){
		return this->delimiterTokens->getPosition();
	}
	
	void ame::Lexer::setEnvironment(Environment* e){
		this->environment = e;
	}
	
	ame::Environment* ame::Lexer::getEnvironment(){
		return this->environment;
	}
	
	void ame::Lexer::printTokens(Stream* port){
		for(int x = 0; x < this->capturedTokens->getPosition(); x++){
			Token* t = capturedTokens->getByPosition(x);
			port->println(*t);
		}
	}
	
	bool ame::Lexer::syntax(){
		for(int x = 0; x < this->capturedTokens->getPosition(); x++){
			Token* t = capturedTokens->getByPosition(x);
			if(t->info == "error"){
				return false;
			}
		}
		return true;
	}
	
	void ame::Lexer::printError(Stream* port){
		port->println("Printing Errors:");
		// for(int x = 0; x < this->capturedTokens->getPosition(); x++){
			// Token* t = capturedTokens->getByPosition(x);
			// port->println(*t);
		// }
	}
	
	void ame::Lexer::capture(char chr, bool capturing){}
	
	void ame::Lexer::reset(){
		capturedTokens->resetDelete();
	}
	
#endif 
