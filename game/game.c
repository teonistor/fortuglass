/*******
Main code for the FortuGlass game
*******/

#include <stdlib.h>

#include "lcd.h"
#include "game.h"
#include "shapes.h"
#include "ray.h"


/* What states the game can be in */
enum game_state {menu, playing, paused, tutorial1, tutorial2, demo};

/* During gameplay, counts targets not yet hit by the right color */
uint8_t targets_remaining;

/* Static prototypes */
static void paint();
static void generate_level();

/* Static variables */
static enum game_state state;
static uint8_t active; /* Index of currently active shape in array declared in shapes.h */
static uint8_t ray_phase; /* Used for delaying rays being drawn on screen because this is a visibly heavy operation */
static uint8_t demo_action, demo_count; /* For automatic movement in demo mode */

/* Some more headers that depend on code above */
#include "game_move.h"
#include "game_srand.h"
#include "svgrgb565.h"
#include "menu.h"

/* Turn on display and set up variables and structures for the game
 * This function is supposed to be called once during initialisation
 */
void init_game() {
	init_lcd();
	state = menu;
	paint();
}

uint8_t continuous_movement_enabled() {
	return state == playing;
}

/* Possibly simulate input for demo mode - or do nothing
 * This function is supposed to be called in a reasonably regular fashion (preferably in a timer ISR)
 */
void demo_feed() {
	if (state == demo) {
		if (!demo_count) {
			switch ((rand() >> 8) & 7) {
				case 1: demo_action = 1; demo_count = 50 + ((rand() >> 8) & 63); break;
				case 2: demo_action = 2; demo_count = 50 + ((rand() >> 8) & 63); break;
				case 3: demo_action = 4; demo_count = 50 + ((rand() >> 8) & 63); break;
				case 4: demo_action = 8; demo_count = 50 + ((rand() >> 8) & 63); break;
				case 5: demo_action =16; demo_count = 50 + ((rand() >> 8) & 63); break;
				case 6: demo_action =32; demo_count = 50 + ((rand() >> 8) & 63); break;
				case 7: active = (active + 1) % SHAPES_MOVABLE; break;
			}
		}
		
		if (demo_count) {
			demo_count--;
			switch (demo_action) {
				case 1 : move_north(); break;
				case 2 : move_south(); break;
				case 4 : move_east(); break;
				case 8 : move_west(); break;
				case 16: turn_right(); break;
				case 32: turn_left(); break;
			}
		}
	}
	
	/* Also feed the seed at the beginning */
	seed_increment();
	
	/* Also count up ray phase */
	if (ray_phase)
		ray_phase = (ray_phase + 1) % 6;
}

void on_press_north() {
	switch (state) {
		case menu :
			break;
		case playing :
			move_north();
			break;
		case paused :
			break;
		case tutorial1 :
			break;
		case tutorial2 :
			break;
		case demo :
			state = menu;
			paint();
			break;
	}
}

void on_press_south() {
	
	/* First time South is pressed, seed the random number generator */
	seed_srand();
	
	switch (state) {
		case menu :
			state = playing;
			generate_level();
			break;
		case playing :
			move_south();
			break;
		case paused :
			state = playing;
			clear_screen();
			paint();
			break;
		case tutorial1 :
			break;
		case tutorial2 :
			break;
		case demo :
			state = menu;
			paint();
			break;
	}
}

void on_press_east() {
	switch (state) {
		case menu :
			state = tutorial1;
			paint();
			break;
		case playing :
			move_east();
			break;
		case paused :
			state = playing;
			generate_level();
			break;
		case tutorial1 :
			state = tutorial2;
			paint();
			break;
		case tutorial2 :
			state = menu;
			paint();
			break;
		case demo :
			state = menu;
			paint();
			break;
	}
}

void on_press_west() {
	switch (state) {
		case menu :
			state = demo;
			generate_level();
			break;
		case playing :
			move_west();
			break;
		case paused :
			state = menu;
			paint();
			break;
		case tutorial1 :
			state = menu;
			paint();
			break;
		case tutorial2 :
			state = tutorial1;
			paint();
			break;
		case demo :
			state = menu;
			paint();
			break;
	}
}

void on_press_centre() {
	if (state == demo) {
		state = menu;
		paint();
	}
	else if (state == playing) {
		active = (active + 1) % SHAPES_MOVABLE;
		paint(0); /* The only situation where we don't want the rays redrawn */
	}
}

void on_long_press_centre() {
	if (state == playing) {
		state = paused;
		paint();
	}
}

void on_turn_right() {
	switch (state) {
		case menu :
			break;
		case playing :
			turn_right();
			break;
		case paused :
			break;
		case tutorial1 :
			break;
		case tutorial2 :
			break;
		case demo :
			state = menu;
			paint();
			break;
	}
}

void on_turn_left() {
	switch (state) {
		case menu :
			break;
		case playing :
			turn_left();
			break;
		case paused :
			break;
		case tutorial1 :
			break;
		case tutorial2 :
			break;
		case demo :
			state = menu;
			paint();
			break;
	}
}

/* Finally the function that makes anything visible at all */
static void paint() {
	uint8_t i;

	switch (state) {
		case menu :
			paint_menu ();
			break;
			
		case playing :
		case demo :
			
			if (!ray_phase) {
				targets_remaining = 3;
				erase_rays();
			}
			
			for (i = 0; i<SHAPES_TOTAL; i++) {
				uint16_t color = BEIGE;
				switch (shapes[i].kind) {
					case sun_kind : color = WHITE; break;
					case target_kind :
						switch (shapes[i].rot) {
							case 1: color = RED; break;
							case 2: color = GREEN; break;
							case 4: color = BLUE; break;
						}
						break;
					default: if (i == active) color = FUCHSIA;
				}
				paint_shape (&shapes[i], color);
			}
			
			if (!ray_phase) {
				build_rays();
				if (!targets_remaining)
					generate_level();
				ray_phase ++;
			}
			break;
			
		case paused :
			paint_pause();
			break;
			
		case tutorial1 :
			paint_tutorial (1);
			break;
		case tutorial2 :
			paint_tutorial (2);
			break;
	}
}

/* Set up all shapes at quasi-random locations on screen
 * Screen is divided into 8 virtual boxes. Each shape is allocated one such
 * box of its own and a random position within a box, so they don't hit.
 */
static void generate_level() {
	
	/* Randomise positions */
	uint8_t i, j,
		split_screen[] = {0, 1, 2, 3, 4, 5, 6, 7};
	uint16_t
		x_set[] = {20, 100, 180, 260, 20, 100, 180, 260},
		y_set[] = {20, 20,  20,  20, 140, 140, 140, 140};

	for (i=0; i<SHAPES_TOTAL; i++) {
		j = (rand() >> 7) % (SHAPES_TOTAL - i);
		shapes[i].x = x_set[split_screen[j]] + (rand() >> 7) % 40;
		shapes[i].y = y_set[split_screen[j]] + (rand() >> 7) % 80;
		for (j++; j<8; j++)
			split_screen[j-1] = split_screen[j];
	}
	
	/** Initialise types and sizes **
	 * 
	 * The sun will be rotated in the general direction of the centre of the screen
	 * For targets, the rotation slot will be used to store the color instead:
	 *     1 = red, 2 = green, 4 = blue
	 *    (Note this is different from 16-bit color encodings)
	 */
	shapes[0].kind = prism_kind;
	shapes[0].rad = PRISM_RADIUS;
	shapes[0].rot = 0;

	shapes[1].kind = mirror_kind;
	shapes[1].rad = MIRROR_RADIUS;
	shapes[1].rot = 0;

	shapes[2].kind = mirror_kind;
	shapes[2].rad = MIRROR_RADIUS;
	shapes[2].rot = 0;
	
	uint8_t sun_ranges[] = {0, 12, 36, 24};
	shapes[3].kind = sun_kind;
	shapes[3].rad = SUN_RADIUS;
	shapes[3].rot = (rand() >> 7) % 12 + sun_ranges[(shapes[3].x > display.width >> 1 ? 1 : 0) | (shapes[3].y > display.height >> 1 ? 2 : 0)];

	shapes[4].kind = target_kind;
	shapes[4].rad = TARGET_RADIUS;
	shapes[4].rot = 1;

	shapes[5].kind = target_kind;
	shapes[5].rad = TARGET_RADIUS;
	shapes[5].rot = 2;

	shapes[6].kind = target_kind;
	shapes[6].rad = TARGET_RADIUS;
	shapes[6].rot = 4;
	
	/* Misc. */
	active = 0;
	clear_screen();
	paint();
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
