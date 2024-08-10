
#ifndef ByteArrayForm_hpp
	#define ByteArrayForm_hpp

	#include "higgs_Enviroment.hpp"
	#include "ByteArray.hpp"

	namespace ame{
		
		class ByteArrayForm{
			public:
			ByteArrayForm(){}
			virtual ~ByteArrayForm(){}

			virtual void setByteArray(const ByteArray& array){}

			virtual ByteArray getByteArray(){return 0;}
		};

	}

#endif