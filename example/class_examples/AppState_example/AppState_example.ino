
/*
 * the SimpleApplication is meant to be used when you need to use the guiNode and the rootNode
 * the DefaultApplication doesnt have guiNode or rootNode
 */
 
#include "Application.h"
#include "SimpleApplication.h"
#include "DefaultApplication.h"
#include "LoopState.h"
#include "StartState.h"
#include "TimerState.h"

 Application *app;
 
void setup() {
  Serial.begin(9600);
  app = new SimpleApplication();
//  app = new DefaultApplication();

  Serial.println("setup");
  app->getStateManager()->add(new StartState(&Serial));//starts the timer
  app->getStateManager()->add(new LoopState(&Serial));//appstate with update method (normal loop)
  app->getStateManager()->add(new TimerState(&Serial));//appstate with Play method (timer loop)

  app->getStateManager()->removeDelete(Class<StartState>::classType);//remove the appstate and delete´s it to save up memory but it wouldnt compute the time
  
}

void loop(){
  app->update();
}