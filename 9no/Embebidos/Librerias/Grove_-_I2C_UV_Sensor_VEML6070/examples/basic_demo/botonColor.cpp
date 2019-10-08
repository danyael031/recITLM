
#include "botonColor.h"


void BotonColor::Draw() {
  Pantalla->setTextSize(2);
  auto BuC = VColor::WebColorToByte( cSkyBlue );
  Pantalla->fill(BuC.B,BuC.G,BuC.R);
  Pantalla->stroke(255,255,255);
  Pantalla->rect(0,0, Pantalla->width(),30);
  Pantalla->text(Text.c_str(),10,7);
}

void BotonColor::UpdateDraw()  {
  
  Serial.println("Actualizar Botón");
  Pantalla->setTextSize(2);
  auto BuC = VColor::WebColorToByte( color );
  Pantalla->fill(BuC.B,BuC.G,BuC.R);
  Pantalla->stroke(255,255,255);
  Pantalla->rect(0,0, Pantalla->width(),30);
  Pantalla->text(Text.c_str(),10,7);
}


BotonColor::BotonColor(int x, int y,TFT *pant, String texto) : BaseVisualObjet(x,y,pant){
  Text = texto;
}
