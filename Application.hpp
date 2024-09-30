
#ifndef Application_hpp
	#define Application_hpp

	#include "pankey.hpp"

	// #include "RenderManager.hpp"
	#include "EventManager.hpp"
	#include "LoopManager.hpp"
	#include "DefaultAppSettings.hpp"
	// #include "TimeControl.hpp"

	#ifdef Application_LogApp
		#include "pankey_Logger.hpp"
		#define ApplicationLog(location,method,type,mns) pankey_Log((void*)this,location,"Application",method,type,mns)
	#else
		#define ApplicationLog(location,method,type,mns) 
	#endif

	namespace pankey{
		
		class Application{
			public:
				Application(){
  					createEngineManager();
				}
				virtual ~Application(){}

				virtual EventManager<Application>& getEventManager(){
					return this->m_events;
				}

				virtual LoopManager<Application>& getStateManager(){
					return this->m_states;
				}

				virtual AppSettings& getSettings(){
					return this->m_settings;
				}

				// virtual Object<ThreadControl,O,H,A> getTimeControl(){
				// 	return this->m_timer;
				// }


				virtual void run(Note a_name){
					auto& i_events = this->getEventManager();
					i_events.run(a_name, *this);
				}

				virtual void runMethod(Note a_name){
					auto& i_events = this->getEventManager();
					i_events.runMethod(a_name);
				}

				virtual void runAppMethod(Note a_name){
					auto& i_events = this->getEventManager();
					i_events.runAppMethod(a_name, *this);
				}

				virtual void initialize(){
					this->m_states.initialize(*this);
				}

				virtual float update(){
					ApplicationLog(pankey_Log_StartMethod, "update", "println", "");
					float i_tpc = this->generateTpc();

					this->m_states.update(*this, i_tpc);

					ApplicationLog(pankey_Log_EndMethod, "update", "println", "");
					return i_tpc;
				}
				
				virtual float tpc(){
					return m_tpc;
				}

				virtual float generateTpc(){
					this->m_now = System::microSeconds();

					this->m_tpc = (float)(this->m_now - this->m_prev)/1000000;
					this->m_prev = this->m_now;

					return this->m_tpc;
				}

			protected:
				EventManager<Application> m_events;
				LoopManager<Application> m_states;
				DefaultAppSettings m_settings;
				// TimeControl* m_timer = nullptr;

				long m_now = 0;
				long m_prev = 0;
				float m_tpc = 0;
		};
		
		using AppManager = LoopManager<Application>;
		using appstate = app_state<Application,float>;

	}

#endif
