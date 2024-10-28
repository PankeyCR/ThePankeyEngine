
#ifndef ByteArray_hpp
	#define ByteArray_hpp

	#if pankey_Enviroment == pankey_Windows_Enviroment
		#include "pankey_Printable.hpp"
		#include "pankey_Print.hpp"
	#endif

	#if pankey_IDE == pankey_Arduino_IDE
		#include "Arduino.h"
		#include "Printable.h"
		#include "IPAddress.h"
	#endif

	#include "Array.hpp"

	#include "pankey_Byte.hpp"

	#ifdef ByteArray_LogApp
		#include "pankey_Logger.hpp"
		#define ByteArrayLog(location,method,type,mns) pankey_Log((void*)this,location,"ByteArray",method,type,mns)
	#else
		#define ByteArrayLog(location,method,type,mns) 
	#endif

	namespace pankey{

		class ByteArray : public Array<pankey_Byte>, public Printable{
			public:
				ByteArray(){
					ByteArrayLog(pankey_Log_StartMethod, "Constructor", "println", "");
					ByteArrayLog(pankey_Log_Statement, "Constructor", "println", "Default Constructor");
					ByteArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(const Array<pankey_Byte>& c_array){
					ByteArrayLog(pankey_Log_StartMethod, "Constructor", "println", "");
					int i_array_length = c_array.getPosition();
					if(i_array_length > 0){
						this->createArray(i_array_length);
						this->copyPointer(c_array.pointer(), i_array_length);
						this->copyEndValue();
					}
					ByteArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(const ByteArray& c_array){
					ByteArrayLog(pankey_Log_StartMethod, "Constructor", "println", "");
					int i_array_length = c_array.getPosition();
					if(i_array_length > 0){
						this->createArray(i_array_length);
						this->copyPointer(c_array.pointer(), i_array_length);
						this->copyEndValue();
					}
					ByteArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(pankey_Byte* a_pointer, int a_array_length){
					ByteArrayLog(pankey_Log_StartMethod, "Constructor", "println", "");
					if(a_pointer != nullptr){
						if(a_array_length > 0){
							this->createArray(a_array_length);
							this->copyPointer(a_pointer, a_array_length);
							this->copyEndValue();
						}
					}
					ByteArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(ByteArray&& c_array){
					ByteArrayLog(pankey_Log_StartMethod, "Constructor", "println", "");
					int n_size = c_array.getPosition();
					if(n_size > 0){
						this->m_pos = c_array.m_pos;
						this->m_size = c_array.m_size;
						this->m_t_value = c_array.m_t_value;
						c_array.m_t_value = nullptr;
						c_array.m_pos = 0;
						c_array.m_size = 0;
					}
					ByteArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(const pankey_Byte& a_value){
					ByteArrayLog(pankey_Log_StartMethod, "Constructor", "println", "");
					this->createArray(1);
					this->copyValue(a_value);
					this->copyEndValue();
					ByteArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~ByteArray(){
					ByteArrayLog(pankey_Log_StartMethod, "Destructor", "println", "");
					ByteArrayLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				size_t printTo(Print& p) const{
					ByteArrayLog(pankey_Log_StartMethod, "printTo", "println", "start");
					if(this->isEmpty()){
						ByteArrayLog(pankey_Log_EndMethod, "printTo", "println", "isEmpty");
						return 0;
					}
					size_t i_size = 0;
					for(int x = 0; x < this->getPosition(); x++){
						pankey_Byte f_value = this->m_t_value[x];
						p.print(f_value);
						i_size += sizeof(f_value);
					}
					ByteArrayLog(pankey_Log_EndMethod, "printTo", "println", "end");
					return i_size;
				}

				virtual int getBitSize() const {
					return this->getPosition() * 8;
				}

				virtual ByteArray operator=(const ByteArray& o_array){
					ByteArrayLog(pankey_Log_StartMethod, "operator=", "println", "");
					this->fix();
					this->clear();
					int i_array_length = o_array.getPosition();
					if(i_array_length > 0){
						this->createArray(i_array_length);
						this->copyPointer(o_array.pointer(), i_array_length);
						this->copyEndValue();
					}
					ByteArrayLog(pankey_Log_EndMethod, "operator=", "println", "");
					return *this;
				}

				virtual bool operator==(const ByteArray& o_array){
					if(o_array.getPosition() != this->getPosition()){
						return false;
					}
					for(int x = 0; x < this->getPosition(); x++){
						if(o_array.get(x) != this->get(x)){
							return false;
						}
					}
					return true;
				}

				virtual bool operator!=(const ByteArray& o_array){
					if(o_array.getPosition() != this->getPosition()){
						return true;
					}
					for(int x = 0; x < this->getPosition(); x++){
						if(o_array.get(x) != this->get(x)){
							return true;
						}
					}
					return false;
				}

				virtual void setBit(int cell, int bit, bool value){
					ByteArrayLog(pankey_Log_StartMethod, "setBit", "println", "");
					ByteArrayLog(pankey_Log_Statement, "setBit", "println", "bit");
					ByteArrayLog(pankey_Log_Statement, "setBit", "println", bit);
					pankey_Byte* c = this->getPointer(cell);
					if(c == nullptr || bit >= 8){
						ByteArrayLog(pankey_Log_EndMethod, "setBit", "println", "c == nullptr || bit >= 8");
						return;
					}
					#if pankey_IDE == pankey_Arduino_IDE
					bitWrite((*c), bit, value);
					#elif pankey_Enviroment == pankey_Windows_Enviroment

					#else

					#endif
					ByteArrayLog(pankey_Log_EndMethod, "setBit", "println", "");
				}

				virtual void clearBit(int cell, int bit){
					ByteArrayLog(pankey_Log_StartMethod, "clearBit", "println", "");
					pankey_Byte* c = this->getPointer(cell);
					if(c == nullptr){
						return;
					}
					#if pankey_IDE == pankey_Arduino_IDE
					bitWrite((*c), bit, false);
					#elif pankey_Enviroment == pankey_Windows_Enviroment

					#else

					#endif
					ByteArrayLog(pankey_Log_EndMethod, "clearBit", "println", "");
				}

				virtual void toggleAll(){
					ByteArrayLog(pankey_Log_StartMethod, "toggleAll", "println", "");
					for(int xi = 0; xi < this->getPosition(); xi++){
						for(int xo = 0; xo < 8; xo++){
							pankey_Byte f_byte = this->get(xi);
							#if pankey_IDE == pankey_Arduino_IDE
							bitWrite(f_byte, xo, !bitRead(f_byte, xo));
							#elif pankey_Enviroment == pankey_Windows_Enviroment

							#else

							#endif
						}
					}
					ByteArrayLog(pankey_Log_EndMethod, "toggleAll", "println", "");
				}

				virtual void toggleByte(int cell){
					ByteArrayLog(pankey_Log_StartMethod, "toggleByte", "println", "");
					pankey_Byte* c = this->getPointer(cell);
					if(c == nullptr){
						return;
					}
					for(int x = 0; x < 8; x++){
						#if pankey_IDE == pankey_Arduino_IDE
						bitWrite((*c), x, !bitRead((*c), x));
						#elif pankey_Enviroment == pankey_Windows_Enviroment

						#else

						#endif
					}
					ByteArrayLog(pankey_Log_EndMethod, "toggleByte", "println", "");
				}

				virtual void toggleBit(int cell, int bit){
					ByteArrayLog(pankey_Log_StartMethod, "toggleBit", "println", "");
					pankey_Byte* c = this->getPointer(cell);
					if(c == nullptr){
						return;
					}
					#if pankey_IDE == pankey_Arduino_IDE
					bitWrite((*c), bit, !bitRead((*c), bit));
					#elif pankey_Enviroment == pankey_Windows_Enviroment

					#else

					#endif
					ByteArrayLog(pankey_Log_EndMethod, "toggleBit", "println", "");
				}

				virtual bool getBit(int cell, int bit) const {
					ByteArrayLog(pankey_Log_StartMethod, "getBit", "println", "");
					pankey_Byte* c = this->getPointer(cell);
					if(c == nullptr){
						return false;
					}
					ByteArrayLog(pankey_Log_EndMethod, "getBit", "println", "");
					#if pankey_IDE == pankey_Arduino_IDE
					return bitRead((*c), bit);
					#elif pankey_Enviroment == pankey_Windows_Enviroment
					return false;
					#else
					return false;
					#endif
				}
		};

	}

#endif
