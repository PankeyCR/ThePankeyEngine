
#include "ame_Enviroment.hpp"

#if defined(DISABLE_TextLexer)
	#define TextLexer_hpp
#endif

#ifndef TextLexer_hpp
#define TextLexer_hpp
#define TextLexer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif


#include "DefaultLexer.hpp"
#include "List.hpp"
#include "PrimitiveList.hpp"

#ifdef TextLexerLogApp
	#include "Logger.hpp"
	#define TextLexerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define TextLexerLog(name,method,type,mns) 
#endif

namespace ame{
	
class TextLexer : public DefaultLexer{
    public:
		TextLexer(){m_sentences = new PrimitiveList<Note>();}
		virtual ~TextLexer(){delete m_sentences;}
		
		virtual void capturingToken(char input, Note var, int text_Position, int line_Position, int list_Position){
			Token token = this->getToken(var);
			token.text_Position = position-var.length();;
			token.line_Position = line_p;
			token.list_Position = this->getCapturedTokensPosiotion();
			this->addCapturedTokens(token);
			TextLexerLog("TextLexer", "capture",  "println", Note("token is: ") + token.toNote());
			Note* sentence = m_sentences->getByPosition(sentence_line);
			if(sentence == nullptr){
				m_sentences->addLValue(var+" ");
				return;
			}
			if(line_p == sentence_line){
				sentence->concat(var+" ");
				return;
			}
			if(line_p > sentence_line){
				sentence_line++;
				if(input != '\n'){
					m_sentences->addLValue(var+" ");
				}else{
					m_sentences->addLValue(var);
				}
			}
		}
		
		virtual List<Note>* getSentences(){
			return m_sentences;
		}
		
		virtual Note getWord(int pos, int line){
			int spos = 0;
			for(int x = 0; x < capturedTokens->getPosition(); x++){
				Token token = *capturedTokens->getByPosition(x);
				if(line == token.line_Position && pos == spos){
					return token.value;
				}
				if(line == token.line_Position){
					spos++;
				}
			}
			return "";
		}
		
		virtual void reset(){
			capturedTokens->resetDelete();
			m_sentences->resetDelete();
		}
		
	protected:
		List<Note>* m_sentences = nullptr;
		int sentence_line = 0;
};

}

#endif