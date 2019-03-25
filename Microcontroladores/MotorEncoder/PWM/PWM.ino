#define P1 5
#define P2 6
#define pwm 3

void setup() {
  // put your setup code here, to run once:
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
}

void loop() {
  analogWrite(pwm, 255);
}

void GiroReloj(){
  digitalWrite(P1, HIGH);
  digitalWrite(P2, LOW);
}

void GiroContraReloj(){
  digitalWrite(P1, LOW);
  digitalWrite(P2, HIGH);
}

void FrenoATierra(){
  digitalWrite(P1, LOW);
  digitalWrite(P2, LOW);
}

void FrenoAVoltaje(){
  digitalWrite(P1, HIGH);
  digitalWrite(P2, HIGH);
}
