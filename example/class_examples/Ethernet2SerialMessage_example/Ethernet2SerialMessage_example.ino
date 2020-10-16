
#include "Application.h"
#include "DefaultApplication.h"
#include "SerialMessageState.h"
#include "DefaultSerialPort.h"
#include "MessageInvokeListener.h"
#include "Ethernet2SerialPortServer.h"
#include "Ethernet2SerialPortClient.h"
#include "CommandControl.h"
#include "MemoryFree.h"

Application* app;

void setup() {
  Serial.begin(9600);
  app = new DefaultApplication();
  byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
//  Ethernet2SerialPortClient* internet = new Ethernet2SerialPortClient(
//                                  IPAddress(192,168,15,25),  //server , sebastian tiene que darla
//                                  IPAddress(192,168,1,177),  //ip
//                                  mac                         //mac
//                                  );
  Ethernet2SerialPortServer* internet = new Ethernet2SerialPortServer(80,  // puerto del router ,  sebastian tiene que darla
                                  IPAddress(192,168,15,25),  //ip ,  sebastian tiene que darla
                                  IPAddress(192,168,15,1),  //GATEWAY
                                  IPAddress(255, 255, 255, 0),  //SUBNET
                                  mac                         //mac
                                  );
  SerialMessageState* serialState = new SerialMessageState();
  serialState->addSerial(new DefaultSerialPort(&Serial));//puerto usb
  serialState->addSerial(internet);
  serialState->setRawTypeName("raw");
  app->getStateManager()->add(serialState);
  
  MessageInvokeListener<CommandControl>* commandListener = new MessageInvokeListener<CommandControl>();
  commandListener->messageType("raw");
  commandListener->map->add("commandos",new CommandControl());
  serialState->addListener(commandListener);
}

void loop() {
  app->update();
}
