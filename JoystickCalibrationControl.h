
#ifndef JoystickCalibrationControl_h
#define JoystickCalibrationControl_h

#include "GameOn.h"
#include "GameObject.h"
#include "Joystick.h"
#include "AnalogJoystick.h"

class JoystickCalibrationControl : public GameOn{
    private:
	
    public:
		JoystickCalibrationControl();
		~JoystickCalibrationControl();
		
        bool isValidControl();
        AnalogJoystick *getJoystick();
		
        void update(float tpc);
		
		String getClassName();
		String toString();
		
		JoystickCalibrationControl *clone();
};

#endif 
