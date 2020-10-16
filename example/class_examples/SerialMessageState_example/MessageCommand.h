
#ifndef MessageCommand_h
#define MessageCommand_h

#include "Arduino.h"
#include "Command.h"
#include "Message.h"
#include "Note.h"
#include "Map.h"
#include "Method.h"
#include "PrimitiveMap.h"

class MessageCommand : public Command<Message>{
public:
MessageCommand(){}
~MessageCommand(){}

void execute(Message* mns){
	Note type = mns->type();
	Note text = mns->text();
	Note id = mns->id();
	int size = text.getSentenceSize();
	Serial.print("type: ");Serial.println(type);
	Serial.print("text: ");Serial.println(text);
	Serial.print("id: ");Serial.println(id);
	Serial.print("size: ");Serial.println(size);
	for(int x = 0; x < size; x++){
		Note sentence = text.getSentence(x);
		Note instanceName = sentence.getWord(0);
		Note method = sentence.getWord(1);
		Note parameter1 = sentence.getWord(2);
		Note parameter2 = sentence.getWord(3);
		Serial.print("sentence: ");Serial.println(sentence);
		Serial.print("instanceName: ");Serial.println(instanceName);
		Serial.print("method: ");Serial.println(method);
		Serial.print("parameter1: ");Serial.println(parameter1);
		Serial.print("parameter2: ");Serial.println(parameter2);
	}
}

protected:
};

#endif 
