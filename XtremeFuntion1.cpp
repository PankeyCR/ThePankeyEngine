
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
		if(p==10){
			k=var;
		}
		if(p==11){
			l=var;
		}
		if(p==12){
			m=var;
		}
		if(p==13){
			n=var;
		}
		if(p==14){
			o=var;
		}
		if(p==15){
			pvar=var;
		}
		if(p==16){
			q=var;
		}
		if(p==17){
			r=var;
		}
		if(p==18){
			s=var;
		}
		if(p==19){
			t=var;
		}
		if(p==20){
			u=var;
		}
		if(p==21){
			v=var;
		}
		if(p==22){
			w=var;
		}
		if(p==23){
			x=var;
		}
		if(p==24){
			y=var;
		}
		if(p==25){
			z=var;
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
		
	int XtremeFuntion1::getIterationSize(){
		return 26;
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
		if(this->getIteration() == 10){
			return kdx;
		}
		if(this->getIteration() == 11){
			return ldx;
		}
		if(this->getIteration() == 12){
			return mdx;
		}
		if(this->getIteration() == 13){
			return ndx;
		}
		if(this->getIteration() == 14){
			return odx;
		}
		if(this->getIteration() == 15){
			return pdx;
		}
		if(this->getIteration() == 16){
			return qdx;
		}
		if(this->getIteration() == 17){
			return rdx;
		}
		if(this->getIteration() == 18){
			return sdx;
		}
		if(this->getIteration() == 19){
			return tdx;
		}
		if(this->getIteration() == 20){
			return udx;
		}
		if(this->getIteration() == 21){
			return vdx;
		}
		if(this->getIteration() == 22){
			return wdx;
		}
		if(this->getIteration() == 23){
			return xdx;
		}
		if(this->getIteration() == 24){
			return ydx;
		}
		if(this->getIteration() == 25){
			return zdx;
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
		if(this->getIteration() == 10){
			return &kdx;
		}
		if(this->getIteration() == 11){
			return &ldx;
		}
		if(this->getIteration() == 12){
			return &mdx;
		}
		if(this->getIteration() == 13){
			return &ndx;
		}
		if(this->getIteration() == 14){
			return &odx;
		}
		if(this->getIteration() == 15){
			return &pdx;
		}
		if(this->getIteration() == 16){
			return &qdx;
		}
		if(this->getIteration() == 17){
			return &rdx;
		}
		if(this->getIteration() == 18){
			return &sdx;
		}
		if(this->getIteration() == 19){
			return &tdx;
		}
		if(this->getIteration() == 20){
			return &udx;
		}
		if(this->getIteration() == 21){
			return &vdx;
		}
		if(this->getIteration() == 22){
			return &wdx;
		}
		if(this->getIteration() == 23){
			return &xdx;
		}
		if(this->getIteration() == 24){
			return &ydx;
		}
		if(this->getIteration() == 25){
			return &zdx;
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
		if(this->getIteration() == 10){
			kdx = var;
		}
		if(this->getIteration() == 11){
			ldx = var;
		}
		if(this->getIteration() == 12){
			mdx = var;
		}
		if(this->getIteration() == 13){
			ndx = var;
		}
		if(this->getIteration() == 14){
			odx = var;
		}
		if(this->getIteration() == 15){
			pdx = var;
		}
		if(this->getIteration() == 16){
			qdx = var;
		}
		if(this->getIteration() == 17){
			rdx = var;
		}
		if(this->getIteration() == 18){
			sdx = var;
		}
		if(this->getIteration() == 19){
			tdx = var;
		}
		if(this->getIteration() == 20){
			udx = var;
		}
		if(this->getIteration() == 21){
			vdx = var;
		}
		if(this->getIteration() == 22){
			wdx = var;
		}
		if(this->getIteration() == 23){
			xdx = var;
		}
		if(this->getIteration() == 24){
			ydx = var;
		}
		if(this->getIteration() == 25){
			zdx = var;
		}
	}
	
	float XtremeFuntion1::f(float x){
		return 	-1;
		/*
		return 	a*adx*x - a*ady + adz - adw + a*adt*adt - a*adp*adp +
				b*bdx*x - b*bdy + bdz - bdw + b*bdt*bdt - b*bdp*bdp +
				c*cdx*x - c*cdy + cdz - cdw + c*cdt*cdt - c*cdp*cdp +
				d*ddx*x - d*ddy + ddz - ddw + d*ddt*ddt - d*ddp*ddp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				f*fdx*x - f*fdy + fdz - fdw + f*fdt*fdt - f*fdp*fdp +
				g*gdx*x - g*gdy + gdz - gdw + g*gdt*gdt - g*gdp*gdp +
				h*hdx*x - h*hdy + hdz - hdw + h*hdt*hdt - h*hdp*hdp +
				i*idx*x - i*idy + idz - idw + i*idt*idt - i*idp*idp +
				j*jdx*x - j*jdy + jdz - jdw + j*jdt*jdt - j*jdp*jdp +
				k*kdx*x - k*kdy + kdz - kdw + k*kdt*kdt - k*kdp*kdp +
				l*ldx*x - l*ldy + ldz - ldw + l*ldt*ldt - l*ldp*ldp +
				m*mdx*x - m*mdy + mdz - mdw + m*mdt*mdt - m*mdp*mdp +
				n*ndx*x - n*ndy + ndz - ndw + n*ndt*ndt - n*ndp*ndp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x - e*edy + edz - edw + e*edt*edt - e*edp*edp +
				e*edx*x + e*edx - fvar + fvardx -
				g*gdx*x + h*hdx + i -
				j*jdx*x ;*/
	}
	
	
	
	
	
	
	
	
#endif 
