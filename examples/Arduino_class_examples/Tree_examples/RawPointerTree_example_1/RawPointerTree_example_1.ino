
#include "ame_Enviroment.hpp"
#include "RawPointerTree.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  RawPointerTree<int> tree;
  
  tree.addPointer(new int(5));
  tree.addPointer(new int(10));
  tree.addPointer(new int(15));

  for(int x = 0; x < tree.getPosition(); x++){
    int* value = tree.getByPosition(x);
    if(value == nullptr){
      continue;
    }
    Serial.println(*value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 