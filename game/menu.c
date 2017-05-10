/*****************************************************************************
Functions for painting various menu screens of the FortuGlass game to the
LaFortuna screen
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

#include "lcd.h"
#include "ili934x.h"

/* Print the specified text at the specified location on screen */
static void text_at (char*txt, uint16_t x, uint16_t y) {
	display_move(x, y);
	display_string(txt);
}

static void paint_side_arrows() {
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(0);
	write_data16(display.height-1);
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(0);
	write_data16(display.width-1);
	write_cmd(MEMORY_WRITE);

	uint16_t x, y, x1, x2, x3, x4;
	x1 = x2 = 20;
	x3 = x4 = display.width - x2;

	for (y=0; y<display.height /2 -8; y++)
		for (x=0; x<display.width; x++)
			write_data16(display.background);

	for (; y<display.height /2; y++) {
		x1--;
		x4++;
		for (x=0; x<x1; x++) write_data16(display.background);
		for (; x<x2; x++) write_data16(display.foreground);
		for (; x<x3; x++) write_data16(display.background);
		for (; x<x4; x++) write_data16(display.foreground);
		for (; x<display.width; x++) write_data16(display.background);
	}

	for (; x1<x2; y++) {
		x1++;
		x4--;
		for (x=0; x<x1; x++) write_data16(display.background);
		for (; x<x2; x++) write_data16(display.foreground);
		for (; x<x3; x++) write_data16(display.background);
		for (; x<x4; x++) write_data16(display.foreground);
		for (; x<display.width; x++) write_data16(display.background);
	}

	for (; y<display.height; y++)
		for (x=0; x<display.width; x++)
			write_data16(display.background);
}

void paint_tutorial (char which) {
	paint_side_arrows();
	switch (which) {
		case 1 :
			text_at ("Use the up, down, left, right buttons", 49, 80);
			text_at ("to move the selected object on screen.", 46, 95);
			text_at ("Turn the rotary encoder to rotate it.", 49, 115);
			text_at ("Press the centre button to", 82, 135);
			text_at ("change selection.", 109, 150);
			break;
		case 2 :
			text_at ("Your goal is to hit each target with", 52, 80);
			text_at ("a ray of light of the same color.", 61, 95);
			text_at ("If a level seems impossible, you", 64, 115);
			text_at ("can skip it from the Pause menu.", 64, 130);
			text_at ("To access the Pause menu,", 85, 150);
			text_at ("long press the centre button", 76, 165);
			text_at ("at any time.", 124, 180);
			break;
		default :
			text_at ("Huh?! There seems to be an error.", 61, 100);
	}
}

void paint_pause() {
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(0);
	write_data16(display.height-1);
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(0);
	write_data16(display.width-1);
	write_cmd(MEMORY_WRITE);
	uint16_t i;
	for (i=0; i<10337; i++) {
		write_data16(0x0);
	}
	for (i=0; i<17; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<97; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<199; i++) {
		write_data16(0x0);
	}
	for (i=0; i<19; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<95; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<202; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<96; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<96; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<94; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<94; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<202; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<94; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<94; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<93; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<202; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<16; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<202; i++) {
		write_data16(0x0);
	}
	for (i=0; i<14; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<202; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<17; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<203; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	for (i=0; i<198; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<190; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<190; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<190; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<187; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<186; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<17; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<13382; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	for (i=0; i<18; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<299; i++) {
		write_data16(0x0);
	}
	for (i=0; i<24; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<294; i++) {
		write_data16(0x0);
	}
	for (i=0; i<28; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<290; i++) {
		write_data16(0x0);
	}
	for (i=0; i<32; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<286; i++) {
		write_data16(0x0);
	}
	for (i=0; i<36; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<283; i++) {
		write_data16(0x0);
	}
	for (i=0; i<38; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<280; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<277; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<275; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<24; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<273; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<26; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<271; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<30; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<269; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<32; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<268; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<36; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<61; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<101; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<79; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<38; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<59; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<101; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<60; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<57; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<91; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<60; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<57; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<91; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<56; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<100; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<49; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<57; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<79; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<56; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<78; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<46; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<58; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<45; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<59; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<45; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<60; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<75; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<45; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<61; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<75; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<50; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<51; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<75; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<22; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<51; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	for (i=0; i<76; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<35; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<43; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<76; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<9; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<33; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<76; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<31; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<152; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<67; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<155; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<65; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<153; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<63; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<152; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<62; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<153; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<63; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<155; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<148; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<63; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<31; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<68; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<65; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<33; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<68; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<67; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<35; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<68; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<69; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<22; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<37; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<67; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<22; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<46; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<67; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<50; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<46; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<67; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<50; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<46; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<67; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<41; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<67; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<11; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<41; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<66; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<11; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<41; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<47; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<11; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<66; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<46; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<66; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<66; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<49; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<66; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<49; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<65; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<46; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<50; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<163; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<50; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<164; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<38; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<267; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<36; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<268; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<32; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<269; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<30; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<271; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<26; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<273; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<24; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<275; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<277; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<280; i++) {
		write_data16(0x0);
	}
	for (i=0; i<38; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<283; i++) {
		write_data16(0x0);
	}
	for (i=0; i<36; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<286; i++) {
		write_data16(0x0);
	}
	for (i=0; i<32; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<290; i++) {
		write_data16(0x0);
	}
	for (i=0; i<28; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<294; i++) {
		write_data16(0x0);
	}
	for (i=0; i<24; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<299; i++) {
		write_data16(0x0);
	}
	for (i=0; i<18; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<2230; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<308; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<309; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<310; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<311; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<312; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<313; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<314; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<315; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<316; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<317; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<318; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	for (i=0; i<4752; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<310; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<309; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<308; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<229; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<228; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<227; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<226; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<226; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<14; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<14; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<225; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<14; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<14; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<225; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<236; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<236; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	for (i=0; i<227; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<226; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<227; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<228; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5876; i++) {
		write_data16(0x0);
	}
}

void paint_menu() {
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(0);
	write_data16(display.height-1);
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(0);
	write_data16(display.width-1);
	write_cmd(MEMORY_WRITE);
	uint16_t i;
	for (i=0; i<9661; i++) {
		write_data16(0x0);
	}
	for (i=0; i<23; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<91; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<179; i++) {
		write_data16(0x0);
	}
	for (i=0; i<23; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<88; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<183; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<86; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<183; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<85; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<182; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<43; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<37; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<183; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<36; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<183; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<35; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<183; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<34; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<183; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<35; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<17; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<183; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<41; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<34; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<17; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<183; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<122; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<7; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<120; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<13; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<30; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<119; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<13; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<29; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<118; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<29; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<118; i++) {
		write_data16(0x0);
	}
	for (i=0; i<14; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<30; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<119; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<30; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	for (i=0; i<119; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<29; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<123; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<121; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<120; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<119; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<117; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<17; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<117; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<17; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<117; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<17; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<117; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<117; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<117; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<118; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<114; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<29; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<11; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<115; i++) {
		write_data16(0x0);
	}
	for (i=0; i<14; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<32; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	for (i=0; i<26; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<1394; i++) {
		write_data16(0x0);
	}
	for (i=0; i<217; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<11728; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	for (i=0; i<18; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<299; i++) {
		write_data16(0x0);
	}
	for (i=0; i<24; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<294; i++) {
		write_data16(0x0);
	}
	for (i=0; i<28; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<290; i++) {
		write_data16(0x0);
	}
	for (i=0; i<32; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<286; i++) {
		write_data16(0x0);
	}
	for (i=0; i<36; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<283; i++) {
		write_data16(0x0);
	}
	for (i=0; i<38; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<280; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<277; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<275; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<24; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<273; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<26; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<271; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<30; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<269; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<32; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<268; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<36; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<267; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<38; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<265; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<264; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<263; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<262; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<261; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<260; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<46; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<259; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<171; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<81; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<33; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<51; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<79; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<34; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<52; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<76; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<50; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<35; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<39; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<76; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<22; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<35; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<39; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<13; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<66; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<26; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<38; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<26; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<24; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<7; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<23; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<22; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<9; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<10; i++) {
		write_data16(0xF945);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<15; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<77; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<24; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<19; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<22; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<5; i++) {
		write_data16(0xFDC5);
	}
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<152; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xF945);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<20; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0xFDC5);
	}
	for (i=0; i<236; i++) {
		write_data16(0x0);
	}
	write_data16(0xF945);
	write_data16(0xF945);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<22; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0xFDC5);
	write_data16(0xFDC5);
	for (i=0; i<247; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<22; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<21; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<256; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<50; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<256; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<50; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<257; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<258; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<258; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<48; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<259; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<46; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<260; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<261; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<44; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<262; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<42; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<263; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<264; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<40; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<265; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<38; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<267; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<36; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<268; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<32; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<269; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<30; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<271; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<26; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<273; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<24; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<275; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<18; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<277; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<12; i++) {
		write_data16(0x0);
	}
	for (i=0; i<15; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<280; i++) {
		write_data16(0x0);
	}
	for (i=0; i<38; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<283; i++) {
		write_data16(0x0);
	}
	for (i=0; i<36; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<286; i++) {
		write_data16(0x0);
	}
	for (i=0; i<32; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<290; i++) {
		write_data16(0x0);
	}
	for (i=0; i<28; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<294; i++) {
		write_data16(0x0);
	}
	for (i=0; i<24; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<299; i++) {
		write_data16(0x0);
	}
	for (i=0; i<18; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0xFFFF);
	}
	for (i=0; i<2230; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<307; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<308; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<309; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<310; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<311; i++) {
		write_data16(0x0);
	}
	for (i=0; i<9; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<312; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<313; i++) {
		write_data16(0x0);
	}
	for (i=0; i<7; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<314; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<315; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<316; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<317; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<318; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	for (i=0; i<3173; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<300; i++) {
		write_data16(0x0);
	}
	for (i=0; i<12; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<300; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<300; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<300; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<300; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<300; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<300; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<10; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<268; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<9; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<268; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<269; i++) {
		write_data16(0x0);
	}
	for (i=0; i<13; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<269; i++) {
		write_data16(0x0);
	}
	for (i=0; i<11; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<269; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<14; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<270; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<8; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<270; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<10; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<271; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<271; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<271; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<272; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<272; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	for (i=0; i<6; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	for (i=0; i<4; i++) {
		write_data16(0x2ABF);
	}
	for (i=0; i<273; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<5; i++) {
		write_data16(0x0);
	}
	for (i=0; i<8; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<273; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<16; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<6; i++) {
		write_data16(0x0);
	}
	for (i=0; i<5; i++) {
		write_data16(0x2ABF);
	}
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x0);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<7; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<317; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<317; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<317; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<318; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<317; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<317; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<317; i++) {
		write_data16(0x0);
	}
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	write_data16(0x2ABF);
	for (i=0; i<4942; i++) {
		write_data16(0x0);
	}
}
