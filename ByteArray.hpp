
#ifndef CONFIGURATION_ByteArray_hpp
#define CONFIGURATION_ByteArray_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_ByteArray)
		#define ByteArray_hpp

		#define IMPLEMENTATION_ByteArray
		#define IMPLEMENTING_ByteArray
	#else
		#if defined(DISABLE_IMPLEMENTATION_ByteArray)
			#define IMPLEMENTATION_ByteArray
			#define IMPLEMENTING_ByteArray
		#endif
	#endif
#endif

#ifndef ByteArray_hpp
#define ByteArray_hpp
#define ByteArray_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_ByteArray
	#define IMPLEMENTATION_ByteArray IMPLEMENTATION(public ByteArray)
	#define IMPLEMENTING_ByteArray IMPLEMENTING(public ByteArray)
#endif

#ifdef ame_Windows
	#include "ame_Printable.hpp"
	#include "ame_Print.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
	#include "IPAddress.h"
#endif

#include "Array.hpp"
#include "Class.hpp"

#include "ame_Byte.hpp"

#ifdef ByteArray_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define ByteArrayLog(location,method,type,mns) ame_Log(this,location,"ByteArray",method,type,mns)
	#define const_ByteArrayLog(location,method,type,mns)	System::console.println(method);System::console.println(mns)
#else
	#ifdef ByteArray_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define ByteArrayLog(location,method,type,mns) ame_LogDebug(this,location,"ByteArray",method,type)
		#define const_ByteArrayLog(location,method,type,mns)
	#else
		#define ByteArrayLog(location,method,type,mns)
		#define const_ByteArrayLog(location,method,type,mns)
	#endif
#endif

namespace ame{

class ByteArray : public Array<ame_Byte>, public Printable{
	public:
		ByteArray(){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			ByteArrayLog(ame_Log_Statement, "Constructor", "println", "Default Constructor");
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		ByteArray(const Array<ame_Byte>& c_array){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			int i_array_length = c_array.getPosition();
			if(i_array_length > 0){
				this->createArray(i_array_length);
				this->copyPointer(c_array.pointer(), i_array_length);
				this->copyEndValue();
			}
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		ByteArray(const ByteArray& c_array){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			int i_array_length = c_array.getPosition();
			if(i_array_length > 0){
				this->createArray(i_array_length);
				this->copyPointer(c_array.pointer(), i_array_length);
				this->copyEndValue();
			}
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		ByteArray(ame_Byte* a_pointer, int a_array_length){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			if(a_pointer != nullptr){
				if(a_array_length > 0){
					this->createArray(a_array_length);
					this->copyPointer(a_pointer, a_array_length);
					this->copyEndValue();
				}
			}
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		ByteArray(ByteArray&& c_array){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			int n_size = c_array.getPosition();
			if(n_size > 0){
				this->m_pos = c_array.m_pos;
				this->m_size = c_array.m_size;
				this->m_t_value = c_array.m_t_value;
				c_array.m_t_value = nullptr;
				c_array.m_pos = 0;
				c_array.m_size = 0;
			}
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		ByteArray(const ame_Byte& a_value){
			ByteArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->createArray(1);
			this->copyValue(a_value);
			this->copyEndValue();
			ByteArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		virtual ~ByteArray(){
			ByteArrayLog(ame_Log_StartMethod, "Destructor", "println", "");
			ByteArrayLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		size_t printTo(Print& p) const{
			const_ByteArrayLog(ame_Log_StartMethod, "printTo", "println", "start");
			if(this->isEmpty()){
                const_ByteArrayLog(ame_Log_EndMethod, "printTo", "println", "isEmpty");
				return 0;
			}
			size_t i_size = 0;
			for(int x = 0; x < this->getPosition(); x++){
				ame_Byte f_value = this->m_t_value[x];
				p.print(f_value);
				i_size += sizeof(f_value);
			}
			const_ByteArrayLog(ame_Log_EndMethod, "printTo", "println", "end");
			return i_size;
		}

		virtual int getBitSize() const {
			return this->getPosition() * 8;
		}

		virtual ByteArray operator=(const ByteArray& o_array){
			ByteArrayLog(ame_Log_StartMethod, "operator=", "println", "");
			this->fix();
			this->clear();
			int i_array_length = o_array.getPosition();
			if(i_array_length > 0){
				this->createArray(i_array_length);
				this->copyPointer(o_array.pointer(), i_array_length);
				this->copyEndValue();
			}
			ByteArrayLog(ame_Log_EndMethod, "operator=", "println", "");
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
			ByteArrayLog(ame_Log_StartMethod, "setBit", "println", "");
			ByteArrayLog(ame_Log_Statement, "setBit", "println", "bit");
			ByteArrayLog(ame_Log_Statement, "setBit", "println", bit);
			ame_Byte* c = this->getPointer(cell);
			if(c == nullptr || bit >= 8){
				ByteArrayLog(ame_Log_EndMethod, "setBit", "println", "c == nullptr || bit >= 8");
				return;
			}
			#ifdef ame_ArduinoIDE
			bitWrite((*c), bit, value);
			#elif defined(ame_Windows)

			#else

			#endif
			ByteArrayLog(ame_Log_EndMethod, "setBit", "println", "");
		}

		virtual void clearBit(int cell, int bit){
			ByteArrayLog(ame_Log_StartMethod, "clearBit", "println", "");
			ame_Byte* c = this->getPointer(cell);
			if(c == nullptr){
				return;
			}
			#ifdef ame_ArduinoIDE
			bitWrite((*c), bit, false);
			#elif defined(ame_Windows)

			#else

			#endif
			ByteArrayLog(ame_Log_EndMethod, "clearBit", "println", "");
		}

		virtual void toggleAll(){
			ByteArrayLog(ame_Log_StartMethod, "toggleAll", "println", "");
			for(int xi = 0; xi < this->getPosition(); xi++){
				for(int xo = 0; xo < 8; xo++){
					ame_Byte f_byte = this->get(xi);
                    #ifdef ame_ArduinoIDE
					bitWrite(f_byte, xo, !bitRead(f_byte, xo));
                    #elif defined(ame_Windows)

                    #else

                    #endif
				}
			}
			ByteArrayLog(ame_Log_EndMethod, "toggleAll", "println", "");
		}

		virtual void toggleByte(int cell){
			ByteArrayLog(ame_Log_StartMethod, "toggleByte", "println", "");
			ame_Byte* c = this->getPointer(cell);
			if(c == nullptr){
				return;
			}
			for(int x = 0; x < 8; x++){
                #ifdef ame_ArduinoIDE
				bitWrite((*c), x, !bitRead((*c), x));
                #elif defined(ame_Windows)

                #else

                #endif
			}
			ByteArrayLog(ame_Log_EndMethod, "toggleByte", "println", "");
		}

		virtual void toggleBit(int cell, int bit){
			ByteArrayLog(ame_Log_StartMethod, "toggleBit", "println", "");
			ame_Byte* c = this->getPointer(cell);
			if(c == nullptr){
				return;
			}
            #ifdef ame_ArduinoIDE
			bitWrite((*c), bit, !bitRead((*c), bit));
            #elif defined(ame_Windows)

            #else

            #endif
			ByteArrayLog(ame_Log_EndMethod, "toggleBit", "println", "");
		}

		virtual bool getBit(int cell, int bit) const {
			const_ByteArrayLog(ame_Log_StartMethod, "getBit", "println", "");
			ame_Byte* c = this->getPointer(cell);
			if(c == nullptr){
				return false;
			}
			const_ByteArrayLog(ame_Log_EndMethod, "getBit", "println", "");
            #ifdef ame_ArduinoIDE
			return bitRead((*c), bit);
            #elif defined(ame_Windows)

            #else

            #endif
		}

		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<ByteArray>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<ByteArray>::getClass() || Array<ame_Byte>::instanceof(cls);
		}
		#endif
};

}

#endif
