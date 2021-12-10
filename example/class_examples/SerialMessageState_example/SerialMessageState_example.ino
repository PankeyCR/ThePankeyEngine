
#define LogApp
#define MessageStaticMethodInvokeListenerLogApp
#define DefaultSerialPortLogApp
#define DefaultPortProtocolLogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"

#include "Application.hpp"
#include "DefaultApplication.hpp"
#include "SerialMessageState.hpp"
#include "DefaultSerialPort.hpp"
#include "DefaultPortProtocol.hpp"
#include "Message.hpp"
#include "Command.hpp"
#include "SerialListener.hpp"
#include "MemoryRam.h"

using namespace ame;

Application* app;

class Example : public SerialListener{
  public:
	Example(){}
	void execute(Message* mns){
		String txt = mns->text();
		String tp = mns->type();
		int Id = mns->id();
		String portName = mns->name();
		Serial.print("port name: ");Serial.println(portName);
		Serial.print("message recived: ");Serial.println(txt);
	}
};

void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("DefaultSerialPort");
  LogClass("DefaultPortProtocol");
  
  app = new DefaultApplication();
  
  SerialMessageState* serialState = new SerialMessageState();
  serialState->addSerialPort(new DefaultSerialPort(&Serial,"usb"), new DefaultPortProtocol());
  serialState->addListener(new Example());
  app->getStateManager()->add(serialState);
}

void loop() {
  app->update();
//  Serial.println(getRamSize());
}
