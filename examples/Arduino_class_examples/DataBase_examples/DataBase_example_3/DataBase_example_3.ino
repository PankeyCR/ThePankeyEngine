
#define ame_Level_7

//#define LogApp
//#define SystemListenerLogApp
//#define SerialMessageStateLogApp
//#define StartEndPortProtocolLogApp

//#include "DefaultLogging.h"
//#include "Logger.h"

#include "Application.h"
#include "DefaultApplication.h"

#include "SerialMessageState.h"
#include "DefaultSerialPort.h"
#include "StartEndPortProtocol.h"//has to be next to SerialMessageState

#include <WiFi.h>
#include "WIFISerialPort.h"

#include "SystemListener.h"

#include "TextExporter.h"
#include "TextImporter.h"
#include "AlwaysConnected.h"
#include "IPAddress.h"

IPAddress ip(192, 168, 4, 123);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 4, 1);

using namespace ame;

Application* app;
SerialMessageState* serialState;

void setup() {
  Serial.begin(9600);
//  initializeLogger(new DefaultLogging(&Serial, true, false));
//  LogClass("StartEndPortProtocol");

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);
  if(!WiFi.config(ip,gateway,subnet,dns)) {
    Serial.println("STA Failed to configure");
  }
  WiFi.begin("RACSA","RACSA2021#*");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());

  app = new DefaultApplication();
  
  serialState = app->getStateManager()->addState(new SerialMessageState());
  serialState->addSerialPort(new DefaultSerialPort(&Serial,"usb"), new StartEndPortProtocol());

  serialState->addListener(new SystemListener(app));
  serialState->addListener(MessageEvent);
  
  AlwaysConnected* alwaysConnectedState = app->getStateManager()->addState(new AlwaysConnected("testMicro"));
  alwaysConnectedState->add("DataBase", IPAddress(192, 168, 4, 151), 55, new WIFISerialPort(), new StartEndPortProtocol());
}

void loop() {
  app->update();
}

void MessageEvent(Message* message){
  Serial.println(message->text());
  
  TextImporter importer = message->text();
  String command = importer.read("DataBase.command", "");
  bool connected = importer.read("DataBase.connected", false);
  
  if(connected){
    Serial.println("Connected to the DataBase");
  }
  
  if(command == "put"){
    TextExporter exporter;
    exporter.write("DataBase.command", "put");
    exporter.write("DataBase.type", "file");
    exporter.write("DataBase.dir", "sgsv");
    exporter.write("DataBase.path", "n_memory.txt");
    exporter.write("Camion.placa", "cl1234");
    exporter.write("Camion.Vin", 3.7f);

    serialState->send("DataBase",exporter.getText());
  }
  
  if(command == "put2"){
    TextExporter exporter;
    exporter.write("DataBase.command", "put");
    exporter.write("DataBase.type", "file");
    exporter.write("DataBase.dir", "sgsv");
    exporter.write("DataBase.path", "n_memory.txt");
    exporter.write("Camion.placa", "cl4321");
    exporter.write("Camion.Vin", 5.4f);

    serialState->send("DataBase",exporter.getText());
  }
  if(command == "get"){
    TextExporter exporter;
    exporter.write("DataBase.command", "get");
    exporter.write("DataBase.type", "file");
    exporter.write("DataBase.dir", "sgsv");
    exporter.write("DataBase.path", "n_memory.txt");

    serialState->send("DataBase",exporter.getText());
  }
  if(command == "get2"){
    TextExporter exporter;
    exporter.write("DataBase.command", "get");
    exporter.write("DataBase.type", "file");
    exporter.write("DataBase.dir", "sgsv");
    exporter.write("DataBase.path", "n_memory.txt");
    exporter.write("DataBase.reply", "testMicro");

    serialState->send("DataBase",exporter.getText());
  }
}
