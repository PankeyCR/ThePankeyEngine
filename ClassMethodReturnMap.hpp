
#ifndef ClassMethodReturnMap_hpp
#define ClassMethodReturnMap_hpp
#define ClassMethodReturnMap_AVAILABLE

#include "PrimitivePointerClassMethodReturnMap.hpp"

namespace ame{

template<class T, class R, class... Args>
struct ClassMethodReturnMap {
	
	using Class_Method = R (*)(Args...);
	
	static PrimitivePointerClassMethodReturnMap<cppObjectClass,T,R,Args...>* m_method_map;
	
	static void add(cppObjectClass* a_cls, Class_Method* a_method){
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
	
	static Class_Method* getPointer(cppObjectClass* a_cls){
		if(m_method_map == nullptr){
			return nullptr;
		}
		return m_method_map->getByLValue(a_cls);
	}
	
	static R invoke(T* a_intance, cppObjectClass* a_cls, R a_return, Args... args){
		if(m_method_map == nullptr){
			return a_return;
		}
		return m_method_map->invoke(a_intance, a_cls, a_return, args...);
	}
	
	static R invokeAll(T* a_intance, R a_return, Args... args){
		if(m_method_map == nullptr){
			return a_return;
		}
		return m_method_map->invokeAll(a_intance, a_return, args...);
	}
};

template<class T, class R, class... Args>
PrimitivePointerClassMethodReturnMap<cppObjectClass,T,R,Args...>* ClassMethodReturnMap<T,R,Args...>::m_method_map = new PrimitivePointerClassMethodReturnMap<cppObjectClass,T,R,Args...>();

}

#endif