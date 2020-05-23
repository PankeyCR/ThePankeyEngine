
#ifndef SerialController_h
#define SerialController_h

#include "SerialConnection.h"
#include "GameObject.h"
#include "Arduino.h"
#include "ArrayList.h"
#include "List.h"

class SerialController : public SerialConnection , public GameObject{
    public:
		SerialController();
		~SerialController();
		
		String getClassName();
		String toString();
		SerialController *clone();
		
		String Split(String divide,int parte, char limiter);
		int SplitLenght(String divide,int parte, char limiter);
		String Split(String divide,int parte, char limiter, char fin);
    private:
		
};

#endif 
