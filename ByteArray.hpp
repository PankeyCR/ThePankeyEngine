
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ByteArray)
	#define ByteArray_hpp
	
	#ifdef ame_Windows
		typedef std::bitset<8>* ByteArray;
	#endif

	#ifdef ame_ArduinoIDE
		typedef byte* ByteArray;
	#endif
#endif

#ifndef ByteArray_hpp
#define ByteArray_hpp
#define ByteArray_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
    #include <bitset>
	#include "ame_Printable.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "Memory.hpp"

#include "cppObjectClass.hpp"
#include "Class.hpp"

#include "PrimitiveList.hpp"

#include "ame_Byte.hpp"
#include "ByteArrayIterator.hpp"

#ifdef ByteArray_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define ByteArrayLog(location,method,type,mns) ame_Log(this,location,"ByteArray",method,type,mns)
	#define const_ByteArrayLog(location,method,type,mns) 
	#define StaticByteArrayLog(pointer,location,method,type,mns) ame_Log(pointer,location,"ByteArray",method,type,mns)
#else
	#ifdef ByteArray_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define ByteArrayLog(location,method,type,mns) ame_LogDebug(this,location,"ByteArray",method,type)
		#define const_ByteArrayLog(location,method,type,mns) 
		#define StaticByteArrayLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"ByteArray",method,type)
	#else
		#define ByteArrayLog(location,method,type,mns) 
		#define const_ByteArrayLog(location,method,type,mns) 
		#define StaticByteArrayLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class ByteArray : public Printable{
	protected:
		ame_Byte* m_byte_array = nullptr;
		int m_pos = 0;
		int m_size = 0;

	public:
		ByteArray(){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			ByteArrayLog(ame_Log_Statement, "Constructor", "println", "Default Constructor");
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		ByteArray(const ByteArray& source){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			int n_size = source.getPosition();
			if(n_size > 0){
				m_pos = n_size;
				m_size = getAvailableSize(m_pos);
				m_byte_array = create(m_size);
				copy(m_byte_array, source.m_byte_array, m_pos);
			}
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		ByteArray(ame_Byte* a_value, int a_size){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			if(a_value != nullptr){
				if(a_size > 0){
					m_pos = a_size;
					m_size = getAvailableSize(m_pos);
					m_byte_array = create(m_size);
					copy(m_byte_array, a_value, m_pos);
				}
			}
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
/*
		ByteArray(const Note& i){
			//// Serial.println(i);
			int linePosition = 0;
			int bytePosition = 0;
			if(i.length() > 0){
				this->add();
				if(i.length() < 8){
					//// Serial.println("i.length() < 8");
					for(int x =0; x < i.length(); x++){
						char c = i.charAt(x);
						//// Serial.println("char ");Serial.println(c);
						////Serial.println("position ");Serial.println(i.length() - 1 - bytePosition);
						//// Serial.println("value ");Serial.println(BoolCharValue(c));
						this->setBit(0, i.length() - 1 - bytePosition, BoolCharValue(c));
						bytePosition++;
					}
				}
				if(i.length() == 8){
					//// Serial.println("i.length() == 8");
					for(int x =0; x < i.length(); x++){
						char c = i.charAt(x);
						//// Serial.println("char ");Serial.println(c);
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
						//// Serial.println("(i.length() % 8) == 0");
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
						//// Serial.println("else (i.length() % 8) == 0");
						int coef = i.length() / 8;
						int lst = i.length() - (coef * 8);
						for(int x =0; x < i.length(); x++){
							char c = i.charAt(x);
							//// Serial.println("char ");Serial.println(c);
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
		*/

		ByteArray(ByteArray&& source){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			int n_size = source.getPosition();
			if(n_size > 0){
				m_pos = source.m_pos;
				m_size = source.m_size;
				m_byte_array = source.m_byte_array;
				source.m_pos = 0;
				source.m_size = 0;
				source.m_byte_array = nullptr;
			}
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		ByteArray(const ame_Byte& a_value){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			m_pos = 1;
			m_size = getAvailableSize(m_pos);

			m_byte_array = create(m_size);
			m_byte_array[0] = a_value;
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		virtual ~ByteArray(){
			ByteArrayLog(ame_Log_StartMethod, "Destructor", "println", "");
			ByteArrayLog(ame_Log_Statement, "Destructor", "println", m_pos);
			ByteArrayLog(ame_Log_Statement, "Destructor", "println", m_size);
			if(m_string == nullptr){
				ByteArrayLog(ame_Log_Statement, "Destructor", "println", "m_string == nullptr");
			}else{
				ByteArrayLog(ame_Log_Statement, "Destructor", "println", m_string);
				fix(m_byte_array, m_pos, m_size);
				erase(m_byte_array);
			}
			ByteArrayLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		size_t printTo(Print& p) const{
			ByteArrayLog(ame_Log_StartMethod, "printTo", "println", "");
			if(m_byte_array == nullptr){
				return 0;
			}
			size_t s_t = 0;
			for(int x = 0; x < m_pos; x++){
				s_t += p.print(m_byte_array[x], BIN);
			}
			ByteArrayLog(ame_Log_EndMethod, "printTo", "println", "");
			return s_t;
		}

		virtual cppObjectClass* getClass(){
			return Class<ByteArray>::classType;
		}
		
		virtual ame_Byte* pointer() const{
			return m_byte_array;
		}

		int getPosition() const{
			return m_pos;
		}

		int getSize() const{
			return m_size;
		}

		virtual bool isEmpty() const{
			return m_pos == 0 || m_byte_array == nullptr;
		}

		virtual char byteAt(int x) const{
			if(m_byte_array == nullptr){
				return 0;
			}
			if(x >= m_pos){
				return 0;
			}
			return m_byte_array[x];
		}
		virtual int getBitSize() const {
			return this->m_pos * 8;
		}
		virtual int getByteSize() const {
			return this->m_pos;
		}

		virtual ByteArrayIterator begin(){
			ByteArrayLog(ame_Log_StartMethod, "begin", "println", "");
			ByteArrayLog(ame_Log_EndMethod, "begin", "println", "");
			return ByteArrayIterator(m_byte_array,0);
		}
		virtual ByteArrayIterator end(){
			ByteArrayLog(ame_Log_StartMethod, "end", "println", "");
			ByteArrayLog(ame_Log_EndMethod, "end", "println", "");
			return ByteArrayIterator(m_byte_array, m_pos);
		}

		virtual ByteArray add(const ame_Byte* a_value){
			NoteLog(ame_Log_StartMethod, "add", "println", "");
			int v_size = length(a_value);
			if(v_size <= 0){
				ByteArrayLog(ame_Log_Statement, "add", "println", "v_size <= 0");
				return ByteArray(m_byte_array);
			}
			
			if(m_byte_array == nullptr){
				ByteArrayLog(ame_Log_Statement, "add", "println", "m_string == nullptr");
				return ByteArray(a_value);
			}
			
			ByteArray temp;
			temp.m_pos = m_pos + v_size;
			temp.m_size = getAvailableSize(temp.m_pos);
			temp.m_byte_array = create(temp.m_size);

			copy(temp.m_byte_array, m_byte_array);
			concat(temp.m_byte_array, a_value);
			
			NoteLog(ame_Log_Statement, "add", "println", m_pos);
			NoteLog(ame_Log_Statement, "add", "println", m_size);
			NoteLog(ame_Log_Statement, "add", "println", m_string);
			
			NoteLog(ame_Log_EndMethod, "add", "println", "");

			return temp;
		}
		
		virtual ByteArray& operator=(const ByteArray& source){
			ByteArrayLog(ame_Log_StartMethod, "operator=", "println", "");
			int n_size = source.getPosition();
			if(n_size > 0){
				m_pos = n_size;
				m_size = getAvailableSize(m_pos);
				m_byte_array = create(m_size);
				copy(m_byte_array, source.m_byte_array, m_pos);
			}
			ByteArrayLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}

		virtual ByteArray& operator=(const ame_Byte& a_value){
			ByteArrayLog(ame_Log_StartMethod, "operator=", "println", "");
			m_pos = 1;
			m_size = getAvailableSize(m_pos);

			m_byte_array = create(m_size);
			m_byte_array[0] = a_value;
			ByteArrayLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}

		virtual bool operator==(const ByteArray& source){
			if(source.getPosition() != this->getPosition()){
				return false;
			}
			for(int x = 0; x < this->getPosition(); x++){
				if(source.m_byte_array[x] != m_byte_array[x]){
					return false;
				}
			}
			return true;
		}

		virtual bool operator==(const ame_Byte& source){
			if(this->getPosition() != 1){
				return false;
			}
			ame_Byte c = m_byte_array[0];
			return c == source;
		}

		virtual bool operator!=(const ByteArray& source){
			if(source.getPosition() != this->getPosition()){
				return true;
			}
			for(int x = 0; x < this->getPosition(); x++){
				if(source.m_byte_array[x] != m_byte_array[x]){
					return true;
				}
			}
			return false;
		}

		virtual bool operator!=(const ame_Byte& source){
			if(this->getPosition() != 1){
				return true;
			}
			ame_Byte c = m_byte_array[0];
			return c != source;
		}

		virtual ByteArray operator+(const ame_Byte& value){
			ByteArrayLog(ame_Log_StartMethod, "operator=", "println", "");
			ByteArray array = *this;
			array.add(value);
			ByteArrayLog(ame_Log_EndMethod, "operator=", "println", "");
			return array;
		}

		virtual ByteArray operator+=(const ame_Byte& a_value){
			ByteArrayLog(ame_Log_StartMethod, "operator+=", "println", "");
			if(m_byte_array == nullptr){
				m_pos = 1;
				m_size = getAvailableSize(m_pos);

				m_byte_array = create(m_size);
				m_byte_array[0] = a_value;
				return *this;
			}
			if(m_pos >= m_size){
			}
			if(m_pos >= m_size){
				return *this;
			}
			m_byte_array[m_pos] = a_value;
			m_pos++;
			ByteArrayLog(ame_Log_EndMethod, "operator+=", "println", "");
			return *this;
		}

		virtual ame_Byte& add(){
			ByteArrayLog(ame_Log_StartMethod, "add", "println", "");
			if(this->m_byte_array == nullptr){
				m_pos = 1;
				m_size = getAvailableSize(m_pos);

				m_byte_array = create(m_size);
				m_byte_array[0] = 0b00000000;
				return *this;
			}
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return nullptr;
			}
			this->m_byte_array[this->pos] = 0b00000000;
			this->pos++;
			ByteArrayLog(ame_Log_EndMethod, "add", "println", "");
			return this->m_byte_array[this->pos-1];
		}

		virtual ame_Byte& add(ame_Byte value){
			ByteArrayLog(ame_Log_StartMethod, "add", "println", "");
			if(this->m_byte_array == nullptr){
				m_pos = 1;
				m_size = getAvailableSize(m_pos);

				m_byte_array = create(m_size);
				m_byte_array[0] = value;
				return *this;
			}
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return nullptr;
			}
			this->m_byte_array[this->pos] = value;
			this->pos++;
			ByteArrayLog(ame_Log_EndMethod, "add", "println", "");
			return this->m_byte_array[this->pos-1];
		}

		virtual ByteArray add(int size, byte value){
			ByteArrayLog(ame_Log_StartMethod, "add", "println", "");
			if(this->m_byte_array == nullptr){
				m_pos = size;
				m_size = getAvailableSize(m_pos);

				m_byte_array = create(m_size);
				for(int x = 0; x < size; x++){
					m_byte_array[x] = value;
				}
				return *this;
			}
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return *this;
			}
			for(int x = 0; x < size; x++){
				m_byte_array[x] = value;
				this->pos++;
			}
			ByteArrayLog(ame_Log_EndMethod, "add", "println", "");
			return *this;
		}

		virtual void adding(int size){
			ByteArrayLog(ame_Log_StartMethod, "adding", "println", "");
			for(int x = 0; x < size; x++){
				this->addParameters(0);
			}
			ByteArrayLog(ame_Log_EndMethod, "adding", "println", "");
		}

		virtual void adding(int size, bool value){
			ByteArrayLog(ame_Log_StartMethod, "adding", "println", "");
			for(int x = 0; x < size; x++){
				byte* c = this->addParameters(0);
				for(int y = 0; y < 8; y++){
					bitWrite((*c), y, value);
				}
			}
			ByteArrayLog(ame_Log_EndMethod, "adding", "println", "");
		}

		virtual void addBits(int size){
			ByteArrayLog(ame_Log_StartMethod, "addBits", "println", "");
			int arraySize = (int)(size / 8);
			if(size % 8){
				arraySize++;
			}
			for(int x = 0; x < arraySize; x++){
				add();
			}
			ByteArrayLog(ame_Log_EndMethod, "addBits", "println", "");
		}

		virtual void addBits(int size, bool value){
			ByteArrayLog(ame_Log_StartMethod, "addBits", "println", "");
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
			ByteArrayLog(ame_Log_EndMethod, "addBits", "println", "");
		}

		virtual void setBit(int cell, int bit, bool value){
			ByteArrayLog(ame_Log_StartMethod, "setBit", "println", "");
			byte* c = this->getByPosition(cell);
			if(c == nullptr || bit >= 8){
				return;
			}
			bitWrite((*c), bit, value);
			ByteArrayLog(ame_Log_EndMethod, "setBit", "println", "");
		}

		virtual void clearAll(){
			ByteArrayLog(ame_Log_StartMethod, "clearAll", "println", "");
			for(int xi = 0; xi < this->pos; xi++){
				(*this->values[xi]) = 0;
			}
			ByteArrayLog(ame_Log_EndMethod, "clearAll", "println", "");
		}

		virtual void clearBit(int cell, int bit){
			ByteArrayLog(ame_Log_StartMethod, "clearBit", "println", "");
			byte* c = this->getByPosition(cell);
			if(c == nullptr){
				return;
			}
			bitWrite((*c), bit, false);
			ByteArrayLog(ame_Log_EndMethod, "clearBit", "println", "");
		}

		virtual void toggleAll(){
			ByteArrayLog(ame_Log_StartMethod, "toggleAll", "println", "");
			for(int xi = 0; xi < this->pos; xi++){
				for(int xo = 0; xo < 8; xo++){
					bitWrite((*this->values[xi]), xo, !bitRead((*this->values[xi]), xo));
				}
			}
			ByteArrayLog(ame_Log_EndMethod, "toggleAll", "println", "");
		}

		virtual void toggleByte(int cell){
			ByteArrayLog(ame_Log_StartMethod, "toggleByte", "println", "");
			byte* c = this->getByPosition(cell);
			if(c == nullptr){
				return;
			}
			for(int xx = 0; xx < 8; xx++){
				bitWrite((*c), xx, !bitRead((*c), xx));
			}
			ByteArrayLog(ame_Log_EndMethod, "toggleByte", "println", "");
		}

		virtual void toggleBit(int cell, int bit){
			ByteArrayLog(ame_Log_StartMethod, "toggleBit", "println", "");
			byte* c = this->getByPosition(cell);
			if(c == nullptr){
				return;
			}
			bitWrite((*c), bit, !bitRead((*c), bit));
			ByteArrayLog(ame_Log_EndMethod, "toggleBit", "println", "");
		}

		virtual bool getBit(int cell, int bit) const {
			ByteArrayLog(ame_Log_StartMethod, "getBit", "println", "");
			byte* c = this->values[cell];
			if(c == nullptr){
				return false;
			}
			ByteArrayLog(ame_Log_EndMethod, "getBit", "println", "");
			return bitRead((*c), bit);
		}

		virtual ame_Byte getByte(int x) const {
			ByteArrayLog(ame_Log_StartMethod, "getByte", "println", "");
			if(x >= this->pos){
				return ame_Byte_Null;
			}
			ByteArrayLog(ame_Log_EndMethod, "getByte", "println", "");
			return this->m_byte_array[x];
		}

		virtual ByteArray getByteArray(int start, int end) const {
			ByteArrayLog(ame_Log_StartMethod, "getByteArray", "println", "");
			ByteArray array;
			if(start >= this->pos || end >= this->pos){
				return 0;
			}
			for(int x = start; x <= end; x++){
				array.addLValue(*this->values[x]);
			}
			ByteArrayLog(ame_Log_EndMethod, "getByteArray", "println", "");
			return array;
		}
		
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

		static ame_Byte* create(int ci_size){
			ByteArrayLog(ame_Log_StartMethod, "operator=", "println", "");
			ByteArrayLog(ame_Log_EndMethod, "operator=", "println", "");
			#if defined(Memory_AVAILABLE)
			if(Memory::manager != nullptr){
				// return Memory::manager->create(0, sizeof(char) * 20 *100);
			}
			#endif
			return new ame_Byte[ci_size];
		}

		static void erase(ame_Byte* chr){
			#if defined(Memory_AVAILABLE)
			// if(Memory::manager != nullptr){
				// Memory::manager->erase(chr, sizeof(ame_Byte)*m_pos);
				// return;
			// }
			#endif
			delete[] chr;
		}

		static int getAvailableSize(int input_Size){
			if(input_Size == 0){
				return 5;
			}
			if(input_Size < 10){
				return 10;
			}
			if(input_Size < 20){
				return 20;
			}
			if(input_Size < 30){
				return 30;
			}
			if(input_Size < 40){
				return 40;
			}
			if(input_Size < 200){
				return 200;
			}
			if(input_Size < 1000){
				return 1000;
			}
			if(input_Size < 2000){
				return 2000;
			}
			return 5;
		}

		static void replace(ame_Byte* a_byte, ame_Byte a_search, ame_Byte a_replace){

		}

		static void copy(ame_Byte* a_byte_1, ame_Byte* a_byte_2, int a_size){

		}

		static void replace(ame_Byte* a_Byte, int a_size, const ame_Byte& a_search, const ame_Byte& a_change){
			for(int x = 0; x < a_size; x++){
				if(a_Byte[x] == a_search){
					a_Byte[x] = a_change;
				}
			}
		}

};

}

#endif
