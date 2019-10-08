#include"ardVisual.h"
#include"rtc.h"


#ifndef visualReloj_h
#define visualReloj_h



class VisualReloj : public BaseVisualObjet {
  private:
    int posHora = 180;
    int posMinuto = 180;
    int posSegundo = 180;
    int posReloj;
    int AMPM;
  public:
    RealTC *miRTC;
    VisualReloj();
    VisualReloj(int x,int y,TFT *pantalla, RealTC *rtc);
    void Draw(),UpdateDraw();
};

#endif
