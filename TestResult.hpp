
#ifndef TestResult_hpp
#define TestResult_hpp

#include "PrimitiveRawList.hpp"
#include "Note.hpp"

namespace higgs{
	
class TestResult{
	public:
		TestResult(){}
		TestResult(const TestResult& c_result){
			m_test_Error = c_result.m_test_Error;
			m_info = c_result.m_info;
			m_errors = c_result.m_errors;
			m_indexs = c_result.m_indexs;
			m_index  = c_result.m_index;
		}
		
		TestResult(TestResult&& c_result){
			//m_test_Error = c_result.m_test_Error;
		}
		virtual ~TestResult(){}
		
		virtual void addInfo(Note a_note){
			m_info.add(a_note);
		}
		
		virtual void catchError(int a_index, Note a_note){
			m_test_Error = true;
			m_errors.add(a_note);
			m_indexs.add(a_index);
		}
		
		virtual void catchError(Note a_note){
			m_test_Error = true;
			m_errors.add(a_note);
			m_indexs.add(m_index);
		}

		virtual void assertTrue(int a_index, Note a_note, bool a_assert){
			if(!a_assert){
				this->catchError(a_index, a_note);
			}
		}

		virtual void assertTrue(Note a_note, bool a_assert){
			if(!a_assert){
				this->catchError(a_note);
			}
			m_index++;
		}

		virtual void assertNull(Note a_note, void* a_assert){
			if(a_assert != nullptr){
				this->catchError(a_note);
			}
			m_index++;
		}

		virtual void assertNotNull(Note a_note, void* a_assert){
			if(a_assert == nullptr){
				this->catchError(a_note);
			}
			m_index++;
		}

		template<class T>
		void assertLessThen(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 >= a_assert_2){
				this->catchError(a_index, a_note);
			}
		}

		template<class T>
		void assertLessThen(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 >= a_assert_2){
				this->catchError(a_note);
			}
			m_index++;
		}

		template<class T>
		void assertNoteLessThen(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 >= a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_index, a_note + i_note);
			}
		}

		template<class T>
		void assertNoteLessThen(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 >= a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_note + i_note);
			}
			m_index++;
		}

		template<class T>
		void assertGreaterThen(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 <= a_assert_2){
				this->catchError(a_index, a_note);
			}
		}

		template<class T>
		void assertGreaterThen(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 <= a_assert_2){
				this->catchError(a_note);
			}
			m_index++;
		}

		template<class T>
		void assertNoteGreaterThen(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 <= a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_index, a_note + i_note);
			}
		}

		template<class T>
		void assertNoteGreaterThen(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 <= a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_note + i_note);
			}
			m_index++;
		}

		template<class T>
		void assertLessEqualThen(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 > a_assert_2){
				this->catchError(a_index, a_note);
			}
		}

		template<class T>
		void assertLessEqualThen(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 > a_assert_2){
				this->catchError(a_note);
			}
			m_index++;
		}

		template<class T>
		void assertNoteLessEqualThen(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 > a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_index, a_note + i_note);
			}
		}

		template<class T>
		void assertNoteLessEqualThen(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 > a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_note + i_note);
			}
			m_index++;
		}

		template<class T>
		void assertGreaterEqualThen(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 < a_assert_2){
				this->catchError(a_index, a_note);
			}
		}

		template<class T>
		void assertGreaterEqualThen(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 < a_assert_2){
				this->catchError(a_note);
			}
			m_index++;
		}

		template<class T>
		void assertNoteGreaterEqualThen(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 < a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_index, a_note + i_note);
			}
		}

		template<class T>
		void assertNoteGreaterEqualThen(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 < a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_note + i_note);
			}
			m_index++;
		}

		template<class T>
		void assertInBetween(int a_index, Note a_note, T a_assert_1, T a_assert_inbetween_1, T a_assert_inbetween_2){
			if(a_assert_inbetween_1 > a_assert_1 || a_assert_inbetween_2 < a_assert_1){
				this->catchError(a_index, a_note);
			}
		}

		template<class T>
		void assertInBetween(Note a_note, T a_assert_1, T a_assert_inbetween_1, T a_assert_inbetween_2){
			if(a_assert_inbetween_1 > a_assert_1 || a_assert_inbetween_2 < a_assert_1){
				this->catchError(a_note);
			}
			m_index++;
		}

		template<class T>
		void assertNoteInBetween(int a_index, Note a_note, T a_assert_1, T a_assert_inbetween_1, T a_assert_inbetween_2){
			if(a_assert_inbetween_1 > a_assert_1 || a_assert_inbetween_2 < a_assert_1){
				Note i_note = Note(" Min Value 1: ") + Note(a_assert_inbetween_1) + Note(" <-> Test Value: ") + Note(a_assert_1) + Note(" <-> Max Value 2: ") + Note(a_assert_inbetween_2);
				this->catchError(a_index, a_note + i_note);
			}
		}

		template<class T>
		void assertNoteInBetween(Note a_note, T a_assert_1, T a_assert_inbetween_1, T a_assert_inbetween_2){
			if(a_assert_inbetween_1 > a_assert_1 || a_assert_inbetween_2 < a_assert_1){
				Note i_note = Note(" Min Value 1: ") + Note(a_assert_inbetween_1) + Note(" <-> Test Value: ") + Note(a_assert_1) + Note(" <-> Max Value 2: ") + Note(a_assert_inbetween_2);
				this->catchError(a_note + i_note);
			}
			m_index++;
		}

		template<class T>
		void assertEqual(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 != a_assert_2){
				this->catchError(a_index, a_note);
			}
		}

		template<class T>
		void assertEqual(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 != a_assert_2){
				this->catchError(a_note);
			}
			m_index++;
		}

		template<class T>
		void assertNotEqual(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 == a_assert_2){
				this->catchError(a_index, a_note);
			}
		}

		template<class T>
		void assertNotEqual(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 == a_assert_2){
				this->catchError(a_note);
			}
			m_index++;
		}

		template<class T>
		void assertNoteEqual(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 != a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_index, a_note + i_note);
			}
		}

		template<class T>
		void assertNoteEqual(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 != a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_note + i_note);
			}
			m_index++;
		}

		template<class T>
		void assertNoteNotEqual(int a_index, Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 == a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_index, a_note + i_note);
			}
		}

		template<class T>
		void assertNoteNotEqual(Note a_note, T a_assert_1, T a_assert_2){
			if(a_assert_1 == a_assert_2){
				Note i_note = Note(" Value 1: ") + Note(a_assert_1) + Note(" <-> Value 2: ") + Note(a_assert_2);
				this->catchError(a_note + i_note);
			}
			m_index++;
		}

		virtual bool hasError(){return m_test_Error;}

		virtual bool hasInfo(){return !this->m_info.isEmpty();}
		
		virtual Note getInfo(){
			Note i_info;
			for(int x = 0; x < m_info.getPosition(); x++){
				Note* f_info = m_info.getByPosition(x);
				if(f_info == nullptr){
					continue;
				}
				i_info.addLocalArrayPointer("Info: ");
				i_info.addLocalCharArray(*f_info);
				if(x == m_info.getPosition() - 1){
					continue;
				}
				i_info.addLocalValue('\n');
			}
			return i_info;
		}
		
		virtual Note getNoteResult(){
			if(!m_test_Error){
				return Note("No Error Found");
			}
			Note i_errors = "Test Failed at:\n";
			for(int x = 0; x < m_errors.getPosition(); x++){
				int* f_index = m_indexs.getByPosition(x);
				Note* f_error = m_errors.getByPosition(x);
				if(f_index == nullptr || f_error == nullptr){
					continue;
				}
				i_errors.addLocalArrayPointer("Index: ");
				i_errors.addLocalInt(*f_index);
				i_errors.addLocalValue('\n');
				i_errors.addLocalCharArray(*f_error);
				if(x != m_errors.getPosition() - 1){
					i_errors.addLocalValue('\n');
				}
			}
			return i_errors;
		}
		
		virtual void operator=(const TestResult& c_result){
			m_test_Error = c_result.m_test_Error;
			m_info = c_result.m_info;
			m_errors = c_result.m_errors;
			m_indexs = c_result.m_indexs;
			m_index  = c_result.m_index;
		}
		
		virtual void operator=(TestResult&& c_result){
			m_test_Error = c_result.m_test_Error;
		}
		
		virtual void clear(){
			m_test_Error = false;
			m_info.resetDelete();
			m_errors.resetDelete();
			m_indexs.resetDelete();
			m_index = 0;
		}
		
	protected:
		bool m_test_Error = false;
		PrimitiveRawList<Note> m_info;

		PrimitiveRawList<Note> m_errors;
		PrimitiveRawList<int> m_indexs;
		int m_index = 0;
};

}

#endif
