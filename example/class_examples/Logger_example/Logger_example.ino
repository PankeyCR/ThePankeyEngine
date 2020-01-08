
//#define Log 
//#define LogSerial 

#include "Logger.h"
#include "MemoryFree.h"


void setup() {
  Serial.begin(9600);
  int startmemory = freeMemory();
  LogSerial(&Serial);
  Log("println","logger");
  int instancememory = freeMemory();
  delete Logger::getLog();
  int deletememory = freeMemory();
  
  Serial.print("instancememory ");Serial.println(startmemory-instancememory);
  Serial.print("leak ");Serial.println(startmemory-deletememory);
}

void loop() {

}
