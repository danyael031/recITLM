#include"visualButton.h"

void VisualButton::Draw() {

  auto BuC = VColor::WebColorToByte(cSkyBlue);
  Pantalla->fill(BuC.B,BuC.G,BuC.R); // set the fill color to blue
  Pantalla->stroke(255,255,255); // outline the rectangle with a white line
  Pantalla->rect(eje_X,eje_Y,Text.length() * 6+4,14);
  Pantalla->text(Text.c_str(),eje_X+3,eje_Y+3);
  
}

void VisualButton::UpdateDraw()  {
  Serial.println("Actualizar Botón");
}

VisualButton::VisualButton()  {

}

VisualButton::VisualButton(int x, int y,String texto,TFT *pant ){
  eje_X = x;
  eje_Y = y;
  Pantalla = pant;
  Text = texto;
}
