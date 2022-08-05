
#include "MemoryRam.hpp"
#include "System.hpp"

using namespace ame;

void setup() {
    Serial.begin(9600);
    
    long totalRam = getRamSize();
    long freeRam = getFreeRamSize();
    long usedRam = getUsedRamSize();

    System::print("Total Ram:");      System::println(totalRam);
    System::print("Free Ram:");       System::println(freeRam);
    System::print("Used Ram:");       System::println(usedRam);

    long totalHeap = getHeapSize();
    long freeHeap = getFreeHeapSize();
    long usedHeap = getUsedHeapSize();

    System::print("Total Heap:");      System::println(totalHeap);
    System::print("Free Heap:");       System::println(freeHeap);
    System::print("Used Heap:");       System::println(usedHeap);

    long totalStack = getStackSize();
    long freeStack = getFreeStackSize();
    long usedStack = getUsedStackSize();

    System::print("Total Heap:");      System::println(totalStack);
    System::print("Free Heap:");       System::println(freeStack);
    System::print("Used Heap:");       System::println(usedStack);


}

void loop() {
  // put your main code here, to run repeatedly:

}
