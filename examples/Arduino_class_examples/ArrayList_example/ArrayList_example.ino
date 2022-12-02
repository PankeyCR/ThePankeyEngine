
#include "ArrayList.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.println("//////////////////////////start");
  ArrayList<String,10> testList;

  testList.add("names");
  testList.add("node");
  testList.add("pankey");
  testList.add("test");
  testList.add("monkey");
  
  Serial.print("Total Size Available:  ");Serial.println(testList.getSize());
  Serial.print("Total Size Used:  ");Serial.println(testList.getPosition());

  for(String& i : testList){
    Serial.print("Actual Object:  ");Serial.println(i);
    if(i == "test"){
      i = "newtest";
    }
  }

  testList.remove("monkey");

  Serial.print("Total Size Available:  ");Serial.println(testList.getSize());
  Serial.print("Total Size Used:  ");Serial.println(testList.getPosition());
  
  for(String& i : testList){
    Serial.print("Actual Object:  ");Serial.println(i);
  }
  Serial.println("//////////////////////////end");
}