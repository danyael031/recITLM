/* Instituto Tecnológico de Los Mochis
 * Ingeniería electrónica
 * Materia: Microcontroladores.
 * Profesor: Cesar Armando López Macias
 * Alumno: Dan Yael Sajarópulos Verdugo
 * 
 *      Ejercicio ADC
 * 
 */
#include "ultraSonic.h"

int led = 8;
int entrada = A0;
int valorEntrada = 0;
float voltaje = 0;
float valorPorBit = 0.00488758553275;// valor por cada bit en un ADC de 10 bits con 5v de referencia

long int tf = 0;

hcsr04 ultrasonico;//declarando sensor ultrasónico
 
void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);
iniciarHCSR04(&ultrasonico); // iniciar Sensor hc-sr04
tf = millis()+700;

}

void loop() {
analogo();


}







float calcularVoltaje(int valorDigital){
  float resultado = (float)valorDigital * valorPorBit;
  return resultado;
  }

void analogo(){
    valorEntrada = analogRead(entrada);
  voltaje = calcularVoltaje(valorEntrada);
  if (tf <= millis()){
        Serial.println(voltaje);
      tf = millis() + 700;
    }
  if (voltaje < 4){
  digitalWrite(led, LOW);
  }
  else {
    digitalWrite(led, HIGH);
  }
}
