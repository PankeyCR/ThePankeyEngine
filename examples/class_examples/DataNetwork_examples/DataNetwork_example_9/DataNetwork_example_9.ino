
#include "DataNetwork.hpp"
#include "System.hpp"

using namespace ame;

DataNetwork<float> network;
DataNetwork<float> network_2;
DataNetwork<float> result;

void setup() {
  Serial.begin(9600);

  network.addValue(5);
  network.addValue(10);
  network.addValue(15);

  network_2.addValue(3);
  network_2.addValue(4);
  network_2.addValue(2);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  result = network.Intersection(network_2);

  for(auto data : result){
    float value = data.get();
    System::console.println(value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//