
#ifndef PointActivationFuntion_cpp
#define PointActivationFuntion_cpp

#include "PointActivationFuntion.h"
	
	template<>
	PointActivationFuntion<float>::PointActivationFuntion(){
	}
	
	// template<>
	// PointActivationFuntion<float,float>::PointActivationFuntion(){
		
	// }
	
	// template<>
	// PointActivationFuntion<float,float,float>::PointActivationFuntion(){
		
	// }
	
	// template<>
	// PointActivationFuntion<float,float,float,float>::PointActivationFuntion(){
		
	// }
	
	// template<>
	// PointActivationFuntion<float,float,float,float,float>::PointActivationFuntion(){
		
	// }
	
	template<>
	PointActivationFuntion<float>::~PointActivationFuntion(){
	}
	
	// template<>
	// PointActivationFuntion<float,float>::~PointActivationFuntion(){
	// }
	
	// template<>
	// PointActivationFuntion<float,float,float>::~PointActivationFuntion(){
	// }
	
	// template<>
	// PointActivationFuntion<float,float,float,float>::~PointActivationFuntion(){
	// }
	
	// template<>
	// PointActivationFuntion<float,float,float,float,float>::~PointActivationFuntion(){
	// }
		
	//cppObject part
	template<class... any>
	String PointActivationFuntion<any...>::getClassName(){
		return "PointActivationFuntion";
	}
	template<class... any>
	String PointActivationFuntion<any...>::toString(){
		return "PointActivationFuntion";
	}
	template<class... any>
	PointActivationFuntion<any...>* PointActivationFuntion<any...>::clone(){
		return this;
	}
	
	template<class... any>
	void PointActivationFuntion<any...>::set(int p, float var){
		if(p==0){
			a=var;
		}
		if(p==1){
			b=var;
		}
		if(p==2){
			c=var;
		}
		if(p==3){
			d=var;
		}
	}
	
	template<class... any>
	void PointActivationFuntion<any...>::set(String name, float var){
		if(name=="a"){
			a=var;
		}
		if(name=="b"){
			b=var;
		}
		if(name=="c"){
			c=var;
		}
		if(name=="d"){
			d=var;
		}
	}
	
	template<>
	float PointActivationFuntion<float>::f(float x){
		return (a/b)*x + (c/a)*x + (d)*x;
	}
	// template<>
	// float PointActivationFuntion<float,float>::f(float x,float y){
		
		// return a*x + b*y + c*x*y + d*x + e*y + fvar;
	// }
	// template<>
	// float PointActivationFuntion<float,float,float>::f(float x,float y,float z){
		
		// return a*x*x + b*y*y + c*z*z + d*x*y + e*x*z + fvar*y*z + g*x + h*y + i*z + j;
	// }
	// template<>
	// float PointActivationFuntion<float,float,float,float>::f(float x,float y,float z,float w){
		
		// return a*x*x + b*y*y + c*z*z + d*w*w + e;
	// }
	
	
	
#endif 
