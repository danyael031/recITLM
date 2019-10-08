/*#include <Seeed_VEML6070.h>


#include"botonColor.h"

VEML6070 sensor;

err_t read_UV(){

  err_t ret = NO_ERROR;
  u16 intencidad;
  sensor.wait_for_ready();
  CHECK_RESULT(ret,sensor.read_step(intencidad));
  Serial.print("UV Intencidad = ");
  Serial.println(intencidad);
  RISK_LEVEL level = sensor.convert_to_risk_level(intencidad);
  Serial.print("UV level is ");
  Serial.println(level);
  //Serial.println(UV_str[level]);

  return ret;
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  if(sensor.init()){
    Serial.println("init failed!!!");  
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if(read_UV()){
    Serial.println("read UV sensor failed!!!");  
  }
  delay (1000);
}*/
