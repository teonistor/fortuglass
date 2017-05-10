/*******
Header for main FortuGlass game code
*******/
#ifndef GAME_H_
#define GAME_H_

#include "shapes.h"

/* Shape array sizes */
#define SHAPES_TOTAL 7
#define SHAPES_MOVABLE 3

/* Shapes of the game */
struct shape shapes[SHAPES_TOTAL];

/* During gameplay, counts targets not yet hit by the right color */
extern uint8_t targets_remaining;

/* Turn on display and set up variables and structures for the game
 * This function is supposed to be called once during initialisation
 */
void init_game();

/* Return nonzero only if continuous movement is currently
 * enabled on directional buttons
 */
uint8_t continuous_movement_enabled ();

/* Possibly simulate input for demo mode - or do nothing
 * This function is supposed to be called in a reasonably regular fashion (preferably in a timer ISR)
 */
void demo_feed ();

/* Functions to be called when various input events occur */
void on_press_north ();
void on_press_south ();
void on_press_east ();
void on_press_west ();
void on_press_centre ();
void on_long_press_centre ();
void on_turn_right ();
void on_turn_left ();

#endif

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
