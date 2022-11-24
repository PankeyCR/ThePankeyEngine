
#include "DataNetwork.hpp"
#include "System.hpp"

using namespace ame;

DataNetwork<float> network;

void setup() {
  Serial.begin(9600);

  network.addValue(5);
  network.addValue(10);
  network.addValue(15);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  LinkedList<float> list = network.getValues();

  for(float value : list){
    System::console.println(value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//