/*******
Functions to comprehensively react to buttons and rotary encoder actions
on the LaFortuna. Designed to work based on periodic calls from a timer.
Designed for the FortuGlass game, but can easily be adapted to call actions
with other purposes.
*******/
#include <avr/io.h>
#include <avr/interrupt.h>

#include "game.h"

/* Pins on La Fortuna board

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

/* Last status of input, counter for long press centre button, variable to use when decoding wheel */
static uint8_t in_last, centre_phase, wheel;

/* Macros for encoding and decoding user input into one byte */
#define NORTH	1
#define SOUTH	2
#define EAST	4
#define WEST	8
#define CENTRE	16
#define LEFT	32
#define RIGHT	64
#define press_north(a)  (a&NORTH)
#define press_south(a)  (a&SOUTH)
#define press_east(a)   (a&EAST)
#define press_west(a)   (a&WEST)
#define press_centre(a) (a&CENTRE)
#define turn_left(a)    (a&LEFT)
#define turn_right(a)   (a&RIGHT)


/* Set up port directions for the input buttons on LaFortuna.
 * This function is supposed to be called once during initialisation
 */
void init_input() {
	DDRB  |=  _BV(PB7);   				/* LED pin out... not really used */
	PORTB &= ~_BV(PB7);   				/* LED off */
	DDRC  &= ~(_BV(PC2)|_BV(PC3)|_BV(PC4)|_BV(PC5));	/* Directional buttons pins in */
	PORTC |=   _BV(PC2)|_BV(PC3)|_BV(PC4)|_BV(PC5);		/* Directional buttons pull-up on */
	DDRE  &= ~(_BV(PE4) | _BV(PE5) | _BV(PE7));			/* Rotary encoder and centre button pins in */
	PORTE |=   _BV(PE4) | _BV(PE5) | _BV(PE7);			/* Rotary encoder and centre button pull-up on */
}

/* Analyse pin states and assess what input the user has performed. Call the functions
 * of the game appropriate to such input.
 * This function is supposed to be called through an ISR every hundredth of a second
 */
void do_input() {

	/* First of all, gather data all at once (or as "at once" as possible) */
	uint8_t inC, inE, in_current;
	inC = PINC;
	inE = PINE;
	in_current = 0;

	/* In order to decode the rotary encoder, concatenate the bits from the
	 * previous reading with the new ones, and take action on certain patterns
	 */
	wheel = (wheel<<2) | (inE >> (PE4-1)) &2 | (inE >> PE5) &1;
	switch (wheel) {
		case 1: case 14: in_current |= LEFT; break;
		case 4: case 11: in_current |= RIGHT; break;
	}

	/* Now read straightforward buttons */
	if ((~inC >> PC2) & 1) in_current |= NORTH;
	if ((~inC >> PC4) & 1) in_current |= SOUTH;
	if ((~inC >> PC3) & 1) in_current |= EAST;
	if ((~inC >> PC5) & 1) in_current |= WEST;
	if ((~inE >> PE7) & 1) in_current |= CENTRE;

	/* If the game is in a relevant state, pretend that directional
	 * buttons were released even though they weren't. This way,
	 * holding down a direction will result in a continuous movement.
	 */
	if (continuous_movement_enabled()) {
		in_last &= ~(NORTH | SOUTH | EAST | WEST );
	}

	/* Where wheel was turned and where button state has changed from released
	 * to pushed, call an action
	 */
	if (press_north(in_current)  && !press_north(in_last))  on_press_north();
	if (press_south(in_current)  && !press_south(in_last))  on_press_south();
	if (press_east(in_current)   && !press_east(in_last))   on_press_east();
	if (press_west(in_current)   && !press_west(in_last))   on_press_west();
	if (turn_left(in_current))   on_turn_left();
	if (turn_right(in_current))  on_turn_right();

	/* Extra consideration for centre button: if continuously pressed for half
	 * a second, send a long press signal.
	 */
	if (press_centre(in_current)) {
		if (press_centre(in_last)) {
			centre_phase ++;
			if (centre_phase == 50)
				on_long_press_centre();
		}
		else {
			on_press_centre();
		}
	}
	else {
		centre_phase = 0;
	}

	/* Don't forget to set current variables as last for future reference */
	in_last = in_current;
	wheel &= 3;
	
	/* Lastly, feed the game a periodic signal */
	demo_feed();
}

/*****************************************************************************
MIT License

Copyright (c) 2017 Teodor Gherasim Nistor

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
