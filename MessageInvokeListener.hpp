

#ifndef MessageInvokeListener_hpp
#define MessageInvokeListener_hpp

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
			map = new PrimitiveMap<String,T>();
			lexer. 	addBreakPoint(' ')->
					addBreakPoint('\r')->
					addBreakPoint('\0')->
					addBreakPoint('\n');
		}
		
		MessageInvokeListener(bool own){
			MessageInvokeListenerLog("MessageInvokeListener", "Constructor",  "println", String("Map ownership: ") + String(own));
			map = new PrimitiveMap<String,T>(own);
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
			String note = mns->text();
			lexer.reset();
			LexerCaptureStringV(lexer,note);
			List<String>* sentences = lexer.getSentences();
			MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("note: ") + mns->text());
			MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("size: ") + String(sentences->getPosition()));
			for(int x = 0; x < sentences->getPosition(); x++){
				String sentence = *sentences->getByPosition(x);
				if(sentence == ""){
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "no sentence");
					return;
				}
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("sentence: ") + String(sentence));
				String instanceName = lexer.getWord(0, x);
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("instanceName: ") + String(instanceName));
				if(instanceName == ""){
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "no instanceName");
					return;
				}
				T* instance = map->getByLValue(instanceName);
				if(instance == nullptr){
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "instance == nullptr");
					String method = instanceName;
					String parameter1 = lexer.getWord(1, x);
					String parameter2 = lexer.getWord(2, x);
					if(method == ""){
						return;
					}
					if(parameter1 == ""){
						if(this->invokeGlobal<>(mns->id(),method)){
							MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "this->invokeGlobal<String>(method)");
							return;
						}
					}
					if(parameter2 == ""){
						if(this->invokeGlobal<String>(mns->id(),method, parameter1)){
							MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "this->invokeGlobal<String,String>(method, parameter1)");
							return;
						}
					}
					if(this->invokeGlobal<String,String>(mns->id(),method, parameter1, parameter2)){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "this->invokeGlobal<String,String,String>(method, parameter1, parameter2)");
					}
					return;
				}
				instance->messageId(mns->id());
				String method = lexer.getWord(1, x);
				if(method == ""){
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "no method");
					return;
				}
				String parameter1 = lexer.getWord(2, x);
				if(parameter1 == ""){
					if(this->invoke<>(instance, method)){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "Method::invoke<bool>(instance, method)");
						return;
					}
				}
				String parameter2 = lexer.getWord(3, x);
				if(parameter2 == ""){
					if(this->invoke<String>(instance, method, parameter1)){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "Method::invoke<bool>(instance, method, parameter1)");
						return;
					}
				}
				this->invoke<String,String>(instance, method, parameter1, parameter2);
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("method: ") + method);
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("parameter1: ") + parameter1);
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("parameter2: ") + parameter2);
			}
		}
		
		template<class... Args>
		bool invokeGlobal(int id, String n, Args... a){
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
		bool invoke(T* t, String n, Args... a){
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
		
		void add(String n, T* t){
			map->addPointer(n, t);
		}

	protected:
		Map<String,T>* map = nullptr;
		TextLexer lexer;
};

}

#endif 
