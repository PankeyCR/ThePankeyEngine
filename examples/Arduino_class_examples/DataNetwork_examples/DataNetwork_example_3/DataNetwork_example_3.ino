
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
DataNetwork<float> network_2;
DataNetwork<float> network_3;

void setup() {
  Serial.begin(9600);

  network.addValue(5);
  network.addValue(10);
  network.addValue(15);

  network_2.addValue(3);
  network_2.addValue(2);
  network_2.addValue(4);

  network_3.addValue(3);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  if(network.similar(network_2)){
    System::console.println("network similar to network_2");
  }

  if(!network.similar(network_3)){
    System::console.println("network not similar to network_3");
  }

  if(!network_2.similar(network_3)){
    System::console.println("network_2 not similar to network_3");
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//