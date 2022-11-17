
#ifndef CONFIGURATION_AppState_hpp
#define CONFIGURATION_AppState_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_Application) || defined(DISABLE_AppState)
		#define AppState_hpp

		#ifndef AppState_IMPLEMENTATION_AVAILABLE
			#define IMPLEMENTATION_AppState
			#define IMPLEMENTING_AppState
			#define AppState_IMPLEMENTATION_AVAILABLE
		#endif
	#else
		#if defined(DISABLE_IMPLEMENTATION_AppState)
			#ifndef AppState_IMPLEMENTATION_AVAILABLE
				#define IMPLEMENTATION_AppState
				#define IMPLEMENTING_AppState
				#define AppState_IMPLEMENTATION_AVAILABLE
			#endif
		#endif
	#endif
#endif

#ifndef AppState_hpp
#define AppState_hpp
#define AppState_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_AppState
	#define IMPLEMENTATION_AppState IMPLEMENTATION(public AppState)
	#define IMPLEMENTING_AppState IMPLEMENTING(public AppState)
#endif

#include "Class.hpp"

namespace ame{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTATION_cppObject
*/
class AppState IMPLEMENTATION_cppObject {
    public:
		virtual ~AppState(){}

		#if defined(Application_AVAILABLE)
		virtual void initialize(Application *app){
			this->initializeState(app);
			this->initializeState();
		}
		virtual void initializeState(Application* app){}
		#endif

		virtual void initializeState(){}
		virtual bool hasInitialize(){return false;}
		virtual void onEnable(){}
		virtual void onDisable(){}
		virtual void setId(Note i){this->id = i;}
		virtual Note getId(){return id;}
		virtual void update(float tpc){
			this->updateState(tpc);
		}
		virtual void updateState(float tpc){}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<AppState>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<AppState>::getClass() || cppObject::instanceof(cls);
		}
		#endif
		
		virtual void operator=(AppState b){}
		virtual bool operator==(AppState b){return false;}
		virtual bool operator!=(AppState b){return true;}
		
	protected:
		Note id = "";
};

}

#endif
