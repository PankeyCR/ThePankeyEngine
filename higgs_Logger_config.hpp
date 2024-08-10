
#ifndef higgs_Logger_config_hpp
#define higgs_Logger_config_hpp

#ifndef higgs_Log_Module
	#include "higgs_Simple_Logger.hpp"
	#define higgs_Log_Module(pointer,location,name,method,type,mns) Simple_LogPrint_(pointer,location,name,method,type,mns)

	// #include "higgs_Method_Stack_Logger.hpp"
	// #define higgs_Log_Module(pointer,location,name,method,type,mns) Stack_LogPrint_(pointer,location,name,method,type,mns)
	
	// #include "higgs_List_Logger.hpp"
	// #define higgs_Log_Module(pointer,location,name,method,type,mns) List_LogPrint_(pointer,location,name,method,type,mns)
#endif

//   addClassToLog("Note");
//   addClassMethodToLog("insertLocalArrayPointer");


#ifndef higgs_LogDebug
	#include "higgs_debug.hpp"
	#define higgs_LogDebug(pointer,location,name,method,type) debug(pointer,location,name,method,type)
#endif

// #ifndef higgs_LogDebug
// 	#include "higgs_list_debug.hpp"
// 	#define higgs_LogDebug(pointer,location,name,method,type) list_debug(pointer,location,name,method,type)
// #endif


namespace higgs{

void higgsLoggerConfig(){
	// addClassToLog("Reflection");
	// addClassToLog("Note");
	// addClassToLog("Array");
	// addClassMethodToLog("addFunction");
	// addClassMethodToLog("invokeFunction");
	// addClassMethodToLog("getFunctionClass");
	// addClassMethodToLog("clonePointer");
	// addClassMethodToLog("copyExternEndValue");
	// addClassMethodToLog("endValue");
	// addClassMethodToLog("insertLocalArrayPointer");

    // addStackChecker(stackName("Reflection", "addFunction"));
    // addStackChecker(stackName("Array", "clonePointer"));
    // addStackChecker(stackName("Reflection", "addFunction"), stackName("Array", "clonePointer"));
    // addStackChecker(stackName("Note", "Constructor"), stackName("Array", "insertLocalArrayPointer"));
	
}

}

#endif 

