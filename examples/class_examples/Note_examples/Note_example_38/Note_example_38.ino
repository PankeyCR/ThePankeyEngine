
#include "Note.hpp"
#include "NoteHelper.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "192.168.5.90";
  Serial.println(toIPAddress(note));

  ame_Debuging(ame_Log_EndLoop, "loop");
}