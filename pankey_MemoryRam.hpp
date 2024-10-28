/*
*   MemoryRam methods:
*
*   getRamSize
*   getFreeRamSize
*   getUsedRamSize
*
*   getHeapSize
*   getFreeHeapSize
*   getUsedHeapSize
*
*   getStackSize
*   getFreeStackSize
*   getUsedStackSize
*
*/
#include "pankey.hpp"

#ifndef pankey_MemoryRam_hpp
    #define pankey_MemoryRam_hpp

    #if pankey_Enviroment == pankey_Windows_Enviroment
        #include <windows.h>

        #define DIVMEM 1048576

        namespace pankey{
            
            long getRamSize(){
                MEMORYSTATUSEX statex;
                statex.dwLength = sizeof (statex);
                GlobalMemoryStatusEx (&statex);
                return statex.ullTotalPhys/DIVMEM;
            }
            long getFreeRamSize(){
                MEMORYSTATUSEX statex;
                statex.dwLength = sizeof (statex);
                GlobalMemoryStatusEx (&statex);
                return statex.ullAvailPhys/DIVMEM;
            }
            long getUsedRamSize(){
                MEMORYSTATUSEX statex;
                statex.dwLength = sizeof (statex);
                GlobalMemoryStatusEx (&statex);
                return statex.ullTotalPhys/DIVMEM - statex.ullAvailPhys/DIVMEM;
            }

            long getHeapSize(){
                MEMORYSTATUSEX statex;
                statex.dwLength = sizeof (statex);
                GlobalMemoryStatusEx (&statex);
                return 0;
            }
            long getFreeHeapSize(){
                MEMORYSTATUSEX statex;
                statex.dwLength = sizeof (statex);
                GlobalMemoryStatusEx (&statex);
                return 0;
            }
            long getUsedHeapSize(){
                MEMORYSTATUSEX statex;
                statex.dwLength = sizeof (statex);
                GlobalMemoryStatusEx (&statex);
                return 0;
            }

            long getStackSize(){
                MEMORYSTATUSEX statex;
                statex.dwLength = sizeof (statex);
                GlobalMemoryStatusEx (&statex);
                return 0;
            }
            long getFreeStackSize(){
                MEMORYSTATUSEX statex;
                statex.dwLength = sizeof (statex);
                GlobalMemoryStatusEx (&statex);
                return 0;
            }
            long getUsedStackSize(){
                MEMORYSTATUSEX statex;
                statex.dwLength = sizeof (statex);
                GlobalMemoryStatusEx (&statex);
                return 0;
            }
        
        }

    #endif
    
    #if pankey_IDE == pankey_Arduino_IDE
        #if pankey_Generic_Hardware == pankey_Generic_Arduino_Hardware
            #include <Arduino.h>

            #ifdef ARDUINO_ARCH_AVR
            
            #ifdef __cplusplus
            extern "C" {
            #endif

            extern unsigned int __heap_start;
            extern void *__brkval;

            struct __freelist {
                size_t sz;
                struct __freelist *nx;
            };

            extern struct __freelist *__flp;


            long freeListSize() {
                struct __freelist* current;
                long total = 0;
                for (current = __flp; current; current = current->nx) {
                    total += 2;
                    total += (long) current->sz;
                }
                return total;
            }

            long getRamSize();
            long getFreeRamSize();
            long getUsedRamSize();

            long getHeapSize();
            long getFreeHeapSize();
            long getUsedHeapSize();

            long getStackSize();
            long getFreeStackSize();
            long getUsedStackSize();

            #ifdef  __cplusplus
            }
            #endif


            long getRamSize() {
                long free_memory;
                if ((long)__brkval == 0) {
                    free_memory = ((long)&free_memory) - ((long)&__heap_start);
                } else {
                    free_memory = ((long)&free_memory) - ((long)__brkval);
                    free_memory += freeListSize();
                }
                return free_memory;
            }
            long getFreeRamSize(){
                long free_memory;
                if ((long)__brkval == 0) {
                    free_memory = ((long)&free_memory) - ((long)&__heap_start);
                } else {
                    free_memory = ((long)&free_memory) - ((long)__brkval);
                    free_memory += freeListSize();
                }
                return free_memory;
            }
            long getUsedRamSize(){
                long free_memory;
                if ((long)__brkval == 0) {
                    free_memory = ((long)&free_memory) - ((long)&__heap_start);
                } else {
                    free_memory = ((long)&free_memory) - ((long)__brkval);
                    free_memory += freeListSize();
                }
                return free_memory;
            }

            long getHeapSize(){
                long free_memory;
                if ((long)__brkval == 0) {
                    free_memory = ((long)&free_memory) - ((long)&__heap_start);
                } else {
                    free_memory = ((long)&free_memory) - ((long)__brkval);
                    free_memory += freeListSize();
                }
                return free_memory;
            }
            long getFreeHeapSize(){
                long free_memory;
                if ((long)__brkval == 0) {
                    free_memory = ((long)&free_memory) - ((long)&__heap_start);
                } else {
                    free_memory = ((long)&free_memory) - ((long)__brkval);
                    free_memory += freeListSize();
                }
                return free_memory;
            }
            long getUsedHeapSize(){
                long free_memory;
                if ((long)__brkval == 0) {
                    free_memory = ((long)&free_memory) - ((long)&__heap_start);
                } else {
                    free_memory = ((long)&free_memory) - ((long)__brkval);
                    free_memory += freeListSize();
                }
                return free_memory;
            }

            long getStackSize(){
                long free_memory;
                if ((long)__brkval == 0) {
                    free_memory = ((long)&free_memory) - ((long)&__heap_start);
                } else {
                    free_memory = ((long)&free_memory) - ((long)__brkval);
                    free_memory += freeListSize();
                }
                return free_memory;
            }
            long getFreeStackSize(){
                long free_memory;
                if ((long)__brkval == 0) {
                    free_memory = ((long)&free_memory) - ((long)&__heap_start);
                } else {
                    free_memory = ((long)&free_memory) - ((long)__brkval);
                    free_memory += freeListSize();
                }
                return free_memory;
            }
            long getUsedStackSize(){
                long free_memory;
                if ((long)__brkval == 0) {
                    free_memory = ((long)&free_memory) - ((long)&__heap_start);
                } else {
                    free_memory = ((long)&free_memory) - ((long)__brkval);
                    free_memory += freeListSize();
                }
                return free_memory;
            }

            #endif
        #endif
        
        #if pankey_Generic_Hardware == pankey_Generic_Esp8266_Hardware
            #ifdef ARDUINO_ARCH_ESP8266
            extern "C" {
            #include "user_interface.h"
            }

            long getRamSize() {
                return system_get_free_heap_size();
            }
            long getFreeRamSize(){
                return system_get_free_heap_size();
            }
            long getUsedRamSize(){
                return system_get_free_heap_size();
            }

            long getHeapSize(){
                return system_get_free_heap_size();
            }
            long getFreeHeapSize(){
                return system_get_free_heap_size();
            }
            long getUsedHeapSize(){
                return system_get_free_heap_size();
            }

            long getStackSize(){
                return system_get_free_heap_size();
            }
            long getFreeStackSize(){
                return system_get_free_heap_size();
            }
            long getUsedStackSize(){
                return system_get_free_heap_size();
            }

            #endif
        #endif
        #if pankey_Generic_Hardware == pankey_Generic_Esp32_Hardware

            long getRamSize() {
                return esp_get_free_heap_size();
            }
            long getFreeRamSize(){
                return esp_get_free_heap_size();
            }
            long getUsedRamSize(){
                return esp_get_free_heap_size();
            }

            long getHeapSize(){
                return esp_get_free_heap_size();
            }
            long getFreeHeapSize(){
                return esp_get_free_heap_size();
            }
            long getUsedHeapSize(){
                return esp_get_free_heap_size();
            }

            long getStackSize(){
                return esp_get_free_heap_size();
            }
            long getFreeStackSize(){
                return esp_get_free_heap_size();
            }
            long getUsedStackSize(){
                return esp_get_free_heap_size();
            }

        #endif
        #if pankey_Generic_Hardware == pankey_Generic_Adafruit_Feather_Hardware

            extern "C" char *sbrk(int i);

            long getRamSize() {
                char stack_dummy = 0;
                return &stack_dummy - sbrk(0);
            }
            long getFreeRamSize(){
                char stack_dummy = 0;
                return &stack_dummy - sbrk(0);
            }
            long getUsedRamSize(){
                char stack_dummy = 0;
                return &stack_dummy - sbrk(0);
            }

            long getHeapSize(){
                char stack_dummy = 0;
                return &stack_dummy - sbrk(0);
            }
            long getFreeHeapSize(){
                char stack_dummy = 0;
                return &stack_dummy - sbrk(0);
            }
            long getUsedHeapSize(){
                char stack_dummy = 0;
                return &stack_dummy - sbrk(0);
            }

            long getStackSize(){
                char stack_dummy = 0;
                return &stack_dummy - sbrk(0);
            }
            long getFreeStackSize(){
                char stack_dummy = 0;
                return &stack_dummy - sbrk(0);
            }
            long getUsedStackSize(){
                char stack_dummy = 0;
                return &stack_dummy - sbrk(0);
            }

        #endif
    #endif

#endif
