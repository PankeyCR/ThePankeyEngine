
#ifndef CONFIGURATION_ame_Enviroment_hpp
#define CONFIGURATION_ame_Enviroment_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_ame_Enviroment)
		#define ame_Enviroment_hpp

		#define IMPLEMENTATION_ame_Enviroment
		#define IMPLEMENTING_ame_Enviroment
	#else
		#if defined(DISABLE_IMPLEMENTATION_ame_Enviroment)
			#define IMPLEMENTATION_ame_Enviroment
			#define IMPLEMENTING_ame_Enviroment
		#endif
	#endif
#endif

#ifndef ame_Enviroment_hpp
#define ame_Enviroment_hpp

#include "ame_Enviroment_config.hpp"

#include "ame_config.hpp"

#include "ame_Class_Implementation.hpp"

#include "ame_Enviroment_config.hpp"
#include "ame_Enviroment_define.hpp"

#include "ame_Render_config.hpp"

#include "ame_Level.hpp"

#include "ame_Logger.hpp"


#endif