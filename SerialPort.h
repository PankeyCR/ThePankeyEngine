
#ifndef SerialPort_h
#define SerialPort_h

//class SerialMessageState;

class SerialPort{	
    public:
		SerialPort(){
		}
		virtual ~SerialPort(){
		}
		// virtual bool attach(SerialMessageState* state){
			// messageState = state;
		// }
		virtual bool available(){
			return false;
		}
		virtual char read(){
			return -1;
		}
		virtual bool connected(){
			return false;
		}
		virtual void stop(){
		}
		virtual void print(String mns){
		}
		virtual void println(String mns){
		}
		virtual void operator=(SerialPort b){}
		virtual bool operator==(SerialPort b){return true;}
		virtual bool operator!=(SerialPort b){return true;}
		
		
	protected:
	// SerialMessageState* messageState = nullptr;
};
#endif 
