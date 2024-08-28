
#ifndef Lexer_hpp
	#define Lexer_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#ifdef pankey_Windows
		#include "pankey_Printable.hpp"
		#include "pankey_Print.hpp"
	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
		#include "Printable.h"
	#endif

	#include "Note.hpp"
	#include "Token.hpp"
	#include "PrimitiveRawList.hpp"

	#ifdef Lexer_LogApp
		#include "pankey_Logger.hpp"
		#define LexerLog(location,method,type,mns) pankey_Log((void*)this,location,"Lexer",method,type,mns)
	#else
		#define LexerLog(location,method,type,mns)
	#endif
	
	namespace pankey{

		class Lexer{
			protected:
				struct DelimiterCapture{
					Token token;
					int index = 0;

					DelimiterCapture(){}

					DelimiterCapture(const Token& c_token){
						token = c_token;
					}

					DelimiterCapture(const DelimiterCapture& delimiter){
						token = delimiter.token;
						index = delimiter.index;
					}

					void operator=(const DelimiterCapture& delimiter){
						token = delimiter.token;
						index = delimiter.index;
					}

					bool operator==(const DelimiterCapture& delimiter){
						return token == delimiter.token && index == delimiter.index;
					}

					bool operator!=(const DelimiterCapture& delimiter){
						return token != delimiter.token && index != delimiter.index;
					}
				};
			public:
				Lexer(){
					LexerLog(pankey_Log_StartMethod, "Contructor",  "println", "");
					LexerLog(pankey_Log_EndMethod, "Contructor",  "println", "");
				}
				virtual ~Lexer(){
					LexerLog(pankey_Log_StartMethod, "Destructor",  "println", "");
					LexerLog(pankey_Log_EndMethod, "Destructor",  "println", "");
				}
				
				virtual void addBreakPoint(char a_break){
					LexerLog(pankey_Log_StartMethod, "addBreakPoint",  "println", "");
					this->m_breakPoint.addLValue(a_break);
					LexerLog(pankey_Log_EndMethod, "addBreakPoint",  "println", "");
				}
			
				virtual Token addTypeToken(Token a_token){
					LexerLog(pankey_Log_StartMethod, "addTypeToken",  "println", a_token);
					this->m_typeTokens.addLValue(a_token);
					LexerLog(pankey_Log_EndMethod, "addTypeToken",  "println", "");
					return a_token;
				}
			
				virtual Token addDelimiterToken(Token a_token){
					LexerLog(pankey_Log_StartMethod, "addDelimiterToken",  "println", a_token);
					this->m_delimiter_tokens.addLValue(a_token);
					LexerLog(pankey_Log_EndMethod, "addDelimiterToken",  "println", "");
					return a_token;
				}

			protected:
				virtual bool isTypeToken(const Note& a_token){
					LexerLog(pankey_Log_StartMethod, "isTypeToken",  "println", "");
					LexerLog(pankey_Log_Statement, "isTypeToken",  "println", "Token:");
					LexerLog(pankey_Log_Statement, "isTypeToken",  "println", a_token);
					for(int x = 0; x < this->m_typeTokens.getPosition(); x++){
						Token* f_token = this->m_typeTokens.getByPosition(x);
						if(f_token == nullptr){
							LexerLog(pankey_Log_Statement, "isTypeToken",  "println", "continue");
							continue;
						}
						if(f_token->value == a_token){
							LexerLog(pankey_Log_EndMethod, "isTypeToken",  "println", "true");
							return true;
						}
					}
					LexerLog(pankey_Log_EndMethod, "isTypeToken",  "println", "false");
					return false;
				}
				
				virtual bool isDelimiterToken(const Note& a_token){
					LexerLog(pankey_Log_StartMethod, "isDelimiterToken",  "println", "");
					LexerLog(pankey_Log_Statement, "isDelimiterToken",  "println", "Token:");
					LexerLog(pankey_Log_Statement, "isDelimiterToken",  "println", a_token);
					for(int x = 0; x < this->m_delimiter_tokens.getPosition(); x++){
						Token* f_token = this->m_delimiter_tokens.getByPosition(x);
						if(f_token == nullptr){
							LexerLog(pankey_Log_Statement, "isDelimiterToken",  "println", "continue");
							continue;
						}
						if(f_token->value == a_token){
							LexerLog(pankey_Log_EndMethod, "isDelimiterToken",  "println", "true");
							return true;
						}
					}
					LexerLog(pankey_Log_EndMethod, "isDelimiterToken",  "println", "false");
					return false;
				}
				
				virtual bool isBreakPoint(char a_break_point){
					LexerLog(pankey_Log_StartMethod, "isBreakPoint",  "println", "");
					LexerLog(pankey_Log_EndMethod, "isBreakPoint",  "println", "false");
					return this->m_breakPoint.contain(a_break_point);
				}
			
				virtual Token getTypeToken(const Note& a_token){
					LexerLog(pankey_Log_StartMethod, "getTypeToken",  "println", "");
					LexerLog(pankey_Log_Statement, "getTypeToken",  "println", "Token:");
					LexerLog(pankey_Log_Statement, "getTypeToken",  "println", a_token);
					for(int x = 0; x < this->m_typeTokens.getPosition(); x++){
						Token* f_token = this->m_typeTokens.getByPosition(x);
						if(f_token == nullptr){
							continue;
						}
						if(f_token->value == a_token){
							LexerLog(pankey_Log_EndMethod, "getTypeToken",  "println", "true");
							return *f_token;
						}
					}
					LexerLog(pankey_Log_StartMethod, "getTypeToken",  "println", "");
					return Token();
				}
			
				virtual Token getDelimiterToken(const Note& a_token){
					LexerLog(pankey_Log_StartMethod, "getDelimiterToken",  "println", "");
					LexerLog(pankey_Log_Statement, "getDelimiterToken",  "println", "Token:");
					LexerLog(pankey_Log_Statement, "getDelimiterToken",  "println", a_token);
					for(int x = 0; x < this->m_delimiter_tokens.getPosition(); x++){
						Token* f_token = this->m_delimiter_tokens.getByPosition(x);
						if(f_token == nullptr){
							continue;
						}
						if(f_token->value == a_token){
							LexerLog(pankey_Log_EndMethod, "getDelimiterToken",  "println", "true");
							return *f_token;
						}
					}
					LexerLog(pankey_Log_StartMethod, "getDelimiterToken",  "println", "");
					return Token();
				}
			
			public:
				virtual Token getToken(const Note& a_token){
					LexerLog(pankey_Log_StartMethod, "getToken",  "println", "");
					LexerLog(pankey_Log_Statement, "getToken",  "println", "Token:");
					LexerLog(pankey_Log_Statement, "getToken",  "println", a_token);
					if(a_token.isCharArray()){
						LexerLog(pankey_Log_EndMethod, "getToken",  "println", "");
						return Token("Note",a_token);
					}
					if(a_token.isBool()){
						LexerLog(pankey_Log_EndMethod, "getToken",  "println", "");
						return Token("Bool",a_token);
					}
					if(a_token.isFloat()){
						LexerLog(pankey_Log_EndMethod, "getToken",  "println", "");
						return Token("Float",a_token);
					}
					if(a_token.isInt()){
						LexerLog(pankey_Log_EndMethod, "getToken",  "println", "");
						return Token("Int",a_token);
					}
					if(a_token.isLong()){
						LexerLog(pankey_Log_EndMethod, "getToken",  "println", "");
						return Token("Long",a_token);
					}
					if(a_token.isNumber()){
						LexerLog(pankey_Log_EndMethod, "getToken",  "println", "");
						return Token("Number",a_token);
					}
					if(this->isDelimiterToken(a_token)){
						LexerLog(pankey_Log_EndMethod, "getToken",  "println", "");
						return this->getDelimiterToken(a_token);
					}
					if(this->isTypeToken(a_token)){
						LexerLog(pankey_Log_EndMethod, "getToken",  "println", "");
						return this->getTypeToken(a_token);
					}
					LexerLog(pankey_Log_EndMethod, "getToken",  "println", "");
					return Token("Variable",a_token);
				}
				
			protected:
				virtual void addCapturedTokens(Token a_token){
					LexerLog(pankey_Log_StartMethod, "addCapturedTokens",  "println", "");
					this->m_capturedTokens.addLValue(a_token);
					LexerLog(pankey_Log_EndMethod, "addCapturedTokens",  "println", "");
				}
				
				virtual void captureTokenByBreakPoint(){
					LexerLog(pankey_Log_StartMethod, "captureToken",  "println", "");
					Token i_token = this->getToken(this->m_capture_note);
					i_token.text_Position = this->m_text_position - this->m_capture_note.getPosition();
					i_token.line_Position = this->m_line_position;
					i_token.list_Position = this->getCapturedTokensPosition();
					this->m_capturedTokens.add(i_token);
					LexerLog(pankey_Log_EndMethod, "captureToken",  "println", "");
				}
				
				virtual void captureToken(){
					LexerLog(pankey_Log_StartMethod, "captureToken",  "println", "");
					Token i_token = this->getToken(this->m_capture_note);
					i_token.text_Position = this->m_text_position - this->m_capture_note.getPosition() + 1;
					i_token.line_Position = this->m_line_position;
					i_token.list_Position = this->getCapturedTokensPosition();
					this->m_capturedTokens.add(i_token);
					LexerLog(pankey_Log_EndMethod, "captureToken",  "println", "");
				}
				
				virtual void captureToken(Token a_token, int a_text_Position){
					LexerLog(pankey_Log_StartMethod, "captureToken",  "println", "");
					a_token.text_Position = a_text_Position;
					a_token.line_Position = this->m_line_position;
					a_token.list_Position = this->getCapturedTokensPosition();
					this->m_capturedTokens.add(a_token);
					LexerLog(pankey_Log_EndMethod, "captureToken",  "println", "");
				}
				
				virtual void captureToken(Token a_token){
					LexerLog(pankey_Log_StartMethod, "captureToken",  "println", "");
					this->captureToken(a_token, this->m_text_position - a_token.value.getPosition() + 1);
					LexerLog(pankey_Log_EndMethod, "captureToken",  "println", "");
				}
				
				virtual void captureToken(Note a_token, int a_text_Position){
					LexerLog(pankey_Log_StartMethod, "captureTokenVariable",  "println", "");
					Token i_token = this->getToken(a_token);
					i_token.text_Position = a_text_Position;
					i_token.line_Position = this->m_line_position;
					i_token.list_Position = this->getCapturedTokensPosition();
					this->m_capturedTokens.add(i_token);
					LexerLog(pankey_Log_EndMethod, "captureTokenVariable",  "println", "");
				}
				
				virtual void captureToken(Note a_token){
					LexerLog(pankey_Log_StartMethod, "captureTokenVariable",  "println", "");
					this->captureToken(a_token, this->m_text_position - a_token.getPosition() + 1);
					LexerLog(pankey_Log_EndMethod, "captureTokenVariable",  "println", "");
				}
				
				virtual void captureTokenVariable(Note a_token, int a_text_Position){
					LexerLog(pankey_Log_StartMethod, "captureTokenVariable",  "println", "");
					Token i_token = Token("Variable", a_token);
					i_token.text_Position = a_text_Position;
					i_token.line_Position = this->m_line_position;
					i_token.list_Position = this->getCapturedTokensPosition();
					this->m_capturedTokens.add(i_token);
					LexerLog(pankey_Log_EndMethod, "captureTokenVariable",  "println", "");
				}
				
				virtual void captureTokenVariable(Note a_token){
					LexerLog(pankey_Log_StartMethod, "captureTokenVariable",  "println", "");
					this->captureTokenVariable(a_token, this->m_text_position - a_token.getPosition() + 1);
					LexerLog(pankey_Log_EndMethod, "captureTokenVariable",  "println", "");
				}
				
				virtual int getCapturedTokensPosition(){
					LexerLog(pankey_Log_StartMethod, "getCapturedTokensPosition",  "println", "");
					LexerLog(pankey_Log_EndMethod, "getCapturedTokensPosition",  "println", "");
					return this->m_capturedTokens.getPosition();
				}
				
				virtual PrimitiveRawList<Token>& getCapturedTokens(){
					LexerLog(pankey_Log_StartMethod, "getCapturedTokens",  "println", "");
					LexerLog(pankey_Log_EndMethod, "getCapturedTokens",  "println", "");
					return this->m_capturedTokens;
				}
				
				virtual int getDelimiterTokenSize(){
					LexerLog(pankey_Log_StartMethod, "getDelimiterTokenSize",  "println", "");
					LexerLog(pankey_Log_EndMethod, "getDelimiterTokenSize",  "println", "");
					return this->m_delimiter_tokens.getPosition();
				}
			
				virtual bool containDelimiterTokenChar(int a_position, char a_char){
					LexerLog(pankey_Log_StartMethod, "containDelimiterTokenChar",  "println", "");
					for(int x = 0; x < this->m_delimiter_tokens.getPosition(); x++){
						Token* f_token = this->m_delimiter_tokens.getByPosition(x);
						if(f_token == nullptr){
							continue;
						}
						Note f_token_value = f_token->value;
						
						if( (f_token_value.getPosition() - 1) < a_position ){
							continue;
						}
						if(f_token_value[a_position] == a_char){
							LexerLog(pankey_Log_EndMethod, "containDelimiterTokenChar",  "println", "");
							return true;
						}
					}
					LexerLog(pankey_Log_EndMethod, "containDelimiterTokenChar",  "println", "");
					return false;
				}

				virtual bool syntax(){
					LexerLog(pankey_Log_StartMethod, "syntax",  "println", "");
					for(int x = 0; x < this->m_capturedTokens.getPosition(); x++){
						Token* f_token = this->m_capturedTokens.getByPosition(x);
						if(f_token == nullptr){
							continue;
						}
						if(f_token->info == "error"){
							LexerLog(pankey_Log_EndMethod, "syntax", "println", "");
							return false;
						}
					}
					LexerLog(pankey_Log_EndMethod, "syntax", "println", "");
					return true;
				}
				
				virtual void reset(){
					this->m_capturedTokens.resetDelete();
				}
				
				virtual void capturingToken(Note a_token, int a_text_Position){
					LexerLog(pankey_Log_StartMethod, "capturingToken",  "println", Note("token is: ") + Note(a_token));
					LexerLog(pankey_Log_Statement, "capturingToken",  "println", Note("a_text_Position: ") + Note(a_text_Position));
					Token i_token = this->getToken(a_token);
					i_token.text_Position = a_text_Position;
					i_token.line_Position = m_line_position;
					i_token.list_Position = this->getCapturedTokensPosition();
					LexerLog(pankey_Log_Statement, "capturingToken",  "println", "Token:");
					LexerLog(pankey_Log_Statement, "capturingToken",  "println", i_token);
					this->addCapturedTokens(i_token);
					this->m_capture_note.clear();
					this->realeseDelimitersTokens();
					LexerLog(pankey_Log_EndMethod, "capturingToken",  "println", "");
				}
				
				virtual void capturingToken(Token a_token, int a_text_Position){
					LexerLog(pankey_Log_StartMethod, "capturingToken",  "println", Note("token is: ") + a_token.value);
					LexerLog(pankey_Log_Statement, "capturingToken",  "println", Note("a_text_Position: ") + Note(a_text_Position));
					a_token.text_Position = a_text_Position;
					a_token.line_Position = m_line_position;
					a_token.list_Position = this->getCapturedTokensPosition();
					LexerLog(pankey_Log_Statement, "capturingToken",  "println", "Token:");
					LexerLog(pankey_Log_Statement, "capturingToken",  "println", a_token);
					this->addCapturedTokens(a_token);
					this->m_capture_note.clear();
					this->realeseDelimitersTokens();
					LexerLog(pankey_Log_EndMethod, "capturingToken",  "println", "");
				}

				virtual void realeseDelimitersTokens(){
					LexerLog(pankey_Log_StartMethod, "realeseDelimitersTokens",  "println", "");
					this->m_delimiter_checker.resetDelete();
					LexerLog(pankey_Log_EndMethod, "realeseDelimitersTokens",  "println", "");
				}

				virtual bool containCaptureDelimiterToken(){
					LexerLog(pankey_Log_StartMethod, "containCaptureDelimiterToken",  "println", "");
					LexerLog(pankey_Log_EndMethod, "containCaptureDelimiterToken",  "println", "");
					return !this->m_delimiter_checker.isEmpty();
				}

				virtual void captureByBreakPoint(){
					LexerLog(pankey_Log_StartMethod, "captureByBreakPoint",  "println", "this->isBreakPoint(a_char)");
					if(!this->m_capture_note.isEmpty()){
						LexerLog(pankey_Log_Statement, "captureByBreakPoint",  "println", "!this->m_capture_note.isEmpty()");
						this->captureTokenByBreakPoint();
					}
					LexerLog(pankey_Log_EndMethod, "captureByBreakPoint",  "println", "");
				}

				virtual void realeseBreakPoint(){
					LexerLog(pankey_Log_StartMethod, "realeseBreakPoint",  "println", "");
					this->m_delimiter_checker.resetDelete();

					this->m_capture_note.clear();
					LexerLog(pankey_Log_EndMethod, "realeseBreakPoint",  "println", "");
				}

				virtual void captureNewDelimiter(char a_char){
					LexerLog(pankey_Log_StartMethod, "captureNewDelimiter",  "println", "");
					LexerLog(pankey_Log_Statement, "captureNewDelimiter",  "println", "Char:");
					LexerLog(pankey_Log_Statement, "captureNewDelimiter",  "println", a_char);
					for(int x = 0; x < this->m_delimiter_tokens.getPosition(); x++){
						Token* f_token = this->m_delimiter_tokens.getByPosition(x);
						if(f_token == nullptr){
							continue;
						}
						if(f_token->value[0] == a_char){
							LexerLog(pankey_Log_Statement, "captureNewDelimiter",  "println", "f_token->value[0] == a_char");
							DelimiterCapture* f_capture = new DelimiterCapture(*f_token);
							this->m_delimiter_checker.addPointer(f_capture);
						}
					}
					LexerLog(pankey_Log_EndMethod, "captureNewDelimiter",  "println", "");
				}

				virtual void captureDelimiterChecker(char a_char){
					LexerLog(pankey_Log_StartMethod, "captureDelimiterChecker",  "println", "");
					LexerLog(pankey_Log_Statement, "captureDelimiterChecker",  "println", "Char:");
					LexerLog(pankey_Log_Statement, "captureDelimiterChecker",  "println", a_char);

					if(this->m_delimiter_checker.isEmpty()){
						LexerLog(pankey_Log_EndMethod, "captureDelimiterChecker",  "println", "");
						return;
					}

					PrimitiveRawList<int> i_checker_remove;

					for(int x = 0; x < this->m_delimiter_checker.getPosition(); x++){
						DelimiterCapture* f_capture = this->m_delimiter_checker.getByPosition(x);
						if(f_capture == nullptr){
							continue;
						}
						Token& f_token = f_capture->token;
						int f_index = f_capture->index;
						if(f_token.value[f_index] != a_char){
							LexerLog(pankey_Log_Statement, "captureDelimiterChecker",  "println", "f_token.value[f_index] != a_char");
							LexerLog(pankey_Log_Statement, "captureDelimiterChecker",  "println", "iteration: ");
							LexerLog(pankey_Log_Statement, "captureDelimiterChecker",  "println", x);
							i_checker_remove.add(x);
							continue;
						}
						f_capture->index++;
					}

					if(i_checker_remove.isEmpty()){
						return;
					}

					LexerLog(pankey_Log_Statement, "captureDelimiterChecker",  "println", "removing checker");

					for(int x = i_checker_remove.getPosition() - 1; x >= 0; x--){
						LexerLog(pankey_Log_Statement, "captureDelimiterChecker",  "println", "iteration: ");
						LexerLog(pankey_Log_Statement, "captureDelimiterChecker",  "println", x);
						int f_list_index = i_checker_remove[x];
						this->m_delimiter_checker.removeDeleteByPosition(f_list_index);
					}

					this->m_delimiter_checker.reorder();


					LexerLog(pankey_Log_EndMethod, "captureDelimiterChecker",  "println", "");
				}

				virtual void captureDelimiter(){
					LexerLog(pankey_Log_StartMethod, "captureDelimiter",  "println", "");
					if(this->m_delimiter_checker.isEmpty()){
						LexerLog(pankey_Log_EndMethod, "captureDelimiter",  "println", "this->m_delimiter_checker.isEmpty()");
						return;
					}
					if(this->m_capture_note.getPosition() == 0){
						LexerLog(pankey_Log_EndMethod, "captureDelimiter",  "println", "this->m_capture_note.getPosition() == 0");
						return;
					}

					for(int x = 0; x < this->m_delimiter_checker.getPosition(); x++){
						DelimiterCapture* f_capture = this->m_delimiter_checker.getByPosition(x);
						if(f_capture == nullptr){
							continue;
						}
						LexerLog(pankey_Log_Statement, "captureDelimiter",  "println", "iteration: ");
						LexerLog(pankey_Log_Statement, "captureDelimiter",  "println", x);
						Token& f_token = f_capture->token;
						int f_index = f_capture->index;
						if(f_token.value.getPosition() == f_index){
							LexerLog(pankey_Log_Statement, "captureDelimiter",  "println", "f_token.value.getPosition() == f_index");
							LexerLog(pankey_Log_Statement, "captureDelimiter",  "println", "f_index: ");
							LexerLog(pankey_Log_Statement, "captureDelimiter",  "println", f_index);
							int i_text_new_position = this->m_text_position;
							if(this->m_capture_note.getPosition() != f_index){
								Note variable = this->m_capture_note.getArrayPartByLastExtraSpace(f_index);
								this->captureToken(variable, this->m_text_position - this->m_capture_note.getPosition() + 1);
							}
							this->captureToken(f_token, this->m_text_position - f_index + 1);
							this->realeseDelimitersTokens();
							this->m_capture_note.clear();
							break;
						}
					}

					LexerLog(pankey_Log_EndMethod, "captureDelimiter",  "println", "");
				}
				
				virtual void captureDelimiterToken(char a_char){
					LexerLog(pankey_Log_StartMethod, "captureDelimiterToken",  "println", "");

					this->captureNewDelimiter(a_char);

					this->captureDelimiterChecker(a_char);

					this->captureDelimiter();
					
					LexerLog(pankey_Log_EndMethod, "captureDelimiterToken",  "println", "");
				}
				
				virtual void captureByEndOfText(){
					LexerLog(pankey_Log_StartMethod, "captureByEndOfText",  "println", "");
					if(!this->m_capture_note.isEmpty()){
						LexerLog(pankey_Log_Statement, "captureByEndOfText",  "println", "!this->m_capture_note.isEmpty()");
						this->captureToken();
					}
					LexerLog(pankey_Log_EndMethod, "captureByEndOfText",  "println", "");
				}
				
				virtual void realeseEndOfText(){
					LexerLog(pankey_Log_StartMethod, "realeseEndOfText",  "println", "!a_capturing");
					this->m_delimiter_checker.resetDelete();

					this->m_capture_note.clear();
					
					this->m_text_position = 0;
					this->m_line_position = 0;
					LexerLog(pankey_Log_EndMethod, "realeseEndOfText",  "println", "");
				}

				virtual void addPositionAndLine(char a_char){
					LexerLog(pankey_Log_StartMethod, "addPositionAndLine",  "println", Note("position: ") + Note(this->m_text_position));
					this->m_text_position++;
					if(a_char == '\n'){
						LexerLog(pankey_Log_Statement, "addPositionAndLine",  "println", "new line");
						this->m_line_position++;
					}
					LexerLog(pankey_Log_EndMethod, "addPositionAndLine",  "println", "");
				}
				
				//types of caputering
				//1. "Hellow\n" || "Hellow " capturing by a break point
				//2. "Hellow" capturing delimiter by end of the text
				//3. "==Hellow"|| "Hellow==World" capturing delimiter alone
				//4. "== " || "Hellow== " capturing delimiter alone or by break point
				//5. "==" || "Hellow==" capturing delimiter alone or by end of text
				virtual void capture(char a_char, bool a_capturing){
					LexerLog(pankey_Log_StartMethod, "capture",  "println", "");
					LexerLog(pankey_Log_Statement, "capture",  "println", Note("Capturing last char? ") + Note(!a_capturing));
					LexerLog(pankey_Log_Statement, "capture",  "println", "Char:");
					LexerLog(pankey_Log_Statement, "capture",  "println", a_char);

					if(this->isBreakPoint(a_char)){// "Hellow\n" || "Hellow World" the Hellow is capture by breakpoint
						LexerLog(pankey_Log_Statement, "capture",  "println", "this->isBreakPoint(a_char)");
						this->captureByBreakPoint();
						this->realeseBreakPoint();
						this->addPositionAndLine(a_char);
						LexerLog(pankey_Log_EndMethod, "capture",  "println", "");
						return;
					}
					
					m_capture_note.addLocalValue(a_char);
					LexerLog(pankey_Log_Statement, "capture",  "println", "captured note:");
					LexerLog(pankey_Log_Statement, "capture",  "println", m_capture_note);

					this->captureDelimiterToken(a_char);// "Hellow==" || "==" 

					if(!a_capturing){// "Hellow"
						LexerLog(pankey_Log_Statement, "capture",  "println", "End of text");
						this->captureByEndOfText();
						this->realeseEndOfText();
						LexerLog(pankey_Log_EndMethod, "capture",  "println", "");
						return;
					}
					this->addPositionAndLine(a_char);
					LexerLog(pankey_Log_EndMethod, "capture",  "println", "");
				}
				
			public:
				virtual PrimitiveRawList<Token>& capture(const Note& a_script){
					for(int x = 0; x < a_script.getPosition(); x++){
						char f_char = a_script[x];
						this->capture(f_char, x != (a_script.getPosition() - 1));
					}
					return this->m_capturedTokens;
				}

				virtual PrimitiveRawList<Token> copyCapturedTokensList() const{return this->m_capturedTokens;}
				
			protected:
				PrimitiveRawList<char> m_breakPoint;
				PrimitiveRawList<Token> m_typeTokens;
				PrimitiveRawList<Token> m_delimiter_tokens;
				PrimitiveRawList<Token> m_capturedTokens;

				PrimitiveRawList<DelimiterCapture> m_delimiter_checker = PrimitiveRawList<DelimiterCapture>(10, true, false);

				Note m_capture_note;
				
				int m_text_position = 0;
				int m_line_position = 0;
		};

	}
 
#endif