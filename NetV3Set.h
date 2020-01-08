

#ifndef NetV3Set_h
#define NetV3Set_h

#include "DataSet.h"
#include "KVMap.h"

template<int zS = 1, int yS = 2, int xS = 3>
class NetV3Set : public DataSet<float>{
	public:
		float x1[xS];
		float x2[yS][xS];
		float x3[zS][yS][xS];
		
		NetV3Set(){
			this->dimentionLimit = 3;
		}
		
		virtual ~NetV3Set(){
			
		}
		
		void setArray(float arr[xS]){
			for(int x=0; x < xS;x++){
				this->x1[x] = arr[x];
			}
		}
		
		void setArray(float arr[yS][xS]){
			for(int x=0; x < xS;x++){
				for(int y=0; y < yS;y++){
					this->x2[y][x] = arr[y][x];
				}
				
			}
		}
		
		void setArray(float arr[zS][yS][xS]){
			for(int x=0; x < xS;x++){
				for(int y=0; y < yS;y++){
					for(int z=0; z < zS;z++){
						this->x3[z][y][x] = arr[z][y][x];
					}
				}				
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
			if(vectorPosn == 1 && pointPosn < yS){
				this->yP = pointPosn;
			}
			if(vectorPosn == 2 && pointPosn < zS){
				this->zP = pointPosn;
			}
			return this;
		}
		
		virtual DataSet<float>* set(float t){
			if(this->dimentionMap == 0){
				x1[xP] = t;
			}
			if(this->dimentionMap == 1){
				x2[yP][xP] = t;
			}
			if(this->dimentionMap == 2){
				x3[zP][yP][xP] = t;
			}
			return this;
		}
		
		virtual DataSet<float>* remove(){
			if(this->dimentionMap == 0){
				x1[xP] = -1;
			}
			if(this->dimentionMap == 1){
				x2[yP][xP] = -1;
			}
			if(this->dimentionMap == 2){
				x3[zP][yP][xP] = -1;
			}
			return this;
		}
		
		virtual float getValue(){
			if(this->dimentionMap == 0){
				return x1[xP];
			}
			if(this->dimentionMap == 1){
				return x2[yP][xP];
			}
			if(this->dimentionMap == 2){
				return x3[zP][yP][xP];
			}
			return -1;
		}
		
		virtual float *getPointer(){
			if(this->dimentionMap == 0){
				return &x1[xP];
			}
			if(this->dimentionMap == 1){
				return &x2[yP][xP];
			}
			if(this->dimentionMap == 2){
				return &x3[zP][yP][xP];
			}
			return nullptr;
		}
		
		virtual int dimentionSize(){
			return 3;
		}
		
		virtual int vectorSize(int dimentionPos){
			if(this->dimentionMap == 0){
				return xS;
			}
			if(this->dimentionMap == 1){
				return yS;
			}
			if(this->dimentionMap == 2){
				return zS;
			}
			return -1;
		}
		
		virtual void setIteration(int iter){
			this->iterateCount = iter;
			if(iter == 0){
				this->dimentionMap = 0;
				this->xP = 0;
				this->yP = 0;
				this->zP = 0;
			}
			if(iter == this->getIterationSize()-1){
				this->dimentionMap = this->dimentionLimit-1;
				this->xP = xS-1;
				this->yP = yS-1;
				this->zP = zS-1;
			}
		}
		
		int getIterationSize(){
			this->fullSize = xS + xS*yS + xS*yS*zS;
			return this->fullSize;
		}
		
		virtual void last(){
			this->iterateCount--;
			xP--;
			if(xP >= 0){
				xP = xS;
				yP--;
				if(yP < 0){
					yP = yS;
					zP--;
					if(zP < 0){
						zP = zS;
					}
				}
			}
			if(this->iterateCount == xS){
				this->dimentionMap++;
				this->xP = xS-1;
				this->yP = yS-1;
				this->zP = zS-1;
			}
			if(this->iterateCount == xS + xS*yS){
				this->dimentionMap++;
				this->xP = xS-1;
				this->yP = yS-1;
				this->zP = zS-1;
			}
		}
		
		virtual void next(){
			this->iterateCount++;
			xP++;
			if(xP >= xS){
				xP = 0;
				yP++;
				if(yP >= yS){
					yP = 0;
					zP++;
					if(zP >= zS){
						zP = 0;
					}
				}
			}
			if(this->iterateCount == xS){
				this->dimentionMap++;
				this->xP = 0;
				this->yP = 0;
				this->zP = 0;
			}
			if(this->iterateCount == xS + xS*yS){
				this->dimentionMap++;
				this->xP = 0;
				this->yP = 0;
				this->zP = 0;
			}
		}
		
		virtual int dimention(){
			return this->dimentionMap;
		}
		
		virtual int vector(int dimentionPos){
			if(this->dimentionMap == 0){
				return xP;
			}
			if(this->dimentionMap == 1){
				return yP;
			}
			if(this->dimentionMap == 2){
				return zP;
			}
			return -1;
		}
		
		virtual String getClassName(){
			return "NetV3Set";
		}
		
		virtual String toString(){
			return "NetV3Set " + String(this->dimentionMap) + " " + String(zP) + " "  + String(yP) + " "  + String(xP) + " = "  + String(getValue());
		}
		
		virtual DataSet<float>* clone(){
			DataSet<float> *nset = new NetV3Set<zS,yS,xS>();
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
		int yP = 0;
		int zP = 0;
		int dimentionLimit = 0;
		int dimentionMap = 0;
		int fullSize = 0;
};

#endif 
