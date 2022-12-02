
#include "DefaultMonkeyFile.hpp"
#include "ElementId.hpp"
#include "MonkeyTransporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "System.hpp"

using namespace ame;

class Example : public MonkeyTransporter{
  public:
  int x = 0;
  float value = 0;
  Note name = "Franco";
  
  Example(){}
  Example(const Example& example){
    x = example.x;
    value = example.value;
    name = example.name;
  }
  
  virtual void write(ElementId id, TextExporter* exporter){
    exporter->write(id.child("x"), x);
    exporter->write(id.child("value"), value);
    exporter->write(id.child("name"), name);
  }
  virtual void read(ElementId id, TextImporter* importer){
    x = importer->read(id.child("x"), -1);
    value = importer->read(id.child("value"), -1.0f);
    name = importer->read(id.child("name"), name);
  }
};

DefaultMonkeyFile<SDFileSystemClass> file = SD;

void setup() {
  Serial.begin(9600);
  
  file.initialize();
  
  file.deleteFile("memory.txt");
  file.createFile("memory.txt");
  
  Example example;
  example.x = 15;
  example.value = 32.87f;
  example.name = "monkey";
  
  TextExporter exporter;
  example.write("parent", &exporter);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  TextImporter importer = file.readText("memory.txt");
  Example example;
  example.read("parent", &importer);
  System::console.println(example.x);
  System::console.println(example.value);
  System::console.println(example.name);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}