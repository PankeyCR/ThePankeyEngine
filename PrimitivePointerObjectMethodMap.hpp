
#ifndef PrimitivePointerObjectMethodMap_hpp
#define PrimitivePointerObjectMethodMap_hpp
#define PrimitivePointerObjectMethodMap_AVAILABLE

#include "PrimitiveRawPointerMap.hpp"

namespace ame{

template<class K, class T, class... Args>
class PrimitivePointerObjectMethodMap : public PrimitiveRawPointerMap<K,void (*)(T*,Args...)>{
	public:
		using EventMethodMap = void (*)(T*,Args...);
		
		PrimitivePointerObjectMethodMap(){}
		virtual ~PrimitivePointerObjectMethodMap(){}

		virtual void invoke(T* a_instance, EventMethodMap* a_method, Args... args){
			if(a_method == nullptr){
				return;
			}
			(**a_method)(a_instance, args...);
		}

		virtual bool invoke(T* a_instance, K* a_key, Args... args){
			EventMethodMap* i_event = this->getByPointer(a_key);
			if(i_event == nullptr){
				return false;
			}
			(**i_event)(a_instance, args...);
			return true;
		}

		virtual void invokeAll(T* a_instance, Args... args){
			for(int x = 0; x < this->getPosition(); x++){
				(**this->getByPosition(x))(a_instance, args...);
			}
		}
};

}

#endif