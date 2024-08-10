
#ifndef NoteIterator_hpp
#define NoteIterator_hpp

namespace higgs{

class NoteIterator{
	public:
	
		NoteIterator(char* i_chr, int i_pos){
			m_chr = i_chr;
			m_pos = i_pos;
		}
	
		NoteIterator(const NoteIterator& i_iterator){
			m_chr = i_iterator.m_chr;
			m_pos = i_iterator.m_pos;
		}
		virtual ~NoteIterator(){}
		
		virtual char& operator *(){
			return m_chr[m_pos];
		}
	
		void operator ++(){
			if(m_chr == nullptr){
				return;
			}
			m_pos++;
		}
		
		bool operator ==(NoteIterator i){
			if(m_chr == nullptr){
				return false;
			}
			return m_pos == i.m_pos;
		}
		
		bool operator !=(NoteIterator i){
			if(m_chr == nullptr){
				return true;
			}
			return m_pos != i.m_pos;
		}
		virtual NoteIterator& operator =(const NoteIterator& i){
			m_chr = i.m_chr;
			m_pos = i.m_pos;
			return *this;
		}
	protected:
		char* m_chr = nullptr;
		int m_pos = 0;
};

}

#endif