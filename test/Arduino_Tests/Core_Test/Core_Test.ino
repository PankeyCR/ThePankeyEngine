
#include "TestRunner.hpp"

#include "TR_PrimitiveRawPointerMap_Testing.hpp"
#include "TR_InvokeRawMap_Testing.hpp"
#include "TR_Array_Testing.hpp"
#include "TR_Note_Testing.hpp"

using namespace ame;

TestRunner test;

void setup() {
  Serial.begin(9600);
  
  TR_PrimitiveRawPointerMap_Testing(test);
  TR_InvokeRawMap_Testing(test);
  TR_Array_Testing(test);
  TR_Note_Testing(test);
}

void loop() {
  test.runTest();
  test.run();
  delay(3000);
}