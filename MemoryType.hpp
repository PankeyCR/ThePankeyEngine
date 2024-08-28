
#ifndef MemoryType_hpp
	#define MemoryType_hpp

	#include "MemoryAllocator.hpp"
	#include "ClassCount.hpp"

	namespace pankey{

		template<class T, class H>
		class MemoryType{
			public:				
				using POINTER_TYPE = T*;
				using HOLDER_TYPE = H*;

				MemoryType(){}
				virtual ~MemoryType(){}
				
				virtual void setType(HOLDER_TYPE& a_holder, long a_type){}
				
				virtual long getType(const HOLDER_TYPE& a_holder){return -1;}
				
				virtual void setBaseType(HOLDER_TYPE& a_holder, long a_type){}
				
				virtual long getBaseType(const HOLDER_TYPE& a_holder){return -1;}

				virtual POINTER_TYPE getType(HOLDER_TYPE& a_holder)const{return nullptr;}
		};

	}

#endif