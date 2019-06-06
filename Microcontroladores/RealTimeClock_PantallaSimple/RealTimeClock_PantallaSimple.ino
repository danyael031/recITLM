
#include <TFT.h>
#include <Wire.h>


#define CS   10
#define DC   9
#define RST  8

TFT pantalla = TFT(CS, DC, RST);

byte cR,cG,cB;
char numerFecha[4];
 
int segundo; 
int minuto;
int hora;
int diaSemana;
int diaMes;
int mes;
int anio;
String dias[7] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
String arrayFecha[6];
char caracteres[10];
int posHora = 180;
int posMinuto = 180;
float posSegundo = 180;
int posReloj;
int AMPM;

void setup() {
  Serial.begin(9600); 
  Wire.begin();
  pantalla.begin();
  pantalla.setRotation(1); 
  pantalla.setTextSize(1);
  pantalla.stroke(0, 0, 0);
  pantalla.background(30, 100, 125);
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
    errorsillo();
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
  minuto = bcd_A_dec(Wire.read()); 
  hora = bcd_A_dec(Wire.read());  
  diaSemana = bcd_A_dec(Wire.read()); 
  diaMes = bcd_A_dec(Wire.read());
  mes = bcd_A_dec(Wire.read());
  anio = bcd_A_dec(Wire.read());
 
  return true;
}

void configurarReloj()  // configuracion del reloj
{  
  // Comandos: segundo = (00-59) || minuto = (00-59) || hora = (00-23) || diaSemana = (1-7) || diaMes = (01-31) || mes = (01-12) || anio = (00-99)
  segundo = 0;
  minuto = 22;
  hora = 7;
  diaSemana = 2;
  diaMes = 12;
  mes = 5;
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
 
int bcd_A_dec(int bcd)
{
  // Convertir decenas y luego unidades a un numero DEC
  return (bcd / 16 * 10) + (bcd % 16);
}

int dec_A_bcd(int dec)
{
  // Convertir decenas y luego unidades a un numero BCD
  return (dec / 10 * 16) + (dec % 10);
}

byte dec_A_bcdByte(int dec)
{
  // Convertir decenas y luego unidades a un numero BCD
  return (dec / 10 * 16) + (dec % 10);
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
void imprimirHoraPantalla(){
  pantalla.background(0, 0, 0);
  pantalla.setTextSize(2);
  pantalla.stroke(255, 255, 255);
  String numero = String(diaMes);
  numero.toCharArray(numerFecha, 4);
  pantalla.text(numerFecha,0,0);
  pantalla.text("de",0,18);

  switch (mes) {
  case 1:
    pantalla.text("Enero",0,36);
    break;
  case 2:
    pantalla.text("Febrero",0,36);
    break;
  case 3:
    pantalla.text("Marzo",0,36);
    break;
  case 4:
    pantalla.text("Abril",0,36);
    break;
  case 5:
    pantalla.text("Mayo",0,36);
    break;
  case 6:
    pantalla.text("Junio",0,36);
    break;
  case 7:
    pantalla.text("Julio",0,36);
    break;
  case 8:
    pantalla.text("Agosto",0,36);
    break;
  case 9:
    pantalla.text("Septiembre",0,36);
    break;
  case 10:
    pantalla.text("Octubre",0,36);
    break;
  case 11:
    pantalla.text("Noviembre",0,36);
    break;
  case 12:
    pantalla.text("Diciembre",0,36);
    break;
  default:
    pantalla.text("Error",0,36);
    break;
}
  pantalla.text("de",0,54);
  numero = String(anio);
  numero.toCharArray(numerFecha, 4);
  pantalla.text(numerFecha,0,72);
  
  Serial.print(hora);
  Serial.print(":");
  Serial.print(minuto);
  Serial.print(":");
  Serial.print(segundo);
  Serial.println("");
  
}

void errorsillo(){
  pantalla.stroke(0, 0, 0);
  pantalla.background(0, 0, 255);
  pantalla.setTextSize(2);
  int numerito = 666;
  String numero = String(numerito);
  numero.toCharArray(numerFecha, 4);
  pantalla.text("ERROR!!!",0,0);
  pantalla.text("ERROR!!!",12,18);
  pantalla.text("ERROR!!!",0,36);
  pantalla.text(numerFecha,0,54);
  pantalla.text("ERROR!!!",0,72);
}


 
