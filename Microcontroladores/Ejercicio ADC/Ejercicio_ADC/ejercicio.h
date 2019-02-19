#define piSobre3 1.0471975512
#define pi 3.14159265359

struct cono{
  double R;
  double H;
  double tanAlpha;
  };

struct cilindro{
  double H;
  double R;
  };


void Cono(cono* conito, double altura, double radio){
   conito->H = altura;
   conito->R = radio;
   conito->tanAlpha = radio / altura;
  }

double volumenConoTruncado(cono* conito, double alturaExt){
  double volumen;
  double r2 = conito->tanAlpha * alturaExt;
  double h = conito->H - alturaExt;
  volumen = h * piSobre3 * (sq(conito->R) + sq(r2) + (conito->R * r2));
  //Serial.print("volCono:");
  //Serial.println(volumen);

  return volumen;
  }

double volumenCilindro(double radio, double altura){
    double volumen = pi * sq(radio) * altura;
    return volumen;
  }
