
#include "ame_Enviroment.hpp"

#include "RawList.hpp"
#include "PrimitiveRawList.hpp"
#include "LinkedRawList.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  PrimitiveRawList<int> list;
  //LinkedRawList<int> list;
  
  list.add(1);
  list.add(2);
  list.add(3);
  list.add(4);
  list.add(5);
  
  int value = list.getByIndex(2);
  Serial.println(value);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}