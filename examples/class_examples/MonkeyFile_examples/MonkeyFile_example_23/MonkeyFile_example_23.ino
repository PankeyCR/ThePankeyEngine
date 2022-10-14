
#define ame_Level_7

#define LogApp
//#define MonkeyFileLogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"

#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"
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
  
  PrimitiveList<long> list;
  list.add(12345678l);
  list.add(12345678l);
  list.add(12345678l);
  list.add(87654321l);
  
  TextExporter exporter;
  exporter.write("parent", list);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  Serial.println("start");
  TextImporter importer = file.readText("memory.txt");
  PrimitiveList<long> list = importer.read("parent", PrimitiveList<long>());
  if(list.isEmpty()){
    Serial.println("isEmpty");
  }
  for(int x = 0; x < list.getPosition(); x++){
    Serial.println(list[x]);
  }
  Serial.println();
}
