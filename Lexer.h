

#ifndef Lexer_h
#define Lexer_h

#include "ArrayList.h"
#include "Arduino.h"
#include "PrimitiveMap.h"
#include "KVMap.h"
#include "List.h"
#include "Map.h"
#include "LinkedList.h"

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
		
		virtual String getActualToken();
		virtual String getCapturedToken(int x);
		virtual Map<String,String>* getCapturedToken();
		
		virtual Lexer* addToken(String tok);
		virtual Lexer* addPrimitiveClass(String cls);
		virtual Lexer* addBreakPoint(char brk);
		virtual Lexer* addDelimiterToken(String name,String dlm);
		//virtual Lexer* addCompareToken(String name,String dlm);
		
		virtual bool syntaxError();
		
	protected:
		Map<String,String>* captureToken = nullptr;
		//Map<String,String>* compareToken = nullptr;
		Map<String,String>* delimiterToken = nullptr;
		List<int>* lastDelimiterTokenPosition = nullptr;
		List<String>* tokens = nullptr;
		List<String>* primitiveClasses = nullptr;
		List<char>* breakPoint = nullptr;
		String reading;
		char captureChar;
		bool syntaxE = false;
};
/*
class				class
classname			pika
LCurlyB				{
classname			int
variable			a
equal				=
intVar				10
endCodeLine			;
classname			PID
variable			p
equal 				=
operatorNew			new
classname			PID
Lparenthesis 		(
intVar				10
coma				,
intVar				15
coma				,
intVar				13
Rparenthesis		)
endCodeLine			;
funreturn			int				// nose
funName				sumA
Lparenthesis		(
parameterClassName	int
parametervariable	c
Rparenthesis		)
LCurlyB				{
classname			b
equal				=
variable			a
sum					+
variable			c
endCodeLine			;
return				return
variable			b
endCodeLine			;
RCurlyB				}
funreturn			int
funName				output
Lparenthesis		(
parameterClassName	int
parametervariable	input
Rparenthesis		)
LCurlyB				{
variable 			p
classDelimiter		.
classfunName		setInput
Lparenthesis		(
variable			input
Rparenthesis		)
endCodeLine			;
variable			p
classDelimiter		.
classfunName		compute
Lparenthesis		(
Rparenthesis		)
endCodeLine			;
return 				return
variable			p
classDelimiter		.
classfunName		getOutput
Lparenthesis		(
Rparenthesis		)
endCodeLine			;
RCurlyB				}
RCurlyB				}

*/
/*
class pika {
	int a=10;
	PID p=new PID(10,15,13);
	
	int sumA(int c){
		int b = a+c;
		return b;
	}
	int output(int input){
		p.setInput(input);
		p.compute();
		return p.getOutput();
	}
}
*/
/*
runcode 			runcode
LCurlyB				{
classname			pika
variable			p
endCodeLine			;
classname			Serial
classDelimiter		.
classfunName		println
Lparenthesis		(
variable			p
classDelimiter		.
classfunName		sumA
Lparenthesis		(
intVar				10
Rparenthesis		)
Rparenthesis		)
endCodeLine			;
RCurlyB				}
*/
/*
runcode{
	pika p;
	Serial.println(p.sumA(10));
}
*/
#endif 
