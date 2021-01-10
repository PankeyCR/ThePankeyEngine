

#ifndef MessageInvokeListener_h
#define MessageInvokeListener_h

#include "Arduino.h"
#include "Command.h"
#include "Message.h"
#include "Note.h"
#include "Map.h"
#include "Method.h"
#include "PrimitiveMap.h"
#include "Logger.h"

#ifdef MessageInvokeListenerLogApp
	#define MessageInvokeListenerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MessageInvokeListenerLog(name,method,type,mns) 
#endif

template<class T>
class MessageInvokeListener : public Command<Message>{
    public:
		Map<String,T>* map = nullptr;
		
		MessageInvokeListener(){
			MessageInvokeListenerLog("MessageInvokeListener", "Constructor",  "println", "");
			map = new PrimitiveMap<String,T>();
		}
		
		MessageInvokeListener(bool own){
			MessageInvokeListenerLog("MessageInvokeListener", "Constructor",  "println", String("List ownership: ") + String(own));
			map = new PrimitiveMap<String,T>(own);
		}
		~MessageInvokeListener(){
			MessageInvokeListenerLog("MessageInvokeListener", "Destructor",  "println", "");
			delete map;
		}

		void messageType(String t){
			MessageInvokeListenerLog("MessageInvokeListener", "messageType",  "println", t);
			type = t;
		}

		void execute(Message* mns){
			MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "");
			if(mns->type() == type){
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", type);
				String note = mns->text();
				int size = Note::getSentenceSize(note);
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("note: ") + mns->text());
				MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("size: ") + String(size));
				for(int x = 0; x < size; x++){
					String sentence = Note::getSentence(x, note);
					if(sentence == ""){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "no sentence");
						return;
					}
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("sentence: ") + String(sentence));
					String instanceName = Note::getWord(0, sentence);
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("instanceName: ") + String(instanceName));
					if(instanceName == ""){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "no instanceName");
						return;
					}
					T* instance = map->getByLValue(instanceName);
					if(instance == nullptr){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "instance == nullptr");
						String method = instanceName;
						String parameter1 = Note::getWord(1, sentence);
						String parameter2 = Note::getWord(2, sentence);
						for(int x = 0; x < map->getPosition(); x++){
							instance = map->getByPosition(x);
							instance->type(mns->type());
							instance->messageId(mns->id());
							if(method == ""){
								continue;
							}
							if(parameter1 == ""){
								if(Method::invokeGlobal<bool>(instance, method)){
									MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "Method::invokeGlobal<bool>(instance, method)");
									continue;
								}
							}
							if(parameter2 == ""){
								if(Method::invokeGlobal<bool>(instance, method, parameter1)){
									MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "Method::invokeGlobal<bool>(instance, method, parameter1)");
									continue;
								}
							}
							if(Method::invokeGlobal<bool>(instance, method, parameter1, parameter2)){
								MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "Method::invokeGlobal<bool>(instance, method, parameter1, parameter2)");
							}
						}
						return;
					}
					instance->type(mns->type());
					instance->messageId(mns->id());
					String method = Note::getWord(1, sentence);
					if(method == ""){
						MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "no method");
						return;
					}
					String parameter1 = Note::getWord(2, sentence);
					if(parameter1 == ""){
						if(Method::invoke<bool>(instance, method)){
							MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "Method::invoke<bool>(instance, method)");
							return;
						}
					}
					String parameter2 = Note::getWord(3, sentence);
					if(parameter2 == ""){
						if(Method::invoke<bool>(instance, method, parameter1)){
							MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", "Method::invoke<bool>(instance, method, parameter1)");
							return;
						}
					}
					Method::invoke<bool>(instance, method, parameter1, parameter2);
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("method: ") + method);
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("parameter1: ") + parameter1);
					MessageInvokeListenerLog("MessageInvokeListener", "execute",  "println", String("parameter2: ") + parameter2);
				}
			}
		}

protected:
String type = "command";
};

#endif 
