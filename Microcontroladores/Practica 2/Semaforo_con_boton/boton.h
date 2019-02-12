
struct botonPush{
	int puerto = 2;
	unsigned long delayBoton = 20;
	int valBoton = 0;
	int carryBoton = 0;
	bool state = false;
};

/*
 * BotonPushValue() utiliza un puntero de el struct botonPush para administrar la señal de entrada de un botón. 
 * Existen diferentes tipos de botón, los cuales se selecciónan con el parámetro tipoBoton:
 * 0: el botón por defecto que sólo conserva el estado de encendido cuando se mantiene presionado.
 * 1: el botón tipo switch que cambia el estado cada vez que es presionado.
 *
*/  
bool BotonPushValue(botonPush* btp, int tipoBoton){
  btp->valBoton = digitalRead(btp->puerto);

  if(btp->delayBoton <= millis()){
  if (btp->valBoton == HIGH && btp->carryBoton == LOW){
    btp->carryBoton = btp->valBoton;
  }
  else if(btp->valBoton == LOW && btp->carryBoton == HIGH){
    btp->delayBoton = millis()+20;
    btp->carryBoton = LOW;
    btp->state = !btp->state;
    
  } 
  }
  return btp->state;
	
}
