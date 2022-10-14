
#include "Note.hpp"
#include "PrimitiveList.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "192.168.2.98";

  Serial.println(note);
  
  RawList<Note>* numbers = note.split('.', new PrimitiveList<Note>());

  for(int x = 0; x < numbers->getPosition(); x++){
	  Note* f_note = numbers->getByPosition(x);
    int value = f_note->toInt();
    Serial.println(value);
  }

  delete numbers;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 