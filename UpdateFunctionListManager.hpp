
#ifndef UpdateFunctionListManager_hpp
	#define UpdateFunctionListManager_hpp

	#include "InvokeRawList.hpp"
	#include "UpdateManager.hpp"

	namespace pankey{

		template<class... Args>
		class UpdateFunctionListManager : virtual public UpdateManager<Args...>{
			public:

				UpdateFunctionListManager(){}
				virtual ~UpdateFunctionListManager(){}

				virtual void add(InvokeMethod<Args...> a_state){
					this->m_update_function_list.add(a_state);
				}
				
				virtual void removeUpdateFunctionList(InvokeMethod<Args...> a_state){
					this->m_update_function_list.removeDeleteByLValue(a_state);
				}
				
				virtual void removeUpdateFunctionList(int a_index){
					this->m_update_function_list.removeDeleteByPosition(a_index);
				}
				
				virtual void removeAllUpdateFunctionList(){
					this->m_update_function_list.resetDelete();
				}
				
				virtual void removeAll(){
					this->m_update_function_list.resetDelete();
				}
				
				virtual int getUpdateFunctionListSize(){
					return this->m_update_function_list.getPosition();
				}
				
				virtual void update(Args... a_update){
					invokeAll<Args...>(this->m_update_function_list, a_update...);
				}

			protected:
				MethodList<Args...> m_update_function_list;
		};

	}

#endif
