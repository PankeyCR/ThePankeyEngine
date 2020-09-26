

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
		virtual T *getPointer(){return nullptr;}
		
		virtual int spaceSize(){return 0;}
		virtual int dimentionSize(int i_space){return 0;}
		virtual int positionSize(int i_dimention, int i_position){return 0;}
		
		virtual DataSet<T>* iterateSpace(int i_space){
			m_iterateSpace = i_space;
			return this;
		}
		virtual DataSet<T>* iterateDimention(int i_space, int i_dimention){
			m_iterateSpace = i_space;
			m_iterateDimention = i_dimention;
			return this;
		}
		virtual void setIteration(int iter){}
		virtual int getIterationSize(){return 0;}
		virtual void last(){}
		virtual void next(){}
		
		virtual int space(){return m_space;}
		virtual int dimention(){return m_dimention;}
		virtual int position(){return m_position;}
    
		//cppObject part
		virtual String getClassName(){return "DataSet";}
		virtual String toString(){return "DataSet";}
		
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			if(b->getClassName() != this->getClassName()){
				return false;
			}
			((DataSet<T>*)b)->setIteration(0);
			this->setIteration(0);
			iterate(this){
				if(((DataSet<T>*)b)->getValue() != this->getValue()){
					return false;
				}
				((DataSet<T>*)b)->next();
			}
			((DataSet<T>*)b)->setIteration(0);
			this->setIteration(0);
			return true;
		}
		
		virtual void operator=(DataSet<T> b){}
		virtual bool operator==(DataSet<T> b){
			b.setIteration(0);
			this->setIteration(0);
			iterate(this){
				if( b.getValue() != this->getValue()){
					return false;
				}
				b.next();
			}
			b.setIteration(0);
			this->setIteration(0);
			return true;
		}

		virtual bool operator!=(DataSet<T> b){
			b.setIteration(0);
			this->setIteration(0);
			iterate(this){
				if( b.getValue() != this->getValue()){
					return true;
				}
				b.next();
			}
			b.setIteration(0);
			this->setIteration(0);
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
