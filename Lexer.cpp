
#ifndef Lexer_cpp
#define Lexer_cpp

#include "Lexer.h"

	
	Lexer::Lexer(){
		this->captureToken = new PrimitiveMap<String,String>();
		this->delimiterToken = new PrimitiveMap<String,String>();
		//this->compareToken = new PrimitiveMap<String,String>();
		
		this->lastDelimiterTokenPosition = new LinkedList<int>();
		this->tokens = new LinkedList<String>();
		this->primitiveClasses = new LinkedList<String>();
		this->breakPoint = new LinkedList<char>();
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
		// if(this->compareToken != nullptr){
			// delete this->compareToken;
			// this->compareToken = nullptr;
		// }
		if(this->lastDelimiterTokenPosition != nullptr){
			delete this->lastDelimiterTokenPosition;
			this->lastDelimiterTokenPosition = nullptr;
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
	}
	
	void Lexer::capture(char chr){
		this->captureChar = chr;
		//Serial.println(this->reading);
		if(this->breakPoint->contain(chr)){
			if(this->reading != ""){
				//Serial.println(this->reading);
				if(this->isString(this->reading)){
					Serial.println(this->reading);
					this->captureToken->add("String",this->reading);
					this->reading = "";
					return;
				}
				if(this->isFloat(this->reading)){
					this->captureToken->add("float",this->reading);
					this->reading = "";
					return;
				}
				if(this->isInt(this->reading)){
					this->captureToken->add("int",this->reading);
					this->reading = "";
					return;
				}
				if(this->isLong(this->reading)){
					this->captureToken->add("long",this->reading);
					this->reading = "";
					return;
				}
				if(this->isDouble(this->reading)){
					this->captureToken->add("double",this->reading);
					this->reading = "";
					return;
				}
				if(this->tokens->contain(this->reading)){
					this->captureToken->add(this->reading,this->reading);
					this->reading = "";
					return;
				}
				if(this->primitiveClasses->contain(this->reading)){
					this->captureToken->add("ClassName",this->reading);
					this->reading = "";
					return;
				}
				if(this->captureToken->getByPos(this->captureToken->getPos()-1) != nullptr){
					if(*this->captureToken->getByPos(this->captureToken->getPos()-1) == "class"){
						this->captureToken->add("ClassName",this->reading);
					}else{
						this->captureToken->add("Variable",this->reading);
					}
				}else{
					this->captureToken->add("Variable",this->reading);
				}
				this->reading = "";
				return;
			}else{
				// this->captureToken->add("Variable",this->reading);
				this->reading = "";
				return;
			}
		}else{
			String chrS(chr);
			if(this->delimiterToken->containValue(chrS)){
				if(this->reading != ""){
					//Serial.println(this->reading);
					if(this->isString(this->reading)){
						this->captureToken->add("String",this->reading);
						this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
						this->reading = "";
						return;
					}
					if(this->tokens->contain(this->reading)){
						this->captureToken->add(this->reading,this->reading);
						this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
						this->reading = "";
						return;
					}
					if(this->primitiveClasses->contain(this->reading)){
						this->captureToken->add("ClassName",this->reading);
						this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
						this->reading = "";
						return;
					}
					if(chr == '.' && this->isInt(this->reading)){
						this->reading.concat(chr);
						return;
					}
					if(this->isFloat(this->reading)){
						this->captureToken->add("float",this->reading);
						this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
						this->reading = "";
						return;
					}
					if(this->isInt(this->reading)){
						this->captureToken->add("int",this->reading);
						this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
						this->reading = "";
						return;
					}
					if(this->isLong(this->reading)){
						this->captureToken->add("long",this->reading);
						this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
						this->reading = "";
						return;
					}
					if(this->isDouble(this->reading)){
						this->captureToken->add("double",this->reading);
						this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
						this->reading = "";
						return;
					}
					if(this->captureToken->getByPos(this->captureToken->getPos()-1) != nullptr){
						if(*this->captureToken->getByPos(this->captureToken->getPos()-1) == "class"){
							this->captureToken->add("ClassName",this->reading);
							this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
						}else{
							this->captureToken->add("Variable",this->reading);
							this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
						}
					}else{
						this->captureToken->add("Variable",this->reading);
					}
					
					this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
					
					this->reading = "";
					return;
				}else{
					this->captureToken->add(*this->delimiterToken->getKey(chrS),chrS);
					
					this->reading = "";
					return;
				}
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
	
	String Lexer::getActualToken(){
		return this->reading;
	}
	
	String Lexer::getCapturedToken(int x){
		if(this->captureToken->getByPos(x) == nullptr){
			return "";
		}
		return *this->captureToken->getByPos(x);
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
	
	// Lexer* Lexer::addCompareToken(String name,String dlm){
		// this->compareToken->add(name,dlm);
		// return this;
	// }
	
	bool Lexer::syntaxError(){
		//class-interface detection with methods
		bool cls = false;
		int curly = 0;
		iterate(this->captureToken){
			if(this->captureToken->getKey() == "class" || this->captureToken->getKey() == "interface"){
				cls = true;
			}
			if(this->captureToken->getKey() == "LCurlyB"){
				if(curly >= 1){
					if(this->captureToken->getKeyByPos(this->captureToken->getIteration()-1) == "if"){
						
					}
					//this->captureToken->setKeyByPos();
				}
				curly++;
			}
		}
		return false;
	}
	
#endif 