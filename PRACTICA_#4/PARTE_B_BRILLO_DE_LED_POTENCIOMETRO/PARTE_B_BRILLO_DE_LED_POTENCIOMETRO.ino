const int LED = 6;      // pin PWM
const int POT = A0;     // entrada analógica

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(POT);        // 0 a 1023
  int duty = map(lectura, 0, 1023, 0, 255);  // escalar a PWM

  analogWrite(LED, duty);

  Serial.print("ADC: ");
  Serial.print(lectura);
  Serial.print("  Duty: ");
  Serial.print(duty);
  Serial.print("  (");
  Serial.print((duty * 100) / 255);
  Serial.println("%)");

  delay(50);
}
