
#include "TestRunner.hpp"

/////////Application test////////////////////////////////
#include "TR_UpdateFunctionListManager_Testing.hpp"
#include "TR_UpdateFunctionMapManager_Testing.hpp"

#include "TR_UpdateClassFunctionListManager_Testing.hpp"
#include "TR_UpdateClassFunctionMapManager_Testing.hpp"

#include "TR_AppStateListManager_Testing.hpp"
//#include "TR_AppStateMapManager_Testing.hpp"

#include "TR_LoopManager_Testing.hpp"

#include "TR_DefaultAppSettings_Testing.hpp"

#include "TR_Application_Testing.hpp"

#include "TR_GlobalEvents_Testing.hpp"

//#include "TR_UsbNetwork_Testing.hpp"
///////////////////////////////////////////////////

//////////DataStructure test////////////////////////
#include "TR_Array_Testing.hpp"
#include "TR_CharArray_Testing.hpp"
#include "TR_Note_Testing.hpp"
#include "TR_ByteArray_Testing.hpp"

#include "TR_LinkedRawPointerList_Testing.hpp"
#include "TR_PrimitiveRawPointerList_Testing.hpp"
#include "TR_PrimitiveRawPointerMap_Testing.hpp"
#include "TR_PrimitiveRawPointerTree_Testing.hpp"
#include "TR_RawPointerList_Testing.hpp"

//#include "TR_LinkedRawList_Testing.hpp"
//#include "TR_PrimitiveRawList_Testing.hpp"
//#include "TR_PrimitiveRawMap_Testing.hpp"
//#include "TR_PrimitiveRawTree_Testing.hpp"

//#include "TR_PrimitiveList_Testing.hpp"

#include "TR_MemberArrayStorage_Testing.hpp"

#include "TR_TypeList_Testing.hpp"
#include "TR_ObjectList_Testing.hpp"
#include "TR_MemberList_Testing.hpp"

#include "MemberArrayTableStorage.hpp"
#include "TR_TableStorage_Testing.hpp"
#include "TR_MemberArrayMap_Testing.hpp"

#include "TR_Hash_Testing.hpp"

//#include "TR_Tree_Testing.hpp"

#include "TR_Variable_Testing.hpp"
#include "TR_Pointer_Testing.hpp"
#include "TR_Value_Testing.hpp"
#include "TR_Object_Testing.hpp"
#include "TR_Self_Testing.hpp"
#include "TR_DuoMember_Testing.hpp"

#include "TR_Set_Testing.hpp"
///////////////////////////////////////////

using namespace pankey;

TestRunner test;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the test");
  
  delay(5000);
  
  ///////Application test////////////////////////////////
  TR_UpdateFunctionListManager_Testing(test);
  TR_UpdateFunctionMapManager_Testing(test);
  
  TR_UpdateClassFunctionListManager_Testing(test);
  TR_UpdateClassFunctionMapManager_Testing(test);

  TR_AppStateListManager_Testing(test);
//  TR_AppStateMapManager_Testing(test);
  
  TR_LoopManager_Testing(test);
  
  TR_DefaultAppSettings_Testing(test);
  
  TR_Application_Testing(test);

  TR_GlobalEvents_Testing(test);

  //TR_UsbNetwork_Testing(test);
  /////////////////////////////////////////

  ////////DataStructure test///////////////
  TR_Array_Testing(test);
  TR_CharArray_Testing(test);
  TR_Note_Testing(test);
  TR_ByteArray_Testing(test);

  TR_LinkedRawPointerList_Testing(test);
  TR_PrimitiveRawPointerList_Testing(test);
  TR_PrimitiveRawPointerMap_Testing(test);
  TR_PrimitiveRawPointerTree_Testing(test);
  TR_RawPointerList_Testing<LinkedRawPointerList<int>,int>("LinkedRawPointerList", test);
  TR_RawPointerList_Testing<PrimitiveRawPointerList<int>,int>("PrimitiveRawPointerList", test);

  TR_MemberArrayStorage_Testing(test);

  //TR_LinkedList_Testing(test);
  TR_TypeList_Testing(test);
  TR_ObjectList_Testing(test);
  //TR_MemberList_Testing(test);

  TR_MemberArrayMap_Testing(test);

  TR_Hash_Testing(test);
  
  //TR_Tree_Testing(test);

  TR_Variable_Testing(test);
  TR_Pointer_Testing(test);
  TR_Value_Testing(test);
  TR_Object_Testing(test);
  TR_Self_Testing(test);
  TR_DuoMember_Testing(test);

  TR_TableStorage_Testing<table,int,float>("MemberArrayTableStorage", test);
  
  TR_Set_Testing(test);
  ///////////////////////////////////////////////////////////

  test.omitInfo(true);
}

void loop() {
  test.runTest();
  test.run();
  delay(3000);
}