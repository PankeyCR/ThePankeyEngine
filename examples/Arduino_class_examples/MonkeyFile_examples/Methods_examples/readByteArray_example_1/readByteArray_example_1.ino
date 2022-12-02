
#include "ByteArray.hpp"
#include "DefaultMonkeyFile.hpp"

using namespace ame;

DefaultMonkeyFile<SDFileSystemClass> file = SD;

void setup() {
  Serial.begin(9600);
  
  file.initialize();
  
  file.deleteFile("memory.txt");
  file.createFile("memory.txt");
  ByteArray array = 0b01010101;
  array += 0b10101010;
  file.writeByteArray(array, "memory.txt");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ByteArray array = file.readByteArray("memory.txt");
  for(byte f_byte : array){
    Serial.println(f_byte);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}