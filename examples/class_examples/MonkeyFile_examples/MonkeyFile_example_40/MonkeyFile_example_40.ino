
#define ame_Level_7

//#define LogApp
//#define MonkeyFileLogApp

//#include "DefaultLogging.hpp"
//#include "Logger.hpp"

#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"
#include "MonkeyTransporter.hpp"
#include "TextImporter.hpp"
#include "TextExporter.hpp"
#include "MemoryRam.h"

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
//  initializeLogger(new DefaultLogging(&Serial, true, false));
//  LogClass("MonkeyFile");

  file.initialize();
  file.setRootPathFile("monkey");
}

void loop() {
  Serial.println("start");
  Example example;
  example.x = 15;
  example.value = 21.98f;
  example.name = "kandra"; 

  file.createFile("hi.txt");
  Note text = file.readText("hi.txt");
  Serial.print("text ");Serial.println(text);
  
  TextExporter exporter;
  example.write(ElementId("Example"), &exporter);

  file.writeText(exporter.getText(), "hi.txt");

  Example example_2;
  text = file.readText("hi.txt");
  TextImporter importer = text;
  example_2.read(ElementId("Example"), &importer);
  
  file.deleteFile("hi.txt");

  Serial.print("text ");Serial.println(text);
  Serial.println();
  Serial.print("x ");Serial.println(example_2.x);
  Serial.print("value ");Serial.println(example_2.value);
  Serial.print("name ");Serial.println(example_2.name);
  Serial.println();
  Serial.println(getRamSize());
  Serial.println();
  Serial.println();
}
