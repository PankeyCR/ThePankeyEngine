

#ifndef Easing_h
#define Easing_h

#include "EaseFunction.hpp"

namespace ame{
	
class ConstantEasing;
class LinearEasing;
class InQuadEasing;
class InCubicEasing;
class InQuartEasing;
class InQuintEasing;
class OutElasticEasing;
class OutBounceEasing;
class SmoothStepEasing;
class SmootherStepEasing;
class InOutEasing;
class InvertEasing;

class Easing {
    public:
		static EaseFunction *constant();
		static EaseFunction *linear();
		static EaseFunction *inQuad();
		static EaseFunction *inCubic();
		static EaseFunction *inQuart();
		static EaseFunction *inQuint();
		static EaseFunction *outElastic();
		static EaseFunction *outBounce();
		
		static EaseFunction *inElastic();
		static EaseFunction *inBounce();
		static EaseFunction *outQuad();
		static EaseFunction *outCubic();
		static EaseFunction *outQuart();
		static EaseFunction *outQuint();
		
		static EaseFunction *inOutQuad();
		static EaseFunction *inOutCubic();
		static EaseFunction *inOutQuart();
		static EaseFunction *inOutQuint();
		static EaseFunction *inOutElastic();
		static EaseFunction *inOutBounce();
		
		static EaseFunction *smoothStep();
		static EaseFunction *smootherStep();
		static EaseFunction *InOut(EaseFunction *in, EaseFunction *out);
		static EaseFunction *Invert(EaseFunction *fun);
     
	private:
		static EaseFunction *cons;
		static EaseFunction *lin;
		static EaseFunction *inQua;
		static EaseFunction *inCubi;
		static EaseFunction *inQuar;
		static EaseFunction *inQuin;
		static EaseFunction *outElasti;
		static EaseFunction *outBounc;
		
		static EaseFunction *inElasti;
		static EaseFunction *inBounc;
		static EaseFunction *outQua;
		static EaseFunction *outCubi;
		static EaseFunction *outQuar;
		static EaseFunction *outQuin;
		static EaseFunction *inOutQua;
		static EaseFunction *inOutCubi;
		static EaseFunction *inOutQuar;
		static EaseFunction *inOutQuin;
		static EaseFunction *inOutElasti;
		static EaseFunction *inOutBounc;
		
		static EaseFunction *smoothSte;
		static EaseFunction *smootherSte;
		static EaseFunction *InOu;
		static EaseFunction *Inver;
};

class ConstantEasing : public EaseFunction {
    public:
		ConstantEasing();
		float apply(float value);
	private:
};

class LinearEasing : public EaseFunction {
    public:
		LinearEasing();
		float apply(float value);
	private:
};

class InQuadEasing : public EaseFunction {
    public:
		InQuadEasing();
		float apply(float value);
	private:
};

class InCubicEasing : public EaseFunction {
    public:
		InCubicEasing();
		float apply(float value);
	private:
};

class InQuartEasing : public EaseFunction {
    public:
		InQuartEasing();
		float apply(float value);
	private:
};

class InQuintEasing : public EaseFunction {
    public:
		InQuintEasing();
		float apply(float value);
	private:
};

class OutElasticEasing : public EaseFunction {
    public:
		OutElasticEasing();
		float apply(float value);
	private:
};

class OutBounceEasing : public EaseFunction {
    public:
		OutBounceEasing();
		float apply(float value);
	private:
};

class SmoothStepEasing : public EaseFunction {
    public:
		SmoothStepEasing();
		float apply(float value);
	private:
};

class SmootherStepEasing : public EaseFunction {
    public:
		SmootherStepEasing();
		float apply(float value);
	private:
};

class InOutEasing : public EaseFunction {
    public:
		InOutEasing(EaseFunction *in, EaseFunction *out);
		float apply(float value);
	private:
		EaseFunction *In;
		EaseFunction *Out;
};
	
class InvertEasing : public EaseFunction {
    public:
		InvertEasing(EaseFunction *fun);
		float apply(float value);
	private:
		EaseFunction *func;
};

}

#endif 
