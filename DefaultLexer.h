
#ifndef DefaultLexer_h
#define DefaultLexer_h

#include "Lexer.h"
#include "List.h"
#include "Token.h"
#include "Arduino.h"

#ifdef DefaultLexerLogApp
	#include "Logger.h"
	#define DefaultLexerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define DefaultLexerLog(name,method,type,mns) 
#endif

namespace ame{
	
class DefaultLexer : public Lexer{
    public:
		DefaultLexer(){}
		virtual ~DefaultLexer(){}
		
		virtual void capture(char chr, bool capturing){
			DefaultLexerLog("DefaultLexer", "capture",  "println", "capturing char");
			DefaultLexerLog("DefaultLexer", "capture",  "println", String("last char:") + String(!capturing));
			if(this->containBreakPoint(chr)){
				if(reading != ""){
					DefaultLexerLog("DefaultLexer", "capture",  "println", String("break point: ") + String(chr));
					DefaultLexerLog("DefaultLexer", "capture",  "println", "adding token");
					this->capturingToken(chr, reading, position-reading.length(),
													line_p,
													this->getCapturedTokensPosiotion());
					reading = "";
					if(delimiterPosition > 0){
						if(this->containDelimiterToken(delimiter)){
							Token delimiterToken = this->getToken(delimiter);
							delimiterToken.text_Position = position-delimiter.length();
							delimiterToken.line_Position = line_p;
							delimiterToken.list_Position = this->getCapturedTokensPosiotion();
							DefaultLexerLog("DefaultLexer", "capture",  "println", "adding delimiter token: ");
							this->capturingToken(chr, delimiter, position-reading.length(),
															line_p,
															this->getCapturedTokensPosiotion());
						}
						delimiterPosition = 0;
						delimiter = "";
					}
				}
			}
			else if(this->containDelimiterTokenChar(delimiterPosition, chr)){
				DefaultLexerLog("DefaultLexer", "capture",  "println", String("concat delimiter token: ") + String(chr));
				delimiter.concat(chr);
				delimiterPosition++;
				if(!capturing){
					if(reading != ""){
						DefaultLexerLog("DefaultLexer", "capture",  "println", String("break point: ") + String(chr));
						DefaultLexerLog("DefaultLexer", "capture",  "println", "adding token");
						this->capturingToken(chr, reading, position-reading.length(),
														line_p,
														this->getCapturedTokensPosiotion());
						reading = "";
						if(delimiterPosition > 0){
							if(this->containDelimiterToken(delimiter)){
								DefaultLexerLog("DefaultLexer", "capture",  "println", "adding delimiter token");
								this->capturingToken(chr, delimiter, 	position-reading.length(),
																line_p,
																this->getCapturedTokensPosiotion());
							}
							delimiterPosition = 0;
							delimiter = "";
						}
					}
				}
			}
			else{
				if(delimiterPosition > 0){
					DefaultLexerLog("DefaultLexer", "capture",  "println", "adding token");
					this->capturingToken(chr, reading, position-reading.length(),
													line_p,
													this->getCapturedTokensPosiotion());
					reading = "";
					if(this->containDelimiterToken(delimiter)){
						DefaultLexerLog("DefaultLexer", "capture",  "println", "adding delimiter token");
						this->capturingToken(chr, delimiter, position-reading.length(),
														line_p,
														this->getCapturedTokensPosiotion());
					}
					delimiterPosition = 0;
					delimiter = "";
				}
				DefaultLexerLog("DefaultLexer", "capture",  "println", String("concat token: ") + String(chr));
				reading.concat(chr);
				if(!capturing){
					DefaultLexerLog("DefaultLexer", "capture",  "println", "adding token");
					this->capturingToken(chr, reading, 	position-reading.length(),
													line_p,
													this->getCapturedTokensPosiotion());
					reading = "";
				}
			}
			DefaultLexerLog("DefaultLexer", "capture",  "println", String("position: ") + String(position));
			position++;
			if(chr == '\n'){
				DefaultLexerLog("DefaultLexer", "capture",  "println", "new line");
				line_p++;
			}
		}
		
		virtual void capturingToken(char input, String var, int text_Position, int line_Position, int list_Position){
			Token token = this->getToken(var);
			token.text_Position = position-var.length();;
			token.line_Position = line_p;
			token.list_Position = this->getCapturedTokensPosiotion();
			this->addCapturedTokens(token);
			DefaultLexerLog("DefaultLexer", "capture",  "println", String("token is: ") + String(token));
		}
		
	protected:
		int delimiterPosition = 0;
		String delimiter = "";
		String reading = "";
		int position = 0;
		int line_p = 0;
};

}

#endif 
