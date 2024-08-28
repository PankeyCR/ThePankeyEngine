
#ifndef Hash_hpp
	#define Hash_hpp

	#include "InvokeMethod.hpp"

	#ifdef Hash_LogApp
		#include "pankey_Logger.hpp"
		#define HashLog(location,method,type,mns) pankey_Log(nullptr,location,"Hash",method,type,mns)
	#else
		#define HashLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class T>
		struct HashFunction{
			static InvokeMethodReturn<long,const T&> function;//return long: returns the hash encrypted number
		};

		struct HashToIndexFunction{
			static InvokeMethodReturn<int,long,int,int> function;//return int index, long hash, int min, int max
		};

		template<class T>
		long invalidHashMethod(const T& a_type){
			HashLog(pankey_Log_StartMethod, "invalidHashMethod", "println", "");
			HashLog(pankey_Log_EndMethod, "invalidHashMethod", "println", "");
			return -1;
		}

		int invalidHashToIndexMethod(long a_hash, int a_min, int a_max){
			HashLog(pankey_Log_StartMethod, "invalidHashToIndexMethod", "println", "");
			HashLog(pankey_Log_EndMethod, "invalidHashToIndexMethod", "println", "");
			return -1;
		}

		template<class T>
		InvokeMethodReturn<long,const T&> HashFunction<T>::function = invalidHashMethod<T>;

		InvokeMethodReturn<int,long,int,int> HashToIndexFunction::function = invalidHashToIndexMethod;

		template<class T>
		void setHashFunction(InvokeMethodReturn<long,const T&> a_function){
			HashFunction<T>::function = a_function;
		}

		void setHashToIndexFunction(InvokeMethodReturn<int,long,int,int> a_function){
			HashToIndexFunction::function = a_function;
		}

		template<class T>
		long Hash(const T& a_type){
			HashLog(pankey_Log_StartMethod, "Hash", "println", "");

			long i_hash = HashFunction<T>::function(a_type);
			HashLog(pankey_Log_Statement, "Hash", "println", "Hash: ");
			HashLog(pankey_Log_Statement, "Hash", "println", i_hash);

			HashLog(pankey_Log_EndMethod, "Hash", "println", "");
			return i_hash;
		}

		template<class T>
		int Hash(const T& a_type, int a_min, int a_max){
			HashLog(pankey_Log_StartMethod, "Hash", "println", "");

			long i_hash = HashFunction<T>::function(a_type);
			int i_index = HashToIndexFunction::function(i_hash, a_min, a_max);
			
			HashLog(pankey_Log_Statement, "Hash", "println", "Hash: ");
			HashLog(pankey_Log_Statement, "Hash", "println", i_hash);
			
			HashLog(pankey_Log_Statement, "Hash", "println", "Index: ");
			HashLog(pankey_Log_Statement, "Hash", "println", i_index);

			HashLog(pankey_Log_EndMethod, "Hash", "println", "");
			return i_index;
		}

	}

#endif
