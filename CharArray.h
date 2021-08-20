

#ifndef CharArray_h
#define CharArray_h

#include "List.h"

#define space ' '
#define endLine '.'
#define enter '\n'
#define empty '\0'

namespace ame{

class CharArray : public List<char>{
	private:
		
    public:
		
		CharArray();
		virtual ~CharArray();
		
		virtual void setPos(int p);
		virtual int getPos();
		virtual int getSize();
		virtual void add(List<char> *list);
		virtual void add(char *value);
		virtual void add(char value);
		virtual void set(int pos,char value);
		virtual void set(int pos,char *value);
		virtual char *get(char *key);
		virtual char *get(char key);
		virtual char *getByPos(int x);
		virtual bool contain(char *key);
		virtual bool contain(char key);
		virtual void reset();
		virtual void resetDelete();
		virtual char *remove(char *key);
		virtual char *remove(char key);
		virtual char *removeByPos(int p);
		virtual void removeDelete(char *key);
		virtual void removeDelete(char key);
		virtual void removeDeleteByPos(int p);
		//iterator part
		virtual char getValue();
		virtual char *getPointer();
		
		virtual CharArray operator=(const chr& s);
		virtual CharArray operator+(char chr);
		virtual void operator+=(char chr);
};

}

#endif 
