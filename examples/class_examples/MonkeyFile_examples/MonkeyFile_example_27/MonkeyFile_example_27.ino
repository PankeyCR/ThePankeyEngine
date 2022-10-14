
#define ame_Level_7

#define LogApp
//#define MonkeyFileLogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"

#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"
#include "MonkeyTransporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "ElementId.hpp"

using namespace ame;

class Extra : public MonkeyTransporter{
  public:
  int x = 0;
  float value = 0;
  Note name = "Franco";
  
  Extra(){}
  Extra(const Extra& example){
    x = example.x;
    value = example.value;
    name = example.name;
  }

  Extra& operator=(const Extra& example){
    x = example.x;
    value = example.value;
    name = example.name;
    return *this;
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

class Example : public MonkeyTransporter{
  public:
  int x = 0;
  float value = 0;
  Note name = "Franco";
  Extra extra;
  
  Example(){}
  Example(const Example& example){
    x = example.x;
    value = example.value;
    name = example.name;
    extra = example.extra;
  }

  Example& operator=(const Example& example){
    x = example.x;
    value = example.value;
    name = example.name;
    extra = example.extra;
    return *this;
  }
  
  virtual void write(ElementId id, TextExporter* exporter){
    exporter->write(id.child("x"), x);
    exporter->write(id.child("value"), value);
    exporter->write(id.child("name"), name);
    extra.write(id.child("extra"), exporter);
  }
  virtual void read(ElementId id, TextImporter* importer){
    x = importer->read(id.child("x"), -1);
    value = importer->read(id.child("value"), -1.0f);
    name = importer->read(id.child("name"), name);
    extra.read(id.child("extra"), importer);
  }
};

DefaultMonkeyFile<SDFileSystemClass> file = SD;

void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("MonkeyFile");

  file.setRootPathFile("monkey");
  
  file.deleteFile("memory.txt");
  file.createFile("memory.txt");
  
  Example example;
  example.x = 15;
  example.value = 32.87f;
  example.name = "monkey";
  example.extra.x = 12;
  example.extra.value = 43.22;
  example.extra.name = "extra";
  
  TextExporter exporter;
  example.write("parent", &exporter);
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  Serial.println("start");
  TextImporter importer = file.readText("memory.txt");
  Example example;
  example.read("parent", &importer);
  Serial.println(example.x);
  Serial.println(example.value);
  Serial.println(example.name);
  Serial.println(example.extra.x);
  Serial.println(example.extra.value);
  Serial.println(example.extra.name);
  Serial.println();
}
