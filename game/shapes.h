/*****************************************************************************
Shape definitions and constants for the FortuGlass game
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

#ifndef TRIANGLE16_H_
#define TRIANGLE16_H_

#include <stdint.h>

/* Constant attributes of various shapes */

#define PRISM_RADIUS 13
#define PRISM_CASES 16

#define MIRROR_RADIUS 13
#define MIRROR_CASES 24

#define TARGET_RADIUS 14
#define SUN_RADIUS 14

/* What kinds of shapes we can have */
enum shape_kind { prism_kind, mirror_kind, sun_kind, target_kind };

/* Information about a shape */
struct shape {
	enum shape_kind kind;
	uint16_t x, y;	/* The coordinates of the centre of the shape */
	uint8_t rad;	/* The maximum radius of the shape */
	uint8_t rot;	/* The rotation situation of the shape. It translates to some
					   angle essentially, but depends on the kind of shape */
};

/* Paint a shape on screen */
void paint_shape (struct shape *shape, uint16_t color);

#endif
