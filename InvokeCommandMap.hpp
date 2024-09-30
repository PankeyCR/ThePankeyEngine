
#ifndef InvokeCommandMap_hpp
	#define InvokeCommandMap_hpp
	
	#include "pankey.hpp"

	#include "Command.hpp"
	#include "CommandReturn.hpp"

	#ifdef InvokeCommandMap_LogApp
		#include "pankey_Logger.hpp"
		#define InvokeCommandMapLog(location,method,type,mns) pankey_Log(nullptr,location,"InvokeCommandMap",method,type,mns)
	#else
		#define InvokeCommandMapLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class K, class... Args>
		using CommandMap = Map;

		template<class K, class R, class... Args>
		using CommandReturnMap = OList<CommandReturn<R,Args...>>;

		template<class K, class... Args>
		void invoke(const CommandMap<K,Args...>& a_map, int a_index, Args... args){
			InvokeCommandMapLog(pankey_Log_StartMethod, "invoke", "println", "");
			command<Args...> i_event = a_map.getValue(a_index);
			if(i_event.isNull()){
				InvokeCommandMapLog(pankey_Log_EndMethod, "invoke", "println", "");
				return;
			}
			i_event->execute(args...);
			InvokeCommandMapLog(pankey_Log_EndMethod, "invoke", "println", "");
		}
/*
		template<class... Args>
		void invokeAll(const CommandList<Args...>& a_list, Args... args){
			InvokeCommandMapLog(pankey_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_list.length(); x++){
				command<Args...> i_event = a_list.get(x);
				if(i_event.isNull()){
					InvokeCommandMapLog(pankey_Log_EndMethod, "invokeAll", "println", "");
					return;
				}
				i_event->execute(args...);
			}
			InvokeCommandMapLog(pankey_Log_EndMethod, "invokeAll", "println", "");
		}

		template<class R, class... Args>
		R invoke(const CommandReturnList<R,Args...>& a_list, int a_index, Args... args){
			InvokeCommandMapLog(pankey_Log_StartMethod, "invoke", "println", "");
			commandReturn<R,Args...> i_event = a_list.get(a_index);
			if(i_event.isNull()){
				InvokeCommandMapLog(pankey_Log_EndMethod, "invoke", "println", "");
				return R();
			}
			InvokeCommandMapLog(pankey_Log_EndMethod, "invoke", "println", "");
			return i_event->execute(args...);
		}

		template<class R, class... Args>
		R invokeAll(const CommandReturnList<R,Args...>& a_list, Args... args){
			InvokeCommandMapLog(pankey_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_list.length(); x++){
				commandReturn<R,Args...> i_event = a_list.get(x);
				if(i_event.isNull()){
					InvokeCommandMapLog(pankey_Log_EndMethod, "invokeAll", "println", "");
					return R();
				}
				i_event->execute(args...);
			}
			InvokeCommandMapLog(pankey_Log_EndMethod, "invokeAll", "println", "");
		}*/
	}

#endif