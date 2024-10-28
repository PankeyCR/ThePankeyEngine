
#ifndef TR_Self_Testing_hpp
	#define TR_Self_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Self.hpp"

	namespace pankey{

		class SelfTest{
			public:
			SelfTest(){}
			bool operator==(const SelfTest& a_test){
				return a_test.m_this == this->m_this;
			}
			bool operator!=(const SelfTest& a_test){
				return a_test.m_this != this->m_this;
			}
			self<SelfTest> m_this = this;
		};
		
		TestResult TR_Self_Testing_1(){
			TestResult result;

			int num = 15;
			self<int> i_self = &num;//if self is not in the same scope than the pointer that has assing, it will crash

			result.assertTrue("allocator shouldnt be null", !i_self.isManagerNull());
			result.assertTrue("holder shouldnt be null", !i_self.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_self.isNull());

			return result;
		}
		
		TestResult TR_Self_Testing_2(){
			TestResult result;

			SelfTest i_test;

			result.assertTrue("allocator shouldnt be null", !i_test.m_this.isManagerNull());
			result.assertTrue("holder shouldnt be null", !i_test.m_this.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_test.m_this.isNull());

			return result;
		}
		
		TestResult TR_Self_Testing_3(){
			TestResult result;
			
			val<SelfTest> i_selfTest;
			{
				SelfTest i_test;
				i_selfTest = i_test.m_this;

				result.assertTrue("allocator shouldnt be null", !i_test.m_this.isManagerNull());
				result.assertTrue("holder shouldnt be null", !i_test.m_this.isHolderNull());
				result.assertTrue("pointer shouldnt be null", !i_test.m_this.isNull());
			}

			result.assertTrue("allocator shouldnt be null", !i_selfTest.isManagerNull());
			result.assertTrue("holder shouldnt be null", !i_selfTest.isHolderNull());
			result.assertTrue("pointer has to be null", i_selfTest.isNull());

			return result;
		}
		
		TestResult TR_Self_Testing_4(){
			TestResult result;
			
			SelfTest i_test;
			{
				val<SelfTest> i_selfTest;
				i_selfTest = i_test.m_this;

				result.assertTrue("allocator shouldnt be null", !i_selfTest.isManagerNull());
				result.assertTrue("holder shouldnt be null", !i_selfTest.isHolderNull());
				result.assertTrue("pointer has to be null", !i_selfTest.isNull());
			}

			result.assertTrue("allocator shouldnt be null", !i_test.m_this.isManagerNull());
			result.assertTrue("holder shouldnt be null", !i_test.m_this.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_test.m_this.isNull());

			return result;
		}
		
		TestResult TR_Self_Testing_5(){
			TestResult result;
			
			data i_out_of_scope_data;
			var i_out_of_scope_var;
			pointer<SelfTest> i_out_of_scope_pointer;
			val<SelfTest> i_out_of_scope_val;
			obj<SelfTest> i_out_of_scope_obj;
			{
				SelfTest i_test;
				i_out_of_scope_var = i_test.m_this;
				i_out_of_scope_data = i_out_of_scope_var;
				i_out_of_scope_pointer = i_out_of_scope_var;
				i_out_of_scope_val = i_out_of_scope_var;
				i_out_of_scope_obj = i_out_of_scope_var;
			
				result.assertTrue("pointer shouldnt be null", !i_out_of_scope_data.isNull());
				result.assertTrue("pointer shouldnt be null", !i_out_of_scope_var.isNull());
				result.assertTrue("pointer shouldnt be null", !i_out_of_scope_pointer.isNull());
				result.assertTrue("pointer shouldnt be null", !i_out_of_scope_val.isNull());
				result.assertTrue("pointer has to be null", i_out_of_scope_obj.isNull());
			}
			
			result.assertTrue("pointer has to be null", i_out_of_scope_data.isNull());
			result.assertTrue("pointer has to be null", i_out_of_scope_var.isNull());
			result.assertTrue("pointer has to be null", i_out_of_scope_pointer.isNull());
			result.assertTrue("pointer has to be null", i_out_of_scope_val.isNull());
			result.assertTrue("pointer has to be null", i_out_of_scope_obj.isNull());

			return result;
		}

		void TR_Self_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("Self only Constructor", TR_Self_Testing_1);
			// a_test_runner.map.add("Self inside class", TR_Self_Testing_2);
			// a_test_runner.map.add("Self inside class", TR_Self_Testing_3);
			// a_test_runner.map.add("Self inside class", TR_Self_Testing_4);
			// a_test_runner.map.add("Self inside class", TR_Self_Testing_5);
		}		

	}

#endif
