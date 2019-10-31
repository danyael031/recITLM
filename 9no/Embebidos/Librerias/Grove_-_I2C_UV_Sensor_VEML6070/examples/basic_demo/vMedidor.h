#ifndef vMedidor_h
#define vMedidor_h

#include<ardVisual.h>


class vMedidor : public BaseVisualObjet {
  private:
    int angulo;
    linea aguja;
    bool firstUpdate;
    // añadir sensor para el proyecto
  public:
    using BaseVisualObjet::BaseVisualObjet;
    vMedidor();
    vMedidor(int x, int y, TFT *pantalla);
    void SetAngulo(int ang);
    void Draw(), UpdateDraw();
};



#endif
