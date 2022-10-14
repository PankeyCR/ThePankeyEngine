
#define ame_LogApp
#define ame_LogPrint
#define ame_Arduino_Log

//#define Note_LogApp
#define DISABLE_Note
#define DISABLE_MemoryPool

#include "Note.hpp"
#include "MemoryRam.h"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(5000);
  Serial.println("////////////start");
  Serial.println(getRamSize());

  Note note = "TRUE";
  Serial.println(toBool(note));
  note = "True";
  Serial.println(toBool(note));
  note = "true";
  Serial.println(toBool(note));
  note = "1";
  Serial.println(toBool(note));
  note = "FALSE";
  Serial.println(toBool(note));
  note = "False";
  Serial.println(toBool(note));
  note = "false";
  Serial.println(toBool(note));
  note = "0";
  Serial.println(toBool(note));

  Serial.println("////////////end");
  Serial.println(getRamSize());
}
