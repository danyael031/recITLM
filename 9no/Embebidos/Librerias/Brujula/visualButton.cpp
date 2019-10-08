#include"visualButton.h"

void VisualButton::Draw() {

  auto BuC = VColor::WebColorToByte( cSkyBlue );
  Pantalla->fill(BuC.B,BuC.G,BuC.R);
  Pantalla->stroke(255,255,255);
  Pantalla->rect(eje_X,eje_Y,Text.length() * 6+4,14);
  Pantalla->text(Text.c_str(),eje_X+3,eje_Y+3);
}

void VisualButton::UpdateDraw()  {
  Serial.println("Actualizar Botón");
}

VisualButton::VisualButton() : BaseVisualObjet() {}

VisualButton::VisualButton(int x, int y,TFT *pant, String texto) : BaseVisualObjet(x,y,pant){
  Text = texto;
}
