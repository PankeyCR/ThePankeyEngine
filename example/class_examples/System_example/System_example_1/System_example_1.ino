
#define ame_ArduinoIDE
//#define ame_Windows

#include "System.hpp"
#include "MemoryRam.hpp"

//System::console is the same as Serial

using namespace ame;

void setup() {
	Serial.begin(9600);
}

void loop() {
	System::console.println("Hellow World");
	System::console.println('g');
	System::console.println(159);
	System::console.println(15954353l);
	System::console.println(159.05f);
}







//