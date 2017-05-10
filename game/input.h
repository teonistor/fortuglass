/*******
Header for input-reading functions to comprehensively react to buttons and
rotary encoder actions on the LaFortuna board. Designed to work based on
periodic calls from a timer.
Designed for the FortuGlass game, but can easily be adapted to call actions
with other purposes.
*******/

#ifndef INPUT_H_
#define INPUT_H_

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


/* Set up port directions for the input buttons on LaFortuna.
 * This function is supposed to be called once during initialisation
 */
void init_input ();

/* Analyse pin states and assess what input the user has performed. Call the functions
 * of the game appropriate to such input.
 * This function is supposed to be called through an ISR every hundredth of a second
 */
void do_input ();

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
