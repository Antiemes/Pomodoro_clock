#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <stdlib.h>

void tune(uint8_t pitch)
{
  uint16_t i;
  switch (pitch)
  {
    case 0:
      for (i=0; i<66; i++)
      {
        PORTB = 0b00000001;
        _delay_us(1130);
        PORTB = 0b00000010;
        _delay_us(1120);
      }
      break;
    case 1:
      for (i=0; i<83; i++)
      {
        PORTB = 0b00000001;
        _delay_us(899);
        PORTB = 0b00000010;
        _delay_us(889);
      }
      break;
    case 2:
      for (i=0; i<100; i++)
      {
        PORTB = 0b00000001;
        _delay_us(750);
        PORTB = 0b00000010;
        _delay_us(740);
      }
      break;
    case 3:
      for (i=0; i<119; i++)
      {
        PORTB = 0b00000001;
        _delay_us(630);
        PORTB = 0b00000010;
        _delay_us(620);
      }
      break;
    case 4:
      for (i=0; i<132; i++)
      {
        PORTB = 0b00000001;
        _delay_us(560);
        PORTB = 0b00000010;
        _delay_us(550);
      }
      break;
  }
  _delay_ms(50);
}

ISR (PCINT0_vect)
{
}

int main(void)
{
  DDRB = _BV(PB0) | _BV(PB1) | _BV(PB2);
  PORTB = 0;
  ACSR = 0; // clear register

  _delay_ms(500);

  uint8_t sec;

  while(1)
  {
  for (sec=0; sec<3; sec++)
  {
    PORTB = 0b00000001;
    _delay_us(300);
    PORTB = 0b00000000;
    _delay_ms(500);
    PORTB = 0b00000010;
    _delay_us(300);
    PORTB = 0b00000000;
    _delay_ms(500);
  }

  tune(rand() % 5);
  tune(rand() % 5);
  tune(rand() % 5);
  tune(rand() % 5);
  tune(rand() % 5);

  PORTB = 0b00000000;
  }
}
