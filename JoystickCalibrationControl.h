
#ifndef JoystickCalibrationControl_h
#define JoystickCalibrationControl_h

#include "Control.h"
#include "Joystick.h"
#include "AnalogJoystick.h"

class JoystickCalibrationControl : public Control{
    private:
	
    public:
		JoystickCalibrationControl();
		~JoystickCalibrationControl();
        bool isValidControl();
        AnalogJoystick *getJoystick();
        void update();
        void onDelete();
		String getClassName();
		String toString();
		JoystickCalibrationControl *clone();
};

#endif 
