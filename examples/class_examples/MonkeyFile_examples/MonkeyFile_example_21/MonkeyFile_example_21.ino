
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
  
  LinkedList<Note> list;
  list.add("deep");
  list.add("monkey");
  list.add("string");
  list.add("node");
  
  TextExporter exporter;
  exporter.write("parent", list);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  Serial.println("start");
  TextImporter importer = file.readText("memory.txt");
  LinkedList<Note> list = importer.read("parent", LinkedList<Note>());
  if(list.isEmpty()){
    Serial.println("isEmpty");
  }
  for(int x = 0; x < list.getPosition(); x++){
    Serial.println(list[x]);
  }
  Serial.println();
}
