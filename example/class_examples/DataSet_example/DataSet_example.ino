
#include "DataSet.h"
#include "NetSet.h"
#include "NetV3Set.h"

DataSet<float>* data;
void setup() {
  Serial.begin(9600);
  data = new NetV3Set<1,2,3>();
  
  float xx=0;
  
  iterate(data){
    xx+=0.2358;
    data->set(xx);
  }
  
  iterate(data){
    Serial.print("toString ");Serial.println(data->toString());
  }
  
  DataSet<float>* copyData = data->clone();

  Serial.println(data->equal(copyData));
  iterate(data){
    if(copyData->getValue() != data->getValue()){
//      Serial.print("toString data ");Serial.println(data->toString());
//      Serial.print("toString copyData ");Serial.println(copyData->toString());
      Serial.println("not equal");
    }else{
//      Serial.print("toString data ");Serial.println(data->toString());
//      Serial.print("toString copyData ");Serial.println(copyData->toString());
      Serial.println("equal");
    }
    copyData->next();
  }
  delete data;
  delete copyData;
  Serial.println("end");
  
}

void loop() {


}
