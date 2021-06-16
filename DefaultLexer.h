
#ifndef DefaultLexer_h
#define DefaultLexer_h

#include "Lexer.h"
#include "List.h"
#include "Token.h"
#include "Arduino.h"

class DefaultLexer : public Lexer{
    public:
		DefaultLexer(){}
		virtual ~DefaultLexer(){}
		
		virtual void capture(char chr){
			if(chr == '\n'){
				line_p++;
			}
			if(this->containBreakPoint(chr)){
				// LinkedList<Token> l = this->getTokens(reading);
				// for(int x = 0; x < l.getPosition(); x++){
					// Token t = *l.getByPosition(x);
					// t.text_Position = position;
					// t.line_Position = line_p;
					// t.list_Position = list_p;
					// this->addCapturedTokens(t);
					// reading = "";
					// list_p++;
				// }
			}else{
				reading += chr;
			}
			position++;
		}
		
	protected:
		String reading = "";
		int position = 0;
		int list_p = 0;
		int line_p = 0;
};
#endif 
