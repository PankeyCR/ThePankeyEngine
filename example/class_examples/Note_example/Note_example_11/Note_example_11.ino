
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  int i_size_1 = Note::intCharSize(1);
  Serial.print("1 size: ");Serial.println(i_size_1);
  char* c_value_1 = new char[i_size_1+1];
  Note::intToCharPointer(1, i_size_1, 0, c_value_1, true);
  Serial.print("value: ");Serial.println(c_value_1);
  delete[] c_value_1;

  int i_size_2 = Note::intCharSize(12);
  Serial.print("12 size: ");Serial.println(i_size_2);
  char* c_value_2 = new char[i_size_2+1];
  Note::intToCharPointer(12, i_size_2, 0, c_value_2, true);
  Serial.print("value: ");Serial.println(c_value_2);
  delete[] c_value_2;

  int i_size_3 = Note::intCharSize(-123);
  Serial.print("-123 size: ");Serial.println(i_size_3);
  char* c_value_3 = new char[i_size_3+1];
  Note::intToCharPointer(-123, i_size_3, 0, c_value_3, true);
  Serial.print("value: ");Serial.println(c_value_3);
  delete[] c_value_3;

  int i_size_4 = Note::intCharSize(-1234);
  Serial.print("-1234 size: ");Serial.println(i_size_4);
  char* c_value_4 = new char[i_size_4+1];
  Note::intToCharPointer(-1234, i_size_4, 0, c_value_4, true);
  Serial.print("value: ");Serial.println(c_value_4);
  delete[] c_value_4;

  int i_size_5 = Note::intCharSize(9603706);
  Serial.print("9603706 size: ");Serial.println(i_size_5);
  char* c_value_5 = new char[i_size_5+1];
  Note::intToCharPointer(9603706, i_size_5, 0, c_value_5, true);
  Serial.print("value: ");Serial.println(c_value_5);
  delete[] c_value_5;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
