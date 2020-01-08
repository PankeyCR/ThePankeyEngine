
#include "Funtion.h"
#include "DefaultNeuron.h"
#include "CuadraticFuntion.h"
#include "RandomFuntion.h"
#include "DataSet.h"
#include "NetV3Set.h"
#include "MemoryFree.h"

DataSet<float>* data;//1132
DefaultNeuron* firstNeuron;
Funtion<float>* fr;
Funtion<float>* fx;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  startmemory = freeMemory();
  fx = new CuadraticFuntion<float>();
  fr = new RandomFuntion<float>(54524);  
  firstNeuron = new DefaultNeuron(); 
  firstNeuron->setFuntion(fx);

  Neuron<float> *n = firstNeuron->
                              connect(firstNeuron->clone())->
                              connect(firstNeuron->clone())->
                              connect(firstNeuron->clone());
  Neuron<float> *fn = n->
                              connect(firstNeuron->clone())->
                              connect(firstNeuron->clone())->
                              connect(firstNeuron->clone());
  Neuron<float> *nn = fn->
                              connect(firstNeuron->clone())->
                              connect(firstNeuron->clone())->
                              connect(firstNeuron->clone());
  
  data = new NetV3Set<1,2,3>();
  
  float xx=0;
  
  iterate(data){
    xx+=0.2358;
    data->set(xx);
  }
  DataSet<float>* responce = firstNeuron->compute(data->clone());
  instancememory = freeMemory();

  Serial.println(data->toString());
  Serial.println(responce->toString());
  data->next();
  responce->next();
  Serial.println(data->toString());
  Serial.println(responce->toString());
   
  delete fx;
  delete fr;
  delete firstNeuron;
  delete data;
  delete responce;

  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {

}
