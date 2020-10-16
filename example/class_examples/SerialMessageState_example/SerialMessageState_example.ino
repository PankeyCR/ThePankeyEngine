
#include "SerialMessageState.h"
#include "DefaultSerialPort.h"
#include "MessageCommand.h"
#include "Application.h"
#include "DefaultApplication.h"
#include "MemoryFree.h"

Application* app;

void setup() {
  Serial.begin(9600);
  app = new DefaultApplication();
  
  SerialMessageState* serialState = new SerialMessageState();
  serialState->addSerial(new DefaultSerialPort(&Serial));
  serialState->addType("command",'¡','!');
  serialState->addType("tag",'<','>');
  serialState->setRawTypeName("raw");
  serialState->addListener(new MessageCommand());
  app->getStateManager()->add(serialState);
}

void loop() {
  app->update();
  Serial.println(freeMemory());
}
