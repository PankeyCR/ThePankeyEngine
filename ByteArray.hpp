
#ifndef ByteArray_hpp
	#define ByteArray_hpp

	#ifdef higgs_Windows
		#include "higgs_Printable.hpp"
		#include "higgs_Print.hpp"
	#endif

	#ifdef higgs_ArduinoIDE
		#include "Arduino.h"
		#include "Printable.h"
		#include "IPAddress.h"
	#endif

	#include "Array.hpp"

	#include "higgs_Byte.hpp"

	#ifdef ByteArray_LogApp
		#include "higgs_Logger.hpp"
		#define ByteArrayLog(location,method,type,mns) higgs_Log((void*)this,location,"ByteArray",method,type,mns)
	#else
		#define ByteArrayLog(location,method,type,mns) 
	#endif

	namespace higgs{

		class ByteArray : public Array<higgs_Byte>, public Printable{
			public:
				ByteArray(){
					ByteArrayLog(higgs_Log_StartMethod, "Constructor", "println", "");
					ByteArrayLog(higgs_Log_Statement, "Constructor", "println", "Default Constructor");
					ByteArrayLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(const Array<higgs_Byte>& c_array){
					ByteArrayLog(higgs_Log_StartMethod, "Constructor", "println", "");
					int i_array_length = c_array.getPosition();
					if(i_array_length > 0){
						this->createArray(i_array_length);
						this->copyPointer(c_array.pointer(), i_array_length);
						this->copyEndValue();
					}
					ByteArrayLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(const ByteArray& c_array){
					ByteArrayLog(higgs_Log_StartMethod, "Constructor", "println", "");
					int i_array_length = c_array.getPosition();
					if(i_array_length > 0){
						this->createArray(i_array_length);
						this->copyPointer(c_array.pointer(), i_array_length);
						this->copyEndValue();
					}
					ByteArrayLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(higgs_Byte* a_pointer, int a_array_length){
					ByteArrayLog(higgs_Log_StartMethod, "Constructor", "println", "");
					if(a_pointer != nullptr){
						if(a_array_length > 0){
							this->createArray(a_array_length);
							this->copyPointer(a_pointer, a_array_length);
							this->copyEndValue();
						}
					}
					ByteArrayLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(ByteArray&& c_array){
					ByteArrayLog(higgs_Log_StartMethod, "Constructor", "println", "");
					int n_size = c_array.getPosition();
					if(n_size > 0){
						this->m_pos = c_array.m_pos;
						this->m_size = c_array.m_size;
						this->m_t_value = c_array.m_t_value;
						c_array.m_t_value = nullptr;
						c_array.m_pos = 0;
						c_array.m_size = 0;
					}
					ByteArrayLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}

				ByteArray(const higgs_Byte& a_value){
					ByteArrayLog(higgs_Log_StartMethod, "Constructor", "println", "");
					this->createArray(1);
					this->copyValue(a_value);
					this->copyEndValue();
					ByteArrayLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~ByteArray(){
					ByteArrayLog(higgs_Log_StartMethod, "Destructor", "println", "");
					ByteArrayLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}

				size_t printTo(Print& p) const{
					ByteArrayLog(higgs_Log_StartMethod, "printTo", "println", "start");
					if(this->isEmpty()){
						ByteArrayLog(higgs_Log_EndMethod, "printTo", "println", "isEmpty");
						return 0;
					}
					size_t i_size = 0;
					for(int x = 0; x < this->getPosition(); x++){
						higgs_Byte f_value = this->m_t_value[x];
						p.print(f_value);
						i_size += sizeof(f_value);
					}
					ByteArrayLog(higgs_Log_EndMethod, "printTo", "println", "end");
					return i_size;
				}

				virtual int getBitSize() const {
					return this->getPosition() * 8;
				}

				virtual ByteArray operator=(const ByteArray& o_array){
					ByteArrayLog(higgs_Log_StartMethod, "operator=", "println", "");
					this->fix();
					this->clear();
					int i_array_length = o_array.getPosition();
					if(i_array_length > 0){
						this->createArray(i_array_length);
						this->copyPointer(o_array.pointer(), i_array_length);
						this->copyEndValue();
					}
					ByteArrayLog(higgs_Log_EndMethod, "operator=", "println", "");
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
					ByteArrayLog(higgs_Log_StartMethod, "setBit", "println", "");
					ByteArrayLog(higgs_Log_Statement, "setBit", "println", "bit");
					ByteArrayLog(higgs_Log_Statement, "setBit", "println", bit);
					higgs_Byte* c = this->getPointer(cell);
					if(c == nullptr || bit >= 8){
						ByteArrayLog(higgs_Log_EndMethod, "setBit", "println", "c == nullptr || bit >= 8");
						return;
					}
					#ifdef higgs_ArduinoIDE
					bitWrite((*c), bit, value);
					#elif defined(higgs_Windows)

					#else

					#endif
					ByteArrayLog(higgs_Log_EndMethod, "setBit", "println", "");
				}

				virtual void clearBit(int cell, int bit){
					ByteArrayLog(higgs_Log_StartMethod, "clearBit", "println", "");
					higgs_Byte* c = this->getPointer(cell);
					if(c == nullptr){
						return;
					}
					#ifdef higgs_ArduinoIDE
					bitWrite((*c), bit, false);
					#elif defined(higgs_Windows)

					#else

					#endif
					ByteArrayLog(higgs_Log_EndMethod, "clearBit", "println", "");
				}

				virtual void toggleAll(){
					ByteArrayLog(higgs_Log_StartMethod, "toggleAll", "println", "");
					for(int xi = 0; xi < this->getPosition(); xi++){
						for(int xo = 0; xo < 8; xo++){
							higgs_Byte f_byte = this->get(xi);
							#ifdef higgs_ArduinoIDE
							bitWrite(f_byte, xo, !bitRead(f_byte, xo));
							#elif defined(higgs_Windows)

							#else

							#endif
						}
					}
					ByteArrayLog(higgs_Log_EndMethod, "toggleAll", "println", "");
				}

				virtual void toggleByte(int cell){
					ByteArrayLog(higgs_Log_StartMethod, "toggleByte", "println", "");
					higgs_Byte* c = this->getPointer(cell);
					if(c == nullptr){
						return;
					}
					for(int x = 0; x < 8; x++){
						#ifdef higgs_ArduinoIDE
						bitWrite((*c), x, !bitRead((*c), x));
						#elif defined(higgs_Windows)

						#else

						#endif
					}
					ByteArrayLog(higgs_Log_EndMethod, "toggleByte", "println", "");
				}

				virtual void toggleBit(int cell, int bit){
					ByteArrayLog(higgs_Log_StartMethod, "toggleBit", "println", "");
					higgs_Byte* c = this->getPointer(cell);
					if(c == nullptr){
						return;
					}
					#ifdef higgs_ArduinoIDE
					bitWrite((*c), bit, !bitRead((*c), bit));
					#elif defined(higgs_Windows)

					#else

					#endif
					ByteArrayLog(higgs_Log_EndMethod, "toggleBit", "println", "");
				}

				virtual bool getBit(int cell, int bit) const {
					ByteArrayLog(higgs_Log_StartMethod, "getBit", "println", "");
					higgs_Byte* c = this->getPointer(cell);
					if(c == nullptr){
						return false;
					}
					ByteArrayLog(higgs_Log_EndMethod, "getBit", "println", "");
					#ifdef higgs_ArduinoIDE
					return bitRead((*c), bit);
					#elif defined(higgs_Windows)
					return false;
					#else
					return false;
					#endif
				}
		};

	}

#endif
