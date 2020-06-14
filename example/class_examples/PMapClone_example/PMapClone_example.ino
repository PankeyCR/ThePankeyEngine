
#include "PMap.h"
#include "Map.h"

Map<int,String> *testMap;

void setup() {
  Serial.begin(9600);
  testMap = new PMap<int,String,10>();

  testMap->add(new int(85),new String("names"));
  testMap->add(new int(24),new String("node"));
  testMap->add(new int(57),new String("pankey"));
  testMap->add(new int(7),new String("test"));
  testMap->add(new int(0),new String("monkey"));
  
  iterate(testMap){
    Serial.print(testMap->getKey());
    Serial.print(" ");
    Serial.println(testMap->getValue());
  }
  
  Map<int,String>* cloneMap = testMap->clone();
  delete testMap;//testMap can be deleted because PMap doesnt have ownership of the data stored on the map
                 //and the data will be transfer to the new map
  iterate(cloneMap){
    Serial.print(cloneMap->getKey());
    Serial.print(" ");
    Serial.println(cloneMap->getValue());
  }

  cloneMap->onDelete();//but remember that PMap doesnt have ownership over the data stored, 
                        //and if you whant to delete the pointers, you have to call onDelete method
}

void loop() {}
