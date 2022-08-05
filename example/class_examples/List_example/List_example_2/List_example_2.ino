
#include "List.hpp"
#include "PList.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveRawList.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  //when your adding stuff to any of this lists, they will work the same,
  //but with different mechanisms inside
//  ArrayList<Note,5> list;
//  PList<Note,5> list(true);//if you dont set true the contructors parameter, it wont manage the memory and have memory leak
  PrimitiveList<Note> list;
//  PrimitiveRawList<int> list;
//  LinkedList<Note> list;
  
  list[0] = 1;
  list[1] = 11;
  list[2] = 111;
  list[3] = 1111;
  list[4] = 11111;

  
  if(list.containByLValue("1111")){
    Serial.println("contain 1111");
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}