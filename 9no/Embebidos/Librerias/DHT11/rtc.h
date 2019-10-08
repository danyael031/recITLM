#include<Arduino.h>
#include <Wire.h>

class RealTC {
  private:
    int segundo;
    int minuto;
    int hora;
    int diaSemana;
    int diaMes;
    int mes;
    int ano;
    int bcdTodec(int bcd);
    int decTobcd(int dec);
  public:
    bool Read();
    void Config();

};
