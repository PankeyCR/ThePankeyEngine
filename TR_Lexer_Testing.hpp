
#ifndef TR_Lexer_Testing_hpp
	#define TR_Lexer_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Lexer.hpp"
	#include "PrintableList.hpp"

	namespace higgs{
		
		TestResult TR_Lexer_Testing_1(){
			TestResult i_result;
			
			Lexer i_lexer;
			
			return i_result;
		}
		
		TestResult TR_Lexer_Testing_2(){
			TestResult i_result;

			Note i_script = "int x = (1+15)*3;";
			
			Lexer i_lexer;
			i_lexer.addBreakPoint(' ');
			Token i_int = i_lexer.addTypeToken(Token("int", "int"));
			Token i_equal = i_lexer.addDelimiterToken(Token("equal", "="));
			Token i_open_parenthesis = i_lexer.addDelimiterToken(Token("open_parenthesis", "("));
			Token i_close_parenthesis = i_lexer.addDelimiterToken(Token("close_parenthesis", ")"));
			Token i_sum = i_lexer.addDelimiterToken(Token("sum", "+"));
			Token i_mult = i_lexer.addDelimiterToken(Token("mult", "*"));
			Token i_end_code = i_lexer.addDelimiterToken(Token("end_code", ";"));

			PrimitiveRawList<Token> i_tokens = i_lexer.capture(i_script);

			Token ir_int_type = i_tokens.getByIndex(0);
			Token ir_variable = i_tokens.getByIndex(1);
			Token ir_equal = i_tokens.getByIndex(2);
			Token ir_open_parenthesis = i_tokens.getByIndex(3);
			Token ir_1 = i_tokens.getByIndex(4);
			Token ir_sum = i_tokens.getByIndex(5);
			Token ir_15 = i_tokens.getByIndex(6);
			Token ir_close_parenthesis = i_tokens.getByIndex(7);
			Token ir_mult = i_tokens.getByIndex(8);
			Token ir_3 = i_tokens.getByIndex(9);
			Token ir_end_code = i_tokens.getByIndex(10);

			i_result.assertNoteEqual("token should cointain int", ir_int_type.value, i_int.value);
			i_result.assertNoteEqual("token should cointain variable x", ir_variable.value, Token("Variable", "x").value);
			i_result.assertNoteEqual("token should cointain =", ir_equal.value, i_equal.value);
			i_result.assertNoteEqual("token should cointain (", ir_open_parenthesis.value, i_open_parenthesis.value);
			i_result.assertNoteEqual("token should cointain )", ir_close_parenthesis.value, i_close_parenthesis.value);
			i_result.assertNoteEqual("token should cointain +", ir_sum.value, i_sum.value);
			i_result.assertNoteEqual("token should cointain *", ir_mult.value, i_mult.value);
			i_result.assertNoteEqual("tokens should cointain ;", i_end_code.value, ir_end_code.value);
			i_result.assertNoteEqual("tokens number should be 1", ir_1.value, Token("number", "1").value);
			i_result.assertNoteEqual("tokens number should be 15", ir_15.value, Token("number", "15").value);
			i_result.assertNoteEqual("tokens number should be 3", ir_3.value, Token("number", "3").value);
			
			//System::console.println(PrintableList<PrimitiveRawList<Token>,Token>(i_tokens));
			
			return i_result;
		}
		
		TestResult TR_Lexer_Testing_2(){
			TestResult i_result;

			Note i_script = "Note name = i_settings.getNote(\"Pankey\");";
			
			Lexer i_lexer;
			i_lexer.addBreakPoint(' ');
			Token i_int = i_lexer.addTypeToken(Token("Note", "Note"));
			Token i_equal = i_lexer.addDelimiterToken(Token("equal", "="));
			Token i_open_parenthesis = i_lexer.addDelimiterToken(Token("open_parenthesis", "("));
			Token i_close_parenthesis = i_lexer.addDelimiterToken(Token("close_parenthesis", ")"));
			Token i_end_code = i_lexer.addDelimiterToken(Token("method_diveder", "."));
			Token i_end_code = i_lexer.addDelimiterToken(Token("end_code", ";"));

			PrimitiveRawList<Token> i_tokens = i_lexer.capture(i_script);

			Token ir_int_type = i_tokens.getByIndex(0);
			Token ir_variable = i_tokens.getByIndex(1);
			Token ir_equal = i_tokens.getByIndex(2);
			Token ir_open_parenthesis = i_tokens.getByIndex(3);
			Token ir_1 = i_tokens.getByIndex(4);
			Token ir_sum = i_tokens.getByIndex(5);
			Token ir_15 = i_tokens.getByIndex(6);
			Token ir_close_parenthesis = i_tokens.getByIndex(7);
			Token ir_mult = i_tokens.getByIndex(8);
			Token ir_3 = i_tokens.getByIndex(9);
			Token ir_end_code = i_tokens.getByIndex(10);

			i_result.assertNoteEqual("token should cointain int", ir_int_type.value, i_int.value);
			i_result.assertNoteEqual("token should cointain variable x", ir_variable.value, Token("Variable", "x").value);
			i_result.assertNoteEqual("token should cointain =", ir_equal.value, i_equal.value);
			i_result.assertNoteEqual("token should cointain (", ir_open_parenthesis.value, i_open_parenthesis.value);
			i_result.assertNoteEqual("token should cointain )", ir_close_parenthesis.value, i_close_parenthesis.value);
			i_result.assertNoteEqual("token should cointain +", ir_sum.value, i_sum.value);
			i_result.assertNoteEqual("token should cointain *", ir_mult.value, i_mult.value);
			i_result.assertNoteEqual("tokens should cointain ;", i_end_code.value, ir_end_code.value);
			i_result.assertNoteEqual("tokens number should be 1", ir_1.value, Token("number", "1").value);
			i_result.assertNoteEqual("tokens number should be 15", ir_15.value, Token("number", "15").value);
			i_result.assertNoteEqual("tokens number should be 3", ir_3.value, Token("number", "3").value);
			
			//System::console.println(PrintableList<PrimitiveRawList<Token>,Token>(i_tokens));
			
			return i_result;
		}

		void TR_Lexer_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Lexer Constructor", TR_Lexer_Testing_1);
			a_test_runner.map.add("Lexer simple math", TR_Lexer_Testing_2);
		}
	}

#endif
