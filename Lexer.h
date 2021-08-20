
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
  for(int xLexerCaptureString = 0; xLexerCaptureString < scriptText.length(); xLexerCaptureString++){		\
    lexer->capture(scriptText.charAt(xLexerCaptureString),(scriptText.length()-1)!=xLexerCaptureString);			\
  }													\

#define LexerCaptureStringV(lexer,scriptText)		\
  for(int xLexerCaptureString = 0; xLexerCaptureString < scriptText.length(); xLexerCaptureString++){		\
    lexer.capture(scriptText.charAt(xLexerCaptureString),(scriptText.length()-1)!=xLexerCaptureString);			\
  }													\
  
 namespace ame{

class Lexer{
    public:
		Lexer();
		virtual ~Lexer();
		
		virtual String extractString(String s);
		
		virtual bool isString(String s);
		virtual bool isFloat(String s);
		virtual bool isInt(String s);
		virtual bool isLong(String s);
		virtual bool isDouble(String s);
		virtual bool isTypeToken(String s);
		virtual bool isVariable(String s);
		virtual Token getToken(String s);
		// virtual LinkedList<Token> getTokens(String s);
		
		virtual void addCapturedTokens(Token tok);
		virtual int getCapturedTokensPosiotion();
		virtual List<Token>* getCapturedTokens();
		
		virtual Lexer* addBreakPoint(char brk);
		virtual bool containBreakPoint(char brk);
		
		virtual Lexer* addTypeToken(Token tok);
		virtual bool containTypeToken(String brk);
		
		virtual Lexer* addDelimiterToken(Token tok);
		virtual bool containDelimiterToken(String st);
		virtual bool containDelimiterTokenChar(int x, char c);
		virtual int getDelimiterTokenSize();
		
		virtual void setEnvironment(Environment* e);
		virtual Environment* getEnvironment();
		
		virtual void printTokens(Stream* port);
		
		virtual void capture(char chr, bool capturing);
		virtual bool syntax();
		
		virtual void printError(Stream* port);
		
		virtual void reset();
		
	protected:
		Environment* environment = nullptr;
		List<char>* breakPoint = nullptr;
		List<Token>* typeTokens = nullptr;
		List<Token>* delimiterTokens = nullptr;
		List<Token>* capturedTokens = nullptr;
};

}
 
#endif 
