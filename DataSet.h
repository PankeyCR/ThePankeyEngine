/*
	The iterator is passed as an rvalue reference 
	Iteratin inside a Iteration with the same dataset is not allowed
	//neuralnetworks dont let the dataset variable to get out until is done using it
*/

#ifndef DataSet_h
#define DataSet_h

#include "Cast.h"
#include "cppObject.h"
#include "Map.h"

namespace ame{
	
template <class T>
class DataSet : public cppObject{
public:
	DataSet(){}
	DataSet(int i_size){
		memory = malloc();
	}
	DataSet(const DataSet<T>& t){
		// m_space = t.m_space;
		// for(int x = 0; x < t.getSize(); x++){
			
		// }
	}
	virtual ~DataSet(){}
	
	virtual void space(int i_space){
		m_space = i_space;
	}
	
	virtual void dimention(int i_dimention){
		m_dimention = i_dimention;
	}
	
	virtual void position(int i_position){
		m_position = i_position;
	}
	
	virtual void position(int i_space, int i_dimention, int i_position){
		m_space = i_space;
		m_dimention = i_dimention;
		m_position = i_position;
	}
	
	virtual void position(int i_dimention, int i_position){
		m_dimention = i_dimention;
		m_position = i_position;
	}
	
	virtual DataSet<T>* set(T t){return this;}
	virtual DataSet<T>* remove(){return this;}
	virtual T getValue(){return T();}
	virtual T* getPointer(){return nullptr;}
	
	virtual int spaceSize(){return 0;}//Amount of spaces in the dataset
	virtual int dimentionSize(int i_space){return 0;}//Amount of dimentions inside the Space
	
	virtual int getSize(){return 0;}//total size of elements
	virtual int getSize(int i_space){return 0;}//total size of elements on the spaec
	virtual int getSize(int i_space, int i_dimention){return 0;}//total size of elements inside the space and dimention
	
	// virtual DataSet<T>&& iterateSpace(int i_space){
		// return DataSet<T>(0, getSize(i_space));
	// }
	// virtual DataSet<T> iterateDimention(int i_space, int i_dimention){
		// return DataSet<T>(0, getSize(i_space,i_dimention));
	// }
	
	// virtual T getInSpace(int i_space, Iterator i){return T();}
	// virtual T getInDimention(int i_space, int i_dimention, Iterator i){return T();}
	
	// virtual T* getPointerInSpace(int i_space, Iterator i){return nullptr;}
	// virtual T* getPointerInDimention(int i_space, int i_dimention, Iterator i){return nullptr;}
	
	virtual int space(){return m_space;}
	virtual int dimention(){return m_dimention;}
	virtual int position(){return m_position;}

	//cppObject part
	virtual bool instanceof(cppObjectClass* cls){
	return cppObject::instanceof(cls) || cls == Class<DataSet<T>>::classType;
	}
	virtual cppObjectClass* getClass(){return Class<DataSet<T>>::classType;}
	virtual String toString(){return "DataSet";}
	
	virtual bool equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(!b->instanceof(Class<DataSet<T>>::classType)){
			return false;
		}
		if(m_space != ((DataSet<T>*)b)->m_space || 
		   m_dimention != ((DataSet<T>*)b)->m_dimention || 
		   m_position != ((DataSet<T>*)b)->m_position){
			return false;
		}
		// for(Iterator i : *this){
			// if(((DataSet<T>*)b)->getValue(i) != this->getValue(i)){
				// return false;
			// }
		// }
		return true;
	}
	
	virtual void operator=(const DataSet<T>& b){}
	virtual bool operator==(DataSet<T> b){
		return true;
	}
	
	virtual DataSet<T>&& begin(){return DataSet<T>();}
	virtual DataSet<T>&& end(){return DataSet<T>();}
	virtual DataSet<T> operator *(){return DataSet<T>();}
	virtual void operator ++(){
		if(iterationDirection){
			next();
		}else{
			last();
		}
	}
	virtual bool operator !=(DataSet<T>&& i){return true;}

	virtual bool last(){return false;}
	virtual bool next(){return false;}
	
protected:
	T* memory = nullptr;
	
	bool iterationDirection = true;
	
	int m_space = 0;
	int m_dimention = 0;
	int m_position = 0;
	
};

}

#endif 
