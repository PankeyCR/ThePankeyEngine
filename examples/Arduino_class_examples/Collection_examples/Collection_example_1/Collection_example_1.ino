
#include "ame_Memory_Manager_config.hpp"
#include "PointerArrayStorage.hpp"
#include "Collection.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
  createAllocator<higgs_CREATE_ENGINE_MANAGER_ALLOCATOR(int)>();
}

void loop() {
  Var<int> number_1 = 10;
  Var<int> number_2 = 10;
  Var<int> number_3 = 10;

  auto storage = new PointerArrayStorage<higgs_ENGINE_MANAGER_ALLOCATOR(int)>();
  storage->expand(3);
  storage->add(0, number_1);
  storage->add(1, number_2);
  storage->add(2, number_3);

  Collection<higgs_ENGINE_MANAGER_ALLOCATOR(int)> collection = storage;
  
  for(int x = 0; x < collection.getPosition(); x++){
    Var<int> value = collection.get(x);
    if(value.isNull()){
      continue;
    }
    Serial.println(value.getValue());
  }
}




//