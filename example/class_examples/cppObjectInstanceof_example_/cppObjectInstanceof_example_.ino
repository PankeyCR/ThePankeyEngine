
#include "cppObject.h"
#include "MemoryFree.h"
//for instanceof to work you need to implement the getClass method and
// the instanceof(cppObjectClass* cls) method on your derived classes
//this example shows a easy way to go through all the derived classes

class Tick : public cppObject{
  public:
  Tick(){}
  virtual ~Tick(){}
  cppObjectClass* getClass(){
    return Class<Tick>::classType;
  }
  bool instanceof(cppObjectClass* cls){
    return cls == Class<Tick>::classType || cppObject::instanceof(cls);
  }
};

class Stop : public Tick{
  public:
  Stop(){}
  virtual ~Stop(){}
  cppObjectClass* getClass(){
    return Class<Stop>::classType;
  }
  bool instanceof(cppObjectClass* cls){
    return cls == Class<Stop>::classType || Tick::instanceof(cls);
  }
};

class Resume : public Stop{
  public:
  Resume(){}
  virtual ~Resume(){}
  cppObjectClass* getClass(){
    return Class<Resume>::classType;
  }
  bool instanceof(cppObjectClass* cls){
    return cls == Class<Resume>::classType || Stop::instanceof(cls);
  }
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("start");
  Serial.println(freeMemory());
  cppObject* a = new cppObject();
  cppObject* b = new Tick();
  cppObject* c = new Stop();
  cppObject* d = new Resume();
  Serial.println("cppObject");
  Serial.print("cppObject is instanceof cppObject: ");Serial.println(a->instanceof(Class<cppObject>::classType));
  Serial.print("cppObject is instanceof Tick: ");Serial.println(a->instanceof(Class<Tick>::classType));
  Serial.print("cppObject is instanceof Stop: ");Serial.println(a->instanceof(Class<Stop>::classType));
  Serial.print("cppObject is instanceof Resume: ");Serial.println(a->instanceof(Class<Resume>::classType));
  Serial.println();
  Serial.println("Tick");
  Serial.print("Tick is instanceof cppObject: ");Serial.println(b->instanceof(Class<cppObject>::classType));
  Serial.print("Tick is instanceof Tick: ");Serial.println(b->instanceof(Class<Tick>::classType));
  Serial.print("Tick is instanceof Stop: ");Serial.println(b->instanceof(Class<Stop>::classType));
  Serial.print("Tick is instanceof Resume: ");Serial.println(b->instanceof(Class<Resume>::classType));
  Serial.println();
  Serial.println("Stop");
  Serial.print("Stop is instanceof cppObject: ");Serial.println(c->instanceof(Class<cppObject>::classType));
  Serial.print("Stop is instanceof Tick: ");Serial.println(c->instanceof(Class<Tick>::classType));
  Serial.print("Stop is instanceof Stop: ");Serial.println(c->instanceof(Class<Stop>::classType));
  Serial.print("Stop is instanceof Resume: ");Serial.println(c->instanceof(Class<Resume>::classType));
  Serial.println();
  Serial.println("Resume");
  Serial.print("Resume is instanceof cppObject: ");Serial.println(d->instanceof(Class<cppObject>::classType));
  Serial.print("Resume is instanceof Tick: ");Serial.println(d->instanceof(Class<Tick>::classType));
  Serial.print("Resume is instanceof Stop: ");Serial.println(d->instanceof(Class<Stop>::classType));
  Serial.print("Resume is instanceof Resume: ");Serial.println(d->instanceof(Class<Resume>::classType));
  delete a;
  delete b;
  delete c;
  delete d;
  Serial.println("end");
  Serial.println(freeMemory());
}