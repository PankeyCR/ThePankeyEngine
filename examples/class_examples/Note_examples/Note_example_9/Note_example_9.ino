
#include "Note.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Note note;
  int i_size_1 = note.intCharSize(1);
  Serial.print("1 size: ");Serial.println(i_size_1);

  int i_size_2 = note.intCharSize(12);
  Serial.print("12 size: ");Serial.println(i_size_2);

  int i_size_3 = note.intCharSize(123);
  Serial.print("123 size: ");Serial.println(i_size_3);

  int i_size_4 = note.intCharSize(1234);
  Serial.print("1234 size: ");Serial.println(i_size_4);

  int i_size_5 = note.intCharSize(12345);
  Serial.print("12345 size: ");Serial.println(i_size_5);

  int i_size_6 = note.intCharSize(-12345);
  Serial.print("-12345 size: ");Serial.println(i_size_6);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



 