int BOTON = 8;
int LED2  = 12;
int LED3 = 9;
unsigned long tiempoAnterior = 0;
const unsigned long intervalo = 1000;
unsigned long led3tiempoAnterior = 0;
const unsigned long led3intervalo = 2000;
unsigned long tiempoActual;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3,OUTPUT);
  Serial.begin(9600);
  Serial.println("Lectura de boton iniciada");
  pinMode(BOTON, INPUT);
}
void loop() {
  tiempoActual = millis();
 if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
 if (tiempoActual - led3tiempoAnterior >= led3intervalo) {
    led3tiempoAnterior = tiempoActual;
    digitalWrite(LED3, !digitalRead(LED3)); 
  }
  int lectura = digitalRead(BOTON);
  if (lectura == LOW) {        
    digitalWrite(LED2, HIGH);  
    Serial.println("LED ENCENDIDO");
  } else {
    digitalWrite(LED2, LOW);   
    Serial.println("LED APAGADO");
  }
}
