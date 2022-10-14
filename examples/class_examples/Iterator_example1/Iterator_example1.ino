
#include "Iterator.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop(){
  Serial.println("///////////////start");
  
  Serial.println("range iteration:");
  for(Iterator i : Iterator(0,5)){//iterates from 0 to 4, ( x=0; x<5; x++ )
    int x = i.getIteration();
    Serial.println(x);
  }
  
  Serial.println("multi iteration:");
  for(Iterator i : Iterator(0,5)){//iterates from 0 to 4, ( x=0; x<5; x++ )
    int x = i.getIteration();
    Serial.println(x);
    for(Iterator i2 : Iterator(3,7)){//iterates from 3 to 6, ( y=3; y<7; y++ )
      int y = i2.getIteration();
      Serial.println(y);
      for(Iterator i3 : Iterator(4)){//iterates from 0 to 3, ( z=0; z<4; z++ )
        int z = i3.getIteration();
        Serial.println(z);
      }
    }
  }
  
  Serial.println("previously created iterator iteration:");
  Iterator i(0,15);
  for(Iterator i2 : i){//iterates from 0 to 14, ( x=0; x<15; x++ )
    int x = i.getIteration();
    int y = i2.getIteration();
    Serial.println(x);
    Serial.println(y);
  }
  
  Serial.println("previously created iterator iteration 2:");
  Iterator i3(0,15);
  i3.setIteration(10);
  for(Iterator i4 : i3){//iterates from 10 to 14, ( x=10; x<15; x++ )
    int x = i3.getIteration();
    int y = i4.getIteration();
    Serial.println(x);
    Serial.println(y);
  }
  
  Serial.println("previously created iterator iteration 3:");
  Iterator i4(0,5);
  i4.setIteration(2);
  for(Iterator i5 : i4){//iterates from 10 to 4, ( x=10; x<5; x++ )
    int x = i4.getIteration();
    int y = i5.getIteration();
    i4.setIteration(y+1);
    Serial.println(x);
    Serial.println(y);
  }
  Serial.print("i4.getIteration()");
  Serial.print(" ");
  Serial.println(i4.getIteration());
  i4.refreshIteration();//this returns the counter to 0
  Serial.print("i4.getIteration()");
  Serial.print(" ");
  Serial.println(i4.getIteration());
  
  Serial.println("previously created iterator iteration 4:");
  Iterator i6(0,5);
  i6.setIteration(2);
  for(Iterator i7 : i6){//iterates from 10 to 4, ( x=10; x<5; x++ )
    int x = i6.getIteration();
    int y = i7.getIteration();
    i7.setIteration(x+1);//this wont change the iteration, for the moment theres no way manipulate the iteration while is iterating
    Serial.println(x);
    Serial.println(y);
  }
  Serial.print("i6.getIteration()");
  Serial.print(" ");
  Serial.println(i6.getIteration());
  i6.refreshIteration();
  Serial.print("i6.getIteration()");
  Serial.print(" ");
  Serial.println(i6.getIteration());
  
  Serial.println("///////////////end");
}
