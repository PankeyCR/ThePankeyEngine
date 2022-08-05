
#if defined(DISABLE_ame_debug)
	#define ame_debug_hpp
#endif

#ifndef ame_debug_hpp
#define ame_debug_hpp
#define ame_debug_AVAILABLE

//////////////////////////////////////////////////////////////

#include "ame_Logger_config.hpp"
#include "MemoryRam.hpp"
#include "ame_String.hpp"

long ram_size = -1;

void debug(void* pointer, int location, ame_String name, ame_String method, ame_String type){
	// Serial.println("Name");
	// Serial.println(name);
	// Serial.println("Method");
	// Serial.println(method);
	// Serial.println("Type");
	// Serial.println(type);
	if(location == ame_Log_StartLoop){
		long n_ram_size = getRamSize();
		// long n_ram_size = 0;
		if(ram_size == -1){
			ram_size = n_ram_size;
		}
		if(n_ram_size < ram_size){
			// Serial.println("WARNING");
			
			Serial.print("WARNING, memory is dropping: ");
			Serial.println(ram_size - n_ram_size);
			ram_size = n_ram_size;
			Serial.print("ram size: ");
			Serial.println(ram_size);
			
		}
		// ram_size = n_ram_size;
		// Serial.print("ram size: ");
		// Serial.println(ram_size);
	}
	// if(method == "Constructor" && location == ame_Log_StartMethod){
		// Serial.println("new instance");
	// }
	// Serial.println("debugging");
}

//////////////////////////////////////////////////////////////

#endif
