

#ifndef Display4Digit_cpp
#define Display4Digit_cpp

#include "Display4Digit.h"

		Display4Digit::Display4Digit(int A,int B,int C,int D,int E,int F,int G,int point,
										int digit1,int digit2,int digit3,int digit4){
			a=A;
			b=B;
			c=C;
			d=D;
			e=E;
			f=F;
			g=G;
			p=point;
			d1=digit1;
			d2=digit2;
			d3=digit3;
			d4=digit4;
			pinMode(A,OUTPUT);
			pinMode(B,OUTPUT);
			pinMode(C,OUTPUT);
			pinMode(D,OUTPUT);
			pinMode(E,OUTPUT);
			pinMode(F,OUTPUT);
			pinMode(G,OUTPUT);
			pinMode(point,OUTPUT);
			pinMode(digit1,OUTPUT);
			pinMode(digit2,OUTPUT);
			pinMode(digit3,OUTPUT);
			pinMode(digit4,OUTPUT);		
		}
		
		void Display4Digit::update(){
			actualDigit(count);
			if(count == 0){
				setNumber(num1);				
			}
			if(count == 1){
				setNumber(num2);				
			}
			if(count == 2){
				setNumber(num3);				
			}
			if(count == 3){
				setNumber(num4);
			}
			count++;
			if(count == 4){
				count = 0;
			}
		}
		
		void Display4Digit::setDigit(bool pinA,bool pinB,bool pinC,
								     bool pinD,bool pinE,bool pinF,bool pinG){			
			digitalWrite(a,pinA);						
			digitalWrite(b,pinB);			
			digitalWrite(c,pinC);		
			digitalWrite(d,pinD);		
			digitalWrite(e,pinE);		
			digitalWrite(f,pinF);		
			digitalWrite(g,pinG);
		}
		
		void Display4Digit::actualDigit(int num){
			if(num == 0){	
				digitalWrite(d1,HIGH);		
				digitalWrite(d2,LOW);		
				digitalWrite(d3,LOW);		
				digitalWrite(d4,LOW);				
			}
			if(num == 1){	
				digitalWrite(d1,LOW);		
				digitalWrite(d2,HIGH);		
				digitalWrite(d3,LOW);		
				digitalWrite(d4,LOW);				
			}
			if(num == 2){	
				digitalWrite(d1,LOW);		
				digitalWrite(d2,LOW);		
				digitalWrite(d3,HIGH);		
				digitalWrite(d4,LOW);				
			}
			if(num == 3){	
				digitalWrite(d1,LOW);		
				digitalWrite(d2,LOW);		
				digitalWrite(d3,LOW);		
				digitalWrite(d4,HIGH);				
			}
		}
		
		void Display4Digit::setNumber(int num){
			if(num == 0){
				Number0();
			}
			if(num == 1){
				Number1();
			}
			if(num == 2){
				Number2();
			}
			if(num == 3){
				Number3();
			}
			if(num == 4){
				Number4();
			}
			if(num == 5){
				Number5();
			}
			if(num == 6){
				Number6();
			}
			if(num == 7){
				Number7();
			}
			if(num == 8){
				Number8();
			}
			if(num == 9){
				Number9();
			}
		}
		
		void Display4Digit::Number0(){
			setDigit(0,0,0,0,0,0,1);			
		}
		
		void Display4Digit::Number1(){
			setDigit(1,0,0,1,1,1,1);			
		}
		
		void Display4Digit::Number2(){
			setDigit(0,0,1,0,0,1,0);			
		}
		
		void Display4Digit::Number3(){
			setDigit(0,0,0,0,1,1,0);			
		}
		
		void Display4Digit::Number4(){
			setDigit(0,0,0,0,0,0,0);			
		}
		
		void Display4Digit::Number5(){
			setDigit(0,0,0,0,0,0,0);			
		}
		
		void Display4Digit::Number6(){
			setDigit(0,0,0,0,0,0,0);			
		}
		
		void Display4Digit::Number7(){
			setDigit(0,0,0,0,0,0,0);			
		}
		
		void Display4Digit::Number8(){
			setDigit(0,0,0,0,0,0,0);			
		}
		
		void Display4Digit::Number9(){
			setDigit(0,0,0,0,0,0,0);			
		}
		
		void Display4Digit::setDigit(int digit,int num){
			if(digit == 0){
				num1 = num;
			}
			if(digit == 1){
				num2 = num;
			}
			if(digit == 2){
				num3 = num;
			}
			if(digit == 3){
				num4 = num;
			}		
		}
		
		void Display4Digit::setTime(int hour,int min){
			if (hour<10){
				num1 = 0;
				num2 = hour;
			}
			else{
				num1 = ((float)hour)/10;
				num2 = hour%10;
			}
			if (min<10){
				num3 = 0;
				num4 = min;
			}
			else{
				num3 = ((float)min)/10;
				num4 = min%10;
			}			
		}
#endif 
