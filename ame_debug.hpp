
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
#include "System.hpp"

using namespace ame;

long ram_size = -1;
long initial_ram_size = -1;

void debug(void* pointer, int location, ame_String name, ame_String method, ame_String type){
	// Serial.println("Name");
	// Serial.println(name);
	// Serial.println("Method");
	// Serial.println(method);
	// Serial.println("Type");
	// Serial.println(type);
	if(location == ame_Log_StartSetup){
		initial_ram_size = getRamSize();
	}
	if(location == ame_Log_StartLoop){
        System::console.println("start loop -------------------------------------------");
		long n_ram_size = getRamSize();
		// long n_ram_size = 0;
		if(ram_size == -1){
			ram_size = n_ram_size;
		}
		if(n_ram_size < ram_size){
            System::console.println("WARNING, memory is dropping: ");
            System::console.println(ram_size - n_ram_size);
			ram_size = n_ram_size;
            System::console.println("ram size: ");
            System::console.println(ram_size);
			
		   System::console.print("Loggin class: ");
		   System::console.print(name);
		   System::console.print(" - Method: ");
		   System::console.println(method);

		}
		// ram_size = n_ram_size;
		// System::console.println("ram size: ");
		// System::console.println(ram_size);
	}
	if(location == ame_Log_EndLoop){
		long n_ram_size = getRamSize();
		// System::console.print("initial ram size: ");
		// System::console.println(initial_ram_size);
		System::console.print("ram size: ");
		System::console.println(n_ram_size);
        System::console.println("end loop --------------------------------------------");
	}
	// if(method == "Constructor" && location == ame_Log_StartMethod){
		// System::console.println("new instance");
	// }
	// System::console.println("debugging");
	if(location == ame_Log_Statement){
		   System::console.print("Loggin class: ");
		   System::console.print(name);
		   System::console.print(" - Method: ");
		   System::console.println(method);
	}
}

//////////////////////////////////////////////////////////////

#endif
