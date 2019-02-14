struct  ultraSonic {
  int Trig = 5;
  int Echo = 6;
  
}

void distanciaUltrasonico(struct* ultraSonic){
    digitalWrite(ultraSonic->Trig, HIGH);
    delayMicroseconds(10);
    
  }

void ultrasonicIniciar(struct* ultraSonic){}


