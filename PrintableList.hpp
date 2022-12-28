
#ifndef PrintableList_hpp
#define PrintableList_hpp
#define PrintableList_AVAILABLE

#include "cppObject.hpp"
#include "Class.hpp"

#ifdef PrintableList_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define PrintableListLog(location,method,type,mns) ame_Log(this,location,"PrintableList",method,type,mns)
	#define const_PrintableListLog(location,method,type,mns)
#else
	#ifdef PrintableList_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define PrintableListLog(location,method,type,mns) ame_LogDebug(this,location,"PrintableList",method,type)
		#define const_PrintableListLog(location,method,type,mns)
	#else
		#define PrintableListLog(location,method,type,mns)
		#define const_PrintableListLog(location,method,type,mns)
	#endif
#endif

namespace ame{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTING_cppObject
*/
template <class T>
class PrintableList : public T {	
	public:
	PrintableList(){}
	virtual ~PrintableList(){}
	
	private:
};

}

#endif