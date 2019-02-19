struct  hcsr04{
  int Trig;
  int Echo;
  unsigned long inputSignal;
  unsigned int distanciaCM;
  unsigned int distanciaIN;
};

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


