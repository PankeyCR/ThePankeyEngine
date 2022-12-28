
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "\"Hellow\"";
  System::console.print("Original Note:");
  System::console.println(note);
  
  if(note.isNote()){
    Note value = note.extractNote();
    System::console.print("Note:");
    System::console.println(value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
 
 //