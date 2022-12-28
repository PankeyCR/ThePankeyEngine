
#ifndef TR_List_Reorder_Testing_hpp
#define TR_List_Reorder_Testing_hpp

#include "TestResult.hpp"

#include "TR_Full_List_Testing.hpp"

namespace ame{
	
	TestResult TR_List_Reorder_Testing(){
		TestResult result;
		
		for(int x = 0; x < tipesOfLists(); x++){
			RawList<int>* list = getList<int>(x);
			
			if(list == nullptr){
				result.catchError(0, getListName(x) + Note(" Contructor creates a nullptr pointer"));
				continue;
			}

			list->setReorder(false);
			
			list->add(1);
			list->add(2);
			list->add(3);
			list->add(4);
			list->add(5);
			
			if(list->getPosition() != 5){
				result.catchError(1, getListName(x) + Note(" add is not working"));
			}
			
			if(	list->getByIndex(0) != 1 || 
				list->getByIndex(1) != 2 ||
				list->getByIndex(2) != 3 ||
				list->getByIndex(3) != 4 ||
				list->getByIndex(4) != 5   ){
				result.catchError(2, getListName(x) + Note(" getByIndex not working"));
			}

			list->removeByIndex(1);
			list->removeByIndex(3);
			
			if(list->getPosition() != 5){
				result.catchError(3, getListName(x) + Note(" removeByIndex is not working"));
			}
			
			if(	list->getByPosition(1) != nullptr || 
				list->getByPosition(3) != nullptr   ){
				result.catchError(4, getListName(x) + Note(" reorder not working"));
			}

			list->set(1, 2);
			list->set(3, 4);
			
			if(	list->getByIndex(0) != 1 || 
				list->getByIndex(1) != 2 ||
				list->getByIndex(2) != 3 ||
				list->getByIndex(3) != 4 ||
				list->getByIndex(4) != 5   ){
				result.catchError(5, getListName(x) + Note(" getByIndex not working"));
			}

			delete list;
		}
		
		return result;
	}
}

#endif
