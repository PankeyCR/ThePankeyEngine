
#ifndef CastObject_hpp
#define CastObject_hpp
#define CastObject_AVAILABLE

#include "Class.hpp"

namespace ame{

template<class T>
T* CastObject(cppObject* obj){
	if(obj == nullptr){
		return nullptr;
	}
	if(obj->instanceof(Class<T>::getClass())){
		return (T*)obj;
	}
	return nullptr;
}

template<class T>
T* CastAbstractObject(cppObject* obj){
	if(obj == nullptr){
		return nullptr;
	}
	if(obj->instanceof(AbstractClass<T>::getClass())){
		return (T*)obj;
	}
	return nullptr;
}


}

#endif



//