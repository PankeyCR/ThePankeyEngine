#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "MemoryRam.h"

#ifdef ARDUINO_ARCH_AVR

extern unsigned int __heap_start;
extern void *__brkval;

/*
 * The free list structure as maintained by the 
 * avr-libc memory allocation routines.
 */
struct __freelist {
  size_t sz;
  struct __freelist *nx;
};

/* The head of the free list structure */
extern struct __freelist *__flp;


/* Calculates the size of the free list */
long freeListSize() {
  struct __freelist* current;
  long total = 0;
  for (current = __flp; current; current = current->nx) {
    total += 2; /* Add two bytes for the memory block's header  */
    total += (long) current->sz;
  }
  return total;
}

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

#endif

#ifdef ARDUINO_ARCH_ESP8266
extern "C" {
#include "user_interface.h"
}

long getRamSize() {
	return system_get_free_heap_size();
}

#endif

#ifdef ARDUINO_SAMD_ZERO
extern "C" char *sbrk(int i);
 
long getRamSize() {
  char stack_dummy = 0;
  return &stack_dummy - sbrk(0);
}

#endif

#ifdef ARDUINO_ARCH_ESP32

long getRamSize() {
	return esp_get_free_heap_size();
}

#endif