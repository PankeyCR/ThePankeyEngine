
#ifndef TR_MemberArrayMap_Testing_hpp
	#define TR_MemberArrayMap_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Variable.hpp"
	#include "Value.hpp"
	#include "MemberArrayMap.hpp"

	namespace pankey{
		
		TestResult TR_MemberArrayMap_Testing_1(){
			TestResult result;

			Map i_map;
			
			result.assertTrue("storage has to be null", i_map.isEmpty());
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_2(){
			TestResult result;

			Map i_map;

			var i_key = 15;
			var i_value = 20;

			i_map.add(i_key, i_value);

			var i_v = i_map.getValueByPointer(i_key);
			
			result.assertNoteEqual("with a 15 key a 20 value should apear", i_v.getValue<int>(), 20);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_3(){
			TestResult result;

			Map i_map;

			var i_key = 15;
			var i_value = 20;

			var i_key_1 = 15;
			var i_value_1 = 20;

			i_map.add(i_key, i_value);
			i_map.add(i_key_1, i_value_1);
			
			result.assertNoteEqual("map length should be 2", i_map.length(), 2);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_4(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);

			i_map.replace(0, 1);

			var i_value_11 = i_map.getValue(0);
			var i_value_22 = i_map.getValue(1);
			
			result.assertNoteEqual("value should be 40", i_value_11.getValue<int>(), 40);
			result.assertNoteEqual("value should be 20", i_value_22.getValue<int>(), 20);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_5(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			i_map.add(i_key_1, i_value_1);
			
			result.assertTrue("map should contain var", i_map.containByPointer(i_key_1));
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_6(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			var i_key_3 = 65;
			var i_value_3 = 70;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);
			i_map.add(i_key_3, i_value_3);

			int i_index = i_map.getIndexByPointer(i_key_2);
			
			result.assertNoteEqual("map index should be 1", i_index, 1);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_7(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			var i_key_3 = 65;
			var i_value_3 = 70;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);
			i_map.add(i_key_3, i_value_3);

			bool i_removed = i_map.removeByPointer(i_key_2);
			
			result.assertNoteEqual("should be true", i_removed, true);
			result.assertNoteEqual("map length should be 2", i_map.length(), 2);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_8(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			var i_key_3 = 65;
			var i_value_3 = 70;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);
			i_map.add(i_key_3, i_value_3);

			var i_value = i_map.remove(1);
			
			result.assertNoteEqual("var should be 40", i_value.getValue<int>(), 40);
			result.assertNoteEqual("map length should be 2", i_map.length(), 2);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_9(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			var i_key_3 = 65;
			var i_value_3 = 70;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);
			i_map.add(i_key_3, i_value_3);

			bool i_removed = i_map.removeFirstIndex(2);

			var i_value = i_map.getValue(0);
			
			result.assertNoteEqual("should be true", i_removed, true);
			result.assertNoteEqual("var should be 70", i_value.getValue<int>(), 70);
			result.assertNoteEqual("map length should be 1", i_map.length(), 1);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_10(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			var i_key_3 = 65;
			var i_value_3 = 70;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);
			i_map.add(i_key_3, i_value_3);

			bool i_removed = i_map.removeLastIndex(2);

			var i_value = i_map.getValue(0);
			
			result.assertNoteEqual("should be true", i_removed, true);
			result.assertNoteEqual("var should be 70", i_value.getValue<int>(), 20);
			result.assertNoteEqual("map length should be 1", i_map.length(), 1);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_11(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			var i_key_3 = 65;
			var i_value_3 = 70;

			var i_key_4 = 85;
			var i_value_4 = 90;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);
			i_map.add(i_key_3, i_value_3);
			i_map.add(i_key_4, i_value_4);

			bool i_removed = i_map.removePart(1, 2);

			var i_value_00 = i_map.getValue(0);
			var i_value_11 = i_map.getValue(1);
			
			result.assertNoteEqual("should be true", i_removed, true);
			result.assertNoteEqual("var should be 20", i_value_00.getValue<int>(), 20);
			result.assertNoteEqual("var should be 90", i_value_11.getValue<int>(), 90);
			result.assertNoteEqual("map length should be 2", i_map.length(), 2);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_12(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			var i_key_3 = 65;
			var i_value_3 = 70;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);
			i_map.add(i_key_3, i_value_3);

			bool i_removed = i_map.removeFirst();

			var i_value_00 = i_map.getValue(0);
			var i_value_11 = i_map.getValue(1);
			
			result.assertNoteEqual("should be true", i_removed, true);
			result.assertNoteEqual("var should be 20", i_value_00.getValue<int>(), 40);
			result.assertNoteEqual("var should be 90", i_value_11.getValue<int>(), 70);
			result.assertNoteEqual("map length should be 2", i_map.length(), 2);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_13(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			var i_key_3 = 65;
			var i_value_3 = 70;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);
			i_map.add(i_key_3, i_value_3);

			bool i_removed = i_map.removeLast();

			var i_value_00 = i_map.getValue(0);
			var i_value_11 = i_map.getValue(1);
			
			result.assertNoteEqual("should be true", i_removed, true);
			result.assertNoteEqual("var should be 20", i_value_00.getValue<int>(), 20);
			result.assertNoteEqual("var should be 90", i_value_11.getValue<int>(), 40);
			result.assertNoteEqual("map length should be 2", i_map.length(), 2);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_14(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			var i_key_2 = 35;
			var i_value_2 = 40;

			var i_key_3 = 65;
			var i_value_3 = 70;

			var i_key_4 = 85;
			var i_value_4 = 90;

			i_map.add(i_key_1, i_value_1);
			i_map.add(i_key_2, i_value_2);
			i_map.add(i_key_3, i_value_3);
			i_map.add(i_key_4, i_value_4);

			bool i_removed = i_map.clear();
			
			result.assertNoteEqual("should be true", i_removed, true);
			result.assertTrue("it should be empty", i_map.isEmpty());
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_15(){
			TestResult result;

			Map i_map;

			var i_key_1 = 15;
			var i_value_1 = 20;

			i_map.put(i_key_1, i_value_1);
			i_map.put(i_key_1, i_value_1);
			i_map.put(i_key_1, i_value_1);
			i_map.put(i_key_1, i_value_1);
			
			result.assertNoteEqual("lenght should be 1", i_map.length(), 1);
			return result;
		}
		
		TestResult TR_MemberArrayMap_Testing_16(){
			TestResult result;

			Map i_map;

			duo i_duo = duo(var(10), var(20));

			i_map.put(i_duo);

			var i_value = i_map.getValueByPointer(i_duo.getMember());
			
			result.assertNoteEqual("lenght should be 1", i_map.length(), 1);
			result.assertNoteEqual("var should be 20", i_value.getValue<int>(), 20);
			return result;
		}

		void TR_MemberArrayMap_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("MemberArrayMap Constructor", TR_MemberArrayMap_Testing_1);
			a_test_runner.map.add("MemberArrayMap add, getByPointer", TR_MemberArrayMap_Testing_2);
			a_test_runner.map.add("MemberArrayMap add, length", TR_MemberArrayMap_Testing_3);
			a_test_runner.map.add("MemberArrayMap replace, get int", TR_MemberArrayMap_Testing_4);
			a_test_runner.map.add("MemberArrayMap contain", TR_MemberArrayMap_Testing_5);
			a_test_runner.map.add("MemberArrayMap getIndex", TR_MemberArrayMap_Testing_6);
			a_test_runner.map.add("MemberArrayMap remove", TR_MemberArrayMap_Testing_7);
			a_test_runner.map.add("MemberArrayMap remove", TR_MemberArrayMap_Testing_8);
			a_test_runner.map.add("MemberArrayMap removeFirstIndex", TR_MemberArrayMap_Testing_9);
			a_test_runner.map.add("MemberArrayMap removeLastIndex", TR_MemberArrayMap_Testing_10);
			a_test_runner.map.add("MemberArrayMap removePart", TR_MemberArrayMap_Testing_11);
			a_test_runner.map.add("MemberArrayMap removeFirst", TR_MemberArrayMap_Testing_12);
			a_test_runner.map.add("MemberArrayMap removeLast", TR_MemberArrayMap_Testing_13);
			a_test_runner.map.add("MemberArrayMap clear", TR_MemberArrayMap_Testing_14);
			a_test_runner.map.add("MemberArrayMap put", TR_MemberArrayMap_Testing_15);
			a_test_runner.map.add("MemberArrayMap put duo", TR_MemberArrayMap_Testing_16);
		}	

	}

#endif
