

#ifndef MemoryManager_h
#define MemoryManager_h

template<class T>
class MemoryManager{
    public:		
		MemoryManager(){}
		virtual ~MemoryManager(){}
		
		virtual void* allocateMemory(size_t size){return nullptr;}
		virtual void deleteMemory(void* pointerToDelete, size_t sizeofMemory){}
		virtual void watchdog(void* pointerToWatch){}
		
		virtual void maintain(float tpc, size_t sizeofMemory){}
		virtual void addMemory(T* t){}
		virtual void removeMemory(T* t){}
		virtual bool containMemory(T* t){return false;}
		
	protected:
};


#endif 
