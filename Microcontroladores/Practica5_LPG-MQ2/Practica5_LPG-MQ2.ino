#include "DHT11.h"
#define REL1 3
#define REL2 7


dht11 sens;


char datSer[4];

//bool flagSendData = false;
int estRel1 = HIGH;
int estRel2 = HIGH;

const int pinMQ2 = A0;
const int resModulo = 5;
const int resSalida = 10;

const int tiempoEntreMuestras = 100;
const int numeroMuestras = 5;

const float X0 = 200; const float Y0 = 7;
const float X1 = 10000; const float Y1 = 2;

const float punto0[] = {log10(X0),log10(Y0)};
const float punto1[] = {log10(X1),log10(Y1)};

const float A = (punto1[1] - punto0[1]) / (punto1[0] - punto0[0]);
const float B = (punto0[1] - A) * punto0[0];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  digitalWrite(7,HIGH);
}

float leerSensorMQ(int MQpin)
{
  float res = 0;
  for(int i = 0; i < numeroMuestras; i++)
  {
    res += obtenerResMQ(analogRead(pinMQ2));
    delay(tiempoEntreMuestras);
  }
  return res / numeroMuestras;
}

float obtenerResMQ(int ORATDLA)
{
  return (((float)resModulo / 1000.0*(1023 - ORATDLA) / ORATDLA));
}

float calcularConcentracion(float cocienteRSRO)
{
  return pow(10, A * log(cocienteRSRO) + B);
}

void enviarDatos(){
  leerDHT11(&sens);
  float rs = leerSensorMQ(pinMQ2);
  float concentracion = calcularConcentracion(rs)/resSalida;

  Serial.print("~/");
  Serial.print(sens.B[0]);
  Serial.print("/");
  Serial.print(sens.B[2]);
  Serial.print("/");
  Serial.print(concentracion);
  Serial.print("/\n");
}

void serialEvent() {
  Serial.readBytes(datSer, 4);
  Serial.print(datSer[0]);
  Serial.print("/");
  Serial.print(datSer[1]);
  Serial.print("/");
  Serial.print(datSer[2]);
  Serial.print("/");
  Serial.print("\n");
  

  if(datSer[3] == 10){
    if(datSer[0] == 64){//@
      enviarDatos();
    }
    else if(datSer[0] == 32){// espacio
      
      estRel1 = (datSer[1] == 49) ? LOW : HIGH ;
      estRel2 = (datSer[2] == 49) ? LOW : HIGH ;
      digitalWrite(REL1, estRel1);
      digitalWrite(REL2, estRel2);
    }
  }

  for(int i = 0; i <= 3; i ++){
    datSer[i] = 0x00;
  }
}

void loop() {
  
  
}
