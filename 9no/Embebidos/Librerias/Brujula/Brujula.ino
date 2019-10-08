#include "visualBrujula.h"

#include<TFT.h>

#define CS   10
#define DC   9
#define RST  8  

TFT pantalla = TFT(CS, DC, RST);

VisualBrujula vbrujula = VisualBrujula(5,4,&pantalla);
int angulo = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("hola");
  pantalla.begin();
  pantalla.setRotation(0);
  auto BC = VColor::WebColorToByte(cBlack);
  // Colores: Azul, Verde, Rojo. BGR
  pantalla.background(BC.B, BC.G, BC.R);
  vbrujula.Draw();
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  angulo++;
  vbrujula.SetAngulo(angulo);
  vbrujula.UpdateDraw();
  Serial.println(angulo);
  delay(100);
}
