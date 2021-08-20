
#define LogApp
#define MessageStaticMethodInvokeListenerLogApp
#define DefaultSerialPortLogApp
#define DefaultPortProtocolLogApp

#include "DefaultLogging.h"
#include "Logger.h"

#include "Application.h"
#include "DefaultApplication.h"
#include "SerialMessageState.h"
#include "DefaultSerialPort.h"
#include "DefaultPortProtocol.h"
#include "Message.h"
#include "Command.h"
#include "MemoryFree.h"

using namespace ame;

Application* app;

class Example : public Command<Message>{
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
//  Serial.println(freeMemory());
}
