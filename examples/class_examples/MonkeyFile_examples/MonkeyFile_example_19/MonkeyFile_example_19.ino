
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
  
  LinkedList<char> list;
  list.add('c');
  list.add('a');
  list.add('t');
  list.add('s');
  
  TextExporter exporter;
  exporter.write("parent", list);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  Serial.println("start");
  TextImporter importer = file.readText("memory.txt");
  LinkedList<char> list = importer.read("parent", LinkedList<char>());
  if(list.isEmpty()){
    Serial.println("isEmpty");
  }
  for(int x = 0; x < list.getPosition(); x++){
    Serial.println(list[x]);
  }
  Serial.println();
}
