
#ifndef Note_hpp
#define Note_hpp

#include "ame_Level.hpp"

#if defined(ame_untilLevel_1)

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "NoteIterator.hpp"
#include "NoteIterator.hpp"
// #include "MemoryManager.hpp"
// #include "MemoryPool.hpp"
// #include "MemoryChunk.hpp"

namespace ame{

#ifdef ame_Windows
class Note{

	protected:
		char* m_string = nullptr;

    public:

		Note(){
			m_string = new char[1];
			m_string[0] = '\0';
		}

		Note(const char* val){
		}

		Note(const Note& source){
		}

		Note(const int& val){
			// int size_val = intCharSize(val);

			// m_string = new char[size_val + 1];
			// intToCharPointer(val, size_val, 0, m_string, true);
		}

		Note(const long& val){

		}
		Note(const float& val){
			// int size_val = floatCharSize(val, 4);

			// m_string = new char[size_val + 1];
			// floatToCharPointer(val, size_val, 0, 4, m_string, true);
		}

		// Note(const char& i);
		// Note(const int& i);
		// Note(const long& i);
		// Note(const String& i);
		virtual ~Note(){
			// if(m_string != nullptr){
				// delete[] m_string;
			// }
		}

		virtual int length() const{
			// return strlen(m_string);
			return 0;
		}

		virtual char charAt(int x) const{
			// if(m_string == nullptr){
				// Serial.println("m_string == nullptr");
				// return 0;
			// }
			// if(strlen(m_string) < x){
				// Serial.println("strlen(m_string) > x");
				// return 0;
			// }
			// return m_string[x];
			return 0;
		}

		// virtual NoteIterator begin(){
			// return NoteIterator(m_string,0);
		// }
		// virtual NoteIterator end(){
			// return NoteIterator(m_string, this->length());
		// }

		virtual Note add(const char* value){
			// int length = strlen(m_string) + strlen(value);

			// char* buff = new char[length + 1];

			// strcpy(buff, m_string);
			// strcat(buff, value);
			// buff[length] = '\0';

			// Note temp = Note(buff);
			// delete[] buff;
			// return temp;
			return *this;
		}

		virtual Note addLocal(const char* value){
			// int length = strlen(m_string) + strlen(value);

			// char* buff = new char[length + 1];

			// strcpy(buff, m_string);
			// strcat(buff, value);
			// buff[length] = '\0';

			// delete[] m_string;
			// m_string = buff;
			return *this;
		}

		virtual void concat(const Note& note){
			// int length = strlen(m_string) + strlen(note.m_string);

			// char* buff = new char[length + 1];

			// strcpy(buff, m_string);
			// strcat(buff, note.m_string);
			// buff[length] = '\0';

			// delete[] m_string;
			// m_string = buff;
		}

		virtual void concat(const char& chr){
			// int length = strlen(m_string) + 1;

			// char* buff = new char[length + 1];

			// strcpy(buff, m_string);
			// buff[length - 1] = chr;
			// buff[length] = '\0';

			// delete[] m_string;
			// m_string = buff;
		}

		virtual void concat(const int& val){
			// int size_val = intCharSize(val);
			// int length = strlen(m_string) + size_val;

			// char* buff = new char[length + 1];

			// strcpy(buff, m_string);
			// intToCharPointer(val, size_val, strlen(m_string), m_string, true);

			// delete[] m_string;
			// m_string = buff;
		}

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

		// int toInt();
		// long toLong();
		// char toChar();
		// char toChar(int x);
		// String toString();

		Note subNote(int start){
			// int t_size = this->length();
			// int s_size = t_size - start;
			//Serial.print("s_size ");Serial.println(s_size);
			// char* buff = new char[s_size + 1];

			// for(int x = start; x < t_size; x++){
				//Serial.print("m_string[x] ");Serial.println(m_string[x]);
				// buff[x - start] = m_string[x];
			// }
			// buff[s_size] = '\0';

			// Note note = buff;
			// delete[] buff;

			// return note;
			return *this;
		}

		Note subNote(int start, int end){
			// int t_size = this->length();
			// int s_size = t_size - start;
			// if(end < t_size){
				// s_size -= t_size - end;
				// t_size = end;
			// }
			// Serial.print("s_size ");Serial.println(s_size);
			// Serial.print("t_size ");Serial.println(t_size);
			// char* buff = new char[s_size + 1];

			// for(int x = start; x < t_size; x++){
				// Serial.print("x ");Serial.println(x);
				// Serial.print("m_string[x] ");Serial.println(m_string[x]);
				// buff[x - start] = m_string[x];
			// }
			// buff[s_size] = '\0';

			// Note note = buff;
			// delete[] buff;

			// return note;
			return *this;
		}

		void operator=(const Note& source){
			// delete[] m_string;
			// m_string = new char[strlen(source.m_string) + 1];
			// strcpy(m_string, source.m_string);
			// m_string[strlen(source.m_string)] = '\0';
		}
		// void operator=(const char* chr);
		// void operator=(const char& i);
		// void operator=(const int& i);
		// void operator=(const long& i);
		// void operator=(Note note);
		Note operator+(const Note& note){
			// int length = strlen(m_string) + strlen(note.m_string);

			// char* buff = new char[length + 1];

			// strcpy(buff, m_string);
			// strcat(buff, note.m_string);
			// buff[length] = '\0';

			// Note m_note = buff;
			// delete[] buff;
			// return m_note;
			return *this;
		}
		// Note operator+(const char& chr);
		// Note operator+(const char* chr);
		Note& operator+=(const Note& value){
			// int length = strlen(m_string) + strlen(value.m_string);

			// char* buff = new char[length + 1];

			// strcpy(buff, m_string);
			// strcat(buff, value.m_string);
			// buff[length] = '\0';

			// delete[] m_string;
			// m_string = buff;
			return *this;
		}

		Note& operator+=(const char* value){
			// int length = strlen(m_string) + strlen(value);

			// char* buff = new char[length + 1];

			// strcpy(buff, m_string);
			// strcat(buff, value);
			// buff[length] = '\0';

			// delete[] m_string;
			// m_string = buff;
			return *this;
		}
		// void operator<(const char* chr);
		// void operator<<(const char* chr);
		bool operator==(const Note& note){
			// if(m_string == note.m_string){
				// return true;
			// }
			// int c_length = strlen(note.m_string) + 1;
			// int s_length = strlen(m_string) + 1;
			// if(length() != note.length()){
				// return false;
			// }
			// for(int x = 0; x < length(); x++){
				// if(m_string[x] == note.m_string[x]){
					// return false;
				// }
			// }
			return true;
		}
		bool operator!=(const Note& note){
			// if(m_string == note.m_string){
				// return false;
			// }
			// int c_length = strlen(note.m_string) + 1;
			// int s_length = strlen(m_string) + 1;
			// if(length() != note.length()){
				// return true;
			// }
			// for(int x = 0; x < length(); x++){
				// if(m_string[x] == note.m_string[x]){
					// return true;
				// }
			// }
			return false;
		}

		bool operator==(const char* chr){
			// if(chr == m_string){
				// return true;
			// }
			// int c_length = strlen(chr) + 1;
			// int s_length = strlen(m_string) + 1;
			// if(c_length != s_length){
				// return false;
			// }
			// for(int x = 0; x < s_length; x++){
				// if(chr[x] != m_string[x]){
					// return false;
				// }
			// }
			return true;
		}
		bool operator!=(const char* chr){
			// if(chr == m_string){
				// return false;
			// }
			// int c_length = strlen(chr) + 1;
			// int s_length = strlen(m_string) + 1;
			// if(c_length != s_length){
				// return true;
			// }
			// for(int x = 0; x < s_length; x++){
				// if(chr[x] == m_string[x]){
					// return true;
				// }
			// }
			return false;
		}
		// void operator+=(const char& chr);
		// void operator+=(const String& s);

		static int intCharSize(int value){
			// int i_size_val = 0;
			// int x = 1;
			// int add_x = 0;
			// if(value < 0){
				// Serial.println("negative int");
				// value *= -1;
				// add_x++;
				// Serial.print("size capture: ");Serial.println(x);
			// }
			// for( ; x < 100; x++){
				// Serial.print("size capture: ");Serial.println(x);
				// int expn = 1;
				// for(int y = 0; y < x; y++){
					// expn *= 10;
				// }

				// Serial.print("expn: ");Serial.println(expn);
				// Serial.print("value/expn: ");Serial.println(value/expn);
				// if(value/expn < 1){
					// i_size_val = x;
					// break;
				// }
			// }
				// Serial.print("i_size_val capture: ");Serial.println(i_size_val);

			// return i_size_val + add_x;
			return 0;
		}

		static void intToCharPointer(int value, int size, int start, char* chr, bool end){
			// if(chr == nullptr){
				// return;
			// }
			// int position = start;
			// bool isNegative = false;
			// if(value < 0){
				// isNegative = true;
				// value *= -1;
				// size--;
				// chr[position] = 45;
				// position++;
			// }
			// int n_value = 1;
			// int r_value = 1;
			// int s_value = 1;
			// for(int x = 0; x < size; x++){
				// int expn = 1;
				// for(int y = 0; y < size - x - 1; y++){
					// expn *= 10;
				// }
				// n_value = value / expn;
				// if(x == 0){
					// s_value = n_value;
				// }else{
					// s_value = n_value - r_value;
				// }
				// r_value = n_value * 10;
				// Serial.print("expn ");Serial.println(expn);
				// Serial.print("n_value ");Serial.println(n_value);
				// Serial.print("r_value ");Serial.println(r_value);
				// Serial.print("s_value ");Serial.println(s_value);
				// chr[position] = s_value + 48;
				// position++;
			// }
			// if(end){
				// chr[position] = '\0';
			// }
		}

		static int floatCharSize(float value,int extra){
			// int i_size_val = 0;
			// int x = 1;
			// int add_x = 0;
			// if(value < 0){
				// Serial.println("negative int");
				// value *= -1;
				// add_x++;
				// Serial.print("size capture: ");Serial.println(x);
			// }
			// for( ; x < 100; x++){
				// Serial.print("size capture: ");Serial.println(x);
				// int expn = 1;
				// for(int y = 0; y < x; y++){
					// expn *= 10;
				// }

				// Serial.print("expn: ");Serial.println(expn);
				// Serial.print("value/expn: ");Serial.println(value/expn);
				// if(value/expn < 1){
					// i_size_val = x;
					// break;
				// }
			// }
				// Serial.print("i_size_val capture: ");Serial.println(i_size_val);

			// return i_size_val + add_x + extra + 1;
			return 0;
		}

		static void floatToCharPointer(float value, int total_size, int start, int decimal_size, char* chr, bool end){
			// if(chr == nullptr){
				// return;
			// }
			// int position = start;
			// bool isNegative = false;
			// if(value < 0){
				// isNegative = true;
				// value *= -1;
				// total_size--;
				// chr[position] = 45;
				// position++;
			// }
			// int n_value = 1;
			// int r_value = 1;
			// int s_value = 1;
			// int i_size = total_size - decimal_size - 1;
			// for(int x = 0; x < i_size; x++){
				// int expn = 1;
				// for(int y = 0; y < i_size - x - 1; y++){
					// expn *= 10;
				// }
				// n_value = value / expn;
				// if(x == 0){
					// s_value = n_value;
				// }else{
					// s_value = n_value - r_value;
				// }
				// r_value = n_value * 10;
				// Serial.print("expn ");Serial.println(expn);
				// Serial.print("n_value ");Serial.println(n_value);
				// Serial.print("r_value ");Serial.println(r_value);
				// Serial.print("s_value ");Serial.println(s_value);
				// chr[position] = s_value + 48;
				// position++;
			// }

			// chr[position] = 46;
			// Serial.print("chr[position] ");Serial.println(chr[position]);
			// position++;

			// n_value = 1;
			// r_value = 1;
			// s_value = 1;
			// float i_value = value - (int)value;
			// for(int x = 0; x < decimal_size; x++){
				// int expn = 10;
				// for(int y = 0; y < x; y++){
					// expn *= 10;
				// }
				// n_value = i_value * expn;
				// if(x == 0){
					// s_value = n_value;
				// }else{
					// s_value = n_value - r_value;
				// }
				// r_value = n_value * 10;
				// Serial.print("expn ");Serial.println(expn);
				// Serial.print("n_value ");Serial.println(n_value);
				// Serial.print("r_value ");Serial.println(r_value);
				// Serial.print("s_value ");Serial.println(s_value);
				// chr[position] = s_value + 48;
				// Serial.print("chr[position] ");Serial.println(chr[position]);
				// position++;
			// }
			// if(end){
				// chr[position] = '\0';
			// }
		}



};
#endif

#ifdef ame_ArduinoIDE
class Note : public Printable{

	protected:
		char* m_string = nullptr;

    public:

		// void* operator new(size_t size, void* memory){
			// if(Memory::manager == nullptr){
				// NoteLog("Note", "operator new",  "println", "no memory manager, malloc invoke");
				// return malloc(size);
			// }
			// if(m_Pool == nullptr){
				// NoteLog("Note", "operator new",  "println", "no memory pool, creating notepool");
			// m_Pool = Memory::manager->createMemoryPool();
			// }
			// MemoryChunk* chunk = m_Pool->getLastChunk();
			// if(chunk == nullptr){
				// NoteLog("Note", "operator new",  "println", "no memory chunk, creating new memory chunk");
				// chunk = m_Pool->createMemoryChunk();
			// }
			// if(chunk->isFull()){
				// NoteLog("Note", "operator new",  "println", "no memory chunk, creating new memory chunk");
				// if(m_Pool->isFull()){
					// return nullptr;
				// }
				// chunk = m_Pool->createMemoryChunk();
			// }
			// return chunk->newInstance<Note,alignof(Note),sizeof(Note)>();
		// }
		// void operator delete(void* pointerToDelete){
			// NoteLog("Note", "operator delete",  "println", "");
			// if(Memory::manager == nullptr){
				// NoteLog("Note", "operator delete",  "println", "free ");
				// free(pointerToDelete);
				// return;
			// }
			// m_Pool->deleteNote(pointerToDelete);
		// }

		Note(){
			m_string = new char[1];
			m_string[0] = '\0';
		}

		Note(const char* val){
			if(val == nullptr) {
				m_string = new char[1];
				m_string[0] = '\0';
			}else{
				m_string = new char[strlen(val) + 1];
				strcpy(m_string, val);
				m_string[strlen(val)] = '\0';
			}
		}

		Note(const Note& source){
			Serial.println("const Note&");
			int n_size = source.length();
			Serial.print("source.length ");Serial.println(n_size);
			m_string = new char[n_size + 1];
			strcpy(m_string, source.m_string);
			m_string[n_size] = '\0';
		}

		Note(Note&& source){
			m_string = source.m_string;
			source.m_string = nullptr;
		}

		Note(const char& i){
			m_string = new char[2];
			m_string[0] = i;
			m_string[1] = '\0';
		}

		Note(const int& val){
			int size_val = intCharSize(val);

			m_string = new char[size_val + 1];
			intToCharPointer(val, size_val, 0, m_string, true);
		}

		Note(const long& val){
			int size_val = longCharSize(val);

			m_string = new char[size_val + 1];
			longToCharPointer(val, size_val, 0, m_string, true);
		}

		Note(const float& val){

			int size_val = floatCharSize(val, 4);

			m_string = new char[size_val + 1];
			floatToCharPointer(val, size_val, 0, 4, m_string, true);
		}

		#ifdef ame_ArduinoIDE

		Note(const String& source){
			if(!source.isEmpty()){
				m_string = new char[strlen(source.c_str()) + 1];
				strcpy(m_string, source.c_str());
				m_string[strlen(source.c_str())] = '\0';
			}
		}

		// Note(String&& source){
			// if(!source.isEmpty()){
				// m_string = source.c_str();
				// source.c_str() = nullptr;
			// }
		// }

		#endif
		
		virtual ~Note(){
			delete[] m_string;
		}

		virtual int length() const{
			return strlen(m_string);
		}

		virtual char charAt(int x) const{
			if(m_string == nullptr){
				Serial.println("m_string == nullptr");
				return 0;
			}
			if(strlen(m_string) < x){
				Serial.println("strlen(m_string) > x");
				return 0;
			}
			return m_string[x];
		}

		virtual NoteIterator begin(){
			return NoteIterator(m_string,0);
		}
		virtual NoteIterator end(){
			return NoteIterator(m_string, this->length());
		}

		#ifdef ame_ArduinoIDE

		virtual size_t printTo(Print& p) const{
			p.print(m_string);
			return sizeof(m_string);
		}

		#endif

		virtual Note add(const char* value){
			int length = strlen(m_string) + strlen(value);

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			strcat(buff, value);
			buff[length] = '\0';

			Note temp = Note(buff);
			delete[] buff;
			return temp;
		}

		virtual Note addLocal(const char* value){
			int length = strlen(m_string) + strlen(value);

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			strcat(buff, value);
			buff[length] = '\0';

			delete[] m_string;
			m_string = buff;
			return *this;
		}

		virtual void concat(const Note& note){
			int length = strlen(m_string) + strlen(note.m_string);

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			strcat(buff, note.m_string);
			buff[length] = '\0';

			delete[] m_string;
			m_string = buff;
		}

		virtual void concat(const char& chr){
			int length = strlen(m_string) + 1;

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			buff[length - 1] = chr;
			buff[length] = '\0';

			delete[] m_string;
			m_string = buff;
		}

		virtual void concat(const char* chr){
			int length = strlen(m_string) + strlen(chr);

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			strcat(buff, chr);
			buff[length] = '\0';

			delete[] m_string;
			m_string = buff;
		}

		virtual void concat(const int& val){
			int size_val = intCharSize(val);
			int length = strlen(m_string) + size_val;
			// Serial.print("size_val ");Serial.println(size_val);
			// Serial.print("length ");Serial.println(length);

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			intToCharPointer(val, size_val, strlen(m_string), buff, true);

			delete[] m_string;
			m_string = buff;
		}

		virtual void concat(const long& val){
			int size_val = longCharSize(val);
			int length = strlen(m_string) + size_val;

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			longToCharPointer(val, size_val, strlen(m_string), buff, true);

			delete[] m_string;
			m_string = buff;
		}
		
		virtual void concat(const String& val){
			int length = strlen(m_string) + val.length();

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			strcat(buff, val.c_str());
			buff[length] = '\0';

			delete[] m_string;
			m_string = buff;
		}

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

		int toInt(){
			int output = 0;
			int c_size = strlen(m_string);
			bool lastDecimals = false;
			for(int x = 0; x < c_size; x++){
				if(m_string[x] == 46){
					if(lastDecimals){
						// Serial.println("m_string[x] == 46 && lastDecimals");
						// Serial.print("position ");Serial.println(x);
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
					return 0;
				}
			}
			return output;
		}
		
		long toLong(){
			long output = 0;
			int c_size = strlen(m_string);
			bool lastDecimals = false;
			for(int x = 0; x < c_size; x++){
				if(m_string[x] == 46){
					if(lastDecimals){
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
					return 0;
				}
			}
			return output;
		}
		
		float toFloat(){
			float output = 0;
			int c_size = strlen(m_string);
			bool lastDecimals = false;
			int d_pos = 0;
			for(int x = 0; x < c_size; x++){
				if(m_string[x] == 46){
					if(lastDecimals){
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
					return 0;
				}
			}
			return output;
		}
		
		String toString(){
			return String(m_string);
		}

		Note subNote(int start){
			int t_size = this->length();
			int s_size = t_size - start;
			// Serial.print("s_size ");Serial.println(s_size);
			char* buff = new char[s_size + 1];

			for(int x = start; x < t_size; x++){
				// Serial.print("m_string[x] ");Serial.println(m_string[x]);
				buff[x - start] = m_string[x];
			}
			buff[s_size] = '\0';

			Note note = buff;
			delete[] buff;

			return note;
		}

		Note subNote(int start, int end){
			int t_size = this->length();
			int s_size = t_size - start;
			if(end < t_size){
				s_size -= t_size - end;
				t_size = end;
			}
			// Serial.print("s_size ");Serial.println(s_size);
			// Serial.print("t_size ");Serial.println(t_size);
			char* buff = new char[s_size + 1];

			for(int x = start; x < t_size; x++){
				// Serial.print("x ");Serial.println(x);
				// Serial.print("m_string[x] ");Serial.println(m_string[x]);
				buff[x - start] = m_string[x];
			}
			buff[s_size] = '\0';

			Note note = buff;
			delete[] buff;

			return note;
		}
		
		void toCharArray(char* c_pointer, int c_size){
			if(c_pointer == nullptr){
				return;
			}
			if(c_size != this->length() + 1){
				return;
			}
			for(int x = 0; x < c_size - 1; x++){
				c_pointer[x] = m_string[x];
			}
		}

		void operator=(const Note& source){
			delete[] m_string;
			m_string = new char[strlen(source.m_string) + 1];
			strcpy(m_string, source.m_string);
			m_string[strlen(source.m_string)] = '\0';
		}
		// void operator=(const char* chr);
		// void operator=(const char& i);
		// void operator=(const int& i);
		// void operator=(const long& i);
		// void operator=(Note note);
		Note operator+(const Note& note){
			int length = strlen(m_string) + strlen(note.m_string);

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			strcat(buff, note.m_string);
			buff[length] = '\0';

			Note m_note = buff;
			delete[] buff;
			return m_note;
		}
		// Note operator+(const char& chr);
		// Note operator+(const char* chr);
		Note& operator+=(const Note& value){
			int length = strlen(m_string) + strlen(value.m_string);

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			strcat(buff, value.m_string);
			buff[length] = '\0';

			delete[] m_string;
			m_string = buff;
			return *this;
		}

		Note& operator+=(const char* value){
			int length = strlen(m_string) + strlen(value);

			char* buff = new char[length + 1];

			strcpy(buff, m_string);
			strcat(buff, value);
			buff[length] = '\0';

			delete[] m_string;
			m_string = buff;
			return *this;
		}
		// void operator<(const char* chr);
		// void operator<<(const char* chr);
		bool operator==(const Note& note){
			if(m_string == note.m_string){
				return true;
			}
			if(length() != note.length()){
				return false;
			}
			for(int x = 0; x < length(); x++){
				if(m_string[x] != note.m_string[x]){
					return false;
				}
			}
			return true;
		}
		bool operator!=(const Note& note){
			if(m_string == note.m_string){
				return false;
			}
			if(length() != note.length()){
				return true;
			}
			for(int x = 0; x < length(); x++){
				if(m_string[x] != note.m_string[x]){
					return true;
				}
			}
			return false;
		}

		bool operator==(const char* chr){
			if(chr == m_string){
				return true;
			}
			int c_length = strlen(chr);
			int s_length = strlen(m_string);
			if(c_length != s_length){
				return false;
			}
			for(int x = 0; x < s_length; x++){
				if(chr[x] != m_string[x]){
					return false;
				}
			}
			return true;
		}
		bool operator!=(const char* chr){
			if(chr == m_string){
				return false;
			}
			int c_length = strlen(chr);
			int s_length = strlen(m_string);
			if(c_length != s_length){
				return true;
			}
			for(int x = 0; x < s_length; x++){
				if(chr[x] != m_string[x]){
					return true;
				}
			}
			return false;
		}
		// void operator+=(const char& chr);
		// void operator+=(const String& s);

		static int intCharSize(int value){
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

			return i_size_val + add_x;
		}

		static void intToCharPointer(int value, int size, int start, char* chr, bool end){
			if(chr == nullptr){
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
		}

		static int longCharSize(long value){
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

			return i_size_val + add_x;
		}

		static void longToCharPointer(long value, int size, int start, char* chr, bool end){
			if(chr == nullptr){
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
		}

		static int floatCharSize(float value,int extra){
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

			return i_size_val + add_x + extra + 1;
		}

		static void floatToCharPointer(float value, int total_size, int start, int decimal_size, char* chr, bool end){
			if(chr == nullptr){
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
		}
};
#endif

}

#endif

#endif
