
#define ame_Level_7

#define LogApp
//#define MonkeyFileLogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"

#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"
#include "ElementId.hpp"
#include "TransporterObject.hpp"
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
  Serial.println("start");
  TextImporter importer = file.readText("memory.txt");
  
  TransporterObject obj;
  obj.read("parent", &importer);
  
  Serial.println(obj);
  Serial.println();
  Serial.println();
}
