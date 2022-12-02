
#include "MemoryRam.h"
#include "Cast.hpp"

class MoveExample{
  public:
  bool m_copy = false;
  bool m_move = false;
  MoveExample(){
    Serial.println("MoveExample Normal Contructor");
  }
  MoveExample(const MoveExample& x){
    m_copy = true;
    Serial.println("MoveExample Copy Contructor");
  }
  MoveExample(MoveExample&& x){
    m_move = true;
    Serial.println("MoveExample Move Contructor");
  }
  void copy(bool t){m_copy = t;}
  void move(bool t){m_move = t;}
  
  virtual ~MoveExample(){
    Serial.println("MoveExample Destructor");
  }
  virtual MoveExample& operator=(const MoveExample& x){
    Serial.println("MoveExample Copy Operator");
    return *this;
  }
  virtual MoveExample& operator=(MoveExample&& x){
    Serial.println("MoveExample Move Operator");
    return *this;
  }
  void println(String a){
    Serial.println(a);    
  }
  void printC(){
    Serial.println(m_copy);    
  }
  void printM(){
    Serial.println(m_move);    
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
  Serial.println("Test 5");
  Test_5();
  Serial.println("Test 6");
  Test_6();

  Serial.println("//////////////////////////end");
  Serial.println(getRamSize());
}

void Test_1(){
  Serial.println("Line 1");  MoveExample y;
  Serial.println("Line 2");  MoveExample&& z = MoveExample(y);
  Serial.println("Line 3");  z.printC();
  Serial.println("Line 4");  z.printM();
  Serial.println("Line 5");  y.printC();
  Serial.println("Line 6");  y.printM();
}

void Test_2(){
  Serial.println("Line 1");  MoveExample y;
  Serial.println("Line 2");  MoveExample&& z = MoveExample();
  Serial.println("Line 3");  z.printC();
  Serial.println("Line 4");  z.printM();
  Serial.println("Line 5");  y.printC();
  Serial.println("Line 6");  y.printM();
}

void Test_3(){
  Serial.println("Line 1");  MoveExample y;
  Serial.println("Line 2");  MoveExample&& z = ame::move<MoveExample>(y);
  Serial.println("Line 3");  z.printC();
  Serial.println("Line 4");  z.printM();
  Serial.println("Line 5");  y.printC();
  Serial.println("Line 6");  y.printM();
}

void Test_4(){
  Serial.println("Line 1");  MoveExample y;
                             y.move(true);
  Serial.println("Line 2");  MoveExample&& z = ame::move<MoveExample>(y);
  Serial.println("Line 3");  z.printC();
  Serial.println("Line 4");  z.printM();
  Serial.println("Line 5");  y.printC();
  Serial.println("Line 6");  y.printM();
}

void Test_5(){
  Serial.println("Line 1");  MoveExample y;
  Serial.println("Line 2");  MoveExample&& z = ame::move<MoveExample>(y);
                             y.move(true);
  Serial.println("Line 3");  z.printC();
  Serial.println("Line 4");  z.printM();
  Serial.println("Line 5");  y.printC();
  Serial.println("Line 6");  y.printM();
}

void Test_6(){
  Serial.println("Line 1");  MoveExample* y = new MoveExample();
                             y->move(true);
  Serial.println("Line 2");  MoveExample&& z = ame::move<MoveExample>(*y);
  Serial.println("Line 3");  z.printC();
  Serial.println("Line 4");  z.printM();
  Serial.println("Line 5");  y->printC();
  Serial.println("Line 6");  y->printM();
  delete y;
}
