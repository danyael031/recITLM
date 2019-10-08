
#include"rtc.h"

RealTC::RealTC(){
  Wire.begin();
}


bool RealTC::Read(){
  Wire.beginTransmission(0x68);
  
  Wire.write(0x00);
  
  if (Wire.endTransmission())
  {
    return false;
  } 
  
  Wire.requestFrom(0x68, 7);
  
  this->segundo = bcdTodec(Wire.read());
  minuto = bcdTodec(Wire.read()); // // dirección 0x01
  hora = bcdTodec(Wire.read());   // dirección 0x02
  diaSemana = bcdTodec(Wire.read()); // dirección 0x03
  diaMes = bcdTodec(Wire.read());  // dirección 0x04
  mes = bcdTodec(Wire.read());  // dirección 0x05
  ano = bcdTodec(Wire.read());  // dirección 0x06
 
  return true;  
}

void RealTC::Config(){
  int psegundo = 0;
  int pminuto = 17;
  int phora = 18;
  int pdiaSemana = 2;
  int pdiaMes = 10;
  int pmes = 9;
  int panio = 19;
  
  Wire.beginTransmission(0x68); 
  
  Wire.write(0x00);  
  
  Wire.write(decTobcd(psegundo));
  Wire.write(decTobcd(pminuto));
  Wire.write(decTobcd(phora));
  Wire.write(decTobcd(pdiaSemana));
  Wire.write(decTobcd(pdiaMes));
  Wire.write(decTobcd(pmes));
  Wire.write(decTobcd(panio));
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

String RealTC::Date(){
  String result = "";
  result += (String)diaMes;
  result += " de ";
  result += (String)mes;
  result += " de ";
  result += ano;
  return result;
  
}

String RealTC::Clock(){
  String result = "";
  result += hora;
  result += ":";
  result += minuto;
  result += ":";
  result += segundo;
  return result;
  
}

String RealTC::getSegundo(){return (String)segundo;}
String RealTC::getMinuto(){return (String)minuto;}
String RealTC::getHora(){return (String)hora;}
String RealTC::getDia(){return (String)diaMes;}
String RealTC::getDiaSemana(){
  String result="";
  switch(diaSemana){
    case 1:
    result = "Lunes";
    break;
    case 2:
    result = "Martes";
    break;
    case 3:
    result = "Miercoles";
    break;
    case 4:
    result = "Jueves";
    break;
    case 5:
    result = "Viernes";
    break;
    case 6:
    result = "Sabado";
    break;
    case 7:
    result = "Domingo";
    break;
    
    }
  return result;
  }

String RealTC::getMes(){return (String)mes;}
String RealTC::getAno(){return (String)ano;}
