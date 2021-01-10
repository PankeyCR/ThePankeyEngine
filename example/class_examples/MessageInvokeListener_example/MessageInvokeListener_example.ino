
//#define LogApp
//#define SerialMessageStateLogApp
//#define DefaultPortProtocolLogApp
//#define MessageInvokeListenerLogApp


#include "DefaultLogging.h"
#include "Logger.h"

#include "SerialMessageState.h"
#include "DefaultSerialPort.h"
#include "MessageInvokeListener.h"
#include "Application.h"
#include "DefaultApplication.h"
#include "DefaultServerProtocol.h"
#include "DefaultPortProtocol.h"
#include "DefaultSerialPort.h"
#include "ScriptClass.h"
#include "MemoryFree.h"

Application* app;

void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("SerialMessageState");
  LogClass("DefaultPortProtocol");
  LogClass("MessageInvokeListener");
  
  app = new DefaultApplication();
  
  SerialMessageState* serialState = new SerialMessageState();
  serialState->addSerialPort(new DefaultSerialPort(&Serial), new DefaultPortProtocol());
  
  ScriptClass* script = new ScriptClass();
  script->setSerial(&Serial);
  
  MessageInvokeListener<ScriptClass>* listener1 = new MessageInvokeListener<ScriptClass>();
  listener1->messageType("raw");
  listener1->map->addPointer("ScriptClass",script);
  
  serialState->addListener(listener1);
  app->getStateManager()->add(serialState);
}

void loop() {
  app->update();
  //Serial.println(freeMemory());
}