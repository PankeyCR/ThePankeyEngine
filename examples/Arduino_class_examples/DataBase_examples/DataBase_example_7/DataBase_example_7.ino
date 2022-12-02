
#define ame_Level_7

#define LogApp
#define StartEndPortProtocolLogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"

#include "Application.hpp"
#include "DefaultApplication.hpp"
#include "MemoryRam.h"

#include "SerialMessageState.hpp"
#include "DefaultSerialPort.hpp"
#include "StartEndPortProtocol.hpp"//has to be next to SerialMessageState

#include <WiFi.h>
#include "WIFISerialPort.hpp"

#include "SystemListener.hpp"

#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "AlwaysConnected.hpp"
#include "IPAddress.h"

IPAddress ip(192, 168, 4, 124);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 4, 1);

using namespace ame;

Application* app;
SerialMessageState* serialState;

float t_time = 0;

void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
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
  
  AlwaysConnected* alwaysConnectedState = app->getStateManager()->addState(new AlwaysConnected());
  alwaysConnectedState->add("DataBase", IPAddress(192, 168, 4, 151), 55, new WIFISerialPort(), new StartEndPortProtocol());
}

void loop() {
  app->update();
  t_time += app->getStateManager()->tpc();
  if(t_time >= 2){
    t_time = 0;
    TextExporter exporter;
    exporter.write("DataBase.command", "get");
    exporter.write("DataBase.type", "object");
    exporter.write("DataBase.getObjList", true);

    serialState->send("DataBase",exporter.getExporterText());
    Serial.println("exporter.getText");
    Serial.println(exporter.getExporterText());
    Serial.println("request objList");
    Serial.println(getRamSize());
  }
//  Serial.println(getRamSize());
}

void MessageEvent(Message* message){
  Serial.println(message->text());
  
  TextImporter importer = message->text();
  Note objList = importer.read("DataBase.objList", "");

  Serial.println(objList);
  
}
