
#define WIFI_IP "192.168.1.141"
#define WIFI_MAC { 7, 15, 5, 5, 0, 5 }

#include "SerialState.hpp"
#include "AlwaysConnected.hpp"

#include "WIFISerialServer.hpp"

#include "WIFISerialPort.hpp"
#include "DefaultSerialPort.hpp"

#include "DefaultServerProtocol.hpp"
#include "DefaultPortProtocol.hpp"

#include "SerialListenerState.hpp"
#include "SerialDelivery.hpp"

#include "ame_WIFI.hpp"
#include "SerialStateCommands.hpp"
#include "AlwaysConnectedCommands.hpp"
#include "NetworkMessageRedirection.hpp"

using namespace ame;

SerialState* serialState;
AlwaysConnected* alwaysConnectedState;
SerialListenerState<Note>* listener;

long prevNow = 0;

void setup() {
  Serial.begin(9600);

  uint8_t mac[6] = WIFI_MAC;

  initializeWIFI( WIFI_IP,                //ip
                  "192.168.1.1" ,         //gateway
                  "192.168.1.1" ,         //subnet
                  "255, 255, 255, 0" ,    //dns
                  mac ,                   //mac
                  "MERCUSYS_6541" ,       //router name
                  "57924106");            //router password

                  //router name MERCUSYS_6541 - pokemon
                  //router password 57924106 - tania1919

  haltUntilWIFIConnection();

  serialState = new SerialState();
  setSerialState(serialState);

  serialState->setIP(WIFI_IP);
  serialState->addSerialServer(new WIFISerialServer(55), new DefaultServerProtocol<DefaultPortProtocol>());
  serialState->addSerialPort(new DefaultSerialPort(&Serial, "usb"), new DefaultPortProtocol());

  listener = new SerialListenerState<Note>();
  listener->addListener(SerialMessage);
  listener->addListener(SerialStateCommands);
  listener->addListener(AlwaysConnectedCommands);
  listener->addListener(new NetworkMessageRedirection(serialState));

  SerialDelivery* delivery = new SerialDelivery(listener);

  serialState->setDelivery(delivery);

  serialState->initializeState();
  
  alwaysConnectedState = new AlwaysConnected(serialState);
  setAlwaysConnected(alwaysConnectedState);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  long Now = millis();
  float l_time = ((float)(Now - prevNow)) / 1000.0f;
  
  serialState->updateState(l_time);
  alwaysConnectedState->updateState(l_time);
  listener->updateState(l_time);
  
  prevNow = Now;
  ame_Debuging(ame_Log_EndLoop, "loop");
}

void SerialMessage(Note* message) {
  Note mns = *message;
  Serial.println("SerialMessage");
  Serial.println(mns);
  if (mns == "hola") {
    Serial.println("broadcast ethernet");
    serialState->instantSend("Mensaje recivido");
  }
}


//