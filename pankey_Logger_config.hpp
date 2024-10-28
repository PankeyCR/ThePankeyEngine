
#ifndef pankey_Logger_config_hpp
#define pankey_Logger_config_hpp

#ifndef pankey_Log_Module
	#include "pankey_Simple_Logger.hpp"
	#define pankey_Log_Module(pointer,location,name,method,type,mns) Simple_LogPrint_(pointer,location,name,method,type,mns)

	// #include "pankey_Method_Stack_Logger.hpp"
	// #define pankey_Log_Module(pointer,location,name,method,type,mns) Stack_LogPrint_(pointer,location,name,method,type,mns)
	
	// #include "pankey_List_Logger.hpp"
	// #define pankey_Log_Module(pointer,location,name,method,type,mns) List_LogPrint_(pointer,location,name,method,type,mns)
#endif

//   addClassToLog("Note");
//   addClassMethodToLog("insertLocalArrayPointer");


// #ifndef pankey_LogDebug
// 	#include "pankey_debug.hpp"
// 	#define pankey_LogDebug(pointer,location,name,method,type) debug(pointer,location,name,method,type)
// #endif

// #ifndef pankey_LogDebug
// 	#include "pankey_list_debug.hpp"
// 	#define pankey_LogDebug(pointer,location,name,method,type) list_debug(pointer,location,name,method,type)
// #endif


namespace pankey{

void pankeyLoggerConfig(){
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

