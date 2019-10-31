s#include"visualBrujula.h"

//---------- Constructores----------
VisualBrujula::VisualBrujula() : BaseVisualObjet(){}
VisualBrujula::VisualBrujula(int x, int y, TFT *pantalla, MechaQMC5883* Bruj) : BaseVisualObjet(x,y,pantalla){
  // Añadir la relación del sensor como puntero  
  brujula = Bruj;
}
//----------

void VisualBrujula::Draw(){
  brujula->init();
  firstUpdate = true;
  Pantalla->setTextSize(1);
  auto BuC = VColor::WebColorToByte( cBlack );
  Pantalla->fill(BuC.B,BuC.G,BuC.R);
  auto colorStroke = VColor::WebColorToByte( cWhite );
  Pantalla->stroke(colorStroke.B, colorStroke.G, colorStroke.R);

  Pantalla->text("O", eje_X+100, eje_Y+52);
  Pantalla->text("S", eje_X+50, eje_Y+104);
  Pantalla->text("E", eje_X, eje_Y+52);
  Pantalla->text("N", eje_X+47, eje_Y);

  Pantalla->stroke(255, 255, 255);
  Pantalla->fill(0,0,0);
  Pantalla->circle(eje_X+52, eje_Y+55, 40);
}

void VisualBrujula::UpdateDraw(){
  
  angulo = (int)(NorteMag())   + 100 ;
  
  if (!firstUpdate){
      Pantalla->stroke(0, 0, 0);
      Pantalla->line(aguja.p1.x, aguja.p1.y, aguja.p2.x, aguja.p2.y);
      Pantalla->stroke(0, 0, 0);
      Pantalla->line(agujaSur.p1.x, aguja.p1.y, agujaSur.p2.x , agujaSur.p2.y );
  }
  else{firstUpdate = false;}
  
  aguja.p1.x = eje_X + 52;
  agujaSur.p1.x = aguja.p1.x;
  aguja.p1.y = eje_Y + 55;
  agujaSur.p1.y = aguja.p1.y;
  
  aguja.p2.x =    int(20 * sin(angulo * 0.0174533)) + eje_X + 52;
  agujaSur.p2.x = int(20 * sin((angulo + 180) * 0.0174533)) + eje_X + 52;
  aguja.p2.y =    int(20 * cos(angulo * 0.0174533)) + eje_Y + 55;
  agujaSur.p2.y = int(20 * cos((angulo + 180) * 0.0174533)) + eje_Y + 55;
  
  Pantalla->stroke(0, 0, 255);
  Pantalla->line(aguja.p1.x, aguja.p1.y, aguja.p2.x, aguja.p2.y);
   auto Cst = VColor::WebColorToByte( cLightGray );
  Pantalla->stroke(Cst.B, Cst.G, Cst.R);
  Pantalla->line(agujaSur.p1.x, aguja.p1.y, agujaSur.p2.x , agujaSur.p2.y );
  
  
}

void VisualBrujula::SetAngulo(int ang){
  angulo = ang;  
}

float VisualBrujula::NorteMag(){
  brujula->read(&x, &y, &z,&azimuth);
  geografico=azimuth+declinacion;
  Serial.print( "Angulo: ");
  Serial.println(geografico);
  
  
  return geografico;
  
}
