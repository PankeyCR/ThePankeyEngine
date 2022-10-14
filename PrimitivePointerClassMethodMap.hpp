
#ifndef PrimitivePointerClassMethodMap_hpp
#define PrimitivePointerClassMethodMap_hpp
#define PrimitivePointerClassMethodMap_AVAILABLE

#include "PrimitiveRawPointerMap.hpp"

namespace ame{

template<class K, class T, class... Args>
class PrimitivePointerClassMethodMap : public PrimitiveRawPointerMap<K,void (T::*)(Args...)>{
	public:
		using EventMethodMap = void (T::*)(Args...);
		
		PrimitivePointerClassMethodMap(){}
		virtual ~PrimitivePointerClassMethodMap(){}

		virtual void invoke(T* a_intance, EventMethodMap* a_method, Args... args){
			if(a_method == nullptr){
				return;
			}
			( a_intance->**a_method)(args...);
		}

		virtual bool invoke(T* a_intance, K* a_key, Args... args){
			EventMethodMap* i_event = this->getByPointer(a_key);
			if(i_event == nullptr || a_intance == nullptr){
				return false;
			}
			(a_intance->**i_event)(args...);
			return true;
		}

		virtual void invoke(T* a_intance, Args... args){
			for(int x = 0; x < this->getPosition(); x++){
				(a_intance->**this->getByPosition(x))(args...);
			}
		}
};

}

#endif