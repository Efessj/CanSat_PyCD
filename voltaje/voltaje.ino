float Sensibilidad=0.066; //sensibilidad en Voltios/Amperio para sensor de 5A

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  
  float voltajeSensor= analogRead(A0)*(5.0 / 1023.0); //lectura del sensor   
  float I=(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
  Serial.print("Corriente: ");
  Serial.println(I,3); 
  delay(200);     
}