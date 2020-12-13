

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
				String note = mns->text();
				int size = Note::getSentenceSize(note);
				//Serial.print("note: ");Serial.println(mns->text());
				//Serial.print("size: ");//Serial.println(size);
				for(int x = 0; x < size; x++){
					////Serial.print("note: ");//Serial.println(note.getNote());
					String sentence = Note::getSentence(x, note);
					if(sentence == ""){
						return;
					}
					//Serial.print("sentence: ");//Serial.println(sentence);
					String instanceName = Note::getWord(0, sentence);
					//Serial.print("instanceName: ");//Serial.println(instanceName);
					if(instanceName == ""){
						return;
					}
					T* instance = map->get(instanceName);
					if(instance == nullptr){
						//Serial.println("instance == nullptr");
						String method = instanceName;
						String parameter1 = Note::getWord(1, sentence);
						String parameter2 = Note::getWord(2, sentence);
						iterate(map){
							instance = map->getPointer();
							instance->type(mns->type());
							instance->id(mns->id());
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
					instance->type(mns->type());
					instance->id(mns->id());
					String method = Note::getWord(1, sentence);
					if(method == ""){
						return;
					}
					String parameter1 = Note::getWord(2, sentence);
					if(parameter1 == ""){
						if(Method::invoke<bool>(instance, method)){
							//Serial.println("invoked on parameter1: ");
							return;
						}
					}
					String parameter2 = Note::getWord(3, sentence);
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
