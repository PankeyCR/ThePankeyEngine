
#include "ame_DataStructure_config.hpp"
#include "Iterator.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
  createAllocator<higgs_CREATE_ENGINE_MANAGER_ALLOCATOR(int, ExternReferenceCountAllocator<int>)>();
}

void loop() {
  Var<int> number = 10;
  RPTree<int> tree = number;
  
  Var<int> number_1 = 15;
  Var<int> number_2 = 16;
  Var<int> number_3 = 17;
  
  RPTree<int> branch_1 = tree.branch(number_1);
  RPTree<int> branch_2 = tree.branch(number_2);
  RPTree<int> branch_3 = tree.branch(number_3);

  Iterator<RPTree<int>> iterator = tree;

  for(RPTree<int> branch : iterator){
    Var<int> i = branch.get();
    Serial.println(i.getValue());
  }
}




//