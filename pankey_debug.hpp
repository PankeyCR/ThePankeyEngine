
#ifndef pankey_debug_hpp
	#define pankey_debug_hpp

	//////////////////////////////////////////////////////////////

	#include "pankey_Logger_config.hpp"
	#include "pankey_MemoryRam.hpp"
	#include "pankey_String.hpp"
	#include "pankey_System.hpp"

	using namespace pankey;

	long ram_size = -1;
	long initial_ram_size = -1;
	int g_count_leak = 0;
	int g_time_loop_spent = 0;

	void debug(void* pointer, int location, pankey_String name, pankey_String method, pankey_String type){
		// Serial.println("Name");
		// Serial.println(name);
		// Serial.println("Method");
		// Serial.println(method);
		// Serial.println("Type");
		// Serial.println(type);
		if(location == pankey_Log_StartSetup){
			initial_ram_size = getRamSize();
		}
		if(location == pankey_Log_StartLoop){
			System::console.println("start loop -------------------------------------------");
			g_time_loop_spent = System::microSeconds();
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

				g_count_leak++;
			}
			// ram_size = n_ram_size;
			// System::console.println("ram size: ");
			// System::console.println(ram_size);
		}
		if(location == pankey_Log_EndLoop){
			System::console.print("loop time spent in micros: ");
			System::console.println(System::microSeconds() - g_time_loop_spent);
			long n_ram_size = getRamSize();
			// System::console.print("initial ram size: ");
			// System::console.println(initial_ram_size);
			System::console.print("ram size: ");
			System::console.println(n_ram_size);
			System::console.println("end loop --------------------------------------------");
		}
		// if(method == "Constructor" && location == pankey_Log_StartMethod){
			// System::console.println("new instance");
		// }
		// System::console.println("debugging");
		if(location == pankey_Log_Statement){
			//    System::console.print("Loggin class: ");
			//    System::console.print(name);
			//    System::console.print(" - Method: ");
			//    System::console.println(method);
		}

		if(g_count_leak >= 10){
			while(true){
				System::console.println("Engine stop because of memory leaks");
			}
		}
	}

//////////////////////////////////////////////////////////////

#endif
