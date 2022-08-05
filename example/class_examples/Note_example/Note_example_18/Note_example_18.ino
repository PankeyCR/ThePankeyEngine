
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  int i_size_1 = Note::longCharSize(1l);
  Serial.print("1 size: ");Serial.println(i_size_1);
  char* c_value_1 = new char[i_size_1+1];
  Note::longToCharPointer(1l, i_size_1, 0, c_value_1, true);
  Serial.print("value: ");Serial.println(c_value_1);
  delete[] c_value_1;

  int i_size_2 = Note::longCharSize(12l);
  Serial.print("12 size: ");Serial.println(i_size_2);
  char* c_value_2 = new char[i_size_2+1];
  Note::longToCharPointer(12l, i_size_2, 0, c_value_2, true);
  Serial.print("value: ");Serial.println(c_value_2);
  delete[] c_value_2;

  int i_size_3 = Note::longCharSize(-123l);
  Serial.print("-123 size: ");Serial.println(i_size_3);
  char* c_value_3 = new char[i_size_3+1];
  Note::longToCharPointer(-123l, i_size_3, 0, c_value_3, true);
  Serial.print("value: ");Serial.println(c_value_3);
  delete[] c_value_3;

  int i_size_4 = Note::longCharSize(-1234543453l);
  Serial.print("-1234543453 size: ");Serial.println(i_size_4);
  char* c_value_4 = new char[i_size_4+1];
  Note::longToCharPointer(-1234543453l, i_size_4, 0, c_value_4, true);
  Serial.print("value: ");Serial.println(c_value_4);
  delete[] c_value_4;

  int i_size_5 = Note::longCharSize(960334544l);
  Serial.print("960334544l size: ");Serial.println(i_size_5);
  char* c_value_5 = new char[i_size_5+1];
  Note::longToCharPointer(960334544l, i_size_5, 0, c_value_5, true);
  Serial.print("value: ");Serial.println(c_value_5);
  delete[] c_value_5;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
