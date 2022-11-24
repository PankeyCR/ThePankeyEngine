
#include "DataNetwork.hpp"
#include "Array.hpp"
#include "System.hpp"

using namespace ame;

DataNetwork<float>* Layer(DataNetwork<float>* network, int layer, int position){
  return nullptr;
}

void Feed(DataNetwork<float>* actual, DataNetwork<float>* next){
  
}

DataNetwork<float> network;

void setup() {
  Serial.begin(9600);
  
  network.createFlatNetwork(2, 4, 4, 2);

  network.setFlatNetwork(0, 5, 10);
  network.setFlatNetwork(1, 5, 10, 15, 20);
  network.setFlatNetwork(2, 5, 10, 15, 20);
  network.setFlatNetwork(3, 5, 10);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  network.applyFlatNetwork(Layer, Feed);
  
  Array<float> array = network.getFlatLayerArray(3);

  for(float value : array){
    System::console.println(value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//