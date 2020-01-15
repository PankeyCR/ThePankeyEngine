
#ifndef CuadraticFuntion_cpp
#define CuadraticFuntion_cpp

#include "CuadraticFuntion.h"


	// template<class... any>
	// CuadraticFuntion<any...>::CuadraticFuntion(){
		
	// }
		
	// template<class... any>
	// CuadraticFuntion<any...>::~CuadraticFuntion(){
		
	// }
	
	template<>
	CuadraticFuntion<float>::CuadraticFuntion(){
		
	}
	
	template<>
	CuadraticFuntion<float,float>::CuadraticFuntion(){
		
	}
	
	template<>
	CuadraticFuntion<float,float,float>::CuadraticFuntion(){
		
	}
	
	template<>
	CuadraticFuntion<float,float,float,float>::CuadraticFuntion(){
		
	}
	
	template<>
	CuadraticFuntion<float,float,float,float,float>::CuadraticFuntion(){
		
	}
	
	template<>
	CuadraticFuntion<float>::~CuadraticFuntion(){
		
	}
	
	template<>
	CuadraticFuntion<float,float>::~CuadraticFuntion(){
		
	}
	
	template<>
	CuadraticFuntion<float,float,float>::~CuadraticFuntion(){
		
	}
	
	template<>
	CuadraticFuntion<float,float,float,float>::~CuadraticFuntion(){
		
	}
	
	template<>
	CuadraticFuntion<float,float,float,float,float>::~CuadraticFuntion(){
		
	}
		
	//cppObject part
	template<class... any>
	String CuadraticFuntion<any...>::getClassName(){
		return "CuadraticFuntion";
	}
	template<class... any>
	String CuadraticFuntion<any...>::toString(){
		return "CuadraticFuntion";
	}
	template<class... any>
	CuadraticFuntion<any...>* CuadraticFuntion<any...>::clone(){
		return this;
	}
	
	template<class... any>
	void CuadraticFuntion<any...>::set(int p, float var){
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
	void CuadraticFuntion<any...>::set(String name, float var){
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
	// virtual float CuadraticFuntion::f(any... a){
		
	// }
	
	template<>
	float CuadraticFuntion<float>::f(float x){
		
		return a*x*x + b*x + c;
	}
	template<>
	float CuadraticFuntion<float,float>::f(float x,float y){
		
		return a*x*x + b*y*y + c*x*y + d*x + e*y + fvar;
	}
	template<>
	float CuadraticFuntion<float,float,float>::f(float x,float y,float z){
		
		return a*x*x + b*y*y + c*z*z + d*x*y + e*x*z + fvar*y*z + g*x + h*y + i*z + j;
	}
	template<>
	float CuadraticFuntion<float,float,float,float>::f(float x,float y,float z,float w){
		
		return a*x*x + b*y*y + c*z*z + d*w*w + e;
	}
	template<>
	float CuadraticFuntion<float,float,float,float,float>::f(float x,float y,float z,float w,float t){
		
		return a*x*x + b*y*y + c*z*z + d*w*w + e*t*t + fvar;
	}
		
	template<class... any>
	int CuadraticFuntion<any...>::getIterationSize(){
		return 10;
	}
		
	template<class... any>
	float CuadraticFuntion<any...>::getValue(){
		if(this->getIteration() == 0){
			return a;
		}
		if(this->getIteration() == 0){
			return b;
		}
		if(this->getIteration() == 0){
			return c;
		}
		if(this->getIteration() == 0){
			return d;
		}
		if(this->getIteration() == 0){
			return e;
		}
		if(this->getIteration() == 0){
			return fvar;
		}
		if(this->getIteration() == 0){
			return g;
		}
		if(this->getIteration() == 0){
			return h;
		}
		if(this->getIteration() == 0){
			return i;
		}
		if(this->getIteration() == 0){
			return j;
		}
		return -1;
	}
		
	template<class... any>
	float *CuadraticFuntion<any...>::getPointer(){
		if(this->getIteration() == 0){
			return &a;
		}
		if(this->getIteration() == 0){
			return &b;
		}
		if(this->getIteration() == 0){
			return &c;
		}
		if(this->getIteration() == 0){
			return &d;
		}
		if(this->getIteration() == 0){
			return &e;
		}
		if(this->getIteration() == 0){
			return &fvar;
		}
		if(this->getIteration() == 0){
			return &g;
		}
		if(this->getIteration() == 0){
			return &h;
		}
		if(this->getIteration() == 0){
			return &i;
		}
		if(this->getIteration() == 0){
			return &j;
		}
		return nullptr;
	}
		
	template<class... any>
	String CuadraticFuntion<any...>::getName(){
		if(this->getIteration() == 0){
			return "a";
		}
		if(this->getIteration() == 0){
			return "b";
		}
		if(this->getIteration() == 0){
			return "c";
		}
		if(this->getIteration() == 0){
			return "d";
		}
		if(this->getIteration() == 0){
			return "e";
		}
		if(this->getIteration() == 0){
			return "f";
		}
		if(this->getIteration() == 0){
			return "g";
		}
		if(this->getIteration() == 0){
			return "h";
		}
		if(this->getIteration() == 0){
			return "i";
		}
		if(this->getIteration() == 0){
			return "j";
		}
		return "";
	}
		
	template<class... any>
	bool CuadraticFuntion<any...>::isModifiable(){
		return true;
	}
		
	template<class... any>
	void CuadraticFuntion<any...>::set(float var){
		if(this->getIteration() == 0){
			a = var;
		}
		if(this->getIteration() == 0){
			b = var;
		}
		if(this->getIteration() == 0){
			c = var;
		}
		if(this->getIteration() == 0){
			d = var;
		}
		if(this->getIteration() == 0){
			e = var;
		}
		if(this->getIteration() == 0){
			fvar = var;
		}
		if(this->getIteration() == 0){
			g = var;
		}
		if(this->getIteration() == 0){
			h = var;
		}
		if(this->getIteration() == 0){
			i = var;
		}
		if(this->getIteration() == 0){
			j = var;
		}
	}
	
	
	
	
	
	
	
	
#endif 
