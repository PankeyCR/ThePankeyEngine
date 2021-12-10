// MemoryFree library based on code posted here:
// https://forum.arduino.cc/index.php?topic=27536.msg204024#msg204024
// Extended by Matthew Murdoch to include walking of the free list.

#ifndef MemoryRam_H
#define MemoryRam_H


#ifdef __cplusplus
extern "C" {
#endif

long getRamSize();

#ifdef  __cplusplus
}
#endif

#endif