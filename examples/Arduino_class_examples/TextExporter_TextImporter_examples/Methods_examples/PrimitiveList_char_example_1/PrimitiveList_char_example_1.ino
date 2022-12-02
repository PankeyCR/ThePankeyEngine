
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
  
  PrimitiveList<char> list;
  list.add('c');
  list.add('a');
  list.add('t');
  list.add('s');
  
  TextExporter exporter;
  exporter.write("parent", list);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  TextImporter importer = file.readText("memory.txt");
  PrimitiveList<char> list = importer.read("parent", PrimitiveList<char>());
  if(list.isEmpty()){
    System::console.println("isEmpty");
  }
  for(int x = 0; x < list.getPosition(); x++){
    System::console.println(list[x]);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}