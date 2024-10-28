
#ifndef TR_CharArray_Testing_hpp
	#define TR_CharArray_Testing_hpp
	
	#include "pankey.hpp"

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
			
		TestResult TR_CharArray_Testing_19(){
			TestResult result;
			
			CharArray array = "-hellow-world-";//14

			CharArray i_part_1 = array.removeAllInitialValues('-');
			CharArray i_part_2 = array.removeAllEndingValues('-');
			CharArray i_part_3 = array.removeAllInitialAndEndingValues('-');

			result.assertNoteEqual("array removeAllInitialValues size should be 13", i_part_1.length(), 13);
			result.assertNoteEqual("array part 1 should be hellow-world-", i_part_1, CharArray("hellow-world-"));

			result.assertNoteEqual("array removeAllEndingValues size should be 13", i_part_2.length(), 13);
			result.assertNoteEqual("array part 1 should be -hellow-world", i_part_2, CharArray("-hellow-world"));

			result.assertNoteEqual("array removeAllInitialAndEndingValues size should be 12", i_part_3.length(), 12);
			result.assertNoteEqual("array part 1 should be hellow-world", i_part_3, CharArray("hellow-world"));

			int i_split_size = array.getSplitSize('-');
			int i_part_size = array.getPartSize('-');

			result.assertNoteEqual("array splits 1 time", i_split_size, 1);
			result.assertNoteEqual("array splits in to parts", i_part_size, 2);

			CharArray i_part_4 = array.split(0, '-');
			CharArray i_part_5 = array.split(1, '-');

			result.assertNoteEqual("array should contain 2 ints", i_part_4.length(), 6);
			result.assertNoteEqual("array part should be hellow", i_part_4, CharArray("hellow"));

			result.assertNoteEqual("array should contain 2 ints", i_part_5.length(), 5);
			result.assertNoteEqual("array part should be world", i_part_5, CharArray("world"));
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_20(){
			TestResult result;
			
			CharArray i_num = "15.15f";

			result.assertNoteEqual("array should contain 6 chars", i_num.length(), 6);
			result.assertTrue("array should be a float", i_num.isFloat());
			// result.assertNoteEqual("float should be 15.15f", i_num.toFloat(), 15.15f);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_21(){
			TestResult result;
			
			CharArray i_num = "15.15";

			result.assertNoteEqual("array should contain 6 chars", i_num.length(), 5);
			result.assertTrue("array should be a float", i_num.isFloat());
			// result.assertNoteEqual("float should be 15.15f", i_num.toFloat(), 15.15f);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_22(){
			TestResult result;
			
			CharArray i_num = "0";

			result.assertNoteEqual("array should contain 1 chars", i_num.length(), 1);
			result.assertTrue("array should be a bool", i_num.isBool());
			result.assertNoteEqual("bool should be false", i_num.toBool(), false);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_23(){
			TestResult result;
			
			CharArray i_num = "1";

			result.assertNoteEqual("array should contain 1 chars", i_num.length(), 1);
			result.assertTrue("array should be a bool", i_num.isBool());
			result.assertNoteEqual("bool should be true", i_num.toBool(), true);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_24(){
			TestResult result;
			
			CharArray i_num = "true";

			result.assertNoteEqual("array should contain 4 chars", i_num.length(), 4);
			result.assertTrue("array should be a bool", i_num.isBool());
			result.assertNoteEqual("bool should be true", i_num.toBool(), true);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_25(){
			TestResult result;
			
			CharArray i_num = "TRUE";

			result.assertNoteEqual("array should contain 4 chars", i_num.length(), 4);
			result.assertTrue("array should be a bool", i_num.isBool());
			result.assertNoteEqual("bool should be true", i_num.toBool(), true);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_26(){
			TestResult result;
			
			CharArray i_num = "false";

			result.assertNoteEqual("array should contain 5 chars", i_num.length(), 5);
			result.assertTrue("array should be a bool", i_num.isBool());
			result.assertNoteEqual("bool should be false", i_num.toBool(), false);
			
			return result;
		}
			
		TestResult TR_CharArray_Testing_27(){
			TestResult result;
			
			CharArray i_num = "FALSE";

			result.assertNoteEqual("array should contain 5 chars", i_num.length(), 5);
			result.assertTrue("array should be a bool", i_num.isBool());
			result.assertNoteEqual("bool should be false", i_num.toBool(), false);
			
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
			a_test_runner.map.add("CharArray splits", TR_CharArray_Testing_19);
			a_test_runner.map.add("CharArray isFloat, toFloat with f at the end", TR_CharArray_Testing_20);
			a_test_runner.map.add("CharArray isFloat, toFloat with out f at the end", TR_CharArray_Testing_21);
			a_test_runner.map.add("CharArray isBool, toBool with array 0", TR_CharArray_Testing_22);
			a_test_runner.map.add("CharArray isBool, toBool with array 1", TR_CharArray_Testing_23);
			a_test_runner.map.add("CharArray isBool, toBool with array true", TR_CharArray_Testing_24);
			a_test_runner.map.add("CharArray isBool, toBool with array TRUE", TR_CharArray_Testing_25);
			a_test_runner.map.add("CharArray isBool, toBool with array false", TR_CharArray_Testing_26);
			a_test_runner.map.add("CharArray isBool, toBool with array FALSE", TR_CharArray_Testing_27);
		}
	}

#endif
