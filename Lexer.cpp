
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
		if(this->captureToken != nullptr){
			delete this->captureToken;
			this->captureToken = nullptr;
		}
		if(this->delimiterToken != nullptr){
			delete this->delimiterToken;
			this->delimiterToken = nullptr;
		}
		if(this->tokens != nullptr){
			delete this->tokens;
			this->tokens = nullptr;
		}
		if(this->primitiveClasses != nullptr){
			delete this->primitiveClasses;
			this->primitiveClasses = nullptr;
		}
		if(this->breakPoint != nullptr){
			delete this->breakPoint;
			this->breakPoint = nullptr;
		}
		if(this->delimiterCatcher != nullptr){
			delete this->delimiterCatcher;
			this->delimiterCatcher = nullptr;
		}
	}
	
	void Lexer::capture(char chr){
		this->captureChar = chr;
		//Serial.println("start capture "+String(chr));
		
		if(this->delimiterCatcher->getPos() >= 1){
			bool deleteCatcher = false;
			LinkedList<String> deleteCatcherList;
			iterate(this->delimiterCatcher){
				int* delPosition = this->delimiterCatcher->getPointer();
				String delToken = this->delimiterCatcher->getKey();
				//Serial.println("iterate delimiterCatcher "+String(delimiterCatcher->getIteration()));
				//Serial.println("delToken.length() "+String(delToken.length()));
				
				(*delPosition)++;
				//Serial.println("delPosition "+String(*delPosition));
				//Serial.println("this->delimiterCatcher->getPos() "+String(this->delimiterCatcher->getPos()));
								
				if(*delPosition == delToken.length() && this->delimiterCatcher->getPos() == 1){
					deleteCatcher = true;
					break;
				}
				if(*delPosition == delToken.length() && this->delimiterCatcher->getPos() > 1){
					deleteCatcherList.add(delToken);
					//Serial.println("adding deleteCatcherList > 1 "+delToken);
					continue;
				}
				
				if(*delPosition <= delToken.length()){
					if(chr != delToken.charAt(*delPosition)){
						deleteCatcherList.add(delToken);
						//Serial.println("adding deleteCatcherList "+delToken);
						//this->delimiterCatcher->removeDelete(delToken);
					}
				}
			}
			iterateV(deleteCatcherList){
				//Serial.println("deleting delimiterCatcher "+deleteCatcherList.getValue());
				this->delimiterCatcher->removeDelete(deleteCatcherList.getValue());
			}
			if(deleteCatcher){
				//Serial.println("resetDelete delimiterCatcher ");
				this->delimiterCatcher->resetDelete();
				if(this->reading != ""){
					String tkn = this->getToken(this->reading);
					if(tkn != ""){
						this->captureToken->add(tkn,this->reading);
						this->reading = "";
					}
				}
			}
			//deleteCatcherList.resetDelete();
		}
		
		if(this->delimiterCatcher->getPos() == 0){
			//Serial.println("reading "+reading);
			//Serial.println("delimiterCatcher getPos "+String(this->delimiterCatcher->getPos()));
			iterate(this->delimiterToken){
				String delToken = this->delimiterToken->getValue();
				if(delToken.charAt(0) == chr){
					//Serial.println("adding delimiterCatcher "+delToken);
					this->delimiterCatcher->add(new String(delToken),new int(0));
					if(this->reading != ""){
						String tkn = this->getToken(this->reading);
						if(tkn != ""){
							this->captureToken->add(tkn,this->reading);
							//Serial.println("reading "+reading);
							//Serial.println("delimiterCatcher getPos "+String(this->delimiterCatcher->getPos()));
							this->reading = "";
						}else{
							this->captureToken->add("Variable",this->reading);
							//Serial.println("reading "+reading);
							//Serial.println("delimiterCatcher getPos "+String(this->delimiterCatcher->getPos()));
							this->reading = "";
						}
					}
				}
			}
		}
		
		if(this->breakPoint->contain(chr)){
			if(this->reading != ""){
				String tkn = this->getToken(this->reading);
				if(tkn != ""){
					this->captureToken->add(tkn,this->reading);
					this->reading = "";
					return;
					//Serial.println("breakPoint "+tkn);
				}else{
					this->captureToken->add("Variable",this->reading);
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
		if(this->tokens->contain(tkn)){
			return tkn;
		}
		if(this->primitiveClasses->contain(tkn)){
			return "ClassName";
		}
		if(this->delimiterToken->containValue(tkn)){
			return *this->delimiterToken->getKey(tkn);
		}
		
		return "";
	}
	
	String Lexer::getActualToken(){
		return this->reading;
	}
	
	String Lexer::getCapturedToken(int x){
		String* token = this->captureToken->getByPos(x);
		if(token == nullptr){
			return "";
		}
		return *token;
	}
	
	Map<String,String>* Lexer::getCapturedToken(){
		return this->captureToken;
	}
	
	Lexer* Lexer::addToken(String tkn){
		this->tokens->add(tkn);
		return this;
	}
	
	Lexer* Lexer::addPrimitiveClass(String cls){
		this->primitiveClasses->add(cls);
		return this;
	}
	
	Lexer* Lexer::addBreakPoint(char brk){
		this->breakPoint->add(brk);
		return this;
	}
	
	Lexer* Lexer::addDelimiterToken(String name,String dlm){
		this->delimiterToken->add(name,dlm);
		return this;
	}
	
	void Lexer::printTokens(Stream* port){
		iterate(this->getCapturedToken()){
			port->print(this->getCapturedToken()->getKey());
			port->print(" ");
			port->println(this->getCapturedToken()->getValue());
		}
	}
	
#endif 