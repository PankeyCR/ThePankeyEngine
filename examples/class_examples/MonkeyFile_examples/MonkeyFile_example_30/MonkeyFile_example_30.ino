
#define ame_Level_7

#define LogApp
//#define MonkeyFileLogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"

#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"
#include "PrimitiveMap.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"

using namespace ame;

DefaultMonkeyFile<SDFileSystemClass> file = SD;

void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("MonkeyFile");

  file.setRootPathFile("monkey");
  
  file.deleteFile("memory.txt");
  file.createFile("memory.txt");
  
  PrimitiveMap<ElementId,Note> data;
  data.add(ElementId("monkey"), "play");
  data.add(ElementId("engine"), "stop");
  data.add(ElementId("pankey"), "play");
  data.add(ElementId("game"), "stop");
  
  TextExporter exporter;
  exporter.write("parent", data);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  Serial.println("start");
  TextImporter importer = file.readText("memory.txt");
  PrimitiveMap<ElementId,Note> data = importer.read("parent", PrimitiveMap<ElementId,Note>());
  if(data.isEmpty()){
    Serial.println("isEmpty");
  }
  for(int x = 0; x < data.getPosition(); x++){
    Serial.print("key id ");Serial.println(data.getKeyByPosition(x)->getId());
    Serial.print("value ");Serial.println(*data.getByPosition(x));
  }
  Serial.println();
}
