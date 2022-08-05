
#include "Note.hpp"
#include "RawList.hpp"
#include "PrimitiveList.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "192.168.2.98";

  Serial.println(note);
  
  RawList<Note>* numbers = note.splitList('.', new PrimitiveList<Note>());

  for(int x = 0; x < numbers->getPosition(); x++){
    int n = numbers->getByPosition(x)->toInt();
    Serial.println(n);
  }

  delete numbers;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
