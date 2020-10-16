
#include "Note.h"

void setup() {
  Serial.begin(9600); 
  Note text = "Sentence number 1.";
  text < "Sentence number 2.";// the operator < adds a new sentence to the note
  text < "Sentence number 3.";
  text < "Sentence number 4.";
  text << "Sentence number 5.";// the operator << adds a new paragraph to the note
  text < "Sentence number 6.";
  text << "Sentence number 7.";
  Serial.println("text: ");Serial.println(text);
  Serial.print("getWord(0); ");Serial.println(text.getWord(0));
  Serial.print("getSentence(0); ");Serial.println(text.getSentence(0));
  Serial.print("getSentence(1); ");Serial.println(text.getSentence(1));
  Serial.print("getParagraph(0); ");Serial.println(text.getParagraph(0));
  Serial.print("getParagraph(2); ");Serial.println(text.getParagraph(2));
  Serial.print("getParagraph(1); ");Serial.println(text.getParagraph(1));
}

void loop(){}
