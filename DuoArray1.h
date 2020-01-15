

#ifndef DuoArray1_h
#define DuoArray1_h

#include "DataSet.h"
#include "KVMap.h"

template<int xS2 = 3,int xS1 = 3>
class DuoArray1 : public DataSet<float>{
	public:
		float x1[xS1];
		float x2[xS2];
		
		DuoArray1(){
			this->dimentionLimit = 2;
		}
		
		virtual ~DuoArray1(){
			
		}
		
		void setArray1(float arr[xS1]){
			for(int x=0; x < xS1;x++){
				this->x1[x] = arr[x];
			}
		}
		
		void setArray2(float arr[xS2]){
			for(int x=0; x < xS2;x++){
				this->x2[x] = arr[x];
			}
		}
		
		virtual DataSet<float>* dimention(int dimentionPos){
			if(dimentionPos < this->dimentionLimit){
				this->dimentionMap = dimentionPos;
			}
			return this;
		}
		
		virtual DataSet<float>* vector(int vectorPosn, int pointPosn){
			if(vectorPosn == 0 && pointPosn < xS1){
				this->xP1 = pointPosn;
			}
			if(vectorPosn == 1 && pointPosn < xS2){
				this->xP2 = pointPosn;
			}
			return this;
		}
		
		virtual DataSet<float>* set(float t){
			if(this->dimentionMap == 0){
				x1[xP1] = t;
			}
			if(this->dimentionMap == 1){
				x2[xP2] = t;
			}
			return this;
		}
		
		virtual DataSet<float>* remove(){
			if(this->dimentionMap == 0){
				x1[xP1] = -1;
			}
			if(this->dimentionMap == 1){
				x2[xP2] = -1;
			}
			return this;
		}
		
		virtual float getValue(){
			if(this->dimentionMap == 0){
				return x1[xP1];
			}
			if(this->dimentionMap == 1){
				return x2[xP2];
			}
			return -1;
		}
		
		virtual float *getPointer(){
			if(this->dimentionMap == 0){
				return &x1[xP1];
			}
			if(this->dimentionMap == 1){
				return &x2[xP2];
			}
			return nullptr;
		}
		
		virtual int dimentionSize(){
			return 2;
		}
		
		virtual int dimentionVectorSize(int dimentionPos){
			if(this->dimentionMap == 0){
				return 1;
			}
			if(this->dimentionMap == 1){
				return 1;
			}
			return -1;
		}
		
		virtual int vectorSize(int dimentionPos){
			if(this->dimentionMap == 0){
				return xS1;
			}
			if(this->dimentionMap == 1){
				return xS2;
			}
			return -1;
		}
		
		virtual DataSet<float>* iterateDimention(int dimention){
			this->iterateOnlyOneDimention=true;
			this->iterateOnlyOneDimentionSize=true;
			this->iterdim=dimention;
			return this;
		}
		
		virtual void setIteration(int iter){
			if(this->iterateOnlyOneDimention){
				this->iterateOnlyOneDimention=false;
				this->iterateOnlyOneDimentionSize=false;
				if(this->iterdim==0){
					this->iterateCount = 0;
					this->dimentionMap = 0;
					this->xP1 = 0;
					this->xP2 = 0;					
				}
				if(this->iterdim==1){
					this->iterateCount = xS1;
					this->dimentionMap = 1;
					this->xP1 = 0;
					this->xP2 = 0;					
				}
				if(this->iterdim>=2){
					this->iterateCount = 0;
					this->dimentionMap = 0;
					this->xP1 = 0;
					this->xP2 = 0;					
				}
				
				return;
			}
			this->iterateCount = iter;
			if(iter == 0){
				this->dimentionMap = 0;
				this->xP1 = 0;
				this->xP2 = 0;
			}
			if(iter == this->getIterationSize()-1){
				this->dimentionMap = this->dimentionLimit-1;
				this->xP1 = xS1-1;
				this->xP2 = xS2-1;
			}
		}
		
		int getIterationSize(){
			if(this->iterateOnlyOneDimentionSize){
				this->iterateOnlyOneDimention=false;
				this->iterateOnlyOneDimentionSize=false;
				if(this->iterdim==0){
					this->fullSize = xS1;
					return this->fullSize;
				}
				if(this->iterdim==1){
					this->fullSize = xS1 + xS2;
					return this->fullSize;
				}
			}
			this->fullSize = xS1 + xS2;
			return this->fullSize;
		}
		
		virtual void last(){
			this->iterateCount--;
			if(xP1 >= 0 && this->dimentionMap == 0){
				xP1--;
			}
			
			if(xP2 >= 0 && this->dimentionMap == 1){
				xP2--;
			}
			if(this->iterateCount == xS1){
				this->dimentionMap++;
				this->xP1 = xS1-1;
				this->xP2 = xS2-1;
			}
			// if(this->iterateCount == xS1 + xS2){
				// this->dimentionMap = xS1 + xS2 - 1;
				// this->xP1 = xS1-1;
				// this->xP2 = xS2-1;
			// }
		}
		
		virtual void next(){
			this->iterateCount++;
			if(xP1 < xS1 && this->dimentionMap == 0){
				xP1++;
			}
			
			if(xP2 < xS2 && this->dimentionMap == 1){
				xP2++;
			}
			if(this->iterateCount == xS1){
				this->dimentionMap++;
				this->xP1 = 0;
				this->xP2 = 0;
			}
			// if(this->iterateCount == xS1 + xS2){
				// this->dimentionMap = 0;
				// this->xP2 = 0;
			// }
		}
		
		virtual int dimention(){
			return this->dimentionMap;
		}
		
		virtual int vector(int dimentionPos){
			if(this->dimentionMap == 0){
				return xP1;
			}
			if(this->dimentionMap == 1){
				return xP2;
			}
			return -1;
		}
		
		virtual String getClassName(){
			return "DuoArray1";
		}
		
		virtual String toString(){
			return "DuoArray1 " + String(this->dimentionMap) + " " + String(xP2) + " "  + String(xP1) + " = "  + String(getValue());
		}
		
		virtual DataSet<float>* clone(){
			DataSet<float> *nset = new DuoArray1<xS2,xS1>();
			nset->setIteration(0);
			this->setIteration(0);
			iterate(this){
				nset->set(this->getValue());
				nset->next();
			}
			nset->setIteration(0);
			this->setIteration(0);
			return nset;
		}
		virtual void offset(float offS){
			this->offSet=offS;
		}
		
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			if(b->getClassName() != this->getClassName()){
				return false;
			}
			((DataSet<float>*)b)->setIteration(0);
			this->setIteration(0);
			iterate(this){
				if(((DataSet<float>*)b)->getValue() <= this->getValue()+this->offSet ||
				   ((DataSet<float>*)b)->getValue() >= this->getValue()-this->offSet	){
					return false;
				}
				((DataSet<float>*)b)->next();
			}
			((DataSet<float>*)b)->setIteration(0);
			this->setIteration(0);
			return true;
		}
		
	private:
		int xP1 = 0;
		int xP2 = 0;
		int dimentionLimit = 0;
		int dimentionMap = 0;
		int fullSize = 0;
		float offSet = 0.1f;
		int iterdim=0;
		bool iterateOnlyOneDimentionSize=false;
		bool iterateOnlyOneDimention=false;
};

#endif 
