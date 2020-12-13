
#ifndef DefaultMemoryManager_h
#define DefaultMemoryManager_h

#include "PrimitiveList.h"
#include "MemoryManager.h"
#include "MemoryFree.h"

template<class T>
class DefaultMemoryManager : public MemoryManager{
    public:		
		DefaultMemoryManager(){
			listPointer = new PrimitiveList<T>();
			// listSafeOverWrite = new PrimitiveList<T>();
			// listTime = new PrimitiveList<long>(); 
		}
		virtual ~DefaultMemoryManager(){
			delete listPointer; 
			// delete listTime; 
			// delete listSafeOverWrite; 
		}
		
		void* allocateMemory(size_t size){
			T* p = nullptr;
			//Serial.println("starting full allocateMemory");
			//Serial.println(freeMemory());
			if(freeMemory() < RamMinSize){
				// if(!listSafeOverWrite->isEmpty()){
					// p = listSafeOverWrite->getByPos(listSafeOverWrite->getPos()-1);
					// p->onRecycleMemory();
					// int pos = listPointer->getIndex(p);
					// long* l = listTime->getByPos(pos);
					// (*l) = 0l;
					//listTime->set(pos , 0l);
					// listSafeOverWrite->removeByPos(listSafeOverWrite->getPos()-1);
				// }
			}else{
				// listTime->add(new long(0l));
				p = (T*)malloc(size);
				listPointer->add(p);
			}
			//Serial.println(freeMemory());
			//Serial.println("full allocateMemory");
			return p;
		}
		void deleteMemory(void* pointerToDelete){
			//Serial.println("starting full delete");
			//Serial.println(freeMemory());
			T* p = (T*)pointerToDelete;
			//p->onDeleteMemory();
			//Serial.println(freeMemory());
			int x = listPointer->getIndex(p);
			if(x == -1){
				return;
			}
			// listTime->removeDeleteByPos(x);
			// Serial.println(freeMemory());
			// listSafeOverWrite->remove(p);
			// Serial.println(freeMemory());
			listPointer->remove(p);
			//Serial.println(freeMemory());
			free((T*)p);
			//Serial.println(freeMemory());
			//Serial.println("full delete");
		}
		void watchdog(void* pointerToWatch){
			// int x = listPointer->getIndex((T*)pointerToWatch);
			// if(x == -1){
				// return;
			// }
			// long* l = listTime->getByPos(x);
			// (*l) = 0l;
		}
		
		void maintain(float tpc){
			// for(int m = 0; m < listTime->getPos(); m++){
				// T* p = listPointer->getByPos(m);
				// float t = *listTime->getByPos(m);
				// if(t >= maxTimeLimit){
					// Serial.println("delete maintain");
					// deleteMemory(p);
					// m--;
					// continue;
				// }
				// if(t >= normalTimeLimit){
					// if(!listSafeOverWrite->contain(p)){
						// listSafeOverWrite->add(p);
					// }
				// }
				// long* l = listTime->getByPos(m);
				// (*l) += 1l;
				//listTime->set(m, *listTime->getByPos(m) + 1l);
			// }
			// Serial.println("maintain");
			// Serial.println(freeMemory());
		}
		
		void setTimes(long max, long normal){
			maxTimeLimit = max;
			normalTimeLimit = normal;
		}
		
		void setTime(long max){
			maxTimeLimit = max;
			normalTimeLimit = max+1;
		}
		
		void setRamMinSize(long r){
			RamMinSize = r;
		}
		
	protected:
		PrimitiveList<T>* listPointer; 
		// PrimitiveList<long>* listTime;
		// PrimitiveList<T>* listSafeOverWrite;
		long maxTimeLimit = 100l;
		long normalTimeLimit = 10l;
		long RamMinSize = 1500l;
};


#endif