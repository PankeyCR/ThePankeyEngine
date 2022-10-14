
#include "Reflection.hpp"

#include "System.hpp"

#include "Application.hpp"
#include "SimpleApplication.hpp"

#include "SerialPost.hpp"

#include "ReflectionDelivery.hpp"

#include "Note.hpp"

using namespace ame;

Application* app;

void setup() {
  Serial.begin(9600);

  delay(3000);
  
  app = new SimpleApplication();

  SerialPost* serialPost = app->getStateManager()->addState(new SerialPost());
  
  serialPost->addFullNetwork("192.168.5.170");
  serialPost->addFullDelivery<Note,ReflectionDelivery>();

  Reflection::ReflectEngine();

  Enviroment* enviroment = Reflection::getEnviroment();

  enviroment->add("app", app);

  System::console.println("starting...");
}

void loop() {
  app->update();
}





//