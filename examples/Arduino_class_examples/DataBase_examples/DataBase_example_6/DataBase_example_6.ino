
//#define LogApp
//#define SystemListenerLogApp
//#define SerialMessageStateLogApp
//#define StartEndPortProtocolLogApp

//#include "DefaultLogging.hpp"
//#include "Logger.hpp"

#include "Application.hpp"
#include "DefaultApplication.hpp"

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

IPAddress ip(192, 168, 4, 123);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 4, 1);

using namespace ame;

Application* app;
SerialMessageState* serialState;

float t_time = 0;
long count = 0;

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
  
  AlwaysConnected* alwaysConnectedState = app->getStateManager()->addState(new AlwaysConnected());
  alwaysConnectedState->add("DataBase", IPAddress(192, 168, 4, 151), 55, new WIFISerialPort(), new StartEndPortProtocol());
}

void loop() {
  app->update();
  t_time += app->getStateManager()->tpc();
  if(t_time >= 3){
    t_time = 0;
    TextExporter exporter;
    
    exporter.addTag("DataBase.project", "test");
    exporter.addTag("DataBase.command", "put");
    exporter.addTag("DataBase.type", "object");
    exporter.addTag("camion.actual", "Camion.z_0_0");
    
    LinkedList<float> z_0_0;
    z_0_0.add(3.7f);
    z_0_0.add(4.7f);
    z_0_0.add(2.3f);
    z_0_0.add(3.4f);
    z_0_0.add(3.1f);
    exporter.write("Camion.z_0_0", z_0_0);
    exporter.write("count", count);

    exporter.writeTags();
    serialState->send("DataBase",exporter.getExporterText());
    count++;
  }
}
