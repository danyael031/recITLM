#ifndef visualBrujula_h
#define visualBrujula_h

#include <MechaQMC5883.h>

#include"ardVisual.h"


class VisualBrujula : public BaseVisualObjet {
  private:
    int angulo;
    linea aguja;
    linea agujaSur;
    bool firstUpdate;
    int x, y, z;  
    float declinacion=8.14; 
    float azimuth,geografico;
    float NorteMag();
    // añadir sensor para el proyecto
  public:
    MechaQMC5883* brujula;
    using BaseVisualObjet::BaseVisualObjet;
    VisualBrujula();
    VisualBrujula(int x, int y, TFT *pantalla,MechaQMC5883* bruj);
    void SetAngulo(int ang);
    void Draw(), UpdateDraw();
};



#endif
