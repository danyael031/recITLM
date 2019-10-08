
#include"rtc.h"



bool RealTC::Read(){
  Wire.beginTransmission(0x68);
  
  Wire.write(0x00);
  
  if (Wire.endTransmission())
  {
    return false;
  } 
  
  Wire.requestFrom(0x68, 7);
  
  segundo = bcd_A_dec(Wire.read());
  minuto = bcd_A_dec(Wire.read()); // // dirección 0x01
  hora = bcd_A_dec(Wire.read());   // dirección 0x02
  diaSemana = bcd_A_dec(Wire.read()); // dirección 0x03
  diaMes = bcd_A_dec(Wire.read());  // dirección 0x04
  mes = bcd_A_dec(Wire.read());  // dirección 0x05
  anio = bcd_A_dec(Wire.read());  // dirección 0x06
 
  return true;  
}

void RealTC::Config(){)
  int psegundo = 0;
  int pminuto = 14;
  int phora = 8;
  int pdiaSemana = 2;
  int pdiaMes = 4;
  int pmes = 6;
  int panio = 19;
  
  Wire.beginTransmission(0x68); 
  
  Wire.write(0x00);  
  
  Wire.write(dec_A_bcd(psegundo));
  Wire.write(dec_A_bcd(pminuto));
  Wire.write(dec_A_bcd(phora));
  Wire.write(dec_A_bcd(pdiaSemana));
  Wire.write(dec_A_bcd(pdiaMes));
  Wire.write(dec_A_bcd(pmes));
  Wire.write(dec_A_bcd(panio));
  Wire.endTransmission();
}

int RealTC::bcdTodec(int bcd)
{
  // Convertir decenas y luego unidades a un numero DEC
  return (bcd / 16 * 10) + (bcd % 16);
}

int RealTC::decTobcd(int dec)
{
  return (dec / 10 * 16) + (dec % 10);
}
