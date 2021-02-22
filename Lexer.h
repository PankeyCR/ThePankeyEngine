
#ifndef Lexer_h
#define Lexer_h

#include "Map.h"
#include "List.h"
#include "Token.h"
#include "Stream.h"
#include "Arduino.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "Environment.h"
#include "PrimitiveMap.h"

class Lexer{
    public:
		Lexer();
		virtual ~Lexer();
		
		virtual void capture(char chr);
		
		virtual bool isString(String s);
		virtual bool isFloat(String s);
		virtual bool isInt(String s);
		virtual bool isLong(String s);
		virtual bool isDouble(String s);
		virtual bool isToken(String s);
		virtual bool isVariable(String s);
		virtual Token getToken(String s);
		
		virtual List<Token>* getCapturedTokens();
		
		virtual Lexer* addToken(Token* tok);
		virtual Lexer* addBreakPoint(char brk);
		
		virtual void setEnvironment(Environment* e);
		
		virtual void printTokens(Stream* port);
		virtual bool checkSyntax();
		
	protected:
};
#endif 
