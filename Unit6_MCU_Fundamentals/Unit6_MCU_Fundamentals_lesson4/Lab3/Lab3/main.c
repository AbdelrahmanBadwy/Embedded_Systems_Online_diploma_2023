/*
 ============================================================================
 Name        : LAB3 Unit 6
 Author      : Abdelrahman_Badawy
 Version     :
 Copyright   : Your copyright notice
 Description : main file in C, Ansi-style
 ============================================================================
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000ul
// enable interrupt INT0 on rising edge
ISR(INT0_vect)
{
    PORTD |= 1<<5;
    _delay_ms(1000);
}
// enable interrupt INT1 on falling edge
ISR(INT1_vect)
{
    PORTD |= 1<<6;
    _delay_ms(1000);
}
// enable interrupt INT2 on every change
ISR(INT2_vect)
{
    PORTD |= 1<<7;
    _delay_ms(1000);
}
void GPIO_init()
{
    // enable interrupt INT0 on rising edge
    MCUCR |= (1<<0 |  1<<2 | 1<< 3); // enable interrupt INT0 on rising edge
    MCUCR &= ~(1<<1); // enable interrupt INT1 on falling edge
    MCUCSR &= ~(1<<6); // enable interrupt INT2 on every change
    GICR |= (1<<5 |  1<<6 | 1<< 7); // enable INT0, INT1, INT2
    sei(); // enable SREG [global interrupt enable]
    DDRD |= (1<<5) | (1<<6) | (1<<7) ; // set the leds as output
}
int main(void)
{
    GPIO_init();

    /* Replace with your application code */
    while (1) 
    {
        //clear all leds
        PORTD &= ~((1<<5) | (1<<6) | (1<<7));
    }
}

