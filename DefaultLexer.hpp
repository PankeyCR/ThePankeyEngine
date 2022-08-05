
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultLexer)
	#define DefaultLexer_hpp
#endif

#ifndef DefaultLexer_hpp
#define DefaultLexer_hpp
#define DefaultLexer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Lexer.hpp"
#include "List.hpp"
#include "Token.hpp"

#ifdef DefaultLexerLogApp
	#include "Logger.hpp"
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
			DefaultLexerLog("DefaultLexer", "capture",  "println", Note("last char:") + Note(!capturing));
			if(this->containBreakPoint(chr)){
				if(reading != ""){
					DefaultLexerLog("DefaultLexer", "capture",  "println", Note("break point: ") + Note(chr));
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
				DefaultLexerLog("DefaultLexer", "capture",  "println", Note("concat delimiter token: ") + Note(chr));
				delimiter.concat(chr);
				delimiterPosition++;
				if(!capturing){
					if(reading != ""){
						DefaultLexerLog("DefaultLexer", "capture",  "println", Note("break point: ") + Note(chr));
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
				DefaultLexerLog("DefaultLexer", "capture",  "println", Note("concat token: ") + Note(chr));
				reading.concat(chr);
				if(!capturing){
					DefaultLexerLog("DefaultLexer", "capture",  "println", "adding token");
					this->capturingToken(chr, reading, 	position-reading.length(),
													line_p,
													this->getCapturedTokensPosiotion());
					reading = "";
				}
			}
			DefaultLexerLog("DefaultLexer", "capture",  "println", Note("position: ") + Note(position));
			position++;
			if(chr == '\n'){
				DefaultLexerLog("DefaultLexer", "capture",  "println", "new line");
				line_p++;
			}
		}
		
		virtual void capturingToken(char input, Note var, int text_Position, int line_Position, int list_Position){
			Token token = this->getToken(var);
			token.text_Position = position-var.length();;
			token.line_Position = line_p;
			token.list_Position = this->getCapturedTokensPosiotion();
			this->addCapturedTokens(token);
			DefaultLexerLog("DefaultLexer", "capture",  "println", Note("token is: ") + Note(token));
		}
		
	protected:
		int delimiterPosition = 0;
		Note delimiter = "";
		Note reading = "";
		int position = 0;
		int line_p = 0;
};

}

#endif