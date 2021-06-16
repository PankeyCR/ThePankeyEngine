
#ifndef JoystickCalibrationControl_h
#define JoystickCalibrationControl_h

#include "GameOn.h"
#include "GameObject.h"
#include "Joystick.h"
#include "AnalogJoystick.h"
#include "cppObjectClass.h"

class JoystickCalibrationControl : public GameOn{
    private:
	
    public:
		JoystickCalibrationControl();
		~JoystickCalibrationControl();
		
        bool isValidControl();
        AnalogJoystick *getJoystick();
		
        void update(float tpc);
		
		cppObjectClass* getClass();
		String toString();
		
		JoystickCalibrationControl *clone();
};

#endif 
