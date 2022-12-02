
#include "DefaultMonkeyFile.hpp"
#include "ElementId.hpp"
#include "TransporterObject.hpp"
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
  
  TransporterObject obj;
  
  obj.putObject("Object");
  obj.putInt("Object.intValue",15);
  obj.putFloat("Object.floatValue",76.01f);
  obj.putNote("Object.StringValue","value");
  
  TextExporter exporter;
  obj.write("parent", &exporter);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  TextImporter importer = file.readText("memory.txt");
  
  TransporterObject obj;
  obj.read("parent", &importer);
  
  System::console.println(obj);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}