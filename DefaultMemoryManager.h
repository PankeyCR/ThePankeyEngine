
#ifndef DefaultMemoryManager_h
#define DefaultMemoryManager_h

#include "PrimitiveList.h"
#include "MemoryManager.h"
#include "MemoryFree.h"

template<class T>
class DefaultMemoryManager : public MemoryManager<T>{
    public:		
		DefaultMemoryManager(){
			listPointer = new PrimitiveList<T>();
			// listSafeOverWrite = new PrimitiveList<T>();
			listTime = new PrimitiveList<float>(); 
		}
		virtual ~DefaultMemoryManager(){
			delete listPointer; 
			delete listTime; 
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
				listTime->addPointer(new float(0.0f));
				p = (T*)malloc(size);
				listPointer->addPointer(p);
			}
			//Serial.println(freeMemory());
			//Serial.println("full allocateMemory");
			return p;
		}
		void deleteMemory(void* pointerToDelete,size_t sizeofMemory){
			//Serial.println("starting full delete");
			//Serial.println(freeMemory());
			T* p = (T*)pointerToDelete;
			//p->onDeleteMemory();
			//Serial.println(freeMemory());
			int x = listPointer->getIndexByPointer(p);
			if(x == -1){
				return;
			}
			listTime->removeDeleteByPosition(x);
			// Serial.println(freeMemory());
			listPointer->removeByPointer(p);
			//Serial.println(freeMemory());
			free((T*)p);
			//Serial.println(freeMemory());
			//Serial.println("full delete");
		}
		void watchdog(void* pointerToWatch){
			int x = listPointer->getIndexByPointer((T*)pointerToWatch);
			if(x == -1){
				return;
			}
			listTime->setLValue(x, 0.0f);
		}
		
		void maintain(float tpc, size_t sizeofMemory){
			for(int m = 0; m < listTime->getPosition(); m++){
				T* p = listPointer->getByPosition(m);
				float t = *listTime->getByPosition(m);
				if(t >= maxTimeLimit){
					// Serial.println("delete maintain maxTimeLimit");
					deleteMemory(p,sizeofMemory);
					m--;
					continue;
				}
				if(freeMemory() < RamMinSize){
					// Serial.println("delete maintain freeMemory");
					deleteMemory(p,sizeofMemory);
					m--;
					continue;
				}
				listTime->setLValue(m, t + 1.0f);
			}
			// Serial.println("maintain");
			// Serial.println(freeMemory());
		}
		virtual void addMemory(T* t){
			listPointer->addPointer(t);
		}
		virtual void removeMemory(T* t){
			listPointer->removeByPointer(t);
		}
		virtual bool containMemory(T* t){
			return listPointer->containByPointer(t);
		}
		
		void setTime(float max){
			maxTimeLimit = max;
		}
		
		void setRamMinSize(long r){
			RamMinSize = r;
		}
		
	protected:
		PrimitiveList<T>* listPointer; 
		PrimitiveList<float>* listTime;
		float maxTimeLimit = 0.1f;
		long RamMinSize = 1500l;
};


#endif