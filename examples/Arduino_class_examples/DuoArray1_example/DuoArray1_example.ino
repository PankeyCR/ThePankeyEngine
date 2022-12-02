
#include "DataSet.h"
#include "DuoArray1.h"

DuoArray1<float,2,7>* data;

void setup() {
  Serial.begin(9600);
  data = new DuoArray1<float,2,7>();
  {
  float arr1[] = {0,1,2,1,3,4,5};
  float arr2[] = {0,1};
  data->setArray1(arr1);
  data->setArray2(arr2);
  }
  Serial.println("iterate space 0");
  for(Iterator i : data->iterateSpace(0)){
    Serial.print("toString ");Serial.println(data->toString());
    //data->getValue();
  }
  
  Serial.println("full iterate");
  for(Iterator i : data){
    Serial.print("toString ");Serial.println(data->toString());
  }
  Serial.println("iterate space 1");
  for(Iterator i : data->iterateSpace(1)){
    Serial.print("toString ");Serial.println(data->toString());
  }
  
}

void loop() {
}