//Life owns it lelf, life deletes it lelf, but it can be deleted by others


#ifndef Life_h
#define Life_h

#include "Function.h"
#include "GameObject.h"
#include "ByteArray.h"
#include "PrimitiveList.h"
#include "PrimitiveMap.h"
#include "GridIncrementor.h"
#include "Order.h"


class Life : public GameObject{
public:
Life(){
	spaceConsumed = 15;
	dimention = 7;
}
Life(int dimentions){
	dimention = dimentions;
	spaceConsumed = (dimention*2)+1;
}
~Life(){}

virtual void update(float tpf){
	iterateV(nextStep){
		setRawCell(nextStep.getValue(), nextStep.getKey());
	}
	nextStep.resetDelete();
}

template<class... args>
void setGrid(args... x){
	size.resetDelete();
	size.addPack<args...>(x...);
	int total = 1;
	iterateV(size){
		total*=size.getValue();
	}
	for(int xx =0; xx < total; xx++){
		addCell();
	}
}

template<class... args>
void setCell(bool state, args... x){
	PrimitiveList<int> in;
	in.addPack<args...>(x...);
	if(dimention != in.getPos() && dimention != size.getPos() && dimention != 0){
		return;
	}
	int rawPosition = -1;
	for(int x = 0; x < dimention; x++){
		int Size = size.getByPos(x);
		int position = in.getByPos(x);
		
	}
	if(rawPosition != -1){
		cells.setBit(rawPosition,0,state);
	}
	for(int x = 0; x < spaceConsumed; x++){
		
	}
}
void setRawCell(bool state, int rawPosition){
	cells.setBit(rawPosition,0,state);
	int p = 1;
	for(int x = 0; x < dimention; x++){
		int Size = size.getByPos(x);
		
		p+=2;
	}
}

virtual void addCell(){
	float size = spaceConsumed/8.0f;
	if(spaceConsumed % 8){
		size++;
	}
	for(int xx=0; xx < size; xx++){
		cells.add();
	}
}

virtual int getCellPosition(int cell){
	float size = spaceConsumed/8.0f;
	if(spaceConsumed % 8){
		size++;
	}
	return size*cell;
}

virtual int getCellSize(){
	float size = spaceConsumed/8.0f;
	if(spaceConsumed % 8){
		size++;
	}
	return cells.getPos()/size;
}

protected:
int spaceConsumed;
int dimention;
PrimitiveList<int> size;
PrimitiveMap<int,bool> nextStep;
ByteArray cells;
};

#endif