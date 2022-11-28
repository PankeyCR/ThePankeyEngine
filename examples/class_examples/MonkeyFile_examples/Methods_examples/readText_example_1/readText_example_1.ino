
#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"

using namespace ame;

DefaultMonkeyFile<SDFileSystemClass> file = SD;

void setup() {
  Serial.begin(9600);
  
  file.initialize();
  
  file.deleteFile("memory.txt");
  file.createFile("memory.txt");
  file.writeText("saving memory", "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Note text = file.readText("memory.txt");
  Serial.println(text);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}