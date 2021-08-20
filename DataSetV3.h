

#ifndef DataSetV3_h
#define DataSetV3_h

#include "DataSet.h"
/*
template<class T, int xS = 3, int yS = 2, int zS = 1>
class DataSetV3 : public DataSet<T>{
	public:
		T x1[xS];
		T x2[yS][xS];
		T x3[zS][yS][xS];
		T r;
		
		DataSetV3(){
		}
		DataSetV3(T rr){
			r = rr;
		}
		
		virtual ~DataSetV3(){
		}
		
		void setArray(T arr[xS]){
			for(int x=0; x < xS;x++){
				this->x1[x] = arr[x];
			}
		}
		
		void setArray(T arr[yS][xS]){
			for(int x=0; x < xS;x++){
				for(int y=0; y < yS;y++){
					this->x2[y][x] = arr[y][x];
				}
			}
		}
		
		void setArray(T arr[zS][yS][xS]){
			for(int x=0; x < xS;x++){
				for(int y=0; y < yS;y++){
					for(int z=0; z < zS;z++){
						this->x3[z][y][x] = arr[z][y][x];
					}
				}				
			}
		}
		
		virtual DataSet<T>* position(int i_position){
			if(this->m_dimention == 0 && this->m_position < xS){
				xP = i_position;
			}
			if(this->m_dimention == 1 && this->m_position < yS){
				yP = i_position;
			}
			if(this->m_dimention == 2 && this->m_position < zS){
				zP = i_position;
			}
			this->m_position = i_position;
			return this;
		}
		
		virtual DataSet<T>* set(T t){
			if(this->m_space == 0){
				x1[xP] = t;
			}
			if(this->m_space == 1){
				x2[yP][xP] = t;
			}
			if(this->m_space == 2){
				x3[zP][yP][xP] = t;
			}
			return this;
		}
		
		virtual DataSet<T>* remove(){
			if(this->m_space == 0){
				x1[xP] = r;
			}
			if(this->m_space == 1){
				x2[yP][xP] = r;
			}
			if(this->m_space == 2){
				x3[zP][yP][xP] = r;
			}
			return this;
		}
		
		virtual T getValue(){
			if(this->m_space == 0){
				return x1[xP];
			}
			if(this->m_space == 1){
				return x2[yP][xP];
			}
			if(this->m_space == 2){
				return x3[zP][yP][xP];
			}
			return -1;
		}
		
		virtual T* getPointer(){
			if(this->m_space == 0){
				return &x1[xP];
			}
			if(this->m_space == 1){
				return &x2[yP][xP];
			}
			if(this->m_space == 2){
				return &x3[zP][yP][xP];
			}
			return nullptr;
		}
		
		virtual int spaceSize(){
			return 3;
		}
		
		virtual int dimentionSize(int i_space){
			if(i_space == 0){
				return 1;
			}
			if(i_space == 1){
				return 2;
			}
			if(i_space == 2){
				return 3;
			}
			return -1;
		}
		
		virtual int positionSize(int i_space, int i_dimention){
			if(i_space == 0){
				if(i_dimention == 0){
					return xS;
				}
			}
			if(i_space == 1){
				if(i_dimention == 0){
					return xS;
				}
				if(i_dimention == 1){
					return yS;
				}
			}
			if(i_space == 2){
				if(i_dimention == 0){
					return xS;
				}
				if(i_dimention == 1){
					return yS;
				}
				if(i_dimention == 2){
					return zS;
				}
			}
			return -1;
		}
		
		int getIterationSize(){
			return xS + xS*yS + xS*yS*zS;
		}
		
		virtual cppObjectClass* getClass(){
			return Class<DataSetV3<T,xS,yS,zS>>::classType;
		}
		
		virtual String toString(){
			return "DataSetV3 " + String(this->m_space) + " " + String(zP) + " "  + String(yP) + " "  + String(xP) + " = "  + String(getValue());
		}
		
		virtual DataSet<T>* clone(bool mem){
			DataSetV3<T,xS,yS,zS> *nset = new DataSetV3<T,xS,yS,zS>();
			nset->setArray(this->x1);
			nset->setArray(this->x2);
			nset->setArray(this->x3);
			return nset;
		}
		
		virtual DataSet<T>* set(Iterator i,T t){
			int x = i.getIteration();
			if(x < xS){
				x1[x] = t;
			}
			if(x >= xS && x < xS + xS){
				x2[0][x-xS] = t;
			}
			if(x >=  xS + xS && x < xS + xS*yS){
				float a = (x-xS-xS)/xS;
				float s = a-(int)a;
				x2[(int)a][s*xS] = t;
			}
			if(x >= xS + xS*yS && x < xS + xS*yS + xS*yS*zS){
				float a = (x-xS-xS)/xS;
				float s = a-(int)a;
				x3[0][0][x-xS / yS] = t;
			}
			return this;
		}
		virtual DataSet<T>* remove(Iterator i){
			int x = i.getIteration();
			if(x < xS){
				x1[x] = r;
			}else{
				x2[x-xS] = r;
			}
			return this;
		}
		virtual T getValue(Iterator i){
			int x = i.getIteration();
			if(x < xS){
				return x1[x];
			}
			if(x-xS < xS){
				return x2[x-xS];
			}
			return r;
		}
		virtual T* getPointer(Iterator i){
			int x = i.getIteration();
			if(x < xS){
				return &x1[x];
			}else{
				return &x2[x-xS];
			}
			return nullptr;
		}
		virtual String toString(Iterator i){
			int x = i.getIteration();
			T t;
			int s;
			if(x < xS){
				s = 0;
				t = x1[x];
			}else{
				s = 1;
				t = x2[x-xS];
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
			if(x < xS){
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
			if(x < xS){
				return x;
			}else{
				return x-xS;
			}
			return -1;
		}
		
	protected:
		int xP = 0;
		int yP = 0;
		int zP = 0;
};

*/

#endif 
