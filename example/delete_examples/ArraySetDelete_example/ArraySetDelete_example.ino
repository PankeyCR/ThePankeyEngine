
#include "DataSet.h"
#include "ArraySet.h"
#include "MemoryFree.h"

ArraySet<7>* data;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  data = new ArraySet<7>();
  instancememory = freeMemory();

  float arr[] = {0,1,2,1,3,4,5};

  data->setArray(arr);
  
  iterate(data){
    Serial.print("toString ");Serial.println(data->toString());
  }
  
  delete data;
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);  
}

void loop() {


}
