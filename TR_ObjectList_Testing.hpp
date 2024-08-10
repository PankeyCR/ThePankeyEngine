
#ifndef TR_ObjectList_Testing_hpp
	#define TR_ObjectList_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Variable.hpp"
	#include "Value.hpp"
	#include "TypeList.hpp"

	namespace higgs{

		class BaseTestExample{public: int num = 0;};
		class TestExample : public BaseTestExample{
			public:
			TestExample(){}
			TestExample(int x){num = x;}
		};
		
		TestResult TR_ObjectList_Testing_1(){
			TestResult result;

			OList<BaseTestExample> i_list;
			
			result.assertTrue("storage has to be null", i_list.isEmpty());
			return result;
		}
		
		TestResult TR_ObjectList_Testing_2(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample();
			obj<BaseTestExample> i_var_1 = TestExample();
			obj<BaseTestExample> i_var_2 = TestExample();
			obj<BaseTestExample> i_var_3 = TestExample();
			obj<BaseTestExample> i_var_4 = TestExample();
			obj<BaseTestExample> i_var_5 = TestExample();

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);
			i_list.add(i_var_4);
			i_list.add(i_var_5);

			result.assertNoteEqual("index should be the same", i_list.length(), 6);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_3(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(15);
			obj<BaseTestExample> i_var_1 = TestExample();

			i_list.add(i_var_0);
			i_list.add(i_var_1);

			i_list.replace(0, 1);

			obj<BaseTestExample> i_var_10 = i_list.get(1);

			if(!i_var_0.isValidObject<TestExample>()){
				result.catchError("not a valid object 0");
				return result;
			}

			if(!i_var_10.isValidObject<TestExample>()){
				result.catchError("not a valid object 1");
				return result;
			}

			TestExample i_var_00 = i_var_0.getValue<TestExample>();
			TestExample i_var_01 = i_var_10.getValue<TestExample>();

			result.assertEqual("value should be the same", i_var_00.num, i_var_01.num);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_4(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);

			i_list.add(i_var_0);
			i_list.add(i_var_1);

			obj<BaseTestExample> i_var_11 = i_list.get(i_var_1);
			TestExample i_val_1 = i_var_11.getValue<TestExample>();

			result.assertEqual("index should be the same", i_val_1.num, 1);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_5(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);

			i_list.add(i_var_0);
			i_list.add(i_var_1);

			result.assertTrue("OList contain var", i_list.contain(i_var_1));

			return result;
		}
		
		TestResult TR_ObjectList_Testing_6(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);

			i_list.add(i_var_0);
			i_list.add(i_var_1);

			result.assertEqual("var index should be 1", i_list.getIndex(i_var_1), 1);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_7(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);

			i_list.add(i_var_0);
			i_list.add(i_var_1);

			i_list.remove(i_var_0);

			result.assertEqual("var index should be 0", i_list.getIndex(i_var_1), 0);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_8(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);

			i_list.add(i_var_0);
			i_list.add(i_var_1);

			i_list.remove(0);

			result.assertEqual("var index should be 0", i_list.getIndex(i_var_1), 0);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_9(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);

			i_list.removeFirstIndex(2);

			result.assertEqual("var index should be 1", i_list.length(), 1);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_10(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);

			i_list.removeLastIndex(2);

			result.assertEqual("var index should be 1", i_list.length(), 1);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_11(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);
			obj<BaseTestExample> i_var_3 = TestExample(3);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);

			i_list.removePart(1, 2);

			result.assertNoteEqual("var index should be 2", i_list.length(), 2);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_12(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);
			obj<BaseTestExample> i_var_3 = TestExample(3);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);

			i_list.removeFirst();

			result.assertNoteEqual("var index should be 3", i_list.length(), 3);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_13(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);
			obj<BaseTestExample> i_var_3 = TestExample(3);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);

			i_list.removeLast();

			result.assertNoteEqual("var index should be 3", i_list.length(), 3);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_14(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);
			obj<BaseTestExample> i_var_3 = TestExample(3);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);

			i_list.clear();

			result.assertNoteEqual("var index should be 3", i_list.length(), 0);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_15(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);
			obj<BaseTestExample> i_var_3 = TestExample(3);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);

			result.assertNoteEqual("value should be the same", i_var_0.getValue<TestExample>().num, 0);
			result.assertNoteEqual("value should be the same", i_var_1.getValue<TestExample>().num, 1);

			result.assertNoteEqual("var index should be 3", i_list.length(), 4);

			for(int x = 0; x < i_list.length(); x++){
				obj<BaseTestExample> i_var = i_list.get(x);
				result.assertNoteEqual("storage value should be the same as the index", i_var.getValue<TestExample>().num, x);
			}

			return result;
		}
		
		TestResult TR_ObjectList_Testing_16(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);

			i_list.put(i_var_0);
			i_list.put(i_var_1);
			i_list.put(i_var_1);
			i_list.put(i_var_2);

			result.assertNoteEqual("var index should be 3", i_list.length(), 3);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_17(){
			TestResult result;

			OList<BaseTestExample> i_list;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;

			i_list.put(i_var_0);
			i_list.put(i_var_1);
			i_list.put(i_var_1);
			i_list.put(i_var_2);

			result.assertNoteEqual("var index should be 0", i_list.length(), 0);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_18(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);
			obj<BaseTestExample> i_var_3 = TestExample(3);
			obj<BaseTestExample> i_var_4 = TestExample(4);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);

			i_list.set(2, i_var_4);

			var i_var_11 = i_list.get(2);
			TestExample i_val_1 = i_var_11.getValue<TestExample>();

			result.assertNoteEqual("var index should be 4", i_val_1.num, 4);

			result.assertNoteEqual("var index should be 4", i_list.length(), 4);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_19(){
			TestResult result;

			OList<BaseTestExample> i_list;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;
			val<int> i_var_4 = 4;

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);

			i_list.set(2, i_var_4);

			var i_var_11 = i_list.get(2);
			TestExample i_val_1 = i_var_11.getValue<TestExample>();

			result.assertNoteEqual("var value should be 0", i_val_1.num, 0);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_20(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);
			obj<BaseTestExample> i_var_3 = TestExample(3);
			obj<BaseTestExample> i_var_4 = TestExample(4);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_3);
			i_list.add(i_var_4);

			i_list.insert(2, i_var_2);

			result.assertNoteEqual("OList index should be 5", i_list.length(), 5);

			for(int x = 0; x < i_list.length(); x++){
				val<int> i_var = i_list.get(x);
				result.assertNoteEqual("storage value should be the same as the index", i_var.getValue(), x);
			}

			return result;
		}
		
		TestResult TR_ObjectList_Testing_21(){
			TestResult result;

			OList<BaseTestExample> i_list;

			val<int> i_var_0 = 0;
			val<int> i_var_1 = 1;
			val<int> i_var_2 = 2;
			val<int> i_var_3 = 3;
			val<int> i_var_4 = 4;

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_3);
			i_list.add(i_var_4);

			i_list.insert(2, i_var_2);

			result.assertNoteEqual("OList index should be 0", i_list.length(), 0);

			return result;
		}
		
		TestResult TR_ObjectList_Testing_22(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);
			obj<BaseTestExample> i_var_3 = TestExample(3);
			obj<BaseTestExample> i_var_4 = TestExample(4);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);
			i_list.add(i_var_4);

			OList<BaseTestExample> i_list_2;

			i_list_2.move(i_list);

			result.assertNoteEqual("OList index should be 5", i_list_2.length(), 5);
			result.assertTrue("OList should be empty", i_list.isEmpty());

			for(int x = 0; x < i_list_2.length(); x++){
				obj<BaseTestExample> i_var = i_list_2.get(x);
				result.assertNoteEqual("storage value should be the same as the index", i_var.getValue<TestExample>().num, x);
			}

			return result;
		}
		
		TestResult TR_ObjectList_Testing_23(){
			TestResult result;

			OList<BaseTestExample> i_list;

			obj<BaseTestExample> i_var_0 = TestExample(0);
			obj<BaseTestExample> i_var_1 = TestExample(1);
			obj<BaseTestExample> i_var_2 = TestExample(2);
			obj<BaseTestExample> i_var_3 = TestExample(3);
			obj<BaseTestExample> i_var_4 = TestExample(4);

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);
			i_list.add(i_var_4);

			OList<BaseTestExample> i_list_2;

			i_list_2.duplicate(i_list);

			result.assertNoteEqual("OList index should be 5", i_list.length(), 5);
			result.assertNoteEqual("OList index should be 5", i_list_2.length(), 5);

			for(int x = 0; x < i_list_2.length(); x++){
				obj<BaseTestExample> i_var = i_list_2.get(x);
				result.assertNoteEqual("storage value should be the same as the index", i_var.getValue<TestExample>().num, x);
			}

			return result;
		}

		void TR_ObjectList_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("OList Constructor", TR_ObjectList_Testing_1);
			a_test_runner.map.add("OList add and length", TR_ObjectList_Testing_2);
			a_test_runner.map.add("OList replace and get", TR_ObjectList_Testing_3);
			a_test_runner.map.add("OList get by obj", TR_ObjectList_Testing_4);
			a_test_runner.map.add("OList contain", TR_ObjectList_Testing_5);
			a_test_runner.map.add("OList getIndex", TR_ObjectList_Testing_6);
			a_test_runner.map.add("OList remove member", TR_ObjectList_Testing_7);
			a_test_runner.map.add("OList remove index", TR_ObjectList_Testing_8);
			a_test_runner.map.add("OList removeFirstIndex", TR_ObjectList_Testing_9);
			a_test_runner.map.add("OList removeLastIndex", TR_ObjectList_Testing_10);
			a_test_runner.map.add("OList removePart", TR_ObjectList_Testing_11);
			a_test_runner.map.add("OList removeFirst", TR_ObjectList_Testing_12);
			a_test_runner.map.add("OList removeLast", TR_ObjectList_Testing_13);
			a_test_runner.map.add("OList clear", TR_ObjectList_Testing_14);
			a_test_runner.map.add("OList add value", TR_ObjectList_Testing_15);
			a_test_runner.map.add("OList put var", TR_ObjectList_Testing_16);
			a_test_runner.map.add("OList put value", TR_ObjectList_Testing_17);
			a_test_runner.map.add("OList set var", TR_ObjectList_Testing_18);
			a_test_runner.map.add("OList set value", TR_ObjectList_Testing_19);
			a_test_runner.map.add("OList insert var", TR_ObjectList_Testing_20);
			a_test_runner.map.add("OList insert value", TR_ObjectList_Testing_21);
			a_test_runner.map.add("OList move", TR_ObjectList_Testing_22);
			a_test_runner.map.add("OList duplicate", TR_ObjectList_Testing_23);
		}	

	}

#endif
