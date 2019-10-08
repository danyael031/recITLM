#ifndef visualBrujula_h
#define visualBrujula_h

#include"ardVisual.h"


class VisualBrujula : public BaseVisualObjet {
  private:
    int angulo;
    linea aguja;
    linea agujaSur;
    bool firstUpdate;
    // añadir sensor para el proyecto
  public:
    using BaseVisualObjet::BaseVisualObjet;
    VisualBrujula();
    VisualBrujula(int x, int y, TFT *pantalla);
    void SetAngulo(int ang);
    void Draw(), UpdateDraw();
};



#endif
