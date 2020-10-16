
#include "SerialMessageState.h"
#include "DefaultSerialPort.h"
#include "MessageInvokeListener.h"
#include "Application.h"
#include "DefaultApplication.h"
#include "ScriptClass.h"
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
  
  ScriptClass* script = new ScriptClass();
  script->setSerial(&Serial);
  
  MessageInvokeListener<ScriptClass>* listener1 = new MessageInvokeListener<ScriptClass>();
  listener1->messageType("tag");
  listener1->map->add("ScriptClass",script);
  
  serialState->addListener(listener1);
  app->getStateManager()->add(serialState);
}

void loop() {
  app->update();
  //Serial.println(freeMemory());
}
