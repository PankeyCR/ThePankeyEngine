
#ifndef Lexer_h
#define Lexer_h

#include "List.h"
#include "Token.h"
#include "Stream.h"
#include "Arduino.h"
#include "LinkedList.h"
#include "PrimitiveList.h"
#include "Environment.h"

#define LexerCaptureString(lexer,scriptText)		\
  for(int x = 0; x < scriptText.length(); x++){		\
    lexer->capture(scriptText.charAt(x));			\
  }													\
  

class Lexer{
    public:
		Lexer();
		virtual ~Lexer();
		
		virtual bool isString(String s);
		virtual bool isFloat(String s);
		virtual bool isInt(String s);
		virtual bool isLong(String s);
		virtual bool isDouble(String s);
		virtual bool isToken(String s);
		virtual bool isVariable(String s);
		virtual Token getToken(String s);
		// virtual LinkedList<Token> getTokens(String s);
		
		virtual void addCapturedTokens(Token tok);
		virtual List<Token>* getCapturedTokens();
		
		virtual bool containBreakPoint(char brk);
		
		virtual Lexer* addTokenStructure(Token tok);
		virtual Lexer* addBreakPoint(char brk);
		
		virtual void setEnvironment(Environment* e);
		virtual Environment* getEnvironment();
		
		virtual void printTokens(Stream* port);
		
		virtual void capture(char chr);
		virtual bool syntax();
		
		virtual void printError(Stream* port);
		
	protected:
		Environment* environment = nullptr;
		List<char>* breakPoint = nullptr;
		List<Token>* tokens = nullptr;
		List<Token>* capturedTokens = nullptr;
};
#endif 
