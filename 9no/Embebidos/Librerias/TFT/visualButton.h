#ifndef visualButton_h
#define visualButton_h

#include"ardVisual.h"


class VisualButton : public BaseVisualObjet {
  public:
    String Text;
    using BaseVisualObjet::BaseVisualObjet;
    VisualButton();
    VisualButton(int x, int y, String texto,TFT *pant);
    void Draw() override;
    void UpdateDraw();
};

#endif
