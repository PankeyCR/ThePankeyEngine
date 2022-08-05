
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Logic)
	#define Logic_hpp
#endif

#ifndef Logic_hpp
#define Logic_hpp
#define Logic_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ByteArray.hpp"

namespace ame{

class Logic{
	public:
		Logic(){}
		virtual ~Logic(){}

		virtual ByteArray logic(ByteArray array){
			ByteArray r_array = array;
			return r_array;
		}
		
		virtual Logic* clone(){
			return nullptr;
		}

	protected:
};

}

#endif