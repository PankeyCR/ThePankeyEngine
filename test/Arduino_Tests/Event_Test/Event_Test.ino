
#include "TestRunner.hpp"

#include "TR_InvokeRawList_Testing.hpp"
#include "TR_InvokeRawMap_Testing.hpp"

#include "TR_InvokeCommandList_Testing.hpp"

using namespace ame;

TestRunner test;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the test");

  delay(5000);

  TR_InvokeRawList_Testing(test);
  TR_InvokeRawMap_Testing(test);
  
  TR_InvokeCommandList_Testing(test);
}

void loop() {
  test.runTest();
  test.run();
  delay(3000);
}