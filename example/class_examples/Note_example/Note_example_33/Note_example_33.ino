
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
  
  IPAddress ip = note.toIPAddress();

  Serial.println(ip);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
