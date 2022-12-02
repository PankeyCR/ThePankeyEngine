
#include "CommandReader.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////////////////////////////// start");
  CommandReader cmd;
  cmd.setText("DataBase.delete#1$DataBase.path#memory.txt");
  
  int x_1 = cmd.getCommandOrder("DataBase.delete");
  if(x_1 == -1){
    Serial.println("x_1 == -1");
  }
  Note arg = cmd.getArgument(x_1);
  Serial.print("arg ");Serial.println(arg);
  
  int x_2 = cmd.getCommandOrder("DataBase.path");
  if(x_2 == -1){
    Serial.println("x_2 == -1");
  }
  Note arg_2 = cmd.getArgument(x_2);
  Serial.print("arg_2 ");Serial.println(arg_2);
  Serial.println("////////////////////////////////////// end");
}

