
#ifndef RawPointerManager_hpp
#define RawPointerManager_hpp
#define RawPointerManager_AVAILABLE

#ifdef RawPointerManager_LogApp
	#include "pankey_Logger_config.hpp"
	#include "pankey_Logger.hpp"

	#define RawPointerManagerLog(location,method,type,mns) pankey_Log(this,location,"RawPointerManager",method,type,mns)
#else
	#ifdef RawPointerManager_LogDebugApp
		#include "pankey_Logger_config.hpp"
		#include "pankey_Logger.hpp"

		#define RawPointerManagerLog(location,method,type,mns) pankey_LogDebug(this,location,"RawPointerManager",method,type)
	#else
		#define RawPointerManagerLog(location,method,type,mns)
	#endif
#endif

namespace pankey{

class RawPointerManager{
	public:
		RawPointerManager(){
			RawPointerManagerLog(pankey_Log_StartMethod, "Contructor", "println","");
			RawPointerManagerLog(pankey_Log_EndMethod, "Contructor", "println","");
		}
		virtual ~RawPointerManager(){
			RawPointerManagerLog(pankey_Log_StartMethod, "Destructor", "println","");
			RawPointerManagerLog(pankey_Log_EndMethod, "Destructor", "println","");
		}

		virtual void addPointer(){
			RawPointerManagerLog(pankey_Log_StartMethod, "addPointer", "println","");
			m_count++;
			RawPointerManagerLog(pankey_Log_EndMethod, "addPointer", "println","");
		}

		virtual void removePointer(void* a_memory){
			RawPointerManagerLog(pankey_Log_StartMethod, "removePointer", "println","");
			if(a_memory == nullptr){
				RawPointerManagerLog(pankey_Log_EndMethod, "removePointer", "println","a_memory == nullptr");
				return;
			}
			m_count--;
			if(m_count == 0){
				free(a_memory);
			}
			RawPointerManagerLog(pankey_Log_EndMethod, "removePointer", "println","");
		}
		virtual int getReferenceCount(){return m_count;}

		virtual void reset(){
			RawPointerManagerLog(pankey_Log_StartMethod, "reset", "println","");
			m_count = 0;
			RawPointerManagerLog(pankey_Log_EndMethod, "reset", "println","");
		}

		virtual bool isReferenced(){
			RawPointerManagerLog(pankey_Log_StartMethod, "isReferenced", "println","");
			RawPointerManagerLog(pankey_Log_Statement, "isReferenced", "println","Reference Count: ");
			RawPointerManagerLog(pankey_Log_Statement, "isReferenced", "println",m_count);
			RawPointerManagerLog(pankey_Log_EndMethod, "isReferenced", "println","");
			return m_count > 0;
		}

	protected:
		int m_count = 0;
};

}

#endif