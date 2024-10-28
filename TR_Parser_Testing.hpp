
#ifndef TR_Parser_Testing_hpp
	#define TR_Parser_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Lexer.hpp"
	#include "PrintableList.hpp"

	namespace pankey{
		
		TestResult TR_Parser_Testing_1(){
			TestResult i_result;
			
			Lexer i_lexer = javaLexer();
			
			return i_result;
		}

		void TR_Parser_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Lexer Constructor", TR_Parser_Testing_1);
		}
	}

#endif
