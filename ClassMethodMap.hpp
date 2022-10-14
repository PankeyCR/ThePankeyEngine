
#ifndef ClassMethodMap_hpp
#define ClassMethodMap_hpp
#define ClassMethodMap_AVAILABLE

#include "PrimitivePointerClassMethodMap.hpp"

namespace ame{

template<class T, class... Args>
struct ClassMethodMap {
	
	using Class_Method = void(T::*)(Args...);
	
	static PrimitivePointerClassMethodMap<cppObjectClass,T,Args...>* m_method_map;
	
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
		return m_method_map->getByPointer(a_cls);
	}
	
	static bool invoke(T* a_instance, cppObjectClass* a_cls, Args... a_invoke){
		if(m_method_map == nullptr){
			return false;
		}
		m_method_map->invoke(a_instance, a_cls, a_invoke...);
		return true;
	}
	
	static bool invokeAll(T* a_instance, Args... a_invoke){
		if(m_method_map == nullptr){
			return false;
		}
		m_method_map->invokeAll(a_instance, a_invoke...);
		return true;
	}
};

template<class T, class... Args>
PrimitivePointerClassMethodMap<cppObjectClass,T,Args...>* ClassMethodMap<T,Args...>::m_method_map = new PrimitivePointerClassMethodMap<cppObjectClass,T,Args...>();

}

#endif