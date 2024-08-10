/*
*
*	No config can be included inside a class
*
*/
#ifndef higgs_Enviroment_config_hpp
	#define higgs_Enviroment_config_hpp

	#include "higgs_Hardware_config.hpp"

	// #include "higgs_Render_config.hpp"

	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"

	#include "higgs_config.hpp"

	#include "higgs_Memory_Manager_config.hpp"

	#include "higgs_Context.hpp"
	#include "System.hpp"
	
	namespace higgs{

		void initializeEngine(){
			higgsHardwareConfig();
			higgsLoggerConfig();
			higgsConfig();
			System::console.print("Enviroment: ");
			System::console.println(higgs_Enviroment_Name);
			System::console.print("Hardware: ");
			System::console.println(higgs_Hardware_Name);
			System::console.println("Roboto Engine");
		}

	}

#endif