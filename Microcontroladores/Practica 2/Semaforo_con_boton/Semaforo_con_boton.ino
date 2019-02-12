
/* Instituto Tecnológico de Los Mochis
 * Ingeniería electrónica
 * Materia: Microcontroladores.
 * Profesor: Cesar Armando López Macias
 * Alumno: Dan Yael Sajarópulos Verdugo
 * 
 *      Práctica 2 Semáforo con botón.
 *  
 */
#include "semaforo.h"
#include "boton.h"

#define DELAYBOTON 20

//El struct semáforo tiene el siguiente órden de los colores: verde, amarillo y rojo. 
Semaforo semaforo1 = {4, 8, 12};
botonPush boton1;

int estado = 0;
bool guardado = false;
unsigned long relojf = 0;

unsigned long tRestante = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(semaforo1.verde, OUTPUT);
  pinMode(semaforo1.amarillo, OUTPUT);
  pinMode(semaforo1.rojo, OUTPUT);
  pinMode(boton1.puerto, INPUT);
  
}

void loop() {

BotonPushValue(&boton1, 0);
  
  if (boton1.state){
    if (guardado){
      guardado = false;
      relojf = millis() + tRestante;
    }

  
  //Estado 1 Rojo encendido 3 segundos 
  if (estado == 0){
  digitalWrite(semaforo1.amarillo, LOW);
  digitalWrite(semaforo1.rojo, HIGH);
  digitalWrite(semaforo1.verde, LOW);
    unsigned long tref = millis();
    if (relojf <= tref){
        relojf = tref + 3000;
        estado = estado + 1;
      }
    
  }
  //Estado 2 Verde encendido 2.5 segundos
  if (estado == 1){
  digitalWrite(semaforo1.rojo, LOW);
  digitalWrite(semaforo1.verde, HIGH);
  digitalWrite(semaforo1.amarillo, LOW);
  unsigned long tref = millis();
    if (relojf <= tref){
        relojf = tref + 1500;
        estado = estado + 1;
      }
  }
  //Estado 3 Amarillo encendido 1.5 segundos
  if (estado == 2){
  digitalWrite(semaforo1.amarillo, HIGH);
  digitalWrite(semaforo1.verde, LOW);
  digitalWrite(semaforo1.rojo, LOW);
  unsigned long tref = millis();
    if (relojf <= tref){
        relojf = tref + 3000;
        estado = 0;
      }
  }
  //delay(1500);
  }
  else {
    digitalWrite(semaforo1.amarillo, LOW);
    digitalWrite(semaforo1.verde, LOW);
    digitalWrite(semaforo1.rojo, LOW);
    
      if (!guardado){
            tRestante = relojf - millis();
            guardado = true;
        }
    
    }

  
}
