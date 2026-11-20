const int MOTOR = 6;
const int bot1 = 2;
const int bot2 = 8;
int estadoA1 = HIGH;
int estadoA2 = HIGH;
int velocidad = 0;
void setup() {
  pinMode(MOTOR, OUTPUT);
  pinMode(bot1, INPUT_PULLUP);
  pinMode(bot2, INPUT_PULLUP);
}
void loop() {
  int estadoB1 = digitalRead(bot1);
  int estadoB2 = digitalRead(bot2);
  if (estadoB1 == LOW && estadoA1 == HIGH) {
    velocidad = velocidad + 25;
    if (velocidad > 255) {
      velocidad = 255;
    }
    delay(50);
  }
  if (estadoB2 == LOW && estadoA2 == HIGH) {
    velocidad = velocidad - 25;
    if (velocidad < 0) {
      velocidad = 0;
    }
    delay(50);
  }
  analogWrite(MOTOR, velocidad);
  estadoA1 = estadoB1;
  estadoA2 = estadoB2;
}
