
#ifndef ByteArray_h
#define ByteArray_h

#include "Math.h"
#include "Function.h"
#include "PrimitiveList.h"
#include "Printable.h"

namespace ame{

class ByteArray : public PrimitiveList<byte> , public Printable{
public:
ByteArray(){}
ByteArray(const ByteArray& i){
	for(int x =0; x < i.pos; x++){
		this->addLValue((byte)*i.values[x]);
	}
}
ByteArray(const int i){
	this->addLValue(i);
}
ByteArray(byte b){
	this->addLValue(b);
}
ByteArray(byte b[]){
	for(int x = 0; x < sizeof(b)/sizeof(b[0]); x++){
		this->addLValue(b[x]);
	}
}
virtual ~ByteArray(){}
		
	
size_t printTo(Print& p) const{
	for(int x = 0; x < this->pos; x++){
		p.print(*this->values[x],BIN);
	}
}
		
virtual cppObjectClass* getClass(){
	return Class<ByteArray>::classType;
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
virtual int getBitSize() const {
	return this->pos * 8;
}
virtual int getByteSize() const {
	return this->pos;
}

virtual void operator=(const ByteArray& i){
	for(int x =0; x < i.pos; x++){
		this->addLValue((byte)*i.values[x]);
	}
}

virtual void operator=(const int i){
	this->addLValue(i);
}

virtual void operator=(byte value){
	this->resetDelete();
	this->addLValue(value);
}

virtual bool operator==(ByteArray b){
	if(b.getPosition() != this->getPosition()){
		return false;
	}
	for(int x = 0; x < this->getPosition(); x++){
		if(*b.getByPosition(x) != *this->getByPosition(x)){
			return false;
		}
	}
	return true;
}

virtual bool operator!=(ByteArray b){
	if(b.getPosition() != this->getPosition()){
		return true;
	}
	for(int x = 0; x < this->getPosition(); x++){
		if(*b.getByPosition(x) != *this->getByPosition(x)){
			return true;
		}
	}
	return false;
}

virtual void operator+=(byte value){
	this->addLValue(value);
}

virtual byte* add(){
	return this->addParameters(0);
}

virtual byte* add(byte value){
	return this->addLValue(value);
}

virtual void add(int size, byte value){
	for(int x = 0; x < size; x++){
		this->addLValue(value);
	}
}

virtual void adding(int size){
	for(int x = 0; x < size; x++){
		this->addParameters(0);
	}
}

virtual void adding(int size, bool value){
	for(int x = 0; x < size; x++){
		byte* c = this->addParameters(0);
		for(int y = 0; y < 8; y++){
			bitWrite((*c), y, value);
		}
	}
}

virtual void addBits(int size){
	int arraySize = (int)(size / 8);
	if(size % 8){
		arraySize++;
	}
	for(int x = 0; x < arraySize; x++){
		add();
	}
}

virtual void addBits(int size, bool value){
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

virtual void setBit(int cell, int bit, bool value){
	byte* c = this->getByPosition(cell);
	if(c == nullptr || bit >= 8){
		return;
	}
	bitWrite((*c), bit, value);
}

virtual void clearAll(){
	for(int xi = 0; xi < this->pos; xi++){
		(*this->values[xi]) = 0;
	}
}

virtual void clearBit(int cell, int bit){
	byte* c = this->getByPosition(cell);
	if(c == nullptr){
		return;
	}
	bitWrite((*c), bit, false);
}

virtual void toggleAll(){
	for(int xi = 0; xi < this->pos; xi++){
		for(int xo = 0; xo < 8; xo++){
			bitWrite((*this->values[xi]), xo, !bitRead((*this->values[xi]), xo));
		}
	}
}

virtual void toggleByte(int cell){
	byte* c = this->getByPosition(cell);
	if(c == nullptr){
		return;
	}
	for(int xx = 0; xx < 8; xx++){
		bitWrite((*c), xx, !bitRead((*c), xx));
	}
}

virtual void toggleBit(int cell, int bit){
	byte* c = this->getByPosition(cell);
	if(c == nullptr){
		return;
	}
	bitWrite((*c), bit, !bitRead((*c), bit));
}

virtual bool getBit(int cell, int bit) const {
	byte* c = this->values[cell];
	if(c == nullptr){
		return false;
	}
	return bitRead((*c), bit);
}

virtual byte getByte(int x) const {
	if(x >= this->pos){
		return 0;
	}
	return (byte)*this->values[x];
}

virtual ByteArray getByteArray(int start, int end) const {
	ByteArray array;
	if(start >= this->pos || end >= this->pos){
		return 0;
	}
	for(int x = start; x <= end; x++){
		array.addLValue(*this->values[x]);
	}
	return array;
}

};

}

#endif