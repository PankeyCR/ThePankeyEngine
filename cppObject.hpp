
#ifndef cppObject_hpp
	#define cppObject_hpp

	namespace pankey{
		template<class H, class A>
		class cppObject;

		template<class T>
		using Entity = Object<T,cppObject,cppObject,ALLOCATOR>;
		
		using Obj = Pointer<cppObject,cppObject,ALLOCATOR>;
	}

	#include "cppObjectClass.hpp"
	#include "Object.hpp"

	namespace pankey{

		template<class H, class A>
		class cppObject{
			public:
				cppObject(){}
				virtual ~cppObject(){}
				
				virtual void onDelete(){}
				
				virtual cppObjectClass* getClass(){return nullptr;}
				virtual bool instanceof(cppObjectClass* cls){return false;}

				virtual Obj clone(){return nullptr;}
				virtual Obj clone(bool owningMemory){return nullptr;}
				
				virtual bool equal(const Obj& obj){return this == obj;}
				
				virtual bool copy(const Obj& obj){return false;}
				virtual bool move(const Obj& obj){return false;}
				virtual bool duplicate(const Obj& obj){return false;}
				
				virtual Obj move(){return nullptr;}
				virtual Obj duplicate(){return nullptr;}

				virtual void operator=(const cppObject& obj){}
				virtual bool operator==(const cppObject& obj){return false;}
				virtual bool operator!=(const cppObject& obj){return false;}
				
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
				
				virtual bool isReferenced(){
					return contained_on_list > 0;
				}
				
			protected:
				int contained_on_list = 0;
				bool memory_managed = false;
		};

	}

#endif