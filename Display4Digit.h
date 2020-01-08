

#ifndef Display4Digit_h
#define Display4Digit_h

#include "Arduino.h"

class Display4Digit{
    public:
		int a,b,c,d,e,f,g,p,d1,d2,d3,d4,count=0;
		int num1,num2,num3,num4=0;
		Display4Digit(int A,int B,int C,int D,int E,int F,int G,int point,int digit1,int digit2,int digit3,int digit4);
		void update();
		void setDigit(bool pinA,bool pinB,bool pinC,
								     bool pinD,bool pinE,bool pinF,bool pinG);
		
		void setDigit(int digit,int num);
		void setTime(int hour,int min);
		
	private:
		void actualDigit(int num);
		void setNumber(int num);
		void Number0();
		void Number1();
		void Number2();
		void Number3();
		void Number4();
		void Number5();
		void Number6();
		void Number7();
		void Number8();
		void Number9();
};

#endif 
