
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note text = " monkey ";

  Note note;
  note.addLocal(text);//Note
  note.addLocal(" hello ");//char*
  note.addLocal(' ');//char
  note.addLocal(150);//int
  note.addLocal(97.6f);//float
  note.addLocal(1234567l);//long
  note.addLocal(true);//bool
  
  note.addLocal(text);//Note
  note.addLocal(" hello ");//char*
  note.addLocal(' ');//char
  note.addLocal(150);//int
  note.addLocal(97.6f);//float
  note.addLocal(1234567l);//long
  note.addLocal(false);//bool
  
  note.addLine("");

  Serial.println(note);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 