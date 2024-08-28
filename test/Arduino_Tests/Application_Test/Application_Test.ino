
#include "TestRunner.hpp"

#include "TR_UpdateFunctionListManager_Testing.hpp"
#include "TR_UpdateFunctionMapManager_Testing.hpp"

#include "TR_UpdateClassFunctionListManager_Testing.hpp"
#include "TR_UpdateClassFunctionMapManager_Testing.hpp"

#include "TR_AppStateListManager_Testing.hpp"
//#include "TR_AppStateMapManager_Testing.hpp"

#include "TR_LoopManager_Testing.hpp"

#include "TR_DefaultAppSettings_Testing.hpp"

#include "TR_Application_Testing.hpp"

#include "TR_GlobalEvents_Testing.hpp"

//#include "TR_UsbNetwork_Testing.hpp"

using namespace pankey;

TestRunner test;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the test");
  
  delay(5000);
  
  TR_UpdateFunctionListManager_Testing(test);
  TR_UpdateFunctionMapManager_Testing(test);
  
  TR_UpdateClassFunctionListManager_Testing(test);
  TR_UpdateClassFunctionMapManager_Testing(test);

  TR_AppStateListManager_Testing(test);
//  TR_AppStateMapManager_Testing(test);
  
  TR_LoopManager_Testing(test);
  
  TR_DefaultAppSettings_Testing(test);
  
  TR_Application_Testing(test);

  TR_GlobalEvents_Testing(test);

  //TR_UsbNetwork_Testing(test);
}

void loop() {
  test.runTest();
  test.run();
  delay(3000);
}