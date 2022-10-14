
#define ame_ArduinoIDE
//#define ame_Windows

#include "System.hpp"
#include "MemoryRam.hpp"

using namespace ame;

void setup() {
	Serial.begin(9600);
}

void loop() {
	long totalRam = getRamSize();
	long freeRam = getFreeRamSize();
	long usedRam = getUsedRamSize();

	System::console.print("Total Ram:");      System::console.println(totalRam);
	System::console.print("Free Ram:");       System::console.println(freeRam);
	System::console.print("Used Ram:");       System::console.println(usedRam);

	long totalHeap = getHeapSize();
	long freeHeap = getFreeHeapSize();
	long usedHeap = getUsedHeapSize();

	System::console.print("Total Heap:");      System::console.println(totalHeap);
	System::console.print("Free Heap:");       System::console.println(freeHeap);
	System::console.print("Used Heap:");       System::console.println(usedHeap);

	long totalStack = getStackSize();
	long freeStack = getFreeStackSize();
	long usedStack = getUsedStackSize();

	System::console.print("Total Stack:");      System::console.println(totalStack);
	System::console.print("Free Stack:");       System::console.println(freeStack);
	System::console.print("Used Stack:");       System::console.println(usedStack);
}







//