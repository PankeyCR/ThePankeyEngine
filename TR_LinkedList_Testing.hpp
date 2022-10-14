
#ifndef TR_LinkedList_Testing_hpp
#define TR_LinkedList_Testing_hpp

#include "TestResult.hpp"

#include "LinkedList.hpp"
#include "MemoryRam.hpp"

namespace ame{
	
	int ram = -1;
	
	TestResult TR_LinkedList_Testing(){
		TestResult result;
		
		int a_ram = getRamSize();
		
		LinkedList<int> list;
		
		list.addPointerToNode(new int(5));
		LinkedListNode<int>* node = list.getEndNode();
		
		if(node == nullptr){
			result.catchError(0, "getEndNode shouldnt be null, addPointerToNode didnt add the pointer");
		}
		
		if(list.getSize() != 1){
			result.catchError(1, Note("list size most be 1 and it has ") + Note(list.getSize()));
		}
		
		list.addPointerToNode(new int(47));
		
		if(list.getSize() != 2){
			result.catchError(2, Note("list size most be 2 and it has ") + Note(list.getSize()));
		}
		
		list.addPointerToNode(new int(31));
		
		if(list.getSize() != 3){
			result.catchError(3, Note("list size most be 3 and it has ") + Note(list.getSize()));
		}
		
		list.addPointerToStartNode(new int(781));
		
		if(list.getSize() != 4){
			result.catchError(301, Note("list size most be 4 and it has ") + Note(list.getSize()));
		}
		
		list.addPointerToEndNode(new int(96));
		
		if(list.getSize() != 5){
			result.catchError(302, Note("list size most be 5 and it has ") + Note(list.getSize()));
		}
		
		{
		LinkedListNode<int>* i_node_1 = list.getNode(0);
		LinkedListNode<int>* i_node_2 = list.getNode(4);
		if(i_node_1 == nullptr){
			result.catchError(4, "node 0 shouldnt be null");
		}
		if(i_node_2 == nullptr){
			result.catchError(5, "node 4 shouldnt be null");
		}
		if(i_node_1 != nullptr){
			if(i_node_1->get() == nullptr){
				result.catchError(6, "node 0 value shouldnt be null");
			}
		}
		if(i_node_2 != nullptr){
			if(i_node_2->get() == nullptr){
				result.catchError(7, "node 4 value shouldnt be null");
			}
		}
		if(i_node_1 != nullptr){
			if(i_node_1->get() != nullptr){
				if(*i_node_1->get() != 781){
					result.catchError(8, "node 0 value should be 781");
				}
			}
		}
		if(i_node_2 != nullptr){
			if(i_node_2->get() != nullptr){
				if(*i_node_2->get() != 96){
					result.catchError(9, "node 4 value should be 96");
				}
			}
		}
		}
		
		{
		int* num_781 = list.getByPosition(0);
		int* num_96 = list.getByPosition(4);
		
		if(num_781 == nullptr){
			result.catchError(10, "shouldnt be null, it should contain a 781 value");
		}
		
		if(num_96 == nullptr){
			result.catchError(11, "shouldnt be null, it should contain a 96 value");
		}
		}
		
		{
		int* num_781 = list.getByLValue(781);
		int* num_96 = list.getByLValue(96);
		
		if(num_781 == nullptr){
			result.catchError(12, "shouldnt be null, it should contain a 781 value");
		}
		
		if(num_96 == nullptr){
			result.catchError(13, "shouldnt be null, it should contain a 96 value");
		}
		}
		
		{
		LinkedList<int>* n_list = new LinkedList<int>();
		n_list->copy(&list);
		
		if(!n_list->equal(&list)){
			result.catchError(14, "this two lists have to be identical, or the copy method dont work or the equal method dont work");
		}
		
		LinkedList<int>* n_list_2 = new LinkedList<int>();
		n_list_2->move(n_list);
		
		if(!n_list->isEmpty()){
			result.catchError(15, "this instance should be empty");
		}
		
		delete n_list;
		delete n_list_2;
		}
		
		list.resetDelete();
		
		int na_ram = getRamSize();
		if(ram == -1){
			ram = a_ram - na_ram;
		}
		if(a_ram - na_ram != 0){
			result.catchError(159, "memory leak");
		}
		if(a_ram - na_ram != ram){
			ram = a_ram - na_ram;
			result.catchError(852, "theres a ram problem");
		}
		
		
		return result;
	}
}

#endif
