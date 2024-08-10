
#ifndef TR_Token_Testing_hpp
	#define TR_Token_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Token.hpp"

	namespace higgs{
		
		TestResult TR_Token_Testing_1(){
			TestResult i_result;
			
			Token i_token;

			i_result.assertTrue("token name has to be empty", i_token.name.isEmpty());
			i_result.assertTrue("token value has to be empty", i_token.value.isEmpty());
			i_result.assertTrue("token info has to be empty", i_token.info.isEmpty());
			
			i_result.assertNoteEqual("token text_Position has to be -1", i_token.text_Position, -1);
			i_result.assertNoteEqual("token line_Position has to be -1", i_token.line_Position, -1);
			i_result.assertNoteEqual("token list_Position has to be -1", i_token.list_Position, -1);
			
			return i_result;
		}
		
		TestResult TR_Token_Testing_2(){
			TestResult i_result;
			
			Token i_token = Token("char", "t", "primitive", 0, 5, 10);

			i_result.assertNoteEqual("token name has to be char", i_token.name, Note("char"));
			i_result.assertNoteEqual("token value has to be t", i_token.value, Note("t"));
			i_result.assertNoteEqual("token info has to be primitive", i_token.info, Note("primitive"));
			
			i_result.assertNoteEqual("token text_Position has to be 0", i_token.text_Position, 0);
			i_result.assertNoteEqual("token line_Position has to be 5", i_token.line_Position, 5);
			i_result.assertNoteEqual("token list_Position has to be 10", i_token.list_Position, 10);
			
			return i_result;
		}
		
		TestResult TR_Token_Testing_3(){
			TestResult i_result;
			
			Token i_token = Token("char", "t", "primitive");

			i_result.assertNoteEqual("token name has to be char", i_token.name, Note("char"));
			i_result.assertNoteEqual("token value has to be t", i_token.value, Note("t"));
			i_result.assertNoteEqual("token info has to be primitive", i_token.info, Note("primitive"));
			
			i_result.assertNoteEqual("token text_Position has to be -1", i_token.text_Position, -1);
			i_result.assertNoteEqual("token line_Position has to be -1", i_token.line_Position, -1);
			i_result.assertNoteEqual("token list_Position has to be -1", i_token.list_Position, -1);
			
			return i_result;
		}
		
		TestResult TR_Token_Testing_4(){
			TestResult i_result;
			
			Token i_token = Token("char", "t");

			i_result.assertNoteEqual("token name has to be char", i_token.name, Note("char"));
			i_result.assertNoteEqual("token value has to be t", i_token.value, Note("t"));
			i_result.assertTrue("token info has to be empty", i_token.info.isEmpty());
			
			i_result.assertNoteEqual("token text_Position has to be -1", i_token.text_Position, -1);
			i_result.assertNoteEqual("token line_Position has to be -1", i_token.line_Position, -1);
			i_result.assertNoteEqual("token list_Position has to be -1", i_token.list_Position, -1);
			
			return i_result;
		}
		
		TestResult TR_Token_Testing_5(){
			TestResult i_result;
			
			Token i_token = Token("char");

			i_result.assertNoteEqual("token name has to be char", i_token.name, Note("char"));
			i_result.assertTrue("token value has to be empty", i_token.value.isEmpty());
			i_result.assertTrue("token info has to be empty", i_token.info.isEmpty());
			
			i_result.assertNoteEqual("token text_Position has to be -1", i_token.text_Position, -1);
			i_result.assertNoteEqual("token line_Position has to be -1", i_token.line_Position, -1);
			i_result.assertNoteEqual("token list_Position has to be -1", i_token.list_Position, -1);
			
			return i_result;
		}
		
		TestResult TR_Token_Testing_6(){
			TestResult i_result;
			
			Token i_token;
			i_token = Token("char", "t", "primitive", 0, 5, 10);

			i_result.assertNoteEqual("token name has to be char", i_token.name, Note("char"));
			i_result.assertNoteEqual("token value has to be t", i_token.value, Note("t"));
			i_result.assertNoteEqual("token info has to be primitive", i_token.info, Note("primitive"));
			
			i_result.assertNoteEqual("token text_Position has to be 0", i_token.text_Position, 0);
			i_result.assertNoteEqual("token line_Position has to be 5", i_token.line_Position, 5);
			i_result.assertNoteEqual("token list_Position has to be 10", i_token.list_Position, 10);
			
			return i_result;
		}

		void TR_Token_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Token Constructor", TR_Token_Testing_1);
			a_test_runner.map.add("Token Full Constructor", TR_Token_Testing_2);
			a_test_runner.map.add("Token Name Value Info Constructor", TR_Token_Testing_3);
			a_test_runner.map.add("Token Name Value Constructor", TR_Token_Testing_4);
			a_test_runner.map.add("Token Name Constructor", TR_Token_Testing_5);
			a_test_runner.map.add("Token operator==", TR_Token_Testing_6);
		}
	}

#endif
