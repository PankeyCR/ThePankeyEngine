
#ifndef UniversalHolder_hpp
	#define UniversalHolder_hpp

	#include "MemoryAllocator.hpp"

	namespace higgs{

		struct UniversalHolder{
			MemoryAllocator* m_allocator = nullptr;
			void* m_pointer = nullptr;
			int m_count = 0;
			long m_type = 0;
			long m_base_type = 0;
			bool m_maneged = true;
		};
		
	}

#endif