

#ifndef Parser_h
#define Parser_h

#include "PrimitiveMap.h"
#include "GameObject.h"
#include "Block.h"
#include "PMap.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "Statement.h"
#include "Arduino.h"
#include "Stream.h"
#include "Script.h"
#include "Lexer.h"
#include "List.h"
#include "Map.h"

class Parser{
    public:
		Parser();
		~Parser();
		
		void addLexerTokens(Map<String,String>* lexer);
		void setLineCommentToken(String n);
		void setCommentTokens(String start, String end);
		Map<String,String>* removeComments(Map<String,String>* ntoken, Map<String,String>* lexertokens);
		void addBlock(Block* block);
		/*
		GameObject* getBlockStatement(Map<String,String>* tokens);*/
		Script* compile();
		void printFileTree(Stream* port);
		
	protected:
		Map<String,String>* captureToken = nullptr;
		List<Statement>* statements = nullptr;
		List<Block>* blocks = nullptr;
		String lineCommentToken = "linecomment";
		String commentTokenStart = "commentstart";
		String commentTokenEnd = "commentend";
		String enterToken = "enter";
};

#endif 
