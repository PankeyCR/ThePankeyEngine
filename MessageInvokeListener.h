

#ifndef MessageInvokeListener_h
#define MessageInvokeListener_h

#include "Arduino.h"
#include "Command.h"
#include "Message.h"
#include "Note.h"
#include "Map.h"
#include "Method.h"
#include "PrimitiveMap.h"

template<class T>
class MessageInvokeListener : public Command<Message>{
    public:
		Map<String,T>* map = nullptr;
		
		MessageInvokeListener(){
			map = new PrimitiveMap<String,T>();
		}
		
		MessageInvokeListener(bool own){
			map = new PrimitiveMap<String,T>(own);
		}
		~MessageInvokeListener(){
			delete map;
		}

		void messageType(String t){
			type = t;
		}

		void execute(Message* mns){
			if(mns->type() == type){
				//Serial.println("execute");
				Note note = mns->text();
				int size = note.getSentenceSize();
				//Serial.print("note: ");//Serial.println(mns->text());
				//Serial.print("size: ");//Serial.println(size);
				for(int x = 0; x < size; x++){
					////Serial.print("note: ");//Serial.println(note.getNote());
					Note sentence = note.getSentence(x);
					if(sentence == ""){
						return;
					}
					//Serial.print("sentence: ");//Serial.println(sentence);
					String instanceName = sentence.getWord(0);
					//Serial.print("instanceName: ");//Serial.println(instanceName);
					if(instanceName == ""){
						return;
					}
					T* instance = map->get(instanceName);
					if(instance == nullptr){
						//Serial.println("instance == nullptr");
						String method = instanceName;
						String parameter1 = sentence.getWord(1);
						String parameter2 = sentence.getWord(2);
						iterate(map){
							instance = map->getPointer();
							if(method == ""){
								continue;
							}
							if(parameter1 == ""){
								if(Method::invokeGlobal<bool>(instance, method)){
									continue;
								}
							}
							if(parameter2 == ""){
								if(Method::invokeGlobal<bool>(instance, method, parameter1)){
									continue;
								}
							}
							Method::invokeGlobal<bool>(instance, method, parameter1, parameter2);
						}
						return;
					}
					String method = sentence.getWord(1);
					if(method == ""){
						return;
					}
					String parameter1 = sentence.getWord(2);
					if(parameter1 == ""){
						if(Method::invoke<bool>(instance, method)){
							//Serial.println("invoked on parameter1: ");
							return;
						}
					}
					String parameter2 = sentence.getWord(3);
					if(parameter2 == ""){
						if(Method::invoke<bool>(instance, method, parameter1)){
							//Serial.println("invoked on parameter2: ");
							return;
						}
					}
					Method::invoke<bool>(instance, method, parameter1, parameter2);
					//Serial.print("method: ");//Serial.println(method);
					//Serial.print("parameter1: ");//Serial.println(parameter1);
					//Serial.print("parameter2: ");//Serial.println(parameter2);
				}
			}
		}

protected:
String type = "command";
};

#endif 
