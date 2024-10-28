
#ifndef pankey_Function_config_hpp
    #define pankey_Function_config_hpp

	#include "Function.hpp"
	#include "FreeFunction.hpp"

	
	namespace pankey{

		template<class T, class... Args>
		using function = obj<ClassFunction<T,Args...>>;

		using Fx = Function<float,float>;
		using fx = function<float,float>;

		template<class N>
		using Fn = Function<N,N>;



		using FreeFun = FreeFunction<float,float>;
		
    }


#endif