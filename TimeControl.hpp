
#ifndef CONFIGURATION_TimeControl_hpp
#define CONFIGURATION_TimeControl_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_TimeControl) || defined(DISABLE_TimeElapsed)
		#define TimeControl_hpp

		#define IMPLEMENTATION_TimeControl
		#define IMPLEMENTING_TimeControl
	#else
		#if defined(DISABLE_IMPLEMENTATION_TimeControl)
			#define IMPLEMENTATION_TimeControl
			#define IMPLEMENTING_TimeControl
		#endif
	#endif

#endif

#ifndef TimeControl_hpp
#define TimeControl_hpp
#define TimeControl_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_TimeControl
	#define IMPLEMENTATION_TimeControl IMPLEMENTATION(public TimeControl)
	#define IMPLEMENTING_TimeControl IMPLEMENTING(public TimeControl)
#endif

#include "cppObject.hpp"
#include "PrimitiveList.hpp"
#include "Note.hpp"

namespace ame{
	class TimeControl;
}

#include "TimeElapsed.hpp"

namespace ame{

/*
*	Class Configuration:
*	DISABLE_Application
*	DISABLE_cppObject
*	DISABLE_cppObjectClass
*	DISABLE_AbstractClass
*	DISABLE_IMPLEMENTATION_cppObject
*/
class TimeControl IMPLEMENTATION_cppObject {
    public:
		List<TimeElapsed> *timeList;
		long time=0;
		long period=0;
		
		TimeControl(){
			this->timeList = new PrimitiveList<TimeElapsed>();
		}
		
		virtual ~TimeControl(){
			delete this->timeList;
		}
		
		virtual long getTime(){
			return this->time;
		}
		
		
		virtual TimeControl* initialize(long timeperiod){
			return this;
		}
		virtual TimeControl* setPeriod(long timeperiod){
			return this;
		}
		virtual long getPeriod(){
			return this->period;
		}
		
		virtual TimeControl* attachInterrupt(){
			return this;										
		}
		virtual TimeControl* detachInterrupt(){
			return this;										
		}
		virtual TimeControl* startInterrupt(){
			return this;										
		}
		virtual TimeControl* stopInterrupt(){
			return this;										
		}
		virtual TimeControl* resumeInterrupt(){
			return this;										
		}
		
		virtual TimeElapsed *add(TimeElapsed *t){
			this->timeList->addPointer(t);
			return t;
		}
		virtual TimeElapsed *remove(TimeElapsed *t){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList->removeByPointer(t);
		}
		virtual TimeElapsed *removeByPos(int pos){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList->removeByPosition(pos);
		}
		 
		virtual List<TimeElapsed> *getTimeElapsedList(){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList;
		}
		virtual TimeElapsed *getTimeElapsed(int pos){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList->getByPosition(pos);
		}
		virtual TimeElapsed *getTimeElapsed(TimeElapsed *t){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList->getByPointer(t);
		}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){
			return Class<TimeControl>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<TimeControl>::getClass();
		}
		#endif
		
	protected:
	
};

}

#endif