#ifndef botonColor_h
#define botonColor_h
#include<ardVisual.h>
#include<visualColorList.h>

class BotonColor : public BaseVisualObjet {
  public:
    uint32_t color;
    String Text;
    BotonColor(int x, int y,TFT *pant, String texto);
    void Draw(),
         UpdateDraw();
};


#endif
