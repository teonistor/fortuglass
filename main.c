/*****************************************************************************
FortuGlass - a light ray game for LaFortuna
COMP2215 16/17 Final Project

Copyright (c) 2017 Teodor Gherasim Nistor

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*****************************************************************************/

/* Pins on La Fortuna board
   [copied from input.h where such pins are configured and used]

   | Port  | Pin | Function         |
   |-------+-----+------------------|
   |   B   |  7  | Green LED        |
   |   C   |  2  | North Button     |
   |   C   |  3  | East  Button     |
   |   C   |  4  | South Button     |
   |   C   |  5  | West  Button     |
   |   E   |  4  | Rotary Encoder A |
   |   E   |  5  | Rotary Encoder B |
   |   E   |  7  | Centre Button    |

*/

#include <avr/io.h>
#include <avr/interrupt.h>

#include "input.h"
#include "game.h"

/* Function prototypes */
void init (void);

/* Program entry point */
void main (void) {

	init();
	init_input();
	init_game();
    sei();

	PINB |= _BV(PINB7);   /* toggle LED */
	for(;;);
}

/* Configure clock, prescaler, timers */
void init (void) {

	/* 8MHz clock, no prescaling (DS, p. 48) */
	CLKPR = (1 << CLKPCE);
	CLKPR = 0;

	/* Timer 0 to regularly execut the input routine */
	TCCR0A = _BV(WGM01);			/* Timer mode: Clear on compare; Top value from OCR0A */
	TCCR0B = _BV(CS02) | _BV(CS00);	/* F_CPU / 1024 */

    /* SET OCR0A FOR 1/100 S PERIOD */
	OCR0A = 80;

    /* ENABLE TIMER INTERRUPT */
	TIMSK0 |= _BV(OCIE0A);
}


/* Timer 0 interrupt service routine */
ISR( TIMER0_COMPA_vect ) {
     do_input();
}
