#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "MemoryFree.h"

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
int freeListSize() {
  struct __freelist* current;
  int total = 0;
  for (current = __flp; current; current = current->nx) {
    total += 2; /* Add two bytes for the memory block's header  */
    total += (int) current->sz;
  }
  return total;
}

int freeMemory() {
  int free_memory;
  if ((int)__brkval == 0) {
    free_memory = ((int)&free_memory) - ((int)&__heap_start);
  } else {
    free_memory = ((int)&free_memory) - ((int)__brkval);
    free_memory += freeListSize();
  }
  return free_memory;
}

#endif

#ifdef ARDUINO_ARCH_ESP8266
extern "C" {
#include "user_interface.h"
}

int freeMemory() {
	return system_get_free_heap_size();
}

#endif

#ifdef ARDUINO_SAMD_ZERO
extern "C" char *sbrk(int i);
 
int freeMemory() {
  char stack_dummy = 0;
  return &stack_dummy - sbrk(0);
}

#endif