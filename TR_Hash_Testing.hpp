
#ifndef TR_Hash_Testing_hpp
	#define TR_Hash_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Hash.hpp"
	#include "UniversalHashToIndex.hpp"
	#include "PrimitiveHashFunction.hpp"

	namespace pankey{
		
		TestResult TR_Hash_Testing_1(){
			TestResult i_result;

			HashFunction<int>::function = primitiveHash<int>;

			int i_num = 15;

			long i_hash = HashFunction<int>::function(i_num);

			i_result.addInfo(Note("number inserted = ") + Note(i_num) + Note(" : hash generated = ") + Note(i_hash));
			
			return i_result;
		}
		
		TestResult TR_Hash_Testing_2(){
			TestResult i_result;

			setHashFunction(primitiveHash<int>);

			int i_num = 15;

			long i_hash = Hash(i_num);

			i_result.addInfo(Note("number inserted = ") + Note(i_num) + Note(" : hash generated = ") + Note(i_hash));
			
			return i_result;
		}
		
		TestResult TR_Hash_Testing_3(){
			TestResult i_result;

			HashFunction<int>::function = primitiveHash<int>;
			HashToIndexFunction::function = universalHashToIndex;

			int i_num = 15;

			long i_hash = HashFunction<int>::function(i_num);

			int i_index = HashToIndexFunction::function(i_hash, 0, 1);
			
			i_result.assertNoteInBetween("hash index should be 1", i_index, 0, 1);
			
			return i_result;
		}
		
		TestResult TR_Hash_Testing_4(){
			TestResult i_result;

			setHashFunction(primitiveHash<int>);
			setHashToIndexFunction(universalHashToIndex);

			int i_num = 15;

			int i_index = Hash(i_num, 0, 1);
			
			i_result.assertNoteInBetween("hash index should be 1", i_index, 0, 1);
			
			return i_result;
		}
		
		TestResult TR_Hash_Testing_5(){
			TestResult i_result;

			setHashFunction(primitiveHash<int>);
			setHashToIndexFunction(universalHashToIndex);

			int i_num_1 = 7;
			int i_num_2 = 15;
			int i_num_3 = 55;

			int i_index_1 = Hash<int>(i_num_1, 0, 20);
			int i_index_2 = Hash<int>(i_num_2, 0, 20);
			int i_index_3 = Hash<int>(i_num_3, 0, 20);

			i_result.addInfo(Note("number inserted = ") + Note(i_num_1) + Note(" : hash index generated = ") + Note(i_index_1));
			i_result.addInfo(Note("number inserted = ") + Note(i_num_2) + Note(" : hash index generated = ") + Note(i_index_2));
			i_result.addInfo(Note("number inserted = ") + Note(i_num_3) + Note(" : hash index generated = ") + Note(i_index_3));
			
			i_result.assertNoteInBetween("hash index should be less or equal then 2", i_index_1, 0, 20);
			i_result.assertNoteInBetween("hash index should be less or equal then 2", i_index_2, 0, 20);
			i_result.assertNoteInBetween("hash index should be less or equal then 2", i_index_3, 0, 20);
			
			return i_result;
		}

		void TR_Hash_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("hash function info", TR_Hash_Testing_1);
			a_test_runner.map.add("hash function info", TR_Hash_Testing_2);
			a_test_runner.map.add("hash between 0 and 1", TR_Hash_Testing_3);
			a_test_runner.map.add("hash between 0 and 1", TR_Hash_Testing_4);
			a_test_runner.map.add("hash between 0 and 2", TR_Hash_Testing_5);
		}
	}

#endif
