#include"DHT11.h"
#include"untrasonico.h"
//#include"dht.h"

#define pinDHT 5

//dht11 dht;

DHT11 dht(pinDHT);
//Ultrasonico ultra(pinTrigger, pinEcho);

void setup() {
  Serial.begin(9600);
}

void loop(){
  if(!dht.Read()){
  Serial.println(dht.getByteTemperatura());
  Serial.println(dht.getByteHumedad());
  }

  delay(300);
}
