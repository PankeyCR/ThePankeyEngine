
#ifndef Logic_hpp
#define Logic_hpp

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