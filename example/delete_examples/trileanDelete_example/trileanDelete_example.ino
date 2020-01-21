
#include "trilean.h"
#include "MemoryFree.h"

trilean* state;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  state = new trilean();
  instancememory = freeMemory();

//  *state=true;
  *state=false;
//  *state="unknown";
  Serial.println(*state==true);
//  Serial.println(*state==false);
//  Serial.println(*state==unknown);
  
  delete state;

  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {


}
