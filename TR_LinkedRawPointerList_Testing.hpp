
#ifndef TR_LinkedRawPointerList_Testing_hpp
	#define TR_LinkedRawPointerList_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "LinkedRawPointerList.hpp"

	namespace pankey{
		
		TestResult TR_LinkedRawPointerList_Testing_1(){
			TestResult i_result;
			
			LinkedRawPointerList<int> i_list;

			i_result.assertTrue("list should be empty", i_list.isEmpty());
			
			return i_result;
		}
		
		TestResult TR_LinkedRawPointerList_Testing_2(){
			TestResult i_result;
			
			LinkedRawPointerList<int> i_list;

			i_list.addPointer(new int(15));
			int* i_num = i_list.getByPosition(0);

			i_result.assertTrue("list shouldnt be empty", !i_list.isEmpty());
			i_result.assertNotNull("list element in position 0 shouldnt be null", i_num);
			if(i_num != nullptr){
				i_result.assertNoteEqual("list element should be 15", *i_num, 15);
			}
			
			return i_result;
		}
		
		TestResult TR_LinkedRawPointerList_Testing_3(){
			TestResult i_result;
			
			LinkedRawPointerList<int> i_list;

			int* i_num = new int(15);
			i_list.putPointer(i_num);
			i_list.putPointer(i_num);
			int* i_num_1 = i_list.getByPosition(0);
			int* i_num_2 = i_list.getByPosition(1);

			i_result.assertNotNull("list element in position 0 shouldnt be null", i_num_1);
			i_result.assertNull("list element in position 1 should be null", i_num_2);
			
			return i_result;
		}
		
		TestResult TR_LinkedRawPointerList_Testing_4(){
			TestResult i_result;
			
			LinkedRawPointerList<int> i_list;

			int* i_num_01 = i_list.setPointer(0, new int(15));
			int* i_num_02 = i_list.setPointer(1, new int(15));
			int* i_num_1 = i_list.getByPosition(0);
			int* i_num_2 = i_list.getByPosition(1);
			
			i_result.assertNotNull("list element in position 0 shouldnt be null", i_num_1);
			i_result.assertNotNull("list element in position 1 shouldnt be null", i_num_2);
			i_result.assertEqual("should be the same", i_num_1, i_num_01);
			i_result.assertEqual("should be the same", i_num_2, i_num_02);
			
			return i_result;
		}

		void TR_LinkedRawPointerList_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("LinkedList Constructor", TR_LinkedRawPointerList_Testing_1);
			a_test_runner.map.add("LinkedList addPointer getByPosition", TR_LinkedRawPointerList_Testing_2);
			a_test_runner.map.add("LinkedList putPointer", TR_LinkedRawPointerList_Testing_3);
			a_test_runner.map.add("LinkedList setPointer", TR_LinkedRawPointerList_Testing_4);
		}
	}

#endif
