
#ifndef higgs_Logger_hpp
	#define higgs_Logger_hpp
	
	#include "higgs_Logger_position.hpp"

	#ifndef higgs_Log_Module
		#define higgs_Log_Module(pointer,location,name,method,type,mns) 
	#endif

	#ifndef higgs_LogDebug
		#define higgs_LogDebug(pointer,location,name,method,type) 
	#endif

	#ifndef higgs_Debuging
		#define higgs_Debuging(location,method) higgs_LogDebug(nullptr,location,"raw",method,"println")
	#endif

	#ifndef higgs_ClassDebuging
		#define higgs_ClassDebuging(location,name,method) higgs_LogDebug(nullptr,location,name,method,"println")
	#endif
	
	#ifdef higgs_LogApp
		#ifdef higgs_LogPrint
			#include "higgs_String.hpp"
			#include "System.hpp"

			namespace higgs{
			
				template<class T>
				void LogPrint_(void* a_log_pointer, int location, const higgs_String& name, const higgs_String& method, const higgs_String& type, T mns){
					higgs_Log_Module(a_log_pointer, location, name, method, type, mns);

					higgs_LogDebug(a_log_pointer, location, name, method, type);
				}

				#ifndef higgs_Log
					#define higgs_Log(pointer,location,name,method,type,mns) LogPrint_(pointer,location,name,method,type,mns)
				#endif
			
			}
		#else
			#ifndef higgs_Log
				#define higgs_Log(pointer,location,name,method,type,mns) 
			#endif
		#endif
		
	#else
		
		#ifndef higgs_Log
			#define higgs_Log(pointer,location,name,method,type,mns) 
		#endif
		
	#endif

	#define higgs_Loging(location,method) higgs_Log(nullptr,location,"raw",method,"println","Loging Event") 
	#define higgs_Loger(location,method,mns) higgs_Log(nullptr,location,"raw",method,"println",mns) 

	#define higgs_ClassLoging(location,name,method) higgs_Log(nullptr,location,name,method,"println","Loging Event") 

#endif 

