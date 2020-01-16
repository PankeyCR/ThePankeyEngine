
#include "Funtion.h"
#include "Neuron.h"
#include "PNeuron.h"
#include "PList.h"
#include "CuadraticFuntion.h"
#include "DataSet.h"
#include "NetV3Set.h"
#include "MemoryFree.h"

DataSet<float>* data;
PNeuron<9>* firstNeuron;
Funtion<float,float>* fx;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  data = new NetV3Set<4,2,4>();
  fx = new CuadraticFuntion<float>();
  firstNeuron = new PNeuron<9>();
  firstNeuron->setFuntion(fx);

  Neuron<float> *n0=firstNeuron->connect(firstNeuron->clone());
  Neuron<float> *n1=firstNeuron->connect(firstNeuron->clone());
  Neuron<float> *p0=n0->connect(firstNeuron->clone());
  Neuron<float> *p1=n0->connect(firstNeuron->clone());
  
  instancememory = freeMemory();

  float x=0.2f;
  bool increment=true;
  
  iterate(data){
    data->set(x);
    if(x>14.0f){
      increment=true;
    }
    if(x<0.0f){
      increment=false;
    }
    if(increment){
      x = x - 0.18f;
    }else{
      x = x + 0.58f;
    }
  }
  
  DataSet<float>* responce = firstNeuron->compute(data->clone());

  iterate(responce){
    Serial.print("responce ");Serial.println(responce->getValue());
    Serial.print("data     ");Serial.println(data->getValue());
    data->next();
  }


  delete n0;
  delete n1;
  delete p0;
  delete p1;
  delete firstNeuron;
  delete responce;
  delete data;
  delete fx;

  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {

}
