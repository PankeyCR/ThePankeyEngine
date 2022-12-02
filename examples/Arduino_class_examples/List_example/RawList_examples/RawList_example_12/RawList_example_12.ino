
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
  
  list.addPack(1, 2, 3, 4, 5);
  
  for(int number : list){
    Serial.println(number);
  }
  
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}