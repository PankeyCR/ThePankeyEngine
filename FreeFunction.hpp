
#ifndef FreeFunction_hpp
	#define FreeFunction_hpp

	#include "InvokeMethod.hpp"
	#include "ClassFunction.hpp"

	#ifdef FreeFunction_LogApp
		#include "pankey_Logger.hpp"
		#define FreeFunctionLog(location,method,type,mns) pankey_Log((void*)this,location,"FreeFunction",method,type,mns)
	#else
		#define FreeFunctionLog(location,method,type,mns)
	#endif
	
	namespace pankey{

		template<class T, class... Args>
		class FreeFunction : public ClassFunction<T,Args...>{
			public:
				InvokeMethodReturn<T,Args...> m_method = nullptr;
				InvokeMethodReturn<bool,T,Args...> m_fit = nullptr;

				FreeFunction(){
					FreeFunctionLog(pankey_Log_StartMethod, "Constructor", "println", "");
					FreeFunctionLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				FreeFunction(const FreeFunction<T,Args...>& a_freefunction){
					FreeFunctionLog(pankey_Log_StartMethod, "Constructor", "println", "");
					m_method = a_freefunction.m_method;
					m_fit = a_freefunction.m_fit;
					FreeFunctionLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				FreeFunction(InvokeMethodReturn<T,Args...> a_method){
					FreeFunctionLog(pankey_Log_StartMethod, "Constructor", "println", "InvokeMethodReturn<T,Args...>");
					m_method = a_method;
					FreeFunctionLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				FreeFunction(InvokeMethodReturn<T,Args...> a_method, InvokeMethodReturn<bool,T,Args...> a_fit){
					FreeFunctionLog(pankey_Log_StartMethod, "Constructor", "println", "InvokeMethodReturn<T,Args...>, InvokeMethodReturn<bool,T,Args...>");
					m_method = a_method;
					m_fit = a_fit;
					FreeFunctionLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~FreeFunction(){
					FreeFunctionLog(pankey_Log_StartMethod, "Destructor", "println", "");
					FreeFunctionLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual T run(Args... a_args){
					FreeFunctionLog(pankey_Log_StartMethod, "run", "println", "");
					FreeFunctionLog(pankey_Log_EndMethod, "run", "println", "");
					return invoke<T,Args...>(m_method, a_args...);
				}
				virtual bool fit(T a_result, Args... a_args){
					FreeFunctionLog(pankey_Log_StartMethod, "fit", "println", "");
					FreeFunctionLog(pankey_Log_EndMethod, "fit", "println", "");
					return invoke<bool,T,Args...>(m_fit, a_result, a_args...);
				}
				virtual void operator=(const FreeFunction<T,Args...>& a_fn){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "println", "");
					m_method = a_fn.m_method;
					m_fit = a_fn.m_fit;
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "println", "");
				}
				virtual void operator=(InvokeMethodReturn<T,Args...> a_method){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "println", "");
					m_method = a_method;
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "println", "");
				}
				virtual void operator=(InvokeMethodReturn<bool,T,Args...> a_fit){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "println", "");
					m_fit = a_fit;
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "println", "");
				}

				virtual bool operator==(const FreeFunction<T,Args...>& a_fn){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "println", "");
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "println", "");
					return a_fn.m_method == m_method && a_fn.m_fit == m_fit;
				}

				virtual bool operator!=(const FreeFunction<T,Args...>& a_fn){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "println", "");
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "println", "");
					return a_fn.m_method != m_method || a_fn.m_fit != m_fit;
				}
		};

	}

#endif