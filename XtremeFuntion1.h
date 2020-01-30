
#ifndef XtremeFuntion1_h
#define XtremeFuntion1_h

#include "ArrayList.h"
#include "Funtion.h"

class XtremeFuntion1 : public Funtion<float,float>{
	public:
		
		XtremeFuntion1();
		virtual ~XtremeFuntion1();
    
		virtual float f(float mf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual XtremeFuntion1* clone();
		
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
