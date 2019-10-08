#include <Arduino.h>

class Ultrasonico {
  public:
    Ultrasonico(uint8_t pinTrigger, uint8_t pinEcho);
    float ObtenerDistancia();
  private:
    uint8_t PinEcho;
    uint8_t PinTrigger;
    void EnviarTrigger();
};
