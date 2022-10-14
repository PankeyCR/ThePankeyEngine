
#ifndef ame_Array_hpp
#define ame_Array_hpp
#define ame_Array_AVAILABLE 

namespace ame{

template <class T, int t_size>
class ame_Array{
	protected:
	T m_array[t_size];
	int m_position = 0;
	
	public:
	ame_Array(){}
	virtual ~ame_Array(){}
	
	int getSize(){return t_size;}
	
	void add(T a_value){
		if(this->m_position >= t_size){
			return;
		}
		m_array[this->m_position] = a_value;
	}
	
	T removeByPosition(int a_position){
		if(this->m_position >= t_size){
			return T();
		}
		T i_value = m_array[a_position];
		this->m_position--;
		for(int x = a_position; x < this->m_position; x++){
			m_array[x] = m_array[x + 1];
		}
		return i_value;
	}
	
	T getByPosition(int a_position){
		if(this->m_position >= t_size){
			return T();
		}
		return m_array[a_position];
	}
	
	void reset(){
		this->m_position = 0;
	}
	
	bool isEmpty(){return this->m_position == 0;}
	
	int getIndex(T a_value){
		if(this->isEmpty()){
			return -1;
		}
		for(int x = 0; x < this->m_position; x++){
			if(a_value == m_array[x]){
				return x;
			}
		}
		return -1;
	}
};

}

#endif