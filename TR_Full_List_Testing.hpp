
#ifndef TR_Full_List_Testing_hpp
#define TR_Full_List_Testing_hpp

#include "TestResult.hpp"

#include "RawPointerList.hpp"
#include "RawList.hpp"
#include "List.hpp"
#include "PList.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveRawList.hpp"
#include "Note.hpp"
#include "cppObject.hpp"
#include "cppObjectList.hpp"
#include "Number.hpp"
#include "Vector2f.hpp"

namespace ame{
	
	int tipesOfLists(){
		return 5;
	}
	
	template<class T>
	RawList<T>* getList(int x){
		if(x == 0){
			return new ArrayList<T,5>();//1
		}
		if(x == 1){
			return new PList<T,5>(true);//2
		}
		if(x == 2){
			return new PrimitiveRawList<T>();//3
		}
		if(x == 3){
			return new PrimitiveList<T>();//4
		}
		if(x == 4){
			return new LinkedList<T>();//5
		}
		if(x == 5){
			// return new cppObjectList<T>();//6
		}
		return nullptr;
	}
	
	Note getListName(int x){
		if(x == 0){
			return Note("ArrayList");
		}
		if(x == 1){
			return Note("PList");
		}
		if(x == 2){
			return Note("PrimitiveRawList");
		}
		if(x == 3){
			return Note("PrimitiveList");
		}
		if(x == 4){
			return Note("LinkedList");
		}
		if(x == 5){
			return Note("cppObjectList");
		}
		return "";
	}
	
	template<class T>
	void removeFirstIndex_Test(RawList<T>* a_raw_list){
		
	}
	
	template<class T = int>
	TestResult TR_Full_List_Testing(){
		TestResult result;
		
		for(int x = 0; x < tipesOfLists(); x++){
			RawList<T>* list = getList<T>(x);
			if(list == nullptr){
				result.catchError(0, getListName(x) + Note(" Contructor creates a nullptr pointer"));
				continue;
			}
			list->addLValue(1);
			if(list->isEmpty()){
				result.catchError(1, getListName(x) + Note(" isEmpty: it suppose to have one element"));
			}
			
			{
			RawList<T>* plist = getList<T>(x);
			plist->add(15);
			plist->add(16);
			plist->add(17);
			
			list->addCopy(plist);
			
			delete plist;
			}
			
			if(!list->contain(15) && !list->contain(16) && !list->contain(17)){
				result.catchError(2, getListName(x) + Note(" the add method didnt add the numbers or the addList method didnt add the numbers or contain method dont work"));
			}
			
			list->put(15);
			if(list->repeated(15) != 1){
				result.catchError(3, getListName(x) + Note(" the put method is adding even if it contains the element"));
			}
			
			int index_15 = list->getIndex(15);
			list->set(index_15, 14);
			
			if(list->contain(15)){
				result.catchError(4, getListName(x) + Note(" the set method didnt change the value on the index the 15 value was on"));
			}
			
			// {
			// cppObject* obj = list->duplicate();
			
			// if(!obj->equal(list)){
				// result.catchError(getListName(x) + Note(" the object should be identical because of the duplicate method"));
			// }
			
			// delete obj;
			// }
			
			// {
			// cppObject* obj = list->move();
			
			// if(!obj->equal(list)){
				// result.catchError(getListName(x) + Note(" the object should be identical because of the duplicate method"));
			// }
			
			// delete obj;
			// }
			
			removeFirstIndex_Test<T>(list);

			delete list;
		}
		
		return result;
	}
}

#endif
