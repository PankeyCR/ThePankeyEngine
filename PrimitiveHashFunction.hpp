
#ifndef PrimitiveHashFunction_hpp
	#define PrimitiveHashFunction_hpp

	#ifdef PrimitiveHashFunction_LogApp
		#include "pankey_Logger.hpp"
		#define PrimitiveHashFunctionLog(location,method,type,mns) pankey_Log(nullptr,location,"PrimitiveHashFunction",method,type,mns)
	#else
		#define PrimitiveHashFunctionLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class T>
		long primitiveHash(const T& a_type){
			PrimitiveHashFunctionLog(pankey_Log_StartMethod, "primitiveHash", "println", "");
			float i_seed = 923;
			float i_value = (float)a_type;
			float i_hash = (1 / i_value) * i_seed;
			PrimitiveHashFunctionLog(pankey_Log_Statement, "primitiveHash", "println", "Hash generated: ");
			PrimitiveHashFunctionLog(pankey_Log_Statement, "primitiveHash", "println", i_hash);
			PrimitiveHashFunctionLog(pankey_Log_EndMethod, "primitiveHash", "println", "");
			return (long)i_hash;
		}

	}

#endif
