#include <TimerOne.h>

volatile bool flag = false;

const int LED = 8;
const int LED2 = 7;
const int BOTON = 2;

void ISR_timer() {
  flag = true;
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(ISR_timer);
}

void loop() {

  // INTERRUPCION CADA 1 SEGUNDO
  if (flag) {
    flag = false;
    digitalWrite(LED, !digitalRead(LED));
  }

  // OTRA TAREA: CONTROL CON PULSADOR
  if (digitalRead(BOTON) == LOW) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
}
