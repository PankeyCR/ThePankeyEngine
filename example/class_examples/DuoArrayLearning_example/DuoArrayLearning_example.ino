
//#define Log 
//#define LogSerial 

#include "Funtion.h"
#include "Neuron.h"
#include "PNeuron.h"
#include "XtremeFuntion1.h"
#include "DataSet.h"
#include "DuoArray1.h"
#include "Logger.h"
#include "MinimalError.h"

DuoArray1<2,7>* data;
PNeuron<2>* firstNeuron;
Funtion<float,float>* fx;


void setup() {
  Serial.begin(9600);
  LogSerial(&Serial);
  data = new DuoArray1<2,7>();

  float inputData[] = {0,1,2,3,4,5,6};
  float learningData[] = {12,21};
  
  data->setArray1(inputData);
  data->setArray2(learningData);
  
  MinimalError* fconf = new MinimalError(&Serial);
  
  fx = fconf->epochs(1000)
            ->dataset(data)
            ->minimalerror(0.1f)
            ->random(10,0,526)
            ->input(0)
            ->output(1)
            ->build();
            
  Serial.print("minimal error found ");Serial.println(fconf->error());
  delete fconf;
  
  firstNeuron = new PNeuron<2>();
  firstNeuron->setFuntion(fx); 
  
  DataSet<float>* responce = firstNeuron->compute(data->clone());

  iterate(responce){
    Serial.print("responce ");Serial.println(responce->getValue());
    Serial.print("data     ");Serial.println(data->getValue());
    data->next();
  }

  float inputData2[] = {0,1.5f,2,3,3.8f,5,7};
  
  data->setArray1(inputData2);
  
  DataSet<float>* responce2 = firstNeuron->compute(data->clone());

  iterate(responce2){
    Serial.print("responce ");Serial.println(responce2->getValue());
    Serial.print("data     ");Serial.println(data->getValue());
    data->next();
  }
}

void loop() {

}
