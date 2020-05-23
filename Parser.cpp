
#ifndef Parser_cpp
#define Parser_cpp

#include "Parser.h"

	
	Parser::Parser(){
		this->captureToken = new LinkedList<String>();
		this->tokens = new LinkedList<String>();
		this->breakPoint = new LinkedList<char>();
	}
	
	Parser::~Parser(){
		if(this->captureToken != nullptr){
			delete this->captureToken;
			this->captureToken = nullptr;
		}
		if(this->tokens != nullptr){
			delete this->tokens;
			this->tokens = nullptr;
		}
		if(this->breakPoint != nullptr){
			delete this->breakPoint;
			this->breakPoint = nullptr;
		}
	}
	
#endif 