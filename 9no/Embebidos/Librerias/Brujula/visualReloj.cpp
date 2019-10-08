#include"visualReloj.h"


VisualReloj::VisualReloj() : BaseVisualObjet(){}


void VisualReloj::Draw() {
  Pantalla->setTextSize(1);
  Pantalla->stroke(0, 0, 0);
//  Pantalla->text("1", 104, 16);
//  Pantalla->text("2", 120, 34);
//  Pantalla->text("3", 128, 60);
//  Pantalla->text("4", 120, 84);
//  Pantalla->text("5", 102, 104);
//  Pantalla->text("6", 78, 112);
//  Pantalla->text("7", 54, 104);
//  Pantalla->text("8", 36, 84);
//  Pantalla->text("9", 28, 60);
//  Pantalla->text("10", 30, 34);
//  Pantalla->text("11", 50, 16);
//  Pantalla->text("12", 75, 8);

  Pantalla->text("1", eje_X+76, eje_Y+8);
  Pantalla->text("2", eje_X+92, eje_Y+26);
  Pantalla->text("3", eje_X+100, eje_Y+52);
  Pantalla->text("4", eje_X+92, eje_Y+76);
  Pantalla->text("5", eje_X+74, eje_Y+96);
  Pantalla->text("6", eje_X+50, eje_Y+104);
  Pantalla->text("7", eje_X+22, eje_Y+96);
  Pantalla->text("8", eje_X+8, eje_Y+76);
  Pantalla->text("9", eje_X, eje_Y+52);
  Pantalla->text("10", eje_X+2, eje_Y+26);
  Pantalla->text("11", eje_X+22, eje_Y+8);
  Pantalla->text("12", eje_X+47, eje_Y);

}

void VisualReloj::UpdateDraw() {
  Serial.println("Actualizar Reloj");

  int hora    = miRTC->getIntHora();
  int minuto  = miRTC->getIntMinuto();
  int segundo = miRTC->getIntSegundo();
  
 
  Pantalla->stroke(0, 0, 0);
  Pantalla->fill(255,255,255);
  Pantalla->circle(eje_X+52, eje_Y+55, 40);
  for(int i = 0; i < 12; i ++)
  {
    Pantalla->line(int(35 * sin(posReloj * 0.0174533)) + eje_X + 52, int(35 * cos(posReloj * 0.0174533)) + eje_Y+ 55, int(40 * sin(posReloj * 0.0174533)) + eje_X + 52, int(40 * cos(posReloj * 0.0174533)) + eje_Y + 55);
    posReloj += 30;
  }
  posReloj = 0;
  if (hora > 12)
  {
    AMPM = hora - 12;
    posHora = 180;
    for (int i = 0; i < AMPM; i ++)
    {
      posHora -= 30;
    }
  }
  else
  {
    posHora = 180;
    for (int i = 0; i < hora; i ++)
    {
      posHora -= 30;
    }
  }
  posMinuto = 180;
  for (int i = 0; i < minuto; i ++)
  {
    posMinuto -= 6;
  }
  posSegundo = 180;
  for (int i = 0; i < segundo; i ++)
  {
    posSegundo -= 6;
  }
  Pantalla->stroke(255, 0, 0);
  Pantalla->line(eje_X + 52, eje_Y + 55, int(20 * sin(posHora * 0.0174533)) + eje_X + 52, int(20 * cos(posHora * 0.0174533)) + eje_Y + 55);
  Pantalla->stroke(0, 170, 0);
  Pantalla->line(eje_X + 52, eje_Y + 55, int(30 * sin(posMinuto * 0.0174533)) + eje_X + 52, int(30 * cos(posMinuto * 0.0174533)) + eje_Y + 55);
  Pantalla->stroke(0, 0, 255);
  Pantalla->line(eje_X + 52, eje_Y + 55, int(40 * sin(posSegundo * 0.0174533)) + eje_X + 52, int(40 * cos(posSegundo * 0.0174533)) + eje_Y + 55);
  delay(1000);
  Pantalla->stroke(255, 255, 255);
  Pantalla->line(eje_X + 52, eje_Y + 55, int(20 * sin(posHora * 0.0174533)) + eje_X + 52, int(20 * cos(posHora * 0.0174533)) + eje_Y + 55);
  Pantalla->line(eje_X + 52, eje_Y + 55, int(30 * sin(posMinuto * 0.0174533)) + eje_X + 52, int(30 * cos(posMinuto * 0.0174533)) + eje_Y + 55);
  Pantalla->line(eje_X + 52, eje_Y + 55, int(40 * sin(posSegundo * 0.0174533)) + eje_X + 52, int(40 * cos(posSegundo * 0.0174533)) + eje_Y + 55);
}

VisualReloj::VisualReloj(int x, int y,TFT *pantalla, RealTC *rtc) : BaseVisualObjet(x,y,pantalla){
  miRTC = rtc;
}
