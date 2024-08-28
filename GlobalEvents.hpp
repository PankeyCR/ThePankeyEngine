
#ifndef GlobalEvents_hpp
	#define GlobalEvents_hpp

	#include "InvokeRawMap.hpp"

	#ifdef GlobalEvents_LogApp
		#include "ame_Logger.hpp"
		#define GlobalEventsLog(location,method,type,mns) ame_Log((void*)this,location,"GlobalEvents",method,type,mns)
	#else
		#define GlobalEventsLog(location,method,type,mns) 
	#endif

	namespace pankey{

		template<class K, class... Args>
		struct GlobalEvents{
			static MethodMap<K,Args...> g_global_events;

			static void put(K a_key, InvokeMethod<Args...> a_method){
				g_global_events.put(a_key, a_method);
			}

			static void change(K a_key, InvokeMethod<Args...> a_method){
				g_global_events.remove(a_key);
				g_global_events.add(a_key, a_method);
			}

			static void remove(K a_key){
				g_global_events.removeUpdateFunctionMap(a_key);
			}

			static void removeAll(){
				g_global_events.resetDelete();
			}

			static void run(K a_key, Args... a_parameters){
				invoke<K,Args...>(g_global_events, a_key, a_parameters...);
			}

			static void runAll(Args... a_parameters){
				invokeAll<K,Args...>(g_global_events, a_parameters...);
			}
		};

		template<class K, class... Args> MethodMap<K,Args...> GlobalEvents<K,Args...>::g_global_events;

	}

#endif
