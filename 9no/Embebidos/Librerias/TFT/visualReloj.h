#ifndef visualReloj_h
#define visualReloj_h

#include"ardVisual.h"
#include"rtc.h"



class VisualReloj : public BaseVisualObjet {
  private:
    int posHora = 180;
    int posMinuto = 180;
    int posSegundo = 180;
    int posReloj;
    int AMPM;
  public:
    RealTC *miRTC;
    using BaseVisualObjet::BaseVisualObjet;
    VisualReloj(TFT *pantalla, RealTC *rtc);
    VisualReloj(int x,int y,TFT *pantalla, RealTC *rtc);
    VisualReloj();
    void Draw() override;
    void UpdateDraw()override;
};

#endif
