
#include "DefaultMonkeyFile.hpp"
#include "MonkeyTransporter.hpp"
#include "TextImporter.hpp"
#include "TextExporter.hpp"
#include "System.hpp"

using namespace ame;

DefaultMonkeyFile<SDFileSystemClass> file = SD;

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
  
  virtual void write(ElementId id, MonkeyExporter* file){
    file->write(id.child("x"), x);
    file->write(id.child("value"), value);
    file->write(id.child("name"), name);
  }
  virtual void read(ElementId id, MonkeyImporter* file){
    x = file->read(id.child("x"), -1);
    value = file->read(id.child("value"), -1.0f);
    name = file->read(id.child("name"), name);
  }
};

void setup() {
  Serial.begin(9600);

  file.initialize();
  file.setRootPathFile("monkey");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Example example;
  example.x = 15;
  example.value = 21.98f;
  example.name = "kandra"; 

  file.createFile("hi.txt");
  Note text = file.readText("hi.txt");
  System::console.print("text ");System::console.println(text);
  
  TextExporter exporter;
  example.write(ElementId("Example"), &exporter);

  file.writeText(exporter.getText(), "hi.txt");

  Example example_2;
  text = file.readText("hi.txt");
  TextImporter importer = text;
  example_2.read(ElementId("Example"), &importer);
  
  file.deleteFile("hi.txt");

  System::console.print("text ");   System::console.println(text);
  System::console.print("x ");      System::console.println(example_2.x);
  System::console.print("value ");  System::console.println(example_2.value);
  System::console.print("name ");   System::console.println(example_2.name);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}