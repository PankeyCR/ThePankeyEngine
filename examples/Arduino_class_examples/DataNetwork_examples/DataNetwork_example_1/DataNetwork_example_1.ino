
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

  for(auto data : network){
    float value = data.get();
    System::console.println(value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//