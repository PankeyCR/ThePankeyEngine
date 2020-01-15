

#ifndef ArraySet_h
#define ArraySet_h

#include "DataSet.h"
#include "KVMap.h"

template<int xS = 3>
class ArraySet : public DataSet<float>{
	public:
		float x1[xS];
		
		ArraySet(){
			this->dimentionLimit = 1;
		}
		
		virtual ~ArraySet(){
			
		}
		
		void setArray(float arr[xS]){
			for(int x=0; x < xS;x++){
				this->x1[x] = arr[x];
			}
		}
		
		virtual DataSet<float>* dimention(int dimentionPos){
			if(dimentionPos < this->dimentionLimit){
				this->dimentionMap = dimentionPos;
			}
			return this;
		}
		
		virtual DataSet<float>* vector(int vectorPosn, int pointPosn){
			if(vectorPosn == 0 && pointPosn < xS){
				this->xP = pointPosn;
			}
			return this;
		}
		
		virtual DataSet<float>* set(float t){
			if(this->dimentionMap == 0){
				x1[xP] = t;
			}
			return this;
		}
		
		virtual DataSet<float>* remove(){
			if(this->dimentionMap == 0){
				x1[xP] = -1;
			}
			return this;
		}
		
		virtual float getValue(){
			if(this->dimentionMap == 0){
				return x1[xP];
			}
			return -1;
		}
		
		virtual float *getPointer(){
			if(this->dimentionMap == 0){
				return &x1[xP];
			}
			return nullptr;
		}
		
		virtual int dimentionSize(){
			return 1;
		}
		
		virtual int dimentionVectorSize(int dimentionPos){
			if(this->dimentionMap == 0){
				return 1;
			}
			return -1;
		}
		
		virtual int vectorSize(int dimentionPos){
			if(this->dimentionMap == 0){
				return xS;
			}
			return -1;
		}
		
		virtual void setIteration(int iter){
			this->iterateCount = iter;
			if(iter == 0){
				this->dimentionMap = 0;
				this->xP = 0;
			}
			if(iter == this->getIterationSize()-1){
				this->dimentionMap = this->dimentionLimit-1;
				this->xP = xS-1;
			}
		}
		
		int getIterationSize(){
			this->fullSize = xS;
			return this->fullSize;
		}
		
		virtual void last(){
			this->iterateCount--;
			if(xP > 0 && this->dimentionMap == 0){
				xP--;
			}
			if(this->iterateCount == xS){
				this->dimentionMap++;
				this->xP = xS-1;
			}
			// if(this->iterateCount == xS + xS2){
				// this->dimentionMap = xS + xS2 - 1;
				// this->xP = xS-1;
				// this->xP2 = xS2-1;
			// }
		}
		
		virtual void next(){
			this->iterateCount++;
			if(xP < xS && this->dimentionMap == 0){
				xP++;
			}
			if(this->iterateCount == xS){
				this->dimentionMap++;
				this->xP = 0;
			}
		}
		
		virtual int dimention(){
			return this->dimentionMap;
		}
		
		virtual int vector(int dimentionPos){
			if(this->dimentionMap == 0){
				return xP;
			}
			return -1;
		}
		
		virtual String getClassName(){
			return "ArraySet";
		}
		
		virtual String toString(){
			return "ArraySet " + String(this->dimentionMap) + " "  + String(xP) + " = "  + String(getValue());
		}
		
		virtual DataSet<float>* clone(){
			DataSet<float> *nset = new ArraySet<xS>();
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
		
	private:
		int xP = 0;
		int dimentionLimit = 0;
		int dimentionMap = 0;
		int fullSize = 0;
};

#endif 
