/*
#ifndef PointActivationFuntion_h
#define PointActivationFuntion_h

#include "Funtion.h"

template<class... any>
class PointActivationFuntion : public Funtion<any...>{
	public:
		PointActivationFuntion();
		virtual ~PointActivationFuntion();
    
		virtual float f(any... mf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual PointActivationFuntion* clone();
		
		virtual void set(int p, float var);
		virtual void set(String name, float var);
		
		virtual int getIterationSize();
		virtual float getValue();
		virtual String getName();
		virtual bool isModifiable();
		virtual void set(float var);
		
	protected:
		float a = 1;
		float b = 1;
		float c = 1;
		float d = 1;
	
};

#endif 
*/