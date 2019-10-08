#include"ardVisual.h"

//---------- BaseVisualObjet----------
BaseVisualObjet::BaseVisualObjet(int x, int y, double scale){
  eje_X = x;
  eje_Y = y;
  escala = scale;
 }
 BaseVisualObjet::BaseVisualObjet(int x, int y){
  eje_X = x;
  eje_Y = y;
  escala = 1;
 }

BaseVisualObjet::BaseVisualObjet(){
  eje_X = 0;
  eje_Y = 0;
  escala = 1;
 }

BaseVisualObjet::BaseVisualObjet(int x, int y,TFT *pant){
  eje_X = x;
  eje_Y = y;
  escala = 1;
  Pantalla = pant;
}


void BaseVisualObjet::SetPositionX(int x){eje_X = x;}
void BaseVisualObjet::SetPositionY(int y){eje_Y = y;}
void BaseVisualObjet::SetScala(float scala){escala = scala;}

int BaseVisualObjet::GetPositionX(){return eje_X;}
int BaseVisualObjet::GetPositionY(){return eje_Y;}
float BaseVisualObjet::GetScala(){return escala;}

//---------- VisualColor----------

static ByteRGB VColor::WebColorToByte(uint32_t hexVal){
byte *pointer = (byte*)&hexVal;
ByteRGB result;
result.R = pointer[2];
result.G = pointer[1];
result.B = pointer[0];
return result;
}

//---------- VisualScenario----------
