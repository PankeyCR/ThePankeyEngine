

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
		virtual T getValue(){}
		virtual T* getPointer(){return nullptr;}
		
		virtual int spaceSize(){return 0;}
		virtual int getSize(int i_space){return 0;}
		virtual int getSize(int i_space, int i_dimention){return 0;}
		virtual int dimentionSize(int i_space){return 0;}
		// virtual int positionSize(int i_dimention, int i_position){return 0;}
		
		virtual Iterator iterateSpace(int i_space){
			m_iterateSpace = i_space;
			return Iterator(0, getSize(i_space));
		}
		virtual Iterator iterateDimention(int i_space, int i_dimention){
			m_iterateSpace = i_space;
			m_iterateDimention = i_dimention;
			return Iterator(0, getSize(i_space,i_dimention));
		}
		// virtual void setIteration(int iter){}
		// virtual int getIterationSize(){return 0;}
		// virtual void last(){}
		// virtual void next(){}
		
		virtual int space(){return m_space;}
		virtual int dimention(){return m_dimention;}
		virtual int position(){return m_position;}
    
		//cppObject part
		virtual bool instanceof(cppObjectClass* cls){
		return cppObject::instanceof(cls) || cls == Class<DataSet>::classType;
		}
		virtual cppObjectClass* getClass(){return Class<DataSet>::classType;}
		virtual String toString(){return "DataSet";}
		
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			if(!b->instanceof(Class<DataSet>::classType)){
				return false;
			}
			for(Iterator i : *this){
				if(((DataSet<T>*)b)->getLValue(i) != this->getLValue(i)){
					return false;
				}
				((DataSet<T>*)b)->next();
			}
			return true;
		}
		
		virtual void operator=(DataSet<T> b){}
		virtual bool operator==(DataSet<T> b){
			for(Iterator i : *this){
				if( b.getValue() != this->getValue()){
					return false;
				}
				b.next();
			}
			return true;
		}

		virtual bool operator!=(DataSet<T> b){
			b.refreshIteration();
			for(Iterator i : *this){
				if( b.getValue() != this->getValue()){
					return true;
				}
				b.next();
			}
			return false;
		}
	
		
	protected:
		int m_iterateSpace=-1;
		int m_iterateDimention=-1;
		int m_space = 0;
		int m_dimention = 0;
		int m_position = 0;
		
};

#endif 
