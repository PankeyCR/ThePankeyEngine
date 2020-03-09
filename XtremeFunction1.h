
#ifndef XtremeFunction1_h
#define XtremeFunction1_h

#include "ArrayList.h"
#include "Function.h"

class XtremeFunction1 : public Function<float,float>{
	public:
		
		XtremeFunction1();
		virtual ~XtremeFunction1();
    
		virtual float f(float mf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual XtremeFunction1* clone();
		
		virtual void set(int p, float var);
		virtual void set(String name, float var);
		
		virtual int getIterationSize();
		virtual float getValue();
		virtual float* getPointer();
		virtual String getName();
		virtual bool isModifiable();
		virtual void set(float var);
		
	protected:
		ArrayList<float,20> vars;
		ArrayList<float,200> learningvars;
		
		
	
};

#endif 
