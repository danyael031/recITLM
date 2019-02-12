/* Instituto Tecnológico de Los Mochis
 * Ingeniería electrónica
 * Materia: Microcontroladores.
 * Profesor: Cesar Armando López Macias
 * Alumno: Dan Yael Sajarópulos Verdugo
 * 
 *      Práctica 1 Semáforo
 * 
 */
#include "semaforo.h"

Semaforo semaforo1 = {4, 8, 12};

int estado = 0;
unsigned long reloj = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(semaforo1.verde, OUTPUT);
  pinMode(semaforo1.amarillo, OUTPUT);
  pinMode(semaforo1.rojo, OUTPUT);

  digitalWrite(semaforo1.rojo, LOW);
  digitalWrite(semaforo1.verde, LOW);
  digitalWrite(semaforo1.amarillo, LOW);
}

void loop() {
  //Estado 1 Rojo encendido 3 segundos
  digitalWrite(semaforo1.amarillo, LOW);
  digitalWrite(semaforo1.rojo, HIGH);
  delay(3000);
  //Estado 2 Verde encendido 2.5 segundos
  digitalWrite(semaforo1.rojo, LOW);
  digitalWrite(semaforo1.verde, HIGH);
  delay(2500);
  //Secuencia de parpadeo color verde
  digitalWrite(semaforo1.verde, LOW);
  delay(100);
  digitalWrite(semaforo1.verde, HIGH);
  delay(100);
  digitalWrite(semaforo1.verde, LOW);
  delay(100);
  digitalWrite(semaforo1.verde, HIGH);
  delay(100);
  digitalWrite(semaforo1.verde, LOW);
  delay(100);
  
  //Estado 3 Amarillo encendido 1.5 segundos
  digitalWrite(semaforo1.amarillo, HIGH);
  delay(1500);

  
}
