
#ifndef Full_List_Testing_hpp
#define Full_List_Testing_hpp

#include "TestResult.hpp"

#include "RawList.hpp"
#include "List.hpp"
#include "PList.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveRawList.hpp"
#include "Note.hpp"

namespace ame{
	
	int tipesOfLists(){
		return 5;
	}
	
	template<class T>
	RawList<T>* getList(int x){
		if(x == 0){
			return new ArrayList<T,5>();
		}
		if(x == 1){
			return new PList<T,5>(true);
		}
		if(x == 2){
			return new PrimitiveList<T>();
		}
		if(x == 3){
			return new PrimitiveRawList<T>();
		}
		if(x == 4){
			return new LinkedList<T>();
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
			return Note("PrimitiveList");
		}
		if(x == 3){
			return Note("PrimitiveRawList");
		}
		if(x == 4){
			return Note("LinkedList");
		}
		return "";
	}
	
	TestResult Full_List_Testing(){
		TestResult result;
		
		for(int x = 0; x < tipesOfLists(); x++){
			RawList<int>* list = getList<int>(x);
			if(list == nullptr){
				result.catchError(getListName(x) + Note(" Contructor creates a nullptr pointer"));
				continue;
			}
			list->addLValue(1);
			if(list->isEmpty()){
				result.catchError(getListName(x) + Note(" isEmpty: it suppose to have one element"));
			}
			
			{
			PrimitiveList<int>* plist = new PrimitiveList<int>();
			plist->add(15);
			plist->add(16);
			plist->add(17);
			
			list->addList(plist);
			
			delete plist;
			}
			
			if(!list->contain(15) && !list->contain(16) && !list->contain(17)){
				result.catchError(getListName(x) + Note(" the add method didnt add the numbers or the addList method didnt add the numbers or contain method dont work"));
			}
			
			list->put(15);
			if(list->repeated(15) != 1){
				result.catchError(getListName(x) + Note(" the put method is adding even if it contains the element"));
			}
			
			int index_15 = list->getIndex(15);
			list->set(index_15, 14);
			
			if(list->contain(15)){
				result.catchError(getListName(x) + Note(" the set method didnt change the value on the index the 15 value was on"));
			}
			
			delete list;
		}
		
		return result;
	}
}

#endif
