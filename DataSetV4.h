

#ifndef DataSetV4_h
#define DataSetV4_h

#include "DataSet.h"
#include "KVMap.h"

template<int wS = 1, int zS = 2, int yS = 3, int xS = 2>
class DataSetV4 : public DataSet<float>{
	public:
		DataSetV4(){
			this->dimentionLimit = 4;
		}
		
		virtual ~DataSetV4(){
			
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
		
		void setArray(float arr[wS][zS][yS][xS]){
			for(int x=0; x < xS;x++){
				for(int y=0; y < yS;y++){
					for(int z=0; z < zS;z++){
						this->x3[z][y][x] = arr[z][y][x];
						for(int w=0; w < wS;w++){
							this->x4[w][z][y][x] = arr[w][z][y][x];
						}
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
			if(vectorPosn == 3 && pointPosn < wS){
				this->wP = pointPosn;
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
			if(this->dimentionMap == 3){
				x4[wP][zP][yP][xP] = t;
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
			if(this->dimentionMap == 3){
				x4[wP][zP][yP][xP] = -1;
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
			if(this->dimentionMap == 3){
				return x4[wP][zP][yP][xP];
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
			if(this->dimentionMap == 3){
				return &x4[wP][zP][yP][xP];
			}
			return nullptr;
		}
		
		virtual int dimentionSize(){
			return 4;
		}
		
		virtual int dimentionVectorSize(int dimentionPos){
			if(dimentionPos == 0){
				return 1;
			}
			if(dimentionPos == 1){
				return 2;
			}
			if(dimentionPos == 2){
				return 3;
			}
			if(dimentionPos == 3){
				return 4;
			}
			return -1;
		}
		
		virtual int vectorSize(int dimentionPos, int vectorPos){
			if(dimentionPos == 0){
				if(vectorPos == 0){
					return xS;
				}
			}
			if(dimentionPos == 1){
				if(vectorPos == 0){
					return xS;
				}
				if(vectorPos == 1){
					return yS;
				}
			}
			if(dimentionPos == 2){
				if(vectorPos == 0){
					return xS;
				}
				if(vectorPos == 1){
					return yS;
				}
				if(vectorPos == 2){
					return zS;
				}
			}
			if(dimentionPos == 3){
				if(vectorPos == 0){
					return xS;
				}
				if(vectorPos == 1){
					return yS;
				}
				if(vectorPos == 2){
					return zS;
				}
				if(vectorPos == 3){
					return wS;
				}
			}
			return -1;
		}
		
		virtual void setIteration(int iter){
			if(this->iteratedimention >= 0){
				if(this->iteratedimention == 0){
					this->iterateCount = 0;
					this->dimentionMap = 0;
					this->xP = 0;
					this->yP = 0;
					this->zP = 0;
					this->wP = 0;			
				}
				if(this->iteratedimention == 1){
					this->iterateCount = 0;
					this->dimentionMap = 1;
					this->xP = 0;
					this->yP = 0;
					this->zP = 0;	
					this->wP = 0;			
				}
				if(this->iteratedimention == 2){
					this->iterateCount = 0;
					this->dimentionMap = 2;
					this->xP = 0;
					this->yP = 0;
					this->zP = 0;
					this->wP = 0;				
				}
				if(this->iteratedimention == 3){
					this->iterateCount = 0;
					this->dimentionMap = 3;
					this->xP = 0;
					this->yP = 0;
					this->zP = 0;
					this->wP = 0;				
				}
				if(this->iteratedimention >= 4){
					this->iterateCount = 0;
					this->dimentionMap = 0;
					this->xP = 0;
					this->yP = 0;
					this->zP = 0;
					this->wP = 0;		
				}
				this->iteratedimention = -1;
				return;
			}
			this->iterateCount = iter;
			if(iter == 0){
				this->dimentionMap = 0;
				this->xP = 0;
				this->yP = 0;
				this->zP = 0;
				this->wP = 0;
			}
			if(iter == this->getIterationSize()-1){
				this->dimentionMap = this->dimentionLimit-1;
				this->xP = xS-1;
				this->yP = yS-1;
				this->zP = zS-1;
				this->wP = wS-1;
			}
		}
		
		int getIterationSize(){
			if(this->iteratedimention >= 0){
				if(this->iteratedimention == 0){
					this->fullSize = xS;
				}
				if(this->iteratedimention == 1){
					this->fullSize = xS*yS;
				}
				if(this->iteratedimention == 2){
					this->fullSize = xS*yS*zS;
				}
				if(this->iteratedimention == 3){
					this->fullSize = xS*yS*zS*wS;
				}
				this->iteratedimention = -1;
				return this->fullSize;
			}
			this->fullSize = xS + xS*yS + xS*yS*zS + xS*yS*zS*wS;
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
						wP--;
						if(wP < 0){
							wP = wS;
						}
					}
				}
			}
		}
		
		virtual void next(){
			this->iterateCount++;
			if(this->iteratedimention >= 0){
				if(this->iteratedimention == 0){
					xP++;
				}
				if(this->iteratedimention == 1){
					xP++;
					if(xP >= xS){
						xP = 0;
						yP++;
					}
				}
				if(this->iteratedimention == 2){
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
				}
				if(this->iteratedimention == 3){
					xP++;
					if(xP >= xS){
						xP = 0;
						yP++;
						if(yP >= yS){
							yP = 0;
							zP++;
							if(zP >= zS){
								zP = 0;
								wP++;
								if(wP >= wS){
									wP = 0;
								}
							}
						}
					}
				}
				this->iteratedimention = -1;
				return;
			}
			xP++;
			if(xP >= xS){
				xP = 0;
				yP++;
				if(yP >= yS){
					yP = 0;
					zP++;
					if(zP >= zS){
						zP = 0;
						wP++;
						if(wP >= wS){
							wP = 0;
						}
					}
				}
			}
			if(this->iterateCount == xS){
				this->dimentionMap++;
				this->xP = 0;
				this->yP = 0;
				this->zP = 0;
				this->wP = 0;
			}
			if(this->iterateCount == xS + xS*yS){
				this->dimentionMap++;
				this->xP = 0;
				this->yP = 0;
				this->zP = 0;
				this->wP = 0;
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
			if(this->dimentionMap == 3){
				return wP;
			}
			return -1;
		}
		
		virtual String getClassName(){
			return "DataSetV4";
		}
		
		virtual String toString(){
			return "DataSetV4 " + String(this->dimentionMap) + " " + String(wP) + " "  + String(zP) + " "  + String(yP) + " "  + String(xP) + " = "  + String(getValue());
		}
		
		virtual DataSet<float>* clone(){
			DataSet<float> *nset = new DataSetV4<wS,zS,yS,xS>();
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
		float x1[xS];
		float x2[yS][xS];
		float x3[zS][yS][xS];
		float x4[wS][zS][yS][xS];
		int xP = 0;
		int yP = 0;
		int zP = 0;
		int wP = 0;
		int dimentionLimit = 0;
		int dimentionMap = 0;
		int fullSize = 0;
};

#endif 
