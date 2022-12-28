
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = 15;
  System::console.print("Original Note:");
  System::console.println(note);
  
  if(note.isInt()){
    int value = note.toInt();
    System::console.print("int:");
    System::console.println(value);
    Note note2 = value;
    System::console.print("Note version of the int:");
    System::console.println(note2);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
 
 //