/* Functions for seeding the random number generator to obtain different behaviour
 * every time the program is run.
 * 
 * seed_increment() has to be called regularly through an interrupt. When the user
 * interacts, seed_srand() has to be called. This will execute the system srand()
 * function and then change pointers so it does not execute again.
 * 
 * Extracted from game.c for convenience - part of FortuGlass game (but can be used
 * in other projects easily)
 */

#ifndef GAME_SRAND_H_
#define GAME_SRAND_H_

static uint32_t seed;

static void effective_increment ();
static void effective_srand ();
static void do_nothing () {}
 
void (*seed_increment) () = effective_increment;
void (*seed_srand) () = effective_srand;

static void effective_increment() {
	seed++;
}

static void effective_srand() {
	srand (seed);
	seed_increment = do_nothing;
	seed_srand = do_nothing;
}

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
