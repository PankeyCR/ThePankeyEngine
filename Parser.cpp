
#ifndef Parser_cpp
#define Parser_cpp

#include "Parser.h"

	
	Parser::Parser(){
		//this->captureToken = new PrimitiveMap<String,String>();
		this->statements = new LinkedList<Statement>();
		this->blocks = new LinkedList<Block>();
	}
	
	Parser::~Parser(){
		if(this->captureToken != nullptr){
			delete this->captureToken;
			this->captureToken = nullptr;
		}
		if(this->statements != nullptr){
			delete this->statements;
			this->statements = nullptr;
		}
		if(this->blocks != nullptr){
			delete this->blocks;
			this->blocks = nullptr;
		}
	}
	
	void Parser::addLexerTokens(Map<String,String>* map){
		if(this->captureToken != nullptr){
			delete this->captureToken;
		}
		this->captureToken = this->removeComments(map,new PrimitiveMap<String,String>());
	}
	
	void Parser::setLineCommentToken(String n){
		this->lineCommentToken = n;
	}
	
	void Parser::setCommentTokens(String start, String end){
		this->commentTokenStart = start;
		this->commentTokenEnd = end;
	}
	
	void Parser::addBlock(Block* block){
		this->blocks->add(block);
	}
	
	Map<String,String>* Parser::removeComments(Map<String,String>* lexertokens,Map<String,String>* ntoken){
		
		bool comnt = false;
		LinkedList<int> com;
		LinkedList<int> com2;
		iterate(lexertokens){
			if(lexertokens->getKey() == lineCommentToken){
				comnt = true;
			}
			if(comnt){
				com.add(lexertokens->getIteration());
			}
			if(lexertokens->getKey() == enterToken){
				comnt = false;
			}
		}
		comnt = false;
		iterate(lexertokens){
			if(lexertokens->getKey() == commentTokenStart){
				comnt = true;
			}
			if(comnt){
				com2.add(lexertokens->getIteration());
			}
			if(lexertokens->getKey() == commentTokenEnd){
				comnt = false;
			}
		}
		iterate(lexertokens){
			if( !com.contain(lexertokens->getIteration()) &&
					!com2.contain(lexertokens->getIteration()) ){
				ntoken->add(lexertokens->getKey(),lexertokens->getValue());
			}
		}
		
		return ntoken;
	}
	
	Script* Parser::compile(){
		
	}
	
	void Parser::printFileTree(Stream* port){
		iterate(this->captureToken){
			Serial.print(this->captureToken->getKey());
			Serial.print(" ");
			Serial.println(this->captureToken->getValue());
		}
	}
	
	/*
	GameObject* Parser::compile(){
		bool comnt = false;
		iterate(this->captureToken){
			if(this->captureToken->getKey() == lineCommentToken){
				comnt = true;
			}
			if(comnt){
				this->comments->add(this->captureToken->getIteration());
			}
			if(this->captureToken->getKey() == enterToken){
				comnt = true;
			}
		}
		comnt = false;
		iterate(this->captureToken){
			if(this->captureToken->getKey() == commentTokenStart){
				comnt = true;
			}
			if(comnt){
				this->comments->add(this->captureToken->getIteration());
			}
			if(this->captureToken->getKey() == commentTokenEnd){
				comnt = true;
			}
		}
		
		return this->getBlockStatement();
	}
	
	GameObject* Parser::getBlockStatement(Map<String,String>* code){
		
		
		return nullptr;
	}
	*/
	
#endif 