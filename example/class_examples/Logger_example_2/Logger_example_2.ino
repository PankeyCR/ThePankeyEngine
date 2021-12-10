
#define ExampleLogApp

#define LogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"
#include "MemoryRam.h"

//using namespace ame;

#ifdef ExampleLogApp
  #define ExampleLog(name,method,type,mns) Log(name,method,type,mns)
#else
  #define ExampleLog(name,method,type,mns)
#endif

using namespace ame;

class Example{
  public:
  Example(){
    ExampleLog("Example","Contructor","println","");
  }
};
void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("Example");
}

void loop() {
  Example x;
  Serial.println(getRamSize());
}
