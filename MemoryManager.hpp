
#ifndef MemoryManager_hpp
	#define MemoryManager_hpp

	#include "MemoryAllocator.hpp"

	namespace pankey{

		template<class H>
		class MemoryManager{
			public:				
				using VOID_TYPE = void*;
				using HOLDER_TYPE = H*;

				MemoryManager(){}
				virtual ~MemoryManager(){}
				
				virtual void setType(HOLDER_TYPE& a_holder, long a_type){}
				
				virtual long getType(const HOLDER_TYPE& a_holder){return -1;}
				
				virtual void setBaseType(HOLDER_TYPE& a_holder, long a_type){}
				
				virtual long getBaseType(const HOLDER_TYPE& a_holder){return -1;}

				virtual HOLDER_TYPE newHolder(){return nullptr;}

				virtual HOLDER_TYPE newInstance(long a_type, MemoryAllocator* a_allocator){return nullptr;}
				virtual HOLDER_TYPE newInstance(long a_type, pointer_size a_size, MemoryAllocator* a_allocator){return nullptr;}

				virtual void setManageableCheck(HOLDER_TYPE& a_holder, bool a_check){}
				
				virtual void set(HOLDER_TYPE& a_holder, HOLDER_TYPE& a_set_holder){}

				virtual void add(HOLDER_TYPE& a_holder){}

				virtual void remove(HOLDER_TYPE& a_holder){}

				virtual void destroy(HOLDER_TYPE& a_holder){}

				virtual VOID_TYPE get(const HOLDER_TYPE& a_holder){return nullptr;}
		};

	}

#endif