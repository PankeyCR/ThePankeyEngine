
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
		float k = 0;
		float l = 0;
		float m = 0;
		float n = 0;
		float o = 0;
		float pvar = 0;
		float q = 0;
		float r = 0;
		float s = 0;
		float t = 0;
		float u = 0;
		float v = 0;
		float w = 0;
		float x = 0;
		float y = 0;
		float z = 0;
		
		float adx = 0;
		float ady = 0;
		float adz = 0;
		float adw = 0;
		float adt = 0;
		float adp = 0;
		float bdx = 0;
		float cdx = 0;
		float ddx = 0;
		float edx = 0;
		float fvardx = 0;
		float gdx = 0;
		float hdx = 0;
		float idx = 0;
		float jdx = 0;
		float kdx = 0;
		float ldx = 0;
		float mdx = 0;
		float ndx = 0;
		float odx = 0;
		float pdx = 0;
		float qdx = 0;
		float rdx = 0;
		float sdx = 0;
		float tdx = 0;
		float udx = 0;
		float vdx = 0;
		float wdx = 0;
		float xdx = 0;
		float ydx = 0;
		float zdx = 0;
	
};

#endif 
