
#ifndef XtremeFuntion1_h
#define XtremeFuntion1_h

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
		float a = 0;
		float b = 0;
		float c = 0;
		float d = 0;
		float e = 0;
		float fvar = 0;
		float g = 0;
		float h = 0;
		float i = 0;
		float j = 0;
		
		float adx = 0;
		float bdx = 0;
		float cdx = 0;
		float ddx = 0;
		float edx = 0;
		float fvardx = 0;
		float gdx = 0;
		float hdx = 0;
		float idx = 0;
		float jdx = 0;
	
};

#endif 
