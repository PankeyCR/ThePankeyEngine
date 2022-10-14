
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
  
  PrimitiveMap<Note,Note> data;
  data.add("monkey", "play");
  data.add("engine", "stop");
  data.add("pankey", "play");
  data.add("game", "stop");
  
  TextExporter exporter;
  exporter.write("parent", data);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  Serial.println("start");
  TextImporter importer = file.readText("memory.txt");
  PrimitiveMap<Note,Note> data = importer.read("parent", PrimitiveMap<Note,Note>());
  if(data.isEmpty()){
    Serial.println("isEmpty");
  }
  for(int x = 0; x < data.getPosition(); x++){
    Serial.print("key ");Serial.println(*data.getKeyByPosition(x));
    Serial.print("value ");Serial.println(*data.getByPosition(x));
  }
  Serial.println();
}
