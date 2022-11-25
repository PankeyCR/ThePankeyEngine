
#include "DataNetwork.hpp"
#include "System.hpp"

using namespace ame;

DataNetwork<float> network;

void setup() {
  Serial.begin(9600);

  LinkedList<float> list;
  list.addPack(5,10,15,20);

  network.addValues(list);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  LinkedList<float> list = network.getCloneValues();

  for(float value : list){
    System::console.println(value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//