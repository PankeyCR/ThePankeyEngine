
#include "Note.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "192.168.5.90";
  Serial.println(note);
  note.replace("5", "4");
  Serial.println(note);

  ame_Debuging(ame_Log_EndLoop, "loop");
}
