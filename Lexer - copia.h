/*

#ifndef Lexer_h
#define Lexer_h

#include "Map.h"
#include "List.h"
#include "KVMap.h"
#include "Stream.h"
#include "Arduino.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveMap.h"

class Lexer{
    public:
		Lexer();
		~Lexer();
		
		virtual void capture(char chr);
		
		virtual bool isString(String s);
		virtual bool isFloat(String s);
		virtual bool isInt(String s);
		virtual bool isLong(String s);
		virtual bool isDouble(String s);
		
		virtual String getToken(String tkn);
		virtual String getActualToken();
		virtual String getCapturedToken(int x);
		virtual Map<String,String>* getCapturedToken();
		
		virtual Lexer* addToken(String tok);
		virtual Lexer* addPrimitiveClass(String cls);
		virtual Lexer* addBreakPoint(char brk);
		virtual Lexer* addDelimiterToken(String name,String dlm);
		
		virtual void printTokens(Stream* port);
		
	protected:
		Map<String,String>* captureToken = nullptr;
		Map<String,String>* delimiterToken = nullptr;
		List<String>* tokens = nullptr;
		List<String>* primitiveClasses = nullptr;
		List<char>* breakPoint = nullptr;
		Map<String,int>* delimiterCatcher = nullptr;
		String reading = "";
		char captureChar;
};
#endif 
*/