struct dht11{
  int puerto = 3;
  byte B[5];
  bool stat;
  int cont = 0;
};

bool leerDHT11(dht11* dht){
  dht->cont = 0;

  for (int i = 0; i<=4 ; i++){
    dht->B[i] = 0x00;
  }
  
  
  pinMode(dht->puerto, OUTPUT);  //Colocamos el puerto en modo de salida
  digitalWrite(dht->puerto, LOW);//enviamos a tierra durante 18 milisegundos
  delay(18);
  digitalWrite(dht->puerto, HIGH);
  delayMicroseconds(40);
  pinMode(dht->puerto, INPUT);
  while (digitalRead(dht->puerto) == LOW){}
  while (digitalRead(dht->puerto) == HIGH){}
    for(int iB = 0; iB <= 4; iB++){
      for(int i = 7; i >= 0; i--){
        while (digitalRead(dht->puerto) == LOW){}
        unsigned long tiempo = micros();
        while (digitalRead(dht->puerto) == HIGH){}
        
        if((micros()-tiempo) > 30){
          bitWrite(dht->B[iB], i, 1);
        }

      }
    }
    
    byte checksum = dht->B[0] + dht->B[1] + dht->B[2] + dht->B[3] ;
    if (dht->B[4] == checksum){
      dht->stat = true;
    }
    else{
      dht->stat = false;
    }
  return dht->stat;
  
}
