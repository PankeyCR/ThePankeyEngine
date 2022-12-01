
#include "DefaultMonkeyFile.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "System.hpp"

using namespace ame;

DefaultMonkeyFile<SDFileSystemClass> file = SD;

void setup() {
  Serial.begin(9600);
  
  file.initialize();
  
  file.deleteFile("memory.txt");
  file.createFile("memory.txt");
  
  TextExporter exporter;
  exporter.write("parent", 10);
  
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  TextImporter importer = file.readText("memory.txt");
  int number = importer.read("parent", -1);
  System::console.println(number);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}


//