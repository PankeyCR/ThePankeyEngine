
#ifndef ReturnMethodMap_hpp
#define ReturnMethodMap_hpp
#define ReturnMethodMap_AVAILABLE

#include "StaticReturnMethodMap.hpp"

namespace ame{

template<class R,class... Args>
struct ReturnMethodMap {
	
	using Raw_Method = R(*)(Args...);
	
	static StaticReturnMethodMap<Note,R,Args...>* m_method_map;
	
	static void add(Note a_name, Raw_Method a_method){
		if(m_method_map == nullptr){
			return;
		}
		m_method_map->add(a_name, a_method);
	}
	
	static void remove(Note a_name){
		if(m_method_map == nullptr){
			return;
		}
		m_method_map->removeDelete(a_name);
	}
	
	static Raw_Method* getPointer(Note a_name){
		if(m_method_map == nullptr){
			return nullptr;
		}
		return m_method_map->getByLValue(a_name);
	}
	
	static R invoke(Note a_name, Args... a_invoke){
		if(m_method_map == nullptr){
			return R();
		}
		return m_method_map->invoke(a_name, a_invoke...);
	}
};

template<class R,class... Args>
StaticReturnMethodMap<Note,R,Args...>* ReturnMethodMap<R,Args...>::m_method_map = new StaticReturnMethodMap<Note,R,Args...>();

}

#endif