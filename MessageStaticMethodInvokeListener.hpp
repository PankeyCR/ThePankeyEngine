
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MessageStaticMethodInvokeListener)
	#define MessageStaticMethodInvokeListener_hpp
#endif

#ifndef MessageStaticMethodInvokeListener_hpp
#define MessageStaticMethodInvokeListener_hpp
#define MessageStaticMethodInvokeListener_AVAILABLE

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
#include "StaticMethodMap.hpp"
#include "TextLexer.hpp"

#ifdef MessageStaticMethodInvokeListenerLogApp
	#include "Logger.hpp"
	#define MessageStaticMethodInvokeListenerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MessageStaticMethodInvokeListenerLog(name,method,type,mns) 
#endif

namespace ame{

template<class T>
class MessageStaticMethodInvokeListener : public Command<Message>{
    public:
		MessageStaticMethodInvokeListener(){
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "Constructor",  "println", "");
			map = new PrimitiveMap<Note,T>();
			lexer. 	addBreakPoint(' ')->
					addBreakPoint('\r')->
					addBreakPoint('\0')->
					addBreakPoint('\n');
		}
		
		MessageStaticMethodInvokeListener(bool own){
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "Constructor",  "println", Note("Map ownership: ") + Note(own));
			map = new PrimitiveMap<Note,T>(own);
			lexer. 	addBreakPoint(' ')->
					addBreakPoint('\r')->
					addBreakPoint('\0')->
					addBreakPoint('\n');
		}
		
		virtual ~MessageStaticMethodInvokeListener(){
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "Destructor",  "println", "");
			delete map;
		}

		void execute(Message* mns){
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "");
			Note note = mns->text();
			lexer.reset();
			LexerCaptureNoteV(lexer,note);
			List<Note>* sentences = lexer.getSentences();
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", Note("note: ") + mns->text());
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", Note("size: ") + Note(sentences->getPosition()));
			for(int x = 0; x < sentences->getPosition(); x++){
				Note sentence = *sentences->getByPosition(x);
				if(sentence == ""){
					MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "no sentence");
					return;
				}
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", Note("sentence: ") + Note(sentence));
				Note instanceName = lexer.getWord(0, x);
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", Note("instanceName: ") + Note(instanceName));
				if(instanceName == ""){
					MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "no instanceName");
					return;
				}
				T* instance = map->getByLValue(instanceName);
				if(instance == nullptr){
					MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "instance == nullptr");
					Note method = instanceName;
					Note parameter1 = lexer.getWord(1, x);
					Note parameter2 = lexer.getWord(2, x);
					if(method == ""){
						return;
					}
					if(parameter1 == ""){
						this->invokeGlobal<>(mns->id(),method);
						return;
					}
					if(parameter2 == ""){
						this->invokeGlobal<Note>(mns->id(),method, parameter1);
						return;
					}
					this->invokeGlobal<Note,Note>(mns->id(),method, parameter1, parameter2);
					return;
				}
				instance->messageId(mns->id());
				Note method = lexer.getWord(1, x);
				if(method == ""){
					MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "no method");
					return;
				}
				Note parameter1 = lexer.getWord(2, x);
				if(parameter1 == ""){
					this->invoke<>(method, instance);
					return;
				}
				Note parameter2 = lexer.getWord(3, x);
				if(parameter2 == ""){
					this->invoke<Note>(method, instance, parameter1);
					return;
				}
				this->invoke<Note,Note>(method, instance, parameter1, parameter2);
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", Note("method: ") + method);
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", Note("parameter1: ") + parameter1);
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", Note("parameter2: ") + parameter2);
			}
		}
		
		template<class... Args>
		void invokeGlobal(int id, Note n, Args... a){
			for(int x = 0; x < map->getPosition(); x++){
				T* instance = map->getByPosition(x);
				instance->messageId(id);
				this->invoke<Args...>(n,instance,a...);
			}
		}
		
		template<class... Args>
		void invoke(Note n, T* t, Args... a){
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "invoke",  "println", "");
			cppObjectClass* cls = t->getClass();
			if(cls == nullptr){
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "invoke",  "println", "cls == nullptr");
				return;
			}
			Method* method = cls->getMethod(n);
			if(method == nullptr){
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "invoke",  "println", "method == nullptr");
				return;
			}
			method->staticInvoke<T,T*,Args...>(t,a...);
		}
		
		void add(Note n, T* t){
			map->addPointer(n,t);
		}

	protected:
		Map<Note,T>* map = nullptr;
		TextLexer lexer;
};

}

#endif