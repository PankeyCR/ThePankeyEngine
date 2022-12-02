
#define LogApp
#define DataBaseStateLogApp
//#define ObjectDataBaseConfigLogApp
//#define TextExporterLogApp
//#define TextImporterLogApp
//#define MonkeyFileLogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"

#include "Application.hpp"
#include "DefaultApplication.hpp"

#include "SerialMessageState.hpp"
#include "DefaultSerialPort.hpp"
#include "StartEndPortProtocol.hpp"//has to be next to SerialMessageState

#include <WiFi.h>
#include "WIFISerialServer.hpp"
#include "DefaultServerProtocol.hpp"

#include "DataBaseState.hpp"
#include "ObjectDataBaseConfig.hpp"
#include "FileDataBaseConfig.hpp"

#include "SystemListener.hpp"
#include "Now.hpp"
#include "TimeCheck.hpp"

IPAddress ip(192, 168, 4, 151);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 4, 1);

using namespace ame;

Application* app;

void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("DataBaseState");
//  LogClass("ObjectDataBaseConfig");
//  LogClass("TextExporter");
//  LogClass("TextImporter");
//  LogClass("MonkeyFile");

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

  SerialMessageState* serialState = app->getStateManager()->addState(new SerialMessageState());
  serialState->addSerialServer(new WIFISerialServer(ip,gateway,subnet,55), new DefaultServerProtocol<StartEndPortProtocol>());
  serialState->addSerialPort(new DefaultSerialPort(&Serial,"usb"), new StartEndPortProtocol());

  serialState->addListener(new SystemListener(app));

  DataBaseState* database = app->getStateManager()->addState(new DataBaseState());
  database->addDataBaseConfig("file", new FileDataBaseConfig());
  DataBaseConfig* objectCenter = database->addDataBaseConfig("object", new ObjectDataBaseConfig());
  objectCenter->setFileSize(5);
}

void loop() {
  app->update();
}
