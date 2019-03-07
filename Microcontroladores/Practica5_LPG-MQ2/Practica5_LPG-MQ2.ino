#include "DHT11.h"

dht11 sens;

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

void loop() {
  // put your main code here, to run repeatedly:
  leerDHT11(&sens);
  float rs = leerSensorMQ(pinMQ2);
  float concentracion = calcularConcentracion(rs)/resSalida;

  

  //Serial.print("Concentración = ");
  Serial.print("~/");
  Serial.print(sens.B[0]);
  Serial.print("/");
  Serial.print(sens.B[2]);
  Serial.print("/");
  Serial.print(concentracion);
  Serial.println("/");

//  while(!(Serial.available() > 0)){
//    // read the incoming byte:
//    int incomingByte = Serial.read();
//    Serial.println(incomingByte);
//
//    if(incomingByte == 0){
//      digitalWrite(7,HIGH);
//    }
//    else if(incomingByte == 1){
//      digitalWrite(7,LOW);
//    }
//  }
  
}
