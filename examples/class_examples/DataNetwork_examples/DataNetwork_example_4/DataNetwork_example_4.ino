
#include "DataNetwork.hpp"
#include "Array.hpp"
#include "System.hpp"

using namespace ame;

DataNetwork<float> network;
DataNetwork<float> network_2;
DataNetwork<float> network_3;

void setup() {
  Serial.begin(9600);

  network.addValue(5);
  network.addValue(10);
  network.addValue(15);

  network_2.addValue(5);
  network_2.addValue(10);
  network_2.addValue(15);

  network_3.addValue(5);
  network_3.addValue(3);
  network_3.addValue(15);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  if(network == network_2){
    System::console.println("network == network_2");
  }

  if(network != network_3){
    System::console.println("network != network_3");
  }

  if(network_2 != network_3){
    System::console.println("network_2 != network_3");
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//