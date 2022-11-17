
#ifndef CONFIGURATION_MultiArray_hpp
#define CONFIGURATION_MultiArray_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_MultiArray)
		#define MultiArray_hpp

		#define IMPLEMENTATION_MultiArray
		#define IMPLEMENTING_MultiArray
	#else
		#if defined(DISABLE_IMPLEMENTATION_MultiArray)
			#define IMPLEMENTATION_MultiArray
			#define IMPLEMENTING_MultiArray
		#endif
	#endif
#endif

#ifndef MultiArray_hpp
#define MultiArray_hpp
#define MultiArray_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_MultiArray
	#define IMPLEMENTATION_MultiArray IMPLEMENTATION(public MultiArray)
	#define IMPLEMENTING_MultiArray IMPLEMENTING(public MultiArray)
#endif

#include "cppObject.hpp"
#include "Class.hpp"
#include "PrimitiveList.hpp"
#include "Array.hpp"

namespace ame{
	
template <class T>
class MultiArray IMPLEMENTATION_cppObject {
public:
	MultiArray(){}
	virtual ~MultiArray(){}

	int getDimentionSize(){
		return 0;
	}

	virtual cppObjectClass* getClass(){return Class<MultiArray<T>>::getClass();}
	virtual bool instanceof(cppObjectClass* cls){
		return cls == Class<MultiArray<T>>::getClass();
	}
protected:
	T m_array;
};

template<>int MultiArray<int[]>::getDimentionSize(){return 1;}

}

#endif