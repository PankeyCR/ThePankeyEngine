

#ifndef MessageStaticMethodInvokeListener_hpp
#define MessageStaticMethodInvokeListener_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
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
			map = new PrimitiveMap<String,T>();
			lexer. 	addBreakPoint(' ')->
					addBreakPoint('\r')->
					addBreakPoint('\0')->
					addBreakPoint('\n');
		}
		
		MessageStaticMethodInvokeListener(bool own){
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "Constructor",  "println", String("Map ownership: ") + String(own));
			map = new PrimitiveMap<String,T>(own);
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
			String note = mns->text();
			lexer.reset();
			LexerCaptureStringV(lexer,note);
			List<String>* sentences = lexer.getSentences();
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", String("note: ") + mns->text());
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", String("size: ") + String(sentences->getPosition()));
			for(int x = 0; x < sentences->getPosition(); x++){
				String sentence = *sentences->getByPosition(x);
				if(sentence == ""){
					MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "no sentence");
					return;
				}
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", String("sentence: ") + String(sentence));
				String instanceName = lexer.getWord(0, x);
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", String("instanceName: ") + String(instanceName));
				if(instanceName == ""){
					MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "no instanceName");
					return;
				}
				T* instance = map->getByLValue(instanceName);
				if(instance == nullptr){
					MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "instance == nullptr");
					String method = instanceName;
					String parameter1 = lexer.getWord(1, x);
					String parameter2 = lexer.getWord(2, x);
					if(method == ""){
						return;
					}
					if(parameter1 == ""){
						this->invokeGlobal<>(mns->id(),method);
						return;
					}
					if(parameter2 == ""){
						this->invokeGlobal<String>(mns->id(),method, parameter1);
						return;
					}
					this->invokeGlobal<String,String>(mns->id(),method, parameter1, parameter2);
					return;
				}
				instance->messageId(mns->id());
				String method = lexer.getWord(1, x);
				if(method == ""){
					MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "no method");
					return;
				}
				String parameter1 = lexer.getWord(2, x);
				if(parameter1 == ""){
					this->invoke<>(method, instance);
					return;
				}
				String parameter2 = lexer.getWord(3, x);
				if(parameter2 == ""){
					this->invoke<String>(method, instance, parameter1);
					return;
				}
				this->invoke<String,String>(method, instance, parameter1, parameter2);
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", String("method: ") + method);
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", String("parameter1: ") + parameter1);
				MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", String("parameter2: ") + parameter2);
			}
		}
		
		template<class... Args>
		void invokeGlobal(int id, String n, Args... a){
			for(int x = 0; x < map->getPosition(); x++){
				T* instance = map->getByPosition(x);
				instance->messageId(id);
				this->invoke<Args...>(n,instance,a...);
			}
		}
		
		template<class... Args>
		void invoke(String n, T* t, Args... a){
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
		
		void add(String n, T* t){
			map->addPointer(n,t);
		}

	protected:
		Map<String,T>* map = nullptr;
		TextLexer lexer;
};

}

#endif 
