
#include "TestRunner.hpp"

#include "TR_Set_Testing.hpp"

using namespace ame;

TestRunner test;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the test");

  delay(5000);

  TR_Set_Testing(test);
}

void loop() {
  test.runTest();
  test.run();
  delay(3000);
}