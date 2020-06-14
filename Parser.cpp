
#ifndef Parser_cpp
#define Parser_cpp

#include "Parser.h"

	
	Parser::Parser(){
		this->captureToken = new PrimitiveMap<String,String>();
	}
	
	Parser::~Parser(){
		if(this->captureToken != nullptr){
			delete this->captureToken;
			this->captureToken = nullptr;
		}
	}
	
	void Parser::addLexerTokens(Lexer* lexer){
		this->captureToken = lexer->getCapturedToken()->clone();
	}
	
	
#endif 