

#ifndef Parser_h
#define Parser_h

#include "PrimitiveMap.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "Arduino.h"
#include "Lexer.h"
#include "List.h"
#include "Map.h"

class Parser{
    public:
		Parser();
		~Parser();
		
		void addLexerTokens(Lexer* lexer);
		
	protected:
		Map<String,String>* captureToken = nullptr;
};

#endif 
