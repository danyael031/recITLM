#include"DHT11.h"


DHT11::DHT11(uint8_t port = 3) {
  _port = port;
}

byte DHT11::getByteTemperatura() {
  return data[0];
}

byte DHT11::getByteHumedad() {
  return data[2];
}

bool DHT11::getEstado() {
  return estado;
}

void DHT11::LimpiarData() {
  for (byte i = 0; i <= 4; i++) {
    data[i] = 0x00;
  }
}

bool DHT11::Read() {
  LimpiarData();
  pinMode(_port, OUTPUT);  //Colocamos el puerto en modo de salida
  digitalWrite(_port, LOW);//enviamos a tierra durante 18 milisegundos
  delay(18);
  digitalWrite(_port, HIGH);
  delayMicroseconds(40);
  pinMode(_port, INPUT);
  unsigned long tiempo;
  while (digitalRead(_port) == LOW) {}
  while (digitalRead(_port) == HIGH) {}
  
  for (int iB = 0; iB <= 4; iB++) {
    for (int i = 7; i >= 0; i--) {
      while (digitalRead(_port) == LOW) {}
      tiempo = micros();
      while (digitalRead(_port) == HIGH) {}
      if ((micros() - tiempo) > 30) {
        bitWrite(data[iB], i, 1);
      }
    }
  }
  
  byte checksum = data[0] + data[1] + data[2] + data[3] ;
  if (data[4] == checksum) {
    estado = true;
  }
  else {
    estado = false;
  }
  return estado;

}
