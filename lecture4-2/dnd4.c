#include <stdint.h>
#include <stdio.h>

#define INT_BITS 32

uint8_t getNthByte(uint32_t x, int n) { return (x >> (8 * (4 - n))) & 0xff; }

// setNthByte set x to the N byte of d
uint32_t setNthByte(uint32_t d, uint8_t x, int n) {
	// n = 2
	// mask = 11111111 00000000 11111111 11111111
	// = 0xffffffff ^ (0xff)<<(8*(4-n))
	// d = d & (0xffffffff ^ (0xff) << (8 * (4 - n)));
	d |= x << (8 * (4 - n));
	return d;
}

int main() {
	uint32_t N, d1, d2, d3, d4, n;
	uint32_t tmp = 0;
	scanf("%u %u %u %u %u", &N, &d1, &d2, &d3, &d4);

	tmp = setNthByte(tmp, getNthByte(N, d1) ^ getNthByte(N, d2), 1);
	tmp = setNthByte(tmp, getNthByte(N, d2) & getNthByte(N, d3), 2);
	tmp = setNthByte(tmp, getNthByte(N, d3) | getNthByte(N, d1), 3);
	tmp = setNthByte(tmp, ~getNthByte(N, d4), 4);
	// rotate
	n = d1 + d2 + d3 + d4;
	tmp = (tmp >> n) | (tmp << (INT_BITS - n));

	// Xor
	tmp = ((getNthByte(tmp, 1) ^ getNthByte(tmp, 3)) << 8) |
		  (getNthByte(tmp, 2) ^ getNthByte(tmp, 4));

	printf("%d\n", tmp);
	return 0;
}
