
#include "Note.h"

void setup() {
  Serial.begin(9600);
  
  Note note = "hiii pope";
  Serial.println(note);
  note = "bye pope";
  char c = note.toChar(5);
  Serial.print("char: ");Serial.println(c);
  Serial.print("Note: ");Serial.println(note);
  Serial.println();
  
  Note note2 = 457;
  Serial.print("toInt: ");Serial.println(note2.toInt());
  Serial.print("Note: ");Serial.println(note2);
  note2 = 753;
  Serial.print("Note: ");Serial.println(note2);
  Serial.println();
  
  Note note3 = 'p';
  Serial.print("Note: ");Serial.println(note3);
  note3 = 't';
  Serial.print("toChar: ");Serial.println(note3.toChar());
  Serial.print("Note: ");Serial.println(note3);
  
  Note note4 = 524523625l;
  Serial.print("toLong: ");Serial.println(note4.toLong());
  Serial.print("Note: ");Serial.println(note4);
  note4 = 9998869l;
  Serial.print("toLong: ");Serial.println(note4.toLong());
  Serial.print("Note: ");Serial.println(note4);
}

void loop() {
}
