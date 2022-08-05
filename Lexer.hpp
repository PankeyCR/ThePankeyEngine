
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Lexer)
	#define Lexer_hpp
#endif

#ifndef Lexer_h
#define Lexer_h
#define Lexer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Stream.h"
	#include "Arduino.h"
#endif

#include "Token.hpp"
#include "PrimitiveList.hpp"
#include "Environment.hpp"

#define LexerCaptureNote(lexer,scriptText)		\
  for(int xLexerCaptureNote = 0; xLexerCaptureNote < scriptText.length(); xLexerCaptureNote++){		\
    lexer->capture(scriptText.charAt(xLexerCaptureNote),(scriptText.length()-1)!=xLexerCaptureNote);			\
  }													\

#define LexerCaptureNoteV(lexer,scriptText)		\
  for(int xLexerCaptureNote = 0; xLexerCaptureNote < scriptText.length(); xLexerCaptureNote++){		\
    lexer.capture(scriptText.charAt(xLexerCaptureNote),(scriptText.length()-1)!=xLexerCaptureNote);			\
  }													\
  
 namespace ame{

class Lexer{
    public:
		Lexer(){}
		Lexer(Environment* env){
			environment = env;
		}
		virtual ~Lexer(){}
		
		virtual Note extractNote(Note mns){
			char mnsArray[mns.length()+1];
			mns.toCharArray(mnsArray, mns.length()+1);
			
			if(mnsArray[0] != '"' && mnsArray[mns.length()-1] != '"'){
				return mns;
			}
			Note extract = "";
			for(int i=1; i < mns.length() - 1; i++){
				extract.concat(mnsArray[i]);
			}
			return extract;
		}
		
		virtual bool isNote(Note mns){
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
		
		virtual bool isFloat(Note mns){ 
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
		
		virtual bool isInt(Note mns){
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
		
		virtual bool isLong(Note mns){
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
	
		virtual bool isDouble(Note mns){ 
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
		
		virtual bool isTypeToken(Note mns){
			for(int x = 0; x < typeTokens.getPosition(); x++){
				Token* t = typeTokens.getByPosition(x);
				if(t->name == mns){
					return true;
				}
			}
			return false;
		}
		
		virtual bool isVariable(Note mns){
			if(environment == nullptr){
				return false;
			}
			return environment->containVariable(mns);
		}
	
		virtual Token getToken(Note tkn){
			if(this->isDouble(tkn)){
				return Token("Double",tkn,"");
			}
			if(this->isFloat(tkn)){
				return Token("Float",tkn,"");
			}
			if(this->isNote(tkn)){
				return Token("Note",tkn,"");
			}
			if(this->isInt(tkn)){
				return Token("Int",tkn,"");
			}
			if(this->isLong(tkn)){
				return Token("Long",tkn,"");
			}
			for(int x = 0; x < this->typeTokens.getPosition(); x++){
				Token* t = this->typeTokens.getByPosition(x);
				if(t->name == tkn){
					return Token(tkn,tkn);
				}
			}
			for(int x = 0; x < this->delimiterTokens.getPosition(); x++){
				Token* t = this->delimiterTokens.getByPosition(x);
				if(t->value == tkn){
					return Token(*t);
				}
			}
			if(environment != nullptr){
				return environment->getToken(tkn);
			}
			return Token("Variable",tkn);
		}
	
		// virtual LinkedList<Token> getTokens(Note s);
		
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
	
		virtual bool containTypeToken(Note brk){
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
	
		virtual bool containDelimiterToken(Note tkn){
			for(int x = 0; x < this->delimiterTokens.getPosition(); x++){
				Token* token = this->delimiterTokens.getByPosition(x);
				if(tkn == token->name){
					return true;
				}
			}
			return false;
		}
	
		virtual bool containDelimiterTokenChar(int x, char c){
			for(int xc = 0; xc < this->delimiterTokens.getPosition(); xc++){
				Token* token = this->delimiterTokens.getByPosition(xc);
				Note t = token->value;
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