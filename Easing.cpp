
#include "Easing.h"

ame::EaseFunction* ame::Easing::cons = 0;
ame::EaseFunction* ame::Easing::lin = 0;
ame::EaseFunction* ame::Easing::inCubi = 0;
ame::EaseFunction* ame::Easing::inQua = 0;
ame::EaseFunction* ame::Easing::inQuar = 0;
ame::EaseFunction* ame::Easing::inQuin = 0;
ame::EaseFunction* ame::Easing::outElasti = 0;
ame::EaseFunction* ame::Easing::outBounc = 0;
ame::EaseFunction* ame::Easing::inElasti = 0;
ame::EaseFunction* ame::Easing::inBounc = 0;
ame::EaseFunction* ame::Easing::outQua = 0;
ame::EaseFunction* ame::Easing::outCubi = 0;
ame::EaseFunction* ame::Easing::outQuar = 0;
ame::EaseFunction* ame::Easing::outQuin = 0;
ame::EaseFunction* ame::Easing::inOutQua = 0;
ame::EaseFunction* ame::Easing::inOutCubi = 0;
ame::EaseFunction* ame::Easing::inOutQuar = 0;
ame::EaseFunction* ame::Easing::inOutQuin = 0;
ame::EaseFunction* ame::Easing::inOutElasti = 0;
ame::EaseFunction* ame::Easing::inOutBounc = 0;
ame::EaseFunction* ame::Easing::smoothSte = 0;
ame::EaseFunction* ame::Easing::smootherSte = 0;
ame::EaseFunction* ame::Easing::InOu = 0;
ame::EaseFunction* ame::Easing::Inver = 0;

	
///////////////////////////////////////////////////////////////	

	ame::ConstantEasing::ConstantEasing(){
	
	}
	
	float ame::ConstantEasing::apply(float value){
		return 0.0f;
	}
	
	
	ame::EaseFunction *ame::Easing::constant(){
		if(cons == 0){
			cons = new ame::ConstantEasing();
		}
		return cons;
	}
	
///////////////////////////////////////////////////////////////	
	
	ame::LinearEasing::LinearEasing(){
	
	}
	
	float ame::LinearEasing::apply(float value){
		return value;
	}
	
	
	ame::EaseFunction *ame::Easing::linear(){
		if(lin == 0){
			lin = new ame::LinearEasing();
		}
		return lin;
	}
	
///////////////////////////////////////////////////////////////	
	
	ame::InQuadEasing::InQuadEasing(){
	
	}
	
	float ame::InQuadEasing::apply(float value){
		return value*value;
	}
	
	
	ame::EaseFunction *ame::Easing::inQuad(){
		if(inQua == 0){
			inQua = new ame::InQuadEasing();
		}
		return inQua;
	}
	
///////////////////////////////////////////////////////////////	
	
	ame::InCubicEasing::InCubicEasing(){
	
	}
	
	float ame::InCubicEasing::apply(float value){
		return value * value * value;
	}
	
	
	ame::EaseFunction *ame::Easing::inCubic(){
		if(inCubi == 0){
			inCubi = new ame::InCubicEasing();
		}
		return inCubi;
	}
		
///////////////////////////////////////////////////////////////	
	
	ame::InQuartEasing::InQuartEasing(){
	
	}
	
	float ame::InQuartEasing::apply(float value){
		return value * value * value * value;
	}
	
	
	ame::EaseFunction *ame::Easing::inQuart(){
		if(inQuar == 0){
			inQuar = new ame::InQuartEasing();
		}
		return inQuar;
	}
		
///////////////////////////////////////////////////////////////	
	
	ame::InQuintEasing::InQuintEasing(){
	
	}
	
	float ame::InQuintEasing::apply(float value){
		return value * value * value * value * value;
	}
	
	
	ame::EaseFunction *ame::Easing::inQuint(){
		if(inQuin == 0){
			inQuin = new ame::InQuintEasing();
		}
		return inQuin;
	}
		
///////////////////////////////////////////////////////////////	
	
	ame::OutElasticEasing::OutElasticEasing(){
	
	}
	
	float ame::OutElasticEasing::apply(float value){
		return value*value;
	}
	
	
	ame::EaseFunction *ame::Easing::outElastic(){
		if(outElasti == 0){
			outElasti = new ame::OutElasticEasing();
		}
		return outElasti;
	}
		
///////////////////////////////////////////////////////////////	
	
	ame::OutBounceEasing::OutBounceEasing(){
	
	}
	
	float ame::OutBounceEasing::apply(float value){
		return value*value;
	}
	
	
	ame::EaseFunction *ame::Easing::outBounce(){
		if(outBounc == 0){
			outBounc = new ame::OutBounceEasing();
		}
		return outBounc;
	}
		
///////////////////////////////////////////////////////////////	
	
	ame::SmoothStepEasing::SmoothStepEasing(){
	
	}
	
	float ame::SmoothStepEasing::apply(float value){
		return value*value;
	}
	
	
	ame::EaseFunction *ame::Easing::smoothStep(){
		if(smoothSte == 0){
			smoothSte = new ame::SmoothStepEasing();
		}
		return smoothSte;
	}
		
///////////////////////////////////////////////////////////////	
	
	ame::SmootherStepEasing::SmootherStepEasing(){
	
	}
	
	float ame::SmootherStepEasing::apply(float value){
		return value*value;
	}
	
	
	ame::EaseFunction *ame::Easing::smootherStep(){
		if(smootherSte == 0){
			smootherSte = new ame::SmootherStepEasing();
		}
		return smootherSte;
	}
		
///////////////////////////////////////////////////////////////	
	
	ame::InOutEasing::InOutEasing(ame::EaseFunction *in, ame::EaseFunction *out){
		In = in;
		Out = out;
	}
	
	float ame::InOutEasing::apply(float value){
		return value*value;
	}
	
	ame::EaseFunction *ame::Easing::InOut(ame::EaseFunction *in, ame::EaseFunction *out){
		if(InOu == 0){
			InOu = new ame::InOutEasing(in,out);
		}
		return InOu;
	}
		
///////////////////////////////////////////////////////////////	
	
	ame::InvertEasing::InvertEasing(ame::EaseFunction *fun){
		func = fun;
	}
	
	float ame::InvertEasing::apply(float value){
		return value*value;
	}
	
	ame::EaseFunction *ame::Easing::Invert(ame::EaseFunction *f){
		if(Inver == 0){
			Inver = new ame::InvertEasing(f);
		}
		return Inver;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::inElastic(){
		if(outElasti == 0){
			outElasti = new ame::OutElasticEasing();
		}
		if(inElasti == 0){
			inElasti = new ame::InvertEasing(outElasti);
		}
		return inElasti;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::inBounce(){
		if(outBounc == 0){
			outBounc = new ame::OutBounceEasing();
		}
		if(inBounc == 0){
			inBounc = new ame::InvertEasing(outBounc);
		}
		return inBounc;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::outQuad(){
		if(inQua == 0){
			inQua = new ame::InQuadEasing();
		}
		if(outQua == 0){
			outQua = new ame::InvertEasing(inQua);
		}
		return outQua;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::outCubic(){
		if(inCubi == 0){
			inCubi = new ame::InCubicEasing();
		}
		if(outCubi == 0){
			outCubi = new ame::InvertEasing(inCubi);
		}
		return outCubi;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::outQuart(){
		if(inQuar == 0){
			inQuar = new ame::InQuartEasing();
		}
		if(outQuar == 0){
			outQuar = new ame::InvertEasing(inQuar);
		}
		return outQuar;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::outQuint(){
		if(inQuin == 0){
			inQuin = new ame::InQuintEasing();
		}
		if(outQuin == 0){
			outQuin = new ame::InvertEasing(inQuin);
		}
		return outQuin;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::inOutQuad(){
		if(inQua == 0){
			inQua = new ame::InQuadEasing();
		}
		if(outQua == 0){
			outQua = new ame::InvertEasing(inQua);
		}
		if(inOutQua == 0){
			inOutQua = new ame::InOutEasing(inQua,outQua);
		}
		return inOutQua;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::inOutCubic(){
		if(inCubi == 0){
			inCubi = new ame::InCubicEasing();
		}
		if(outCubi == 0){
			outCubi = new ame::InvertEasing(inCubi);
		}
		if(inOutCubi == 0){
			inOutCubi = new ame::InOutEasing(inCubi,outCubi);
		}
		return inOutCubi;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::inOutQuart(){
		if(inQuar == 0){
			inQuar = new ame::InQuartEasing();
		}
		if(outQuar == 0){
			outQuar = new ame::InvertEasing(inQuar);
		}
		if(inOutQuar == 0){
			inOutQuar = new ame::InOutEasing(inQuar,outQuar);
		}
		return inOutQuar;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::inOutQuint(){
		if(inQuin == 0){
			inQuin = new ame::InQuintEasing();
		}
		if(outQuin == 0){
			outQuin = new ame::InvertEasing(inQuin);
		}
		if(inOutQuin == 0){
			inOutQuin = new ame::InOutEasing(inQuin,outQuin);
		}
		return inOutQuin;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::inOutElastic(){
		if(outElasti == 0){
			outElasti = new ame::OutElasticEasing();
		}
		if(inElasti == 0){
			inElasti = new ame::InvertEasing(outElasti);
		}
		if(inOutElasti == 0){
			inOutElasti = new ame::InOutEasing(inElasti,outElasti);
		}
		return inOutElasti;
	}
		
///////////////////////////////////////////////////////////////		
	
	ame::EaseFunction *ame::Easing::inOutBounce(){
		if(outBounc == 0){
			outBounc = new ame::OutBounceEasing();
		}
		if(inBounc == 0){
			inBounc = new ame::InvertEasing(outBounc);
		}
		if(inOutBounc == 0){
			inOutBounc = new ame::InOutEasing(inBounc,outBounc);
		}
		return inOutBounc;
	}