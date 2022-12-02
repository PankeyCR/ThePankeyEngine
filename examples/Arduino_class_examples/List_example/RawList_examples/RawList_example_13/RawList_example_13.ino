
#include "ame_Enviroment.hpp"

#include "RawList.hpp"
#include "PrimitiveRawList.hpp"
#include "LinkedRawList.hpp"

using namespace ame;

class Example{
  public:
  int value = 0;
  Example(){}
  Example(int example){value = example;}
  Example(const Example& example){value = example.value;}
  void operator=(const Example& example){value = example.value;}
  bool operator==(const Example& example){return value == example.value;}
  bool operator!=(const Example& example){return value != example.value;}
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  PrimitiveRawList<Example> list;
  //LinkedRawList<Example> list;
  
  list.addWithParameters(159);
  
  for(Example number : list){
    Serial.println(number.value);
  }
  
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}