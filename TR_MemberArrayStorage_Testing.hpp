
#ifndef TR_MemberArrayStorage_Testing_hpp
	#define TR_MemberArrayStorage_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Variable.hpp"
	#include "Value.hpp"
	#include "UniversalManager.hpp"
	#include "UniversalHolder.hpp"

	#include "MemberArrayStorage.hpp"

	namespace pankey{
		
		TestResult TR_MemberArrayStorage_Testing_1(){
			TestResult result;

			MAStorage i_storage;
			
			result.assertTrue("storage has to be null", i_storage.isNull());
			result.assertNotNull("allocator shouldnt be null", i_storage.getManager());
			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_2(){
			TestResult result;

			MAStorage i_storage;

			i_storage.expand(10);
			
			result.assertTrue("storage shouldnt be null", !i_storage.isNull());
			result.assertNotNull("allocator shouldnt be null", i_storage.getManager());
			result.assertEqual("storage size should be 10", i_storage.getSize(), 10);
			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_3(){
			TestResult result;

			MAStorage i_storage;

			i_storage.expand(10);
			
			result.assertTrue("storage shouldnt be null", !i_storage.isNull());
			result.assertNotNull("allocator shouldnt be null", i_storage.getManager());
			result.assertEqual("storage size should be 10", i_storage.getSize(), 10);

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;
			val<int> i_var_4 = 4;
			val<int> i_var_5 = 5;
			val<int> i_var_6 = 6;
			val<int> i_var_7 = 7;
			val<int> i_var_8 = 8;
			val<int> i_var_9 = 9;

			i_storage.set(0, i_var_0);
			i_storage.set(1, i_var_1);
			i_storage.set(2, i_var_2);
			i_storage.set(3, i_var_3);
			i_storage.set(4, i_var_4);
			i_storage.set(5, i_var_5);
			i_storage.set(6, i_var_6);
			i_storage.set(7, i_var_7);
			i_storage.set(8, i_var_8);
			i_storage.set(9, i_var_9);
			
			result.assertNoteEqual("value should be the same", i_var_0.getValue(), 0);
			result.assertNoteEqual("value should be the same", i_var_1.getValue(), 1);

			for(int x = 0; x < i_storage.getSize(); x++){
				val<int> i_var = i_storage.get(x);
				result.assertNoteEqual("storage value should be the same as the index", i_var.getValue(), x);
			}
			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_4(){
			TestResult result;

			MAStorage i_storage;

			i_storage.expand(10);
			
			result.assertTrue("storage shouldnt be null", !i_storage.isNull());
			result.assertNotNull("allocator shouldnt be null", i_storage.getManager());
			result.assertEqual("storage size should be 10", i_storage.getSize(), 10);
			
			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.set(0, i_var_0);
			i_storage.set(1, i_var_1);
			i_storage.set(2, i_var_2);
			i_storage.set(3, i_var_3);

			i_storage.replace(0, 1);

			val<int> i_var_10 = i_storage.get(0);
			val<int> i_var_01 = i_storage.get(1);

			result.assertNoteEqual("value should be the same", i_var_0.getValue(), i_var_01.getValue());
			result.assertNoteEqual("value should be the same", i_var_1.getValue(), i_var_10.getValue());

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_5(){
			TestResult result;

			MAStorage i_storage;

			i_storage.setExpansionRate(5);

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;
			val<int> i_var_4 = 4;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);
			i_storage.add(4, i_var_4);
			
			result.assertEqual("storage size should be 5", i_storage.getSize(), 5);

			for(int x = 0; x < i_storage.getSize(); x++){
				val<int> i_var = i_storage.get(x);
				result.assertNoteEqual("storage value should be the same as the index", i_var.getValue(), x);
			}

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_6(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			
			result.assertTrue("storage should contain i_var_1", i_storage.containByPointer(i_var_1));

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_7(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			
			result.assertEqual("storage getIndex should be 1", i_storage.getIndexByPointer(i_var_1), 1);

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_8(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			
			result.assertNotNull("storage raw pointer should be null", i_storage.getRawPointer(0));
			result.assertNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(8));

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_9(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			
			result.assertNotNull("storage holder should be null", i_storage.getHolder(0));
			result.assertNull("storage holder shouldnt be null", i_storage.getHolder(8));

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_10(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);

			i_storage.removeByPointer(i_var_0);

			val<int> i_var_00 = i_storage.get(0);
			
			result.assertTrue("storage holder should be null", i_var_00.isHolderNull());

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_11(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);

			i_storage.removeFirstIndex(4, 3);
			
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(0));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(1));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(2));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(3));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(4));

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_12(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);

			i_storage.removeLastIndex(4, 3);
			
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(0));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(1));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(2));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(3));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(4));

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_13(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);

			i_storage.removePart(1, 4, 2);
			
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(0));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(1));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(2));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(3));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(4));

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_14(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);

			i_storage.removeFirst();
			
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(0));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(1));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(2));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(3));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(4));

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_15(){
			TestResult result;

			MAStorage i_storage;

			i_storage.setExpansionRate(4);

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);

			i_storage.removeLast();
			
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(0));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(1));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(2));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(3));

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_16(){
			TestResult result;

			MAStorage i_storage;

			i_storage.setExpansionRate(4);

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);

			i_storage.clear();
			
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(0));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(1));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(2));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(3));

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_17(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);

			i_storage.removePart(1, 4, 2);

			int i_index = i_storage.reorder();
			
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(0));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(1));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(2));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(3));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(4));
			
			result.assertEqual("storage index should be 2", i_index, 2);

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_18(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);

			i_storage.removePart(1, 4, 2);

			int i_index = i_storage.reorder(1, 4, 2);
			
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(0));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(1));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(2));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(3));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(4));
			
			result.assertNoteEqual("storage index should be 2", i_index, 2);

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_19(){
			TestResult result;

			MAStorage i_storage;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_2);
			i_storage.add(3, i_var_3);

			i_storage.removePart(1, 4, 1);

			int i_index = i_storage.reorder(1, 4);
			
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(0));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(1));
			result.assertNotNull("storage raw pointer shouldnt be null", i_storage.getRawPointer(2));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(3));
			result.assertNull("storage raw pointer should be null", i_storage.getRawPointer(4));
			
			result.assertNoteEqual("storage index should be 3", i_index, 3);

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_20(){
			TestResult result;

			MAStorage i_storage;

			i_storage.expand(5);

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;
			val<int> i_var_4 = 4;

			i_storage.set(0, i_var_0);
			i_storage.set(1, i_var_3);
			i_storage.set(2, i_var_4);

			int i_index = i_storage.insert(1, 3, 2);

			i_storage.set(1, i_var_1);
			i_storage.set(2, i_var_2);

			for(int x = 0; x < i_storage.getSize(); x++){
				val<int> i_var = i_storage.get(x);
				result.assertNoteEqual("storage value should be the same as the index", i_var.getValue(), x);
			}
			
			result.assertNoteEqual("storage index should be 2", i_index, 2);

			return result;
		}
		
		TestResult TR_MemberArrayStorage_Testing_21(){
			TestResult result;

			MAStorage i_storage;

			i_storage.expand(5);

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;
			val<int> i_var_4 = 4;

			i_storage.add(0, i_var_0);
			i_storage.add(1, i_var_1);
			i_storage.add(2, i_var_3);
			i_storage.add(3, i_var_4);

			int i_index = i_storage.insert(2, 4, 1);
			
			i_storage.set(2, i_var_2);

			for(int x = 0; x < i_storage.getSize(); x++){
				val<int> i_var = i_storage.get(x);
				result.assertNoteEqual("storage value should be the same as the index", i_var.getValue(), x);
			}
			
			result.assertNoteEqual("storage index should be 2", i_index, 2);

			return result;
		}

		void TR_MemberArrayStorage_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("MemberArrayStorage Constructor", TR_MemberArrayStorage_Testing_1);
			a_test_runner.map.add("MemberArrayStorage expand size", TR_MemberArrayStorage_Testing_2);
			a_test_runner.map.add("MemberArrayStorage set numbers", TR_MemberArrayStorage_Testing_3);
			a_test_runner.map.add("MemberArrayStorage replace get", TR_MemberArrayStorage_Testing_4);
			a_test_runner.map.add("MemberArrayStorage setExpansionRate add", TR_MemberArrayStorage_Testing_5);
			a_test_runner.map.add("MemberArrayStorage add contain", TR_MemberArrayStorage_Testing_6);
			a_test_runner.map.add("MemberArrayStorage add getIndex", TR_MemberArrayStorage_Testing_7);
			a_test_runner.map.add("MemberArrayStorage add getRawPointer", TR_MemberArrayStorage_Testing_8);
			a_test_runner.map.add("MemberArrayStorage add getHolder", TR_MemberArrayStorage_Testing_9);
			a_test_runner.map.add("MemberArrayStorage add removeByPointer get", TR_MemberArrayStorage_Testing_10);
			a_test_runner.map.add("MemberArrayStorage add removeFirstIndex", TR_MemberArrayStorage_Testing_11);
			a_test_runner.map.add("MemberArrayStorage add removeLastIndex", TR_MemberArrayStorage_Testing_12);
			a_test_runner.map.add("MemberArrayStorage add removePart", TR_MemberArrayStorage_Testing_13);
			a_test_runner.map.add("MemberArrayStorage add removeFirst", TR_MemberArrayStorage_Testing_14);
			a_test_runner.map.add("MemberArrayStorage add removeLast", TR_MemberArrayStorage_Testing_15);
			a_test_runner.map.add("MemberArrayStorage add clear", TR_MemberArrayStorage_Testing_16);
			a_test_runner.map.add("MemberArrayStorage add removePart reorder", TR_MemberArrayStorage_Testing_17);
			a_test_runner.map.add("MemberArrayStorage add removePart reorder with index, length and amount", TR_MemberArrayStorage_Testing_18);
			a_test_runner.map.add("MemberArrayStorage add removePart reorder with index, length", TR_MemberArrayStorage_Testing_19);
			a_test_runner.map.add("MemberArrayStorage set insert", TR_MemberArrayStorage_Testing_20);
			a_test_runner.map.add("MemberArrayStorage add insert set", TR_MemberArrayStorage_Testing_21);
		}	

	}

#endif
