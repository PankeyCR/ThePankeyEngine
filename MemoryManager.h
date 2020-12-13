

#ifndef MemoryManager_h
#define MemoryManager_h

class MemoryManager{
    public:		
		MemoryManager(){}
		virtual ~MemoryManager(){}
		
		virtual void* allocateMemory(size_t size){return nullptr;}
		virtual void deleteMemory(void* pointerToDelete){}
		virtual void watchdog(void* pointerToWatch){}
		
		virtual void maintain(float tpc){}
		
	protected:
};


#endif 
