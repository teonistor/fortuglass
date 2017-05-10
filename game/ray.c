/*******
Code for managing and drawing light rays on LaFortuna Screen
Part of the FortuGlass game
*******/

#include "lcd.h"
#include "ili934x.h"
#include "game.h"
#include "shapes.h"
#include "svgrgb565.h"

#define RAY_MAX 8

/* A structure containing info on a light ray */
struct ray {
	/* Start of ray x and y coordinates. Total number of points - 0 means ray nonexistent */
	int16_t x, y, count;
	/* Angle situation of ray */
	int8_t angle;
};

/* Our punny array of rays */
static struct ray rays[RAY_MAX];

/* Index used for moveing through the ray array */
static uint8_t i;


/* Return nonzero if a ray at the specified location hits the specified shape */
static uint8_t hit (uint16_t x, uint16_t y, const struct shape *shape) {
	if (x > shape -> x - (shape->rad >> 1) &&
		x < shape -> x + (shape->rad >> 1) &&
		y > shape -> y - (shape->rad >> 1) &&
		y < shape -> y + (shape->rad >> 1) )
			return 1;
	return 0;
}

/* Set the pixel at the given coordinates to have the given color */
static void paint_point (uint16_t x, uint16_t y, uint16_t color) {
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(y);
	write_data16(y);
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(x);
	write_data16(x);
	write_cmd(MEMORY_WRITE);
	write_data16(color);
}

/* Given the starting x and y points of the current ray and the current count of points,
 * return the coordinates of the next point (through popinters).
 * The large switch statement has been generated externally.
 */
static void next_point (int16_t *x, int16_t *y, int16_t count) {
	switch (rays[i].angle) {
		case  0: *x = rays[i].x + count; *y = rays[i].y; break;
		case  1: *x = rays[i].x + count; *y = rays[i].y + count * 13 / 100; break;
		case  2: *x = rays[i].x + count; *y = rays[i].y + count * 27 / 100; break;
		case  3: *x = rays[i].x + count; *y = rays[i].y + count * 41 / 100; break;
		case  4: *x = rays[i].x + count; *y = rays[i].y + count * 58 / 100; break;
		case  5: *x = rays[i].x + count; *y = rays[i].y + count * 77 / 100; break;
		case  6: *x = rays[i].x + count; *y = rays[i].y + count; break;
		case  7: *x = rays[i].x + count * 76 / 100; *y = rays[i].y + count; break;
		case  8: *x = rays[i].x + count * 57 / 100; *y = rays[i].y + count; break;
		case  9: *x = rays[i].x + count * 41 / 100; *y = rays[i].y + count; break;
		case 10: *x = rays[i].x + count * 26 / 100; *y = rays[i].y + count; break;
		case 11: *x = rays[i].x + count * 13 / 100; *y = rays[i].y + count; break;
		case 12: *x = rays[i].x; *y = rays[i].y + count; break;
		case 13: *x = rays[i].x - count * 13 / 100; *y = rays[i].y + count; break;
		case 14: *x = rays[i].x - count * 26 / 100; *y = rays[i].y + count; break;
		case 15: *x = rays[i].x - count * 41 / 100; *y = rays[i].y + count; break;
		case 16: *x = rays[i].x - count * 57 / 100; *y = rays[i].y + count; break;
		case 17: *x = rays[i].x - count * 76 / 100; *y = rays[i].y + count; break;
		case 18: *x = rays[i].x - count; *y = rays[i].y + count; break;
		case 19: *x = rays[i].x - count; *y = rays[i].y - count * -77 / 100; break;
		case 20: *x = rays[i].x - count; *y = rays[i].y - count * -58 / 100; break;
		case 21: *x = rays[i].x - count; *y = rays[i].y - count * -41 / 100; break;
		case 22: *x = rays[i].x - count; *y = rays[i].y - count * -27 / 100; break;
		case 23: *x = rays[i].x - count; *y = rays[i].y - count * -13 / 100; break;
		case 24: *x = rays[i].x - count; *y = rays[i].y; break;
		case 25: *x = rays[i].x - count; *y = rays[i].y - count * 13 / 100; break;
		case 26: *x = rays[i].x - count; *y = rays[i].y - count * 27 / 100; break;
		case 27: *x = rays[i].x - count; *y = rays[i].y - count * 41 / 100; break;
		case 28: *x = rays[i].x - count; *y = rays[i].y - count * 58 / 100; break;
		case 29: *x = rays[i].x - count; *y = rays[i].y - count * 77 / 100; break;
		case 30: *x = rays[i].x - count; *y = rays[i].y - count; break;
		case 31: *x = rays[i].x - count * 76 / 100; *y = rays[i].y - count; break;
		case 32: *x = rays[i].x - count * 57 / 100; *y = rays[i].y - count; break;
		case 33: *x = rays[i].x - count * 41 / 100; *y = rays[i].y - count; break;
		case 34: *x = rays[i].x - count * 26 / 100; *y = rays[i].y - count; break;
		case 35: *x = rays[i].x - count * 13 / 100; *y = rays[i].y - count; break;
		case 36: *x = rays[i].x; *y = rays[i].y - count; break;
		case 37: *x = rays[i].x - count * -13 / 100; *y = rays[i].y - count; break;
		case 38: *x = rays[i].x - count * -26 / 100; *y = rays[i].y - count; break;
		case 39: *x = rays[i].x - count * -41 / 100; *y = rays[i].y - count; break;
		case 40: *x = rays[i].x - count * -57 / 100; *y = rays[i].y - count; break;
		case 41: *x = rays[i].x - count * -76 / 100; *y = rays[i].y - count; break;
		case 42: *x = rays[i].x + count; *y = rays[i].y - count; break;
		case 43: *x = rays[i].x + count; *y = rays[i].y + count * -77 / 100; break;
		case 44: *x = rays[i].x + count; *y = rays[i].y + count * -58 / 100; break;
		case 45: *x = rays[i].x + count; *y = rays[i].y + count * -41 / 100; break;
		case 46: *x = rays[i].x + count; *y = rays[i].y + count * -27 / 100; break;
		case 47: *x = rays[i].x + count; *y = rays[i].y + count * -13 / 100; break;
	}
}

/* Erase the ray at current position i by drawing it in black */
static void erase_ray () {
	int16_t x, y, count;
	for (count = 1; count < rays[i].count; count++) {
		next_point (&x, &y, count);
		paint_point (x, y, BLACK);
		
	}
}

/* Build the ray at current index
 * Draw points of the given color one by one until either:
 *  - The edge of the screen is reached
 *  - A shape is hit. If so, potentially start another ray.
 *    * But disregard the ray source or sun being hit
 */
static void build_ray (uint16_t color, int8_t source) {
	
	int16_t x, y;
	
	for (rays[i].count = 1; ; rays[i].count++) {
		next_point (&x, &y, rays[i].count);
		
		
		/* Check if point out of screen */
		if (x < 0 || x >= display.width || y < 0 || y >= display.height) 
			break;

		/* Point is valid - draw it on screen */
		paint_point (x, y, color);
		
		/* Check if any shape was hit, except the sun */
		uint8_t j;
		for (j=0; j < SHAPES_TOTAL; j++) {
			if (j != SHAPES_MOVABLE &&
				j != source &&
				hit (x, y, &shapes[j])) {

				/* Target hit. Check color. */
				if (j > SHAPES_MOVABLE) {
					if (shapes[j].rot & 1 && color==RED ||
						shapes[j].rot & 2 && color==GREEN ||
						shapes[j].rot & 4 && color==BLUE)
							targets_remaining--;
				}
				
				/* Mirror hit. Reflect ray. */
				else if (j) {
					i++;
					if (i < RAY_MAX) {
						rays[i].x = x;
						rays[i].y = y;
						rays[i].angle = (2 * shapes[j].rot - rays[i-1].angle + 48) % 48;
						build_ray (color, j);
					}
				}
				
				/* Prism hit. Complicated. */
				else {

					uint8_t prev_angle = rays[i].angle;
					uint8_t delta_angle = shapes[j].rot - prev_angle % PRISM_CASES;
					
					if (color & RED) {
						i++;
						if (i < RAY_MAX) {
							rays[i].x = x;
							rays[i].y = y;
							rays[i].angle = (49 + prev_angle + delta_angle / 4) % 48;
							build_ray (RED, j);
						}
					}
					
					if (color & GREEN) {
						i++;
						if (i < RAY_MAX) {
							rays[i].x = x;
							rays[i].y = y;
							rays[i].angle = (46 + prev_angle + delta_angle / 5) % 48;
							build_ray (GREEN, j);
						}
					}
					
					if (color & BLUE) {
						i++;
						if (i < RAY_MAX) {
							rays[i].x = x;
							rays[i].y = y;
							rays[i].angle = (47 + prev_angle - delta_angle / 4) % 48;
							build_ray (BLUE, j);
						}
					}
				}
				
				/* Stop looking for shapes and stop building the ray */
				return;
			}
		}
	}
}

/* Erase current rays from screen */
void erase_rays() {
	for (i=0; i<RAY_MAX && rays[i].count; i++) {
		erase_ray();
	}
}

/* Compute and draw new rays starting from the sun */
void build_rays() {
	i = 0;
	rays[0].x = shapes[SHAPES_MOVABLE].x;
	rays[0].y = shapes[SHAPES_MOVABLE].y;
	rays[0].angle = shapes[SHAPES_MOVABLE].rot;
	build_ray (WHITE, SHAPES_MOVABLE);
	
	/* Put an end to the array */
	i++;
	if (i < RAY_MAX)
		rays[i].count = 0;
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
