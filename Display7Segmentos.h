

#ifndef Display7Segmentos_h
#define Display7Segmentos_h

#include "Arduino.h"

class Display7Segmentos{
    public:
		int a,b,c,d,e,f,g,p=0;
		int digito=0;
		Display7Segmentos(int A,int B,int C,int D,int E,int F,int G);
		Display7Segmentos(int A,int B,int C,int D,int E,int F,int G,int point);
		~Display7Segmentos();
		
		void setDisplay(bool pinA,bool pinB,bool pinC, bool pinD,bool pinE,bool pinF,bool pinG);
		
		void setDisplay(int digit);
		void setDisplayPoint(bool point);
		
		int getDisplay();
	private:
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
