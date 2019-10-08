#include "Seeed_VEML6070.h"
#include "botonColor.h"
#include<TFT.h>

#define CS   10
#define DC   9
#define RST  8  

TFT pantalla = TFT(CS, DC, RST);


VEML6070 sensor;
BotonColor botoncito = BotonColor(50,50,&pantalla,"Demo");

uint32_t UV_colors[] = {0x00ff00, 0xffff00, 0xff8000, 0xff0000, 0xff00ff};

byte contar = 0;

char *UV_str[]={"Bajo","Moderado","Alto","Muy Alto","Extremo"};


err_t read_UV()
{
    err_t ret=NO_ERROR;
    u16 step;
    sensor.wait_for_ready();
    CHECK_RESULT(ret,sensor.read_step(step));
    Serial.print("UV step = ");
    Serial.println(step);
    RISK_LEVEL level=sensor.convert_to_risk_level(step);
    
    Serial.print("UV level is ");
    Serial.println(UV_str[level]);
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    return ret;
}

void setup()
{
    Serial.begin(115200);
    delay(10);
    Serial.println("Serial start!!");
    pantalla.begin();
    pantalla.setRotation(0);
    auto BC = VColor::WebColorToByte(cWhite);
    // Colores: Azul, Verde, Rojo. BGR
    pantalla.background(BC.B, BC.G, BC.R);
    delay(1000);
    botoncito.Draw();
    if(sensor.init())
    {
      Serial.println("init failed!!!");
    }
}


void loop()
{
    if(read_UV())
    {
      Serial.print("read UV sensor failed!!");
    }
    botoncito.color = UV_colors[contar];
    botoncito.Text = UV_str[contar];
    botoncito.UpdateDraw();
    //sensor.enable();
    //sensor.disable();
    contar++;
    if (contar > 4)
      contar = 0;
    delay(1000);
}
