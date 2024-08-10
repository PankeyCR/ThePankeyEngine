
#ifndef TR_PrimitiveRawPointerList_Testing_hpp
	#define TR_PrimitiveRawPointerList_Testing_hpp

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "PrimitiveRawPointerList.hpp"

	namespace higgs{
		
		TestResult TR_PrimitiveRawPointerList_Testing_1(){
			TestResult result;
			PrimitiveRawPointerList<int> list;
			result.assertTrue(0, "list should be empty", list.isEmpty());
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerList_Testing_2(){
			TestResult result;
			PrimitiveRawPointerList<int> list;
			list.addPointer(new int(5));
			list.addPointer(new int(10));
			list.addPointer(new int(15));

			result.assertEqual("list has 3 elements", list.getPosition(), 3);

			int* i_value_1 = list.getByPosition(0);
			int* i_value_2 = list.getByPosition(1);
			int* i_value_3 = list.getByPosition(2);
			result.assertTrue("list int 0 not null", i_value_1 != nullptr);
			result.assertTrue("list int 1 not null", i_value_2 != nullptr);
			result.assertTrue("list int 2 not null", i_value_3 != nullptr);

			if(i_value_1 != nullptr){
				result.assertEqual("list value 0", *i_value_1, 5);
			}
			if(i_value_2 != nullptr){
				result.assertEqual("list value 1", *i_value_2, 10);
			}
			if(i_value_3 != nullptr){
				result.assertEqual("list value 2", *i_value_3, 15);
			}
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerList_Testing_3(){
			TestResult result;
			PrimitiveRawPointerList<int> list;
			list.addPointer(new int(5));
			list.addPointer(new int(10));
			list.addPointer(new int(15));
			
			list.replace(0,2);

			result.assertEqual("list has 3 elements", list.getPosition(), 3);

			int* i_value_1 = list.getByPosition(0);
			int* i_value_2 = list.getByPosition(1);
			int* i_value_3 = list.getByPosition(2);
			result.assertTrue("list int 0 not null", i_value_1 != nullptr);
			result.assertTrue("list int 1 not null", i_value_2 != nullptr);
			result.assertTrue("list int 2 not null", i_value_3 != nullptr);

			if(i_value_1 != nullptr){
				result.assertEqual("list value 0", *i_value_1, 15);
			}
			if(i_value_2 != nullptr){
				result.assertEqual("list value 1", *i_value_2, 10);
			}
			if(i_value_3 != nullptr){
				result.assertEqual("list value 2", *i_value_3, 5);
			}
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerList_Testing_4(){
			TestResult i_result;

			PrimitiveRawPointerList<int> i_list;

			int* i_num = new int(15);
			i_list.putPointer(i_num);
			i_list.putPointer(i_num);
			int* i_num_1 = i_list.getByPosition(0);
			int* i_num_2 = i_list.getByPosition(1);
			
			i_result.assertNotNull("list element in position 0 shouldnt be null", i_num_1);
			i_result.assertNull("list element in position 1 should be null", i_num_2);
			
			return i_result;
		}
		
		TestResult TR_PrimitiveRawPointerList_Testing_5(){
			TestResult i_result;

			PrimitiveRawPointerList<int> i_list;

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

		void TR_PrimitiveRawPointerList_Testing(TestRunner& a_test_runner){
			// a_test_runner.map.add("PrimitiveRawPointerList Simple Constructor", TR_PrimitiveRawPointerList_Testing_1);
			// a_test_runner.map.add("PrimitiveRawPointerList adding 3 elements", TR_PrimitiveRawPointerList_Testing_2);
			// a_test_runner.map.add("PrimitiveRawPointerList adding 3 elements and replace", TR_PrimitiveRawPointerList_Testing_3);
			// a_test_runner.map.add("PrimitiveRawPointerList putPointer", TR_PrimitiveRawPointerList_Testing_4);
			a_test_runner.map.add("PrimitiveRawPointerList setPointer", TR_PrimitiveRawPointerList_Testing_5);
		}

	}

#endif
