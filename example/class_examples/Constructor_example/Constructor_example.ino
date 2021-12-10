
#include "MemoryRam.h"

class Base{
  public:
  Base(){
    Serial.println("Base Normal Contructor");
  }
  Base(int x){
    Serial.println("Base Normal Contructor Int Parameter");
  }
  Base(const Base& x){
    Serial.println("Base Copy Contructor");
  }
  virtual ~Base(){
    Serial.println("Base Destructor");
  }
};

class Derived_1 : public Base{
  public:
  Derived_1(){
    Serial.println("Derived_1 Normal Contructor");
  }
  Derived_1(int x){
    Serial.println("Derived_1 Normal Contructor Int Parameter");
  }
  Derived_1(const Derived_1& x){
    Serial.println("Derived_1 Copy Contructor");
  }
  virtual ~Derived_1(){
    Serial.println("Derived_1 Destructor");
  }
};

class Derived_2 : public Base{
  public:
  Derived_2() : Base(5){
    Serial.println("Derived_2 Normal Contructor");
  }
  Derived_2(int x){
    Serial.println("Derived_2 Normal Contructor Int Parameter");
  }
  Derived_2(const Derived_2& x){
    Serial.println("Derived_2 Copy Contructor");
  }
  virtual ~Derived_2(){
    Serial.println("Derived_2 Destructor");
  }
};

class Derived_3 : public Base{
  public:
  Derived_3(){
    Serial.println("Derived_3 Normal Contructor");
  }
  Derived_3(int x){
    Serial.println("Derived_3 Normal Contructor Int Parameter");
  }
  Derived_3(const Derived_3& x){
    Serial.println("Derived_1 Copy Contructor");
  }
  virtual ~Derived_3(){
    Serial.println("Derived_3 Destructor");
  }
};

class NotDerived{
  public:
  Base b;
  NotDerived() : b(5){
    Serial.println("NotDerived Normal Contructor");
  }
  NotDerived(int x){
    Serial.println("NotDerived Normal Contructor Int Parameter");
  }
  NotDerived(const NotDerived& x){
    Serial.println("NotDerived Copy Contructor");
  }
  virtual ~NotDerived(){
    Serial.println("NotDerived Destructor");
  }
};

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println("//////////////////////////start");
  Serial.println(getRamSize());

  Serial.println("Test 1");
  Test_1();
  Serial.println("Test 2");
  Test_2();
  Serial.println("Test 3");
  Test_3();
  Serial.println("Test 4");
  Test_4();
//  Serial.println("Test 5");
//  Test_5();
//  Serial.println("Test 6");
//  Test_6();
  
  Serial.println("//////////////////////////end");
  Serial.println(getRamSize());
}


void Test_1(){
  Derived_1 x;
}

void Test_2(){
  Derived_2 x;
}

void Test_3(){

}

void Test_4(){
  NotDerived x;
}
