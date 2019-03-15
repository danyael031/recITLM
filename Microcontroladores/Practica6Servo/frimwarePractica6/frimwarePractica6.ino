#include <Servo.h>

Servo miServo;
String datos;
float grados;
bool datosCompletados;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  miServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (datosCompletados){
    grados = splitRecuperarGrados();
    if (grados >= 0 && grados <= 180){
      miServo.write(grados);
    }
    datosCompletados = false;
    datos = "";
    }
}

float splitRecuperarGrados(){
  int inicio = 0;
  int fin = 0;
  inicio = datos.indexOf("/");
  fin = datos.indexOf("/", inicio + 1);
  String value = datos.substring(inicio+1, fin);
  return value.toFloat();
}

void serialEvent() {
  while (Serial.available()){
    char inChar = (char)Serial.read();
    datos += inChar;
    if (inChar == '\n') {
      datosCompletados = true;
    }
  }
  
}
