const int MQ_PIN = A0;
const int RL_VALUE = 5;
const int RO = 10;

const int READ_SAMPLE_INTERVAL = 100;
const int READ_SAMPLE_TIMES = 5;

const float X0 = 200;
const float Y0 = 2.9;
const float X1 = 10000;
const float Y1 = 0.65;

const float punto0[] = {log10(X0),log10(Y0)};
const float punto1[] = {log10(X1),log10(Y1)};

const float scope = (punto1[1] - punto0[1])/(punto1[0] - punto0[0]);
const float coord = punto0[1] + punto0[0] * scope;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  float rs_med = readMQ(MQ_PIN);
  float concentration = getConcentration(rs_med/RO);
  Serial.println(concentration);
}

float readMQ(int mq_pin){
  float rs = 0;
  for (int i = 0; i < READ_SAMPLE_TIMES ; i++){
    rs += getMQResistance(analogRead(mq_pin));
    delay(READ_SAMPLE_INTERVAL);
  }
  return rs / READ_SAMPLE_TIMES;
}

float getMQResistance(int raw_adc){
  return (((float)RL_VALUE/1000.0*(1023-raw_adc)/raw_adc));
}

float getConcentration(float rs_ro_ratio){
  return pow(10,coord + scope * log(rs_ro_ratio));
}
