#define piSobre3 1.0471975512

struct cono{
  double R;
  double H;
  double tanAlpha;
  };


void Cono(cono* conito, double altura, double radio){
   conito->H = altura;
   conito->R = radio;
   conito->tanAlpha = radio / altura;
  }

double volumenConoTruncado(cono* conito, double alturaExt){
  double volumen = 0;
  double r2 = conito->tanAlpha * alturaExt;
  double h = conito->H - alturaExt;
  volumen = h * piSobre3 * (sq(conito->R) + sq(r2) + (conito->R * r2));

  return volumen;
  }

double volumenCilindro 
