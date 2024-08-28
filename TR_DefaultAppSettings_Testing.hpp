
#ifndef TR_DefaultAppSettings_Testing_hpp
	#define TR_DefaultAppSettings_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "DefaultAppSettings.hpp"

	namespace pankey{
	
		TestResult TR_DefaultAppSettings_Testing_1(){
			TestResult i_result;

			DefaultAppSettings i_settings;
			
			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_2(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addInt("name", 15);

			int i_value = i_settings.getInt("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containInt("name"));
			i_result.assertNoteEqual("value should be 15", i_value, 15);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_3(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addLong("name", 1590l);

			long i_value = i_settings.getLong("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containLong("name"));
			i_result.assertNoteEqual("value should be 15", i_value, 1590l);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_4(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addFloat("name", 15.6f);

			float i_value = i_settings.getFloat("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containFloat("name"));
			i_result.assertNoteEqual("value should be 15.6f", i_value, 15.6f);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_5(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addNote("name", "Frank");

			Note i_value = i_settings.getNote("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containNote("name"));
			i_result.assertNoteEqual("value should be 15.6f", i_value, Note("Frank"));

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_6(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addBoolean("name", true);

			bool i_value = i_settings.getBoolean("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containBoolean("name"));
			i_result.assertNoteEqual("value should be 15.6f", i_value, true);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_7(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			var i_value_1 = true;

			i_settings.add("name", i_value_1);

			var i_value_2 = i_settings.get("name");
			
			i_result.assertTrue("settings should contain name", i_settings.contain("name"));
			i_result.assertEqual("value should be true", i_value_1, i_value_2);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_8(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addInt("name", 15);
			
			i_result.assertTrue("settings should contain name", i_settings.containInt("name"));

			i_settings.removeInt("name");
			
			i_result.assertTrue("settings shouldnt contain name", !i_settings.containInt("name"));

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_9(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addLong("name", 1578l);
			
			i_result.assertTrue("settings should contain name", i_settings.containLong("name"));

			i_settings.removeLong("name");
			
			i_result.assertTrue("settings shouldnt contain name", !i_settings.containLong("name"));

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_10(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addFloat("name", 15.6f);
			
			i_result.assertTrue("settings should contain name", i_settings.containFloat("name"));

			i_settings.removeFloat("name");
			
			i_result.assertTrue("settings shouldnt contain name", !i_settings.containFloat("name"));

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_11(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addNote("name", "Frank");
			
			i_result.assertTrue("settings should contain name", i_settings.containNote("name"));

			i_settings.removeNote("name");
			
			i_result.assertTrue("settings shouldnt contain name", !i_settings.containNote("name"));

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_12(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addBoolean("name", false);
			
			i_result.assertTrue("settings should contain name", i_settings.containBoolean("name"));

			i_settings.removeBoolean("name");
			
			i_result.assertTrue("settings shouldnt contain name", !i_settings.containBoolean("name"));

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_13(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.add("name", false);
			
			i_result.assertTrue("settings should contain name", i_settings.contain("name"));

			i_settings.remove("name");
			
			i_result.assertTrue("settings shouldnt contain name", !i_settings.contain("name"));

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_14(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			var i_bool = true;

			i_settings.add("name", i_bool);
			i_settings.add("no_name", i_bool);

			auto i_holder = i_bool.getHolder();

			if(i_holder == nullptr){
				i_result.assertNotNull("holder shoulndt be null", i_holder);
				return i_result;
			}
			
			i_result.assertEqual("reference count should be 3", i_holder->m_count, 3);

			i_settings.remove("name");
			i_settings.remove("no_name");

			i_result.assertEqual("reference count should be 1", i_holder->m_count, 1);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_15(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			var i_bool = true;

			i_settings.add("name", i_bool);
			i_settings.add("no_name", i_bool);

			auto i_holder = i_bool.getHolder();

			if(i_holder == nullptr){
				i_result.assertNotNull("holder shoulndt be null", i_holder);
				return i_result;
			}
			
			i_result.assertEqual("reference count should be 3", i_holder->m_count, 3);

			var i_bool_2 = i_settings.get("name");
			
			i_result.assertEqual("reference count should be 4", i_holder->m_count, 4);

			i_settings.remove("name");
			i_settings.remove("no_name");

			i_result.assertEqual("reference count should be 2", i_holder->m_count, 2);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_16(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addInt("name", 15);
			i_settings.setInt("name", 6);

			int i_value = i_settings.getInt("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containInt("name"));
			i_result.assertNoteEqual("value should be 6", i_value, 6);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_17(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addLong("name", 1590l);
			i_settings.setLong("name", 543l);

			long i_value = i_settings.getLong("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containLong("name"));
			i_result.assertNoteEqual("value should be 543", i_value, 543l);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_18(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addFloat("name", 15.6f);
			i_settings.setFloat("name", 65.7f);

			float i_value = i_settings.getFloat("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containFloat("name"));
			i_result.assertNoteEqual("value should be 65.7f", i_value, 65.7f);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_19(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addNote("name", "Frank");
			i_settings.setNote("name", "Sam");

			Note i_value = i_settings.getNote("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containNote("name"));
			i_result.assertNoteEqual("value should be Sam", i_value, Note("Sam"));

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_20(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.addBoolean("name", true);
			i_settings.setBoolean("name", false);

			bool i_value = i_settings.getBoolean("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containBoolean("name"));
			i_result.assertNoteEqual("value should be false", i_value, false);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_21(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.add("name", true);

			var i_value_1 = i_settings.get("name");
			
			i_result.assertEqual("value should be true", i_value_1.getValue<bool>(), true);

			i_settings.set("name", false);

			var i_value_2 = i_settings.get("name");
			
			i_result.assertEqual("value should be false", i_value_2.getValue<bool>(), false);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_22(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.putInt("name", 15);
			i_settings.changeInt("name", 6);

			int i_value = i_settings.getInt("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containInt("name"));
			i_result.assertNoteEqual("value should be 6", i_value, 6);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_23(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.putLong("name", 1590l);
			i_settings.changeLong("name", 543l);

			long i_value = i_settings.getLong("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containLong("name"));
			i_result.assertNoteEqual("value should be 543", i_value, 543l);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_24(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.putFloat("name", 15.6f);
			i_settings.changeFloat("name", 65.7f);

			float i_value = i_settings.getFloat("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containFloat("name"));
			i_result.assertNoteEqual("value should be 65.7f", i_value, 65.7f);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_25(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.putNote("name", "Frank");
			i_settings.changeNote("name", "Sam");

			Note i_value = i_settings.getNote("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containNote("name"));
			i_result.assertNoteEqual("value should be Sam", i_value, Note("Sam"));

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_26(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.putBoolean("name", true);
			i_settings.changeBoolean("name", false);

			bool i_value = i_settings.getBoolean("name");
			
			i_result.assertTrue("settings should contain name", i_settings.containBoolean("name"));
			i_result.assertNoteEqual("value should be false", i_value, false);

			return i_result;
		}
	
		TestResult TR_DefaultAppSettings_Testing_27(){
			TestResult i_result;

			DefaultAppSettings i_settings;

			i_settings.put("name", true);

			var i_value_1 = i_settings.get("name");
			
			i_result.assertEqual("value should be true", i_value_1.getValue<bool>(), true);

			i_settings.change("name", false);

			var i_value_2 = i_settings.get("name");
			
			i_result.assertEqual("value should be false", i_value_2.getValue<bool>(), false);

			return i_result;
		}

		void TR_DefaultAppSettings_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("DefaultAppSettings Constructor", TR_DefaultAppSettings_Testing_1);
			a_test_runner.map.add("DefaultAppSettings addInt, containInt, getInt", TR_DefaultAppSettings_Testing_2);
			a_test_runner.map.add("DefaultAppSettings addLong, containLong, getLong", TR_DefaultAppSettings_Testing_3);
			a_test_runner.map.add("DefaultAppSettings addFloat, containFloat, getFloat", TR_DefaultAppSettings_Testing_4);
			a_test_runner.map.add("DefaultAppSettings addNote, containNote, getNote", TR_DefaultAppSettings_Testing_5);
			a_test_runner.map.add("DefaultAppSettings addBoolean, containBoolean, getBoolean", TR_DefaultAppSettings_Testing_6);
			a_test_runner.map.add("DefaultAppSettings add, contain, get", TR_DefaultAppSettings_Testing_7);
			a_test_runner.map.add("DefaultAppSettings removeInt", TR_DefaultAppSettings_Testing_8);
			a_test_runner.map.add("DefaultAppSettings removeLong", TR_DefaultAppSettings_Testing_9);
			a_test_runner.map.add("DefaultAppSettings removeFloat", TR_DefaultAppSettings_Testing_10);
			a_test_runner.map.add("DefaultAppSettings removeNote", TR_DefaultAppSettings_Testing_11);
			a_test_runner.map.add("DefaultAppSettings removeBoolean", TR_DefaultAppSettings_Testing_12);
			a_test_runner.map.add("DefaultAppSettings remove", TR_DefaultAppSettings_Testing_13);
			a_test_runner.map.add("DefaultAppSettings var count", TR_DefaultAppSettings_Testing_14);
			a_test_runner.map.add("DefaultAppSettings var count", TR_DefaultAppSettings_Testing_15);
			a_test_runner.map.add("DefaultAppSettings int set", TR_DefaultAppSettings_Testing_16);
			a_test_runner.map.add("DefaultAppSettings var set", TR_DefaultAppSettings_Testing_17);
			a_test_runner.map.add("DefaultAppSettings var set", TR_DefaultAppSettings_Testing_18);
			a_test_runner.map.add("DefaultAppSettings var set", TR_DefaultAppSettings_Testing_19);
			a_test_runner.map.add("DefaultAppSettings var set", TR_DefaultAppSettings_Testing_20);
			a_test_runner.map.add("DefaultAppSettings var set", TR_DefaultAppSettings_Testing_21);
			a_test_runner.map.add("DefaultAppSettings change int", TR_DefaultAppSettings_Testing_22);
			a_test_runner.map.add("DefaultAppSettings change long", TR_DefaultAppSettings_Testing_23);
			a_test_runner.map.add("DefaultAppSettings change note", TR_DefaultAppSettings_Testing_24);
			a_test_runner.map.add("DefaultAppSettings change float", TR_DefaultAppSettings_Testing_25);
			a_test_runner.map.add("DefaultAppSettings change boolean", TR_DefaultAppSettings_Testing_26);
			a_test_runner.map.add("DefaultAppSettings change", TR_DefaultAppSettings_Testing_27);
		}		

	}

#endif
