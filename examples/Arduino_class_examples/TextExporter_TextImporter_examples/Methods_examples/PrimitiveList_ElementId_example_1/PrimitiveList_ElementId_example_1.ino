
#include "DefaultMonkeyFile.hpp"
#include "ElementId.hpp"
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
  
  PrimitiveList<ElementId> list;
  list.add(ElementId("c"));
  list.add(ElementId("a"));
  list.add(ElementId("t"));
  list.add(ElementId("s"));
  
  TextExporter exporter;
  exporter.write("parent", list);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  TextImporter importer = file.readText("memory.txt");
  PrimitiveList<ElementId> list = importer.read("parent", PrimitiveList<ElementId>());
  if(list.isEmpty()){
    System::console.println("isEmpty");
  }
  for(int x = 0; x < list.getPosition(); x++){
    System::console.println(list[x]);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}