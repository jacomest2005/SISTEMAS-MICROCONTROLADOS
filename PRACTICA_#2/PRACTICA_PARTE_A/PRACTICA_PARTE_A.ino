int BOTON = 8;
int LED2  = 12;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED2, OUTPUT);
pinMode(BOTON, INPUT);
  Serial.begin(9600);
  Serial.println("Lectura de boton iniciada");
}
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);                    
  digitalWrite(LED_BUILTIN, LOW); 
  delay(1000);   
  int lectura = digitalRead(BOTON);
  if (lectura == LOW) {        
    digitalWrite(LED2, HIGH);  
    Serial.println("LED ENCENDIDO");
  } else {
    digitalWrite(LED2, LOW);   
    Serial.println("LED APAGADO");
  }
                      
}
