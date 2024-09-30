
#include "TestRunner.hpp"

#include "TR_EthernetSerialPort_Testing.hpp"
#include "TR_WIFISerialPort_Testing.hpp"
#include "TR_SerialState_Testing.hpp"

using namespace pankey;

TestRunner test;

void setup() {
  Serial.begin(9600);

  delay(5000);

  TR_EthernetSerialPort_Testing(test);
  TR_WIFISerialPort_Testing(test);
  TR_SerialState_Testing(test);

  test.omitInfo(true);
}

void loop() {
  test.runTest();
  test.run();
}