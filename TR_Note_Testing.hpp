
#ifndef TR_Note_Testing_hpp
	#define TR_Note_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Note.hpp"
	#include "MemoryRam.hpp"

	namespace pankey{
			
		TestResult TR_Note_Testing_1(){
			TestResult result;

			Note note = true;
			
			result.assertEqual(0, "Note Constructor Bool", note.get(0), '1');
			result.assertEqual(1, "Note getPosition", note.getPosition(), 1);
			
			return result;
		}
			
		TestResult TR_Note_Testing_2(){
			TestResult result;

			Note note = "note test";
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 9);
			
			return result;
		}
			
		TestResult TR_Note_Testing_3(){
			TestResult result;

			Note note = 123.4567f;
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 8);
			
			return result;
		}
			
		TestResult TR_Note_Testing_4(){
			TestResult result;

			Note note = 150;
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 3);
			
			return result;
		}
			
		TestResult TR_Note_Testing_5(){
			TestResult result;

			Note note = 1234567l;
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 7);
			
			return result;
		}
			
		TestResult TR_Note_Testing_6(){
			TestResult result;

			Note note = -150;
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 4);
			
			return result;
		}
			
		TestResult TR_Note_Testing_7(){
			TestResult result;

			Note note;
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 0);
			
			return result;
		}
			
		TestResult TR_Note_Testing_8(){
			TestResult result;

			// Note note = String("note test example");
			
			// result.assertEqual(0, "Note getPosition", note.getPosition(), 17);
			
			return result;
		}
			
		TestResult TR_Note_Testing_9(){
			TestResult result;

			Note note = "note";
  			Note n_note = note.addArrayPointer(" test example");
			
			result.assertEqual(0, "Note getPosition", n_note.getPosition(), 17);
			
			return result;
		}
			
		TestResult TR_Note_Testing_10(){
			TestResult result;

			Note note = "hola ";
  			note.addLocalBool(true);
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 6);
			
			return result;
		}
			
		TestResult TR_Note_Testing_11(){
			TestResult result;

			Note note = "note";
			note.addLocalArrayPointer(" ");
			note.addLocalArrayPointer("test");
			note.addLocalArrayPointer(" ");
			note.addLocalArrayPointer("example");
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 17);
			
			return result;
		}
			
		TestResult TR_Note_Testing_12(){
			TestResult result;

			Note note = "hola ";
  			note.addLocalFloat(123.4567f);
			
			result.assertNoteEqual(0, "Note getPosition", note.getPosition(), 13);
			
			return result;
		}
			
		TestResult TR_Note_Testing_13(){
			TestResult result;

			Note note = "hola ";
  			note.addLocalInt(150);
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 8);
			
			return result;
		}
			
		TestResult TR_Note_Testing_14(){
			TestResult result;

			// Note note = "hola ";
  			// note.addLocalNote(String("user"));
			
			// result.assertEqual(0, "Note getPosition", note.getPosition(), 9);
			
			return result;
		}
			
		TestResult TR_Note_Testing_15(){
			TestResult result;

			Note note = "hellow";
  			note.addLocalValue(' ');
  			note.addLocalArrayPointer("world");
			
			result.assertEqual(0, "Note getPosition", note.getPosition(), 12);
			
			return result;
		}
			
		TestResult TR_Note_Testing_16(){
			TestResult result;

			Note note = "hellow world";
			
			result.assertEqual(0, "Note getPosition", note.get(0), 'h');
			
			return result;
		}
		
		void TR_Note_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Note Constructor Bool", TR_Note_Testing_1);
			a_test_runner.map.add("Note Constructor chararray", TR_Note_Testing_2);
			a_test_runner.map.add("Note Constructor float", TR_Note_Testing_3);
			a_test_runner.map.add("Note Constructor int", TR_Note_Testing_4);
			a_test_runner.map.add("Note Constructor long", TR_Note_Testing_5);
			a_test_runner.map.add("Note Constructor negative int", TR_Note_Testing_6);
			a_test_runner.map.add("Note Constructor", TR_Note_Testing_7);
			a_test_runner.map.add("Note Arduino String", TR_Note_Testing_8);
			a_test_runner.map.add("Note addArrayPointer", TR_Note_Testing_9);
			a_test_runner.map.add("Note addLocalBool", TR_Note_Testing_10);
			a_test_runner.map.add("Note addLocalArrayPointer", TR_Note_Testing_11);
			a_test_runner.map.add("Note addLocalFloat", TR_Note_Testing_12);
			a_test_runner.map.add("Note addLocalInt", TR_Note_Testing_13);
			a_test_runner.map.add("Note addLocalNote", TR_Note_Testing_14);
			a_test_runner.map.add("Note addLocalValue", TR_Note_Testing_15);
			a_test_runner.map.add("Note ", TR_Note_Testing_16);
		}
	}

#endif
