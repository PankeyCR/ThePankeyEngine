
#include "ame_Enviroment.hpp"
#include "ame_Enviroment_config.hpp"
#include "System.hpp"

using namespace ame;

DataStorage<int>* i_storage;

void setup() {
  Serial.begin(9600);
  createDataAllocator<int>();
  
  i_storage = new ArrayDataStorage<int>();
  i_storage->expand(3);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Var<int> i = 100;
  Var<int> j = 200;
  Var<int> k = 300;

  i_storage->set(0, i);
  i_storage->set(1, j);
  i_storage->set(2, k);

  for(int x = 0; x < i_storage->getSize(); x++){
      Var<int> f_var = i_storage->get(x);
      if(f_var.isNull()){
          continue;
      }
      int f_value = f_var.getValue();
      System::console.println(f_value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}


//