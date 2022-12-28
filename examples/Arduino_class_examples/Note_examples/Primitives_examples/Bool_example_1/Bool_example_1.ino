
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = true;
  System::console.print("Original Note:");
  System::console.println(note);
  
  if(note.isBool()){
    bool value = note.toBool();
    System::console.print("bool:");
    System::console.println(value);
    Note note2 = value;
    System::console.print("Note version of the bool:");
    System::console.println(note2);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
 
 //