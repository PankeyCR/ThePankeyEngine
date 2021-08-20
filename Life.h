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

namespace ame{

class Life : public GameObject{
public:
Life(){
	sizeList = new PrimitiveList<int>();
	nextStep = new PrimitiveMap<int,bool>();
	cells = new ByteArray();
}
Life(int dimentions){
	sizeList = new PrimitiveList<int>();
	nextStep = new PrimitiveMap<int,bool>();
	cells = new ByteArray();
}
~Life(){
	delete sizeList;
	delete nextStep;
	delete cells;
}

virtual void update(float tpf){
	for(int x = 0; x < nextStep.getPosition(); x++){
		setRawCell(*nextStep.getByPosition(x), *nextStep.getKeyByPosition(x));
	}
	nextStep.resetDelete();
}

template<class... args>
void setGrid(args... x){
	size.resetDelete();
	size.addPack<args...>(x...);
	int total = 1;
	for(int x=0; x < size.getPosition(); x++){
		total *= (*size.getByPosition(x));
	}
	for(int xx =0; xx < total; xx++){
		addCell();
	}
}

template<class... args>
void setCell(bool state, args... x){
	PrimitiveList<int> in;
	in.addPack<args...>(x...);
	if(dimention != in.getPosition() && dimention != size.getPosition() && dimention != 0){
		return;
	}
	int rawPosition = -1;
	for(int x = 0; x < dimention; x++){
		int Size = *size.getByPosition(x);
		int position = *in.getByPosition(x);
		
	}
	if(rawPosition != -1){
		cells->setBit(rawPosition,0,state);
	}
	for(int x = 0; x < spaceConsumed; x++){
		
	}
}
void setRawCell(bool state, int rawPosition){
	cells->setBit(rawPosition,0,state);
	int p = 1;
	for(int x = 0; x < dimention; x++){
		int Size = size.getByPosition(x);
		
		p+=2;
	}
}

virtual void addCell(void){
	float size = spaceConsumed/8.0f;
	if(spaceConsumed % 8){
		size++;
	}
	for(int xx=0; xx < size; xx++){
		cells->add();
	}
}

virtual int getCellPosition(int cell){
	float size = spaceConsumed/8.0f;
	if(spaceConsumed % 8){
		size++;
	}
	return size * cell;
}

protected:
PrimitiveList<ByteLogic>* singleLogic = nullptr;
PrimitiveList<ByteArrayLogic>* complexLogic = nullptr;
ByteArray* cells = nullptr;
};

}

#endif