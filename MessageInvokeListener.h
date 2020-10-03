

#ifndef MessageInvokeListener_h
#define MessageInvokeListener_h

#include "Arduino.h"
#include "Command.h"
#include "Message.h"
#include "Note.h"
#include "Map.h"
#include "Method.h"
#include "PrimitiveMap.h"

class MessageInvokeListener : public Command<Message>{
    public:
		Map<String,Method>* map = nullptr;
		
		MessageInvokeListener(){
			map = new PrimitiveMap<String,Method>();
		}
		
		MessageInvokeListener(bool own){
			map = new PrimitiveMap<String,Method>(own);
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
				Note note(50,10);
				note = mns->text();
				int size = note.getSentenceSize();
				//Serial.print("note: ");Serial.println(mns->text());
				for(int x = 0; x < size; x++){
					//Serial.print("note: ");Serial.println(note.getNote());
					String sentence = note.getSentence(x);
					if(sentence == ""){
						return;
					}
					//Serial.print("sentence: ");Serial.println(sentence);
					String instanceName = note.getWord(sentence, 0);
					//Serial.print("instanceName: ");Serial.println(instanceName);
					if(instanceName == ""){
						return;
					}
					Method* instance = map->get(instanceName);
					if(instance == nullptr){
						//Serial.println("instance == nullptr");
						return;
					}
					String method = note.getWord(sentence, 1);
					if(method == ""){
						return;
					}
					String parameter1 = note.getWord(sentence, 2);
					if(parameter1 == ""){
						Method::invoke(instance, method);
						return;
					}
					String parameter2 = note.getWord(sentence, 3);
					if(parameter2 == ""){
						Method::invoke(instance, method, parameter1);
						return;
					}
					Method::invoke(instance, method, parameter1, parameter2);
					//Serial.print("method: ");Serial.println(method);
					//Serial.print("parameter: ");Serial.println(parameter);
				}
			}
		}

protected:
String type = "command";
};

#endif 
