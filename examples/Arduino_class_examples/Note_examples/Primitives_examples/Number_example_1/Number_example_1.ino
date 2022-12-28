
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = 123.4567f;
  System::console.print("Original Note:");
  System::console.println(note);
  
  if(note.isNumber()){
    float value = note.toFloat();
    System::console.print("float:");
    System::console.println(value);
    Note note2 = value;
    System::console.print("Note version of the Number:");
    System::console.println(note2);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
 
 //