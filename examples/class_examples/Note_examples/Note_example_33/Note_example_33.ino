
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note text = " monkey ";

  Note note;
  note.addLocalNote(text);//Note
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalCharPointer(" hello ");//char*
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalInt(150);//int
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalFloat(97.6f);//float
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalLong(1234567l);//long
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalBool(true);//bool
  
  note.addLine();
  
  note.addLocalNote(text);//Note
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalCharPointer(" hello ");//char*
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalInt(150);//int
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalFloat(97.6f);//float
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalLong(1234567l);//long
  note.addLocalValue(' ');//char
  note.addLocalValue('-');//char
  note.addLocalValue(' ');//char
  note.addLocalBool(false);//bool
  
  note.addLine();

  Serial.println(note);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 