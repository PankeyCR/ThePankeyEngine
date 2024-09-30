
#ifndef InvokeList_hpp
	#define InvokeList_hpp
	
	#include "pankey.hpp"

	#include "InvokeMethod.hpp"

	#ifdef InvokeList_LogApp
		#include "pankey_Logger.hpp"
		#define InvokeListLog(location,method,type,mns) pankey_Log(nullptr,location,"InvokeList",method,type,mns)
	#else
		#define InvokeListLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class T>
		using invoking = obj<T>;

		template<class T>
		using InvokerList = OList<T>;

		template<class T, class... Args>
		void invoke(invoking<T> a_invoke, InvokeClassMethod<T,Args...> a_method, Args... args){
			InvokeListLog(pankey_Log_StartMethod, "invoke", "println", "");
			if(a_invoke.isNull()){
				InvokeListLog(pankey_Log_EndMethod, "invoke", "println", "i_event.isNull()");
				return;
			}
			void* i_pointer = a_invoke.getRawPointer();
			invoke<T,Args...>(*((T*)i_pointer), a_method, args...);
			InvokeListLog(pankey_Log_EndMethod, "invoke", "println", "");
		}

		template<class T, class... Args>
		void invoke(const InvokerList<T>& a_list, int a_index, InvokeClassMethod<T,Args...> a_method, Args... args){
			InvokeListLog(pankey_Log_StartMethod, "invoke", "println", "");
			invoking<T> i_event = a_list.get(a_index);
			if(i_event.isNull()){
				InvokeListLog(pankey_Log_EndMethod, "invoke", "println", "i_event.isNull()");
				return;
			}
			void* i_pointer = i_event.getRawPointer();
			invoke<T,Args...>(*((T*)i_pointer), a_method, args...);
			InvokeListLog(pankey_Log_EndMethod, "invoke", "println", "");
		}

		template<class T, class... Args>
		void invokeAll(const InvokerList<T>& a_list, InvokeClassMethod<T,Args...> a_method, Args... args){
			InvokeListLog(pankey_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_list.length(); x++){
				invoking<T> i_event = a_list.get(x);
				if(i_event.isNull()){
					InvokeListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
					return;
				}
				void* i_pointer = i_event.getRawPointer();
				invoke<T,Args...>(*((T*)i_pointer), a_method, args...);
			}
			InvokeListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
		}
/*
		template<class R, class... Args>
		R invoke(const CommandReturnList<R,Args...>& a_list, int a_index, Args... args){
			InvokeListLog(pankey_Log_StartMethod, "invoke", "println", "");
			commandReturn<R,Args...> i_event = a_list.get(a_index);
			if(i_event.isNull()){
				InvokeListLog(pankey_Log_EndMethod, "invoke", "println", "");
				return R();
			}
			InvokeListLog(pankey_Log_EndMethod, "invoke", "println", "");
			return i_event->execute(args...);
		}

		template<class R, class... Args>
		R invokeAll(const CommandReturnList<R,Args...>& a_list, Args... args){
			InvokeListLog(pankey_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_list.length(); x++){
				commandReturn<R,Args...> i_event = a_list.get(x);
				if(i_event.isNull()){
					InvokeListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
					return R();
				}
				i_event->execute(args...);
			}
			InvokeListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
		}*/
	}

#endif