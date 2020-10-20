
#ifndef ByteArray_h
#define ByteArray_h

#include "Math.h"
#include "Function.h"
#include "PrimitiveList.h"
#include "Printable.h"


class ByteArray : public PrimitiveList<byte> , public Printable{
public:
ByteArray(){}
ByteArray(const byte& b){
	this->add(b);
}
ByteArray(const byte b[]){
	for(int xx = 0; xx < sizeof(b)/sizeof(b[0]); xx++){
		this->add(xx);
	}
}
virtual ~ByteArray(){}
		
	
size_t printTo(Print& p) const{
	for(int x = 0; x < this->pos; x++){
		p.print(*this->values[x],BIN);
	}
}
		
virtual String getClassName(){
	return "ByteArray";
}

virtual String toString(){
	String array = "";
	for(int x =0; x < this->pos; x++){
		for(int y = 7; y >= 0; y--){
			array.concat(String(getBit(x,y)));
		}
		if(x < this->pos-1){
			array+='\n';
		}
	}
	return array;
}
void getBitSize(){
	return this->getSize() * 8;
}

void operator=(const byte& value){
	this->resetDelete();
	this->add(value);
}

void operator+=(const byte& value){
	this->add(value);
}

byte* add(){
	return this->addParameters(0);
}

byte* add(const byte& value){
	if(this->pos >= this->size){
		this->expandLocal(this->expandSize);
	}
	if(this->pos >= this->size){
		return nullptr;
	}
	if(this->values[this->pos] == nullptr){
		this->values[this->pos] = new byte();
	}
	*this->values[this->pos] = value;
	this->pos++;
	return this->values[this->pos-1];
}

void add(int size, const byte& value){
	for(int x = 0; x < size; x++){
		this->add(value);
	}
}

void adding(int size){
	for(int x = 0; x < size; x++){
		this->addParameters(0);
	}
}

void adding(int size, bool value){
	for(int x = 0; x < size; x++){
		byte* c = this->addParameters(0);
		for(int y = 0; y < 8; y++){
			bitWrite((*c), y, true);
		}
	}
}

void addBits(int size){
	int arraySize = (int)(size / 8);
	if(size % 8){
		arraySize++;
	}
	for(int x = 0; x < arraySize; x++){
		add();
	}
}

void addBits(int size, bool value){
	int counter = 0;
	int arraySize = (int)(size / 8);
	if(size % 8){
		arraySize++;
	}
	for(int x = 0; x < arraySize; x++){
		byte* c = add();
		for(int y = 0; y < 8; y++){
			if(counter < size){
				bitWrite((*c), y, value);
			}else{
				return;
			}
			counter++;
		}
	}
}

void setBit(int cell, int bit, bool value){
	byte* c = this->getByPos(cell);
	if(c == nullptr || bit >= 8){
		return;
	}
	bitWrite((*c), bit, value);
}

void clearAll(){
	for(int xi = 0; xi < this->pos; xi++){
		(*this->values[xi]) = 0;
	}
}

void clearBit(int cell, int bit){
	byte* c = this->getByPos(cell);
	if(c == nullptr){
		return;
	}
	bitWrite((*c), bit, false);
}

void toggleAll(){
	for(int xi = 0; xi < this->pos; xi++){
		for(int xo = 0; xo < 8; xo++){
			bitWrite((*this->values[xi]), xo, !bitRead((*this->values[xi]), xo));
		}
	}
}

void toggleByte(int cell){
	byte* c = this->getByPos(cell);
	if(c == nullptr){
		return;
	}
	for(int xx = 0; xx < 8; xx++){
		bitWrite((*c), xx, !bitRead((*c), xx));
	}
}

void toggleBit(int cell, int bit){
	byte* c = this->getByPos(cell);
	if(c == nullptr){
		return;
	}
	bitWrite((*c), bit, !bitRead((*c), bit));
}

bool getBit(int cell, int bit){
	byte* c = this->getByPos(cell);
	if(c == nullptr){
		return false;
	}
	return bitRead((*c), bit);
}
};

#endif