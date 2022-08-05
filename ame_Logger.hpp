
#ifndef ame_Logger_hpp
#define ame_Logger_hpp

#ifndef ame_LogDebug
	#define ame_LogDebug(pointer,location,name,method,type) 
#endif

#ifndef ame_Debuging
	#define ame_Debuging(location,method) ame_LogDebug(nullptr,location,"raw",method,"println")
#endif

#ifndef ame_ClassDebuging
	#define ame_ClassDebuging(location,name,method) ame_LogDebug(nullptr,location,name,method,"println")
#endif
  
#ifdef ame_LogApp
	#ifdef ame_LogPrint
		#include "ame_Logger_config.hpp"
		#include "ame_String.hpp"
		#include "System.hpp"

		namespace ame{
		  
			template<class T>
			void LogPrint_(void* a_log_pointer, int location, const ame_String& name, const ame_String& method, const ame_String& type, T mns){
			
				#ifdef ame_SystemFullLog
				   System::print("Loggin class: ");
				   System::print(name);
				   System::print(" - Method: ");
				   System::print(method);
				   System::print(" - Location: ");
				   System::print(location);
				   System::print(" - Log: ");
				   System::println(mns);
				#elif defined(ame_Arduino_Log)
				   Serial.print("Loggin class: ");
				   Serial.print(name);
				   Serial.print(" - Method: ");
				   Serial.print(method);
				   Serial.print(" - Location: ");
				   Serial.print(location);
				   Serial.print(" - Log: ");
				   Serial.println(mns);
				#endif

				ame_LogDebug(a_log_pointer, location, name, method, type);
			}
		  
		}

		#ifndef ame_Log
			#define ame_Log(pointer,location,name,method,type,mns) LogPrint_(pointer,location,name,method,type,mns)
		#endif
	#else
		#ifndef ame_Log
			#define ame_Log(pointer,location,name,method,type,mns) 
		#endif
	#endif
	
#else
	
	#ifndef ame_Log
		#define ame_Log(pointer,location,name,method,type,mns) 
	#endif
	
#endif

#endif 

