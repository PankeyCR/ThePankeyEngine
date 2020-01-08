
#include "DefaultApplication.h"
#include "Application.h"
#include "LoopState.h"
#include "StartState.h"
#include "TimerState.h"

 Application *app;
 
void setup() {
  Serial.begin(9600);
  app = new DefaultApplication();
  app->getStateManager()->add(new StartState());//starts the timer
//  app->getStateManager()->add(new LoopState(&Serial));//appstate with update method (normal loop)
  app->getStateManager()->add(new TimerState(&Serial));//appstate with Play method (timer loop)
}

void loop(){
  app->update();
}
