

#ifndef Display7Segments_cpp
#define Display7Segments_cpp

#include "Display7Segments.h"

	Display7Segments::Display7Segments(int A,int B,int C,int D,int E,int F,int G){
		a=A;
		b=B;
		c=C;
		d=D;
		e=E;
		f=F;
		g=G;
		pinMode(A,OUTPUT);
		pinMode(B,OUTPUT);
		pinMode(C,OUTPUT);
		pinMode(D,OUTPUT);
		pinMode(E,OUTPUT);
		pinMode(F,OUTPUT);
		pinMode(G,OUTPUT);	
	}
	
	Display7Segments::Display7Segments(int A,int B,int C,int D,int E,int F,int G,int point){
		a=A;
		b=B;
		c=C;
		d=D;
		e=E;
		f=F;
		g=G;
		p=point;
		pinMode(A,OUTPUT);
		pinMode(B,OUTPUT);
		pinMode(C,OUTPUT);
		pinMode(D,OUTPUT);
		pinMode(E,OUTPUT);
		pinMode(F,OUTPUT);
		pinMode(G,OUTPUT);
		pinMode(point,OUTPUT);		
	}
	Display7Segments::~Display7Segments(){
		
	}
	
	void Display7Segments::setDisplay(bool pinA,bool pinB,bool pinC,
								 bool pinD,bool pinE,bool pinF,bool pinG){			
		digitalWrite(a,pinA);						
		digitalWrite(b,pinB);			
		digitalWrite(c,pinC);		
		digitalWrite(d,pinD);		
		digitalWrite(e,pinE);		
		digitalWrite(f,pinF);		
		digitalWrite(g,pinG);
	}
	
	void Display7Segments::setDisplayPoint(bool point){
		digitalWrite(p,point);
	}
	
	int Display7Segments::getDisplay(){
		return digito;
	}
	
	void Display7Segments::Number0(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(1,1,1,1,1,1,0);			
	}
	
	void Display7Segments::Number1(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(0,1,1,0,0,0,0);			
	}
	
	void Display7Segments::Number2(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(1,1,0,1,1,0,1);			
	}
	
	void Display7Segments::Number3(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(1,1,1,1,0,0,1);			
	}
	
	void Display7Segments::Number4(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(0,1,1,0,0,1,1);			
	}
	
	void Display7Segments::Number5(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(1,0,1,1,0,1,1);			
	}
	
	void Display7Segments::Number6(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(1,0,1,1,1,1,1);			
	}
	
	void Display7Segments::Number7(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(1,1,1,0,0,0,0);			
	}
	
	void Display7Segments::Number8(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(1,1,1,1,1,1,1);			
	}
	
	void Display7Segments::Number9(){
		/////////////////a,b,c,d,e,f,g
		this->setDisplay(1,1,1,1,0,1,1);			
	}
	
	void Display7Segments::setDisplay(int digit){
		this->digito = digit;
		if(digit == 0){
			this->Number0();
		}
		if(digit == 1){
			this->Number1();
		}
		if(digit == 2){
			this->Number2();
		}
		if(digit == 3){
			this->Number3();
		}
		if(digit == 4){
			this->Number4();
		}
		if(digit == 5){
			this->Number5();
		}
		if(digit == 6){
			this->Number6();
		}
		if(digit == 7){
			this->Number7();
		}
		if(digit == 8){
			this->Number8();
		}
		if(digit == 9){
			this->Number9();
		}
	}
#endif 
