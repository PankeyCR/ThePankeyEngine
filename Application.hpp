
#ifndef Application_hpp
#define Application_hpp
#define Application_AVAILABLE

#include "cppObject.hpp"

namespace ame{
	class Application;
}

#include "RenderManager.hpp"
#include "AppStateManager.hpp"
#include "AppSettings.hpp"
#include "TimeControl.hpp"
#include "AbstractClass.hpp"

namespace ame{

class Application : public cppObject{
    public:
		virtual ~Application(){}

		virtual RenderManager* setRenderManager(RenderManager* r_manager){
			if(r_manager == nullptr){
				return this->m_render;
			}
			if(this->m_render != r_manager){
				if(this->m_render != nullptr){
					delete this->m_render;
				}
			}
			this->m_render = r_manager;
			return this->m_render;
		}

		virtual RenderManager* getRenderManager(){
			return this->m_render;
		}

		virtual AppStateManager* setStateManager(AppStateManager* a_appstate){
			if(a_appstate == nullptr){
				return this->m_states;
			}
			if(this->m_states != a_appstate){
				if(this->m_states != nullptr){
					delete this->m_states;
				}
			}
			this->m_states = a_appstate;
			return this->m_states;
		}

		virtual AppStateManager* getStateManager(){
			return this->m_states;
		}

		virtual AppSettings* setSettings(AppSettings* a_setting){
			if(a_setting == nullptr){
				return this->m_settings;
			}
			if(this->m_settings != a_setting){
				if(this->m_settings != nullptr){
					delete this->m_settings;
				}
			}
			this->m_settings = a_setting;
			return this->m_settings;
		}

		virtual AppSettings* getSettings(){
			return this->m_settings;
		}

		virtual TimeControl* setTimeControl(TimeControl* a_timecontrol){
			if(a_timecontrol == nullptr){
				return this->m_timer;
			}
			if(this->m_timer != a_timecontrol){
				if(this->m_timer != nullptr){
					delete this->m_timer;
				}
			}
			this->m_timer = a_timecontrol;
			return this->m_timer;
		}

		virtual TimeControl *getTimeControl(){
			return this->m_timer;
		}

		virtual MemoryPool* setMemoryPool(MemoryPool* a_memory){
			if(a_memory == nullptr){
				return this->m_memory;
			}
			if(this->m_memory != a_memory){
				if(this->m_memory != nullptr){
					delete this->m_memory;
				}
			}
			this->m_memory = a_memory;
			return this->m_memory;
		}

		virtual MemoryPool* getMemoryPool(){
			return this->m_memory;
		}


		virtual void initialize(){}

		virtual void update()=0;

		//cppObject part
		virtual cppObjectClass* getClass(){
			return AbstractClass<Application>::classType;
		}

		virtual bool instanceof(cppObjectClass* cls){
			return cls == AbstractClass<Application>::classType;
		}

	protected:
		RenderManager* m_render = nullptr;
		AppStateManager* m_states = nullptr;
		AppSettings* m_settings = nullptr;
		TimeControl* m_timer = nullptr;
		MemoryPool* m_memory = nullptr;
};

}

#endif
