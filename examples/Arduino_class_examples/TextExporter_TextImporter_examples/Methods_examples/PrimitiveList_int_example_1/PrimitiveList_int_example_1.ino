
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
  
  PrimitiveList<int> list;
  list.add(20);
  list.add(21);
  list.add(22);
  list.add(23);
  
  TextExporter exporter;
  exporter.write("parent", list);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  TextImporter importer = file.readText("memory.txt");
  PrimitiveList<int> list = importer.read("parent", PrimitiveList<int>());
  if(list.isEmpty()){
    System::console.println("isEmpty");
  }
  for(int x = 0; x < list.getPosition(); x++){
    System::console.println(list[x]);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}