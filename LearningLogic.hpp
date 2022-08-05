
#include "ame_Enviroment.hpp"

#if defined(DISABLE_LearningLogic)
	#define LearningLogic_hpp
#endif

#ifndef LearningLogic_h
#define LearningLogic_h
#define LearningLogic_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ByteArray.h"
#include "Logic.h"

namespace ame{

class LearningLogic : public Logic{
	public:
		LearningLogic(){}
		virtual ~LearningLogic(){}

		virtual ByteArray logic(ByteArray array){
			ByteArray r_array = array;
			return r_array;
		}

	protected:
};

}

#endif