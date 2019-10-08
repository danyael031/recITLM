#include "untrasonico.h"

Ultrasonico::Ultrasonico(uint8_t pinTrigger, uint8_t pinEcho) {
  PinEcho = pinEcho;
  PinTrigger = pinTrigger;
  pinMode(PinTrigger, OUTPUT);
  pinMode(PinEcho, INPUT);
}

float Ultrasonico::ObtenerDistancia() {
  EnviarTrigger();
  float tiempo = 0;
  tiempo = pulseIn(PinEcho, HIGH, 38000); //Lectura de cantidad de tiempo con la señal en high
  float distancia = 0;
  distancia = (0.034 * tiempo) / 2;
}

void Ultrasonico::EnviarTrigger() {
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(60);
  digitalWrite(PinTrigger, LOW);
}
