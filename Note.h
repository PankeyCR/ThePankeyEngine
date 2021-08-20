

#ifndef Note_h
#define Note_h

#include "MemoryChunk.h"
#include "Printable.h"
#include "Arduino.h"
#include "Logger.h"

#ifdef NoteLogApp
	#define NoteLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define NoteLog(name,method,type,mns) 
#endif

namespace ame{


// class Note : public Printable{
class Note{
	protected:
		static MemoryChunk* charsChunk;
		int focus=0;
		char* m_string = nullptr;
		
    public:
		
		void* operator new(size_t size);
		void operator delete(void* pointerToDelete);
		// static char space;
		// static char endLine;
		// static char enter;
		// static char empty;
		
		Note();
		// Note(const char* cstr);
		// Note(const char& i);
		// Note(const int& i);
		// Note(const long& i);
		// Note(const String& i);
		// virtual ~Note();
		
		void init();
		
		// virtual size_t printTo(Print& p) const;
		
		// virtual char* addPointer(char* value);
		// virtual char* addLValue(char value);
		
		// int length();
		// int getFocus();
		// void setFocus(int Focus);
		/*
		PrimitiveList<int> getCharPositions(char chr);
		int getCharPosition(char chr, int pos);
		int getCharSize(char chr);
		
		PrimitiveList<int> getSpacePositions();/////////////////////////
		int getSpaceSize();
		int getSpacingSize();
		
		PrimitiveList<int> getStringPositions(String s);
		int getStringPosition(String s, int pos);
		
		void fixExtraSpace();
		void fixEmptySpaces();
		void fixEndLinePoint();
		
		static String fixExtraSpace(String s);
		static String fixEmptySpaces(String s);
		static String fixEndLinePoint(String s);
		
		PrimitiveList<String> getWords();
		
		String getWord(int pos);
		String getSentence(int pos);
		String getParagraph(int pos);
		
		static String getWord(int pos, String note);
		static String getSentence(int pos, String note);
		static String getParagraph(int pos, String note);
		
		int getSentenceSize();
		static int getSentenceSize(String note);
		
		bool contain(String key);
		
		void reset();
		bool remove(String key);
		bool remove(char key,int pos);
		bool remove(String key,int pos);
		
		static String Split(String divide, int parte, char limiter);
		static int SplitLenght(String divide, char limiter);
		static String Split(String divide,int parte, char limiter, char fin);
		
		int toInt();
		long toLong();
		char toChar();
		char toChar(int x);
		String toString();
		
		void operator=(const String& s);
		void operator=(const char* chr);
		void operator=(const char& i);
		void operator=(const int& i);
		void operator=(const long& i);
		void operator=(Note note);
		Note operator+(Note note);
		Note operator+(const char& chr);
		Note operator+(const char* chr);
		void operator+=(const char* chr);
		void operator<(const char* chr);
		void operator<<(const char* chr);
		bool operator==(Note note);
		bool operator!=(Note note);
		bool operator==(const char* chr);
		bool operator!=(const char* chr);
		void operator+=(const char& chr);
		void operator+=(const String& s);*/
};

}

#endif 
