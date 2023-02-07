
#include "DefaultApplication.hpp"
#include "SerialState.hpp"

#include "DefaultPortProtocol.hpp"
#include "DefaultSerialPort.hpp"

#include "SerialListenerState.hpp"
#include "SerialDelivery.hpp"

#include "SerialStateCommands.hpp"

using namespace ame;

Application* app;
SerialState* serialState;
SerialListenerState<Note>* listener;

void setup() {
  Serial.begin(9600);
  
  app = new DefaultApplication();
  
  serialState = app->getStateManager()->addState(new SerialState());

  serialState->addSerialPort(new DefaultSerialPort(&Serial, "usb"), new DefaultPortProtocol());

  listener = new SerialListenerState<Note>();
  listener->addListener(SerialMessage);

  SerialDelivery* delivery = new SerialDelivery(listener);

  serialState->setDelivery(delivery);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  app->update();
  ame_Debuging(ame_Log_EndLoop, "loop");
}

void SerialMessage(Note* message) {
  Note mns = *message;
  Serial.println("SerialMessage");
  Serial.println(mns);
  if (mns == "hola") {

  }
}


//