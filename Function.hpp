
#ifndef Function_hpp
	#define Function_hpp
		
	#include "pankey.hpp"
	
	#include "InvokeMethod.hpp"
	#include "ClassFunction.hpp"

	#ifdef Function_LogApp
		#include "pankey_Logger.hpp"
		#define FunctionLog(location,method,type,mns) pankey_Log((void*)this,location,"Function",method,type,mns)
	#else
		#define FunctionLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class T, class... Args>
		class Function{
			protected:
				obj<ClassFunction<T,Args...>> m_function;

			public:
				Function(){}

				template<class O>
				Function(const O& a_obj){
					FunctionLog(pankey_Log_StartMethod, "Constructor", "println", "const ClassFunction<T,Args...>&");
					m_function = a_obj;
					FunctionLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~Function(){
					FunctionLog(pankey_Log_StartMethod, "Destructor", "println", "");
					FunctionLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

			public:
				T run(Args... a_args){
					FunctionLog(pankey_Log_StartMethod, "run", "println", "");
					if(m_function.isNull()){
						FunctionLog(pankey_Log_EndMethod, "run", "println", "m_function.isNull()");
						return T();
					}
					FunctionLog(pankey_Log_EndMethod, "run", "println", "");
					return m_function->run(a_args...);
				}

				bool fit(T a_result, Args... a_args){
					FunctionLog(pankey_Log_StartMethod, "fit", "println", "");
					if(m_function.isNull()){
						FunctionLog(pankey_Log_EndMethod, "fit", "println", "m_function.isNull()");
						return false;
					}
					FunctionLog(pankey_Log_EndMethod, "fit", "println", "");
					return m_function->fit(a_result, a_args...);
				}

				template<class V>
				void operator=(const V& a_value){
					m_function = a_value;
				}
				
				template<class V>
				bool operator==(const V& a_value){
					if(m_function.isNull()){
						return false;
					}
					if(m_function.template isValidObject<V>()){
						V& i_valid = m_function.template getReference<V>();
						return i_valid == a_value ;
					}
					ClassFunction<T,Args...>& i_value = m_function.template getReference<ClassFunction<T,Args...>>();
					return i_value == a_value ;
				}
				
				template<class V>
				bool operator!=(const V& a_value){
					if(m_function.isNull()){
						return false;
					}
					if(m_function.template isValidObject<V>()){
						V& i_valid = m_function.template getReference<V>();
						return i_valid != a_value ;
					}
					ClassFunction<T,Args...>& i_value = m_function.template getReference<ClassFunction<T,Args...>>();
					return i_value != a_value ;
				}
		};

	}

#endif