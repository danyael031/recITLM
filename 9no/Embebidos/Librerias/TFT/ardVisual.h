#ifndef ardVisual_h
#define ardVisual_h

#include<Arduino.h>
#include<TFT.h>
#include"visualColorList.h"



struct ByteRGB{
  byte R;
  byte G;
  byte B;
};

//class VisualScenario {
//  public:
//    TFT pantalla;
//    VisualScenario(byte CS,byte DC,byte RST);
//    
//    
//};


/*
 * Summary:
 *   Clase para manejo de colores en arduino para pantalla TFT.
 */
class VColor{
  private:
    VColor(){}
  public:
    static ByteRGB WebColorToByte(uint32_t hexVal);
};


/*
 * Summary:
 *   Clase abstracta que funciona como base para objetos visuales.
 */
class BaseVisualObjet {
  protected:
    int eje_X;
    int eje_Y;
    float escala;
  public:
    BaseVisualObjet(int x, int y, double scala);
    BaseVisualObjet(int x, int y);
    BaseVisualObjet(int x, int y,TFT *pant);
    BaseVisualObjet();
    TFT *Pantalla;
    virtual void Draw();
    virtual void UpdateDraw();
    void ChangeValues(int x, int y, double scala);
    void ChangeValues(int x, int y);
    void SetPositionX(int);
    void SetPositionY(int);
    void SetScala(float);
    int GetPositionX();
    int GetPositionY();
    float GetScala();
};


#endif
