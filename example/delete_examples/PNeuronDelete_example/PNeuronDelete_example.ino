
#include "Funtion.h"
#include "Neuron.h"
#include "PNeuron.h"
#include "PList.h"
#include "CuadraticFuntion.h"
#include "RandomFuntion.h"
#include "DataSet.h"
#include "NetV3Set.h"
#include "MemoryFree.h"

DataSet<float>* data;//1132
PNeuron<9>* firstNeuron;
Funtion<float>* fr;
Funtion<float>* fx;
PList<Neuron<float>,9>* list;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  fx = new CuadraticFuntion<float>();
  fr = new RandomFuntion<float>(54524); 
  firstNeuron = new PNeuron<9>();
  list = new PList<Neuron<float>,9>();
  firstNeuron->setFuntion(fx);

  list->add(firstNeuron->clone());
  list->add(firstNeuron->clone());
  list->add(firstNeuron->clone());
  list->add(firstNeuron->clone());
  list->add(firstNeuron->clone());
  list->add(firstNeuron->clone());
  list->add(firstNeuron->clone());
  list->add(firstNeuron->clone());
  list->add(firstNeuron->clone());

  iterate(list){
    firstNeuron->connect(list->getPointer());
  }
    
  data = new NetV3Set<1,2,3>();
  
  float xx=0;
  
  iterate(data){
    xx+=0.2358;
    data->set(xx);
  }
  
  DataSet<float>* responce = firstNeuron->compute(data->clone());
  instancememory = freeMemory();
   
  delete fx;
  delete fr;
  list->onDelete();
  delete list;
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
