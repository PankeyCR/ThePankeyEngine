
#ifndef SerialJoystickControl_h
#define SerialJoystickControl_h

#include "GameOn.h"
#include "Joystick.h"
#include "AnalogJoystick.h"
#include "SerialConnection.h"

class SerialJoystickControl : public GameOn{
    private:
	
    public:
		SerialConnection *connection=nullptr;
		Joystick *joystick=nullptr;
		SerialJoystickControl();
        bool isValidControl();
        Joystick *getJoystick();
        SerialConnection *getSerial();
        virtual void update(float tpc);
		virtual String getClassName();
		virtual String toString();
		virtual SerialJoystickControl *clone();
};

#endif 
