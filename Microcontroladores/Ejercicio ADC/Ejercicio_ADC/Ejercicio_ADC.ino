/* Instituto Tecnológico de Los Mochis
 * Ingeniería electrónica
 * Materia: Microcontroladores.
 * Profesor: Cesar Armando López Macias
 * Alumno: Dan Yael Sajarópulos Verdugo
 * 
 *      Ejercicio ADC
 * 
 */
 
int led = 8;
int entrada = A0;
int valorEntrada = 0;
float voltaje = 0;
float valorPorBit = 0.004888;// valor por cada bit en un ADC de 10 bits con 5v de referencia

long int tf = 0;
 
void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);

tf = millis()+700;
}

void loop() {
  valorEntrada = analogRead(entrada);
  voltaje = calcularVoltaje(valorEntrada);
  if (tf <= millis()){
        Serial.println(voltaje);
      tf = millis() + 700;
    }
  if (voltaje < 4){
  digitalWrite(led, LOW);
  }
  else {
    digitalWrite(led, HIGH);
  }

}

float calcularVoltaje(int valorDigital){
  float resultado = (float)valorDigital * valorPorBit;
  return resultado;
  }
