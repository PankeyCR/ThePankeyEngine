

#ifndef RobotiHandTransferData_h
#define RobotiHandTransferData_h

#include "Arduino.h"
#include "GameOn.h"
#include "LimitServo.h"
#include "SimpleServo.h"
#include "MultiServo.h"
#include "SerialController.h"
#include "ArrayList.h"

class RobotiHandTransferData : public GameOn{
	private:  
		
	public:
		MultiServo *servos;
		ArrayList<String,6> *list;
		String buff;
		
		RobotiHandTransferData(MultiServo *s);
		~RobotiHandTransferData();
		
		SerialController *getSerial();
		bool isValidControl();
		void update(float tpc);
		
		String getMessage();
		int moveDistance();
		String Split(String divide,int parte, char limiter);
		int SplitLenght(String divide,int parte, char limiter);
		String Split(String divide,int parte, char limiter, char fin);
};

#endif 
