
#include "ame_DataStructure_config.hpp"
#include "Iterator.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
  createAllocator<higgs_CREATE_ENGINE_MANAGER_ALLOCATOR(int, ExternReferenceCountAllocator<int>)>();
}

void loop() {
  RPTree<int> tree;
  
  Var<int> number_1 = 15;
  Var<int> number_2 = 16;
  Var<int> number_3 = 17;
  
  tree.add(number_1);
  tree.add(number_2);
  tree.add(number_3);

  Iterator<int> iterator = tree;

  for(int x : iterator){
    Serial.println(x);
  }
}




//