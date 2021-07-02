

#ifndef DataSet_h
#define DataSet_h

#include "Iterator.h"
#include "cppObject.h"
#include "Map.h"

template <class T>
class DataSet : public Iterator , public cppObject{
	public:
		virtual ~DataSet(){}
		
		virtual DataSet<T>* space(int i_space){
			m_space = i_space;
			return this;
		}
		
		virtual DataSet<T>* dimention(int i_dimention){
			m_dimention = i_dimention;
			return this;
		}
		
		virtual DataSet<T>* position(int i_position){
			m_position = i_position;
			return this;
		}
		
		virtual DataSet<T>* set(T t){return this;}
		virtual DataSet<T>* remove(){return this;}
		virtual T getValue(){return T();}
		virtual T* getPointer(){return nullptr;}
		
		virtual DataSet<T>* set(Iterator i,T t){return this;}
		virtual DataSet<T>* remove(Iterator i){return this;}
		virtual T getValue(Iterator i){return T();}
		virtual T* getPointer(Iterator i){return nullptr;}
		virtual String toString(Iterator i){return "DataSet";}
		
		virtual int spaceSize(){return 0;}
		virtual int getSize(int i_space){return 0;}
		virtual int getSize(int i_space, int i_dimention){return 0;}
		virtual int dimentionSize(int i_space){return 0;}
		
		virtual Iterator iterateSpace(int i_space){
			return Iterator(0, getSize(i_space));
		}
		virtual Iterator iterateDimention(int i_space, int i_dimention){
			return Iterator(0, getSize(i_space,i_dimention));
		}
		// virtual void setIteration(int iter){}
		// virtual int getIterationSize(){return 0;}
		// virtual bool last(){}
		// virtual bool next(){}
		
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
			for(Iterator i : *this){
				if(((DataSet<T>*)b)->getValue(i) != this->getValue(i)){
					return false;
				}
			}
			return true;
		}
		
		virtual void operator=(DataSet<T> b){}
		virtual bool operator==(DataSet<T> b){
			for(Iterator i : *this){
				if( b.getValue(i) != this->getValue(i)){
					return false;
				}
			}
			return true;
		}

		virtual bool operator!=(DataSet<T> b){
			b.refreshIteration();
			for(Iterator i : *this){
				if( b.getValue(i) != this->getValue(i)){
					return true;
				}
			}
			return false;
		}
	
		
	protected:
		int m_space = 0;
		int m_dimention = 0;
		int m_position = 0;
		
};

#endif 
