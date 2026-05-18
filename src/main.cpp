#include <Arduino.h>

const uint8_t LED_PIN = PC13;

void setup() {
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; // Макрос = бітова маска, відповідає за включення тактування GPIOC
  // Configuration Register High — налаштує піни 8–15 (PC8…PC15).
  // PIN13 Використовує біти 23 22 21 20
  // Інверсійне обнулення + накладання маски через AND оператор.
  GPIOC->CRH &= ~(0xF << 20); 
  // 11 - Push 50 MHZ General purpose push-pull
  GPIOC->CRH |=  (0x3 << 20);
}

void loop() {
  // Unsigned int clear 13th bit LOW  -> LED ON
  GPIOC->ODR &= ~(1U << 13); 
  // volatile каже не оптимізуй
  for (volatile uint32_t i=0; i < 900000; i++);
  // HIGH -> LED OFF
  GPIOC->ODR |= (1U << 13);
  for (volatile uint32_t i=0; i < 500000; i++);
}

