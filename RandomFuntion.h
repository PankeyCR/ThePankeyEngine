/*
#ifndef RandomFuntion_h
#define RandomFuntion_h

#include "Funtion.h"
#include "RealRandom.h"

template<class... any>
class RandomFuntion : public Funtion<any...>{
	public:
		RealRandom random;
		RandomFuntion();
		RandomFuntion(float seed);
		virtual ~RandomFuntion();
    
		virtual float f(any... mf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual RandomFuntion* clone();
		
		virtual void set(int p, float var);
		virtual void set(String name, float var);
		
	protected:
		float a = 1;
		float b = 1;
		float c = 1;
		float d = 1;
		float e = 1;
		float fvar = 1;
		float g = 1;
		float h = 1;
		float i = 1;
		float j = 1;
	
};

#endif 
*/