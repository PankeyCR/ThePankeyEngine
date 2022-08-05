
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  int i_size_1 = Note::floatCharSize(1.9876f, 4);
  Serial.print("1.9876 size: ");Serial.println(i_size_1);

  int i_size_2 = Note::floatCharSize(12.9876f, 4);
  Serial.print("12.9876 size: ");Serial.println(i_size_2);

  int i_size_3 = Note::floatCharSize(123.9876f, 4);
  Serial.print("123.9876 size: ");Serial.println(i_size_3);

  int i_size_4 = Note::floatCharSize(1234.9876f, 4);
  Serial.print("1234.9876 size: ");Serial.println(i_size_4);

  int i_size_5 = Note::floatCharSize(12345.9876f, 4);
  Serial.print("12345.9876 size: ");Serial.println(i_size_5);

  int i_size_6 = Note::floatCharSize(-12345.9876f, 4);
  Serial.print("-12345.9876 size: ");Serial.println(i_size_6);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 
