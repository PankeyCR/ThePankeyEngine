
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

  if(network.belongs(10)){
    System::console.println("network contains value 10");
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//