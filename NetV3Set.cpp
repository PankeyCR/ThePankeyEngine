/*

#ifndef NetV3Set_cpp
#define NetV3Set_cpp

#include "NetV3Set.h"

	template<>
	NetV3Set<1,2,1>::NetV3Set(){
		
	}
		
	template<>
	NetV3Set<1,2,3>::~NetV3Set(){
		
	}
	
	template<>
	DataSet<float>* NetV3Set<1,2,3>::set(float t){
		if(this->dimentionMap = 0){
			this->x1[xP] = t;
		}
		if(this->dimentionMap = 1){
			this->x2[xP][yP] = t;
		}
		if(this->dimentionMap = 2){
			this->x3[xP][yP][zP] = t;
		}
		
		return this;
	}
	
	template<>
	DataSet<float>* NetSet::remove(){
		
		return this;
	}
	
	template<>
	float NetSet::getValue(){
		
	}
	
	float *NetSet::getPointer(){
		
	}
	
	/*
		
	template<>
	void NetV3Set<1,2,3>::set1D(int x, float value){
		this->x1[x] = value;
	}
		
	template<>
	void NetV3Set<1,2,3>::set2D(int x, int y, float value){
		this->x2[x][y] = value;
	}
		
	template<>
	void NetV3Set<1,2,3>::set3D(int x, int y, int z, float value){
		this->x3[x][y][z] = value;
	}
		
	template<>
	float NetV3Set<1,2,3>::get1D(int x){
		return this->x1[x];
	}
		
	template<>
	float NetV3Set<1,2,3>::get2D(int x, int y){
		return this->x2[x][y];
	}
		
	template<>
	float NetV3Set<1,2,3>::get3D(int x, int y, int z){
		return this->x3[x][y][z];
	}
		
	template<>
	int NetV3Set<1,2,3>::getIterationSize(){
		return 1*2*3 + 1*2 + 1;
	}
		
	template<>
	int NetV3Set<1,2,3>::getDimention(){
		if(this->iterationSize() < 1){
			return 1;
		}
		if(this->iterationSize() >= 1 && this->iterationSize() < 1*2 + 1){
			return 2;
		}
		if(this->iterationSize() >= 1*2 + 1 && this->iterationSize() < 1*2*3 + 1*2 + 1){
			return 3;
		}
		return 0;
	}
		
	template<>
	bool NetV3Set<1,2,3>::hasVector(int vector){
		if(this->iterationSize() < 1){
			if(vector == 1){
				return true;
			}
			if(vector == 2){
				return false;
			}
			if(vector == 3){
				return false;
			}
		}
		if(this->iterationSize() >= 1 && this->iterationSize() < 1*2 + 1){
			if(vector == 1){
				return true;
			}
			if(vector == 2){
				return true;
			}
			if(vector == 3){
				return false;
			}
		}
		if(this->iterationSize() >= 1*2 + 1 && this->iterationSize() < 1*2*3 + 1*2 + 1){
			if(vector == 1){
				return true;
			}
			if(vector == 2){
				return true;
			}
			if(vector == 3){
				return true;
			}
		}
		return false;
	}
		
	template<>
	int NetV3Set<1,2,3>::getVector(int vector){
		if(this->iterationSize() < 1){
			if(vector == 1){
				return 0;
			}
			if(vector == 2){
				return 0;
			}
			if(vector == 3){
				return 0;
			}
		}
		float iter = this->iterationSize() - 1;
		float start = 1;
		float end =  1*2 + 1;
		float sizeD = 1*2;
		if(this->iterationSize() >= 1 && this->iterationSize() < 1*2 + 1){
			if(this->iterationSize()-start >= 0 && this->iterationSize()-start < 1){
				if(vector == 1){
					return 0;
				}
				if(vector == 2){
					return 0;
				}
				if(vector == 3){
					return 0;
				}
			}
			if(vector == 2){
				return 0;
			}
			if(vector == 3){
				return 0;
			}
		}
		if(this->iterationSize() >= 1*2 + 1 && this->iterationSize() < 1*2*3 + 1*2 + 1){
			return 3;
		}
		return 0;
	}
		
	template<>
	float NetV3Set<1,2,3>::getValue(){
		return 0;
	}
		

#endif 
*/