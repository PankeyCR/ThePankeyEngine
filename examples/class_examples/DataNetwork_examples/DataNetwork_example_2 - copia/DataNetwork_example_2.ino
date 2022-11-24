
#include "DataNetwork.hpp"
#include "Array.hpp"
#include "System.hpp"

using namespace ame;

DataNetwork<float> network;

void setup() {
  Serial.begin(9600);

  delay(3000);

  network.createHorizontalLayer(0, 2);

  network.setHorizontalLayerValue(0, 0, 10);
  network.setHorizontalLayerValue(0, 1, 11);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Array<float> array = network.getHorizontalLayerArray(0);

  for(float value : array){
    System::console.println(value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//