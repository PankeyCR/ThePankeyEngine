
#include "Funtion.h"
#include "DefaultNeuron.h"
#include "CuadraticFuntion.h"
#include "DataSet.h"
#include "NetV3Set.h"

DataSet<float>* data;//396
DefaultNeuron* firstNeuron;
Funtion<float,float>* fx;

void setup() {
  Serial.begin(9600);
  fx = new CuadraticFuntion<float>();  
  firstNeuron = new DefaultNeuron();
  firstNeuron->setFuntion(fx);

  firstNeuron->connect(firstNeuron->clone());
  
  data = new NetV3Set<1,2,3>();
  
  float xx=0;
  
  iterate(data){
    xx+=0.2358;
    data->set(xx);
  }
  DataSet<float>* responce = firstNeuron->compute(data->clone());

  Serial.println(data->toString());
  Serial.println(responce->toString());
  data->next();
  responce->next();
  Serial.println(data->toString());
  Serial.println(responce->toString());
  
}

void loop() {

}
