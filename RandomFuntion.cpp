
#ifndef RandomFuntion_cpp
#define RandomFuntion_cpp

#include "RandomFuntion.h"


	// template<class... any>
	// RandomFuntion<any...>::RandomFuntion(){
		
	// }
		
	// template<class... any>
	// RandomFuntion<any...>::~RandomFuntion(){
		
	// }
	
	template<>
	RandomFuntion<float>::RandomFuntion(){
	}
	
	template<>
	RandomFuntion<float,float>::RandomFuntion(){
		
	}
	
	template<>
	RandomFuntion<float,float,float>::RandomFuntion(){
		
	}
	
	template<>
	RandomFuntion<float,float,float,float>::RandomFuntion(){
		
	}
	
	template<>
	RandomFuntion<float,float,float,float,float>::RandomFuntion(){
		
	}
	
	template<>
	RandomFuntion<float>::RandomFuntion(float seed){
		random.setSeed(seed);
	}
	
	template<>
	RandomFuntion<float,float>::RandomFuntion(float seed){
		random.setSeed(seed);
	}
	
	template<>
	RandomFuntion<float,float,float>::RandomFuntion(float seed){
		random.setSeed(seed);
	}
	
	template<>
	RandomFuntion<float,float,float,float>::RandomFuntion(float seed){
		random.setSeed(seed);
	}
	
	template<>
	RandomFuntion<float,float,float,float,float>::RandomFuntion(float seed){
		random.setSeed(seed);
	}
	
	template<>
	RandomFuntion<float>::~RandomFuntion(){
		
	}
	
	template<>
	RandomFuntion<float,float>::~RandomFuntion(){
		
	}
	
	template<>
	RandomFuntion<float,float,float>::~RandomFuntion(){
		
	}
	
	template<>
	RandomFuntion<float,float,float,float>::~RandomFuntion(){
		
	}
	
	template<>
	RandomFuntion<float,float,float,float,float>::~RandomFuntion(){
		
	}
		
	//cppObject part
	template<class... any>
	String RandomFuntion<any...>::getClassName(){
		return "RandomFuntion";
	}
	template<class... any>
	String RandomFuntion<any...>::toString(){
		return "RandomFuntion";
	}
	template<class... any>
	RandomFuntion<any...>* RandomFuntion<any...>::clone(){
		return this;
	}
	
	template<class... any>
	void RandomFuntion<any...>::set(int p, float var){
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
		if(p==4){
			e=var;
		}
		if(p==5){
			fvar=var;
		}
		if(p==6){
			g=var;
		}
		if(p==7){
			h=var;
		}
		if(p==8){
			i=var;
		}
		if(p==9){
			j=var;
		}
	}
	
	template<class... any>
	void RandomFuntion<any...>::set(String name, float var){
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
		if(name=="e"){
			e=var;
		}
		if(name=="f"){
			fvar=var;
		}
		if(name=="g"){
			g=var;
		}
		if(name=="h"){
			h=var;
		}
		if(name=="i"){
			i=var;
		}
		if(name=="j"){
			j=var;
		}
	}

	
	// template<class... any>
	// virtual float RandomFuntion::f(any... a){
		
	// }
	
	template<>
	float RandomFuntion<float>::f(float x){
		
		return a*x*random.getRandom() + b*x + c;
	}
	template<>
	float RandomFuntion<float,float>::f(float x,float y){
		
		return a*x*random.getRandom() + b*y*random.getRandom() + c*x*y + d*x + e*y + fvar;
	}
	template<>
	float RandomFuntion<float,float,float>::f(float x,float y,float z){
		
		return a*x*x + b*y*y + c*z*z + d*x*y + e*x*z + fvar*y*z + g*x + h*y + i*z + j;
	}
	template<>
	float RandomFuntion<float,float,float,float>::f(float x,float y,float z,float w){
		
		return a*x*x + b*y*y + c*z*z + d*w*w + e;
	}
	template<>
	float RandomFuntion<float,float,float,float,float>::f(float x,float y,float z,float w,float t){
		
		return a*x*x + b*y*y + c*z*z + d*w*w + e*t*t + fvar;
	}
	
	
	
	
	
	
	
	
#endif 
