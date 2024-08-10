
#ifndef RawPointer_hpp
#define RawPointer_hpp
#define RawPointer_AVAILABLE

#include "RawPointerManager.hpp"

#ifdef RawPointer_LogApp
	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"

	#define RawPointerLog(location,method,type,mns) higgs_Log(this,location,"RawPointer",method,type,mns)
#else
	#ifdef RawPointer_LogDebugApp
		#include "higgs_Logger_config.hpp"
		#include "higgs_Logger.hpp"

		#define RawPointerLog(location,method,type,mns) higgs_LogDebug(this,location,"RawPointer",method,type)
	#else
		#define RawPointerLog(location,method,type,mns)
	#endif
#endif

namespace higgs{

class RawPointer{
	public:
		RawPointer(){
			RawPointerLog(higgs_Log_StartMethod, "Contructor", "println","");
			RawPointerLog(higgs_Log_EndMethod, "Contructor", "println","");
		}

		RawPointer(void* a_raw_pointer){
			RawPointerLog(higgs_Log_StartMethod, "Contructor", "println","void* a_raw_pointer");
			m_pointer = a_raw_pointer;
			m_manager = new RawPointerManager();
			m_manager->addPointer();
			RawPointerLog(higgs_Log_EndMethod, "Contructor", "println","void* a_raw_pointer");
		}

		RawPointer(void* a_raw_pointer, RawPointerManager* a_raw_manager){
			RawPointerLog(higgs_Log_StartMethod, "Contructor", "println","void* a_raw_pointer, RawPointerManager* a_raw_manager");
			m_pointer = a_raw_pointer;
			m_manager = a_raw_manager;
			if(m_manager != nullptr){
				m_manager->addPointer();
			}
			RawPointerLog(higgs_Log_EndMethod, "Contructor", "println","void* a_raw_pointer, RawPointerManager* a_raw_manager");
		}

		RawPointer(const RawPointer& a_raw_pointer){
			RawPointerLog(higgs_Log_StartMethod, "Contructor", "println","const RawPointer& a_raw_pointer");
			m_pointer = a_raw_pointer.m_pointer;
			m_manager = a_raw_pointer.m_manager;
			if(m_manager != nullptr){
				m_manager->addPointer();
			}
			RawPointerLog(higgs_Log_EndMethod, "Contructor", "println","const RawPointer& a_raw_pointer");
		}

		RawPointer(RawPointer&& a_raw_pointer){
			RawPointerLog(higgs_Log_StartMethod, "Contructor", "println","RawPointer&& a_raw_pointer");
			m_pointer = a_raw_pointer.m_pointer;
			m_manager = a_raw_pointer.m_manager;
			a_raw_pointer.m_pointer = nullptr;
			a_raw_pointer.m_manager = nullptr;
			RawPointerLog(higgs_Log_EndMethod, "Contructor", "println","RawPointer&& a_raw_pointer");
		}

		virtual ~RawPointer(){
			RawPointerLog(higgs_Log_StartMethod, "Destructor", "println","");
			if(m_manager == nullptr){
				free(m_pointer);
			}else{
				if(m_pointer != nullptr){
					m_manager->removePointer(m_pointer);
				}
				if(!m_manager->isReferenced()){
					delete m_manager;
				}
			}
			RawPointerLog(higgs_Log_EndMethod, "Destructor", "println","");
		}

		virtual void* getMemory(){
			RawPointerLog(higgs_Log_StartMethod, "getMemory", "println","");
			RawPointerLog(higgs_Log_EndMethod, "getMemory", "println","");
			return m_pointer;
		}

		virtual bool canCast(size_t a_size){
			RawPointerLog(higgs_Log_StartMethod, "canCast", "println","");
			RawPointerLog(higgs_Log_EndMethod, "canCast", "println","");
			return true;
		}

		template<class C>
		C cast(){
			RawPointerLog(higgs_Log_StartMethod, "cast", "println","");
			RawPointerLog(higgs_Log_EndMethod, "cast", "println","");
			if(m_pointer == nullptr){
				return C();
			}
			if(!this->canCast(sizeof(C))){
				return C();
			}
			return *((C*)m_pointer);
		}

		virtual void operator=(const RawPointer& a_raw_pointer){
			RawPointerLog(higgs_Log_StartMethod, "operator=", "println","");
			if(m_pointer == a_raw_pointer.m_pointer && m_manager == a_raw_pointer.m_manager){
				RawPointerLog(higgs_Log_EndMethod, "operator=", "println","");
				return;
			}
			if(m_manager == nullptr){
				free(m_pointer);
			}else{
				m_manager->removePointer(m_pointer);
				if(!m_manager->isReferenced()){
					delete m_manager;
				}
			}
			m_pointer = a_raw_pointer.m_pointer;
			m_manager = a_raw_pointer.m_manager;
			if(m_manager != nullptr){
				m_manager->addPointer();
			}
			RawPointerLog(higgs_Log_EndMethod, "operator=", "println","");
		}

		virtual bool operator==(const RawPointer& a_raw_pointer){
			RawPointerLog(higgs_Log_StartMethod, "operator==", "println","");
			if(m_pointer == a_raw_pointer.m_pointer && m_manager == a_raw_pointer.m_manager){
				RawPointerLog(higgs_Log_EndMethod, "operator==", "println","");
				return true;
			}
			RawPointerLog(higgs_Log_EndMethod, "operator==", "println","");
			return false;
		}

		virtual bool operator!=(const RawPointer& a_raw_pointer){
			if(m_pointer == a_raw_pointer.m_pointer && m_manager == a_raw_pointer.m_manager){
				RawPointerLog(higgs_Log_EndMethod, "operator!=", "println","");
				return false;
			}
			RawPointerLog(higgs_Log_EndMethod, "operator!=", "println","");
			return true;
		}

		virtual void addObject(){m_count++;}
		virtual void removeObject(){m_count--;}
		virtual int getReferenceCount(){return m_count;}
		virtual bool isReferenced(){return m_count > 0;}

	protected:
		int m_count = 0;
		void* m_pointer = nullptr;
		RawPointerManager* m_manager = nullptr;
};

}

#endif