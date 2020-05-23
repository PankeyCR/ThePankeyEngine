#define Log
#define LogSerial

#include "SimpleApplication.h"
#include "Application.h"
#include "WebPageState.h"
#include "WebCommands.h"
#include "RectifierState.h"

Application* app;
WebPageState* webpage;

void setup() {
  Serial.begin(9600);
  LogSerial(&Serial);
  app = new SimpleApplication<4>();
  //webpage =  new WebPageState("WebPage","pokemon","tania1919");
  //webpage->addCommand(new WebCommands());
  
 // app->getStateManager()->add(webpage);
  app->getStateManager()->add(new RectifierState());
}

void loop() {
  app->update();

}
