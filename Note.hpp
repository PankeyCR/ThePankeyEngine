
/*
*	position = total of chars in the CharArray
*	size = total size of the array
*	length = total of chars before the endValue()
*
*
*	position = length
*
*/

#ifndef Note_hpp
#define Note_hpp

#include "pankey.hpp"

#include "Array.hpp"
#include "CharArray.hpp"

#ifdef pankey_Windows
	#include "pankey_Printable.hpp"
	#include "pankey_Print.hpp"
#endif

#ifdef pankey_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "NoteIterator.hpp"

#include "pankey_Byte.hpp"

#define pankey_BINARY 0
#define pankey_HEXADECIMAL 1
#define pankey_DECIMAL 2

#ifdef Note_LogApp
	#include "pankey_Logger.hpp"
	#define NoteLog(location,method,type,mns) pankey_Log((void*)this,location,"Note",method,type,mns)
#else
	#define NoteLog(location,method,type,mns)
#endif

#ifdef PointerNote_LogApp
	#include "pankey_Logger.hpp"
	#define PointerNoteLog(location,method,type,mns) pankey_Log((void*)this,location,"Note",method,type,mns)
#else
	#define PointerNoteLog(location,method,type,mns)
#endif


namespace pankey{

class Note : public CharArray, public Printable{
    public:
		Note(){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "Default Constructor");
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const char* c_value){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "const char* c_value");
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Char Array:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", c_value);

			this->insertLocalArrayPointer(0, c_value);

			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
				
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const Array<char>& source){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "const Array<char>& source");
			int i_array_length = source.length();
			if(i_array_length > 0){
				this->createArray(i_array_length);
				this->copyPointer(source.pointer(), i_array_length);
				this->copyEndValue();
				NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Length:");
				NoteLog(pankey_Log_Statement, "Constructor", "println", i_array_length);
				NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
				NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
				NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
				NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
			}
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const Note& source){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "const Note& val");
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Note:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", source.pointer());
			int i_array_length = source.length();
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Length:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", i_array_length);
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
			if(i_array_length > 0){
				this->createArray(i_array_length);
				this->copyPointer(source.pointer(), i_array_length);
				this->copyEndValue();
				NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
				NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
				NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
				NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
			}
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Note(Note&& source){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "Note&& source");
			int i_array_length = source.getPosition();
			if(i_array_length > 0){
				this->m_pos = source.m_pos;
				this->m_size = source.m_size;
				this->m_t_value = source.m_t_value;
				source.m_t_value = nullptr;
				source.m_pos = 0;
				source.m_size = 0;
				NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Length:");
				NoteLog(pankey_Log_Statement, "Constructor", "println", i_array_length);
				NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
				NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
				NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
				NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
			}
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const char& c_char){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "const char& c_char");
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Char:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", c_char);
			this->createArray(1);
			this->copyValue(c_char);
			this->copyEndValue();
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Length:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", 1);
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const bool& c_value){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "const bool& i");
			NoteLog(pankey_Log_Statement, "Constructor", "println", "bool:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", c_value);
			char* i_pointer = this->getBool(c_value);
			this->addLocalArrayPointer(i_pointer);
			delete i_pointer;
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const int& c_value){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "const int& c_value");
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Int:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", c_value);
			char* i_pointer = this->getInt(c_value);
			this->addLocalArrayPointer(i_pointer);
			delete i_pointer;
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const long& c_value){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "const long& c_value");
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Long:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", c_value);
			char* i_pointer = this->getLong(c_value);
			this->addLocalArrayPointer(i_pointer);
			delete i_pointer;
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const float& c_value){
			NoteLog(pankey_Log_StartMethod, "Constructor", "println", "const float& c_value");
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Float:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", c_value);
			char* i_pointer = this->getFloat(c_value);
			this->addLocalArrayPointer(i_pointer);
			delete i_pointer;
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(pankey_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		virtual ~Note(){
			NoteLog(pankey_Log_StartMethod, "Destructor", "println", "");
			NoteLog(pankey_Log_EndMethod, "Destructor", "println", "");
		}

		virtual size_t printTo(Print& p) const{
			NoteLog(pankey_Log_StartMethod, "printTo", "println", "");
			if(this->isEmpty()){
                NoteLog(pankey_Log_EndMethod, "printTo", "println", "");
				return 0;
			}
			size_t i_size = 0;
			char i_endValue = this->endValue();
			for(int x = 0; x < this->getPosition(); x++){
				char f_value = this->m_t_value[x];
                if(f_value == i_endValue){
					NoteLog(pankey_Log_EndMethod, "printTo", "println", "f_value == i_endValue");
                    NoteLog(pankey_Log_EndMethod, "printTo", "println", "index: ");
                    NoteLog(pankey_Log_EndMethod, "printTo", "println", x);
                    break;
                }
				p.print(f_value);
				i_size += sizeof(f_value);
			}
			NoteLog(pankey_Log_EndMethod, "printTo", "println", "");
			return i_size;
		}

		virtual Note& operator=(const Note& source){
			NoteLog(pankey_Log_StartMethod, "operator=", "println", "");
			this->clear();
			NoteLog(pankey_Log_Statement, "operator=", "println", "const Note& val");
			int i_array_length = source.length();
			if(i_array_length > 0){
				this->m_size = this->getAvailableSize(i_array_length);
				this->m_t_value = this->create(this->m_size);
				this->copyPointer(source.m_t_value, i_array_length);
				this->copyEndValue(this->getPosition());
				NoteLog(pankey_Log_Statement, "operator=", "println", "Array Length:");
				NoteLog(pankey_Log_Statement, "operator=", "println", i_array_length);
				NoteLog(pankey_Log_Statement, "operator=", "println", "Array Position:");
				NoteLog(pankey_Log_Statement, "operator=", "println", this->getPosition());
				NoteLog(pankey_Log_Statement, "operator=", "println", "Array Size:");
				NoteLog(pankey_Log_Statement, "operator=", "println", this->getSize());
			}
			NoteLog(pankey_Log_EndMethod, "operator=", "println", "");
			return *this;
		}

		virtual Note& operator=(Note&& source){
			this->clear();
			NoteLog(pankey_Log_StartMethod, "operator=", "println", "");
			NoteLog(pankey_Log_Statement, "operator=", "println", "const Note& val");
			int i_array_length = source.length();
			if(i_array_length > 0){
				this->m_pos = source.m_pos;
				this->m_size = source.m_size;
				this->m_t_value = source.m_t_value;
				source.m_t_value = nullptr;
				source.m_pos = 0;
				source.m_size = 0;
				NoteLog(pankey_Log_Statement, "operator=", "println", "Array Length:");
				NoteLog(pankey_Log_Statement, "operator=", "println", i_array_length);
				NoteLog(pankey_Log_Statement, "operator=", "println", "Array Position:");
				NoteLog(pankey_Log_Statement, "operator=", "println", this->getPosition());
				NoteLog(pankey_Log_Statement, "operator=", "println", "Array Size:");
				NoteLog(pankey_Log_Statement, "operator=", "println", this->getSize());
			}
			NoteLog(pankey_Log_EndMethod, "operator=", "println", "");
			return *this;
		}

		virtual Note operator+=(const Note& a_note){
			NoteLog(pankey_Log_StartMethod, "operator+=", "println", "");
			NoteLog(pankey_Log_EndMethod, "operator+=", "println", "");
			return this->addLocalCharArray(a_note);
		}

		virtual Note operator+(const Note& a_note)const{
			NoteLog(pankey_Log_StartMethod, "operator+", "println", "");
			NoteLog(pankey_Log_EndMethod, "operator+", "println", "");
			return this->addCharArray(a_note);
		}

		virtual bool operator==(const Note& a_note) const{
			if(a_note.length() != this->length()){
				return false;
			}
			for(int x = 0; x < this->length(); x++){
				char f_char_1 = this->get(x);
				char f_char_2 = a_note.get(x);
				if(f_char_1 != f_char_2){
					return false;
				}
			}
			return true;
		}

		virtual bool operator!=(const Note& a_note){
			if(a_note.length() != this->length()){
				return true;
			}
			for(int x = 0; x < this->length(); x++){
				char f_char_1 = this->get(x);
				char f_char_2 = a_note.get(x);
				if(f_char_1 == f_char_2){
					return false;
				}
			}
			return true;
		}

		#if defined(pankey_ArduinoIDE)

			virtual String toString()const{
				String i_str;
				i_str.reserve(this->getPosition());
				for(int x = 0; x < this->getPosition(); x++){
					i_str.concat(this->get(x));
				}
				return i_str;
			}

		#endif

};

}

#endif