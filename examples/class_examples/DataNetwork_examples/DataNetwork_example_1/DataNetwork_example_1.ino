
#include "DataNetwork.hpp"
#include "Array.hpp"
#include "System.hpp"

using namespace ame;

DataNetwork<float> network;

void setup() {
  Serial.begin(9600);
  
  network.createVerticalLayer(2);

  network.setVerticalLayerValue(0, 10);
  network.setVerticalLayerValue(0, 11);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Array<float> array = network.getVerticalLayerArray();

  for(float value : array){
    System::console.println(value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//