/*
*
*	No config can be included inside a class
*
*/
#ifndef pankey_Enviroment_config_hpp
	#define pankey_Enviroment_config_hpp
	
	#include "pankey_System.hpp"

	#include "pankey_Hardware_config.hpp"

	// #include "pankey_Render_config.hpp"

	#include "pankey_Logger_config.hpp"
	#include "pankey_Logger.hpp"

	#include "pankey_config.hpp"

	#include "pankey_Memory_Manager_config.hpp"

	#include "pankey_Context.hpp"
	#include "pankey_Watchdog.hpp"
	
	namespace pankey{

		void initializeEngine(){
			pankeyHardwareConfig();
			pankeyLoggerConfig();
			pankeyConfig();
			System::console.print("Enviroment: ");
			System::console.println(pankey_Enviroment_Name);
			System::console.print("Hardware: ");
			System::console.println(pankey_Hardware_Name);
			System::console.println("Roboto Engine");
		}

	}

#endif