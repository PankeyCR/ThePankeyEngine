
#ifndef LifeObject_hpp
#define LifeObject_hpp

#include "ByteArray.hpp"

namespace ame{

class LifeObject{
	public:
		LifeObject(){}
		virtual ~LifeObject(){}

		virtual void setCells(ByteArray c){
			
		}

		virtual ByteArray getCells(){
			return ByteArray();
		}

	protected:
};

}

#endif