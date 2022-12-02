
#include "ElementId.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ElementId parent = "parent";
  ElementId child = parent.child("child");
  Serial.println(parent);
  Serial.println(child);

  ame_Debuging(ame_Log_EndLoop, "loop");
}