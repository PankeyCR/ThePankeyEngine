#ifndef NetList_h
#define NetList_h

#include "List.h"

class NetList : public List<float>{
	public:
		NetList();
		NetList(int netsize);
		~NetList();
		
		virtual void setPos(int p);
		virtual int getPos();
		virtual int getSize();
		virtual void add(List<float> *list);
		virtual void add(float *value);
		virtual void add(float value);
		virtual void set(int position,float value);
		virtual void set(int position,float *value);
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
		virtual int getKey();
		virtual int *getKeyPointer();
		
		//cppObject part
		virtual void onDelete();
		virtual String getClassName();
		virtual String toString();
		virtual NetList *clone();
	private:
		int size=10;
		int pos=0;
		float **value;
};

#endif