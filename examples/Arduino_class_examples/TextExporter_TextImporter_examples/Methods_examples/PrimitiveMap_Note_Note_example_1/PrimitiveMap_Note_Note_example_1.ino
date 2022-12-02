
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
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  TextImporter importer = file.readText("memory.txt");
  PrimitiveMap<Note,Note> data = importer.read("parent", PrimitiveMap<Note,Note>());
  if(data.isEmpty()){
    System::console.println("isEmpty");
  }
  for(int x = 0; x < data.getPosition(); x++){
    System::console.print("key ");System::console.println(*data.getKeyByPosition(x));
    System::console.print("value ");System::console.println(*data.getValueByPosition(x));
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}