
#ifndef UpdateClassFunctionListManager_hpp
	#define UpdateClassFunctionListManager_hpp

	#include "InvokeRawList.hpp"
	#include "UpdateManager.hpp"

	namespace higgs{

		template<class A, class... Args>
		class UpdateClassFunctionListManager : virtual public UpdateManager<A&,Args...>{
			public:

				UpdateClassFunctionListManager(){}
				
				virtual ~UpdateClassFunctionListManager(){}

				virtual void add(InvokeClassMethod<A,Args...> a_state){
					this->m_app_methods.add(a_state);
				}
				
				virtual void removeUpdateClassFunctionList(InvokeClassMethod<A,Args...> a_state){
					this->m_app_methods.removeDeleteByLValue(a_state);
				}
				
				virtual void removeUpdateClassFunctionList(int a_index){
					this->m_app_methods.removeDeleteByPosition(a_index);
				}
				
				virtual void removeAllUpdateClassFunctionList(){
					this->m_app_methods.resetDelete();
				}
				
				virtual void removeAll(){
					this->m_app_methods.resetDelete();
				}
				
				virtual int getUpdateClassFunctionListSize(){
					return this->m_app_methods.getPosition();
				}
				
				virtual void update(A& a_app, Args... a_values){
					invokeAll<A,Args...>(this->m_app_methods, a_app, a_values...);
				}

			protected:
				ClassMethodList<A,Args...> m_app_methods;
		};

	}

#endif
