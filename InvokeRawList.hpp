
#ifndef InvokeRawList_hpp
	#define InvokeRawList_hpp

	#include "PrimitiveRawList.hpp"
	#include "InvokeMethod.hpp"

	#ifdef InvokeRawList_LogApp
		#include "pankey_Logger.hpp"
		#define InvokeRawListLog(location,method,type,mns) pankey_Log(nullptr,location,"InvokeRawList",method,type,mns)
	#else
		#define InvokeRawListLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class... Args>
		using MethodList = PrimitiveRawList<InvokeMethod<Args...>>;

		template<class R, class... Args>
		using MethodReturnList = PrimitiveRawList<InvokeMethodReturn<R,Args...>>;

		template<class T, class... Args>
		using ClassMethodList = PrimitiveRawList<InvokeClassMethod<T,Args...>>;

		template<class T, class R, class... Args>
		using ClassMethodReturnList = PrimitiveRawList<InvokeClassMethodReturn<T,R,Args...>>;

		template<class... Args>
		void invoke(const RawList<InvokeMethod<Args...>>& a_list, int a_index, Args... args){
			InvokeRawListLog(pankey_Log_StartMethod, "invoke", "println", "");
			auto i_event = a_list.getByPosition(a_index);
			if(i_event == nullptr){
				InvokeRawListLog(pankey_Log_EndMethod, "invoke", "println", "");
				return;
			}
			(**i_event)(args...);
			InvokeRawListLog(pankey_Log_EndMethod, "invoke", "println", "");
		}

		template<class... Args>
		void invokeAll(const RawList<InvokeMethod<Args...>>& a_list, Args... args){
			InvokeRawListLog(pankey_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_list.getPosition(); x++){
				auto i_event = a_list.getByPosition(x);
				if(i_event == nullptr){
					InvokeRawListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
					return;
				}
				(**i_event)(args...);
			}
			InvokeRawListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
		}

		template<class T, class... Args>
		void invoke(const RawList<InvokeClassMethod<T,Args...>>& a_list, T& a_instance, int a_index, Args... args){
			InvokeRawListLog(pankey_Log_StartMethod, "invoke", "println", "");
			auto i_event = a_list.getByPosition(a_index);
			if(i_event == nullptr){
				InvokeRawListLog(pankey_Log_EndMethod, "invoke", "println", "");
				return;
			}
			T* i_instance = &a_instance;
			(i_instance->**i_event)(args...);
			InvokeRawListLog(pankey_Log_EndMethod, "invoke", "println", "");
		}

		template<class T, class... Args>
		void invokeAll(const RawList<InvokeClassMethod<T,Args...>>& a_list, T& a_instance, Args... args){
			InvokeRawListLog(pankey_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_list.getPosition(); x++){
				auto i_event = a_list.getByPosition(x);
				if(i_event == nullptr){
					InvokeRawListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
					return;
				}
				T* i_instance = &a_instance;
				(i_instance->**i_event)(args...);
			}
			InvokeRawListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
		}

		template<class R, class... Args>
		R invoke(const RawList<InvokeMethodReturn<R,Args...>>& a_list, int a_index, Args... args){
			InvokeRawListLog(pankey_Log_StartMethod, "invoke", "println", "");
			auto i_event = a_list.getByPosition(a_index);
			if(i_event == nullptr){
				InvokeRawListLog(pankey_Log_EndMethod, "invoke", "println", "");
				return R();
			}
			InvokeRawListLog(pankey_Log_EndMethod, "invoke", "println", "");
			return (**i_event)(args...);
		}

		template<class T, class R, class... Args>
		R invoke(const RawList<InvokeClassMethodReturn<T,R,Args...>>& a_list, T& a_instance, int a_index, Args... args){
			InvokeRawListLog(pankey_Log_StartMethod, "invoke", "println", "");
			auto i_event = a_list.getByPosition(a_index);
			if(i_event == nullptr){
				InvokeRawListLog(pankey_Log_EndMethod, "invoke", "println", "");
				return R();
			}
			T* i_instance = &a_instance;
			InvokeRawListLog(pankey_Log_EndMethod, "invoke", "println", "");
			return (i_instance->**i_event)(args...);
		}
		
	}

#endif