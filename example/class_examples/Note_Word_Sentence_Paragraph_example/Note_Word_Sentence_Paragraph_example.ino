
#include "Note.h"

void setup() {
  Serial.begin(9600);  
  Note text(1);
  text += "sentence number 1. sentence number 2.";
  text += enter;
  text += "sentence number 3. sentence number 4.     ";
  Serial.print("text ");Serial.println(text.getNote());
  Serial.print("getWord ");Serial.println(text.getWord(0));
  Serial.print("getSentence ");Serial.println(text.getSentence(0));
  Serial.print("getParagraph ");Serial.println(text.getParagraph(0));

  String p = text.getParagraph(text.getNote(), 0);
  //s = text.fixEmptySpaces(s);not working yet
  //p = text.fixEndLinePoint(p);//not working yet
  Serial.print("getParagraph ");Serial.println(p);
  String s = text.getSentence(p, 0);
  Serial.print("getSentence ");Serial.println(s);
  //s = text.fixEmptySpaces(s);not working yet
  //p = text.fixEndLinePoint(p);//not working yet
  String w = text.getWord(s, 0);
  Serial.print("getWord ");Serial.println(w);
  Serial.println("end");
}

void loop(){}
