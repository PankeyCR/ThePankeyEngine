#ifndef NetMap_h
#define NetMap_h

#include "Map.h"

class NetMap : public Map<int,float>{
	public:
		NetMap();
		NetMap(int netsize);
		~NetMap();
		
		virtual void setPos(int p);
		virtual int getPos();
		virtual int getSize();
		virtual void add(int *key, float *value);
		virtual void add(int key, float value);
		virtual void add(int key, float *value);
		virtual void set(int *key, float *value);
		virtual void set(int key, float value);
		virtual void set(int key, float *value);
		virtual bool contain(int *key);
		virtual bool contain(int key);
		virtual float *get(int *key);
		virtual float *get(int key);
		virtual float *getByPos(int p);
		virtual int *getKeyByPos(int p);
		virtual int *getKey(float *value);
		virtual int *getKey(float value);
		virtual void reset();
		virtual void resetDelete();
		virtual float *remove(int *key);
		virtual float *remove(int key);
		virtual float *removeByPos(int p);
		virtual void removeDelete(int *key);
		virtual void removeDelete(int key);
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
		virtual NetMap *clone();
	private:
		int size=10;
		float **value;
};

#endif