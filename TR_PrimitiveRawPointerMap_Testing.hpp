
#ifndef TR_PrimitiveRawPointerMap_Testing_hpp
	#define TR_PrimitiveRawPointerMap_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "PrimitiveRawPointerMap.hpp"

	namespace pankey{
		/*
		TestResult TR_PrimitiveRawPointerMap_Testing_1(){
			TestResult result;
  
			PrimitiveRawPointerMap<int,int> map;

			map.addPointers(new int(1), new int(11));
			map.addPointers(new int(2), new int(12));
			map.addPointers(new int(3), new int(13));
			map.addPointers(new int(4), new int(14));
			map.addPointers(new int(5), new int(15));

			for(int x = 0; x < map.getPosition(); x++){
				MapEntry<int,int> entry = map.getMapEntryByPosition(x);
				if(entry.isNull()){
				continue;
				}
				int key = *entry.getKey();
				int value = *entry.getValue();
				System::console.print("key: ");System::console.print(key);
				System::console.print("     value: ");System::console.println(value);
			}

			return result;
		}*/
		
		TestResult TR_PrimitiveRawPointerMap_Testing_1(){
			TestResult result;
			PrimitiveRawPointerMap<int,int> map;
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerMap_Testing_2(){
			TestResult result;

			PrimitiveRawPointerMap<int,int> map;

			map.addPointers(new int(1), new int(11));
			map.addPointers(new int(2), new int(12));
			map.addPointers(new int(3), new int(13));

			return result;
		}

		void TR_PrimitiveRawPointerMap_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("PrimitiveRawPointerMap Simple Constructor", TR_PrimitiveRawPointerMap_Testing_1);
			a_test_runner.map.add("PrimitiveRawPointerMap addPointer", TR_PrimitiveRawPointerMap_Testing_2);
		}		

	}

#endif
