
#include "config.hpp"

#include "TestRunner.hpp"

#include "TR_InvokeMethod_Testing.hpp"

#include "TR_InvokeRawList_Testing.hpp"
#include "TR_InvokeRawMap_Testing.hpp"

#include "TR_InvokeCommandList_Testing.hpp"
#include "TR_InvokeCommandMap_Testing.hpp"

#include "TR_InvokeList_Testing.hpp"

#include "TR_Function_Testing.hpp"

using namespace pankey;

TestRunner test;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the test");

  delay(5000);

  TR_InvokeMethod_Testing(test);

  TR_InvokeRawList_Testing(test);
  TR_InvokeRawMap_Testing(test);
  
  TR_InvokeCommandList_Testing(test);
  TR_InvokeCommandMap_Testing(test);
  
  TR_InvokeList_Testing(test);
  
  TR_Function_Testing(test);
}

void loop() {
  test.runTest();
  test.run();
  delay(3000);
}