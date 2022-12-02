
#define LogApp

#include "Logger.h"
#include "DefaultLogging.h"
#include "MinimalError.h"
#include "Function.h"
#include "Neuron.h"
#include "DuoArray1Neuron.h"
#include "XtremeFunction1.h"
#include "DataSet.h"
#include "DuoArray1.h"

DuoArray1<float, 7, 2>* data;
DuoArray1Neuron* firstNeuron;
Function<float,float>* fx;


void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("MinimalError");
  data = new DuoArray1<float, 7, 2>();

  float inputData[] = {0, 1, 2, 3, 4, 5, 6};
  float learningData[] = {12, 21};

  data->setArray1(inputData);
  data->setArray2(learningData);

  MinimalError* fconf = new MinimalError();

  fx = fconf->epochs(1000)
       ->dataset(data)
       ->minimalerror(0.1f)
       ->random(10, 0, 526)
       ->input(0)
       ->output(1)
       ->build();

  Serial.print("minimal error found "); Serial.println(fconf->error());
  delete fconf;

  firstNeuron = new DuoArray1Neuron();
  firstNeuron->setFunction(fx);

  DataSet<float>* responce = firstNeuron->compute(data->clone());

  iterate(responce->iterateSpace(0)) {
    Serial.print("responce: "); Serial.println(responce->getValue());
  }

  float inputData2[] = {0, 1.5f, 2, 3, 3.8f, 5, 7};

  data->setArray1(inputData2);

  DataSet<float>* responce2 = firstNeuron->compute(data->clone());

  iterate(responce2->iterateSpace(0)) {
    Serial.print("responce2: "); Serial.println(responce2->getValue());
  }
}

void loop() {

}