
#include "cppObject.h"
//for instanceof<class T> to work you need to implement the getClassName method and
// the instanceof(String name) method on your derived classes
//this example shows a easy way to go through all the derived classes

class Tick : public cppObject{
  public:
  Tick(){}
  ~Tick(){}
  String getClassName(){
    return "Tick";
  }
  bool instanceof(String name){
    return name == "Tick" || cppObject::instanceof(name);
  }
};

class Stop : public Tick{
  public:
  Stop(){}
  ~Stop(){}
  String getClassName(){
    return "Stop";
  }
  bool instanceof(String name){
    return name == "Stop" || Tick::instanceof(name);
  }
};

class Resume : public Stop{
  public:
  Resume(){}
  ~Resume(){}
  String getClassName(){
    return "Resume";
  }
  bool instanceof(String name){
    return Stop::instanceof(name);//if this is your last derived class, you don need to check for your own class because is done on the cppObject, but only on the last derived class
    //return name == "Resume" || Tick::instanceof(name);
  }
};

void setup() {
  Serial.begin(9600);
  
  cppObject* a = new cppObject();
  cppObject* b = new Tick();
  cppObject* c = new Stop();
  cppObject* d = new Resume();
  Serial.println("cppObject");
  Serial.print("a is instanceof cppObject: ");Serial.println(a->instanceof<cppObject>());
  Serial.print("a is instanceof Tick: ");Serial.println(a->instanceof<Tick>());
  Serial.print("a is instanceof Stop: ");Serial.println(a->instanceof<Stop>());
  Serial.print("a is instanceof Resume: ");Serial.println(a->instanceof<Resume>());
  Serial.println();
  Serial.println("Tick");
  Serial.print("b is instanceof cppObject: ");Serial.println(b->instanceof<cppObject>());
  Serial.print("b is instanceof Tick: ");Serial.println(b->instanceof<Tick>());
  Serial.print("b is instanceof Stop: ");Serial.println(b->instanceof<Stop>());
  Serial.print("b is instanceof Resume: ");Serial.println(b->instanceof<Resume>());
  Serial.println();
  Serial.println("Stop");
  Serial.print("c is instanceof cppObject: ");Serial.println(c->instanceof<cppObject>());
  Serial.print("c is instanceof Tick: ");Serial.println(c->instanceof<Tick>());
  Serial.print("c is instanceof Stop: ");Serial.println(c->instanceof<Stop>());
  Serial.print("c is instanceof Resume: ");Serial.println(c->instanceof<Resume>());
  Serial.println();
  Serial.println("Resume");
  Serial.print("d is instanceof cppObject: ");Serial.println(d->instanceof<cppObject>());
  Serial.print("d is instanceof Tick: ");Serial.println(d->instanceof<Tick>());
  Serial.print("d is instanceof Stop: ");Serial.println(d->instanceof<Stop>());
  Serial.print("d is instanceof Resume: ");Serial.println(d->instanceof<Resume>());
}

void loop() {
}
