

#ifndef DuoArray1_h
#define DuoArray1_h

#include "DataSet.h"

namespace ame{

template<class T, int xS1 = 3, int xS2 = 3>
class DuoArray1 : public DataSet<T>{
	protected:
	public:
		T x1[xS1];
		T x2[xS2];
		T r;
		
		DuoArray1(){
		}
		DuoArray1(T rr){
			r = rr;
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
		
		virtual DataSet<T>* set(T t){
			if(this->m_space == 0 && this->m_dimention == 0 && this->m_position < xS1){
				x1[this->m_position] = t;
			}
			if(this->m_space == 1 && this->m_dimention == 0 && this->m_position < xS2){
				x2[this->m_position] = t;
			}
			return this;
		}
		
		virtual DataSet<T>* remove(){
			if(this->m_space == 0 && this->m_dimention == 0 && this->m_position < xS1){
				x1[this->m_position] = r;
			}
			if(this->m_space == 1 && this->m_dimention == 0 && this->m_position < xS2){
				x2[this->m_position] = r;
			}
			return this;
		}
		
		virtual T getValue(){
			if(this->m_space == 0 && this->m_dimention == 0 && this->m_position < xS1){
				return x1[this->m_position];
			}
			if(this->m_space == 1 && this->m_dimention == 0 && this->m_position < xS2){
				return x2[this->m_position];
			}
			return r;
		}
		
		virtual T* getPointer(){
			if(this->m_space == 0 && this->m_dimention == 0 && this->m_position < xS1){
				return &x1[this->m_position];
			}
			if(this->m_space == 1 && this->m_dimention == 0 && this->m_position < xS2){
				return &x2[this->m_position];
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
		virtual int getSize(int i_space){
			if(i_space == 0){
				return xS1;
			}
			if(i_space == 1){
				return xS2;
			}
			return -1;
		}
		
		virtual int getSize(int i_space, int i_dimention){
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
		
		int getIterationSize(){
			return xS1 + xS2;
		}
		
		virtual cppObjectClass* getClass(){
			return Class<DuoArray1<T,xS2,xS1>>::classType;
		}
		
		virtual String toString(){
			return "DuoArray1(" + String(this->m_space) + ", " + String(xP2) + ", "  + String(xP1) + " = "  + String(getValue()) + ")";
		}
		
		virtual DataSet<T>* clone(bool mem){
			DuoArray1<T,xS2,xS1>* nset = new DuoArray1<T,xS2,xS1>();
			nset->setArray1(this->x1);
			nset->setArray2(this->x2);
			return nset;
		}
		
		virtual DataSet<T>* set(Iterator i,T t){
			int x = i.getIteration();
			if(x < xS1){
				x1[x] = t;
			}else{
				x2[x-xS1] = t;
			}
			return this;
		}
		virtual DataSet<T>* remove(Iterator i){
			int x = i.getIteration();
			if(x < xS1){
				x1[x] = r;
			}else{
				x2[x-xS1] = r;
			}
			return this;
		}
		virtual T getValue(Iterator i){
			int x = i.getIteration();
			if(x < xS1){
				return x1[x];
			}
			if(x-xS1 < xS2){
				return x2[x-xS1];
			}
			return r;
		}
		virtual T* getPointer(Iterator i){
			int x = i.getIteration();
			if(x < xS1){
				return &x1[x];
			}else{
				return &x2[x-xS1];
			}
			return nullptr;
		}
		virtual String toString(Iterator i){
			int x = i.getIteration();
			T t;
			int s;
			if(x < xS1){
				s = 0;
				t = x1[x];
			}else{
				s = 1;
				t = x2[x-xS1];
			}
			return  String("DuoArray1(") + 
					String(x) + 
					", " + 
					String(s) + 
					", " + 
					String(0) + 
					" = "  + 
					String(t) + 
					")";
		}
		
		virtual T getInSpace(int i_space, Iterator i){
			int x = i.getIteration();
			if(i_space == 0){
				return x1[x];
			}
			if(i_space == 1){
				return x2[x];
			}
			return r;
		}
		virtual T getInDimention(int i_space, int i_dimention, Iterator i){
			int x = i.getIteration();
			if(i_dimention != 0){
				return r;
			}
			if(i_space == 0){
				return x1[x];
			}
			if(i_space == 1){
				return x2[x];
			}
			return r;
		}
		
		virtual T* getPointerInSpace(int i_space, Iterator i){
			int x = i.getIteration();
			if(i_space == 0){
				return &x1[x];
			}
			if(i_space == 1){
				return &x2[x];
			}
			return nullptr;
		}
		virtual T* getPointerInDimention(int i_space, int i_dimention, Iterator i){
			int x = i.getIteration();
			if(i_dimention != 0){
				return nullptr;
			}
			if(i_space == 0){
				return &x1[x];
			}
			if(i_space == 1){
				return &x2[x];
			}
			return nullptr;
		}
		
		virtual int space(Iterator i){
			int x = i.getIteration();
			if(x < xS1){
				return 0;
			}else{
				return 1;
			}
			return -1;
		}
		virtual int dimention(Iterator i){
			return 0;
		}
		virtual int position(Iterator i){
			int x = i.getIteration();
			if(x < xS1){
				return x;
			}else{
				return x-xS1;
			}
			return -1;
		}
		
	private:
		int xP1 = 0;
		int xP2 = 0;
};

}

#endif 
