int BOTON = 8;
int LED2  = 12;
unsigned long tiempoAnterior = 0;
unsigned long tiempoActual;
const unsigned long intervalo = 1000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED2, OUTPUT);
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
 
  int lectura = digitalRead(BOTON);
  if (lectura == LOW) { 
    digitalWrite(LED2, HIGH);
    Serial.println("LED ENCENDIDO");
  } else {
    digitalWrite(LED2, LOW); 
    Serial.println("LED APAGADO");
  }
}
