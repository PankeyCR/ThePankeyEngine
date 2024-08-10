
#include "ame_Enviroment.hpp"
#include "ame_Enviroment_config.hpp"
#include "System.hpp"

using namespace ame;

DataStorage<DataStorage<int>>* i_storage;

void setup(){
  Serial.begin(9600);
  createValueAllocator<int>();
  createDataAllocator<DataStorage<int>>();
  
  i_storage = new ArrayDataStorage<DataStorage<int>>();
  i_storage->expand(5);
}

void loop(){
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  for(int x = 0; x < i_storage->getSize(); x++){
    Data<DataStorage<int>> f_storage;
    f_storage.set(new ArrayDataStorage<int>());
    
    f_storage->expand(3);
    i_storage->set(x, f_storage); 
    
    Var<int> i = 100;
    Var<int> j = 200;
    Var<int> k = 300;
  
    f_storage->set(0, i);
    f_storage->set(1, j);
    f_storage->set(2, k);
  
    for(int x = 0; x < f_storage->getSize(); x++){
        Var<int> f_var = f_storage->get(x);
        if(f_var.isNull()){
            continue;
        }
        int f_value = f_var.getValue();
        System::console.println(f_value);
    }
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}