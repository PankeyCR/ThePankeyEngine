
#include "Ultrasonic.h"
int contador=0;
int distance_prev=0;


    Ultrasonic::Ultrasonic() {
       
	}
       Ultrasonic Ultrasonic::setPins(int TrigPin, int EchoPin) {
			trigPin =TrigPin;
        echoPin=EchoPin;
		pinMode(echoPin, INPUT);
		pinMode(trigPin, OUTPUT);

        }
    float Ultrasonic::getDistance() { 
      int maximumRange = 500;
      int minimumRange = 0; 
      long duration, distance;
  
      digitalWrite(trigPin, LOW); 
      delay(112); 

      digitalWrite(trigPin, HIGH);
      delay(110); 
 
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
      distance = duration/58.2;
      return distance;
    }
    float Ultrasonic::getSafeDistance(int safe) { 
      int maximumRange = 500;
      int minimumRange = 0; 
      long duration, distance;
  
      digitalWrite(trigPin, LOW); 
      delay(112); 

      digitalWrite(trigPin, HIGH);
      delay(110); 
 
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
      distance = duration/58.2;
      if(distance_prev==distance){
        distance_prev=distance;
        contador++;
      }else{
        contador=0;
      }
        distance_prev=distance;
        if(contador>=safe){
			return distance;
        }
		return -1*distance;
    }
