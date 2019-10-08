#include<Arduino.h>

class DHT11 {
  private:
    uint8_t _port;
    byte data[5];
  public:
    bool Read();
    DHT11(uint8_t port);
    byte getByteTemperatura();
    byte getByteHumedad();
    void LimpiarData();
};
