
#include "ame_Enviroment.hpp"

#ifndef DataSetV4_hpp
#define DataSetV4_hpp

#include "DataSet.hpp"

/*

template<class T, int xS = 2, int yS = 3, int zS = 2, int wS = 1>
class DataSetV4 : public DataSet<T>{
	public:
		T x1[xS];
		T x2[yS][xS];
		T x3[zS][yS][xS];
		T x4[wS][zS][yS][xS];
		
		DataSetV4(){
			this->spaceLimit = 4;
		}
		
		virtual ~DataSetV4(){
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
		
		void setArray(T arr[wS][zS][yS][xS]){
			for(int x=0; x < xS;x++){
				for(int y=0; y < yS;y++){
					for(int z=0; z < zS;z++){
						for(int w=0; w < wS;w++){
							this->x4[w][z][y][x] = arr[w][z][y][x];
						}
					}
				}				
			}
		}
		
		virtual DataSet<T>* space(int i_space){
			if(i_space < this->spaceLimit){
				this->m_space = i_space;
			}else{
				this->m_space = -1;
			}
			return this;
		}
		
		virtual DataSet<T>* dimention(int i_dimention){
			if(this->m_space == 0 && i_dimention < 1){
				this->m_dimention = i_dimention;
			}
			if(this->m_space == 1 && i_dimention < 2){
				this->m_dimention = i_dimention;
			}
			if(this->m_space == 2 && i_dimention < 3){
				this->m_dimention = i_dimention;
			}
			if(this->m_space == 3 && i_dimention < 4){
				this->m_dimention = i_dimention;
			}
			return this;
		}
		
		virtual DataSet<T>* position(int i_position){
			this->m_position = i_position;
			if(this->m_dimention == 0 && i_position < xS){
				this->xP = i_position;
			}
			if(this->m_dimention == 1 && i_position < yS){
				this->yP = i_position;
			}
			if(this->m_dimention == 2 && i_position < zS){
				this->zP = i_position;
			}
			if(this->m_dimention == 3 && i_position < wS){
				this->wP = i_position;
			}
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
			if(this->m_space == 3){
				x4[wP][zP][yP][xP] = t;
			}
			return this;
		}
		
		virtual DataSet<T>* remove(){
			if(this->m_space == 0){
				x1[xP] = -1;
			}
			if(this->m_space == 1){
				x2[yP][xP] = -1;
			}
			if(this->m_space == 2){
				x3[zP][yP][xP] = -1;
			}
			if(this->m_space == 3){
				x4[wP][zP][yP][xP] = -1;
			}
			return this;
		}
		
		virtual T getValue(){
			if(this->m_space == 0 && this->xP < xS){
				return x1[xP];
			}
			if(this->m_space == 1 && this->xP < xS && this->yP < yS){
				return x2[yP][xP];
			}
			if(this->m_space == 2 && this->xP < xS && this->yP < yS && this->zP < zS){
				return x3[zP][yP][xP];
			}
			if(this->m_space == 3 && this->xP < xS && this->yP < yS && this->zP < zS && this->wP < wS){
				return x4[wP][zP][yP][xP];
			}
			return -1;
		}
		
		virtual T* getPointer(){
			if(this->m_space == 0 && this->xP < xS){
				return &x1[xP];
			}
			if(this->m_space == 1 && this->xP < xS && this->yP < yS){
				return &x2[yP][xP];
			}
			if(this->m_space == 2 && this->xP < xS && this->yP < yS && this->zP < zS){
				return &x3[zP][yP][xP];
			}
			if(this->m_space == 3 && this->xP < xS && this->yP < yS && this->zP < zS && this->wP < wS){
				return &x4[wP][zP][yP][xP];
			}
			return nullptr;
		}
		
		virtual int spaceSize(){
			return 4;
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
			if(i_space == 3){
				return 4;
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
			if(i_space == 3){
				if(i_dimention == 0){
					return xS;
				}
				if(i_dimention == 1){
					return yS;
				}
				if(i_dimention == 2){
					return zS;
				}
				if(i_dimention == 3){
					return wS;
				}
			}
			return -1;
		}
		
		virtual void setIteration(int iter){
			// if(this->m_iterateSpace >= 0){
				// if(this->m_iterateSpace == 0){
					// this->iterateCount = 0;
					// this->m_space = 0;
					// this->xP = 0;
					// this->yP = 0;
					// this->zP = 0;
					// this->wP = 0;			
				// }
				// if(this->m_iterateSpace == 1){
					// this->iterateCount = 0;
					// this->m_space = 1;
					// this->xP = 0;
					// this->yP = 0;
					// this->zP = 0;	
					// this->wP = 0;			
				// }
				// if(this->m_iterateSpace == 2){
					// this->iterateCount = 0;
					// this->m_space = 2;
					// this->xP = 0;
					// this->yP = 0;
					// this->zP = 0;
					// this->wP = 0;				
				// }
				// if(this->m_iterateSpace == 3){
					// this->iterateCount = 0;
					// this->m_space = 3;
					// this->xP = 0;
					// this->yP = 0;
					// this->zP = 0;
					// this->wP = 0;				
				// }
				// if(this->m_iterateSpace >= 4){
					// this->iterateCount = 0;
					// this->m_space = 0;
					// this->xP = 0;
					// this->yP = 0;
					// this->zP = 0;
					// this->wP = 0;		
				// }
				// this->m_iterateSpace = -1;
				// return;
			// }
			// this->iterateCount = iter;
			// if(iter == 0){
				// this->m_space = 0;
				// this->xP = 0;
				// this->yP = 0;
				// this->zP = 0;
				// this->wP = 0;
			// }
			// if(iter == this->getIterationSize()-1){
				// this->m_space = this->spaceLimit-1;
				// this->xP = xS-1;
				// this->yP = yS-1;
				// this->zP = zS-1;
				// this->wP = wS-1;
			// }
		}
		
		int getIterationSize(){
			// if(this->m_iterateSpace >= 0){
				// if(this->m_iterateSpace == 0){
					// this->fullSize = xS;
				// }
				// if(this->m_iterateSpace == 1){
					// this->fullSize = xS*yS;
				// }
				// if(this->m_iterateSpace == 2){
					// this->fullSize = xS*yS*zS;
				// }
				// if(this->m_iterateSpace == 3){
					// this->fullSize = xS*yS*zS*wS;
				// }
				// this->m_iterateSpace = -1;
				// return this->fullSize;
			// }
			// this->fullSize = xS + xS*yS + xS*yS*zS + xS*yS*zS*wS;
			return this->fullSize;
		}
		
		virtual bool last(){
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
			return true;
		}
		
		virtual bool next(){
			this->iterateCount++;
			// if(this->m_iterateSpace >= 0){
				// if(this->m_iterateSpace == 0){
					// xP++;
				// }
				// if(this->m_iterateSpace == 1){
					// xP++;
					// if(xP >= xS){
						// xP = 0;
						// yP++;
					// }
				// }
				// if(this->m_iterateSpace == 2){
					// xP++;
					// if(xP >= xS){
						// xP = 0;
						// yP++;
						// if(yP >= yS){
							// yP = 0;
							// zP++;
							// if(zP >= zS){
								// zP = 0;
							// }
						// }
					// }
				// }
				// if(this->m_iterateSpace == 3){
					// xP++;
					// if(xP >= xS){
						// xP = 0;
						// yP++;
						// if(yP >= yS){
							// yP = 0;
							// zP++;
							// if(zP >= zS){
								// zP = 0;
								// wP++;
								// if(wP >= wS){
									// wP = 0;
								// }
							// }
						// }
					// }
				// }
				// this->m_iterateSpace = -1;
				// return true;
			// }
			// xP++;
			// if(xP >= xS){
				// xP = 0;
				// yP++;
				// if(yP >= yS){
					// yP = 0;
					// zP++;
					// if(zP >= zS){
						// zP = 0;
						// wP++;
						// if(wP >= wS){
							// wP = 0;
						// }
					// }
				// }
			// }
			// if(this->iterateCount == xS){
				// this->m_space++;
				// this->xP = 0;
				// this->yP = 0;
				// this->zP = 0;
				// this->wP = 0;
			// }
			// if(this->iterateCount == xS + xS*yS){
				// this->m_space++;
				// this->xP = 0;
				// this->yP = 0;
				// this->zP = 0;
				// this->wP = 0;
			// }
			// if(this->iterateCount == xS + xS*yS + xS*yS*zS){
				// this->m_space++;
				// this->xP = 0;
				// this->yP = 0;
				// this->zP = 0;
				// this->wP = 0;
			// }
			// if(this->iterateCount == xS + xS*yS + xS*yS*zS + xS*yS*zS*wS){
				// this->m_space++;
				// this->xP = 0;
				// this->yP = 0;
				// this->zP = 0;
				// this->wP = 0;
			// }
			return true;
		}
		
		virtual cppObjectClass* getClass(){
			return Class<DataSetV4<T,xS,yS,zS,wS>>::classType;
		}
		
		virtual String toString(){
			return "DataSetV4 " + String(this->m_space) + " " + String(wP) + " "  + String(zP) + " "  + String(yP) + " "  + String(xP) + " = "  + String(getValue());
		}
		
		virtual DataSet<T>* clone(){
			DataSetV4<T,xS,yS,zS,wS> *nset = new DataSetV4<T,xS,yS,zS,wS>();
			nset->setArray(this->x1);
			nset->setArray(this->x2);
			nset->setArray(this->x3);
			nset->setArray(this->x4);
			return nset;
		}
		
	protected:
		int xP = 0;
		int yP = 0;
		int zP = 0;
		int wP = 0;
		int spaceLimit = 0;
		int fullSize = 0;
};

*/

#endif 
