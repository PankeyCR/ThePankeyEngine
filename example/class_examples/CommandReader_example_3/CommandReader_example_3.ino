
#include "CommandReader.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////////////////////////////// start");
  CommandReader cmd;
  cmd.setText("DataBase.delete 1\nDataBase.path memory.txt\nDataBase.dir monkey\n");
  
  Serial.print("text: ");Serial.println(cmd.getText());

  cmd.writeLine(0, "DataBase.command put");
  
  Serial.print("text: ");Serial.println(cmd.getText());

  cmd.writeLine(1, "DataBase.type object");
  
  Serial.print("text: ");Serial.println(cmd.getText());

  cmd.writeLine("DataBase.type", "DataBase.type file");
  
  Serial.print("text: ");Serial.println(cmd.getText());

  cmd.removeLine("DataBase.command");
  
  Serial.print("text: ");Serial.println(cmd.getText());

  cmd.removeLine("DataBase.type");
  
  Serial.print("text: ");Serial.println(cmd.getText());
  
  Serial.println("////////////////////////////////////// end");
}
