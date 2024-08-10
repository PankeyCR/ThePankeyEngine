
#ifndef TR_TableStorage_Testing_hpp
	#define TR_TableStorage_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Variable.hpp"
	#include "Value.hpp"

	namespace higgs{
		
		template<class TTable, class KEY_TYPE, class VALUE_TYPE>
		TestResult TR_TableStorage_Testing_1(){
			TestResult result;

			TTable i_map;
			
			result.assertTrue("storage has to be null", i_map.isNull());
			return result;
		}
		
		template<class TTable, class KEY_TYPE, class VALUE_TYPE>
		TestResult TR_TableStorage_Testing_2(){
			TestResult result;

			TTable i_map;
			i_map.expand(5);
			
			result.assertTrue("storage shoulnt be null", i_map.isNull());
			result.assertEqual("storage size shoulnt be 5", i_map.getArraySize(), 5);
			return result;
		}

		template<class TTable, class KEY_TYPE, class VALUE_TYPE>
		void TR_TableStorage_Testing(const Note& a_list_name, TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add(a_list_name + " Table Constructor", TR_TableStorage_Testing_1<TTable,KEY_TYPE,VALUE_TYPE>);
			// a_test_runner.map.add(a_list_name + " Table expand", TR_TableStorage_Testing_2<TTable,KEY_TYPE,VALUE_TYPE>);
		}	

	}

#endif
