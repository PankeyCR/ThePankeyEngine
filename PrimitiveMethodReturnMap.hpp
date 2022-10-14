
#ifndef PrimitiveMethodReturnMap_hpp
#define PrimitiveMethodReturnMap_hpp
#define PrimitiveMethodReturnMap_AVAILABLE

#include "PrimitiveRawMap.hpp"

namespace ame{

template<class K, class R, class... Args>
class PrimitiveMethodReturnMap{
	protected:
		PrimitiveRawMap<K,R (*)(Args...)> m_method_map;
	public:
		using EventMethodMap = R (*)(Args...);
		
		PrimitiveMethodReturnMap(){}
		virtual ~PrimitiveMethodReturnMap(){}
		
		virtual void add(K a_key, EventMethodMap a_method){
			m_method_map.addLValues(a_key, a_method);
		}

		virtual R invoke(K a_key, R a_return, Args... args){
			EventMethodMap* i_event = m_method_map.getValueByLValue(a_key);
			if(i_event == nullptr){
				return a_return;
			}
			return (**i_event)(args...);
		}

		virtual R invokeByPosition(int a_position, R a_return, Args... args){
			EventMethodMap* i_event = m_method_map.getValueByPosition(a_position);
			if(i_event == nullptr){
				return a_return;
			}
			return (**i_event)(args...);
			// return a_return;
		}

		virtual void invokeAll(Args... args){
			for(int x = 0; x < m_method_map.getPosition(); x++){
				(**m_method_map.getValueByPosition(x))(args...);
			}
		}
		
		virtual int getPosition(){
			return m_method_map.getPosition();
		}
		
		virtual K getKey(int x){
			K* i_key = m_method_map.getKeyByPosition(x);
			if(i_key == nullptr){
				return K();
			}
			return *i_key;
		}
		
		virtual EventMethodMap* getMethod(int x){
			EventMethodMap* i_method = m_method_map.getValueByPosition(x);
			return i_method;
		}
};

}

#endif