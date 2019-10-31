#include"vMedidor.h"

//---------- Constructores----------
vMedidor::vMedidor() : BaseVisualObjet(){}
vMedidor::vMedidor(int x, int y, TFT *pantalla) : BaseVisualObjet(x,y,pantalla){
  // Añadir la relación del sensor como puntero  
}
//----------

void vMedidor::Draw(){
  firstUpdate = true;
  Pantalla->setTextSize(1);
  auto BuC = VColor::WebColorToByte( cBlack );
  Pantalla->fill(BuC.B,BuC.G,BuC.R);
  auto colorStroke = VColor::WebColorToByte( cWhite );
  Pantalla->stroke(colorStroke.B, colorStroke.G, colorStroke.R);

  

  Pantalla->stroke(255, 255, 255);
  Pantalla->fill(0,0,0);
  //Pantalla->circle(eje_X+52, eje_Y+55, 40);
  punto p1,p0;

  uint32_t UV_colors[5] = {0x00ff00, 0xffff00, 0xff8000, 0xff0000, 0xff00ff};
  u16 riskmap[4] = {2241, 4482, 5976, 8217};

  auto colorMed = VColor::WebColorToByte( UV_colors[0] );
  int angulo[4];

  for(int tac = 0; tac <= 4; tac++){
      angulo[tac] = map(0,8500,0,180,riskmap[tac]);
  }
  

  p0.x = int(25 * sin((0 +90) * 0.0174533)) + eje_X + 52;
  p0.y = int(25 * cos((0 +90)* 0.0174533)) + eje_Y + 55;
  int contar = 0;
  int antG = 0;
  for (int i=1; i <= 180; i++){

    

    if (angulo[contar] <= i){
        colorMed = VColor::WebColorToByte(UV_colors[contar+1]);
        contar++;
    }

    
    p1.x = int(25 * sin((i +90) * 0.0174533)) + eje_X + 52;
    p1.y = int(25 * cos((i +90) * 0.0174533)) + eje_Y + 55;

    
    Pantalla->stroke(colorMed.B, colorMed.G, colorMed.R);
    Pantalla->line(p0.x, p0.y, p1.x, p1.y);

    p0.x = p1.x;
    p0.y = p1.y; 
    
      
  }
}

void vMedidor::UpdateDraw(){
  if (!firstUpdate){
      Pantalla->stroke(0, 0, 0);
      Pantalla->line(aguja.p1.x, aguja.p1.y, aguja.p2.x, aguja.p2.y);
  }
  else{firstUpdate = false;}
  
  aguja.p1.x = eje_X + 52;
  aguja.p1.y = eje_Y + 55;

  
  aguja.p2.x = int(20 * sin(angulo * 0.0174533)) + eje_X + 52;
  aguja.p2.y = int(20 * cos(angulo * 0.0174533)) + eje_Y + 55;
  
  Pantalla->stroke(0, 0, 255);
  Pantalla->line(aguja.p1.x, aguja.p1.y, aguja.p2.x, aguja.p2.y);
  
  
}

void vMedidor::SetAngulo(int ang){
  angulo = ang;  
}
