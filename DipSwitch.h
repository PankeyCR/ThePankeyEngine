
#ifndef DipSwitch_h
#define DipSwitch_h

#include "Arduino.h"
#include "List.h"
#include "ArrayList.h"
#include "cppObject.h"

namespace ame{

class DipSwitch : public cppObject{
    private:
		void readPins();
	
    public:
		int value;
		ArrayList<int,10> *pinList;
		
		DipSwitch();
		int getValue();
		void addPin(int pin);

        void onDelete();
        int operator &();
        void operator =(const DipSwitch& d);
        void operator =(const int& t);
        bool operator ==(const int& t);
        bool operator !=(const int& t);
};

}

#endif 
