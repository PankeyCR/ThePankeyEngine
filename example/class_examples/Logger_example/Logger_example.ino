
#define LogApp

#include "DefaultLogging.h"
#include "Logger.h"
#include "MemoryFree.h"

using namespace ame;

void setup() {
  Serial.begin(9600);
  int startmemory = freeMemory();
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("main");
  Log("main","setup","println","logger");
  int instancememory = freeMemory();
  delete Logger::getLog();
  int deletememory = freeMemory();
  
  Serial.print("instancememory ");Serial.println(startmemory-instancememory);
  Serial.print("leak ");Serial.println(startmemory-deletememory);
}

void loop() {

}
