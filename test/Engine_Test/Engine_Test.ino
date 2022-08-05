
#define ame_ArduinoIDE 

#include "Application.hpp"
#include "DefaultApplication.hpp"
#include "TestRunnerState.hpp"
#include "Full_List_Testing.hpp"
#include "LinkedList_Testing.hpp"
#include "Random_Testing.hpp"

using namespace ame;

Application* app;
TestRunnerState* testRunner;

void setup() {
  Serial.begin(9600);

  app = new DefaultApplication();

  testRunner = app->getStateManager()->addState(new TestRunnerState());
  testRunner->addUnitTest("Full_List_Testing", Full_List_Testing);
  testRunner->addUnitTest("LinkedList_Testing", LinkedList_Testing);
  testRunner->addUnitTest("Random_Testing", Random_Testing);
}

void loop() {
  app->update();
  delay(3000);
  Serial.println("Stating Test");
  testRunner->runTest();
}












//