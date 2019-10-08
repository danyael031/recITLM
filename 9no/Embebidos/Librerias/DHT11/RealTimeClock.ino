#include <Wire.h>
 
int segundo; 
int minuto;
int hora;
int diaSemana;
int diaMes;
int mes;
int anio;


void setup() {
  Serial.begin(9600); 
  Wire.begin();
}

void loop() {

delay(1000);
  if (leerReloj()) 
  {
    imprimirHora();
  } 
  else 
  {
    Serial.println("Falla Reloj");
  }
}
 
bool leerReloj()
{  
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

void configurarReloj()  // configuracion del reloj
{  
  // Comandos: segundo = (00-59) || minuto = (00-59) || hora = (00-23) || diaSemana = (1-7) || diaMes = (01-31) || mes = (01-12) || anio = (00-99)
  segundo = 0;
  minuto = 14;
  hora = 8;
  diaSemana = 2;
  diaMes = 4;
  mes = 6;
  anio = 19;
  
  Wire.beginTransmission(0x68); 
  
  Wire.write(0x00);  
  
  Wire.write(dec_A_bcd(segundo));
  Wire.write(dec_A_bcd(minuto));
  Wire.write(dec_A_bcd(hora));
  Wire.write(dec_A_bcd(diaSemana));
  Wire.write(dec_A_bcd(diaMes));
  Wire.write(dec_A_bcd(mes));
  Wire.write(dec_A_bcd(anio));
  Wire.endTransmission();
}
 


void imprimirHora(){
  Serial.print(diaMes);
  Serial.print(" de ");
  Serial.print(mes);
  Serial.print(" de ");
  Serial.print("20");
  Serial.print(anio);
  Serial.print(". ");
  Serial.print(hora);
  Serial.print(":");
  Serial.print(minuto);
  Serial.print(":");
  Serial.print(segundo);
  Serial.println("");
  
}
 
