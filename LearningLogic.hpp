
#ifndef LearningLogic_h
#define LearningLogic_h

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