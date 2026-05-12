#include <Arduino.h>

const uint8_t LED_PIN = PC13;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  GPIOA->ODR |= (1U << 3);
}

