
#ifndef PrimitivePointerMethodReturnMap_hpp
#define PrimitivePointerMethodReturnMap_hpp
#define PrimitivePointerMethodReturnMap_AVAILABLE

#include "PrimitiveRawPointerMap.hpp"

namespace ame{

template<class K, class R, class... Args>
class PrimitivePointerMethodReturnMap : public PrimitiveRawPointerMap<K,R (*)(Args...)>{
	public:
		using EventMethodMap = R (*)(Args...);
		
		PrimitivePointerMethodReturnMap(){}
		virtual ~PrimitivePointerMethodReturnMap(){}

		virtual R invoke(EventMethodMap* a_method, Args... args){
			if(a_method == nullptr){
				return;
			}
			return (**a_method)(args...);
		}

		virtual R invoke(K* a_key, R a_return, Args... args){
			EventMethodMap* i_event = this->getByPointer(a_key);
			if(i_event == nullptr){
				return a_return;
			}
			return (**i_event)(args...);
		}

		virtual void invokeAll(Args... args){
			for(int x = 0; x < this->getPosition(); x++){
				(**this->getByPosition(x))(args...);
			}
		}
};

}

#endif