
#ifndef PrimitivePointerClassMethodReturnMap_hpp
#define PrimitivePointerClassMethodReturnMap_hpp
#define PrimitivePointerClassMethodReturnMap_AVAILABLE

#include "PrimitiveRawPointerMap.hpp"

namespace ame{

template<class K, class T, class R, class... Args>
class PrimitivePointerClassMethodReturnMap : public PrimitiveRawPointerMap<K,R (T::*)(Args...)>{
	public:
		using EventMethodMap = R (T::*)(Args...);
		
		PrimitivePointerClassMethodReturnMap(){}
		virtual ~PrimitivePointerClassMethodReturnMap(){}

		virtual R invoke(T* a_intance, EventMethodMap* a_method, R a_return, Args... args){
			if(a_method == nullptr){
				return a_return;
			}
			return (a_intance->**a_method)(args...);
		}

		virtual R invoke(T* a_intance, K* a_key, R a_return, Args... args){
			EventMethodMap* i_event = this->getByPointer(a_key);
			if(i_event == nullptr || a_intance == nullptr){
				return a_return;
			}
			return (a_intance->**i_event)(args...);
		}

		virtual R invokeAll(T* a_intance, R a_return, Args... args){
			for(int x = 0; x < this->getPosition(); x++){
				(a_intance->**this->getByPosition(x))(args...);
			}
			return a_return;
		}
};

}

#endif