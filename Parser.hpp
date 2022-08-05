
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Parser)
	#define Parser_hpp
#endif

#ifndef Parser_hpp
#define Parser_hpp
#define Parser_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

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
/*

class Parser{
    public:
		Parser();
		virtual ~Parser();
		
		virtual void addLexerTokens(Lexer* lexer);
		virtual void addLexerTokens(Map<Note,Note>* lexer);
		
		virtual void setLineCommentToken(Note n);
		virtual void setCommentTokens(Note start, Note end);
		virtual void setEnterToken(Note n);
		virtual void setBlockName(Note n);
		
		virtual Map<Note,Note>* removeComments(
										Map<Note,Note>* ntoken, 
										Map<Note,Note>* lexertokens);
		virtual bool syntax(Map<Note,Note>* tokens);
		
		template<class... Tokens>
		void addBlock(Block* block, Tokens... t){
			PrimitiveList<Note>* list = new PrimitiveList<Note>();
			list->addPack(t...);
			blocks->addPointers(block, list);
		}
		
		virtual Script* compile();
		virtual void printTree(Stream* port);
		
	protected:
		Map<Note,Note>* captureToken = nullptr;
		Map<Block,PrimitiveList<Note>>* blocks = nullptr;
		Note lineCommentToken = "linecomment";
		Note commentTokenStart = "commentstart";
		Note commentTokenEnd = "commentend";
		Note enterToken = "enter";
		Note blockName = "BLOCK";
};
*/

#endif 
