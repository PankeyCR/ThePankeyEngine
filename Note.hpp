
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Note)
	#define Note_hpp
	
	#ifdef ame_Windows
		typedef std::string Note;
	#endif

	#ifdef ame_ArduinoIDE
		typedef String Note;
	#endif
	
#endif

#ifndef Note_hpp
#define Note_hpp
#define Note_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
	#include "ame_Printable.h"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
	#include "IPAddress.h"
#endif

#include "NoteIterator.hpp"

#include "Memory.hpp"

#include "RawList.hpp"
#include "PrimitiveRawList.hpp"
#include "RawMap.hpp"
#include "PrimitiveRawMap.hpp"

#define ame_BINARY 0
#define ame_HEXADECIMAL 1
#define ame_DECIMAL 2

#ifdef Note_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define NoteLog(location,method,type,mns) ame_Log((void*)this,location,"Note",method,type,mns)
	#define const_NoteLog(location,method,type,mns) 
	#define StaticNoteLog(pointer,location,method,type,mns) ame_Log(pointer,location,"Note",method,type,mns)
#else
	#ifdef Note_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define NoteLog(location,method,type,mns) ame_LogDebug((void*)this,location,"Note",method,type)
		#define const_NoteLog(location,method,type,mns) 
		#define StaticNoteLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"Note",method,type)
	#else
		#define NoteLog(location,method,type,mns) 
		#define const_NoteLog(location,method,type,mns) 
		#define StaticNoteLog(pointer,location,method,type,mns) 
	#endif
#endif


namespace ame{

class Note : public Printable{

	protected:
		char* m_string = nullptr;
		int m_pos = 0;
		int m_size = 0;

    public:
		Note(){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "");
			NoteLog(ame_Log_Statement, "Constructor", "println", "Default Constructor");
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const char* val){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const char* val");
			if(val != nullptr){
				int lth = length(val);
				NoteLog(ame_Log_Statement, "Constructor", "println", lth);
				if(lth > 0){
					m_pos = lth;
					m_size = getAvailableSize(lth);
					NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
					m_string = create(m_size);
					copy(m_string, val);
					NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
				}
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const Note& source){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const Note& val");
			// NoteLog(0, "Constructor", source);
			int n_size = source.getPosition();
			if(n_size > 0){
				NoteLog(ame_Log_Statement, "Constructor", "println", n_size);
				m_pos = n_size;
				m_size = getAvailableSize(m_pos);
				NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
				m_string = create(m_size);
				copy(m_string, source.m_string);
				NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(Note&& source){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "Note&& source");
			int n_size = source.getPosition();
			if(n_size > 0){
				m_pos = source.m_pos;
				m_size = source.m_size;
				m_string = source.m_string;
				source.m_string = nullptr;
				source.m_pos = 0;
				source.m_size = 0;
				NoteLog(ame_Log_Statement, "Constructor", "println", m_pos);
				NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
				NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const bool& i){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const char& i");
			m_pos = 1;
			m_size = getAvailableSize(1);
			m_string = create(m_size);
			if(i){
				m_string[0] = '1';
			}else{
				m_string[0] = '0';
			}
			m_string[1] = '\0';
			NoteLog(ame_Log_Statement, "Constructor", "println", m_pos);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const char& i){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const char& i");
			m_pos = 1;
			m_size = getAvailableSize(1);
			m_string = create(m_size);
			m_string[0] = i;
			m_string[1] = '\0';
			NoteLog(ame_Log_Statement, "Constructor", "println", m_pos);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const int& val){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const int& i");
			m_pos = intCharSize(val);
			m_size = getAvailableSize(m_pos);

			m_string = create(m_size);
			intToCharPointer(val, m_pos, 0, m_string, true);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_pos);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const long& val){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const long& i");
			m_pos = longCharSize(val);
			m_size = getAvailableSize(m_pos);

			m_string = create(m_size);
			longToCharPointer(val, m_pos, 0, m_string, true);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_pos);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const float& val){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const float& i");
			m_pos = floatCharSize(val, 4);
			m_size = getAvailableSize(m_pos);

			m_string = create(m_size);
			floatToCharPointer(val, m_pos, 0, 4, m_string, true);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_pos);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const byte& val){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const byte& i");
			m_pos = byteCharSize(ame_DECIMAL, val);
			m_size = getAvailableSize(m_pos);

			m_string = create(m_size);
			byteToCharPointer(val, m_pos, 0, m_string, ame_DECIMAL, true);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_pos);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const byte& val, int a_type){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const byte& val, int a_type");
			m_pos = byteCharSize(a_type, val);
			m_size = getAvailableSize(m_pos);

			m_string = create(m_size);
			byteToCharPointer(val, m_pos, 0, m_string, a_type, true);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_pos);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
			NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		#ifdef ame_ArduinoIDE

		Note(const String& source){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const String& source");
			if(source != ""){
				m_pos = source.length();
				m_size = getAvailableSize(m_pos);
				m_string = create(m_size);
				copy(m_string, source.c_str());
				NoteLog(ame_Log_Statement, "Constructor", "println", m_pos);
				NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
				NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		// Note(String&& source){
			// if(!source.isEmpty()){
				// m_string = source.c_str();
				// source.c_str() = nullptr;
			// }
		// }

		#endif

		virtual ~Note(){
			NoteLog(ame_Log_StartMethod, "Destructor", "println", "");
			NoteLog(ame_Log_Statement, "Destructor", "println", "~Note");
			NoteLog(ame_Log_Statement, "Destructor", "println", m_pos);
			NoteLog(ame_Log_Statement, "Destructor", "println", m_size);
			if(m_string == nullptr){
				NoteLog(ame_Log_Note_Destructor_nullchar, "Destructor", "println", "m_string == nullptr");
			}else{
				NoteLog(ame_Log_Note_Destructor_fillchar, "Destructor", "println", m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
			}
			NoteLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		virtual size_t printTo(Print& p) const{
			if(m_string == nullptr){
				p.print("");
				return sizeof("");
			}
			size_t i_size = 0;
			for(int x = 0; x < m_pos; x++){
				p.print(m_string[x]);
				i_size += sizeof(m_string[x]);
			}
			return i_size;
		}

		virtual char* c_str(){
			NoteLog(ame_Log_StartMethod, "pointer", "println", "");
			NoteLog(ame_Log_EndMethod, "pointer", "println", "");
			return m_string;
		}

		virtual int length() const{
			const_NoteLog(ame_Log_StartMethod, "pointer", "println", "");
			int l = length(m_string);
			if(l <= 0){
				const_NoteLog(ame_Log_EndMethod, "pointer", "println", "");
				return 0;
			}
			const_NoteLog(ame_Log_EndMethod, "pointer", "println", "");
			return l;
		}

		virtual int getPosition() const{
			return m_pos;
		}

		virtual int getSize() const{
			return m_size;
		}

		virtual bool isEmpty() const{
			return m_pos == 0 || m_string == nullptr;
		}

		virtual char charAt(int x) const{
			if(m_string == nullptr){
				return 0;
			}
			if(x >= m_pos){
				return 0;
			}
			return m_string[x];
		}

		virtual NoteIterator begin(){
			NoteLog(ame_Log_StartMethod, "begin", "println", "");
			NoteLog(ame_Log_EndMethod, "begin", "println", "");
			return NoteIterator(m_string,0);
		}
		virtual NoteIterator end(){
			NoteLog(ame_Log_StartMethod, "end", "println", "");
			NoteLog(ame_Log_EndMethod, "end", "println", "");
			return NoteIterator(m_string, m_pos);
		}

		virtual Note add(const char* value){
			NoteLog(ame_Log_StartMethod, "add", "println", "");
			int v_size = length(value);
			if(v_size <= 0){
				NoteLog(ame_Log_Statement, "add", "println", "v_size <= 0");
				return Note(m_string);
			}
			
			if(m_string == nullptr){
				NoteLog(ame_Log_Statement, "add", "println", "m_string == nullptr");
				return Note(value);
			}
			
			Note temp;
			temp.m_pos = m_pos + v_size;
			temp.m_size = getAvailableSize(temp.m_pos);
			temp.m_string = create(temp.m_size);

			copy(temp.m_string, m_string);
			concat(temp.m_string, value);
			
			NoteLog(ame_Log_Statement, "add", "println", m_pos);
			NoteLog(ame_Log_Statement, "add", "println", m_size);
			NoteLog(ame_Log_Statement, "add", "println", m_string);
			
			NoteLog(ame_Log_EndMethod, "add", "println", "");

			return temp;
		}

		virtual Note addLocal(const char* value){
			NoteLog(ame_Log_StartMethod, "addLocal", "println", "");
			int v_size = length(value);
			if(v_size <= 0){
				NoteLog(ame_Log_Statement, "addLocal", "println", "v_size <= 0");
				return *this;
			}
			
			if(m_string == nullptr){
				NoteLog(ame_Log_Statement, "addLocal", "println", "m_string == nullptr");
				int lth = length(value);
				if(lth > 0){
					NoteLog(ame_Log_Statement, "addLocal", "println", "lth > 0");
					m_pos = lth;
					m_size = getAvailableSize(lth);
					m_string = create(m_size);
					copy(m_string, value);
				}
				NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
				return *this;
			}
			
			m_pos += v_size;
			
			if(m_pos >= m_size){
				NoteLog(ame_Log_Statement, "addLocal", "println", "m_pos >= m_size");
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			concat(m_string, value);
			
			NoteLog(ame_Log_Statement, "addLocal", "println", m_pos);
			NoteLog(ame_Log_Statement, "addLocal", "println", m_size);
			NoteLog(ame_Log_Statement, "addLocal", "println", m_string);
			
			NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
			return *this;
		}

		virtual Note addLocal(const char& chr){
			NoteLog(ame_Log_StartMethod, "addLocal", "println", "");
			NoteLog(ame_Log_Statement, "addLocal", "println", "~Note");
			if(m_string == nullptr){
				NoteLog(0, "addLocal", "println", "m_string == nullptr");
				m_pos = 1;
				m_size = getAvailableSize(1);
				m_string = create(m_size);
				m_string[0] = chr;
				m_string[1] = '\0';
			
				NoteLog(ame_Log_Statement, "addLocal", "println", m_pos);
				NoteLog(ame_Log_Statement, "addLocal", "println", m_size);
				NoteLog(ame_Log_Statement, "addLocal", "println", m_string);
				NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
				return *this;
			}
			
			m_pos += 1;
			
			if(m_pos >= m_size){
				NoteLog(ame_Log_Statement, "addLocal", "println", "m_string >= nullptr");
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			m_string[m_pos - 1] = chr;
			m_string[m_pos] = '\0';
			
			NoteLog(ame_Log_Statement, "addLocal", "println", m_pos);
			NoteLog(ame_Log_Statement, "addLocal", "println", m_size);
			NoteLog(ame_Log_Statement, "addLocal", "println", m_string);
			
			NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
			return *this;
		}

		virtual Note addLocal(const Note& note){
			NoteLog(ame_Log_StartMethod, "Destructor", "println", "");
			NoteLog(ame_Log_Statement, "Destructor", "println", "~Note");
			if(note.m_pos <= 0){
				NoteLog(ame_Log_EndMethod, "addLocal", "println", "note.m_pos <= 0");
				return *this;
			}
			
			if(m_string == nullptr){
				NoteLog(ame_Log_Statement, "addLocal", "println", "m_string == nullptr");
				int lth = note.m_pos;
				if(lth > 0){
					m_pos = lth;
					m_size = getAvailableSize(lth);
					m_string = create(m_size);
					copy(m_string, note.m_string);
			
					NoteLog(ame_Log_Statement, "addLocal", "println", m_pos);
					NoteLog(ame_Log_Statement, "addLocal", "println", m_size);
					NoteLog(ame_Log_Statement, "addLocal", "println", m_string);
				}
			
				NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
				return *this;
			}
			
			m_pos += note.m_pos;
			
			if(m_pos >= m_size){
				NoteLog(ame_Log_Statement, "addLocal", "println", "m_string >= nullptr");
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			concat(m_string, note.m_string);
			
			NoteLog(ame_Log_Statement, "addLocal", "println", m_pos);
			NoteLog(ame_Log_Statement, "addLocal", "println", m_size);
			NoteLog(ame_Log_Statement, "addLocal", "println", m_string);
			
			NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
			return *this;
		}

		virtual void concat(const Note& note){
			NoteLog(ame_Log_StartMethod, "concat", "println", "");
			NoteLog(ame_Log_Statement, "concat", "println", "");
			if(note.m_pos <= 0){
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			
			if(m_string == nullptr){
				int lth = note.m_pos;
				if(lth > 0){
					m_pos = lth;
					m_size = getAvailableSize(lth);
					m_string = create(m_size);
					copy(m_string, note.m_string);
				}
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			
			m_pos += note.m_pos;
			
			if(m_pos >= m_size){
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			concat(m_string, note.m_string);
			
			NoteLog(ame_Log_EndMethod, "concat", "println", "");
		}

		virtual void concat(const char& chr){
			NoteLog(ame_Log_StartMethod, "concat", "println", "");
			NoteLog(ame_Log_Statement, "concat", "println", "");
			if(m_string == nullptr){
				m_pos = 1;
				m_size = getAvailableSize(1);
				m_string = create(m_size);
				m_string[0] = chr;
				m_string[1] = '\0';
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			
			m_pos += 1;
			
			if(m_pos >= m_size){
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			m_string[m_pos - 1] = chr;
			m_string[m_pos] = '\0';
			
			NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
		}

		virtual void concat(const char* chr){
			NoteLog(ame_Log_StartMethod, "concat", "println", "");
			NoteLog(ame_Log_Statement, "concat", "println", "~Note");
			if(chr == nullptr){
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			
			if(m_string == nullptr){
				int lth = length(chr);
				if(lth > 0){
					m_pos = lth;
					m_size = getAvailableSize(lth);
					m_string = create(m_size);
					copy(m_string, chr);
				}
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			
			int v_size = length(chr);
			if(v_size <= 0){
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			m_pos += v_size;
			
			if(m_pos >= m_size){
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			concat(m_string, chr);
			
			NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
		}

		virtual void concat(const int& val){
			NoteLog(ame_Log_StartMethod, "concat", "println", "");
			NoteLog(ame_Log_Statement, "concat", "println", "~Note");
			if(m_string == nullptr){
				m_pos = intCharSize(val);
				m_size = getAvailableSize(m_pos);

				m_string = create(m_size);
				intToCharPointer(val, m_pos, 0, m_string, true);
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			
			int size_val = intCharSize(val);
			
			if(m_pos + size_val >= m_size){
				m_size = getAvailableSize(m_pos + size_val);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			intToCharPointer(val, size_val, m_pos, m_string, true);

			m_pos += size_val;
			
			NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
		}

		virtual void concat(const long& val){
			NoteLog(ame_Log_StartMethod, "concat", "println", "");
			NoteLog(ame_Log_Statement, "concat", "println", "~Note");
			if(m_string == nullptr){
				m_pos = longCharSize(val);
				m_size = getAvailableSize(m_pos);

				m_string = create(m_size);
				longToCharPointer(val, m_pos, 0, m_string, true);
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			
			int size_val = longCharSize(val);
			
			if(m_pos + size_val >= m_size){
				m_size = getAvailableSize(m_pos + size_val);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			longToCharPointer(val, size_val, m_pos, m_string, true);
			
			m_pos += size_val;
			
			NoteLog(ame_Log_EndMethod, "concat", "println", "");
		}

		virtual void concat(const float& val){
			NoteLog(ame_Log_StartMethod, "concat", "println", "");
			NoteLog(ame_Log_Statement, "concat", "println", "~Note");
			if(m_string == nullptr){
				m_pos = floatCharSize(val, 4);
				m_size = getAvailableSize(m_pos);

				m_string = create(m_size);
				floatToCharPointer(val, m_pos, 0, 4, m_string, true);
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			
			int size_val = floatCharSize(val, 4);
			
			if(m_pos + size_val >= m_size){
				m_size = getAvailableSize(m_pos + size_val);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			floatToCharPointer(val, size_val, m_pos, 4, m_string, true);
			
			m_pos += size_val;
			
			NoteLog(ame_Log_EndMethod, "concat", "println", "");
		}

#ifdef ame_ArduinoIDE
		virtual void concat(const String& val){
			NoteLog(ame_Log_StartMethod, "concat", "println", "");
			NoteLog(ame_Log_Statement, "concat", "println", "~Note");
			if(m_string == nullptr){
				m_pos = val.length();
				m_size = getAvailableSize(m_pos);

				m_string = create(m_size);
				copy(m_string, val.c_str());
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			
			if(val == ""){
				NoteLog(ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			m_pos += val.length();

			if(m_pos >= m_size){
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			concat(m_string, val.c_str());
			
			NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
		}
#endif

		// PrimitiveList<int> getCharPositions(char chr);
		// int getCharPosition(char chr, int pos);
		// int getCharSize(char chr);

		// PrimitiveList<int> getSpacePositions();/////////////////////////
		// int getSpaceSize();
		// int getSpacingSize();

		// PrimitiveList<int> getStringPositions(String s);
		// int getStringPosition(String s, int pos);

		// void fixExtraSpace();
		// void fixEmptySpaces();
		// void fixEndLinePoint();

		// static String fixExtraSpace(String s);
		// static String fixEmptySpaces(String s);
		// static String fixEndLinePoint(String s);

		// PrimitiveList<String> getWords();

		// String getWord(int pos);
		// String getSentence(int pos);
		// String getParagraph(int pos);

		// static String getWord(int pos, String note);
		// static String getSentence(int pos, String note);
		// static String getParagraph(int pos, String note);

		// int getSentenceSize();
		// static int getSentenceSize(String note);

		// bool contain(String key);

		// void reset();
		// bool remove(String key);
		// bool remove(char key,int pos);
		// bool remove(String key,int pos);

		// static String Split(String divide, int parte, char limiter);
		// static int SplitLenght(String divide, char limiter);
		// static String Split(String divide,int parte, char limiter, char fin);

		int toInt() const {
			NoteLog(ame_Log_StartMethod, "toInt", "println", "");
			NoteLog(ame_Log_Statement, "toInt", "println", "~Note");
			int output = 0;
			int c_size = length(m_string);
			bool lastDecimals = false;
			for(int x = 0; x < c_size; x++){
				if(m_string[x] == 46){
					if(lastDecimals){
						// Serial.println("m_string[x] == 46 && lastDecimals");
						// Serial.print("position ");Serial.println(x);
						NoteLog(ame_Log_EndMethod, "toInt", "println", "");
						return 0;
					}
					// Serial.println("m_string[x] == 46");
					// Serial.print("position ");Serial.println(x);
					int expn = 10;
					for(int y = 0; y < c_size - x - 1; y++){
						expn *= 10;
					}
					output /= expn;
					lastDecimals = true;
					continue;
				}
				if(m_string[x] > 47 && m_string[x] < 58){
					if(lastDecimals){
						// Serial.println("m_string[x] > 47 && m_string[x] < 58 && lastDecimals");
						// Serial.print("position ");Serial.println(x);
						continue;
					}
					// Serial.println("m_string[x] > 47 && m_string[x] < 58");
					// Serial.print("position ");Serial.println(x);
					int expn = 1;
					for(int y = 0; y < c_size - x - 1; y++){
						expn *= 10;
					}
					output += (m_string[x] - 48) * expn;
				}else{
					// Serial.println("else");
					// Serial.print("position ");Serial.println(x);
					NoteLog(ame_Log_EndMethod, "toInt", "println", "");
					return 0;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "toInt", "println", "");
			return output;
		}

		long toLong() const {
			NoteLog(ame_Log_StartMethod, "toLong", "println", "");
			NoteLog(ame_Log_Statement, "toLong", "println", "~Note");
			long output = 0;
			int c_size = length(m_string);
			bool lastDecimals = false;
			for(int x = 0; x < c_size; x++){
				if(m_string[x] == 46){
					if(lastDecimals){
						NoteLog(ame_Log_EndMethod, "toLong", "println", "");
						return 0;
					}
					long expn = 10;
					for(int y = 0; y < c_size - x - 1; y++){
						expn *= 10;
					}
					output /= expn;
					lastDecimals = true;
					continue;
				}
				if(m_string[x] > 47 && m_string[x] < 58){
					if(lastDecimals){
						continue;
					}
					long expn = 1;
					for(int y = 0; y < c_size - x - 1; y++){
						expn *= 10;
					}
					output += (m_string[x] - 48) * expn;
				}else{
					NoteLog(ame_Log_EndMethod, "toLong", "println", "");
					return 0;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "toLong", "println", "");
			return output;
		}

		float toFloat(){
			NoteLog(ame_Log_StartMethod, "toFloat", "println", "");
			NoteLog(ame_Log_Statement, "toFloat", "println", "toFloat");
			float output = 0;
			int c_size = length(m_string);
			bool lastDecimals = false;
			int d_pos = 0;
			for(int x = 0; x < c_size; x++){
				if(m_string[x] == 46){
					if(lastDecimals){
						NoteLog(ame_Log_EndMethod, "toFloat", "println", "");
						return 0;
					}
					float expn = 10;
					for(int y = 0; y < c_size - x - 1; y++){
						expn *= 10;
					}
					output /= expn;
					lastDecimals = true;
					d_pos = x;
					continue;
				}
				if(m_string[x] > 47 && m_string[x] < 58){
					int expsize = c_size - x - 1;
					if(lastDecimals){
						expsize = x - d_pos;
					}
					// Serial.print("expsize ");Serial.println(expsize);
					float expn = 1;
					for(int y = 0; y < expsize; y++){
						expn *= 10;
					}
					if(lastDecimals){
						// Serial.println("divide");
						output += (m_string[x] - 48) / expn;
					}else{
						// Serial.println("mult");
						output += (m_string[x] - 48) * expn;
					}
					// Serial.println("m_string[x] > 47 && m_string[x] < 58");
					// Serial.print("value ");Serial.println(output);
					// Serial.print("position ");Serial.println(x);
				}else{
					// Serial.println("else");
					// Serial.print("position ");Serial.println(x);
					NoteLog(ame_Log_EndMethod, "toFloat", "println", "");
					return 0;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "toFloat", "println", "");
			return output;
		}

		bool toBool(){
			NoteLog(ame_Log_StartMethod, "toBool", "println", "");
			if(m_string == nullptr){
				NoteLog(ame_Log_Statement, "toBool", "println", "m_string == nullptr");
				return false;
			}
			
			if(m_pos == 1){
				NoteLog(ame_Log_Statement, "toBool", "println", "m_pos == 1");
				if(m_string[0] == '0'){
					NoteLog(ame_Log_EndMethod, "toBool", "println", "");
					return false;
				}
				if(m_string[0] == '1'){
					NoteLog(ame_Log_EndMethod, "toBool", "println", "");
					return true;
				}
			}
			
			if(m_pos == 3){
				NoteLog(ame_Log_Statement, "toBool", "println", "m_pos == 4");
				if( (m_string[0] == 'l' && m_string[1] == 'o' && m_string[2] == 'w') || 
					(m_string[0] == 'L' && m_string[1] == 'o' && m_string[2] == 'w') || 
					(m_string[0] == 'L' && m_string[1] == 'O' && m_string[2] == 'W') ){
					NoteLog(ame_Log_EndMethod, "toBool", "println", "");
					return false;
				}
			}
			
			if(m_pos == 4){
				NoteLog(ame_Log_Statement, "toBool", "println", "m_pos == 4");
				if( (m_string[0] == 't' && m_string[1] == 'r' && m_string[2] == 'u' && m_string[3] == 'e') || 
					(m_string[0] == 'T' && m_string[1] == 'r' && m_string[2] == 'u' && m_string[3] == 'e') || 
					(m_string[0] == 'T' && m_string[1] == 'R' && m_string[2] == 'U' && m_string[3] == 'E') ){
					NoteLog(ame_Log_EndMethod, "toBool", "println", "");
					return true;
				}
				if( (m_string[0] == 'h' && m_string[1] == 'i' && m_string[2] == 'g' && m_string[3] == 'h') || 
					(m_string[0] == 'H' && m_string[1] == 'i' && m_string[2] == 'g' && m_string[3] == 'h') || 
					(m_string[0] == 'H' && m_string[1] == 'I' && m_string[2] == 'G' && m_string[3] == 'H') ){
					NoteLog(ame_Log_EndMethod, "toBool", "println", "");
					return true;
				}
			}
			
			if(m_pos == 5){
				NoteLog(ame_Log_Statement, "toBool", "println", "m_pos == 5");
				if( (m_string[0] == 'f' && m_string[1] == 'a' && m_string[2] == 'l' && m_string[3] == 's' && m_string[4] == 'e') || 
					(m_string[0] == 'F' && m_string[1] == 'a' && m_string[2] == 'l' && m_string[3] == 's' && m_string[4] == 'e') || 
					(m_string[0] == 'F' && m_string[1] == 'A' && m_string[2] == 'L' && m_string[3] == 'S' && m_string[4] == 'E') ){
					NoteLog(ame_Log_EndMethod, "toBool", "println", "");
					return false;
				}
			}
				
			NoteLog(ame_Log_EndMethod, "toBool", "println", "Default");
			return false;
		}

#ifdef ame_ArduinoIDE

		IPAddress toIPAddress() const{
			const_NoteLog(ame_Log_StartMethod, "toIPAddress", "println", "");
			const_NoteLog(ame_Log_Statement, "toIPAddress", "println", "~Note");
			RawList<Note>* numbers = splitList('.', new PrimitiveRawList<Note>());

			if(numbers->getPosition() < 4){
				delete numbers;
				const_NoteLog(ame_Log_EndMethod, "toIPAddress", "println", "");
				return IPAddress(0,0,0,0);
			}
			
			int n_1 = numbers->getByPosition(0)->toInt();
			int n_2 = numbers->getByPosition(1)->toInt();
			int n_3 = numbers->getByPosition(2)->toInt();
			int n_4 = numbers->getByPosition(3)->toInt();
			
			IPAddress ip = IPAddress(n_1, n_2, n_3, n_4);

			delete numbers;
			
			
			const_NoteLog(ame_Log_EndMethod, "addLocal", "println", "");
			return ip;
		}
			
			
		String toString(){
			return String(m_string);
		}
#endif // ame_ArduinoIDE

		Note substring(int start){
			NoteLog(ame_Log_StartMethod, "substring", "println", "");
			NoteLog(ame_Log_Statement, "substring", "println", "~Note");
			if(m_pos <= 0){
				NoteLog(ame_Log_EndMethod, "substring", "println", "");
				return Note();
			}
			Note note;
			note.m_pos = m_pos - start;
			note.m_size = getAvailableSize(note.m_pos);
			char* buff = create(note.m_size);

			for(int x = start; x < m_pos; x++){
				buff[x - start] = m_string[x];
			}
			buff[note.m_pos] = '\0';

			note.m_string = buff;
			
			NoteLog(ame_Log_EndMethod, "substring", "println", "");

			return note;
		}

		Note substring(int start, int end){
			NoteLog(ame_Log_StartMethod, "substring", "println", "");
			NoteLog(ame_Log_Statement, "substring", "println", "~Note");
			int t_size = m_pos;
			if(t_size <= 0){
				NoteLog(ame_Log_EndMethod, "substring", "println", "");
				return Note();
			}
			int s_size = t_size - start;
			if(end < t_size){
				s_size -= t_size - end;
				t_size = end;
			}
			Note note;
			note.m_pos = s_size;
			note.m_size = getAvailableSize(note.m_pos);
			char* buff = create(note.m_size);

			for(int x = start; x < t_size; x++){
				buff[x - start] = m_string[x];
			}
			buff[s_size] = '\0';

			note.m_string = buff;
			
			NoteLog(ame_Log_EndMethod, "substring", "println", "");

			return note;
		}

		void toCharArray(char* c_pointer, int c_size){
			NoteLog(ame_Log_StartMethod, "toCharArray", "println", "");
			NoteLog(ame_Log_Statement, "toCharArray", "println", "~Note");
			if(c_pointer == nullptr){
				NoteLog(ame_Log_EndMethod, "toCharArray", "println", "");
				return;
			}
			if(c_size != this->getPosition() + 1){
				NoteLog(ame_Log_EndMethod, "toCharArray", "println", "");
				return;
			}
			for(int x = 0; x < c_size; x++){
				c_pointer[x] = m_string[x];
			}
			
			NoteLog(ame_Log_EndMethod, "toCharArray", "println", "");
		}

		void set(const Note& source){
			NoteLog(ame_Log_StartMethod, "set", "println", "");
			NoteLog(ame_Log_Statement, "set", "println", "~Note");
			if(source.isEmpty()){
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = nullptr;
				m_pos = 0;
				m_size = 0;
				NoteLog(ame_Log_EndMethod, "set", "println", "");
				return;
			}
			if(source.m_pos < m_pos){
				copy(m_string, source.m_string);
			}else{
				m_pos = source.getPosition();
				m_size = getAvailableSize(m_pos);
				m_string = create(m_size);
				copy(m_string, source.m_string);
			}
			
			NoteLog(ame_Log_EndMethod, "set", "println", "");
		}

		Note& operator=(const Note& source){
			NoteLog(ame_Log_StartMethod, "operator=", "println", "");
			NoteLog(ame_Log_Statement, "operator=", "println", "~Note");
			if(source.isEmpty()){
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = nullptr;
				m_pos = 0;
				m_size = 0;
				NoteLog(ame_Log_EndMethod, "operator=", "println", "");
				return *this;
			}
			if(source.m_pos < m_pos){
				copy(m_string, source.m_string);
			}else{
				m_pos = source.getPosition();
				m_size = getAvailableSize(m_pos);
				m_string = create(m_size);
				copy(m_string, source.m_string);
			}
			
			NoteLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
		Note operator=(const char* val){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const char* val");
			fix(m_string, m_pos, m_size);
			erase(m_string);
			m_string = nullptr;
			m_pos = 0;
			m_size = 0;
			if(val != nullptr){
				int lth = length(val);
				NoteLog(ame_Log_Statement, "Constructor", "println", lth);
				if(lth > 0){
					m_pos = lth;
					m_size = getAvailableSize(lth);
					NoteLog(ame_Log_Statement, "Constructor", "println", m_size);
					m_string = create(m_size);
					copy(m_string, val);
					NoteLog(ame_Log_Statement, "Constructor", "println", m_string);
				}
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
			return *this;
		}
		// void operator=(const char& i);
		// void operator=(const int& i);
		// void operator=(const long& i);
		// void operator=(Note note);
		Note operator+(const Note& note){
			NoteLog(ame_Log_StartMethod, "operator+", "println", "");
			NoteLog(ame_Log_Statement, "operator+", "println", "~Note");
			if(note.isEmpty()){
				NoteLog(ame_Log_EndMethod, "operator+", "println", "");
				return Note(m_string);
			}
			if(isEmpty()){
				NoteLog(ame_Log_EndMethod, "operator+", "println", "");
				return Note(note);
			}
			int l_size = m_pos + note.getPosition();
			
			Note m_note;
			m_note.m_pos = l_size;
			m_note.m_size = getAvailableSize(m_note.m_pos);

			char* buff = create(m_note.m_size);

			copy(buff, m_string);
			concat(buff, note.m_string);

			m_note.m_string = buff;
			
			NoteLog(ame_Log_EndMethod, "operator+", "println", "");
			return m_note;
		}
		// Note operator+(const char& chr);
		// Note operator+(const char* chr);
		Note& operator+=(const Note& value){
			NoteLog(ame_Log_StartMethod, "operator+=", "println", "");
			NoteLog(ame_Log_Statement, "operator+=", "println", "~Note");
			if(value.isEmpty()){
				NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
				return *this;
			}
			if(isEmpty()){
				m_pos = value.m_pos;
				m_size = getAvailableSize(m_pos);

				m_string = create(m_size);

				copy(m_string, value.m_string);
				NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
				return *this;
			}
			int l_size = m_pos + value.m_pos;
			
			if(l_size >= m_size){
				m_pos = l_size;
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			concat(m_string, value.m_string);
			
			NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
			return *this;
		}

		Note& operator+=(const char* value){
			NoteLog(ame_Log_StartMethod, "operator+=", "println", "");
			NoteLog(ame_Log_Statement, "operator+=", "println", "const char* value");
			int v_size = length(value);
			if(v_size == 0){
				NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
				return *this;
			}
			
			if(isEmpty()){
				m_pos = v_size;
				m_size = getAvailableSize(m_pos);

				m_string = create(m_size);

				copy(m_string, value);
				NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
				return *this;
			}
			int l_size = m_pos + v_size;
			
			if(l_size >= m_size){
				m_pos = l_size;
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			concat(m_string, value);
			
			NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
			return *this;
		}

		Note& operator+=(const char& value){
			NoteLog(ame_Log_StartMethod, "operator+=", "println", "");
			NoteLog(ame_Log_Statement, "operator+=", "println", "const char& value");
			m_pos += 1;
			
			if(m_pos >= m_size){
				m_size = getAvailableSize(m_pos);
				char* buff = create(m_size);
				copy(buff, m_string);
				fix(m_string, m_pos, m_size);
				erase(m_string);
				m_string = buff;
			}
			
			m_string[m_pos - 1] = value;
			m_string[m_pos] = '\0';
			
			NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
			return *this;
		}
		// void operator<(const char* chr);
		// void operator<<(const char* chr);
		bool operator==(const Note& note){
			NoteLog(ame_Log_StartMethod, "operator==", "println", "");
			NoteLog(ame_Log_Statement, "operator==", "println", "~Note");
			if(isEmpty() && note.isEmpty()){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return true;
			}
			if(m_string == note.m_string){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return true;
			}
			if(length() != note.length()){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return false;
			}
			for(int x = 0; x < length(); x++){
				if(m_string[x] != note.m_string[x]){
					NoteLog(ame_Log_EndMethod, "operator==", "println", "");
					return false;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "operator==", "println", "");
			return true;
		}
		bool operator!=(const Note& note){
			NoteLog(ame_Log_StartMethod, "operator!=", "println", "");
			NoteLog(ame_Log_Statement, "operator!=", "println", "~Note");
			if(isEmpty() && note.isEmpty()){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return false;
			}
			if(m_string == note.m_string){
				NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
				return false;
			}
			if(length() != note.length()){
				NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
				return true;
			}
			for(int x = 0; x < length(); x++){
				if(m_string[x] != note.m_string[x]){
					NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
					return true;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
			return false;
		}

		bool operator==(const char* chr){
			NoteLog(ame_Log_StartMethod, "operator==", "println", "");
			NoteLog(ame_Log_Statement, "operator==", "println", "const char* chr");
			if(isEmpty() && length(chr) <= 0){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return true;
			}
			if(chr == m_string){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return true;
			}
			int c_length = length(chr);
			int s_length = length(m_string);
			if(c_length != s_length){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return false;
			}
			for(int x = 0; x < s_length; x++){
				if(chr[x] != m_string[x]){
					NoteLog(ame_Log_EndMethod, "operator==", "println", "");
					return false;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "operator==", "println", "");
			return true;
		}
		bool operator!=(const char* chr){
			NoteLog(ame_Log_StartMethod, "operator!=", "println", "");
			NoteLog(ame_Log_Statement, "operator!=", "println", "const char* chr");
			if(isEmpty() && length(chr) <= 0){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return false;
			}
			if(chr == m_string){
				NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
				return false;
			}
			int c_length = length(chr);
			int s_length = length(m_string);
			if(c_length != s_length){
				NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
				return true;
			}
			for(int x = 0; x < s_length; x++){
				if(chr[x] != m_string[x]){
					NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
					return true;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
			return false;
		}

		bool operator==(const char& chr){
			NoteLog(ame_Log_StartMethod, "operator==", "println", "");
			NoteLog(ame_Log_Statement, "operator==", "println", "const char& chr");
			if(m_pos != 1){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return false;
			}
			if(chr != m_string[0]){
				NoteLog(ame_Log_EndMethod, "operator==", "println", "");
				return false;
			}
			
			NoteLog(ame_Log_EndMethod, "operator==", "println", "");
			return true;
		}
		bool operator!=(const char& chr){
			NoteLog(ame_Log_StartMethod, "operator!=", "println", "");
			NoteLog(ame_Log_Statement, "operator!=", "println", "const char& chr");
			if(m_pos != 1){
				NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
				return true;
			}
			if(chr != m_string[0]){
				NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
				return true;
			}
			
			NoteLog(ame_Log_EndMethod, "operator!=", "println", "");
			return false;
		}
		// void operator+=(const char& chr);
		// void operator+=(const String& s);
		
		void reset(){
			NoteLog(ame_Log_StartMethod, "reset", "println", "");
			NoteLog(ame_Log_Statement, "reset", "println", "");
			if(m_pos != 0 && m_string != nullptr){
				m_string[0] = '\0';
				m_pos = 0;
				m_size = 0;
			}
			
			NoteLog(ame_Log_EndMethod, "reset", "println", "");
		}
		
		void clear(){
			NoteLog(ame_Log_StartMethod, "clear", "println", "");
			NoteLog(ame_Log_Statement, "clear", "println", "~Note");
			fix(m_string, m_pos, m_size);
			erase(m_string);
			m_string = nullptr;
			m_pos = 0;
			m_size = 0;
			
			NoteLog(ame_Log_EndMethod, "clear", "println", "");
		}
		
		RawList<Note>* splitList(char chr, RawList<Note>* a_list) const{
			const_NoteLog(ame_Log_StartMethod, "splitList", "println", "");
			const_NoteLog(ame_Log_Statement, "splitList", "println", "~Note");
			RawList<Note>* list = a_list;
			Note n;
			for(int x = 0; x < m_pos; x++){
				char c = m_string[x];
				if(c == chr){
					list->add(n);
					n = "";
					continue;
				}
				n += c;
				if(x == m_pos - 1){
					list->add(n);
				}
			}
				
			const_NoteLog(ame_Log_EndMethod, "splitList", "println", "");
			return list;
		}
		
		Note split(int arg, char splitChar){
			NoteLog(ame_Log_StartMethod, "split", "println", "");
			NoteLog(ame_Log_Statement, "split", "println", "");
			Note c = "";
			bool init = true;
			int gcmd = 0;
			for(int x = 0; x < length(); x++){
				char cr = charAt(x);
				if(cr == splitChar){
					if(gcmd == arg){
						return c;
					}
					c = "";
					gcmd++;
					continue;
				}
				c.concat(cr);
			}
			if(gcmd == arg){
				return c;
			}
			
			NoteLog(ame_Log_EndMethod, "split", "println", "");
			return "";
		}
		
		Note splitNote(int arg, Note splitNote){
			NoteLog(ame_Log_StartMethod, "split", "println", "");
			NoteLog(ame_Log_Statement, "split", "println", "");
			Note c = "";
			bool init = true;
			int gcmd = 0;
			int splitPos = 0;
			for(int x = 0; x < length(); x++){
				char cr = charAt(x);
				char sChar = splitNote.charAt(splitPos);
				if(cr == sChar){
					if(splitPos >= splitNote.length()){
						if(gcmd == arg){
							NoteLog(ame_Log_EndMethod, "split", "println", "");
							return c.substring(0,splitPos);
						}
					}else{
						c = "";
						splitPos++;
					}
				}else{
					splitPos = 0;
				}
				if(x == length() - 1){
					NoteLog(ame_Log_EndMethod, "split", "println", "");
					return c.substring(0,splitPos);
				}
				c.concat(cr);
			}
			
			NoteLog(ame_Log_EndMethod, "split", "println", "");
			return "";
		}
		
		void addLine(Note a_line){
			NoteLog(ame_Log_StartMethod, "addLine", "println", "");
			NoteLog(ame_Log_Statement, "addLine", "println", "");
			addLocal('\n');
			addLocal(a_line);
			
			NoteLog(ame_Log_EndMethod, "addLine", "println", "");
		}
		
		int getOrder(Note t, char split, char end){
			NoteLog(ame_Log_StartMethod, "getOrder", "println", "");
			NoteLog(ame_Log_Statement, "getOrder", "println", "");
			Note c = "";
			bool init = true;
			int gcmd = 0;
			for(int x = 0; x < length(); x++){
				char cr = charAt(x);
				if(cr == end){
					init = true;
					if(t == c){
						NoteLog(ame_Log_EndMethod, "getOrder", "println", "");
						return gcmd;
					}
					gcmd++;
					c = "";
					continue;
				}
				if(init){
					if(cr == split){
						if(t == c){
							NoteLog(ame_Log_EndMethod, "getOrder", "println", "");
							return gcmd;
						}
						init = false;
						continue;
					}
					c.addLocal(cr);
				}
			}
			
			NoteLog(ame_Log_EndMethod, "getOrder", "println", "");
			return -1;
		}
		
		int getSplitSize(char split){
			NoteLog(ame_Log_StartMethod, "getSplitSize", "println", "");
			NoteLog(ame_Log_Statement, "getSplitSize", "println", "~Note");
			if(m_pos == 0){
				return 0;
			}
			int gcmd = 1;
			for(int x = 0; x < m_pos; x++){
				char cr = charAt(x);
				if(cr == split){
					gcmd++;
					continue;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "getSplitSize", "println", "");
			return gcmd;
		}
		
		int getSizeNoStartNoEnd(char split){
			NoteLog(ame_Log_StartMethod, "getSizeNoStartNoEnd", "println", "");
			NoteLog(ame_Log_Statement, "getSizeNoStartNoEnd", "println", "~Note");
			int gcmd = 0;
			for(int x = 0; x < length(); x++){
				char cr = charAt(x);
				if(cr == split){
					gcmd++;
					continue;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "getSizeNoStartNoEnd", "println", "");
			return gcmd + 1;
		}
		
		int getLineSize(){
			NoteLog(ame_Log_StartMethod, "getLineSize", "println", "");
			NoteLog(ame_Log_Statement, "getLineSize", "println", "");
			int gcmd = 0;
			int x_c = 0;
			for(int x = 0; x < getPosition(); x++){
				char cr = charAt(x);
				if(cr == '\n'){
					gcmd++;
					x_c = 0;
					continue;
				}
				x_c++;
			}
			if(x_c == 0){
				return gcmd;
			}
			if(x_c > 0){
				return gcmd + 1;
			}
			NoteLog(ame_Log_EndMethod, "getLineSize", "println", "");
			return gcmd;
		}
		
		Note getLine(int l, char end){
			NoteLog(ame_Log_StartMethod, "getLine", "println", "");
			NoteLog(ame_Log_Statement, "getLine", "println", "");
			Note c = "";
			int gcmd = 0;
			for(int x = 0; x < length(); x++){
				char cr = charAt(x);
				if(cr == end){
					if(gcmd == l){
						NoteLog(ame_Log_EndMethod, "getLine", "println", "");
						return c;
					}
					c = "";
					gcmd++;
					continue;
				}
				c.addLocal(cr);
			}
			
			NoteLog(ame_Log_EndMethod, "getLine", "println", "");
			return "";
		}
		
		void removeLine(int line, char end){
			NoteLog(ame_Log_StartMethod, "removeLine", "println", "");
			NoteLog(ame_Log_Statement, "removeLine", "println", "");
			if(line == -1){
				NoteLog(ame_Log_EndMethod, "removeLine", "println", "");
				return;
			}
			Note newTxt = "";
			int xLine = 0;
			for(int x = 0; x < length(); x++){
				char ctext = charAt(x);
				if(ctext == end){
					xLine++;
					if(newTxt == ""){
						continue;
					}
					char cnewTxt = newTxt.charAt(newTxt.length()-1);
					if(newTxt != "" && cnewTxt != end){
						newTxt.addLocal(end);
					}
					continue;
				}
				if(xLine != line){
					newTxt.addLocal(ctext);
				}
			}
			
			NoteLog(ame_Log_EndMethod, "removeLine", "println", "");
			set(newTxt);
		}
		
		void removeLine(Note txt, char split, char end){
			NoteLog(ame_Log_StartMethod, "removeLine", "println", "");
			NoteLog(ame_Log_Statement, "removeLine", "println", "~Note");
			int cmdO = getOrder(txt, split, end);
			if(cmdO == -1){
				NoteLog(ame_Log_EndMethod, "removeLine", "println", "");
				return;
			}
			removeLine(cmdO, end);
			
			NoteLog(ame_Log_EndMethod, "removeLine", "println", "");
		}
		
		void writeLine(int line, Note txt, char end){
			NoteLog(ame_Log_StartMethod, "writeLine", "println", "");
			NoteLog(ame_Log_Statement, "writeLine", "println", "");
			Note newTxt = "";
			int xLine = 0;
			int xTxt = 0;
			int xText = 0;
			for(int x = 0; x < length() + txt.length(); x++){
				char ctext = charAt(xText);
				char ctxt = txt.charAt(xTxt);
				if(ctext == end){
					xLine++;
					xText++;
					newTxt.addLocal(end);
					continue;
				}
				if((xLine == line || xText >= length())){
					newTxt.addLocal(ctxt);
					xTxt++;
					if(xTxt == txt.length()){
						newTxt.addLocal('\n');
						xLine++;
					}
				}else{
					newTxt.addLocal(ctext);
					xText++;
				}
			}
			set(newTxt);
			
			NoteLog(ame_Log_EndMethod, "writeLine", "println", "");
		}
		
		void writeLine(Note cmdt, Note txt, char split, char end){
			NoteLog(ame_Log_StartMethod, "writeLine", "println", "");
			NoteLog(ame_Log_Statement, "writeLine", "println", "~Note");
			int line = getOrder(cmdt, split, end);
			if(line == -1){
				NoteLog(ame_Log_EndMethod, "writeLine", "println", "");
				return;
			}
			writeLine(line, txt, end);
			removeLine(line + 1, end);
			
			NoteLog(ame_Log_EndMethod, "writeLine", "println", "");
		}
		
		Note getCommand(int l, char split, char end){
			NoteLog(ame_Log_StartMethod, "getCommand", "println", "");
			NoteLog(ame_Log_Statement, "getCommand", "println", "~Note");
			Note c = "";
			bool init = true;
			int gcmd = 0;
			for(int x = 0; x < length(); x++){
				char cr = charAt(x);
				if(cr == end){
					if(gcmd == l){
						NoteLog(ame_Log_EndMethod, "getCommand", "println", "");
						return c;
					}
					init = true;
					gcmd++;
					c = "";
					continue;
				}
				if(init){
					if(cr == split){
						if(gcmd == l){
							NoteLog(ame_Log_EndMethod, "getCommand", "println", "");
							return c;
						}
						init = false;
						c = "";
						continue;
					}
					c.addLocal(cr);
				}
			}
			
			NoteLog(ame_Log_EndMethod, "getCommand", "println", "");
			return "";
		}
		
		Note getArgument(int l, char split, char end){
			NoteLog(ame_Log_StartMethod, "getArgument", "println", "");
			NoteLog(ame_Log_Statement, "getArgument", "println", "~Note");
			Note c = "";
			bool init = false;
			int gcmd = 0;
			for(int x = 0; x < length(); x++){
				char cr = charAt(x);
				if(cr == end){
					if(gcmd == l){
						NoteLog(ame_Log_EndMethod, "getArgument", "println", "");
						return c;
					}
					gcmd++;
					c = "";
					init = false;
					continue;
				}
				if(cr == split && !init){
					init = true;
					continue;
				}
				if(init && gcmd == l){
					c.addLocal(cr);
				}
			}
			if(gcmd == l){
				NoteLog(ame_Log_EndMethod, "getArgument", "println", "");
				return c;
			}
			
			NoteLog(ame_Log_EndMethod, "getArgument", "println", "");
			return "";
		}
		
		int getSize(char split){
			NoteLog(ame_Log_StartMethod, "getSize", "println", "");
			NoteLog(ame_Log_Statement, "getSize", "println", "");
			int gcmd = -1;
			for(int x = 0; x < length(); x++){
				char cr = charAt(x);
				if(cr == split){
					if(gcmd == -1){
						gcmd = 0;
					}
					gcmd++;
					continue;
				}
			}
			
			NoteLog(ame_Log_EndMethod, "getSize", "println", "");
			return gcmd;
		}
		
		void replace(Note a_search, Note a_change){
			NoteLog(ame_Log_StartMethod, "replace", "println", "");
			NoteLog(ame_Log_Statement, "replace", "println", "");
			Note i_note;
			Note i_search;
			int i_search_index = 0;
			
			if(isEmpty()){
				return;
			}
			
			NoteLog(ame_Log_Statement, "replace", "println", "start for");
			for(int x = 0; x < m_pos; x++){
				NoteLog(ame_Log_Statement, "replace", "println", ame_String("iteration ") + ame_String(x));
				char cr = charAt(x);
				char schr = a_search.charAt(i_search_index);
				NoteLog(ame_Log_Statement, "replace", "println", ame_String("notes char: ") + ame_String((char)cr));
				NoteLog(ame_Log_Statement, "replace", "println", ame_String("searche char: ") + ame_String((char)schr));
				if(schr == cr){
					NoteLog(ame_Log_Statement, "replace", "println", "schr == cr");
					i_search_index++;
					i_search += schr;
				}else{
					NoteLog(ame_Log_Statement, "replace", "println", "schr != cr");
					if(i_search_index > 0){
						NoteLog(ame_Log_Statement, "replace", "println", "i_search_index > 0");
						i_search_index = 0;
						i_note += i_search;
						i_search = "";
					}
					i_note += cr;
				}
				if(i_search_index == a_search.getPosition()){
					NoteLog(ame_Log_Statement, "replace", "println", "i_search_index == a_search.getPosition() - 1");
					i_search_index = 0;
					i_search = "";
					i_note += a_change;
				}
			}
			NoteLog(ame_Log_Statement, "replace", "println", "end for");
			
			fix(m_string, m_pos, m_size);
			erase(m_string);
			m_string = i_note.m_string;
			m_pos = i_note.m_pos;
			m_size = i_note.m_size;
			i_note.m_string = nullptr;
			i_note.m_pos = 0;
			i_note.m_size = 0;
			return;
		}
		
		void removeAll(Note a_remove){
			NoteLog(ame_Log_StartMethod, "removeAll", "println", "");
			NoteLog(ame_Log_Statement, "removeAll", "println", "");
			
			if(isEmpty()){
				return;
			}
			
			Note i_note;
			Note i_remove;
			int i_remove_index = 0;
			
			NoteLog(ame_Log_Statement, "removeAll", "println", "start for");
			for(int x = 0; x < m_pos; x++){
				NoteLog(ame_Log_Statement, "removeAll", "println", ame_String("iteration ") + ame_String(x));
				char cr = charAt(x);
				char schr = a_remove.charAt(i_remove_index);
				NoteLog(ame_Log_Statement, "removeAll", "println", ame_String("notes char: ") + ame_String((char)cr));
				NoteLog(ame_Log_Statement, "removeAll", "println", ame_String("searche char: ") + ame_String((char)schr));
				if(schr == cr){
					NoteLog(ame_Log_Statement, "removeAll", "println", "schr == cr");
					i_remove_index++;
					i_remove += schr;
				}else{
					NoteLog(ame_Log_Statement, "removeAll", "println", "schr != cr");
					if(i_remove_index > 0){
						NoteLog(ame_Log_Statement, "removeAll", "println", "i_remove_index > 0");
						i_remove_index = 0;
						i_note += i_remove;
						i_remove = "";
					}
					i_note += cr;
				}
				if(i_remove_index == a_remove.getPosition()){
					NoteLog(ame_Log_Statement, "removeAll", "println", "i_remove_index == a_remove.getPosition() - 1");
					i_remove_index = 0;
					i_remove = "";
				}
			}
			NoteLog(ame_Log_Statement, "removeAll", "println", "end for");
			
			fix(m_string, m_pos, m_size);
			erase(m_string);
			m_string = i_note.m_string;
			m_pos = i_note.m_pos;
			m_size = i_note.m_size;
			i_note.m_string = nullptr;
			i_note.m_pos = 0;
			i_note.m_size = 0;
			return;
		}

		static int intCharSize(int value){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "intCharSize", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "intCharSize", "println", "");
			int i_size_val = 0;
			int x = 1;
			int add_x = 0;
			if(value < 0){
				// Serial.println("negative int");
				value *= -1;
				add_x++;
				// Serial.print("size capture: ");Serial.println(x);
			}
			for( ; x < 100; x++){
				// Serial.print("size capture: ");Serial.println(x);
				int expn = 1;
				for(int y = 0; y < x; y++){
					expn *= 10;
				}

				// Serial.print("expn: ");Serial.println(expn);
				// Serial.print("value/expn: ");Serial.println(value/expn);
				if(value/expn < 1){
					i_size_val = x;
					break;
				}
			}
				// Serial.print("i_size_val capture: ");Serial.println(i_size_val);

			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "intCharSize", "println", "");
			return i_size_val + add_x;
		}

		static void intToCharPointer(int value, int size, int start, char* chr, bool end){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "intToCharPointer", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "intToCharPointer", "println", "");
			if(chr == nullptr){
				StaticNoteLog(nullptr, ame_Log_EndMethod, "intToCharPointer", "println", "");
				return;
			}
			int position = start;
			bool isNegative = false;
			if(value < 0){
				isNegative = true;
				value *= -1;
				size--;
				chr[position] = 45;
				position++;
			}
			int n_value = 1;
			int r_value = 1;
			int s_value = 1;
			for(int x = 0; x < size; x++){
				int expn = 1;
				for(int y = 0; y < size - x - 1; y++){
					expn *= 10;
				}
				n_value = value / expn;
				if(x == 0){
					s_value = n_value;
				}else{
					s_value = n_value - r_value;
				}
				r_value = n_value * 10;
				// Serial.print("expn ");Serial.println(expn);
				// Serial.print("n_value ");Serial.println(n_value);
				// Serial.print("r_value ");Serial.println(r_value);
				// Serial.print("s_value ");Serial.println(s_value);
				chr[position] = s_value + 48;
				position++;
			}
			if(end){
				// Serial.print("adding last char at position ");Serial.println(position);
				chr[position] = '\0';
			}
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "intToCharPointer", "println", "");
		}

		static int longCharSize(long value){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "longCharSize", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "longCharSize", "println", "");
			int i_size_val = 0;
			int x = 1;
			int add_x = 0;
			if(value < 0){
				// Serial.println("negative int");
				value *= -1;
				add_x++;
				// Serial.print("size capture: ");Serial.println(x);
			}
			for( ; x < 100; x++){
				// Serial.print("size capture: ");Serial.println(x);
				long expn = 1;
				for(int y = 0; y < x; y++){
					expn *= 10;
				}

				// Serial.print("expn: ");Serial.println(expn);
				// Serial.print("value/expn: ");Serial.println(value/expn);
				if(value/expn < 1){
					i_size_val = x;
					break;
				}
			}
				// Serial.print("i_size_val capture: ");Serial.println(i_size_val);

			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "longCharSize", "println", "");
			return i_size_val + add_x;
		}

		static void longToCharPointer(long value, int size, int start, char* chr, bool end){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "longToCharPointer", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "longToCharPointer", "println", "~Note");
			if(chr == nullptr){
				StaticNoteLog(nullptr, ame_Log_EndMethod, "longToCharPointer", "println", "");
				return;
			}
				// Serial.print("input ");Serial.println(value);
			int position = start;
			bool isNegative = false;
			if(value < 0){
				isNegative = true;
				value *= -1;
				size--;
				chr[position] = 45;
				position++;
			}
			long n_value = 1;
			long r_value = 1;
			long s_value = 1;
			for(int x = 0; x < size; x++){
				long expn = 1;
				for(int y = 0; y < size - x - 1; y++){
					expn *= 10;
				}
				n_value = value / expn;
				if(x == 0){
					s_value = n_value;
				}else{
					s_value = n_value - r_value;
				}
				r_value = n_value * 10;
				// Serial.print("expn ");Serial.println(expn);
				// Serial.print("n_value ");Serial.println(n_value);
				// Serial.print("r_value ");Serial.println(r_value);
				// Serial.print("s_value ");Serial.println(s_value);
				chr[position] = s_value + 48;
				position++;
			}
			if(end){
				chr[position] = '\0';
			}
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "longToCharPointer", "println", "");
		}

		static int floatCharSize(float value,int extra){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "floatCharSize", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "floatCharSize", "println", "");
			int i_size_val = 0;
			int x = 1;
			int add_x = 0;
			if(value < 0){
				// Serial.println("negative int");
				value *= -1;
				add_x++;
				// Serial.print("size capture: ");Serial.println(x);
			}
			for( ; x < 100; x++){
				// Serial.print("size capture: ");Serial.println(x);
				int expn = 1;
				for(int y = 0; y < x; y++){
					expn *= 10;
				}

				// Serial.print("expn: ");Serial.println(expn);
				// Serial.print("value/expn: ");Serial.println(value/expn);
				if(value/expn < 1){
					i_size_val = x;
					break;
				}
			}
				// Serial.print("i_size_val capture: ");Serial.println(i_size_val);

			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "floatCharSize", "println", "");
			return i_size_val + add_x + extra + 1;
		}

		static void floatToCharPointer(float value, int total_size, int start, int decimal_size, char* chr, bool end){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "floatToCharPointer", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "floatToCharPointer", "println", "");
			if(chr == nullptr){
				StaticNoteLog(nullptr, ame_Log_EndMethod, "floatToCharPointer", "println", "");
				return;
			}
			int position = start;
			bool isNegative = false;
			if(value < 0){
				isNegative = true;
				value *= -1;
				total_size--;
				chr[position] = 45;
				position++;
			}
			int n_value = 1;
			int r_value = 1;
			int s_value = 1;
			int i_size = total_size - decimal_size - 1;
			for(int x = 0; x < i_size; x++){
				int expn = 1;
				for(int y = 0; y < i_size - x - 1; y++){
					expn *= 10;
				}
				n_value = value / expn;
				if(x == 0){
					s_value = n_value;
				}else{
					s_value = n_value - r_value;
				}
				r_value = n_value * 10;
				// Serial.print("expn ");Serial.println(expn);
				// Serial.print("n_value ");Serial.println(n_value);
				// Serial.print("r_value ");Serial.println(r_value);
				// Serial.print("s_value ");Serial.println(s_value);
				chr[position] = s_value + 48;
				position++;
			}

			chr[position] = 46;
			// Serial.print("chr[position] ");Serial.println(chr[position]);
			position++;

			n_value = 1;
			r_value = 1;
			s_value = 1;
			float i_value = value - (int)value;
			for(int x = 0; x < decimal_size; x++){
				int expn = 10;
				for(int y = 0; y < x; y++){
					expn *= 10;
				}
				n_value = i_value * expn;
				if(x == 0){
					s_value = n_value;
				}else{
					s_value = n_value - r_value;
				}
				r_value = n_value * 10;
				// Serial.print("expn ");Serial.println(expn);
				// Serial.print("n_value ");Serial.println(n_value);
				// Serial.print("r_value ");Serial.println(r_value);
				// Serial.print("s_value ");Serial.println(s_value);
				chr[position] = s_value + 48;
				// Serial.print("chr[position] ");Serial.println(chr[position]);
				position++;
			}
			if(end){
				chr[position] = '\0';
			}
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "floatToCharPointer", "println", "");
		}

		static int byteCharSize(int a_type, byte a_byte){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "byteCharSize", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "byteCharSize", "println", "");
			if(a_type == ame_DECIMAL){
				return intCharSize((int)a_byte);
			}
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "byteCharSize", "println", "");
			return 0;
		}

		static void byteToCharPointer(byte value, int total_size, int start, char* chr, int a_type, bool end){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "byteToCharPointer", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "byteToCharPointer", "println", "");
			if(a_type == ame_DECIMAL){
				intToCharPointer((int)value, total_size, start, chr, end);
			}
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "byteToCharPointer", "println", "");
		}

		static int length(const char* i_char){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "length", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "length", "println", ame_String(i_char));
			if(i_char == nullptr){
				// Serial.println("i_char == nullptr");
				StaticNoteLog(nullptr, ame_Log_EndMethod, "length", "println", "");
				return -1;
			}
			int in_size = 0;
			while(i_char[in_size] != '\0'){
				if(in_size > 1000){
					StaticNoteLog(nullptr, ame_Log_EndMethod, "length", "println", "");
					return -2;
				}
				in_size++;
			}
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "length", "println", "");
			return in_size;
		}

		static void copy(char* n_char, const char* i_char){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "copy", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "copy", "println", ame_String(n_char) + ame_String(" ") + ame_String(i_char));
			if(n_char == nullptr || i_char == nullptr){
				// Serial.println("n_char == nullptr || i_char == nullptr");
				StaticNoteLog(nullptr, ame_Log_EndMethod, "copy", "println", "");
				return;
			}
			int position = 0;
			while(i_char[position] != '\0'){
				n_char[position] = i_char[position];
				position++;
			}
			n_char[position] = '\0';
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "copy", "println", "");
		}

		static void concat(char* n_char, const char* i_char){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "concat", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "concat", "println", "");
			if(n_char == nullptr || i_char == nullptr){
				// Serial.println("n_char == nullptr || i_char == nullptr");
				StaticNoteLog(nullptr, ame_Log_EndMethod, "concat", "println", "");
				return;
			}
			int position = 0;
			int position_2 = 0;
			bool startConcat = false;
			while(i_char[position_2] != '\0'){
				if(n_char[position] == '\0'){
					startConcat = true;
				}
				if(startConcat){
					n_char[position] = i_char[position_2];
					position_2++;
				}
				position++;
			}
			n_char[position] = '\0';
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "concat", "println", "");
		}

		#if defined(MemoryPool_AVAILABLE)
		static MemoryPool* pool(MemoryPool* ci_pool){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "pool", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "pool", "println", "");
			m_Pool = ci_pool;
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "pool", "println", "");
			return m_Pool;
		}
		#endif
		
		static char* create(int ci_size){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "create", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "create", "println", "");
			#if defined(MemoryPool_AVAILABLE)
			if(Memory::manager != nullptr){
				if(m_Pool == nullptr){
					// m_Pool = Memory::manager->createMemoryPool<CharMemoryPool>(0, sizeof(char) * 20 *100);
				}
				// return m_Pool->newInstance<char>(ci_size + 1);
			}
			#endif
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "create", "println", "");
			return new char[ci_size + 1];
		}
		
		static void erase(char* chr){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "erase", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "erase", "println", "");
			if(chr == nullptr){
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "erase", "println", "");
				StaticNoteLog(nullptr, ame_Log_EndMethod, "erase", "println", "");
				return;
			}
			#if defined(MemoryPool_AVAILABLE)
			if(Memory::manager != nullptr){
				if(m_Pool == nullptr){
					delete[] chr;
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "erase", "println", "");
					StaticNoteLog(nullptr, ame_Log_EndMethod, "erase", "println", "");
					return;
				}
				m_Pool->recycle(chr);
				StaticNoteLog(nullptr, ame_Log_EndMethod, "erase", "println", "");
				return;
			}
			#endif
			delete[] chr;
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "erase", "println", "");
		}
		
		static void clear(char* chr, int stop){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "clear", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "clear", "println", "");
			if(chr == nullptr){
				StaticNoteLog(nullptr, ame_Log_EndMethod, "clear", "println", "");
				return;
			}
			for(int x = 0; x < stop; x++){
				chr[x] = '\0';
			}
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "clear", "println", "");
		}
		
		static void fill(char* chr, char a_fill, int stop){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "fill", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "fill", "println", "");
			// if(chr == nullptr){
				// return;
			// }
			// for(int x = 0; x < stop - 1; x++){
				// chr[x] = a_fill;
			// }
			// chr[stop - 1] = '\0';
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "fill", "println", "");
		}
		
		static void fix(char* chr, int a_pos, int a_size){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "fix", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "fix", "println", "");
			StaticNoteLog(nullptr, 0, "fix", "println", "");
			StaticNoteLog(nullptr, 0, "fix", "println", a_pos);
			StaticNoteLog(nullptr, 0, "fix", "println", a_size);
			if(chr == nullptr){
				StaticNoteLog(nullptr, 0, "fix", "println", "chr == nullptr");
			}else{
				StaticNoteLog(nullptr, 0, "fix", "println", chr);
			}
			// if(chr == nullptr){
				// return;
			// }
			// for(int x = 0; x < stop - 1; x++){
				// chr[x] = a_fill;
			// }
			// chr[stop - 1] = '\0';
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "fix", "println", "");
		}
		
		static int getAvailableSize(int input_Size){
			StaticNoteLog(nullptr, ame_Log_StartMethod, "getAvailableSize", "println", "");
			StaticNoteLog(nullptr, ame_Log_Statement, "getAvailableSize", "println", "");
			// if(input_Size == 0){
				// return 5;
			// }
			// if(input_Size < 10){
				// return 10;
			// }
			// if(input_Size < 20){
				// return 20;
			// }
			// if(input_Size < 30){
				// return 30;
			// }
			// if(input_Size < 40){
				// return 40;
			// }
			// if(input_Size < 200){
				// return 200;
			// }
			// if(input_Size < 1000){
				// return 1000;
			// }
			// if(input_Size < 2000){
				// return 2000;
			// }
			// return 5;
			
			StaticNoteLog(nullptr, ame_Log_EndMethod, "getAvailableSize", "println", "");
			return input_Size;
		}
};

#if defined(MemoryPool_AVAILABLE)
MemoryPool* Note::m_Pool = nullptr;
#endif

}

#endif

#ifndef Note_Method_Helper_hpp
#define Note_Method_Helper_hpp

#ifdef NoteMethods_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define NoteMethodsLog(location,method,type,mns) ame_Log(this,location,"Note",method,type,mns)
	#define const_NoteMethodsLog(location,method,type,mns) 
	#define StaticNoteMethodsLog(pointer,location,method,type,mns) ame_Log(pointer,location,"Note",method,type,mns)
#else
	#ifdef NoteMethods_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define NoteMethodsLog(location,method,type,mns) ame_LogDebug(this,location,"Note",method,type)
		#define const_NoteMethodsLog(location,method,type,mns) 
		#define StaticNoteMethodsLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"Note",method,type)
	#else
		#define NoteMethodsLog(location,method,type,mns) 
		#define const_NoteMethodsLog(location,method,type,mns) 
		#define StaticNoteMethodsLog(pointer,location,method,type,mns) 
	#endif
#endif

	
	#if defined(Note_AVAILABLE)
	namespace ame{
		#if defined(ame_ArduinoIDE)
		IPAddress toIPAddress(const Note& note){
			int i_pos = 0;
			Note container;
			
			int n_1 = 0;
			int n_2 = 0;
			int n_3 = 0;
			int n_4 = 0;
			
			for(int x = 0; x < note.length(); x++){
				char i_char = note.charAt(x);
				if(i_char == '.'){
					if(i_pos == 0){
						n_1 = container.toInt();
					}
					if(i_pos == 1){
						n_2 = container.toInt();
					}
					if(i_pos == 2){
						n_3 = container.toInt();
					}
					i_pos++;
					container = "";
					continue;
				}
				container.concat(i_char);
				if(x == note.length() - 1){
					if(i_pos == 3){
						n_4 = container.toInt();
					}
					i_pos++;
				}
			}

			if(i_pos != 4){
				return IPAddress(1,1,1,1);
			}
			
			return IPAddress(n_1, n_2, n_3, n_4);
		}
		
		#endif
		
		Note split(const Note& note, int a_pos, char a_splitChar){
			Note c = "";
			bool init = true;
			int gcmd = 0;
			for(int x = 0; x < note.length(); x++){
				char cr = note.charAt(x);
				if(cr == a_splitChar){
					if(gcmd == a_pos){
						return c;
					}
					c = "";
					gcmd++;
					continue;
				}
				c.concat(cr);
			}
			if(gcmd == a_pos){
				return c;
			}
			
			return "";
		}
		
		int getSplitSize(const Note& note, char a_splitChar){
			if(note.length() == 0){
				return 0;
			}
			int gcmd = 1;
			for(int x = 0; x < note.length(); x++){
				char cr = note.charAt(x);
				if(cr == a_splitChar){
					gcmd++;
					continue;
				}
			}
			return gcmd;
		}
		
		bool toBool(const Note& note){
			NoteMethodsLog(ame_Log_StartMethod, "toBool", "println", "");
			if(note.isEmpty()){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_string == nullptr");
				return false;
			}
			
			if(note.length() == 1){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_pos == 1");
				if(note.charAt(0) == '0'){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return false;
				}
				if(note.charAt(0) == '1'){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return true;
				}
			}
			
			if(note.length() == 3){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_pos == 4");
				if( (note.charAt(0) == 'l' && note.charAt(1) == 'o' && note.charAt(2) == 'w') || 
					(note.charAt(0) == 'L' && note.charAt(1) == 'o' && note.charAt(2) == 'w') || 
					(note.charAt(0) == 'L' && note.charAt(1) == 'O' && note.charAt(2) == 'W') ){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return false;
				}
			}
			
			if(note.length() == 4){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_pos == 4");
				if( (note.charAt(0) == 't' && note.charAt(1) == 'r' && note.charAt(2) == 'u' && note.charAt(3) == 'e') || 
					(note.charAt(0) == 'T' && note.charAt(1) == 'r' && note.charAt(2) == 'u' && note.charAt(3) == 'e') || 
					(note.charAt(0) == 'T' && note.charAt(1) == 'R' && note.charAt(2) == 'U' && note.charAt(3) == 'E') ){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return true;
				}
				if( (note.charAt(0) == 'h' && note.charAt(1) == 'i' && note.charAt(2) == 'g' && note.charAt(3) == 'h') || 
					(note.charAt(0) == 'H' && note.charAt(1) == 'i' && note.charAt(2) == 'g' && note.charAt(3) == 'h') || 
					(note.charAt(0) == 'H' && note.charAt(1) == 'I' && note.charAt(2) == 'G' && note.charAt(3) == 'H') ){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return true;
				}
			}
			
			if(note.length() == 5){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_pos == 5");
				if( (note.charAt(0) == 'f' && note.charAt(1) == 'a' && note.charAt(2) == 'l' && note.charAt(3) == 's' && note.charAt(4) == 'e') || 
					(note.charAt(0) == 'F' && note.charAt(1) == 'a' && note.charAt(2) == 'l' && note.charAt(3) == 's' && note.charAt(4) == 'e') || 
					(note.charAt(0) == 'F' && note.charAt(1) == 'A' && note.charAt(2) == 'L' && note.charAt(3) == 'S' && note.charAt(4) == 'E') ){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return false;
				}
			}
			
			NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "Default");
			return false;
		}
		
		int toInt(const Note& note){
			return note.toInt();
		}
		
		long toLong(const Note& note){
			return note.toLong();
		}
		
		char toChar(const Note& note){
			return note.charAt(0);
		}
		
		char toChar(const Note& note, int a_x){
			return note.charAt(a_x);
		}
	}
	#else
		
	#include "ame_String.hpp"

	#if defined(ame_ArduinoIDE)
		#include "IPAddress.h"
	
	namespace ame{
		IPAddress toIPAddress(const ame_String& note){
			int i_pos = 0;
			ame_String container;
			
			int n_1 = 0;
			int n_2 = 0;
			int n_3 = 0;
			int n_4 = 0;
			
			for(int x = 0; x < note.length(); x++){
				char i_char = note.charAt(x);
				if(i_char == '.'){
					if(i_pos == 0){
						n_1 = container.toInt();
					}
					if(i_pos == 1){
						n_2 = container.toInt();
					}
					if(i_pos == 2){
						n_3 = container.toInt();
					}
					i_pos++;
					container = "";
					continue;
				}
				container.concat(i_char);
				if(x == note.length() - 1){
					if(i_pos == 3){
						n_4 = container.toInt();
					}
					i_pos++;
				}
			}

			if(i_pos != 4){
				return IPAddress(1,1,1,1);
			}
			
			return IPAddress(n_1, n_2, n_3, n_4);
		}
		
		ame_String split(const ame_String& note, int a_pos, char a_splitChar){
			ame_String c = "";
			bool init = true;
			int gcmd = 0;
			for(int x = 0; x < note.length(); x++){
				char cr = note.charAt(x);
				if(cr == a_splitChar){
					if(gcmd == a_pos){
						return c;
					}
					c = "";
					gcmd++;
					continue;
				}
				c.concat(cr);
			}
			if(gcmd == a_pos){
				return c;
			}
			
			return "";
		}
		
		int getSplitSize(const Note& note, char a_splitChar){
			if(note.length() == 0){
				return 0;
			}
			int gcmd = 1;
			for(int x = 0; x < note.length(); x++){
				char cr = note.charAt(x);
				if(cr == a_splitChar){
					gcmd++;
					continue;
				}
			}
			return gcmd;
		}
		
		bool toBool(const ame_String& note){
			NoteMethodsLog(ame_Log_StartMethod, "toBool", "println", "");
			if(note == ""){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_string == nullptr");
				return false;
			}
			
			if(note.length() == 1){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_pos == 1");
				if(note.charAt(0) == '0'){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return false;
				}
				if(note.charAt(0) == '1'){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return true;
				}
			}
			
			if(note.length() == 3){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_pos == 4");
				if( (note.charAt(0) == 'l' && note.charAt(1) == 'o' && note.charAt(2) == 'w') || 
					(note.charAt(0) == 'L' && note.charAt(1) == 'o' && note.charAt(2) == 'w') || 
					(note.charAt(0) == 'L' && note.charAt(1) == 'O' && note.charAt(2) == 'W') ){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return false;
				}
			}
			
			if(note.length() == 4){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_pos == 4");
				if( (note.charAt(0) == 't' && note.charAt(1) == 'r' && note.charAt(2) == 'u' && note.charAt(3) == 'e') || 
					(note.charAt(0) == 'T' && note.charAt(1) == 'r' && note.charAt(2) == 'u' && note.charAt(3) == 'e') || 
					(note.charAt(0) == 'T' && note.charAt(1) == 'R' && note.charAt(2) == 'U' && note.charAt(3) == 'E') ){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return true;
				}
				if( (note.charAt(0) == 'h' && note.charAt(1) == 'i' && note.charAt(2) == 'g' && note.charAt(3) == 'h') || 
					(note.charAt(0) == 'H' && note.charAt(1) == 'i' && note.charAt(2) == 'g' && note.charAt(3) == 'h') || 
					(note.charAt(0) == 'H' && note.charAt(1) == 'I' && note.charAt(2) == 'G' && note.charAt(3) == 'H') ){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return true;
				}
			}
			
			if(note.length() == 5){
				NoteMethodsLog(ame_Log_Statement, "toBool", "println", "m_pos == 5");
				if( (note.charAt(0) == 'f' && note.charAt(1) == 'a' && note.charAt(2) == 'l' && note.charAt(3) == 's' && note.charAt(4) == 'e') || 
					(note.charAt(0) == 'F' && note.charAt(1) == 'a' && note.charAt(2) == 'l' && note.charAt(3) == 's' && note.charAt(4) == 'e') || 
					(note.charAt(0) == 'F' && note.charAt(1) == 'A' && note.charAt(2) == 'L' && note.charAt(3) == 'S' && note.charAt(4) == 'E') ){
					NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "");
					return false;
				}
			}
			
			NoteMethodsLog(ame_Log_EndMethod, "toBool", "println", "Default");
			return false;
		}
		
	}
	
	#elif defined(ame_Windows)
	
	
	#endif

	#endif

#endif






