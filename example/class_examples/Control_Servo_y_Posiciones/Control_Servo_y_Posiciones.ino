
#include "ServoPosition.h"
#include "Pulsador.h"
#include "Display7Segmentos.h"

//Se inicia el pulsador que aumenta la posicion, en el pin 0
Pulsador pulsadorA(0);

//Se inicia el pulsador que disminuye la posicion, en el pin 1
Pulsador pulsadorB(1);

//Se inicia el pulsador que reinicia si esta en posicion, en el pin 2
Pulsador pulsadorC(2);

//Se inicia el servo motor, en el pin 3
ServoPosition motor(3);

//////////////////////////a,b,c,d,e,f,g,punto
Display7Segmentos Display(4,5,6,7,8,9,10,11);//aqui se inicia es display, asignando los pines para cada letra
int estado = 0;//posicion actual del servo
  
void setup() {// no es necesario iniciar casi nada porque todo se inicio en cada objeto de cada clase(Pulsador,ServoPosition,Display7Segmentos)
  motor.set5Points(20,0,40,60,80);//se establecen las 5 posiciones del servo
  Display.setDisplayPoint(LOW);//se apaga el punto del display
}

void loop() {
  //Aqui se actualiza la logica para obtener los metodos isClick, isPressed, isReleased 
  //que nos dicen el estado de los pulsadores
  
  //isClick - dice cuando se hace click, si se apreta y se deja apretado, solo se activa una vez
  //isPressed - dice cuando se esta apretando
  //isReleased - dice cuando se libera el pulsador, solo se activa una vez al soltarlo
  pulsadorA.update();
  pulsadorB.update();
  pulsadorC.update();
  
  //if(pulsadorA.isReleased()){
  if(pulsadorA.isClick()){// este if se encarga de sumar la posicion
    estado++;//suma la posicion
    if(estado > 4){// si es mayor que la ultima posicion disponible
      estado = 4;//se queda en la ultima posicion
    }
    motor.setPosition(estado);// y se asigna la posicion al servo
    Display.setDisplay(estado);// y tambien al display
  }
  
  if(pulsadorB.isClick()){// este if se encarga de disminuir la posicion al servo
    estado--;//disminuye la posicion
    if(estado < 0){//si la posicion es menor a 0
      estado = 0;// se queda en 0
    }
    motor.setPosition(estado);// y se asigna la posicion al servo
    Display.setDisplay(estado);// y tambien al display
  }
  
  if(pulsadorC.isClick()){// este if se encarga de reiniciar la posicion
    if(estado == 1 || estado == 2){// si la posicion esta en 1 o 2 
      estado = 0;// se reinicia
    }
    motor.setPosition(estado);// y se cambia la posicion a 0
    Display.setDisplay(estado);// y tambien el display cambia el digito a 0
  }
}
