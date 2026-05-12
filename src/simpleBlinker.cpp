#include <Arduino.h>

const uint8_t LED_PIN = PC13;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  delay(random(100, 301));
}

