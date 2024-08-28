
#ifndef PointerSize_hpp
	#define PointerSize_hpp

	#include "pankey_Enviroment.hpp"

	namespace pankey{

		#if defined(pankey_Windows)
			//#include <iostream>
			//using pointer_size = size_t;
			using pointer_size = decltype(alignof(char));
		#elif defined(pankey_ArduinoIDE)
			using pointer_size = size_t;
		#else
			using pointer_size = long;
		#endif

		template<class P>
		pointer_size sizeOfPointer(const P* a_pointer){
			return (char *)(a_pointer + 1) - (char *)(a_pointer);
		}

		template<class P>
		pointer_size sizeOfPointer(){
			P i_pointer;
			return sizeOfPointer<P>(&i_pointer);
		}
	}

#endif