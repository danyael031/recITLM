/* Instituto Tecnológico de Los Mochis
 * Ingeniería electrónica
 * Materia: Microcontroladores.
 * Profesor: Cesar Armando López Macias
 * Alumno: Dan Yael Sajarópulos Verdugo
 * 
 *      Ejercicio ADC
 * 
 */
#include "HCSR04.h"
#include "ejercicio.h"

int led = 8;
int entrada = A0;
int valorEntrada = 0;
float voltaje = 0;
float valorPorBit = 0.00488758553275;// valor por cada bit en un ADC de 10 bits con 5v de referencia


long int tf = 0;

hcsr04 ultrasonico;//declarando sensor ultrasónico

cono elCono;
cilindro elCilindro = {45, 15};
 
void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);
iniciarHCSR04(&ultrasonico); // iniciar Sensor hc-sr04
Cono(&elCono, 30.0, 15.0);
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
        unsigned int distancia = distanciaHCSR04(&ultrasonico);
        
        double volTot = volumenTotal(&elCono, &elCilindro, distancia);
        
        Serial.print("voltaje: ");
        Serial.println(voltaje);
        Serial.print("distancia: ");
        Serial.println(distancia);
        Serial.print("volumen:");
        Serial.println(volTot);
        

      tf = millis() + 700;
    }
  if (voltaje < 4){
  digitalWrite(led, LOW);
  }
  else {
    digitalWrite(led, HIGH);
  }
}

double volumenTotal(cono* conito, cilindro* cilindrito, unsigned int distancia){
   double maxDist = conito->H + cilindrito->H;

   double altRel = maxDist - (double) distancia;


   if (distancia > maxDist){
      //double volumen = volumenCilindro(cilindrito->R,cilindrito->H) + volumenConoTruncado(conito, 0.0);
      return 0.0;
    }
    else if (altRel <= cilindrito->H){
      double volumen = volumenCilindro(cilindrito->R, altRel);
      return volumen;
      }
    else{
      double volumen = volumenCilindro(cilindrito->R,cilindrito->H) + volumenConoTruncado(conito, (double)distancia);
      return volumen;
      }
  
  }
