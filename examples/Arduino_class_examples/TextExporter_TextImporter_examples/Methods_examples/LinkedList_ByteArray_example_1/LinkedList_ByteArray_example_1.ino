
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
  
  LinkedList<ByteArray> list;
  list.add(0b01010101);
  list.add(0b01010111);
  list.add(0b11010101);
  list.add(0b00000000);
  
  TextExporter exporter;
  exporter.write("parent", list);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  TextImporter importer = file.readText("memory.txt");
  LinkedList<ByteArray> list = importer.read("parent", LinkedList<ByteArray>());
  if(list.isEmpty()){
    System::console.println("isEmpty");
  }
  for(int x = 0; x < list.getPosition(); x++){
    System::console.println(toNote(list[x]));
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}