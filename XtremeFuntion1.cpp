
#ifndef XtremeFuntion1_cpp
#define XtremeFuntion1_cpp

#include "XtremeFuntion1.h"


	
	XtremeFuntion1::XtremeFuntion1(){
		
	}
	
	XtremeFuntion1::~XtremeFuntion1(){
		
	}
		
	//cppObject part
	String XtremeFuntion1::getClassName(){
		return "XtremeFuntion1";
	}
	String XtremeFuntion1::toString(){
		return "XtremeFuntion1";
	}
	XtremeFuntion1* XtremeFuntion1::clone(){
		return this;
	}
	
	void XtremeFuntion1::set(int p, float var){
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
	
	void XtremeFuntion1::set(String name, float var){
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
	
	float XtremeFuntion1::f(float x){
		
		return 	a*adx*x - b*bdx + c - cdx +
				d*ddx*x + e*edx - fvar + fvardx -
				g*gdx*x + h*hdx + i -
				j*jdx*x ;
	}
		
	int XtremeFuntion1::getIterationSize(){
		return 20;
	}
		
	float XtremeFuntion1::getValue(){
		if(this->getIteration() == 0){
			return adx;
		}
		if(this->getIteration() == 1){
			return bdx;
		}
		if(this->getIteration() == 2){
			return cdx;
		}
		if(this->getIteration() == 3){
			return ddx;
		}
		if(this->getIteration() == 4){
			return edx;
		}
		if(this->getIteration() == 5){
			return fvardx;
		}
		if(this->getIteration() == 6){
			return gdx;
		}
		if(this->getIteration() == 7){
			return hdx;
		}
		if(this->getIteration() == 8){
			return idx;
		}
		if(this->getIteration() == 9){
			return jdx;
		}
		return -1;
	}
		
	float *XtremeFuntion1::getPointer(){
		if(this->getIteration() == 0){
			return &adx;
		}
		if(this->getIteration() == 1){
			return &bdx;
		}
		if(this->getIteration() == 2){
			return &cdx;
		}
		if(this->getIteration() == 3){
			return &ddx;
		}
		if(this->getIteration() == 4){
			return &edx;
		}
		if(this->getIteration() == 5){
			return &fvardx;
		}
		if(this->getIteration() == 6){
			return &gdx;
		}
		if(this->getIteration() == 7){
			return &hdx;
		}
		if(this->getIteration() == 8){
			return &idx;
		}
		if(this->getIteration() == 9){
			return &jdx;
		}
		return nullptr;
	}
		
	String XtremeFuntion1::getName(){
		if(this->getIteration() == 0){
			return "a";
		}
		if(this->getIteration() == 1){
			return "b";
		}
		if(this->getIteration() == 2){
			return "c";
		}
		if(this->getIteration() == 3){
			return "d";
		}
		if(this->getIteration() == 4){
			return "e";
		}
		if(this->getIteration() == 5){
			return "f";
		}
		if(this->getIteration() == 6){
			return "g";
		}
		if(this->getIteration() == 7){
			return "h";
		}
		if(this->getIteration() == 8){
			return "i";
		}
		if(this->getIteration() == 9){
			return "j";
		}
		return "";
	}
		
	bool XtremeFuntion1::isModifiable(){
		return true;
	}
		
	void XtremeFuntion1::set(float var){
		if(this->getIteration() == 0){
			adx = var;
		}
		if(this->getIteration() == 1){
			bdx = var;
		}
		if(this->getIteration() == 2){
			cdx = var;
		}
		if(this->getIteration() == 3){
			ddx = var;
		}
		if(this->getIteration() == 4){
			edx = var;
		}
		if(this->getIteration() == 5){
			fvardx = var;
		}
		if(this->getIteration() == 6){
			gdx = var;
		}
		if(this->getIteration() == 7){
			hdx = var;
		}
		if(this->getIteration() == 8){
			idx = var;
		}
		if(this->getIteration() == 9){
			jdx = var;
		}
	}
	
	
	
	
	
	
	
	
#endif 
