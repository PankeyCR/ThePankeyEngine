
#include "DataSet.h"
#include "NetSet.h"
#include "NetV3Set.h"
#include "NetV4Set.h"
#include "MemoryFree.h"

DataSet<float>* data;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  //data = new NetV3Set<5,7,13>();//2000 left 5242
  //data = new NetV4Set<3,7,13,2>();//2638 left 4604
  //data = new NetV4Set<5,7,9,2>();//3962 left 3280
  //data = new NetV4Set<20,7,2,2>();//4022 left 3220
  //data = new NetV4Set<4,3,10,3>();//2006 left 5236
  //data = new NetV4Set<1,1,1,1>();//38 left 7204
  //data = new NetV3Set<1,1,1>();//32 left 7210
  //data = new NetV4Set<10,3,3,10>();//4142 left 3100
  //data = new NetV4Set<10,3,3,5>();//2342 left 4900
  //data = new NetV4Set<2,5,3,10>();//1390 left 5852
  //data = new NetV4Set<1,5,3,100>();//6106 left 1136
  data = new NetV4Set<1,5,3,20>();//1306 left 5936

  Serial.println(data->getClassName());
    
  instancememory = freeMemory();
  int sizeData = data->getIterationSize();
  int readData = 0;

  delete data;
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  Serial.print("read ");Serial.println(sizeData);
  Serial.print("size ");Serial.println(readData);
  
}

void loop() {


}
