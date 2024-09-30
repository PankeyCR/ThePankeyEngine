
#ifndef pankey_Logger_hpp
	#define pankey_Logger_hpp
	
	#include "pankey_Logger_position.hpp"

	#if !defined(pankey_Log_Module) || !defined(pankey_Log_Split_Module) || !defined(pankey_Log_Start_Module) || !defined(pankey_Log_Stop_Module)
		#include "pankey_Simple_Logger.hpp"
		#define pankey_Log_Module(pointer,location,name,method,type,mns) Simple_LogPrint_(pointer,location,name,method,type,mns)
		#define pankey_Log_Split_Modulo(tittle) Simple_LogSplitPrint_(tittle)
		#define pankey_Log_Start_Module(tittle) Simple_LogStartPrint_(tittle)
		#define pankey_Log_Stop_Module(tittle) Simple_LogStopPrint_(tittle)
	#endif

	#ifndef pankey_Log_Module
		#define pankey_Log_Module(pointer,location,name,method,type,mns) 
	#endif

	#ifndef pankey_Log_Split_Module
		#define pankey_Log_Split_Module(tittle) 
	#endif

	#ifndef pankey_Log_Start_Module
		#define pankey_Log_Start_Module(tittle) 
	#endif

	#ifndef pankey_Log_Stop_Module
		#define pankey_Log_Stop_Module(tittle) 
	#endif

	#ifndef pankey_LogDebug
		#define pankey_LogDebug(pointer,location,name,method,type) 
	#endif

	#ifndef pankey_Debuging
		#define pankey_Debuging(location,method) pankey_LogDebug(nullptr,location,"raw",method,"println")
	#endif

	#ifndef pankey_ClassDebuging
		#define pankey_ClassDebuging(location,name,method) pankey_LogDebug(nullptr,location,name,method,"println")
	#endif
	
	#ifdef pankey_LogApp
		#ifdef pankey_LogPrint
			#include "pankey_String.hpp"

			namespace pankey{
			
				template<class T>
				void LogPrint_(void* a_log_pointer, int location, const pankey_String& name, const pankey_String& method, const pankey_String& type, T mns){
					pankey_Log_Module(a_log_pointer, location, name, method, type, mns);

					pankey_LogDebug(a_log_pointer, location, name, method, type);
				}

				#ifndef pankey_Log
					#define pankey_Log(pointer,location,name,method,type,mns) LogPrint_(pointer,location,name,method,type,mns)
				#endif
			
				template<class T>
				void LogSplitPrint_(T a_tittle){
					pankey_Log_Split_Module(a_tittle);
				}

				#ifndef pankey_Log_Split
					#define pankey_Log_Split(tittle) LogSplitPrint_(tittle)
				#endif
			
				template<class T>
				void LogStartPrint_(T a_tittle){
					pankey_Log_Start_Module(a_tittle);
				}

				#ifndef pankey_Log_Start
					#define pankey_Log_Start(tittle) LogStartPrint_(tittle)
				#endif
			
				template<class T>
				void LogStopPrint_(T a_tittle){
					pankey_Log_Stop_Module(a_tittle);
				}

				#ifndef pankey_Log_Stop
					#define pankey_Log_Stop(tittle) LogStopPrint_(tittle)
				#endif
			
			}
		#else
			#ifndef pankey_Log
				#define pankey_Log(pointer,location,name,method,type,mns) 
			#endif
			#ifndef pankey_Log_Split
				#define pankey_Log_Split(tittle) 
			#endif
			#ifndef pankey_Log_Start
				#define pankey_Log_Start(tittle) 
			#endif
			#ifndef pankey_Log_Stop
				#define pankey_Log_Stop(tittle) 
			#endif
		#endif
		
	#else
		
		#ifndef pankey_Log
			#define pankey_Log(pointer,location,name,method,type,mns) 
		#endif
		#ifndef pankey_Log_Split
			#define pankey_Log_Split(tittle) 
		#endif
		#ifndef pankey_Log_Start
			#define pankey_Log_Start(tittle) 
		#endif
		#ifndef pankey_Log_Stop
			#define pankey_Log_Stop(tittle) 
		#endif
		
	#endif

	#define pankey_Loging(location,method) pankey_Log(nullptr,location,"raw",method,"println","Loging Event") 
	#define pankey_Loger(location,method,mns) pankey_Log(nullptr,location,"raw",method,"println",mns) 

	#define pankey_ClassLoging(location,name,method) pankey_Log(nullptr,location,name,method,"println","Loging Event") 

#endif 

