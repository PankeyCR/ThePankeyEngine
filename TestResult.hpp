
#ifndef TestResult_hpp
#define TestResult_hpp
#define TestResult_AVAILABLE 

#include "Note.hpp"
#include "PrimitiveList.hpp"

namespace ame{
	
class TestResult{
	public:
		TestResult(){}
		TestResult(const TestResult& c_result){
			//m_test_Error = c_result.m_test_Error;
		}
		TestResult(TestResult&& c_result){
			//m_test_Error = c_result.m_test_Error;
		}
		virtual ~TestResult(){}
		
		virtual void catchError(Note a_note){
			m_test_Error = true;
			m_errors.add(a_note);
			m_indexs.add(-1);
		}
		
		virtual void catchError(int a_index){
			m_test_Error = true;
			m_errors.add(Note());
			m_indexs.add(a_index);
		}
		
		virtual void catchError(int a_index, Note a_note){
			m_test_Error = true;
			m_errors.add(a_note);
			m_indexs.add(a_index);
		}
		virtual bool hasError(){return m_test_Error;}
		
		virtual Note getNoteResult(){
			if(!m_test_Error){
				return Note("No Error Found");
			}
			Note i_errors = "Test Failed at:\n";
			for(int x = 0; x < m_errors.getPosition(); x++){
				i_errors += "Index: ";
				i_errors += *m_indexs.getByPosition(x);
				i_errors += '\n';
				i_errors += *m_errors.getByPosition(x);
				if(x != m_errors.getPosition() - 1){
					i_errors += '\n';
				}
			}
			return i_errors;
		}
		
		virtual void operator=(const TestResult& c_result){
			m_test_Error = c_result.m_test_Error;
		}
		
		virtual void operator=(TestResult&& c_result){
			m_test_Error = c_result.m_test_Error;
		}
		
	protected:
		bool m_test_Error = false;
		PrimitiveList<Note> m_errors;
		PrimitiveList<int> m_indexs;
};

}

#endif
