
#include "DefaultApplication.h"
#include "Application.h"
#include "LoopState.h"
#include "StartState.h"
#include "TimerState.h"
#include "MemoryFree.h"

 Application *app;

int deletememory;
int startmemory;
int instancememory;
 
void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  app = new DefaultApplication();
  
  app->getStateManager()->add(new StartState());//starts the timer
  app->getStateManager()->add(new LoopState(&Serial));//appstate with update method (normal loop)
  app->getStateManager()->add(new TimerState(&Serial));//appstate with Play method (timer loop)
  instancememory = freeMemory();
   
  delete app;
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop(){
}
