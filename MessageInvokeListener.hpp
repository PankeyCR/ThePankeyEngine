
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MessageInvokeListener)
	#define MessageInvokeListener_hpp
#endif

#ifndef MessageInvokeListener_hpp
#define MessageInvokeListener_hpp
#define MessageInvokeListener_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Command.hpp"
#include "Message.hpp"
#include "Note.hpp"
#include "Map.hpp"
#include "Method.hpp"
#include "PrimitiveMap.hpp"
#include "TextLexer.hpp"
#include "cppObjectClass.hpp"
#include "Method.hpp"

#ifdef MessageInvokeListenerLogApp
	#include "Logger.hpp"
	#define MessageInvokeListenerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MessageInvokeListenerLog(name,method,type,mns) 
#endif

namespace ame{

template<class T>
class MessageInvokeListener : public Command<Message>{
    public:
		MessageInvokeListener(){
			MessageInvokeListenerLog("MessageInvokeListener", "Constructor",  "println", "");
			map = new PrimitiveMap<Note,T>();
			lexer. 	addBreakPoint(' ')->
					addBreakPoint('\r')->
					addBreakPoint('\0')->
					addBreakPoint('\n');
		}
		
		MessageInvokeListener(bool own){
			MessageInvokeListenerLog("MessageInvokeListener", "Constructor",  "println", Note("Map ownership: ") + Note(own));
			map = new PrimitiveMap<Note,T>(own);
			lexer. 	addBreakPoint(' ')->
					addBreakPoint('\r')->
					addBreakPoint('\0')->
					addBreakPoint('\n');
		}
		
		virtual ~MessageInvokeListener(){
			MessageInvokeListenerLog("MessageInvokeListener", "Destructor",  "println", "");
			delete map;
		}
		

		void execute(Message* mns){
			MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "");
			Note note = mns->text();
			lexer.reset();
			LexerCaptureNoteV(lexer,note);
			List<Note>* sentences = lexer.getSentences();
			MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", Note("note: ") + mns->text());
			MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", Note("size: ") + Note(sentences->getPosition()));
			for(int x = 0; x < sentences->getPosition(); x++){
				Note sentence = *sentences->getByPosition(x);
				if(sentence == ""){
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "no sentence");
					return;
				}
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", Note("sentence: ") + Note(sentence));
				Note instanceName = lexer.getWord(0, x);
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", Note("instanceName: ") + Note(instanceName));
				if(instanceName == ""){
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "no instanceName");
					return;
				}
				T* instance = map->getByLValue(instanceName);
				if(instance == nullptr){
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "instance == nullptr");
					Note method = instanceName;
					Note parameter1 = lexer.getWord(1, x);
					Note parameter2 = lexer.getWord(2, x);
					if(method == ""){
						return;
					}
					if(parameter1 == ""){
						if(this->invokeGlobal<>(mns->id(),method)){
							MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "this->invokeGlobal<Note>(method)");
							return;
						}
					}
					if(parameter2 == ""){
						if(this->invokeGlobal<Note>(mns->id(),method, parameter1)){
							MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "this->invokeGlobal<Note,Note>(method, parameter1)");
							return;
						}
					}
					if(this->invokeGlobal<Note,Note>(mns->id(),method, parameter1, parameter2)){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "this->invokeGlobal<Note,Note,Note>(method, parameter1, parameter2)");
					}
					return;
				}
				instance->messageId(mns->id());
				Note method = lexer.getWord(1, x);
				if(method == ""){
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "no method");
					return;
				}
				Note parameter1 = lexer.getWord(2, x);
				if(parameter1 == ""){
					if(this->invoke<>(instance, method)){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "Method::invoke<bool>(instance, method)");
						return;
					}
				}
				Note parameter2 = lexer.getWord(3, x);
				if(parameter2 == ""){
					if(this->invoke<Note>(instance, method, parameter1)){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "Method::invoke<bool>(instance, method, parameter1)");
						return;
					}
				}
				this->invoke<Note,Note>(instance, method, parameter1, parameter2);
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", Note("method: ") + method);
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", Note("parameter1: ") + parameter1);
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", Note("parameter2: ") + parameter2);
			}
		}
		
		template<class... Args>
		bool invokeGlobal(int id, Note n, Args... a){
			for(int x = 0; x < map->getPosition(); x++){
				T* instance = map->getByPosition(x);
				instance->messageId(id);
				if(this->invoke<Args...>(instance,n,a...)){
					return true;
				}
			}
			return false;
		}
		
		template<class... Args>
		bool invoke(T* t, Note n, Args... a){
			cppObjectClass* cls = t->getClass();
			if(cls == nullptr){
				return false;
			}
			Method* method = cls->getMethod(n);
			if(method == nullptr){
				return false;
			}
			return method->invoke<T,bool,Args...>(t,false,a...);
		}
		
		void add(Note n, T* t){
			map->addPointer(n, t);
		}

	protected:
		Map<Note,T>* map = nullptr;
		TextLexer lexer;
};

}

#endif