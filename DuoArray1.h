

#ifndef DuoArray1_h
#define DuoArray1_h

#include "DataSet.h"

template<class T, int xS1 = 3, int xS2 = 3>
class DuoArray1 : public DataSet<T>{
	protected:
	public:
		T x1[xS1];
		T x2[xS2];
		
		DuoArray1(){
			this->spaceLimit = 2;
		}
		
		virtual ~DuoArray1(){
			
		}
		
		void setArray1(const T arr[xS1]){
			for(int x=0; x < xS1;x++){
				this->x1[x] = arr[x];
			}
		}
		
		void setArray2(const T arr[xS2]){
			for(int x=0; x < xS2;x++){
				this->x2[x] = arr[x];
			}
		}
		
		virtual DataSet<T>* space(int i_space){
			if(i_space < this->spaceLimit){
				this->m_space = i_space;
			}
			return this;
		}
		
		virtual DataSet<T>* dimention(int i_dimention){
			if(this->m_space == 0 && i_dimention < 1){
				this->m_dimention = i_dimention;
			}
			if(this->m_space == 1 && i_dimention < 1){
				this->m_dimention = i_dimention;
			}
			return this;
		}
		
		virtual DataSet<T>* position(int i_position){
			this->m_position = i_position;
			if(this->m_space == 0 && this->m_dimention == 0 && i_position < xS1){
				this->xP1 = i_position;
			}
			if(this->m_space == 1 && this->m_dimention == 0 && i_position < xS2){
				this->xP2 = i_position;
			}
			return this;
		}
		
		virtual DataSet<T>* set(T t){
			if(this->m_space == 0){
				x1[xP1] = t;
			}
			if(this->m_space == 1){
				x2[xP2] = t;
			}
			return this;
		}
		
		virtual DataSet<T>* remove(){
			if(this->m_space == 0){
				x1[xP1] = -1;
			}
			if(this->m_space == 1){
				x2[xP2] = -1;
			}
			return this;
		}
		
		virtual T getValue(){
			if(this->m_space == 0 && this->xP1 < xS1){
				return x1[xP1];
			}
			if(this->m_space == 1 && this->xP2 < xS2){
				return x2[xP2];
			}
			return -1;
		}
		
		virtual T *getPointer(){
			if(this->m_space == 0){
				return &x1[xP1];
			}
			if(this->m_space == 1){
				return &x2[xP2];
			}
			return nullptr;
		}
		
		virtual int spaceSize(){
			return 2;
		}
		
		virtual int dimentionSize(int i_space){
			if(i_space == 0){
				return 1;
			}
			if(i_space == 1){
				return 1;
			}
			return -1;
		}
		
		virtual int positionSize(int i_space, int i_dimention){
			if(i_space == 0){
				if(i_dimention == 0){
					return xS1;
				}
			}
			if(i_space == 1){
				if(i_dimention == 0){
					return xS2;
				}
			}
			return -1;
		}
		
		virtual void setIteration(int iter){
			this->iterateCount = iter;	
			if(this->m_iterateSpace == -1){
				if(iter >= xS1 + xS2){
					return;
				}
				this->xP1 = iter;
				this->xP2 = iter-xS1;
				return;				
			}
			if(this->m_iterateSpace >= 2 || this->m_iterateDimention >= 1){
				return;				
			}
			if(this->m_iterateSpace == 0){
				this->m_space = 0;
				if(iter < xS1){
					this->xP1 = iter;
				}
				return;
			}
			if(this->m_iterateSpace == 1){
				this->m_space = 1;
				if(iter < xS2){
					this->xP2 = iter;
				}
				return;
			}
			this->m_dimention = this->m_iterateDimention;
			this->m_iterateSpace = -1;
			this->m_iterateDimention = -1;
		}
		
		int getIterationSize(){
			if(this->m_iterateSpace >= 2 || this->m_iterateDimention >= 1){
				return 0;				
			}
			if(this->m_iterateSpace == 0){
				this->fullSize = xS1;
				this->m_iterateSpace = -1;
				this->m_iterateDimention = -1;
				return this->fullSize;
			}
			if(this->m_iterateSpace == 1){
				this->fullSize = xS2;
				this->m_iterateSpace = -1;
				this->m_iterateDimention = -1;
				return this->fullSize;
			}
			this->m_iterateSpace = -1;
			this->m_iterateDimention = -1;
			this->fullSize = xS1 + xS2;
			return this->fullSize;
		}
		
		virtual void last(){
			this->iterateCount--;
			this->xP1--;
			this->xP2--;
			this->xP1 = this->xP1 * (this->xP1 < xS1);
			this->xP2 = this->xP2 * (this->xP2 < xS2);
			this->m_space = this->iterateCount >= xS1;
			this->m_iterateSpace = -1;
			this->m_iterateDimention = -1;
		}
		
		virtual void next(){
			this->iterateCount++;
			this->xP1++;
			this->xP2++;
			this->xP1 = this->xP1 * (this->xP1 < xS1);
			this->xP2 = this->xP2 * (this->xP2 < xS2);
			this->m_space = this->iterateCount >= xS1;
			this->m_iterateSpace = -1;
			this->m_iterateDimention = -1;
		}
		
		virtual String getClassName(){
			return "DuoArray1";
		}
		
		virtual String toString(){
			return "DuoArray1(" + String(this->m_space) + ", " + String(xP2) + ", "  + String(xP1) + " = "  + String(getValue()) + ")";
		}
		
		virtual DataSet<T>* clone(){
			DuoArray1<T,xS2,xS1> *nset = new DuoArray1<T,xS2,xS1>();
			nset->setArray1(this->x1);
			nset->setArray2(this->x2);
			return nset;
		}
		
	private:
		int xP1 = 0;
		int xP2 = 0;
		int spaceLimit = 0;
		int fullSize = 0;
};

#endif 
