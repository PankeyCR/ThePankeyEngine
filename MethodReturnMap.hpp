
#ifndef MethodReturnMap_hpp
#define MethodReturnMap_hpp
#define MethodReturnMap_AVAILABLE

#include "PrimitivePointerMethodReturnMap.hpp"

namespace ame{

template<class R, class... Args>
struct MethodReturnMap {
	
	using Raw_Method = R (*)(Args...);
	
	static PrimitivePointerMethodReturnMap<cppObjectClass,R,Args...>* m_method_map;
	
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
	
	static R invoke(cppObjectClass* a_cls, R a_return, Args... a_invoke){
		if(m_method_map == nullptr){
			return a_return;
		}
		return m_method_map->invoke(a_cls, a_return, a_invoke...);
	}
	
	static void invokeAll(Args... a_invoke){
		if(m_method_map == nullptr){
			return;
		}
		m_method_map->invokeAll(a_invoke...);
	}
};

template<class R, class... Args>
PrimitivePointerMethodReturnMap<cppObjectClass,R,Args...>* MethodReturnMap<R,Args...>::m_method_map = new PrimitivePointerMethodReturnMap<cppObjectClass,R,Args...>();

}

#endif