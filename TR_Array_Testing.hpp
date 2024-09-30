
#ifndef TR_Array_Testing_hpp
	#define TR_Array_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Array.hpp"
	#include "Cast.hpp"

	namespace pankey{
			
		TestResult TR_Array_Testing_1(){
			TestResult result;
			
  			Array<int> array;

			array.addLocalValue(1);
			array.addLocalValue(2);
			array.addLocalValue(3);
			array.addLocalValue(4);
			array.addLocalValue(5);

			result.assertEqual(0, "array value position 0", array.get(0), 1);
			result.assertEqual(1, "array value position 1", array.get(1), 2);
			result.assertEqual(2, "array value position 4", array.get(4), 5);
			result.assertEqual(3, "array position", array.getPosition(), 5);
			
			return result;
		}
			
		TestResult TR_Array_Testing_2(){
			TestResult result;
			
  			Array<int> array;

			array.addLocalValue(1);
			array.addLocalValue(2);
			array.addLocalValue(3);
			array.addLocalValue(4);
			array.addLocalValue(5);
  			
			array.set(2, 91);

			result.assertEqual(0, "array value position 0", array.get(0), 1);
			result.assertEqual(1, "array value position 1", array.get(1), 2);
			result.assertEqual(2, "array value position 4", array.get(4), 5);
			result.assertEqual(3, "array position", array.getPosition(), 5);
			result.assertEqual(4, "array value position 2", array.get(2), 91);
			
			return result;
		}
			
		TestResult TR_Array_Testing_3(){
			TestResult result;
			
  			Array<int> array = {1,2,3,4,5};

			result.assertEqual(0, "array value position 0", array.get(0), 1);
			result.assertEqual(1, "array value position 1", array.get(1), 2);
			result.assertEqual(2, "array value position 4", array.get(4), 5);
			result.assertEqual(3, "array position", array.getPosition(), 5);
			
			return result;
		}
			
		TestResult TR_Array_Testing_4(){
			TestResult result;
			
  			Array<int> array = {1,2,3,4,5};
  			Array<int> array_2 = array;

			result.assertEqual(0, "array value position 0", array_2.get(0), 1);
			result.assertEqual(1, "array value position 1", array_2.get(1), 2);
			result.assertEqual(2, "array value position 4", array_2.get(4), 5);
			result.assertEqual(3, "array position", array_2.getPosition(), 5);
			
			return result;
		}
			
		TestResult TR_Array_Testing_5(){
			TestResult result;
			
  			Array<int> array = {1,2,3,4,5};
  			Array<int> array_2 = move(array);

			result.assertEqual(0, "array value position 0", array_2.get(0), 1);
			result.assertEqual(1, "array value position 1", array_2.get(1), 2);
			result.assertEqual(2, "array value position 4", array_2.get(4), 5);
			result.assertEqual(3, "array position", array_2.getPosition(), 5);
			
			return result;
		}
			
		TestResult TR_Array_Testing_6(){
			TestResult result;
			
  			Array<int> array = {1,2,3,4,5};

			result.assertEqual(0, "array value position 0", array.get(0), array[0]);
			
			return result;
		}
			
		TestResult TR_Array_Testing_7(){
			TestResult result;
			
  			Array<int> array = {1,2,3,4,5};
  			Array<int> array_2 = array.addValue(20);

			result.assertEqual(0, "array value position 0", array_2.get(0), 1);
			result.assertEqual(1, "array value position 1", array_2.get(1), 2);
			result.assertEqual(2, "array value position 4", array_2.get(4), 5);
			result.assertEqual(3, "array position", array_2.getPosition(), 6);
			result.assertEqual(4, "array value position 5", array_2.get(5), 20);
			
			return result;
		}
			
		TestResult TR_Array_Testing_8(){
			TestResult result;
			
  			Array<int> array = {1,2,3,4,5};
			Array<int> array_2 = {1,2,3,4,5};

			Array<int> array_3 = array.addArray(array_2);

			result.assertEqual(0, "array value position 0", array_3.get(0), 1);
			result.assertEqual(1, "array value position 1", array_3.get(1), 2);
			result.assertEqual(2, "array value position 4", array_3.get(4), 5);
			result.assertEqual(3, "array position", array_3.getPosition(), 10);
			result.assertEqual(4, "array value position 5", array_3.get(5), 1);
			result.assertEqual(5, "array value position 5", array_3.get(6), 2);
			
			return result;
		}
			
		TestResult TR_Array_Testing_9(){
			TestResult result;
			
  			Array<int> array = {1,2,3,4,5};

			Array<int> array_2 = array.addLocal();

			result.assertEqual(0, "array value position 0", array_2.get(0), 1);
			result.assertEqual(1, "array value position 1", array_2.get(1), 2);
			result.assertEqual(2, "array value position 4", array_2.get(4), 5);
			result.assertEqual(3, "array position", array_2.getPosition(), 10);
			result.assertEqual(4, "array value position 5", array_2.get(5), 1);
			result.assertEqual(5, "array value position 5", array_2.get(6), 2);
			
			return result;
		}
			
		TestResult TR_Array_Testing_10(){
			TestResult result;
			
  			Array<int> array = {1,2,3,4,5};

			result.assertTrue(0, "array value position 0", array.contain(3));
			
			return result;
		}
			
		TestResult TR_Array_Testing_11(){
			TestResult result;
			
			Array<int> array = {1,3,2,3,4,3,5};

			int index = array.getFirstIndex(3);

			result.assertEqual(0, "array value position 0", index, 1);
			
			return result;
		}
			
		TestResult TR_Array_Testing_12(){
			TestResult result;
			
			Array<int> array = {1,3,2,3,4,3,5};

			int index = array.getLastIndex(3);

			result.assertEqual(0, "array value position 0", index, 5);
			
			return result;
		}
			
		TestResult TR_Array_Testing_13(){
			TestResult result;
			
			Array<int> array = {1,2,3,4,5};

			array.remove(2);//position of the array

			result.assertTrue(0, "array has remove an index", !array.contain(3));
			
			return result;
		}
			
		TestResult TR_Array_Testing_14(){
			TestResult result;
			
			Array<int> array = {1,2,3,4,2,5};

			array.removeFirst(2);//value of the array

			result.assertNotEqual(0, "array has remove an index", array.get(1), 2);
			
			return result;
		}
			
		TestResult TR_Array_Testing_15(){
			TestResult result;
			
			Array<int> array = {1,2,3,4,2,5};

			array.removeLast(2);//value of the array

			result.assertNotEqual(0, "array has remove an index", array.get(4), 2);
			
			return result;
		}
			
		TestResult TR_Array_Testing_16(){
			TestResult result;
			
			Array<int> array = {1,2,3,4,2,5};

			array = Array<int>(5,4,3,2,1);

			result.assertEqual(0, "array = operator", array.get(3), 2);
			result.assertEqual(0, "array = operator", array.get(4), 1);
			
			return result;
		}
			
		TestResult TR_Array_Testing_17(){
			TestResult result;
			
			Array<int> array = {1,2,3,4,2,5};

			array = move(Array<int>(5,4,3,2,1));

			result.assertEqual(0, "array = move operator", array.get(3), 2);
			result.assertEqual(0, "array = move operator", array.get(4), 1);
			
			return result;
		}
			
		TestResult TR_Array_Testing_18(){
			TestResult result;
			
			Array<int> array = {1,2,3,4,2,5};

			array = 5;

			result.assertEqual(0, "array = value operator", array.get(0), 5);
			
			return result;
		}
			
		TestResult TR_Array_Testing_19(){
			TestResult result;
			
			Array<int> array = {1,2,3,4,5,6,7};

  			array.remove(1,3);//1 = start, 3 = size

			result.assertNotEqual(0, "array remove", array.get(1), 2);
			result.assertNotEqual(1, "array remove", array.get(2), 3);
			result.assertNotEqual(2, "array remove", array.get(3), 4);
			
			return result;
		}
			
		TestResult TR_Array_Testing_20(){
			TestResult result;
			
			Array<int> array = {1,2,3,4,2,5};

  			array.insertLocalValue(2, 150);

			result.assertEqual(0, "array insertLocalValue", array.get(2), 150);
			
			return result;
		}
			
		TestResult TR_Array_Testing_21(){
			TestResult result;
			
			Array<int> array = {1,2,3,4,2,5};

			Array<int> array_2 = {11,12,13,14,15};
			
			array.insertLocalArray(2, array_2);

			result.assertEqual(0, "array insertLocalArray", array.get(2), 11);
			
			return result;
		}
		
		void TR_Array_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Array addLocalValue", TR_Array_Testing_1);
			a_test_runner.map.add("Array set", TR_Array_Testing_2);
			a_test_runner.map.add("Array Contructor", TR_Array_Testing_3);
			a_test_runner.map.add("Array Copy Contructor", TR_Array_Testing_4);
			a_test_runner.map.add("Array Move Contructor", TR_Array_Testing_5);
			a_test_runner.map.add("Array [] operator", TR_Array_Testing_6);
			a_test_runner.map.add("Array addValue", TR_Array_Testing_7);
			a_test_runner.map.add("Array addArray", TR_Array_Testing_8);
			a_test_runner.map.add("Array addLocal", TR_Array_Testing_9);
			a_test_runner.map.add("Array contain", TR_Array_Testing_10);
			a_test_runner.map.add("Array getFirstIndex", TR_Array_Testing_11);
			a_test_runner.map.add("Array getLastIndex", TR_Array_Testing_12);
			a_test_runner.map.add("Array remove", TR_Array_Testing_13);
			a_test_runner.map.add("Array removeFirst", TR_Array_Testing_14);
			a_test_runner.map.add("Array removeLast", TR_Array_Testing_15);
			a_test_runner.map.add("Array = operator", TR_Array_Testing_16);
			a_test_runner.map.add("Array = move operator", TR_Array_Testing_17);
			a_test_runner.map.add("Array = value operator", TR_Array_Testing_18);
			a_test_runner.map.add("Array remove", TR_Array_Testing_19);
			a_test_runner.map.add("Array insertLocalValue", TR_Array_Testing_20);
			a_test_runner.map.add("Array insertLocalArray", TR_Array_Testing_21);
		}
	}

#endif
