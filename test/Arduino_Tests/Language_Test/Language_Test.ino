
#include "TestRunner.hpp"

#include "TR_Token_Testing.hpp"
#include "TR_Lexer_Testing.hpp"

using namespace higgs;

TestRunner test;

void setup() {
  Serial.begin(9600);

  delay(5000);
  
  TR_Token_Testing(test);
  TR_Lexer_Testing(test);
  
  Serial.println("Starting the language test");
}

void loop() {
  test.runTest();
  test.run();
  delay(3000);
}