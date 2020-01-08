

#ifndef LimitServo_h
#define LimitServo_h

#include "MultiServo.h"
#include "ArrayList.h"
#include "List.h"
#include "PList.h"

template<int size>
class LimitServo : public MultiServo{
	private:
	
    public:
		Servo **servos;
		ArrayList<int,size> *limitMax;
		ArrayList<int,size> *limitMin;
		int range=100;
		
		LimitServo(){
			servos = new Servo*[size];
			for(int x=0; x < size; x++){
				servos[x] = new Servo();
			}
			limitMax = new ArrayList<int,size>();
			limitMin = new ArrayList<int,size>();
		}
		
		~LimitServo(){
			for(int x=0; x < size; x++){
				delete servos[x];
			}
			delete servos;
			limitMax->onDelete();
			limitMin->onDelete();
		}
		
		void setRange(int Range){
			this->range= Range;
		}
		
		void addMaxLimit(int sel,int max){
			limitMax->set(sel,max);
		}
		
		void addMinLimit(int sel,int min){
			limitMin->set(sel,min);
		}
		
		Servo *getServo(int sel){
			if(sel < size){
				return NULL;				
			}
			return servos[sel];
		}
		
		void attach(int sel,int i){
			if(sel < size){
				return NULL;				
			}
			servos[sel]->attach(i);
		}
		
		void detach(int sel,int i){
			if(sel < size){
				return NULL;				
			}
			servos[sel]->detach();
		}
		
		int getLimitMax(int sel){
			if(limitMax->getByPos(sel) == NULL){
				return NULL;
			}
			return *limitMax->getByPos(sel);
		}
		
		int getLimitMin(int sel){
			if(limitMin->getByPos(sel) == NULL){
				return NULL;
			}
			return *limitMin->getByPos(sel);
		}
		
		int MoveServo(int sel,int angle){
			if(sel >= size
					|| limitMax->getByPos(sel) == NULL
					|| limitMin->getByPos(sel) == NULL){
				return 0;				
			}
			int limitmax = *limitMax->getByPos(sel);
			int limitmin = *limitMin->getByPos(sel);
			bool invers = (limitmax - limitmin)<0;
			int out=0;
			if(invers){
				int dist = limitmin-limitmax;
				int outToAdd = (float)((float)dist/(float)range)*angle;
				out = limitmax+outToAdd;
				servos[sel]->write(out);				
			}else{
				int dist = limitmax-limitmin;
				int outToAdd = (float)((float)dist/(float)range)*angle;
				out = limitmin+outToAdd;
				servos[sel]->write(out);				
			}
			return out;
		}
};

#endif 
