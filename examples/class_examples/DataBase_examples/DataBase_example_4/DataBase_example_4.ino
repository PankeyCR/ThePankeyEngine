
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
#include "MonkeyTransporter.h"

IPAddress ip(192, 168, 4, 123);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 4, 1);

using namespace ame;

Application* app;
SerialMessageState* serialState;
int count = 0;

class Example : public MonkeyTransporter{
  public:
  int intValue = 0;
  float floatValue = 0.0f;
  String stringValue = "";
  
  Example(){}
  virtual ~Example(){}
  
  virtual void write(ElementId id, MonkeyExporter* exporter){
    exporter->write(id.child("intValue"), intValue);
    exporter->write(id.child("floatValue"), floatValue);
    exporter->write(id.child("stringValue"), stringValue);
  }
  virtual void read(ElementId id, MonkeyImporter* importer){
    intValue = importer->read(id.child("intValue"), -1);
    floatValue = importer->read(id.child("floatValue"), -1.0f);
    stringValue = importer->read(id.child("stringValue"), "");
  }
};

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
  String parent = importer.read("DataBase.parent", "");
  int intV = importer.read("DataBase.parent.int", -1);
  float floatV = importer.read("DataBase.parent.float", -1.0f);
  String stringV = importer.read("DataBase.parent.string", "");
  bool connected = importer.read("DataBase.connected", false);
  
  if(connected && serialState->isConnected("DataBase")){
    Serial.println("Connected to the DataBase");
  }
  
  if(command == "put"){
    TextExporter exporter;
    Example example;
    example.intValue = intV;
    example.floatValue = floatV;
    example.stringValue = stringV;
    ElementId id = "parent";
    
    if(parent == ""){
      example.write(id, &exporter);
    }else{
      example.write(ElementId(parent), &exporter);
    }
    
    exporter.write("DataBase.command", "put");
    exporter.write("DataBase.type", "file");
    exporter.write("DataBase.dir", "sgsv");
    exporter.write("DataBase.path", "obj_memory.txt");

    serialState->send("DataBase",exporter.getText());
    return;
  }
  
  if(command == "get"){
    TextExporter exporter;
    exporter.write("DataBase.command", "get");
    exporter.write("DataBase.type", "file");
    exporter.write("DataBase.dir", "sgsv");
    exporter.write("DataBase.path", "obj_memory.txt");

    serialState->send("DataBase",exporter.getText());
    return;
  }
  
  if(command == "delete"){
    TextExporter exporter;
    exporter.write("DataBase.command", "delete");
    exporter.write("DataBase.type", "file");
    exporter.write("DataBase.dir", "sgsv");
    exporter.write("DataBase.path", "obj_memory.txt");

    serialState->send("DataBase",exporter.getText());
    return;
  }

  ElementId id = "parent";

  Example example;
  example.read(id, &importer);

  Serial.print("intValue ");Serial.println(example.intValue);
  Serial.print("floatValue ");Serial.println(example.floatValue);
  Serial.print("stringValue ");Serial.println(example.stringValue);
}

//!DataBase.command#get$!
//!DataBase.command#delete$!
//!DataBase.connected#1$!
//!DataBase.command#put$DataBase.parent#pokemon$DataBase.parent.int#23$DataBase.parent.float#54.34$DataBase.parent.string#hola$!
