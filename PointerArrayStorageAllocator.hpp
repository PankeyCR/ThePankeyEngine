
#ifndef PointerArrayStorageAllocator_hpp
	#define PointerArrayStorageAllocator_hpp

    #include "MemoryStorageAllocator.hpp"
    #include "PointerArrayStorage.hpp"

	namespace pankey{

		template<class P, class H, class A>
		class PointerArrayStorageAllocator : public MemoryStorageAllocator<P,H,A>{
			public:
            	using STORAGE_TYPE = MemoryStorage<P,H,A>*;

				PointerArrayStorageAllocator(){}
				virtual ~PointerArrayStorageAllocator(){}

				virtual STORAGE_TYPE newMemoryStorage(){
					return new PointerArrayStorage<P,H,A>();
				}

				virtual void removeMemoryStorage(STORAGE_TYPE& a_holder){
					delete a_holder;
					a_holder = nullptr;
				}
		};

	}

#endif