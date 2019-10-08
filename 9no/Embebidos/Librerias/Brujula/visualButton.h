#ifndef visualButton_h
#define visualButton_h

#include"ardVisual.h"


class VisualButton : public BaseVisualObjet {
  public:
    String Text;
    using BaseVisualObjet::BaseVisualObjet;
    VisualButton(int x, int y,TFT *pant, String texto);
    VisualButton();
    void Draw(), UpdateDraw();
};

#endif
