
#ifndef UpdateClassFunctionMapManager_hpp
	#define UpdateClassFunctionMapManager_hpp

	#include "InvokeRawMap.hpp"
	#include "UpdateManager.hpp"

	namespace higgs{

		template<class A, class K, class... Args>
		class UpdateClassFunctionMapManager : virtual public UpdateManager<A&,Args...>{
			public:

				UpdateClassFunctionMapManager(){}
				
				virtual ~UpdateClassFunctionMapManager(){}

				virtual void add(K a_key, InvokeClassMethod<A,Args...> a_state){
					this->m_app_methods.add(a_key, a_state);
				}
				
				virtual void removeUpdateClassFunctionMap(K a_key){
					this->m_app_methods.removeDeleteByKeyLValue(a_key);
				}
				
				virtual void removeUpdateClassFunctionMap(int a_index){
					this->m_app_methods.removeDeleteByPosition(a_index);
				}
				
				virtual void removeAllUpdateClassFunctionMap(){
					this->m_app_methods.resetDelete();
				}
				
				virtual void removeAll(){
					this->m_app_methods.resetDelete();
				}
				
				virtual int getUpdateClassFunctionMapSize(){
					return this->m_app_methods.getPosition();
				}
				
				virtual void update(A& a_app, Args... a_values){
					invokeAll<A,K,Args...>(this->m_app_methods, a_app, a_values...);
				}

			protected:
				ClassMethodMap<A,K,Args...> m_app_methods;
		};

	}

#endif
