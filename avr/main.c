#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
  uint8_t signal_counter = 0;
  uint8_t d = 220;
  int8_t dd = -1;
  uint8_t co = 0;


  /* setup */
  DDRB = _BV(PB0) | _BV(PB1);
  PORTB = 0;
  ACSR = 0; // clear register

  _delay_ms(500);

  /* loop */
  while (1)
  {
    uint16_t i;

    d += dd;
    co += 1;
    if (co == 100)
    {
      co = 0;
      dd = -dd;
    }
    for (i=0; i<d; i++)
    {
      asm("nop");
      asm("nop");
    }
    PORTB = 0b00000001;
    for (i=0; i<d; i++)
    {
      asm("nop");
      asm("nop");
    }
    PORTB = 0b00000010;
  }
}
