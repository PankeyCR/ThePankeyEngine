
#ifndef TR_TypeArrayMap_Testing_hpp
	#define TR_TypeArrayMap_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	namespace pankey{
		
		TestResult TR_TypeArrayMap_Testing_1(){
			TestResult result;

			TMap<int,int> i_map;
			
			result.assertTrue("storage has to be null", i_map.isEmpty());
			return result;
		}
		
		TestResult TR_TypeArrayMap_Testing_2(){
			TestResult result;

			TMap<int,int> i_map;

			val<int> i_key = 15;
			val<int> i_value = 20;

			i_map.add(i_key, i_value);

			var i_search = 20;

			var i_p = i_map.getKeyByPointer(i_search);
			var i_v = i_map.getKeyByValue(i_search);
			
			result.assertNoteNotEqual("key shouldnt be found by pointer", i_p.getValue<int>(), 15);
			result.assertNoteEqual("key should be found by value", i_v.getValue<int>(), 15);
			return result;
		}
		
		TestResult TR_TypeArrayMap_Testing_3(){
			TestResult result;

			TMap<int,int> i_map;

			val<int> i_key = 15;
			val<int> i_value = 20;

			i_map.add(i_key, i_value);

			var i_search = 15;

			var i_p = i_map.getValueByPointer(i_search);
			var i_v = i_map.getValueByValue(i_search);
			
			result.assertNoteNotEqual("value shouldnt be found by pointer", i_p.getValue<int>(), 20);
			result.assertNoteEqual("value should be found by value", i_v.getValue<int>(), 20);
			return result;
		}

		void TR_TypeArrayMap_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("TypeArrayMap Constructor", TR_TypeArrayMap_Testing_1);
			a_test_runner.map.add("TypeArrayMap add, getKeyByValue", TR_TypeArrayMap_Testing_2);
			a_test_runner.map.add("TypeArrayMap add, getValueByValue", TR_TypeArrayMap_Testing_3);
		}	

	}

#endif
