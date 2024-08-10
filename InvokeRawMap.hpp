
#ifndef InvokeRawMap_hpp
	#define InvokeRawMap_hpp

	#include "PrimitiveRawMap.hpp"
	#include "InvokeMethod.hpp"

	#ifdef InvokeRawMap_LogApp
		#include "higgs_Logger.hpp"
		#define InvokeRawMapLog(location,method,type,mns) higgs_Log(nullptr,location,"InvokeRawMap",method,type,mns)
	#else
		#define InvokeRawMapLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class K, class... Args>
		using MethodMap = PrimitiveRawMap<K,InvokeMethod<Args...>>;

		template<class K, class R, class... Args>
		using MethodReturnMap = PrimitiveRawMap<K,InvokeMethodReturn<R,Args...>>;

		template<class T, class K, class... Args>
		using ClassMethodMap = PrimitiveRawMap<K,InvokeClassMethod<T,Args...>>;

		template<class T, class K, class R, class... Args>
		using ClassMethodReturnMap = PrimitiveRawMap<K,InvokeClassMethodReturn<T,R,Args...>>;

		template<class K, class... Args>
		void invoke(const RawMap<K,InvokeMethod<Args...>>& a_map, K a_key, Args... args){
			InvokeRawMapLog(higgs_Log_StartMethod, "invoke", "println", "");
			auto i_event = a_map.getValueByLValue(a_key);
			if(i_event == nullptr){
				InvokeRawMapLog(higgs_Log_EndMethod, "invoke", "println", "");
				return;
			}
			(**i_event)(args...);
			InvokeRawMapLog(higgs_Log_EndMethod, "invoke", "println", "");
		}

		template<class K, class... Args>
		void invokeAll(const RawMap<K,InvokeMethod<Args...>>& a_map, Args... args){
			InvokeRawMapLog(higgs_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_map.getPosition(); x++){
				auto i_event = a_map.getValueByPosition(x);
				if(i_event == nullptr){
					InvokeRawMapLog(higgs_Log_EndMethod, "invokeAll", "println", "");
					return;
				}
				(**i_event)(args...);
			}
			InvokeRawMapLog(higgs_Log_EndMethod, "invokeAll", "println", "");
		}

		template<class T, class K, class... Args>
		void invoke(const RawMap<K,InvokeClassMethod<T,Args...>>& a_map, T& a_instance, K a_key, Args... args){
			InvokeRawMapLog(higgs_Log_StartMethod, "invoke", "println", "");
			auto i_event = a_map.getValueByLValue(a_key);
			if(i_event == nullptr){
				InvokeRawMapLog(higgs_Log_EndMethod, "invoke", "println", "");
				return;
			}
			T* i_instance = &a_instance;
			(i_instance->**i_event)(args...);
			InvokeRawMapLog(higgs_Log_EndMethod, "invoke", "println", "");
		}

		template<class T, class K, class... Args>
		void invokeAll(const RawMap<K,InvokeClassMethod<T,Args...>>& a_map, T& a_instance, Args... args){
			InvokeRawMapLog(higgs_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_map.getPosition(); x++){
				auto i_event = a_map.getValueByPosition(x);
				if(i_event == nullptr){
					InvokeRawMapLog(higgs_Log_EndMethod, "invokeAll", "println", "");
					return;
				}
				T* i_instance = &a_instance;
				(i_instance->**i_event)(args...);
			}
			InvokeRawMapLog(higgs_Log_EndMethod, "invokeAll", "println", "");
		}

		template<class K, class R, class... Args>
		R invoke(const RawMap<K,InvokeMethodReturn<R,Args...>>& a_map, K a_key, Args... args){
			InvokeRawMapLog(higgs_Log_StartMethod, "invoke", "println", "");
			auto i_event = a_map.getValueByLValue(a_key);
			if(i_event == nullptr){
				InvokeRawMapLog(higgs_Log_EndMethod, "invoke", "println", "");
				return R();
			}
			InvokeRawMapLog(higgs_Log_EndMethod, "invoke", "println", "");
			return (**i_event)(args...);
		}

		template<class K, class R, class... Args>
		void invokeAll(const RawMap<K,InvokeMethodReturn<R,Args...>>& a_map, Args... args){
			InvokeRawMapLog(higgs_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_map.getPosition(); x++){
				InvokeRawMapLog(higgs_Log_Statement, "invokeAll", "println", "loop index:");
				InvokeRawMapLog(higgs_Log_Statement, "invokeAll", "println", x);
				auto i_event = a_map.getValueByPosition(x);
				if(i_event == nullptr){
					InvokeRawMapLog(higgs_Log_EndMethod, "invokeAll", "println", "");
					continue;
				}
				(**i_event)(args...);
			}
			InvokeRawMapLog(higgs_Log_EndMethod, "invokeAll", "println", "");
		}

		template<class T, class K, class R, class... Args>
		R invoke(const RawMap<K,InvokeClassMethodReturn<T,R,Args...>>& a_map, T& a_instance, K a_key, Args... args){
			InvokeRawMapLog(higgs_Log_StartMethod, "invoke", "println", "");
			auto i_event = a_map.getValueByLValue(a_key);
			if(i_event == nullptr){
				InvokeRawMapLog(higgs_Log_EndMethod, "invoke", "println", "");
				return R();
			}
			T* i_instance = &a_instance;
			InvokeRawMapLog(higgs_Log_EndMethod, "invoke", "println", "");
			return (i_instance->**i_event)(args...);
		}

		template<class T, class K, class R, class... Args>
		void invokeAll(const RawMap<K,InvokeClassMethodReturn<T,R,Args...>>& a_map, T& a_instance, Args... args){
			InvokeRawMapLog(higgs_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_map.getPosition(); x++){
				auto i_event = a_map.getValueByPosition(x);
				if(i_event == nullptr){
					InvokeRawMapLog(higgs_Log_EndMethod, "invokeAll", "println", "");
					return;
				}
				T* i_instance = &a_instance;
				(i_instance->**i_event)(args...);
			}
			InvokeRawMapLog(higgs_Log_EndMethod, "invokeAll", "println", "");
		}

	}

#endif