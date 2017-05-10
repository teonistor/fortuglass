#include "lcd.h"
#include <stdarg.h>

static void print_num (int16_t);
static void print_bin (uint16_t);

void printf (char* format, ...) {
	/* For traversing varargs */
	uint8_t i;
	va_list list;
	va_start (list, format);
	
	/* For getting / parsing values */
	char* s;
	double d;
	
	for (i = 0; format[i]; i++) {
		if (format[i] == '%') {
			i++;
			switch (format[i]) {
				
				case 'd': /* Base 10 integer */
					print_num (va_arg (list, int16_t));
					break;
					
				case 'b': /* Integer to be printed as binary (8-bit or 16-bit register) */
					print_bin (va_arg (list, int16_t));
					break;

				case 'f': /* Floating-point. Will be printed with 3 decimal places. */
					d = va_arg (list, double);
					print_num ((int16_t) d);
					display_char ('.');
					print_num ((int16_t) (1000.0 * (d - (int16_t) d)));
					break;
					
				case 'c': /* Single char */
					display_char (va_arg(list, int));
					break;
					
				case 's': /* String */
					s = va_arg (list, char*);
					while (*s) {
						display_char (*s);
						s++;
					}
					break;
					
				case '%': /* Literal % */
					display_char ('%');
					break;
					
				default: /* Unknown */
					display_char ('?');
			}
		}
		
		else {
			display_char (format[i]);
		}
	}
	
	va_end (list);
}

static void print_num(int16_t n) {

	/* If negative, print a minus and make it positive */
	if (n<0) {
		display_char ('-');
		n=-n;
	}
	
	/* By repeatedly dividing a copy of n (stored in m) compute in o the highest power of 10 smaller than n */
	int16_t m = n/10;
	uint16_t o = 1;
	while (m) {
		m/=10;
		o*=10;
	}
	
	/* Take the remainder and divide n by smaller and smaller powers of 10 until all digits have been printed */
	while (o) {
		display_char (n/o + '0');
		n%=o;
		o/=10;
	}
}

static void print_bin (uint16_t n) {

	/* Calculate in o the exponent of the lowest power of 2 larger than n */
	uint16_t m = n;
	uint8_t o = 0;
	while (m) {
		m>>=1;
		o++;
	}
	
	/* Cap o so that exactly 8 or 16 bits will be displayed */
	if (o>8)
		o=15;
	else
		o=7;
		
	/* Repeatedly shift n and take remainders until all 8 or 16 bits have been printed */
	while (o) {
		display_char (n>>o ? '1' : '-');
		n%=1<<o;
		o--;
	}
	
	/* Don't forget the last bit */
	display_char (n ? '1' : '-');
}
