
#ifndef Lexer_h
#define Lexer_h


#ifndef ame_Enviroment_Defined
	#include "Stream.h"
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Stream.h"
	#include "Arduino.h"
#endif

#include "List.hpp"
#include "Token.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "Environment.hpp"

#define LexerCaptureString(lexer,scriptText)		\
  for(int xLexerCaptureString = 0; xLexerCaptureString < scriptText.length(); xLexerCaptureString++){		\
    lexer->capture(scriptText.charAt(xLexerCaptureString),(scriptText.length()-1)!=xLexerCaptureString);			\
  }													\

#define LexerCaptureStringV(lexer,scriptText)		\
  for(int xLexerCaptureString = 0; xLexerCaptureString < scriptText.length(); xLexerCaptureString++){		\
    lexer.capture(scriptText.charAt(xLexerCaptureString),(scriptText.length()-1)!=xLexerCaptureString);			\
  }													\
  
 namespace ame{

class Lexer{
    public:
		Lexer(){}
		Lexer(Environment* env){
			environment = env;
		}
		virtual ~Lexer(){}
		
		virtual String extractString(String mns){
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
		
		virtual bool isString(String mns){
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
		
		virtual bool isFloat(String mns){ 
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
		
		virtual bool isInt(String mns){
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
		
		virtual bool isLong(String mns){
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
	
		virtual bool isDouble(String mns){ 
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
		
		virtual bool isTypeToken(String mns){
			for(int x = 0; x < typeTokens.getPosition(); x++){
				Token* t = typeTokens.getByPosition(x);
				if(t->name == mns){
					return true;
				}
			}
			return false;
		}
		
		virtual bool isVariable(String mns){
			if(environment == nullptr){
				return false;
			}
			return environment->containVariable(mns);
		}
	
		virtual Token getToken(String tkn){
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
			for(int x = 0; x < this->typeTokens.getPosition(); x++){
				ame::Token* t = this->typeTokens.getByPosition(x);
				if(t->name == tkn){
					return Token(tkn,tkn);
				}
			}
			for(int x = 0; x < this->delimiterTokens.getPosition(); x++){
				ame::Token* t = this->delimiterTokens.getByPosition(x);
				if(t->value == tkn){
					return Token(*t);
				}
			}
			if(environment != nullptr){
				return environment->getToken(tkn);
			}
			return Token("Variable",tkn);
		}
	
		// virtual LinkedList<Token> getTokens(String s);
		
		virtual void addCapturedTokens(Token tkn){
			this->capturedTokens.addLValue(tkn);
		}
		
		virtual int getCapturedTokensPosiotion(){
			return this->capturedTokens.getPosition();
		}
		
		virtual PrimitiveList<Token>& getCapturedTokens(){
			return this->capturedTokens;
		}
		
		virtual void addBreakPoint(char brk){
			this->breakPoint.addLValue(brk);
		}
	
		virtual bool containBreakPoint(char brk){
			return this->breakPoint.containByLValue(brk);
		}
	
		
		virtual void addTypeToken(Token tkn){
			this->typeTokens.addLValue(tkn);
		}
	
		virtual bool containTypeToken(String brk){
			for(int x = 0; x < this->typeTokens.getPosition(); x++){
				Token* token = this->typeTokens.getByPosition(x);
				if(brk == token->name){
					return true;
				}
			}
			return false;
		}
	
		virtual void addDelimiterToken(Token tkn){
			this->delimiterTokens.addLValue(tkn);
		}
	
		virtual bool containDelimiterToken(String tkn){
			for(int x = 0; x < this->delimiterTokens.getPosition(); x++){
				Token* token = this->delimiterTokens.getByPosition(x);
				if(tkn == token->value){
					return true;
				}
			}
			return false;
		}
	
		virtual bool containDelimiterTokenChar(int x, char c){
			for(int xc = 0; xc < this->delimiterTokens.getPosition(); xc++){
				Token* token = this->delimiterTokens.getByPosition(xc);
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
		
		virtual int getDelimiterTokenSize(){
			return this->delimiterTokens.getPosition();
		}
		
		virtual void setEnvironment(Environment* e){
			this->environment = e;
		}
		
		virtual Environment* getEnvironment(){
			return this->environment;
		}
		
		virtual void printTokens(Stream* port){
			for(int x = 0; x < this->capturedTokens.getPosition(); x++){
				Token* t = capturedTokens.getByPosition(x);
				port->println(*t);
			}
		}
		
		virtual void capture(char chr, bool capturing){}
		virtual bool syntax(){
			for(int x = 0; x < this->capturedTokens.getPosition(); x++){
				Token* t = capturedTokens.getByPosition(x);
				if(t->info == "error"){
					return false;
				}
			}
			return true;
		}
			
		virtual void printError(Stream* port){}
		
		virtual void reset(){
			capturedTokens.resetDelete();
		}
		
	protected:
		Environment* environment = nullptr;
		
		PrimitiveList<char> breakPoint;
		PrimitiveList<Token> typeTokens;
		PrimitiveList<Token> delimiterTokens;
		PrimitiveList<Token> capturedTokens;
};

}
 
#endif 
