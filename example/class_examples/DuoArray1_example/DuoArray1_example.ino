
#include "DataSet.h"
#include "DuoArray1.h"

DuoArray1<2,7>* data;

void setup() {
  Serial.begin(9600);
  data = new DuoArray1<2,7>();

  float arr1[] = {0,1,2,1,3,4,5};
  float arr2[] = {0,1};
  data->setArray1(arr1);
  data->setArray2(arr2);
  
  iterate(data->iterateDimention(0)){
    Serial.print("toString ");Serial.println(data->toString());
  }
  
  iterate(data){
    Serial.print("toString ");Serial.println(data->toString());
  }
  Serial.println("start dim 1 ");
  iterate(data->iterateDimention(1)){
    Serial.print("toString ");Serial.println(data->toString());
  }
  
}

void loop() {


}
