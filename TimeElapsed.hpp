
#ifndef CONFIGURATION_TimeElapsed_hpp
#define CONFIGURATION_TimeElapsed_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_TimeControl) || defined(DISABLE_TimeElapsed)
		#define TimeElapsed_hpp

		#define IMPLEMENTATION_TimeElapsed
		#define IMPLEMENTING_TimeElapsed
	#else
		#if defined(DISABLE_IMPLEMENTATION_TimeElapsed)
			#define IMPLEMENTATION_TimeElapsed
			#define IMPLEMENTING_TimeElapsed
		#endif
	#endif

#endif

#ifndef TimeElapsed_hpp
#define TimeElapsed_hpp
#define TimeElapsed_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_TimeElapsed
	#define IMPLEMENTATION_TimeElapsed IMPLEMENTATION(public TimeElapsed)
	#define IMPLEMENTING_TimeElapsed IMPLEMENTING(public TimeElapsed)
#endif

namespace ame{

/*
*	Class Configuration:
*	DISABLE_cppObject
*	DISABLE_cppObjectClass
*	DISABLE_AbstractClass
*	DISABLE_IMPLEMENTATION_cppObject
*/
class TimeElapsed IMPLEMENTATION_cppObject {
    public:
		virtual ~TimeElapsed(){}

		virtual void Play(TimeControl *t){}

		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(AbstractClass_AVAILABLE)
		virtual cppObjectClass* getClass(){
			return AbstractClass<TimeElapsed>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == AbstractClass<TimeElapsed>::getClass();
		}
		#endif

		virtual void operator=(TimeElapsed a){}
		virtual bool operator==(TimeElapsed a){return true;}
		virtual bool operator!=(TimeElapsed a){return true;}
	private:	
};

}

#endif