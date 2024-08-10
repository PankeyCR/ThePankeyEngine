
#ifndef UpdateFunctionMapManager_hpp
	#define UpdateFunctionMapManager_hpp

	#include "InvokeRawMap.hpp"
	#include "UpdateManager.hpp"

	namespace higgs{

		template<class K, class... Args>
		class UpdateFunctionMapManager : virtual public UpdateManager<Args...>{
			public:

				UpdateFunctionMapManager(){}
				virtual ~UpdateFunctionMapManager(){}

				virtual void add(K a_key, InvokeMethod<Args...> a_state){
					this->m_update_function_map.add(a_key, a_state);
				}

				virtual void put(K a_key, InvokeMethod<Args...> a_state){
					this->m_update_function_map.put(a_key, a_state);
				}

				virtual void change(K a_key, InvokeMethod<Args...> a_state){
					this->m_update_function_map.remove(a_key);
					this->m_update_function_map.add(a_key, a_state);
				}
				
				virtual void removeUpdateFunctionMap(K a_key){
					this->m_update_function_map.removeDeleteByKeyLValue(a_key);
				}
				
				virtual void removeUpdateFunctionMap(int a_index){
					this->m_update_function_map.removeDeleteByPosition(a_index);
				}
				
				virtual void removeAllUpdateFunctionMap(){
					this->m_update_function_map.resetDelete();
				}
				
				virtual void removeAll(){
					this->m_update_function_map.resetDelete();
				}
				
				virtual int getUpdateFunctionMapSize(){
					return this->m_update_function_map.getPosition();
				}
				
				virtual void update(Args... a_update){
					invokeAll<K,Args...>(this->m_update_function_map, a_update...);
				}

			protected:
				MethodMap<K,Args...> m_update_function_map;
		};

	}

#endif
