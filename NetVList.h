#ifndef NetVList_h
#define NetVList_h

#include "List.h"

template<int size = 10>
class NetVList : public List<float>{
	public:
		NetVList();
		~NetVList();
		
		virtual void setPos(int p);
		virtual int getPos();
		virtual int getSize();
		virtual void add(List<float> *list);
		virtual void add(float *value);
		virtual void add(float value);
		virtual void set(int pos,float value);
		virtual void set(int pos,float *value);
		virtual float *get(float *key);
		virtual float *get(float key);
		virtual float *getByPos(int x);
		virtual bool contain(float *key);
		virtual bool contain(float key);
		virtual void reset();
		virtual void resetDelete();
		virtual float *remove(float *key);
		virtual float *remove(float key);
		virtual float *removeByPos(int p);
		virtual void removeDelete(float *key);
		virtual void removeDelete(float key);
		virtual void removeDeleteByPos(int p);
		
		//iterator part
		virtual int getIterationSize();
		virtual float getValue();
		virtual float *getPointer();
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual NetVList<size> *clone();
	private:
		int pos = 0;
		float value[size];
};

#endif