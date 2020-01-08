
#include "Easing.h"

EaseFunction* Easing::cons = 0;
EaseFunction* Easing::lin = 0;
EaseFunction* Easing::inCubi = 0;
EaseFunction* Easing::inQua = 0;
EaseFunction* Easing::inQuar = 0;
EaseFunction* Easing::inQuin = 0;
EaseFunction* Easing::outElasti = 0;
EaseFunction* Easing::outBounc = 0;
EaseFunction* Easing::inElasti = 0;
EaseFunction* Easing::inBounc = 0;
EaseFunction* Easing::outQua = 0;
EaseFunction* Easing::outCubi = 0;
EaseFunction* Easing::outQuar = 0;
EaseFunction* Easing::outQuin = 0;
EaseFunction* Easing::inOutQua = 0;
EaseFunction* Easing::inOutCubi = 0;
EaseFunction* Easing::inOutQuar = 0;
EaseFunction* Easing::inOutQuin = 0;
EaseFunction* Easing::inOutElasti = 0;
EaseFunction* Easing::inOutBounc = 0;
EaseFunction* Easing::smoothSte = 0;
EaseFunction* Easing::smootherSte = 0;
EaseFunction* Easing::InOu = 0;
EaseFunction* Easing::Inver = 0;

	
///////////////////////////////////////////////////////////////	

	ConstantEasing::ConstantEasing(){
	
	}
	
	float ConstantEasing::apply(float value){
		return 0.0f;
	}
	
	
	EaseFunction *Easing::constant(){
		if(cons == 0){
			cons = new ConstantEasing();
		}
		return cons;
	}
	
///////////////////////////////////////////////////////////////	
	
	LinearEasing::LinearEasing(){
	
	}
	
	float LinearEasing::apply(float value){
		return value;
	}
	
	
	EaseFunction *Easing::linear(){
		if(lin == 0){
			lin = new LinearEasing();
		}
		return lin;
	}
	
///////////////////////////////////////////////////////////////	
	
	InQuadEasing::InQuadEasing(){
	
	}
	
	float InQuadEasing::apply(float value){
		return value*value;
	}
	
	
	EaseFunction *Easing::inQuad(){
		if(inQua == 0){
			inQua = new InQuadEasing();
		}
		return inQua;
	}
	
///////////////////////////////////////////////////////////////	
	
	InCubicEasing::InCubicEasing(){
	
	}
	
	float InCubicEasing::apply(float value){
		return value * value * value;
	}
	
	
	EaseFunction *Easing::inCubic(){
		if(inCubi == 0){
			inCubi = new InCubicEasing();
		}
		return inCubi;
	}
		
///////////////////////////////////////////////////////////////	
	
	InQuartEasing::InQuartEasing(){
	
	}
	
	float InQuartEasing::apply(float value){
		return value * value * value * value;
	}
	
	
	EaseFunction *Easing::inQuart(){
		if(inQuar == 0){
			inQuar = new InQuartEasing();
		}
		return inQuar;
	}
		
///////////////////////////////////////////////////////////////	
	
	InQuintEasing::InQuintEasing(){
	
	}
	
	float InQuintEasing::apply(float value){
		return value * value * value * value * value;
	}
	
	
	EaseFunction *Easing::inQuint(){
		if(inQuin == 0){
			inQuin = new InQuintEasing();
		}
		return inQuin;
	}
		
///////////////////////////////////////////////////////////////	
	
	OutElasticEasing::OutElasticEasing(){
	
	}
	
	float OutElasticEasing::apply(float value){
		return value*value;
	}
	
	
	EaseFunction *Easing::outElastic(){
		if(outElasti == 0){
			outElasti = new OutElasticEasing();
		}
		return outElasti;
	}
		
///////////////////////////////////////////////////////////////	
	
	OutBounceEasing::OutBounceEasing(){
	
	}
	
	float OutBounceEasing::apply(float value){
		return value*value;
	}
	
	
	EaseFunction *Easing::outBounce(){
		if(outBounc == 0){
			outBounc = new OutBounceEasing();
		}
		return outBounc;
	}
		
///////////////////////////////////////////////////////////////	
	
	SmoothStepEasing::SmoothStepEasing(){
	
	}
	
	float SmoothStepEasing::apply(float value){
		return value*value;
	}
	
	
	EaseFunction *Easing::smoothStep(){
		if(smoothSte == 0){
			smoothSte = new SmoothStepEasing();
		}
		return smoothSte;
	}
		
///////////////////////////////////////////////////////////////	
	
	SmootherStepEasing::SmootherStepEasing(){
	
	}
	
	float SmootherStepEasing::apply(float value){
		return value*value;
	}
	
	
	EaseFunction *Easing::smootherStep(){
		if(smootherSte == 0){
			smootherSte = new SmootherStepEasing();
		}
		return smootherSte;
	}
		
///////////////////////////////////////////////////////////////	
	
	InOutEasing::InOutEasing(EaseFunction *in, EaseFunction *out){
		In = in;
		Out = out;
	}
	
	float InOutEasing::apply(float value){
		return value*value;
	}
	
	EaseFunction *Easing::InOut(EaseFunction *in, EaseFunction *out){
		if(InOu == 0){
			InOu = new InOutEasing(in,out);
		}
		return InOu;
	}
		
///////////////////////////////////////////////////////////////	
	
	InvertEasing::InvertEasing(EaseFunction *fun){
		func = fun;
	}
	
	float InvertEasing::apply(float value){
		return value*value;
	}
	
	EaseFunction *Easing::Invert(EaseFunction *f){
		if(Inver == 0){
			Inver = new InvertEasing(f);
		}
		return Inver;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::inElastic(){
		if(outElasti == 0){
			outElasti = new OutElasticEasing();
		}
		if(inElasti == 0){
			inElasti = new InvertEasing(outElasti);
		}
		return inElasti;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::inBounce(){
		if(outBounc == 0){
			outBounc = new OutBounceEasing();
		}
		if(inBounc == 0){
			inBounc = new InvertEasing(outBounc);
		}
		return inBounc;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::outQuad(){
		if(inQua == 0){
			inQua = new InQuadEasing();
		}
		if(outQua == 0){
			outQua = new InvertEasing(inQua);
		}
		return outQua;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::outCubic(){
		if(inCubi == 0){
			inCubi = new InCubicEasing();
		}
		if(outCubi == 0){
			outCubi = new InvertEasing(inCubi);
		}
		return outCubi;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::outQuart(){
		if(inQuar == 0){
			inQuar = new InQuartEasing();
		}
		if(outQuar == 0){
			outQuar = new InvertEasing(inQuar);
		}
		return outQuar;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::outQuint(){
		if(inQuin == 0){
			inQuin = new InQuintEasing();
		}
		if(outQuin == 0){
			outQuin = new InvertEasing(inQuin);
		}
		return outQuin;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::inOutQuad(){
		if(inQua == 0){
			inQua = new InQuadEasing();
		}
		if(outQua == 0){
			outQua = new InvertEasing(inQua);
		}
		if(inOutQua == 0){
			inOutQua = new InOutEasing(inQua,outQua);
		}
		return inOutQua;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::inOutCubic(){
		if(inCubi == 0){
			inCubi = new InCubicEasing();
		}
		if(outCubi == 0){
			outCubi = new InvertEasing(inCubi);
		}
		if(inOutCubi == 0){
			inOutCubi = new InOutEasing(inCubi,outCubi);
		}
		return inOutCubi;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::inOutQuart(){
		if(inQuar == 0){
			inQuar = new InQuartEasing();
		}
		if(outQuar == 0){
			outQuar = new InvertEasing(inQuar);
		}
		if(inOutQuar == 0){
			inOutQuar = new InOutEasing(inQuar,outQuar);
		}
		return inOutQuar;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::inOutQuint(){
		if(inQuin == 0){
			inQuin = new InQuintEasing();
		}
		if(outQuin == 0){
			outQuin = new InvertEasing(inQuin);
		}
		if(inOutQuin == 0){
			inOutQuin = new InOutEasing(inQuin,outQuin);
		}
		return inOutQuin;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::inOutElastic(){
		if(outElasti == 0){
			outElasti = new OutElasticEasing();
		}
		if(inElasti == 0){
			inElasti = new InvertEasing(outElasti);
		}
		if(inOutElasti == 0){
			inOutElasti = new InOutEasing(inElasti,outElasti);
		}
		return inOutElasti;
	}
		
///////////////////////////////////////////////////////////////		
	
	EaseFunction *Easing::inOutBounce(){if(outBounc == 0){
			outBounc = new OutBounceEasing();
		}
		if(inBounc == 0){
			inBounc = new InvertEasing(outBounc);
		}
		if(inOutBounc == 0){
			inOutBounc = new InOutEasing(inBounc,outBounc);
		}
		return inOutBounc;
	}