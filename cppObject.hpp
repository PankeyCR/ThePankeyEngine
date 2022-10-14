
#ifndef cppObject_hpp
#define cppObject_hpp
#define cppObject_AVAILABLE

#include "ame_Enviroment.hpp"

namespace ame{
	class cppObject;
}

#include "Memory.hpp"
#include "cppObjectClass.hpp"

namespace ame{

class cppObject{
    public:
		cppObject(){}
		virtual ~cppObject(){}
		
		// void* operator new(size_t a_size){
			// return Memory::newObject(a_size);
		// }
		// void operator delete(void* a_obj){
			// Memory::deleteObject((cppObject*)a_obj);
		// }
		
		virtual void onDelete(){}
		
		virtual cppObjectClass* getClass(){return nullptr;}
		virtual bool instanceof(cppObjectClass* cls){return false;}

		virtual cppObject* clone(void){return nullptr;}
		virtual cppObject* clone(bool owningMemory){return nullptr;}
		
		virtual bool equal(cppObject* obj){return this == obj;}
		
		virtual bool copy(cppObject* obj){return false;}
		virtual bool move(cppObject* obj){return false;}
		virtual bool duplicate(cppObject* obj){return false;}
		
		virtual cppObject* move(){return nullptr;}
		virtual cppObject* duplicate(){return nullptr;}

		virtual void operator=(cppObject obj){}
		virtual bool operator==(cppObject obj){return false;}
		virtual bool operator!=(cppObject obj){return false;}
		
		virtual void MemoryManagerOn(){memory_managed = true;}
		virtual void MemoryManagerOff(){memory_managed = false;}
		
		virtual void addObject(){contained_on_list++;}
		virtual void removeObject(){
			contained_on_list--;
			if(contained_on_list < 0){
				contained_on_list = 0;
			}
		}
		
		virtual bool isManaged(){
			return memory_managed;
		}
		
		virtual bool readyToDelete(){
			return contained_on_list == 0;
		}
		
	protected:
		int contained_on_list = 0;
		bool memory_managed = false;
		
		
	private:
};

}

#endif