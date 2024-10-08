
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
  list.add(1);
  list.add(1);
  list.add(1);
  list.add(1);
  
  int repeated = list.repeated(1);
  
  Serial.println(repeated);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}