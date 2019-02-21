struct Semaforo{
  int verde;
  int amarillo;
  int rojo;
};



struct  hcsr04{
  int Trig;
  int Echo;
  unsigned long inputSignal;
  unsigned int distanciaCM;
  unsigned int distanciaIN;
};

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
bool BotonPushValue(botonPush* btp, int tipoBoton=0){
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

unsigned int distanciaHCSR04(hcsr04* ulSo , int selecUnidades = 0){
    digitalWrite(ulSo->Trig, HIGH); //Enviando pulso al trigger del sensor
    delayMicroseconds(10);// duración del pulso
    digitalWrite(ulSo->Trig, LOW);
    ulSo->inputSignal = pulseIn(ulSo->Echo, HIGH);
    ulSo->distanciaCM = ulSo->inputSignal / 58;
    ulSo->distanciaIN = ulSo->inputSignal / 148;
    switch (selecUnidades){
      case 0:
      return ulSo->distanciaCM;
      break;
      case 1:
      return ulSo->distanciaIN;
      break;
      default:
      return 0;
      break;
      }
    
    
  }

void iniciarHCSR04(hcsr04* ulSo, int pTrig = 5, int pEcho = 6){
  ulSo->Trig = pTrig;
  ulSo->Echo = pEcho;
  
  pinMode(ulSo->Trig, OUTPUT);
  pinMode(ulSo->Echo, INPUT);
  }


