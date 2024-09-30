
#ifndef TR_CharArray_Testing_hpp
	#define TR_CharArray_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "CharArray.hpp"

	namespace pankey{
			
		TestResult TR_CharArray_Testing_1(){
			TestResult result;

			CharArray i_CharArray = true;
			
			result.assertEqual(0, "CharArray Constructor Bool", i_CharArray.get(0), '1');
			result.assertEqual(1, "CharArray getPosition", i_CharArray.getPosition(), 1);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_2(){
			TestResult result;

			CharArray i_CharArray = "CharArray test";
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 14);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_3(){
			TestResult result;

			CharArray i_CharArray = 123.4567f;
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 8);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_4(){
			TestResult result;

			CharArray i_CharArray = 150;
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 3);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_5(){
			TestResult result;

			CharArray i_CharArray = 1234567l;
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 7);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_6(){
			TestResult result;

			CharArray i_CharArray = -150;
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 4);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_7(){
			TestResult result;

			CharArray i_CharArray;
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 0);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_8(){
			TestResult result;

			// CharArray i_CharArray = CharArray("CharArray test example");
			
			// result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 17);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_9(){
			TestResult result;

			CharArray i_CharArray = "CharArray";
  			CharArray n_CharArray = i_CharArray.addArrayPointer(" test example");
			
			result.assertEqual(0, "CharArray getPosition", n_CharArray.getPosition(), 22);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_10(){
			TestResult result;

			CharArray i_CharArray = "hola ";
  			i_CharArray.addLocalBool(true);
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 6);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_11(){
			TestResult result;

			CharArray i_CharArray = "CharArray";
			i_CharArray.addLocalArrayPointer(" ");
			i_CharArray.addLocalArrayPointer("test");
			i_CharArray.addLocalArrayPointer(" ");
			i_CharArray.addLocalArrayPointer("example");
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 22);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_12(){
			TestResult result;

			CharArray i_CharArray = "hola ";
  			i_CharArray.addLocalFloat(123.4567f);
			
			result.assertNoteEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 13);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_13(){
			TestResult result;

			CharArray i_CharArray = "hola ";
  			i_CharArray.addLocalInt(150);
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 8);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_14(){
			TestResult result;

			// CharArray i_CharArray = "hola ";
  			// i_CharArray.addLocalCharArray(CharArray("user"));
			
			// result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 9);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_15(){
			TestResult result;

			CharArray i_CharArray = "hellow";
  			i_CharArray.addLocalValue(' ');
  			i_CharArray.addLocalArrayPointer("world");
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.getPosition(), 12);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_16(){
			TestResult result;

			CharArray i_CharArray = "hellow world";
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray.get(0), 'h');
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_17(){
			TestResult result;

			CharArray i_CharArray = "hellow world";
			void* i_CharArray_2 = new CharArray("hellow world");

			CharArray* i_CharArray_3 = (CharArray*)i_CharArray_2;
			*i_CharArray_3 = i_CharArray;
			
			result.assertEqual(0, "CharArray getPosition", i_CharArray_3->get(0), 'h');

			delete i_CharArray_3;
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_18(){
			TestResult result;

			CharArray i_CharArray = "hellow pikachu world";
			
			result.assertTrue("CharArray should contain hellow", i_CharArray.contain("hellow"));
			result.assertTrue("CharArray should contain pikachu", i_CharArray.contain("pikachu"));
			result.assertTrue("CharArray shouldnt contain pikacha", !i_CharArray.contain("pikacha"));
			result.assertTrue("CharArray shouldnt contain raychu", !i_CharArray.contain("raychu"));
			result.assertTrue("CharArray shouldnt contain worldd", !i_CharArray.contain("worldd"));
			result.assertTrue("CharArray should contain world", i_CharArray.contain("world"));
			
			return result;
		}
		
		void TR_CharArray_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("CharArray Constructor Bool", TR_CharArray_Testing_1);
			a_test_runner.map.add("CharArray Constructor chararray", TR_CharArray_Testing_2);
			a_test_runner.map.add("CharArray Constructor float", TR_CharArray_Testing_3);
			a_test_runner.map.add("CharArray Constructor int", TR_CharArray_Testing_4);
			a_test_runner.map.add("CharArray Constructor long", TR_CharArray_Testing_5);
			a_test_runner.map.add("CharArray Constructor negative int", TR_CharArray_Testing_6);
			a_test_runner.map.add("CharArray Constructor", TR_CharArray_Testing_7);
			a_test_runner.map.add("CharArray Arduino CharArray", TR_CharArray_Testing_8);
			a_test_runner.map.add("CharArray addArrayPointer", TR_CharArray_Testing_9);
			a_test_runner.map.add("CharArray addLocalBool", TR_CharArray_Testing_10);
			a_test_runner.map.add("CharArray addLocalArrayPointer", TR_CharArray_Testing_11);
			a_test_runner.map.add("CharArray addLocalFloat", TR_CharArray_Testing_12);
			a_test_runner.map.add("CharArray addLocalInt", TR_CharArray_Testing_13);
			a_test_runner.map.add("CharArray addLocalCharArray", TR_CharArray_Testing_14);
			a_test_runner.map.add("CharArray addLocalValue", TR_CharArray_Testing_15);
			a_test_runner.map.add("CharArray ", TR_CharArray_Testing_16);
			a_test_runner.map.add("CharArray assingment operator", TR_CharArray_Testing_17);
			a_test_runner.map.add("CharArray contain", TR_CharArray_Testing_18);
		}
	}

#endif
