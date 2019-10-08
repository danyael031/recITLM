#ifndef rtc_h
#define rtc_h

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
    String Date();
    String Clock();
    String getSegundo();
    String getMinuto();
    String getHora();
    String getDia();
    String getDiaSemana();
    String getMes();
    String getAno();
    int getIntSegundo();
    int getIntMinuto();
    int getIntHora();
    RealTC();

};

#endif
