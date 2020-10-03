

#ifndef Note_h
#define Note_h

#include "Arduino.h"
#include "List.h"
#include "ArrayList.h"
#include "PrimitiveList.h"

#define space ' '
#define endLine '.'
#define enter '\n'
#define empty '\0'

class Note{
	private:
		
    public:
		PrimitiveList<char> *charList = nullptr;
		int focus=0;
		int size=20;
		//char space=' ';
		//char enter='\n';
		//char empty='\0';
		
		Note();
		Note(int size);
		Note(int size, int expantion);
		~Note();
		
		String getNote();
		
		void setPos(int p);
		int getPos();
		int getSize();
		int getFocus();
		void setFocus(int Focus);
		void add(List<char> *list);
		template<int Size> void add(ArrayList<char,Size> list);
		void add(char *value);
		void add(char *value,int size);
		void add(char value);
		void add(String value);
		void set(int pos,char value);
		void set(int pos,char *value);
		void set(int pos,String value);
		
		template<int Lsize=20>
		ArrayList<int,Lsize> getCharPositions(char chr);
		int getCharSize(char chr);
		char getChar(int x);
		
		template<int Lsize=20>
		ArrayList<int,Lsize> getSpacePositions();
		int getSpaceSize();
		
		template<int Lsize=20>
		ArrayList<int,Lsize> getStringPositions(String s);
		
		int getSpacingSize();
		void fixExtraSpace();
		void fixEmptySpaces();
		void fixEndLinePoint();
		
		static String fixExtraSpace(String s);
		static String fixEmptySpaces(String s);
		static String fixEndLinePoint(String s);
		
		// template<int Lsize=20>
		// ArrayList<String,Lsize> getWords();
		
		String getWord(int pos);
		String getSentence(int pos);
		String getParagraph(int pos);
		
		int getSentenceSize();
		
		static String getWord(String s, int pos);
		static String getSentence(String s, int pos);
		static String getParagraph(String s, int pos);
		
		bool contain(const char *key,int size);
		bool contain(char key);
		bool contain(String key);
		
		void reset();
		bool remove(const String& s);
		bool remove(String key);
		bool remove(char key);
		bool remove(int pos);
		bool remove(int pos,char key);
		bool remove(int pos,String key);
		
		static String Split(String divide, int parte, char limiter);
		static int SplitLenght(String divide, char limiter);
		static String Split(String divide,int parte, char limiter, char fin);
		
		void operator=(const String& s);
		//void operator=(String s);
		//void operator=(Note note);
		//Note operator+(const char *chr);
		Note operator+(char chr);
		void operator+=(char chr);
		void operator+=(const String& s);
	/*	void operator<<(int moveFocus);
		void operator<<(const int& moveFocus);
		void operator<(int moveFocus);
		void operator<(const int& moveFocus);
		void operator>>(int moveFocus);
		void operator>>(const int& moveFocus);
		void operator>(int moveFocus);
		void operator>(const int& moveFocus);
		void operator<<();
		void operator<<();
		void operator<();
		void operator<();
		void operator>>();
		void operator>>();
		void operator>();
		void operator>();*/
};

#endif 
