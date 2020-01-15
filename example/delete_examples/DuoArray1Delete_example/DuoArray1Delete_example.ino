
#include "DataSet.h"
#include "DuoArray1.h"
#include "MemoryFree.h"

DuoArray1<3,7>* data;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  data = new DuoArray1<3,7>();
  instancememory = freeMemory();

  float arr1[] = {0,1,2,1,3,4,5};
  float arr2[] = {2,5,3};

  data->setArray1(arr1);
  data->setArray2(arr2);
  
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
