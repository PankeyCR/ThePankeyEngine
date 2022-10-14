
#ifndef ObjectMethodMap_hpp
#define ObjectMethodMap_hpp
#define ObjectMethodMap_AVAILABLE

#include "PrimitivePointerObjectMethodMap.hpp"

namespace ame{

template<class T, class... Args>
struct ObjectMethodMap {
	
	using Raw_NTMethod = void(*)(T*,Args...);
	
	static PrimitivePointerObjectMethodMap<cppObjectClass,T,Args...>* m_method_map;
	
	static void add(cppObjectClass* a_cls, Raw_NTMethod* a_method){
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
	
	static Raw_NTMethod* getPointer(cppObjectClass* a_cls){
		if(m_method_map == nullptr){
			return nullptr;
		}
		return m_method_map->getByLValue(a_cls);
	}
	
	static bool invoke(T* a_instance, cppObjectClass* a_cls, Args... a_invoke){
		if(m_method_map == nullptr){
			return false;
		}
		return m_method_map->invoke(a_instance, a_cls, a_invoke...);
	}
};

template<class T, class... Args>
PrimitivePointerObjectMethodMap<cppObjectClass,T,Args...>* ObjectMethodMap<T,Args...>::m_method_map = new PrimitivePointerObjectMethodMap<cppObjectClass,T,Args...>();

}

#endif