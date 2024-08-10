
#ifndef StaticManagerInstance_hpp
	#define StaticManagerInstance_hpp

    #include "MemoryManager.hpp"

    #ifdef StaticManagerInstance_LogApp
        #include "higgs_Logger.hpp"
        #define StaticManagerInstanceLog(location,method,type,mns) higgs_Log(nullptr,location,"StaticManagerInstance",method,type,mns)
    #else
        #define StaticManagerInstanceLog(location,method,type,mns)
    #endif

	namespace higgs{

        template<class H, class M>
        struct StaticManagerInstance{
            static MemoryManager<H>* m_Manager;

			static MemoryManager<H>* getManager(){
				StaticManagerInstanceLog(higgs_Log_StartMethod, "getManager", "println","");
				StaticManagerInstanceLog(higgs_Log_Statement, "getManager", "println", m_Manager == nullptr);
				StaticManagerInstanceLog(higgs_Log_EndMethod, "getManager", "println","");
				return m_Manager;
			}
        };

        template<class H, class M>
        MemoryManager<H>* StaticManagerInstance<H,M>::m_Manager = nullptr;

		template<class H, class M, class HA>
		void createManager(){
			StaticManagerInstanceLog(higgs_Log_StartMethod, "createManager", "println","");
			MemoryManager<H>* i_Manager = StaticManagerInstance<H,M>::m_Manager;
			if(i_Manager != nullptr){
				StaticManagerInstanceLog(higgs_Log_EndMethod, "createManager", "println","i_Manager != nullptr");
				return;
			}
			StaticManagerInstance<H,M>::m_Manager = new HA();
			StaticManagerInstanceLog(higgs_Log_EndMethod, "createManager", "println","");
		}    
	}

#endif