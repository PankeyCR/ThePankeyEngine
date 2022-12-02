
#include "DefaultMonkeyFile.hpp"
#include "PrimitiveMap.hpp"
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
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  TextImporter importer = file.readText("memory.txt");
  PrimitiveMap<ElementId,Note> data = importer.read("parent", PrimitiveMap<ElementId,Note>());
  if(data.isEmpty()){
    System::console.println("isEmpty");
  }
  for(int x = 0; x < data.getPosition(); x++){
    System::console.print("key id ");System::console.println(data.getKeyByPosition(x)->getId());
    System::console.print("value ");System::console.println(*data.getValueByPosition(x));
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}