# Descripción del proyecto de arduino

Debe de contener los siguientes puntos:

* WiFi
* Bluetooth
* TFT
* Visual Studio

Se conectará el móduo wee(ESP8266) al shield de xbee para arduino. 

http://www.itead.cc/wiki/Wee_Serial_WIFI_Module

Página con librerías y comandos AT

Los comandos AT son comandos que se envían por texto a través del puerto serial.

# Características eléctricas

El dispositivo trabaja con 3.3V

# Comandos

## Comandos Genéricos

* AT - prueba la comunicación
* AT+RST - Reset por software
* AT+GMR - Obtener versión de firmware
* AT+CWMODE=1 - Configura modo de trabajo (1=Sta, 2=AP, 3=AP+Sta)

## Configurar como AP (AT+CWMODE=2 o 3)

* AT+CWSAP="MICROS","PASSWORD",CANAL,ENC
  - Canal = 1 al 11
  - enc 0-Open, 1-WEP, 2-WPA_PSK, 4-WPA_WPA2_PSK (SOLO AL CONFIGURAR COMO AP AT+CWMODE=2)
* AT+CIFSR - (Proporciona dir IP asignada al módulo)
* AT+CWLIF - (Obtener la dir IP del módulo)
