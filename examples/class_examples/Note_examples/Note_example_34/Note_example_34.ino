
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note = "DataBase.command put";
  note.addLine();
  note.addLocalCharPointer("DataBase.type object");
  note.addLine();
  note.addLocalCharPointer("DataBase.id bomb");
  note.addLine();
  note.addLocalCharPointer("DataBase.path monkey.txt");
  note.addLine();

  Serial.println("full text");
  Serial.println(note);
  
  int id = note.getOrder("DataBase.id", ' ', '\n');

  Serial.println("DataBase.id position: ");
  Serial.println(id);
  
  int path = note.getOrder("DataBase.path", ' ', '\n');

  Serial.println("DataBase.path position: ");
  Serial.println(path);
  
  int type = note.getOrder("DataBase.type", ' ', '\n');

  Serial.println("DataBase.type position: ");
  Serial.println(type);
  
  int command = note.getOrder("DataBase.command", ' ', '\n');

  Serial.println("DataBase.command position: ");
  Serial.println(command);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 