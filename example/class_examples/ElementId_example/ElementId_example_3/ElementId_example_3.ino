
#include "ElementId.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("//////////////////////////////////start");
  ElementId parent_1 = ElementId("parent",".");

  parent_1 = parent_1.child("child_1").child("child_2").child("child_3");
  Serial.println(Note("parent ") + parent_1.getId());
  for(int x = 0; x < parent_1.getSize(); x++){
    Serial.println(Note("part ") + Note(x) + Note(" ") + parent_1.getPart(x));
  }

  parent_1.changeDelimiterLocal("/");
  
  Serial.println(Note("parent ") + parent_1.getId());
  for(int x = 0; x < parent_1.getSize(); x++){
    Serial.println(Note("part ") + Note(x) + Note(" ") + parent_1.getPart(x));
  }

  parent_1.changeDelimiterLocal("//");
  
  Serial.println(Note("parent ") + parent_1.getId());
  for(int x = 0; x < parent_1.getSize(); x++){
    Serial.println(Note("part ") + Note(x) + Note(" ") + parent_1.getPart(x));
  }
  
  Serial.println();
  Serial.println();
  Serial.println("//////////////////////////////////end");
}
