
#include"rtc.h"

RealTC rtc;

void setup() {
  Serial.begin(9600);
}

void loop() {
  /*
  rtc.Config();
    while(true){
    Serial.println("configurado");
    delay(1000);
    }

  */
  delay(1000);
  if (rtc.Read())
  {
    Serial.println(rtc.getSegundo());
    Serial.println(rtc.getMinuto());
    Serial.println(rtc.getHora());
    Serial.println(rtc.getDia());
    Serial.println(rtc.getDiaSemana());
    Serial.println(rtc.getMes());
    Serial.println(rtc.getAno());
    Serial.println(rtc.Date());
    Serial.println(rtc.Clock());
  }
  else
  {
    Serial.println("Falla Reloj");
  }
    
}
