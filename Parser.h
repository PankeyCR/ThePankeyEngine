

#ifndef Parser_h
#define Parser_h

#include "PrimitiveMap.h"
#include "GameObject.h"
#include "LinkedList.h"
#include "Statement.h"
#include "Arduino.h"
#include "Stream.h"
#include "Script.h"
#include "Lexer.h"
#include "Block.h"
#include "List.h"
#include "Map.h"

class Parser{
    public:
		Parser();
		virtual ~Parser();
		
		virtual void addLexerTokens(Lexer* lexer);
		virtual void addLexerTokens(Map<String,String>* lexer);
		
		virtual void setLineCommentToken(String n);
		virtual void setCommentTokens(String start, String end);
		virtual void setEnterToken(String n);
		virtual void setBlockName(String n);
		
		virtual Map<String,String>* removeComments(
										Map<String,String>* ntoken, 
										Map<String,String>* lexertokens);
		virtual bool syntax(Map<String,String>* tokens);
		
		template<class... Tokens>
		void addBlock(Block* block, Tokens... t){
			PrimitiveList<String>* list = new PrimitiveList<String>();
			list->addPack(t...);
			blocks->addPointers(block, list);
		}
		
		virtual Script* compile();
		virtual void printTree(Stream* port);
		
	protected:
		Map<String,String>* captureToken = nullptr;
		Map<Block,PrimitiveList<String>>* blocks = nullptr;
		String lineCommentToken = "linecomment";
		String commentTokenStart = "commentstart";
		String commentTokenEnd = "commentend";
		String enterToken = "enter";
		String blockName = "BLOCK";
};

#endif 
