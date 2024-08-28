
#ifndef InvokeCommandList_hpp
	#define InvokeCommandList_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "Command.hpp"
	#include "CommandReturn.hpp"

	#ifdef InvokeCommandList_LogApp
		#include "pankey_Logger.hpp"
		#define InvokeCommandListLog(location,method,type,mns) pankey_Log(nullptr,location,"InvokeCommandList",method,type,mns)
	#else
		#define InvokeCommandListLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class... Args>
		using command = obj<Command<Args...>>;

		template<class... Args>
		using CommandList = OList<Command<Args...>>;

		template<class... Args>
		using commandReturn = obj<CommandReturn<Args...>>;

		template<class R, class... Args>
		using CommandReturnList = OList<CommandReturn<R,Args...>>;

		template<class... Args>
		void invoke(const CommandList<Args...>& a_list, int a_index, Args... args){
			InvokeCommandListLog(pankey_Log_StartMethod, "invoke", "println", "");
			command<Args...> i_event = a_list.get(a_index);
			if(i_event.isNull()){
				InvokeCommandListLog(pankey_Log_EndMethod, "invoke", "println", "");
				return;
			}
			i_event->execute(args...);
			InvokeCommandListLog(pankey_Log_EndMethod, "invoke", "println", "");
		}

		template<class... Args>
		void invokeAll(const CommandList<Args...>& a_list, Args... args){
			InvokeCommandListLog(pankey_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_list.length(); x++){
				command<Args...> i_event = a_list.get(x);
				if(i_event.isNull()){
					InvokeCommandListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
					return;
				}
				i_event->execute(args...);
			}
			InvokeCommandListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
		}

		template<class R, class... Args>
		R invoke(const CommandReturnList<R,Args...>& a_list, int a_index, Args... args){
			InvokeCommandListLog(pankey_Log_StartMethod, "invoke", "println", "");
			commandReturn<R,Args...> i_event = a_list.get(a_index);
			if(i_event.isNull()){
				InvokeCommandListLog(pankey_Log_EndMethod, "invoke", "println", "");
				return R();
			}
			InvokeCommandListLog(pankey_Log_EndMethod, "invoke", "println", "");
			return i_event->execute(args...);
		}

		template<class R, class... Args>
		R invokeAll(const CommandReturnList<R,Args...>& a_list, Args... args){
			InvokeCommandListLog(pankey_Log_StartMethod, "invokeAll", "println", "");
			for(int x = 0; x < a_list.length(); x++){
				commandReturn<R,Args...> i_event = a_list.get(x);
				if(i_event.isNull()){
					InvokeCommandListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
					return R();
				}
				i_event->execute(args...);
			}
			InvokeCommandListLog(pankey_Log_EndMethod, "invokeAll", "println", "");
		}
	}

#endif