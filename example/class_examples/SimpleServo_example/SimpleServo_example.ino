
#include "SimpleServo.h"
#include "MemoryFree.h"

SimpleServo *servos;

void setup() {
  Serial.begin(9600);
  Serial.println(freeMemory()); 
  
  servos = new SimpleServo();
  Serial.println(freeMemory()); 
  servos->setup(5);
  Serial.println(freeMemory()); 

  servos->attach(0,24);        
  servos->attach(1,26);
  servos->attach(2,28);
  servos->attach(3,30);
  servos->attach(4,31);

  delete servos;
  Serial.println(freeMemory()); 

}
void loop() {
}
