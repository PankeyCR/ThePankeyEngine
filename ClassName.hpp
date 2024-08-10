
#ifndef ClassName_hpp
	#define ClassName_hpp

	#include "CharArray.hpp"

	namespace higgs{
		
		template<class cls>
		struct ClassName{
			static CharArray className;
			
			static CharArray get(){return className;}
			static void set(CharArray a_note){className = a_note;}
		};

		template<class cls> CharArray ClassName<cls>::className = "Default";

	}

#endif