unsigned long tiempo = 0;
unsigned long paquete = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long presio = 10000;
  float temp = 25.6;
  
  if (tiempo + 1000 < millis()){
    Serial.print(paquete);
    Serial.print(" presio: ");
    Serial.print(presio);
    Serial.print(" temperatura: ");
    Serial.println(temp);
    paquete ++;
    tiempo = millis();
  }

  
}
