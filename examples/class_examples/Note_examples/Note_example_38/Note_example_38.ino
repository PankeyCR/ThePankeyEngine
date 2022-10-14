
#define DISABLE_Note

#include "Note.hpp"
#include "MemoryRam.h"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(getRamSize());

  Note note = "192.168.5.90";
  Serial.println(toIPAddress(note));

  Serial.println("////////////end");
  Serial.println(getRamSize());
}
