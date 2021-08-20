
#ifndef GPRS_V1_1b_h
#define GPRS_V1_1b_h

#include "Arduino.h"
#include "Stream.h"

namespace ame{

class GPRS_V1_1b {
    public:
		GPRS_V1_1b();
		~GPRS_V1_1b();
		String AtMode_List(int atmode_list);
		void SendSim800cMns(Stream *port,String telefono,String mns);
		void SendSim800cLongMns(Stream *port,String telefono,String mns[],int sizee);
		void ListenerSim800cMns(Stream *port);
		String ReceiveSim800cMns(Stream *port);
		String Sim800cSplit(String cmd,int parte, char limiter);
      
    private:  
		Stream *port;
		String inputStringGprs="";
};

}

#endif 
