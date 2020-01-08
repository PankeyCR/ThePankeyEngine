

#ifndef RobotiHandTransferData_h
#define RobotiHandTransferData_h

#include "Arduino.h"
#include "Control.h"
#include "LimitServo.h"
#include "SimpleServo.h"
#include "MultiServo.h"
#include "SerialController.h"
#include "ArrayList.h"

class RobotiHandTransferData : public Control{
	private:  
		
	public:
		MultiServo *servos;
		ArrayList<String,6> *list;
		String buff;
		
		RobotiHandTransferData(MultiServo *s);
		~RobotiHandTransferData();
		void onDelete();
		SerialController *getSerial();
		bool isValidControl();
		void update();
		String getMessage();
		int moveDistance();
		String Split(String divide,int parte, char limiter);
		int SplitLenght(String divide,int parte, char limiter);
		String Split(String divide,int parte, char limiter, char fin);
};

#endif 
