#ifndef botonColor_h

#define botonColor_h
#include<ardVisual.h>

class BotonColor : public BaseVisualObjet{
    public:
      uint8_t R;
      uint8_t G;
      uint8_t B;
      float value;
      using BaseVisualObjet::BaseVisualObjet;
      void Draw(),
           UpdateDraw();
      
    
    
}




#endif
