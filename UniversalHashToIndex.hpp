
#ifndef UniversalHashToIndex_hpp
	#define UniversalHashToIndex_hpp

	#ifdef UniversalHashToIndex_LogApp
		#include "pankey_Logger.hpp"
		#define UniversalHashToIndexLog(location,method,type,mns) pankey_Log(nullptr,location,"UniversalHashToIndex",method,type,mns)
	#else
		#include "pankey_Logger_position.hpp"
		#define UniversalHashToIndexLog(location,method,type,mns)
	#endif

	namespace pankey{

		int universalHashToIndex(long a_hash, int a_min, int a_max){
			UniversalHashToIndexLog(pankey_Log_StartMethod, "universalHashToIndex", "println", "");
			int i_delta = a_max - a_min;
			float i_hash_relation = 1 / (float) a_hash;
			int i_index = (i_hash_relation * i_delta) + a_min;
			UniversalHashToIndexLog(pankey_Log_Statement, "primitiveHash", "println", "Hash delta: ");
			UniversalHashToIndexLog(pankey_Log_Statement, "primitiveHash", "println", i_delta);
			UniversalHashToIndexLog(pankey_Log_Statement, "primitiveHash", "println", "Hash: ");
			UniversalHashToIndexLog(pankey_Log_Statement, "primitiveHash", "println", (float)a_hash);
			UniversalHashToIndexLog(pankey_Log_Statement, "primitiveHash", "println", "Hash relation: ");
			UniversalHashToIndexLog(pankey_Log_Statement, "primitiveHash", "println", i_hash_relation);
			UniversalHashToIndexLog(pankey_Log_Statement, "primitiveHash", "println", "Hash index generated: ");
			UniversalHashToIndexLog(pankey_Log_Statement, "primitiveHash", "println", i_index);
			UniversalHashToIndexLog(pankey_Log_EndMethod, "universalHashToIndex", "println", "");
			return i_index;
		}

	}

#endif
