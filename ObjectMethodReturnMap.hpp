
#ifndef ObjectMethodReturnMap_hpp
#define ObjectMethodReturnMap_hpp
#define ObjectMethodReturnMap_AVAILABLE

#include "PrimitivePointerObjectMethodReturnMap.hpp"

namespace ame{

template<class T, class R, class... Args>
struct ObjectMethodReturnMap {
	
	using Raw_Method = R (*)(T*,Args...);
	
	static PrimitivePointerObjectMethodReturnMap<cppObjectClass,T,R,Args...>* m_method_map;
	
	static void add(cppObjectClass* a_cls, Raw_Method* a_method){
		if(m_method_map == nullptr){
			return;
		}
		m_method_map->addPointers(a_cls, a_method);
	}
	
	static void remove(cppObjectClass* a_cls){
		if(m_method_map == nullptr){
			return;
		}
		m_method_map->removeDeleteByPointer(a_cls);
	}
	
	static Raw_Method* getPointer(cppObjectClass* a_cls){
		if(m_method_map == nullptr){
			return nullptr;
		}
		return m_method_map->getByLValue(a_cls);
	}
	
	static R invoke(T* a_instance, cppObjectClass* a_cls, R a_return, Args... a_invoke){
		if(m_method_map == nullptr){
			return a_return;
		}
		return m_method_map->invoke(a_instance, a_cls, a_return, a_invoke...);
	}
	
	static void invokeAll(T* a_instance, Args... a_invoke){
		if(m_method_map == nullptr){
			return;
		}
		m_method_map->invokeAll(a_instance, a_invoke...);
	}
};

template<class T, class R, class... Args>
PrimitivePointerObjectMethodReturnMap<cppObjectClass,T,R,Args...>* ObjectMethodReturnMap<T,R,Args...>::m_method_map = new PrimitivePointerObjectMethodReturnMap<cppObjectClass,T,R,Args...>();

}

#endif