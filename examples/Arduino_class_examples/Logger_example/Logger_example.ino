
#define ame_Level_1

#define LogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"
#include "MemoryRam.h"

using namespace ame;

void setup() {
  Serial.begin(9600);
  int startmemory = getRamSize();
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("main");
  Log("main","setup","println","logger");
  int instancememory = getRamSize();
  delete Logger::getLog();
  int deletememory = getRamSize();
  
  Serial.print("instancememory ");Serial.println(startmemory-instancememory);
  Serial.print("leak ");Serial.println(startmemory-deletememory);
}

void loop() {

}
