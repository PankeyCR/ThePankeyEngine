
#ifndef InvokeMethod_hpp
	#define InvokeMethod_hpp

	#ifdef InvokeMethod_LogApp
		#include "pankey_Logger.hpp"
		#define InvokeMethodLog(location,method,type,mns) pankey_Log(nullptr,location,"InvokeMethod",method,type,mns)
	#else
		#define InvokeMethodLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class... Args>
		using InvokeMethod = void (*)(Args...);

		template<class R, class... Args>
		using InvokeMethodReturn = R (*)(Args...);

		template<class T, class... Args>
		using InvokeClassMethod = void (T::*)(Args...);

		template<class T, class R, class... Args>
		using InvokeClassMethodReturn = R (T::*)(Args...);

		template<class... Args>
		void invoke(InvokeMethod<Args...> a_method, Args... args){
			InvokeMethodLog(pankey_Log_StartMethod, "invoke", "println", "");
			InvokeMethodLog(pankey_Log_Statement, "invoke", "println", "invoking as a lvalue");
			if(a_method == nullptr){
				InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
				return;
			}
			(*a_method)(args...);
			InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
		}

		template<class... Args>
		void invoke(InvokeMethod<Args...>* a_method, Args... args){
			InvokeMethodLog(pankey_Log_StartMethod, "invoke", "println", "");
			InvokeMethodLog(pankey_Log_Statement, "invoke", "println", "invoking as a pointer");
			if(a_method == nullptr){
				InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "a_method == nullptr");
				return;
			}
			(**a_method)(args...);
			InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
		}

		template<class R, class... Args>
		R invoke(InvokeMethodReturn<R,Args...> a_method, Args... args){
			InvokeMethodLog(pankey_Log_StartMethod, "invoke", "println", "");
			InvokeMethodLog(pankey_Log_Statement, "invoke", "println", "invoking as a lvalue, and returning value");
			if(a_method == nullptr){
				InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
				return R();
			}
			InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
			return (*a_method)(args...);
		}

		template<class R, class... Args>
		R invoke(InvokeMethodReturn<R,Args...>* a_method, Args... args){
			InvokeMethodLog(pankey_Log_StartMethod, "invoke", "println", "");
			InvokeMethodLog(pankey_Log_Statement, "invoke", "println", "invoking as a pointer, and returning value");
			if(a_method == nullptr){
				InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "a_method == nullptr");
				return R();
			}
			InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
			return (**a_method)(args...);
		}

		template<class T, class... Args>
		void invoke(T& a_instance, InvokeClassMethod<T,Args...> a_method, Args... args){
			InvokeMethodLog(pankey_Log_StartMethod, "invoke", "println", "");
			InvokeMethodLog(pankey_Log_Statement, "invoke", "println", "invoking class method as a lvalue");
			if(a_method == nullptr){
				InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
				return;
			}
			T* i_instance = &a_instance;
			(i_instance->*a_method)(args...);
			InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
		}

		template<class T, class R, class... Args>
		R invoke(T& a_instance, InvokeClassMethodReturn<T,R,Args...> a_method, Args... args){
			InvokeMethodLog(pankey_Log_StartMethod, "invoke", "println", "");
			InvokeMethodLog(pankey_Log_Statement, "invoke", "println", "invoking class method as a lvalue, and returning value");
			if(a_method == nullptr){
				InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
				return R();
			}
			T* i_instance = &a_instance;
			InvokeMethodLog(pankey_Log_EndMethod, "invoke", "println", "");
			return (i_instance->*a_method)(args...);
		}
	}

#endif