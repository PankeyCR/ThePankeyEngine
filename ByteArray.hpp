
#include "ame_Level.hpp"

#if defined(ame_untilLevel_1)

#ifndef ByteArray_hpp
#define ByteArray_hpp

//#include "Math.h"
#include "Function.hpp"
#include "PrimitiveList.hpp"
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
ByteArray(const String& i){
	// Serial.println(i);
	int linePosition = 0;
	int bytePosition = 0;
	if(i.length() > 0){
		this->add();
		if(i.length() < 8){
			// Serial.println("i.length() < 8");
			for(int x =0; x < i.length(); x++){
				char c = i.charAt(x);
				// Serial.println("char ");Serial.println(c);
				// Serial.println("position ");Serial.println(i.length() - 1 - bytePosition);
				// Serial.println("value ");Serial.println(BoolCharValue(c));
				this->setBit(0, i.length() - 1 - bytePosition, BoolCharValue(c));
				bytePosition++;
			}
		}
		if(i.length() == 8){
			// Serial.println("i.length() == 8");
			for(int x =0; x < i.length(); x++){
				char c = i.charAt(x);
				// Serial.println("char ");Serial.println(c);
				if(bytePosition >= 8){
					bytePosition = 0;
					linePosition++;
				}
				this->setBit(linePosition, 7 - bytePosition, BoolCharValue(c));
				bytePosition++;
			}
		}
		if(i.length() > 8){
			if((i.length() % 8) == 0){
				// Serial.println("(i.length() % 8) == 0");
				for(int x =0; x < i.length(); x++){
					char c = i.charAt(x);
					// Serial.println("char ");Serial.println(c);
					if(bytePosition >= 8){
						bytePosition = 0;
						linePosition++;
						this->add();
					}
					this->setBit(linePosition, 7 - bytePosition, BoolCharValue(c));
					bytePosition++;
				}
			}else{
				// Serial.println("else (i.length() % 8) == 0");
				int coef = i.length() / 8;
				int lst = i.length() - (coef * 8);
				for(int x =0; x < i.length(); x++){
					char c = i.charAt(x);
					// Serial.println("char ");Serial.println(c);
					if(bytePosition >= 8){
						bytePosition = 0;
						linePosition++;
						this->add();
					}
					if(linePosition < coef){
						this->setBit(linePosition, 7 - bytePosition, BoolCharValue(c));
					}else{
						this->setBit(linePosition, lst - 1 - bytePosition, BoolCharValue(c));
					}
					bytePosition++;
				}
			}
		}
	}
}
ByteArray(const int& i){
	this->addLValue(i);
}
ByteArray(const byte& b){
	this->addLValue(b);
}
ByteArray(const char* b){
	operator=(String(b));
}
ByteArray(byte b[]){
	for(int x = 0; x < sizeof(b)/sizeof(b[0]); x++){
		this->addLValue(b[x]);
	}
}
virtual ~ByteArray(){}
		
	
size_t printTo(Print& p) const{
	size_t t = 0;
	for(int x = 0; x < this->pos; x++){
		p.print(*this->values[x],BIN);
		t += sizeof(*this->values[x]);
	}
	return t;
}
		
virtual cppObjectClass* getClass(){
	return Class<ByteArray>::classType;
}

virtual String toString() const{
	String array = "";
	for(int x =0; x < this->pos; x++){
		for(int y = 7; y >= 0; y--){
			array.concat(String(getBit(x,y)));
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

virtual ByteArray& operator=(const ByteArray& i){
	for(int x =0; x < i.pos; x++){
		this->addLValue((byte)*i.values[x]);
	}
	return *this;
}

virtual ByteArray& operator=(const String& i){
	int linePosition = 0;
	int bytePosition = 0;
	if(i.length() > 0){
		this->add();
		if(i.length() < 8){
			for(int x =0; x < i.length(); x++){
				char c = i.charAt(x);
				this->setBit(0, i.length() - 1 - bytePosition, BoolCharValue(c));
				bytePosition++;
			}
		}
		if(i.length() == 8){
			for(int x =0; x < i.length(); x++){
				char c = i.charAt(x);
				if(bytePosition >= 8){
					bytePosition = 0;
					linePosition++;
				}
				this->setBit(linePosition, 7 - bytePosition, BoolCharValue(c));
				bytePosition++;
			}
		}
		if(i.length() > 8){
			if((i.length() % 8) == 0){
				for(int x =0; x < i.length(); x++){
					char c = i.charAt(x);
					if(bytePosition >= 8){
						bytePosition = 0;
						linePosition++;
						this->add();
					}
					this->setBit(linePosition, 7 - bytePosition, BoolCharValue(c));
					bytePosition++;
				}
			}else{
				int coef = i.length() / 8;
				int lst = i.length() - (coef * 8);
				for(int x =0; x < i.length(); x++){
					char c = i.charAt(x);
					if(bytePosition >= 8){
						bytePosition = 0;
						linePosition++;
						this->add();
					}
					if(linePosition < coef){
						this->setBit(linePosition, 7 - bytePosition, BoolCharValue(c));
					}else{
						this->setBit(linePosition, lst - 1 - bytePosition, BoolCharValue(c));
					}
					bytePosition++;
				}
			}
		}
	}
	return *this;
}

virtual ByteArray& operator=(const int& i){
	this->addLValue(i);
	return *this;
}

virtual ByteArray& operator=(const char& i){
	operator=(String(i));
	return *this;
}

virtual ByteArray& operator=(byte value){
	this->resetDelete();
	this->addLValue(value);
	return *this;
}

virtual bool operator==(const ByteArray& b){
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

virtual bool operator==(const String& b){
	return operator==(ByteArray(b));
}

virtual bool operator==(const byte& b){
	if(1 < this->getPosition() || this->getPosition() == 0){
		return false;
	}
	byte c = this->getByte(0);
	if(c == b){
		return true;
	}
	return false;
}

virtual bool operator==(const char* b){
	return operator==(ByteArray(b));
}

virtual bool operator!=(const ByteArray& b){
	if(b.getPosition() == this->getPosition()){
		return true;
	}
	for(int x = 0; x < this->getPosition(); x++){
		if(*b.getByPosition(x) == *this->getByPosition(x)){
			return false;
		}
	}
	return true;
}

virtual bool operator!=(const String& b){
	return operator!=(ByteArray(b));
}

virtual bool operator!=(const byte& b){
	if(1 < this->getPosition()){
		return false;
	}
	byte c = this->getByte(0);
	if(c != b){
		return true;
	}
	return false;
}

virtual bool operator!=(const char* b){
	return operator!=(ByteArray(b));
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

virtual char* getCharPointer(int x) const {
	if(x >= this->pos){
		return nullptr;
	}
	return (char*)this->values[x];
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

bool BoolCharValue(char x){
	if(x == '1'){
		return true;
	}
	if(x == '0'){
		return false;
	}
	return false;
}

};

}

#endif

#endif
