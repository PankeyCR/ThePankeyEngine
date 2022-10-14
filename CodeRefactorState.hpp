
/*
*	Comments Annotations:
*	1. @change - the code should work but it most be inprubed
*	
*	
*/

#ifndef CodeRefactorState_hpp
#define CodeRefactorState_hpp
#define CodeRefactorState_AVAILABLE 

#include "RawPointerList.hpp"

#ifdef CodeRefactorState_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define CodeRefactorStateLog(location,method,type,mns) ame_Log(this,location,"CodeRefactorState",method,type,mns)
	#define const_CodeRefactorStateLog(location,method,type,mns)
#else
	#ifdef CodeRefactorState_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define CodeRefactorStateLog(location,method,type,mns) ame_LogDebug(this,location,"CodeRefactorState",method,type)
		#define const_CodeRefactorStateLog(location,method,type,mns)
	#else
		#define CodeRefactorStateLog(location,method,type,mns)
		#define const_CodeRefactorStateLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class T>
class CodeRefactorState{	
	public:
		CodeRefactorState(){}
		virtual ~CodeRefactorState(){}

	private:
};

}

#endif