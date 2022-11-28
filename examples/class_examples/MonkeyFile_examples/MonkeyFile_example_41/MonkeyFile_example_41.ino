
#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"

using namespace ame;

DefaultMonkeyFile<SDFileSystemClass> file = SD;

void setup() {
  Serial.begin(9600);
  
  file.initialize();

  file.setRootPathFile("monkey");
  
  file.deleteFile("memory.txt");
  file.deleteRootFile("memory.txt");
  file.createFile("memory.txt");
  file.writeText("saving memory", "memory.txt");
  
  file.createRootFile("memory.txt");
  file.writeRootText("saving root memory", "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Note text = file.readText("memory.txt");
  Serial.println(text);
  Note textRoot = file.readRootText("memory.txt");
  Serial.println(textRoot);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}