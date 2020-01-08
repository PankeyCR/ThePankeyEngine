
#ifndef Logger_h
#define Logger_h

#ifndef LogSerial
	#define LogSerial(serial) Logger::getLog()->setSerial(serial)
#endif

#ifndef Log
	#define Log(priority,mns) Logger::Logging(priority,mns)
#endif 

#include "Stream.h"
class Logger {
	public:
		virtual ~Logger();
		static Logger *getLog();
		static void Logging(String priority,String mns);
	
		virtual void setSerial(Stream *port);
	private:
		Logger();
		static Logger *log;
		Stream *port = nullptr;
};
#endif 
