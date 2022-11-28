
#include "ByteArray.hpp"
#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"

using namespace ame;

DefaultMonkeyFile<SDFileSystemClass> file = SD;

void setup() {
  Serial.begin(9600
  
  file.initialize();

  file.setRootPathFile("monkey");
  
  file.deleteFile("memory.txt");
  file.deleteRootFile("memory.txt");
  ByteArray array = 0b01010101;
  file.createRootFile("memory.txt");
  file.writeRootByteArray(array, "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ByteArray array = file.readRootByteArray("memory.txt");
  for(byte f_byte : array){
    Serial.println(f_byte);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}