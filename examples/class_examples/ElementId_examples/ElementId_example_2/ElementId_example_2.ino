
#include "ElementId.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ElementId parent_1 = "parent";
  ElementId child_1 = parent_1.child("child");
  
  if(parent_1.containChild(child_1)){
    Serial.println("parent_1.containChild(child_1)");
  }
  
  if(child_1.containParent(parent_1)){
    Serial.println("child_1.containParent(parent_1)");
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}