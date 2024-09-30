
#ifndef UniversalHolder_hpp
	#define UniversalHolder_hpp

	#include "MemoryAllocator.hpp"

	namespace pankey{

		struct UniversalHolder{
			MemoryAllocator* m_allocator = nullptr;
			void* m_pointer = nullptr;
			int m_count = 0;
			long m_type = -1;
			long m_base_type = -1;
			bool m_maneged = true;
		};
		
	}

#endif