
#ifndef PrimitivePointerObjectMethodReturnMap_hpp
#define PrimitivePointerObjectMethodReturnMap_hpp
#define PrimitivePointerObjectMethodReturnMap_AVAILABLE

#include "PrimitiveRawPointerMap.hpp"

namespace ame{

template<class K, class T, class R, class... Args>
class PrimitivePointerObjectMethodReturnMap : public PrimitiveRawPointerMap<K,R (*)(T*, Args...)>{
	public:
		using EventMethodMap = R (*)(T*, Args...);
		
		PrimitivePointerObjectMethodReturnMap(){}
		virtual ~PrimitivePointerObjectMethodReturnMap(){}

		virtual R invoke(T* a_instance, K* a_key, R a_return, Args... args){
			EventMethodMap* i_event = this->getByPointer(a_key);
			if(i_event == nullptr){
				return a_return;
			}
			return (**i_event)(a_instance, args...);
		}

		virtual void invokeAll(T* a_instance, Args... args){
			for(int x = 0; x < this->getPosition(); x++){
				(**this->getByPosition(x))(a_instance, args...);
			}
		}
};

}

#endif