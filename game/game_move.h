/* Functions for moving objects on screen in main play mode
 * extracted from game.c for convenience
 (part of FortuGlass game)
 */

#ifndef GAME_MOVE_H_
#define GAME_MOVE_H_

/* Return the highest-numbered rotation situation for the currently active shape */
static uint8_t get_rot_limit() {
	switch (shapes[active].kind) {
		case prism_kind : return PRISM_CASES - 1;
		case mirror_kind : return MIRROR_CASES - 1;
		default : return 0;
	}
}

/* Return nonzero if the active object is too close to any other object */
static uint8_t too_close() {
	uint8_t i;
	uint16_t dist, min_dist;
	for (i=0; i<SHAPES_TOTAL; i++) {
		if (i != active) {
			dist  = shapes[i].x > shapes[active].x ? shapes[i].x - shapes[active].x : shapes[active].x - shapes[i].x;
			dist += shapes[i].y > shapes[active].y ? shapes[i].y - shapes[active].y : shapes[active].y - shapes[i].y;
			min_dist = shapes[i].rad + shapes[active].rad;
			min_dist = ((min_dist << 1) + min_dist) >> 1;
			if (dist < min_dist)
				return 1;
		}
	}
	return 0;
}

/* Move the active object in one of four directions */

static void move_north() {
	if (shapes[active].y - shapes[active].rad > 0) {
		shapes[active].y--;
		if (too_close()) shapes[active].y++;
		else paint();
	}
}

static void move_south() {
	if (shapes[active].y + shapes[active].rad < display.height -1) {
		shapes[active].y++;
		if (too_close()) shapes[active].y--;
		else paint();
	}
}

static void move_east() {
	if (shapes[active].x + shapes[active].rad < display.width -1) {
		shapes[active].x++;
		if (too_close()) shapes[active].x--;
		else paint();
	}
}

static void move_west() {
	if (shapes[active].x - shapes[active].rad > 0) {
		shapes[active].x--;
		if (too_close()) shapes[active].x++;
		else paint();
	}
}

/* Turn the active object in one of two directions */

static void turn_right() {
	if (shapes[active].rot == get_rot_limit()) {
		shapes[active].rot = 0;
	}
	else {
		shapes[active].rot++;
	}
	paint();
}

static void turn_left() {
	if (!shapes[active].rot) {
		shapes[active].rot = get_rot_limit();
	}
	else {
		shapes[active].rot--;
	}
	paint();
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
